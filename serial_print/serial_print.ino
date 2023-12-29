/*  Code that works with the [serial_print] Pd abstraction
 *  The only values you need to change if your circuit uses more or less 
 *  analog or digital pins are the first two constants, 
 *  numAnalogPins, and numDigitalPins.
 *  
 *  Analog pins you use must start from A0, and increment by 1.
 *  Digital pins you use must start from D2, and increment by 1.
 *  
 *  This code simply reads analog and digital pins, you can't use it
 *  with sensors like an ultra-sonic sensor, because they demand built-it functions
 *  in order to work.
 *  
 *  This code is in the public domain
 *  written by Alexandros Drymonits
 */

// analog values array size, must be constant
const int numAnalogPins = 3;
// digital_values array size, must be constant
const int numDigitalPins = 3;

// create an array to store the values of the potentiometers
int analogValues[numAnalogPins];
// create an array to store the values of the push-buttons
int digitalValues[numDigitalPins];

void setup() {
  for(int i = 0; i < numDigitalPins; i++){
    pinMode((i + 2), INPUT_PULLUP);
  }
  Serial.begin(9600);
}

void loop() {
  for(int i = 0; i < numAnalogPins; i++) analogValues[i] = analogRead(i);

  for(int i = 0; i < numDigitalPins; i++) digitalValues[i] = !digitalRead(i + 2);

  Serial.print("Analog_values:");
  for(int i = 0; i < numAnalogPins; i++){
    Serial.print(" ");
    Serial.print(analogValues[i]);
  }
  Serial.println();

  Serial.print("Digital_values:");
  for(int i = 0; i < numDigitalPins; i++){
    Serial.print(" ");
    Serial.print(digitalValues[i]);
  }
  Serial.println();
}

