/*
  LM74.cpp - Arduino library support for the LM74 SPI Bus
  Author: Abraxas666
  
  This library has been made to easily interface and use the LM74 with the Arduino
  This library makes use of the built-in hardware SPI port of the microcontroller 
  so there are some pin connections that are required, see the board documentation

*/

#include "LM74.h"
#include <SPI.h>

LM74::LM74(int ss_pin )
{
 	CS = ss_pin ;
}

void LM74::begin()
{
	digitalWrite(CS, HIGH);
	pinMode(CS, OUTPUT);
	pinMode(SCK, OUTPUT);
	pinMode(MOSI, OUTPUT);
	pinMode(MISO, INPUT);

	SPISettings settings(16000000, MSBFIRST, SPI_MODE3);
}

float LM74::read ()
{
 SPI.begin();
 digitalWrite (CS, LOW);
 byte1  = SPI.transfer(0);
 byte2  = SPI.transfer(0);
 digitalWrite (CS, HIGH);

 regbits = (byte1 << 8) + byte2;
 regbits = (regbits >>3 );
 temp = regbits * 0.0625;

 return temp;
}

float LM74::readf ()
{
 SPI.begin();
 digitalWrite (CS, LOW);
 byte1  = SPI.transfer(0);
 byte2  = SPI.transfer(0);
 digitalWrite (CS, HIGH);

 regbits = (byte1 << 8) + byte2;
 regbits = (regbits >>3 );
 temp = regbits * 0.0625;
 temp = 1.8 * temp + 32 ;
 return temp;
}

