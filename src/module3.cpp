/* this file will enable three different LEDs on and off depending on switch combiniations*/

#include "mbed.h"

#define BUTTON_1 p5
#define BUTTON_2 p6
#define BUTTON_3 p7
#define BUTTON_4 p8
#define RED_LED p9
#define YELLOW_LED p10
#define BLUE_LED p11
/* to associate with given identifier with value
identifier is BUTTON or LED*/

// Define the Input pins
DigitalIn b1(BUTTON_1);
DigitalIn b2(BUTTON_2);
DigitalIn b3(BUTTON_3);
DigitalIn b4(BUTTON_4);

//Define the Output pins
DigitalOut rled(RED_LED);
DigitalOut yled(YELLOW_LED);
DigitalOut bled(BLUE_LED);

//Define Input/Output buses
BusIn buttonbus(BUTTON_1, BUTTON_2, BUTTON_3, BUTTON_4);
BusOut ledsbus(BLUE_LED, YELLOW_LED, RED_LED);
// grouping buttons and leds respectively

void ControlLED_DigitalIO ();
void ControlLED_BusIO ();

int main()
{
    while(1) {
        //ControlLED_DigitalIO ();
         ControlLED_BusIO ();
        wait(0.25);
    }
}

void ControlLED_DigitalIO (){
rled = (!b4&&(!b3||b2)) || (b4&&b3&&b2&&b1);
yled = (b4^b3) || (b4&&b3&&b2&&b1);
bled = b4;
}

void ControlLED_BusIO (){
    switch(buttonbus){
        case 0 ... 3:
        ledsbus = 0b0100;
        // red LED on
        case 4 ... 5:
        ledsbus = 0b0010;
        // yellow LED on
        break;
        case 6 ... 7:
        ledsbus = 0b0110;
        // red and yellow LEDs on
        case 8 ... 11:
        ledsbus = 0b0011;
        // yellow and blue LEDs on
        break;
        case 12 ... 14:
        ledsbus = 0b0001;
        //blue LED on
        break;
        case 15:
        ledsbus = 0b0111;
        // all LEDs on
        break;
        default: ;
    }
}
/*
order of pins in the constructor is the reverse order of the pins in the byte order. If you have BusIn(a,b,c,d,e,f,g,h) then the order of bits in the byte would be h, g, f, e, d, c, b, a, with ‘a’ being bit 0, ‘b’ being bit 1, ‘c’ being bit 2 and so o
*/
