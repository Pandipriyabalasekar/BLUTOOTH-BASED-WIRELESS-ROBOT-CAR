void delays(unsigned int d)
{
    // Set Timer0 prescaler value
    // PCLK is divided to generate required delay timing
    T0PR = 15000 - 1;


    // Start Timer0
    T0TCR = 0X01;


    // Wait until Timer0 counter reaches required delay value
    while(T0TC < d);


    // Stop Timer0 and reset timer counter
    T0TCR = 0X03;


    // Disable Timer0
    T0TCR = 0X00;
}