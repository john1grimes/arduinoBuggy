/* This code programs the buggy to stick to black
 *  If the left sensor is off the left wheel goes forward, while the right wheel reverses
 *  If the right sensor is off the right wheel goes forward, while the left wheel reverses
 *  The Ultrasonic sensor is not coded
*/
int vSpeed = 110;        // MAX 255
int turn_speed = 230;    // MAX 255 
int turn_delay = 100;
  
int IRsensorl = 3;
int IRsensorr = 11;

int left_forward = 5;
int left_backward = 6;
int right_forward = 2;
int right_backward = 12;

;

void setup() {
  pinMode(left_forward, OUTPUT);
  pinMode(left_backward, OUTPUT);
  pinMode(right_forward, OUTPUT);
  pinMode(right_backward, OUTPUT);
  pinMode(IRsensorl, INPUT);
  pinMode(IRsensorr, INPUT);
}

void loop() {
  digitalWrite(left_forward, HIGH);
  digitalWrite(left_backward, LOW);
  digitalWrite(right_forward, HIGH);
  digitalWrite(right_backward, LOW);//starting was "digitalWrite(righ_backward, HIGH)"

  //Serial.println(digitalRead(IRsensorl));
   const int black = 1;
   const int white = 0;
  int  right_sensor_state = digitalRead(IRsensorr);
  int  left_sensor_state = digitalRead(IRsensorl);
   
 if(right_sensor_state != black && left_sensor_state == black){
  Serial.println("turning right");

  digitalWrite (left_forward,HIGH);
  digitalWrite(left_backward,LOW);                       
  digitalWrite (right_forward,LOW);
  digitalWrite(right_backward,HIGH);
  
  delay(turn_delay);
  }
  
if(right_sensor_state == black && left_sensor_state != black)
{
  Serial.println("turning left");
  
  digitalWrite (left_forward,LOW);
  digitalWrite(left_backward,HIGH);                       
  digitalWrite (right_forward, HIGH);
  digitalWrite(right_backward,LOW);

  delay(turn_delay);
  }

if(right_sensor_state == white && left_sensor_state == white)
{
  Serial.println("going forward");

  digitalWrite(left_forward,HIGH); 
  digitalWrite (left_backward,LOW);
  digitalWrite(right_forward,HIGH);
  digitalWrite (right_backward,LOW);
  delay(turn_delay);
  
  }

if(right_sensor_state != black && left_sensor_state != black)
{ 
  Serial.println("stop");
  
  digitalWrite(left_forward, LOW);  
  digitalWrite (left_backward,LOW);
  digitalWrite(right_forward,LOW);                     
  digitalWrite (right_backward,LOW);
  
  }
}
