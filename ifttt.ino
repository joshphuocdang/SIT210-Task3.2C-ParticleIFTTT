// This #include statement was automatically added by the Particle IDE.
#include <thingspeak-webhooks.h>


int light = A4;

void setup()
{
    pinMode(light, INPUT);
}

void loop()
{
  int lightLevel = analogRead(light);
  
  if (lightLevel < 10) 
  {
      Particle.publish("lightLevel", "dark", PRIVATE);
  }
  else if (lightLevel < 200 && lightLevel >= 10)
  {
      Particle.publish("lightLevel", "dim", PRIVATE);
  }
  
  else if (lightLevel <500 && lightLevel >=200)
  {
      Particle.publish("lightLevel", "light", PRIVATE);
  }
  
  else if(lightLevel < 800 && lightLevel >= 500) 
  {
      Particle.publish("lightLevel", "bright",PRIVATE);
  }
  else if (lightLevel > 800)
  {
      Particle.publish("lightLevel", "very bright", PRIVATE);
  }
  
  delay(5000);
}
