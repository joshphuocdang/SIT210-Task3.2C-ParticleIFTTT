

int light = A4;

void setup()
{
    pinMode(light, INPUT);
}

void loop()
{
  int lightLevel = digitalRead(light);
  
  if (lightLevel < 10) Particle.publish("lightLevel", "dark", PRIVATE);
  if (lightLevel < 200) Particle.publish("lightLevel", "dim", PRIVATE);
  if (lightLevel <500) Particle.publish("lightLevel", "light", PRIVATE);
  if(lightLevel < 800) Particle.publish("lightLevel", "bright",PRIVATE);
  else Particle.publish("lightLevel", "very bright", PRIVATE);
  delay(50000);

}