#define MAX_RAND 10000

String strings[3] = { "one_string", "another_string", "last_string" };
int string_counter = 0;

String list_strings[3] = { "a_string_in_a_list", "another_list_string", "last_list_string" };
int list_str_cnt = 0;

float a_float, another_float, negative_float;
int an_int;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()){
    byte in_byte = Serial.read();
    
    switch(in_byte){
      case 0:
        a_float = (float)random(MAX_RAND) / (float)MAX_RAND;
        Serial.print("a_float\t");
        // print a float with five digits
        Serial.println(a_float, 5);
        break;

      case 1:
        Serial.print("a_string\t");
        Serial.println(strings[string_counter]);
        string_counter++;
        if(string_counter >= 3) string_counter = 0;
        break;

      case 2:
        Serial.print("a_bang\t");
        Serial.println("bang");
        break;

      case 3:
        negative_float = ((float)random(MAX_RAND) / (float)MAX_RAND) * -1.0;
        Serial.print("negative_float\t");
        Serial.println(negative_float, 5);
        break;

      case 4:
        an_int = random(MAX_RAND);
        another_float = (float)random(MAX_RAND) / (float)MAX_RAND;
        Serial.print("mixed_list\t");
        Serial.print(list_strings[list_str_cnt]); Serial.print("\t");
        Serial.print(another_float, 5); Serial.print("\t");
        Serial.print(an_int); Serial.print("\t");
        // the bang can't be included in a list in Pd, so it will be output last
        // no matter where it's placed in the Arduino code
        Serial.println("bang");
        list_str_cnt++;
        if(list_str_cnt >= 3) list_str_cnt = 0;
        break;
    }
  }
}
