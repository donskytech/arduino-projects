const int POT_PIN = 0;
const int PIN_SIZE = 9;
int pinArray[PIN_SIZE] = {10,9,8,7,6,5,4,3,2};

void setup() {
  Serial.begin(9600); 
  
  // set the digital pin as output:
  for(int iCtr=0; iCtr < PIN_SIZE; iCtr++){
    pinMode(pinArray[iCtr], OUTPUT);
  }
}

void loop() {
  // Read potentiometer value
  int val = analogRead(POT_PIN);
  // Map the value of the analog read into the number of LED's that we have
  int map_value = map(val, 0, 1023, 0, 8);
  // Light up the LED's upto the corresponding value
  setStripValue(map_value);
}

void setStripValue(int value){
  //Turn off ALL LED's initially
  for(int iCtr=0; iCtr < PIN_SIZE; iCtr++){
    digitalWrite(pinArray[iCtr], LOW);
  }

  //Turn on only LED's upto the corresponding value
  for(int iCtr=0; iCtr <= value; iCtr++){
    digitalWrite(pinArray[iCtr], HIGH);
  }
}
