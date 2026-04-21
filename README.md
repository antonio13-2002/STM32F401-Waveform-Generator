# STM32F401 Waveform Generator (AWG)

## 1. Project Overview
This project implements an **Arbitrary Waveform Generator (AWG)** using an **STM32F401-based** development board.

The core operating principle relies on generating a **Pulse Width Modulation (PWM)** signal with a variable duty cycle. By dynamically modifying the duty cycle via software over time, the average voltage output of the microcontroller's pin changes accordingly. 

To obtain the final analog waveform, this digital PWM signal is routed through an external hardware **low-pass filter** (RC circuit). The primary function of this filter is to isolate the average voltage component of the signal while stripping away the high-frequency PWM switching noise. By connecting the filter's output to an oscilloscope, you can visualize the generated continuous waveform in real-time.

---

## 2. Tools and Frameworks
The following technologies were used for the development and testing of this project:

* **CMSIS (Cortex-Microcontroller Software Interface Standard):** An industry-standard framework provided by ARM that enables "bare-metal" programming. CMSIS allows for direct interaction with the microcontroller's hardware registers and individual bits. This ensures maximum execution efficiency and precise control over the required hardware peripherals (such as the hardware Timers used for PWM generation).
* **STM32CubeIDE:** The official Eclipse-based Integrated Development Environment (IDE) provided by STMicroelectronics. It offers a comprehensive coding environment and features powerful **in-circuit debugging** capabilities. This allows for step-by-step code execution, real-time register inspection, and thorough testing of the firmware directly on the target hardware before final deployment.

---

## 3. Build and Run Instructions

### Important Prerequisites
To successfully compile this project, it is **strictly required** to include the **CMSIS** library specific to the STM32F4xx family in your source files. Please ensure that the *Include paths* are correctly configured within the project properties of your IDE.

### How to run the code on the target board

1.  **Clone the repository** to your local machine:
    ```bash
    git clone [https://github.com/tuo-nome-utente/STM32F401-Waveform-Generator.git](https://github.com/tuo-nome-utente/STM32F401-Waveform-Generator.git)
    ```
2.  **Import the project:** Open STM32CubeIDE, navigate to `File > Import... > General > Existing Projects into Workspace`, and select the downloaded project folder.
3.  **Hardware Setup:**
    * Connect your STM32F401 board to your computer via the USB cable.
    * Connect the input of your RC low-pass filter to the configured PWM output pin on the board.
    * Connect an oscilloscope probe to the analog output of the filter.
4.  **Build:**
    * Click the **Build** button (the hammer icon) to compile the code. Check the console output to ensure the process finishes with `0 errors`.
5.  **Run/Debug:**
    * Click the **Run** (green "Play" icon) or **Debug** (bug icon) button to flash the compiled firmware directly into the target board's memory and start execution.
6.  **Verify:** Check your oscilloscope screen to view the generated waveform.
