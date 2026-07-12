#include <lpc21xx.h>


// Function declarations
void uart0_init(void);
void uart0_tx(char ch);
char uart0_rx(void);
void uart0_string(char *s);



// UART0 initialization function
void uart0_init(void)
{
    // Configure UART0 pins
    // P0.0 = TXD0
    // P0.1 = RXD0
    PINSEL0 = 0x00000005;


    // Configure UART:
    // 8-bit data
    // 1 stop bit
    // Enable DLAB for baud rate setting
    U0LCR = 0x83;


    // Set baud rate to 9600
    // For 12MHz crystal frequency
    U0DLL = 97;

    // High byte of baud rate divisor
    U0DLM = 0;


    // Disable DLAB
    // UART ready for transmit and receive
    U0LCR = 0x03;
}



// UART transmit single character function
void uart0_tx(char ch)
{
    // Wait until transmit holding register is empty
    // Bit 5 of U0LSR indicates transmitter ready
    while((U0LSR & (1<<5))==0);


    // Send character through UART0
    U0THR = ch;
}



// UART receive single character function
char uart0_rx(void)
{
    // Wait until data is received
    // Bit 0 of U0LSR indicates receive data ready
    while((U0LSR & (1<<0))==0);


    // Return received character
    return U0RBR;
}



// UART transmit string function
void uart0_string(char *s)
{
    // Send characters one by one
    while(*s)
    {
        uart0_tx(*s++);
    }
}