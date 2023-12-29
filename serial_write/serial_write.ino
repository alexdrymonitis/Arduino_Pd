/*  Code that works with the [serial_write] Pd abstraction
 *  The only values you need to change if your circuit uses more or less 
 *  analog or digital pins are the first two constants, 
 *  num_of_analog_pins, and num_of_digital_pins.
 *  
 *  Analog pins you use must start from A0, and increment by 1.
 *  Digital pins you use must start from D2, and increment by 1.
 *  
 *  This code simply reads analog and digital pins, you can't use it
 *  with sensors like an ultra-sonic sensor, cause they demand built-it functions
 *  in order to work.
 *  
 *  This code is in the public domain
 *  written by Alexandros Drymonits
 */

// analog values array size, must be constant
const int numAnalogPins = 3;
// digital values array size, must be constant
const int numDigitalPins = 3;

// assemble number of bytes we need
// analog values are being split in two, so their number times 2
// and we need a unique byte to denote the beginning of the data stream
const int numBytes = (numAnalogPins * 2) + numDigitalPins + 1;

// array to store all bytes
byte transferArray[numBytes];

void setup() {
  for(int i = 0; i < numDigitalPins; i++) pinMode((i + 2), INPUT_PULLUP);
  
  Serial.begin(57600);
}

void loop() {
  byte transferArray[0] = 0xc0; // denote beginning of data
  int index = 1; // index offset
  
  // store the analog values to the array
  for(int i = 0; i < numAnalogPins; i++){
    int analogVal = analogRead(i);
    // split analog values so they can retain their 10-bit resolution
    byte transferArray[index++] = analogVal & 0x007f;
    byte transferArray[index++] = analogVal >> 7;
  }

  // store the digital values to the array
  for(int i = 0; i < numDigitalPins; i++)
    byte transferArray[index++] = !digitalRead(i + 2);

  // transfer bytes over serial
  Serial.write(byte transferArray, numBytes);
}
