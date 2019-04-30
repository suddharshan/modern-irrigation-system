const int trigPin = 9;
const int echoPin = 8;

// defines variables
long duration;
float distance;
float vol;
char a;

void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
pinMode(7,OUTPUT);
Serial.begin(9600); // Starts the serial communicati


}



void loop() {
  
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= (duration*0.034/2)+1;
vol=(3.14/4)*(10)*(10)*(11-distance);

// Prints the distance on the Serial Monitor

Serial.print("Distance: ");
Serial.print(distance);
Serial.print("cm ");
Serial.print("Volume: ");
Serial.print(vol);
Serial.print("ml");
Serial.println();
if(Serial.available()){
a=Serial.read();
Serial.println(a);
}
if(a=='O')
{
  digitalWrite(10,0);
  digitalWrite(11,1);
}
else if(a=='F')
{
  digitalWrite(10,0);
  digitalWrite(11,0);
}
if(distance>=8)
{
  
  digitalWrite(7,0);
  delay(1000);
  digitalWrite(7,1);
  digitalWrite(10,0);
  digitalWrite(11,0);
}


delay(600);

}
