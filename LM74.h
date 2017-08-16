/*
  LM74.h - Arduino library support for the LM74 SPI Bus
  Author: Abraxas666
  
  This library has been made to easily interface and use the LM74 with the Arduino
  This library makes use of the built-in hardware SPI port of the microcontroller 
  so there are some pin connections that are required, see the board documentation

*/

#ifndef LM74_H
#define LM74_H

#include "Arduino.h"

class LM74
{
   public:

      uint16_t CS;
      uint16_t ss_pin;
      uint16_t regbits;
      uint16_t byte1;
      uint16_t byte2;
      uint16_t data;

      float temp;

      LM74(int ss_pin);
      
      void	begin();
      
      float read ();
      float readf ();

   private:

};

#endif