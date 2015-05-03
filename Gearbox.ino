
//SET UP THE CORRECT PINS
const int gearUpPin = 22;
const int gearDownPin = 20;
const int changeSignal = 7;

// DELAYS
// delay between button presses (not to send press twice)
const int buttonListenDelay = 500;
//when signal is sent
const int gearChangeDelay = 500;

// 
int state = 0;

void setup() {
  pinMode(gearUpPin, OUTPUT);      
  pinMode(gearDownPin, OUTPUT);      
  pinMode(changeSignal, INPUT);     
}

void loop() {
  //Constantly listening to button
  int buttonState = digitalRead(changeSignal);
  if (changeSignal == HIGH) {     
    nextState();
    delay(buttonListenDelay); 
  } 
}

// This is for changing from state to state
//gear states
// 0-> 1 first gear
// 1-> 2 second gear
// 2-> 3 third gear
// 3-> 4 shift to second
// 4-> 0  shift to zero?

void nextState(){
  // only one code block is run
  if(state==0 || state == 1 || state == 2){
    gearUp();
    state++;
  } else if(state == 3){
    gearDown();
    state--;    
  } else if(state == 4){
    gearDown();
    gearDown();
    state=0;    
  }  
}
void gearUp() {
  digitalWrite(gearUpPin, HIGH); 
  delay(gearChangeDelay);              
  digitalWrite(gearUpPin, LOW)
}

void gearDown() {
  digitalWrite(gearDownPin, HIGH); 
  delay(gearChangeDelay);              
  digitalWrite(gearDownPin, LOW)
  
}
