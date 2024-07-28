/*
*******************************************************************************
*simple exammple for M5 Core 2
* Generates differant tone when A, B, C button is pressed            
* M5Unified.h doesn't work with M5 Core 2 Library
*******************************************************************************
*/
#include <M5Unified.h>
//#include <M5Core2.h>

/* After M5Core is started or reset
the program in the setUp () function will be run, and this part will only be run
once. */
void setup() {
    M5.begin();             // Init M5Core. 
    M5.Lcd.setTextSize(2);  // Set the text size to 2. 
    M5.Lcd.println("M5Stack Speaker test");  // Screen printingformatted string.
// Set Tone Volume - Max volume is 255
    M5.Speaker.setVolume(255);
}

/* After the program in setup() runs, it runs the program in loop()
The loop() function is an infinite loop in which the program runs repeatedly
*/
void loop() {
    M5.update();  // Read the press state of the key.  A, B, C

    if (M5.BtnA.wasPressed()) {  // Check if the key is pressed.
        M5.Lcd.println("A wasPressed");
        M5.Speaker.tone(4000, 200);  // generates 2 millisecond beep
    } else if (M5.BtnB.wasPressed()) {
        M5.Lcd.println("B wasPressed");
        M5.Speaker.tone(2000, 300); // generates 3 millisecond beep
    } else if (M5.BtnC.wasPressed()) {
        M5.Lcd.println("C wasPressed");
        M5.Speaker.tone(1000, 400);// generates 4 millisecond beep
    }
}
