#include <lpc21xx.h>


// Function declarations
void motor_init(void);
void forward(void);
void backward(void);
void left_turn(void);
void right_turn(void);
void stop(void);


// L298 Motor Driver Connections
// IN1 -> P0.16 (Left motor control)
// IN2 -> P0.17 (Left motor control)
// IN3 -> P0.18 (Right motor control)
// IN4 -> P0.19 (Right motor control)


#define IN1 (1<<16)
#define IN2 (1<<17)
#define IN3 (1<<18)
#define IN4 (1<<19)



// Motor initialization function
void motor_init(void)
{
    // Configure motor control pins as output
    IODIR0 |= IN1 | IN2 | IN3 | IN4;


    // Initially stop both motors
    IOCLR0 = IN1 | IN2 | IN3 | IN4;
}



// Move robot forward
void forward(void)
{
    // Left motor forward
    // Right motor forward
    IOSET0 = IN1 | IN3;


    // Clear reverse signals
    IOCLR0 = IN2 | IN4;
}



// Move robot backward
void backward(void)
{
    // Left motor reverse
    // Right motor reverse
    IOSET0 = IN2 | IN4;


    // Clear forward signals
    IOCLR0 = IN1 | IN3;
}



// Turn robot left
void left_turn(void)
{
    // Left motor reverse
    // Right motor forward
    IOSET0 = IN2 | IN3;


    // Clear opposite direction signals
    IOCLR0 = IN1 | IN4;
}



// Turn robot right
void right_turn(void)
{
    // Left motor forward
    // Right motor reverse
    IOSET0 = IN1 | IN4;


    // Clear opposite direction signals
    IOCLR0 = IN2 | IN3;
}



// Stop robot movement
void stop(void)
{
    // Disable all motor inputs
    IOCLR0 = IN1 | IN2 | IN3 | IN4;
}