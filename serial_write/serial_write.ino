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
const int num_of_analog_pins = 3;
// digital values array size, must be constant
const int num_of_digital_pins = 3;

// assemble number of bytes we need
// analog values are being split in two, so their number times 2
// and we need a unique byte to denote the beginning of the data stream
const int num_of_bytes = (num_of_analog_pins * 2) + num_of_digital_pins + 1;

// array to store all bytes
byte transfer_array[num_of_bytes];

void setup() {
  for(int i = 0; i < num_of_digital_pins; i++) pinMode((i + 2), INPUT_PULLUP);
  
  Serial.begin(57600);
}

void loop() {
  transfer_array[0] = 0xc0; // denote beginning of data
  int index = 1; // index offset
  
  // store the analog values to the array
  for(int i = 0; i < num_of_analog_pins; i++){
    int analog_val = analogRead(i);
    // split analog values so they can retain their 10-bit resolution
    transfer_array[index++] = analog_val & 0x007f;
    transfer_array[index++] = analog_val >> 7;
  }

  // store the digital values to the array
  for(int i = 0; i < num_of_digital_pins; i++)
    transfer_array[index++] = !digitalRead(i + 2);

  // transfer bytes over serial
  Serial.write(transfer_array, num_of_bytes);
}
