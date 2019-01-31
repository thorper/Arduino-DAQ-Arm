int inPin = 7;
int a0Pin = 0;
int a1Pin = 1;
int a2Pin = 2;
int val;
double a0;
double a1;
double a2;
unsigned long durationHigh;
unsigned long durationLow;
unsigned long durationTot;
unsigned long RPM;
unsigned long totSum;
unsigned long totAvg;
int avgNum = 2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);
  pinMode(inPin,INPUT);
}

void loop() {

  //RPM
  totSum = 0;
  for (int i=0; i<avgNum; i++){
    durationHigh = pulseIn(inPin, HIGH);
    durationLow = pulseIn(inPin, LOW);
    durationTot = durationHigh + durationLow;
    totSum = durationTot + totSum;
  }
  totAvg = totSum/avgNum;
  RPM = (1/(totAvg*1e-6))*60;

  //A0
    a0 = (5.0 * analogRead(a0Pin) * 100.0) / 1024;
  //  a0 = (5.0 * analogRead(a0Pin))/10;

  //A1
  //  val = analogRead(a1Pin);
  a1 = (5.0 * analogRead(a1Pin)/1024);

  //A2
  //  val = analogRead(a1Pin);
  a2 = (5.0 * analogRead(a2Pin)/1024);
  
  Serial.print(durationTot);
  Serial.print(" us");
  Serial.print("\t");
  Serial.print(RPM);
  Serial.print(" rpm");
  Serial.print("\t");
  Serial.print(a0);
  Serial.print(" C");
  Serial.print("\t");
  Serial.print(a1);
  Serial.print(" V");
  Serial.print("\t");
  Serial.print(a2);
  Serial.println(" lum");
}
