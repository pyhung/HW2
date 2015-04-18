#include "mbed.h"
#include "TextLCD.h"

DigitalIn freq(p16);        // hardcoding pin 16 as the reader for the input frequency
DigitalOut generator(p18);  // using pin 18 as the frequency generator

TextLCD lcd(p24, p26, p27, p28, p29, p30);  // outputting the frequency reading to an LCD screen on the breadboard
Timer t;                    // timer to establish the frequency sampling rate

int main() {
    int i;
    float x;
    i=0;
    //x=0.0;   
    while(1) {
    
       lcd.cls();                                       // clears the LCD screen of previous garbage
       lcd.printf("Frequency is: %f", freq.read());     // Display the output of the frequency read by pin 16
       
       lcd.locate(0, 0);
       t.start();
       while (i<10) {
            x=freq.read();
            if (x==1)
                ++i;
            }
            t.stop();            
            // start counting the number of positive pulses
            // store the positive pulses
            // output the positive pulses after 0.1 ms
            // stop timer after 0.1 ms
            // Output elapsed
            lcd.printf("Time: %f", t.read_ms());
            lcd.printf("i: %d", i);
            //wait(1);      
    //      lcd.printf("V=%d", i);    
    i=0;
    x=0;
    }
}
