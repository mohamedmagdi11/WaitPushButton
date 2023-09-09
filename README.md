# Arduino Delay with Interrupt Library

## Introduction
The Arduino Delay with Interrupt Library provides a convenient way to control the timing of opening and closing an output device, such as a relay or LED, using various input devices, sensors, or pushbuttons. This library allows you to set a delay time for the output device to remain open, but it also provides interrupt capability, which means the output device can be closed immediately if a pushbutton is pressed, even if the delay time has not finished yet.

## Features
- Easy-to-use library for Arduino boards.
- Supports delay functionality for opening an output device.
- Provides interrupt capability to close the output device immediately on a pushbutton hit.
- Compatible with various input devices, sensors, or pushbuttons.
- Offers customizable delay time and interrupt pin.

## Installation
1. Download the latest release of the Arduino Delay with Interrupt Library from the GitHub repository: [Link to Repository](https://github.com/MAzewail/WaitPushButton).
2. Open the Arduino IDE on your computer.
3. In the Arduino IDE, click on the **Sketch** menu, navigate to **Include Library**, and select **Add .ZIP Library**.
4. Locate the downloaded library file (e.g., `WaitPushButton.zip`) and select it.
5. The library will be imported and ready to use.

## Usage
1. Connect your Arduino board to the computer and launch the Arduino IDE.
2. Create a new sketch by clicking on the **File** menu and selecting **New**.
3. In the new sketch, include the Delay with Interrupt Library by adding the following line at the top of your sketch:
   ````cpp
   #include <WaitPushButton.h>
   ```
4. Initialize the Delay with Interrupt library in the `setup()` function:
   ````cpp
   WaitPushButton d(inputPin_on, interruptPin, outputPin, delayTime);
   void setup() {
     // Initialize the library with the output pin, delay time, and interrupt pin
     d.begin();
   }
   ```
   Replace `outputPin` with the Arduino pin connected to the output device, `delayTime` with the desired delay in milliseconds, and `interruptPin` with the Arduino pin connected to the pushbutton for interrupt functionality.
5. In the `loop()` function, call the `d.waitms()` method to open the output device. The delay timer will start counting:
   ````cpp
   void loop() {
     // Open the output device with the specified delay time
     d.waitms(1000);
   }
   ```
6. To handle the interrupt, add the following code to the `loop()` function:
   ````cpp
   WaitPushButton myo1(8, 7, 13); // pushbutton on, pushbutton off, output pin, time in ms
   WaitPushButton myo2(6, 8, 13, 2000);
   void setup() {
      myo1.begin();
      myo2.begin();
     }
   void loop(){
       myo2.waitms(5000); 
   }
   ```
7. Upload the sketch to your Arduino board and observe the behavior of the output device.

## Example
Here's a simple example sketch that demonstrates the usage of the Delay with Interrupt Library:

```cpp
#include <WaitPushButton.h>

const int outputPin = 13;       // Pin connected to the output device
const int delayTime = 5000;     // Delay time in milliseconds
const int interruptPin = 7;     // Pin connected to the interrupt (pushbutton)
const int triggerPin = 8;     // Pin connected to the interrupt (pushbutton)

WaitPushButton delayWithInterrupt(triggerPin, interruptPin, outputPin, delayTime);

void setup() {
  // Initialize the library
  delayWithInterrupt.begin();
}

void loop() {
  // Open the output device with the specified delay time
  delayWithInterrupt.waitms();
}
```

## Contributing
Contributions to the Arduino Delay with Interrupt Library are welcome! If you find any issues or have suggestions for improvement, please open an issue on the GitHub repository. You can also submit pull requests with proposed changes.

When contributing, please ensure to follow the existing code style, add appropriate documentation, and write clear commit messages.

## License
This library is released under the [MIT License](https://opensource.org/licenses/MIT). Please refer to the `LICENSE` file for more details.

## Acknowledgements
We would like to thank all the contributors who have helped in the development of this library.

## Contact
For any further inquiries or feedback, you can contact the maintainer of this project:
- Name: Mohamed Abdallah
- Email: Mohammed.Abdallah.salem@gmail.com

Feel free to reach out with any questions or suggestions related to the Arduino Delay with Interrupt Library.

**Happy tinkering!**
