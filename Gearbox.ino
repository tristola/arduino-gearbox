
//SET UP THE CORRECT PINS
const int gearUpPin = 31;
const int gearDownPin = 30;
const int buttonPin = 32;

// DELAYS
// delay between button presses (not to send press twice)
const int buttonListenDelay = 500;
//when signal is sent
const int gearChangeDelay = 2000;

//gear states
// 0-> 1 first gear
// 1-> 2 second gear
// 2-> 3 third gear
// 3-> 4 shift to second
// 4-> 0  shift to zero?
// 
int state = 0;
int buttonState;
int lastButtonState = LOW;
long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 50;

void setup() {
  pinMode(gearUpPin, OUTPUT);      
  pinMode(gearDownPin, OUTPUT);      
  pinMode(buttonPin, INPUT);     
}


void loop() {
  int reading = digitalRead(buttonPin);
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }
  
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
      if (buttonState == HIGH) {
        nextState();
      }
    }
  }
  lastButtonState = reading;
}

void nextState(){
  // only one code block is run
  if(state==0 || state == 1 || state == 2){
    gearUp();
    state++;
  } else if(state == 3){
    gearDown();
    state++;    
  } else if(state == 4){
    gearDown();
    gearDown();
    state=0;    
  }  
}

void gearUp() {
  digitalWrite(gearUpPin, HIGH); 
  delay(gearChangeDelay);              
  digitalWrite(gearUpPin, LOW);
}

void gearDown() {
  digitalWrite(gearDownPin, HIGH); 
  delay(gearChangeDelay);              
  digitalWrite(gearDownPin, LOW);
}
