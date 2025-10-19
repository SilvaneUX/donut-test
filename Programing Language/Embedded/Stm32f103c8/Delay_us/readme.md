# DWT-based microsecond delay (implementation reference)

This README describes the DWT-based microsecond delay implementation used in the accompanying `main.c` example.
The implementation enables the Cortex-M DWT cycle counter, computes cycles-per-microsecond from `SystemCoreClock`, and provides a very small, fast blocking delay function.

Location: `Delay_us/Core/Src/main.c` (example implementation)

## Implementation highlights (from `main.c`)
- DWT initialization: `DWT_Init_and_calc()` — enables `CoreDebug->DEMCR` trace, clears `DWT->CYCCNT`, enables the counter and stores `cycles_per_us = SystemCoreClock / 1_000_000`.
- Fast microsecond delay: `DWT_Delay_us_fast(uint32_t us)` — busy-waits on `DWT->CYCCNT` using the precomputed `cycles_per_us`. It handles small requests efficiently.
- Millisecond macro: `DELAY_MS(ms)` — calls `DWT_Delay_us_fast(1000)` in a loop.
- Clock setup: `SystemClock_Config()` attempts HSE+PLL (72 MHz) and falls back to `SystemClock_Config_Fallback_HSI()` on failure.
- Peripheral setup: `Periph_Config()` shows direct register configuration for GPIO and enables the port clock.

## API (what to call)
- `DWT_Init_and_calc()` — call once after `SystemClock_Config()` and `SystemCoreClockUpdate()` to enable DWT and compute `cycles_per_us`.
- `DWT_Delay_us_fast(uint32_t us)` — use for blocking microsecond delays. Example: `DWT_Delay_us_fast(1000);` for ~1 ms.
- `DELAY_MS(ms)` — convenience macro for millisecond delays.

## Requirements & notes
- Cortex-M with DWT (Cortex-M3 and up). Some devices or production builds may disable the debug unit or lock DWT — detect and provide a timer fallback if needed.
- `SystemCoreClock` must be correct; call `SystemCoreClockUpdate()` after clock configuration.
- Busy-waiting is CPU blocking — use only for short delays (microseconds → low milliseconds). Use timers or an RTOS for long waits.
- The example uses direct register access for peripherals (low-level style) and minimal HAL usage; adapt to your project's HAL/LL style as needed.
- Watch compiler optimizations; ensure the delay loop isn't removed (inline functions and volatile reads to DWT are normally safe).

## Recommended fallback
If DWT is not available or reliable on your target, implement a timer-based delay (TIMx) or use HAL delay functions for longer intervals.

---

Updated: October 19, 2025
