#include <lpc21xx.h>
#include "lcd.c"
#include "motor.c"
#include "uart.c"


// Stores the latest Bluetooth command
// Default command is STOP
char last_cmd = 'S';



int main()
{
    int left, right;
    char cmd;



    // Initialize LCD
    init();

    // Initialize L298 motor driver
    motor_init();

    // Initialize UART0 for Bluetooth communication
    uart0_init();



    // Configure IR sensor pins P0.14 and P0.15 as input
    IODIR0 &= ~((1<<14)|(1<<15));



    // Clear LCD display
    command(0x01);

    // Move cursor to first position
    command(0x80);

    // Display robot status
    lcds("ROBOT READY");



    while(1)
    {


        // Check whether Bluetooth data is received
        if(U0LSR & (1<<0))
        {
            // Receive Bluetooth character
            cmd = uart0_rx();

            // Store received command
            last_cmd = cmd;
        }




        // Read left IR sensor status
        left  = (IOPIN0 >> 14) & 1;

        // Read right IR sensor status
        right = (IOPIN0 >> 15) & 1;





        // -------- IR OBSTACLE AVOIDANCE --------



        // Both left and right sensors detect obstacle
        // Robot stops
        if(left == 0 && right == 0)
        {
            // Clear LCD
            command(0x01);

            // Set cursor position
            command(0x80);


            // Display stop message
            lcds("STOP");


            // Stop motors
            stop();
        }





        // Left sensor detects obstacle
        // Robot turns right to avoid obstacle
        else if(left == 0 && right == 1)
        {
            command(0x01);
            command(0x80);


            // Display direction
            lcds("TURN RIGHT");


            // Turn robot right
            right_turn();
        }





        // Right sensor detects obstacle
        // Robot turns left to avoid obstacle
        else if(left == 1 && right == 0)
        {
            command(0x01);
            command(0x80);


            // Display direction
            lcds("TURN LEFT");


            // Turn robot left
            left_turn();
        }





        // No obstacle detected
        // Bluetooth command controls robot
        else
        {

            // Check last received Bluetooth command
            switch(last_cmd)
            {



                // Move forward
                case 'F':
                case 'f':

                    command(0x01);
                    command(0x80);

                    lcds("FORWARD");

                    forward();

                    break;





                // Move backward
                case 'B':
                case 'b':

                    command(0x01);
                    command(0x80);

                    lcds("BACKWARD");

                    backward();

                    break;





                // Turn left manually
                case 'L':
                case 'l':

                    command(0x01);
                    command(0x80);

                    lcds("LEFT");

                    left_turn();

                    break;





                // Turn right manually
                case 'R':
                case 'r':

                    command(0x01);
                    command(0x80);

                    lcds("RIGHT");

                    right_turn();

                    break;





                // Stop robot manually
                case 'S':
                case 's':

                    command(0x01);
                    command(0x80);

                    lcds("STOP");

                    stop();

                    break;





                // If unknown command received
                // Stop robot for safety
                default:

                    stop();

                    break;
            }
        }
    }
}