# Independent Watchdog (IWDG) demo — STM32F103C8

Location
- `Programing Language/Embedded/Stm32f103c8/IWDG/Core/Src/main.c`

Purpose
- Demonstrates using the Independent Watchdog (IWDG) on an STM32F103 (Blue Pill style board).
- Shows how to configure the watchdog, detect a watchdog reset, and blink the onboard LED on reset.

What the code does (high-level)
- Enables clocks and basic GPIO for PC13 (commonly the on-board LED, often active-low).
- Optionally enables LSI (internal RC) used as the IWDG clock source.
- Configures IWDG with a chosen prescaler and reload value.
- On boot, checks if the reset was caused by the IWDG (RCC CSR IWDGRSTF). If so the code blinks PC13 three times.
- In the main loop the code reloads the IWDG ("kick"), then simulates a hang after 2000 ms to let the watchdog expire and reset the MCU.

Notes about the LED
- Many Blue Pill boards have the user LED on PC13 and it's wired active-low. The code uses BSRR to set/reset PC13 accordingly.

Math: calculating IWDG timeout

The IWDG counter is clocked by the LSI oscillator. The timeout period t (seconds) for a given reload R and prescaler P is:

```text
t = ((R + 1) * P) / f_LSI   (seconds)
```

Where:
- R is the 12-bit reload value (0..4095).
- P is the prescaler divider (one of 4, 8, 16, 32, 64, 128, 256).
- f_LSI is the LSI oscillator frequency (Hz). A common nominal value is ~40,000 Hz, but it varies per part and with temperature — measure it if you need accurate timeouts.

Prescaler mapping to PR register value (used by the IWDG PR field):
- div 4  -> PR = 0
- div 8  -> PR = 1
- div 16 -> PR = 2
- div 32 -> PR = 3
- div 64 -> PR = 4
- div 128-> PR = 5
- div 256-> PR = 6

Example calculations (use these as guides):

1) Example from current code: prescaler = 4, reload = 999, assume f_LSI = 40,000 Hz

Calculation:

```text
t = ((999 + 1) * 4) / 40000 = 4000 / 40000 = 0.1 seconds  (100 ms)
```

So with those parameters the watchdog will reset the MCU roughly every 100 ms unless the application reloads the counter faster than that.

2) Maximum-ish timeout using max reload (4095) and largest prescaler (256):

Calculation (assuming f_LSI = 40,000 Hz):

```text
t = ((4095 + 1) * 256) / 40000 = 1048576 / 40000 ≈ 26.21 seconds
```

(With a lower actual LSI frequency the timeout increases. Conversely, a higher LSI frequency reduces the timeout.)

Recommendation: measure LSI frequency on your board if you need precise timeouts. One common approach is to route LSI to a timer input (if supported) and measure it with a timer capture.

How to change the timeout in the code
- Edit `iwdg_config()` in `main.c`.
  - `prescaler_div` selects the divider (4..256). Internally code maps it to PR.
  - `reload` is the R value (0..4095).
- Rebuild and flash.

Quick build & flash (typical methods)
- Import the project into STM32CubeIDE and build.
- Or build with your preferred Makefile/CMake flow and flash with ST-Link:

PowerShell example (if you have `st-flash` / `stlink` utilities installed):

```powershell
# build step depends on your chosen toolchain (not shown here)
# flash (example with st-flash)
st-flash write path\to\your\firmware.bin 0x8000000
```

Or use STM32CubeProgrammer / ST-Link Utility to flash the generated .bin or .elf.

How to test
- Flash firmware.
- Power cycle board. On first boot, the reset marker is clear.
- Let the program run: it will kick the watchdog while alive. After the simulated hang (when HAL_GetTick() > 2000) the code stops kicking and the watchdog will reset the MCU — on the next boot the code will detect IWDG reset and blink PC13 three times.

Caveats and safety
- The LSI frequency is not precise; for precise timing measure LSI or use an external crystal/timer chain.
- The IWDG cannot be stopped once started (it's independent). Be careful when testing to avoid repeatedly locking a device behind short timeouts — lower the prescaler or increase the reload if you need more time for debugging.

Contact / Notes
- This README is intended to quickly explain the example in `main.c` under the IWDG folder.
- If you'd like, I can add a small shell script for flashing or extend the example to compute and print estimated timeout using a configured LSI measurement.
