void setup() {
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()){
    byte in_byte = Serial.read();
    if(in_byte == 0){
      Serial.print("receive_float\t");
      Serial.println(PI);
    }
    else if(in_byte == 1){
      Serial.print("receive_string\t");
      Serial.println("this_is_a_string");
    }
    else if(in_byte == 2){
      Serial.print("receive_bang\t");
      Serial.println("bang");
    }
  }
}
