#define enable  D2
#define xDir    D3 // X Axis Direction Pin
#define xStep   D4 // X Axis Step Pin
#define yDir    D5 // Y Axis Direction Pin
#define yStep   D6 // Y Axis Step Pin
#define zDir    D8 // Z Axis Direction Pin
#define zStep   D7 // Z Axis Step Pin

int steps = 200; // Nema17 steps = 200, with 16 microsteps = 3200
int stepDelay = 30; // Delay between each pause (uS)

void step(boolean dir, byte dirPin, byte stepperPin, int steps){
  digitalWrite(dirPin, dir);
  delay(100);
  for(int i=0; i<steps;i++){
    digitalWrite(stepperPin, HIGH);
//    delayMicroseconds(stepDelay);
    delay(1);
    digitalWrite(stepperPin, LOW);
    delay(1);
//    delayMicroseconds(stepDelay);
    
  }
}
void setup() {
 pinMode(xDir, OUTPUT);pinMode(xStep, OUTPUT);
 pinMode(yDir, OUTPUT);pinMode(yStep, OUTPUT);
 pinMode(zDir, OUTPUT);pinMode(zStep, OUTPUT);
 pinMode(enable,OUTPUT);
 digitalWrite(enable, LOW);
}

void loop() {
//  step(false,xDir,xStep,200); // X Axis Rotate Clockwise
//  step(false,yDir,yStep,200); // Y Axis Rotate Clockwise
  step(false,zDir,zStep,200); // Z Axis Rotate Clockwise
  delay(2000);
//  step(true,xDir,xStep,3200); // X Axis Rotate Clockwise
//  step(true,yDir,yStep,3200); // Y Axis Rotate Clockwise
  step(true,zDir,zStep,3200); // Z Axis Rotate Clockwise
  delay(2000);
}
