// LM74_read_temp       Author: Abraxas666
//
// 
// Connections:
// ------------
//            |              Arduino             |      
// | LM74     |  Uno  | Mega  |  Due  | Leonardo | 
// +----------+-------+-------+-------+----------+
// | SI/O     |  D12  |  D50  |  D74  |   D14    |  
// | SC       |  D13  |  D52  |  D76  |   D15    |
// | CS       |        User selectable           |
// +----------+-------+-------+-------+----------+
//

#include <LM74.h>

LM74 LM74(8); // define LM74 name and CS pin ( default set to 8 )

void setup() 
{
  LM74.begin();       // intialize SPI
  Serial.begin(9600);
}

void loop() 
{
  Serial.print("The temperature is ");
  Serial.print(LM74.read ());           // read temp in Celsius degrees
  Serial.println("° Celsius");
  Serial.print("The temperature is ");
  Serial.print(LM74.readf ());          // read temp in Fahrenheit degrees
  Serial.println("° Fahrenheit");
  delay(2000);
}


