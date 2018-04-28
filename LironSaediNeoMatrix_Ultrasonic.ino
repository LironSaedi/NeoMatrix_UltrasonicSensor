#include <Adafruit_GFX.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_SPITFT_Macros.h>
#include <gfxfont.h>

#include <Adafruit_NeoMatrix.h>
#include <Ultrasonic.h>

Ultrasonic sensor(4, 3);
Adafruit_NeoMatrix matrix(8, 8, 2);

void flash()
{
  for (int i = 0; i < 8; i ++)
  {

    for (int j = 0; j < 8; j ++)
    {
      matrix.drawPixel(i, j, matrix.Color(255, 0, 0));
      matrix.show();
      delay(100);
      matrix.drawPixel(i, j, matrix.Color(255, 0, 0));
      delay(100);
      
    }
  }
}
void setup()
{
  matrix.begin();
  matrix.setBrightness(30);
  matrix.clear();
  Serial.begin(9600);
}

void loop()
{

  long distanceFromSensor = sensor.Ranging(0);
  delay(1);
  Serial.println(distanceFromSensor);
  int value = map(distanceFromSensor, 0, 50, 0, 255);
  Serial.println(value);

  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      matrix.drawPixel(i, j, matrix.Color(255 - value, 255 - value, 0));
    }
  }
  if (value = 0)
  {
    flash();
  }

    matrix.show();
}
 
  


