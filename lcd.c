#include<lpc21xx.h>
#include"delays.h"

// LCD data pins connected from P0.4 to P0.11
#define LCD_D 0xff<<4

// Register Select pin (RS)
#define RS 1<<12

// Enable pin (E)
#define E 1<<13


// Function declarations
void init(void);
void command(unsigned char);
void data(unsigned char);
void lcds(unsigned char*);


// LCD initialization function
void init(void)
{
    // Configure LCD data pins, RS and E pins as output
    IODIR0=LCD_D|RS|E;


    // Clear LCD display
    command(0x01);

    // Return cursor to home position
    command(0x02);

    // Display ON, cursor OFF
    command(0x0c);

    // 8-bit mode, 2 line LCD, 5x7 matrix
    command(0x38);
}


// Send command to LCD
void command(unsigned char c)
{
    // Clear LCD data pins
    IOCLR0=LCD_D;


    // Send command data to LCD data pins
    IOSET0=c<<4;


    // RS=0 for command mode
    IOCLR0=RS;


    // Enable LCD
    IOSET0=E;


    // LCD delay
    delays(2);


    // Disable LCD
    IOCLR0=E;
}


// Send data/character to LCD
void data(unsigned char d)
{
    // Clear LCD data pins
    IOCLR0=LCD_D;


    // Send character data to LCD pins
    IOSET0=d<<4;


    // RS=1 for data mode
    IOSET0=RS;


    // Enable LCD
    IOSET0=E;


    // LCD delay
    delays(2);


    // Disable LCD
    IOCLR0=E;
}


// Display string on LCD
void lcds(unsigned char *s)
{
    // Continue until NULL character
    while(*s)
    {
        // Send each character to LCD
        data(*s++);
    }
}