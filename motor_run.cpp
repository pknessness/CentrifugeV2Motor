/*!
	@file     main.cpp
	@author   Gavin Lyons
	@brief   Example cpp file for MCP4725 DAC library, SetVoltage.
	@note
	This file carries out some set voltage tests.
	-# Test 1 setInputCode function 4096 vout = 3.3V.
	-# Test 2 setInputCode function  2048 Vout = 1.65V.
	-# Test 3 setVoltage function 2.0 , vout 2.0V.
	-# Test 4 setVoltage function 0.800 , vout = 800mV.
	
	Example input code calculation .
	PICO Vref = 3.3 , MCP4725A0 , resolution = 2^12 = 4096.
	Note Vout = (Vref X input code) / Resolution .
	Vout = (3.3 X  inputcode)/ 4096.
	eg for input code  2048 -> Vout = (3.3 X 2048) /4096 = 1.65 V.
*/


// Libraries
#include <stdio.h>

#include <iostream>
#include "pico/stdlib.h"
#include "mcp4725/mcp4725.hpp"



// Definations
//Actully 5, scale all outputs accordingly
// #define DAC_REF_VOLTAGE 3.3  // Volts DAC supply-reference voltage
#define DAC_REF_VOLTAGE 5  // Volts DAC supply-reference voltage



// Setup
MCP4725_PICO myDAC(DAC_REF_VOLTAGE);

/*!
	@brief The MAIN loop function, setVoltage example file
	@return  Program Exit code
*/
int main () {
	// local variable declaration:
	// busy_wait_ms(5000);
	stdio_init_all(); // Initialize chosen serial port, default 38400 baud
	busy_wait_ms(1000);
	printf("MCP4725_PICO : Set Voltage example 7.\r\n");
	busy_wait_ms(1000);
	printf("MCP4725_PICO : Set Voltage example 6.\r\n");
	busy_wait_ms(1000);
	printf("MCP4725_PICO : Set Voltage example 5.\r\n");
	busy_wait_ms(1000);
	printf("MCP4725_PICO : Set Voltage example 4.\r\n");
	busy_wait_ms(1000);
	printf("MCP4725_PICO : Set Voltage example 3.\r\n");
	busy_wait_ms(1000);
	printf("MCP4725_PICO : Set Voltage example 2.\r\n");
	busy_wait_ms(1000);
	printf("MCP4725_PICO : Set Voltage example 1.\r\n");
	
	if (!myDAC.begin(MCP4725A0_Addr_A00 , i2c1, 100, 18 , 19))
	{
		printf("MCP4725 : Failed to initialize DAC.!\r\n");
		while(1){};
	}
		while(1){
			char f[7] = {0, 0, 0, 0, 0, 0, 0}; 
			printf("Reading input \n");
			// fgets (f, 256, stdin);
			std::cin.getline(f, 7, 'q');
			printf("Read input success %s\n", f);
			double a = atof(f);
			printf("Convert to double success\n");
			// char buffer[2];
  			// printf ("Enter input: ");
  			// fgets (buffer,2,stdin);
  			// double n = atof(buffer);
			if(myDAC.setVoltage(a, MCP4725_FastMode, MCP4725_PowerDown_Off) == true)
				printf("Set 2.5V & normal mode, Vout = %f\n", a);
			else
				printf("I2C error\n");
			busy_wait_ms(5000);
		};

	// // Test 1  setInputCode function 4090
	
	// if(myDAC.setInputCode(4090, MCP4725_FastMode, MCP4725_PowerDown_Off) == true)
	// 	// printf("Set max value & normal mode, Vout = ~3.3\n");
	// 	printf("Set max value & normal mode, Vout = 5\n");
	// else 
	// 	printf("I2C error\n");
	// busy_wait_ms(5000);

	// // Test 2 setInputCode function  2048 
	
	// if(myDAC.setInputCode(2048, MCP4725_FastMode, MCP4725_PowerDown_Off)== true)
	// 	// printf("Set 50% value & normal mode, Vout = 1.65\n");
	// 	printf("Set 50% value & normal mode, Vout = 2.5\n");
	// else
	// 	printf("I2C error\n");
	// busy_wait_ms(5000);

	// // Test 3 SetVoltage function 2.5V
	// if(myDAC.setVoltage(2.5, MCP4725_FastMode, MCP4725_PowerDown_Off) == true)
	// 	printf("Set 2.5V & normal mode, Vout = 2.5\n");
	// else
	// 	printf("I2C error\n");
	// busy_wait_ms(5000);

	// // Test 4 SetVoltage 800mV
	// if(myDAC.setVoltage(.800, MCP4725_FastMode, MCP4725_PowerDown_Off)== true)
	// 	printf("Set 800mV & normal mode, Vout = 800mV\n");
	// else
	// 	printf("I2C error\n");
	// busy_wait_ms(5000);
	return 0;
}



// /**
//  * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
//  *
//  * SPDX-License-Identifier: BSD-3-Clause
//  */
// #include <stdio.h>
// #include "pico/stdlib.h"
// #include "hardware/i2c.h"
// #include <math.h>


// void r2rMap (float analogOut) { 
//     if (analogOut <0 || analogOut > 1) printf("Invalid input range to r2rMap, need value between 0 to 1");
//     //analog out range 0-1, in incremetns of 2^{-10}
//     analogOut = analogOut * pow(2, 10) - 1;

//     int r2rOut[10] = {1};

//         printf("Analoogout: %d     ", (int)analogOut);

//     for (int i = 0; i < 10; i++) {
//         r2rOut[i] = ((int)analogOut>>(9 - i)) & 0x01;
//         gpio_put(i+4, r2rOut[i]);

//         printf("%d %d, ", ((int)analogOut>>(9 - i)), r2rOut[i]);
//     } 
// }


// int main() {
// #ifndef PICO_DEFAULT_LED_PIN
// #warning blink example requires a board with a regular LED
// #else
//     stdio_init_all();

//     const uint LED_PIN = PICO_DEFAULT_LED_PIN;
//     gpio_init(LED_PIN);
//     gpio_set_dir(LED_PIN, GPIO_OUT);
//     for (int i = 0; i < 10; i++) {
//         gpio_init(i+4);
//         gpio_set_dir(i+4, GPIO_OUT);
//     } 
//     while (true) {
//         gpio_put(LED_PIN, 1);
//         sleep_ms(1000);
//         gpio_put(LED_PIN, 0);
//         r2rMap(0.5);
//         sleep_ms(1000);
//         printf("Helloooooooooo, world!\n");
//     }
// #endif
// }
