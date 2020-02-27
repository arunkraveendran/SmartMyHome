//************************************************************************************//
//                               Copy Write @ Feb - 2020
//************************************************************************************//
//  File Name     : SMH_Distance_Measure.ino
//  Project       : SmartMyHome
//  Module        : Distance Measurement
//------------------------------------------------------------------------------------// 
//  Date          Author      Description
//------------------------------------------------------------------------------------//
//  27-Feb-2020   Arun        Initial Version
//************************************************************************************//

const int trigP = D0;
const int echoP = D1;

long duration;
int distance;
int distance_array[5];
int i = 0;

int Calculated_Distance;

void setup() 
{
  pinMode(trigP, OUTPUT);
  pinMode(echoP, INPUT);
  Serial.begin(9600);
}

int Calculate_Distance()
{
  
  digitalWrite(trigP, LOW);   // Makes trigPin low
  delayMicroseconds(2);       // 2 micro second delay 

  digitalWrite(trigP, HIGH);  // tigPin high
  delayMicroseconds(10);      // trigPin high for 10 micro seconds
  digitalWrite(trigP, LOW);   // trigPin low

  duration = pulseIn(echoP, HIGH);   //Read echo pin, time in microseconds
  distance= duration*0.034/2;        //Calculating actual/real distance

  //Serial.print("Distance = ");        //Output distance on arduino serial monitor 
  //Serial.println(distance);
  //delay(3000);                        //Pause for 3 seconds and start measuring distance again

  return (distance);
}


void loop() 
{

  Calculated_Distance = Calculate_Distance();
  
  Serial.print("Distance = ");        //Output distance on arduino serial monitor 
  Serial.println(Calculated_Distance);
  delay(500);

}
