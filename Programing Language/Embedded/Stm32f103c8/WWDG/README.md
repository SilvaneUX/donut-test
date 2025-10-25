# Window Watchdog (WWDG) demo — STM32F103C8

Location
- `Programing Language/Embedded/Stm32f103c8/WWDG/Core/Src/main.c`

Purpose
- Demonstrates using the Window Watchdog (WWDG) on an STM32F103 (Blue Pill style board).
- Shows how to detect WWDG/IWDG resets, blink the onboard LED on reset, configure the WWDG, refresh it safely inside the allowed window, and trigger a reset by stopping refresh.

High-level behavior of the code
- Initializes clocks and `PC13` GPIO for the on-board LED (often active-low on Blue Pill).
- On boot, checks `RCC->CSR` for `WWDGRSTF` and `IWDGRSTF` flags. If seen, clears reset flags and blinks the LED 3× to indicate the type of reset.
- Initializes the WWDG peripheral (`MX_WWDG_Init`) with HAL values (prescaler, window, start counter) and enables the EWI IRQ.
- In `main()` the code refreshes the WWDG periodically while the app is alive. After 2000 ms the code intentionally stops refreshing (simulates a hang) to demonstrate a WWDG reset.
- When Early Wakeup Interrupt (EWI) fires the code toggles the LED briefly. If the watchdog is not refreshed in time, the MCU resets and the boot code will indicate the watchdog reset via the LED blink sequence.

WWDG concepts and math (GitHub-friendly)

The Window Watchdog runs off the APB1 clock (PCLK1). The WWDG decrement frequency f_WWDG is:

```text
f_WWDG = PCLK1 / 4096 / prescaler
```

Where:
- `PCLK1` is the APB1 clock frequency in Hz (on a Blue Pill typical value is 36_000_000 Hz when using an HSE PLL setup).
- `prescaler` is one of 1, 2, 4 or 8 (set by HAL constants `WWDG_PRESCALER_*`).
- `4096` is the fixed divider used inside the WWDG clocking chain.

Each decrement (one counter tick) takes:

```text
T_tick = 1 / f_WWDG  (seconds)
```

Counter and reset behavior
- The WWDG counter is 7-bit and valid values are `0x40` (64) .. `0x7F` (127).
- The counter is loaded by software (start value). It counts down at `f_WWDG`.
- When the counter reaches `0x40` an Early Wakeup Interrupt (EWI) can be generated (if enabled).
- If the counter goes below `0x40` (i.e., 0x3F) the WWDG generates a system reset.

Timeout calculation

- Time from a loaded counter value `CNT_start` down to reset (underflow) is approximately:

```text
T_reset = (CNT_start - 0x3F) * T_tick
```

- If you want the maximum possible timeout (CNT_start = 0x7F):

```text
T_max = (0x7F - 0x3F) * T_tick = 64 * T_tick
```

Window (when you may refresh)
- WWDG provides a window feature: you must refresh (write new counter value) when the current counter value is less than or equal to the `Window` register and strictly greater than `0x3F` (otherwise a refresh is too late and causes reset).
- If `Window >= CNT_start` the window check is effectively disabled (refresh is allowed immediately after start).

Allowed refresh time window (in seconds) when `Window < CNT_start`:

```text
T_earliest_refresh = (CNT_start - Window) * T_tick
T_latest_refresh   = (CNT_start - 0x3F) * T_tick   # just before reset
```

Therefore you must call the refresh routine between `T_earliest_refresh` and `T_latest_refresh` after you load `CNT_start` (or after the last refresh).

HAL prescaler constant mapping
- `WWDG_PRESCALER_1` -> prescaler = 1
- `WWDG_PRESCALER_2` -> prescaler = 2
- `WWDG_PRESCALER_4` -> prescaler = 4
- `WWDG_PRESCALER_8` -> prescaler = 8

Examples (use as guides)

Example parameters (Blue Pill typical)
- `PCLK1 = 36_000_000` Hz (typical when using HSE + PLL on Blue Pill)
- `prescaler = 8` (`WWDG_PRESCALER_8` in HAL)

Compute f_WWDG and tick time:

```text
f_WWDG = 36_000_000 / 4096 / 8 ≈ 1098.63 Hz
T_tick  ≈ 0.000910 s ≈ 0.91 ms per decrement
```

1) If `CNT_start = 78` (as in the demo):

```text
T_reset ≈ (78 - 63) * 0.91 ms = 15 * 0.91 ms ≈ 13.7 ms
```

So with `CNT_start = 78` the watchdog will reset in ~13.7 ms if not refreshed.

2) Maximum timeout (CNT_start = 127):

```text
T_max ≈ 64 * 0.91 ms ≈ 58.6 ms
```

So on a Blue Pill the WWDG maximum timeout is on the order of tens of milliseconds (≈58.6 ms with the settings above).

Window example
- Suppose `Window = 100` and `CNT_start = 127`:

```text
T_earliest_refresh = (127 - 100) * 0.91 ms = 27 * 0.91 ms ≈ 24.6 ms
T_latest_refresh   = (127 - 63)  * 0.91 ms = 64 * 0.91 ms ≈ 58.6 ms
```

So the application must refresh between ~24.6 ms and ~58.6 ms after the counter is (re)loaded.

How the demo configures WWDG (from `main.c`)
- `Prescaler = WWDG_PRESCALER_8` (largest prescaler to maximize timeout)
- `Window = 0x7F` (127) — note: this is the top value; if `Window >= Counter` the window check is effectively disabled and refreshes are allowed immediately.
- `Counter = 78` — start value loaded into the counter
- `EWIMode = WWDG_EWI_DISABLE` in the demo (EWI IRQ is still enabled in NVIC in the template but EWI is disabled in `Init`), but the template shows how to enable/handle EWI if desired.

How to change timeout/window in the code
- Edit `MX_WWDG_Init()` in `main.c`:
  - Change `hwwdg.Init.Prescaler` to one of `WWDG_PRESCALER_1/2/4/8`.
  - Change `hwwdg.Init.Counter` to a value in `0x40..0x7F` (e.g., 78).
  - Change `hwwdg.Init.Window` to control earliest allowed refresh (must be < counter to enforce a window).
- Rebuild and flash.

Build & flash (typical)
- Open the project in STM32CubeIDE and build, then flash with the built-in programmer.
- Or build with your toolchain and flash with `st-flash` or STM32CubeProgrammer.

PowerShell example (if you have `st-flash`):

```powershell
# flash example
st-flash write path\to\your\firmware.bin 0x8000000
```

How to test the demo
- Flash the firmware to a Blue Pill (STM32F103C8).
- Reset the board. On first boot the reset flags will be clear.
- The firmware will refresh the WWDG for ~2000 ms and then stop refreshing to simulate a hang; the WWDG should reset the MCU.
- On the next boot the code will detect the WWDG reset (RCC CSR WWDGRSTF) and blink the LED 3×.

Caveats & notes
- WWDG timeouts are short (tens of ms). For longer supervisory timeouts use the Independent Watchdog (IWDG), which uses the LSI clock and supports much longer timeouts.
- Ensure your main loop can reliably refresh inside the allowed window. Use a timer or RTOS task with deterministic timing for production code.
- If you enable EWI, keep the callback short and avoid long-blocking operations inside it.

Contact / follow-up
- I can: add a small script to compute the WWDG timings for given `PCLK1`, `prescaler`, `counter`, and `window`, or add a PowerShell flash helper if you'd like — tell me which tool you prefer (st-flash, OpenOCD, STM32CubeProgrammer).
