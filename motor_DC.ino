int IN3 = 5; 
int IN4 = 4;
int IN2 = 3;
int IN1 = 2;
int BluetoothData;
char unChar;

void setup()
{ Serial1.begin(9600); 
  pinMode (IN4, OUTPUT);    // Input4 conectada al pin 4 
  pinMode (IN3, OUTPUT);    // Input3 conectada al pin 5
  pinMode (IN2, OUTPUT);    
  pinMode (IN1, OUTPUT);
}
void loop()
{ unChar=Serial1.read();
  if (unChar == 'c'){
  digitalWrite (IN4, HIGH);
  digitalWrite (IN3, LOW);
  digitalWrite (IN2, HIGH);
  digitalWrite (IN1, LOW); 
  delay(4000);}
  // Motor no gira
  if (unChar == 'd'){
  digitalWrite (IN4, LOW);
  digitalWrite (IN2, LOW); 
  delay(500);}
  // Motor gira en sentido inverso
  if (unChar == 'e'){
  digitalWrite (IN3, HIGH);
  digitalWrite (IN1, HIGH);
  delay(4000);}
  // Motor no gira
  if (unChar == 'f'){
  digitalWrite (IN3, LOW);
  digitalWrite (IN1, LOW); 
  delay(5000);}
}
