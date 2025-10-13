# Minimalist PWM Example for STM32F103C8

This project demonstrates a simple and minimalistic approach to generating PWM (Pulse Width Modulation) signals on the STM32F103C8 microcontroller. The code is written to use the STM32 HAL library as little as possible, directly configuring registers for maximum control and efficiency.

## Features
- PWM output on PA0 using TIM2
- Button input on PB9 to cycle through preset duty cycles (0%, 25%, 50%, 75%, 100%)
- Debounce logic for button press
- Low power operation using `__WFI()` (wait for interrupt)

## File Structure
- `main.c`: Contains all initialization and main loop logic for PWM and button handling.

## How It Works
1. System clock is configured for 72 MHz using HSE and PLL.
2. GPIO and timer peripherals are set up directly via register access.
3. TIM2 is configured for PWM mode on channel 1 (PA0).
4. Pressing the button on PB9 cycles the PWM duty cycle through the preset values.
5. The main loop puts the MCU in low power mode, waking only on interrupts.

## Notes

## Wiring Example

**Button:**
- Connect one side of the button to PB9 (pin 46 on STM32F103C8T6).
- Connect the other side of the button to GND.
- PB9 is configured with an internal pull-up, so no external resistor is needed.

**PWM Output (LED):**
- Connect PA0 (pin 10 on STM32F103C8T6) to the anode (long leg) of an LED.
- Connect the cathode (short leg) of the LED to one end of a resistor (330Ω recommended).
- Connect the other end of the resistor to GND.

This setup allows the button to cycle the LED brightness through preset PWM duty cycles.


---

**Target:** STM32F103C8

**IDE:** STM32CubeIDE (or any toolchain supporting STM32F1)
