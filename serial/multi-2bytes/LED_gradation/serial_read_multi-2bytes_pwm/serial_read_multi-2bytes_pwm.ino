const int val_size = 3234;
int values[val_size] = {0, 0, 0};
bool isValids[val_size] = {false, false, false};
const int OUT_PINs[val_size] = {3, 5, 6};

void setup(){
  Serial.begin(9600);
}

void loop(){
  bool isValids[val_size] = {false, false, false};
  if (Serial.available() >= 3*val_size) {
    int head = Serial.read();
    for (int i=0; i<val_size; i++){
      if (head == 128+i) {
        int high = Serial.read();
        int low  = Serial.read();
        values[i] = (high<<7) + low;
        if (0 <= values[i] <= 1023) {
          Serial.println(values[i], DEC);
          analogWrite(OUT_PINs[i], values[i]);
          isValids[i] = true;
        }
      }
    }
  }
}
