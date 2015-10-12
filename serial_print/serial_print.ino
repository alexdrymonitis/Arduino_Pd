/*  Code that works with the [serial_print] Pd abstraction
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
// digital_values array size, must be constant
const int num_of_digital_pins = 3;

// create an array to store the values of the potentiometers
int analog_values[num_of_analog_pins];
// create an array to store the values of the push-buttons
int digital_values[num_of_digital_pins];

void setup() {
  for(int i = 0; i < num_of_digital_pins; i++){
    pinMode((i + 2), INPUT_PULLUP);
  }
  Serial.begin(9600);
}

void loop() {
  for(int i = 0; i < num_of_analog_pins; i++) analog_values[i] = analogRead(i);

  for(int i = 0; i < num_of_digital_pins; i++) digital_values[i] = !digitalRead(i + 2);

  Serial.print("Analog_values: ");
  for(int i = 0; i < (num_of_analog_pins - 1); i++){
    Serial.print(analog_values[i]);
    Serial.print(" ");
  }
  Serial.println(analog_values[num_of_analog_pins - 1]);

  Serial.print("Digital_values: ");
  for(int i = 0; i < (num_of_digital_pins - 1); i++){
    Serial.print(digital_values[i]);
    Serial.print(" ");
  }
  Serial.println(digital_values[num_of_digital_pins - 1]);
}

