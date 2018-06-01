char leer;
int AdelA = 8;          //Define pin 1 de motor A
int AdelB = 9;          //Define pin 1 de motor B
int AtrasA = 10;          //Define pin 2 de motor A
int AtrasB = 11;          //Define pin 2 de motor B
int EnaAdel = 7;
int EnaAtras = 12;
int velocidad = 130;

const int ss1 = 27;  // sensor 1 del sigue línea
const int ss2 = 28;  // sensor 2 del sigue línea
const int ss3 = 29;  // sensor 3 del sigue línea
const int ss4 = 30;  // sensor 4 del sigue línea
const int ss5 = 31;  // sensor 5 del sigue línea
const int ss6 = 32;  // sensor Near o "cerca" del sigue línea
const int clp = 26;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
pinMode(ss1, INPUT);        //Define los pines del sigue línea como entradas
  pinMode(ss2, INPUT);
  pinMode(ss3, INPUT);
  pinMode(ss4, INPUT);
  pinMode(ss5, INPUT);
  pinMode(ss6, INPUT);
  pinMode(clp, INPUT);
}

int nv1_barra_otica(int p_anterior) //Define las instrucciones necesarias para captar la informacion de los sensores del sigue línea.
{ if (digitalRead(ss6) == 1 || digitalRead(clp) == 1) {
    return (0);
  }
  else if (digitalRead(ss3) == 0) {
    return (1);
  }
  else if (digitalRead(ss5) == 0) {
    return (3);
  }
  else if (digitalRead(ss1) == 0) {
    return (-3);
  }
  else if (digitalRead(ss4) == 0) {
    return (2);
  }
  else if (digitalRead(ss2) == 0) {
    return (-2);
  }
  else {
    return (p_anterior);
  }
}

void loop() {
  leer=Serial.read();
          // Boton ON,  se mueve sensando distancia
    if ((digitalRead(ss3) == LOW) || (digitalRead(ss3) == LOW) && (digitalRead(ss2) == LOW) && (digitalRead(ss4) == LOW))
    {
      Adel(); //Si el sensor ss3 no manda voltaje ó si ss2,ss3 y ss4 no mandan voltaje,el carro sigue derecho.
    }
    if ((digitalRead(ss1) == LOW) || (digitalRead(ss1) == LOW) && (digitalRead(ss2) == LOW))
    {
      Izq(); //Si el sensor ss1 no manda voltaje ó si ss1 y ss2 no mandan voltaje, el carro gira hacia la izquierda.
    }
    if ((digitalRead(ss5) == LOW) || (digitalRead(ss5) == LOW) && (digitalRead(ss4) == LOW))
    {
      Der(); //Si el sensor ss5 no manda voltaje ó si ss5 y ss4 no mandan voltaje, el carro gira hacia la derecha.
    }
    if (digitalRead(ss1) == LOW){
      Serial.println("ss1");
    }
    if (digitalRead(ss2) == LOW){
      Serial.println("ss2");
    }
    if (digitalRead(ss3) == LOW){
      Serial.println("ss3");
    }
    if (digitalRead(ss4) == LOW){
      Serial.println("ss4");
    }
    if (digitalRead(ss5) == LOW){
      Serial.println("ss5");
    }
    if (digitalRead(ss6) == HIGH){
      Serial.println("NEAR");
    }
  
}
    void Adel() {
  M_AtrasAdel();
  M_AdelDet();
}
void Der() {
  M_AdelDer();
  M_AtrasAdel();
}
void Izq() {
  M_AtrasAdel();
  M_AdelIzq();
}
void Ret() {
  M_AtrasRet();
  M_AdelDet();
}
void Detener() {
  M_AtrasDet();
  M_AdelDet();
}
void AdelDetDer(){
  M_AdelIzq();
  delay(200);
}
void AdelDetIzq(){
  M_AdelDer();
  delay(200);
}
void DerRet() {
  M_AtrasRet();
  M_AdelDer();
}
void IzqRet() {
  M_AtrasRet();
  M_AdelIzq();
}

void M_AdelDer() {
  digitalWrite(AdelA, LOW);
  digitalWrite(AdelB, HIGH);
  digitalWrite(EnaAdel,HIGH);
}
void M_AdelIzq() {
  digitalWrite(AdelB, LOW);
  digitalWrite(AdelA, HIGH);
  digitalWrite(EnaAdel,HIGH);
}
void M_AdelDet() {
  digitalWrite(AdelA, LOW);
  digitalWrite(AdelB, LOW);
  digitalWrite(EnaAdel,LOW);
}

void M_AtrasAdel() {
  digitalWrite(AtrasA, HIGH);
  digitalWrite(AtrasB, LOW);
  analogWrite(EnaAtras, velocidad);
}
void M_AtrasRet() {
  digitalWrite(AtrasB, HIGH);
  digitalWrite(AtrasA, LOW);
  analogWrite(EnaAtras, velocidad);
}
void M_AtrasDet() {
  digitalWrite(AtrasA, LOW);
  digitalWrite(AtrasB, LOW);
  analogWrite(EnaAtras, 0);
}


