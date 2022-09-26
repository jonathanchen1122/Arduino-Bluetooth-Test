#include <Servo.h>

Servo beats;


static int c2=65,    cs2=69,   d2=73,    ds2=78,   e2=82,    f2=87,    fs2=93,   g2=98,
 gs2=104,  a2=110,   b2=123,   c3=131,   cs3=139,  d3=147,   ds3=156,  e3=165,   f3=175,
 fs3=185,  g3=196,   gs3=208,  a3=220,   as3=233,  b3=247,   c4=262,   cs4=277,  d4=294,
 ds4=311,  e4=330,   f4=349,   fs4=370,  g4=392,   gs4=415,  a4=440,   as4=466,  b4=494,
 c5=523,   cs5=554,  d5=587,   ds5=622,  e5=659,   f5=698,   fs5=740,  g5=784,   gs5=831,
 a5=880,   as5=932,  b5=988,   c6=1047,  cs6=1109, d6=1175,  ds6=1245, e6=1319,  f6=1397,
 fs6=1480, g6= 1568, gs6=1661, a6=1760,  as6=1865, b6=1976,  c7= 2093, cs7=2217, d7=2349,
 ds7=2489, e7=2637,  f7=2794,  fs7=2960, g7= 3136, gs7=3322, a7= 3520, as7=3729, b7=3951,
 c8=4186,  cs8=4435, d8=4699,  ds8=4978;

double Qrt=250, Hf=500, full=1000;

int state = 0;

void Notes(int note, int notedrag, int pauseTime) {
    tone(8, note, notedrag);
    delay(notedrag + pauseTime);
}

void MusicScale() {
  Notes(e4,1.5*Qrt,0); Notes(f4,Qrt/2,0); beats.write(50); Notes(e4,Qrt/2,0);  beats.write(0); Notes(ds4,Qrt/2,0); Notes(e4,Qrt,0); beats.write(50); Notes(c5,Qrt,0);  
  
   beats.write(100); Notes(b4,1.5*Hf,Hf);  bass();
  
  Notes(e4,1.5*Qrt,0); Notes(f4,Qrt/2,0); beats.write(50); Notes(e4,1.5*Qrt/2,0); 
  beats.write(0); Notes(ds4,1.5*Qrt/2,0); beats.write(50); Notes(e4,Qrt,0); Notes(c5,Qrt,0); beats.write(100);  Notes(a4,1.5*Hf,Hf); bass();
  
  Notes(a4,1.5*Qrt,0); Notes(b4,Qrt/2,0); beats.write(50); Notes(a4,1.5*Qrt/2,0);  beats.write(0); Notes(gs4,1.5*Qrt/2,0); beats.write(50); Notes(a4,Qrt,0); Notes(e5,Qrt,0);
  Notes(d5,Qrt,Qrt); Notes(d5,Qrt/2,0); beats.write(100); Notes(d5,Qrt,0); Notes(d5,Qrt,Qrt/2); Notes(e5,Qrt/2,0); beats.write(50);
  
  Notes(d5,Qrt,0); beats.write(0); Notes(c5,Hf,0); bass(); delay(Qrt); bass();
  
  Notes(c5,Qrt,0); Notes(d5,Qrt,0);  beats.write(50); Notes(e5,Qrt,0);  Notes(e5,Qrt*1.5,0); Notes(d5,Qrt/2,Qrt/2); Notes(d5,Qrt,Qrt); beats.write(0);
  Notes(d5,Qrt,0); Notes(e5,Qrt,0); beats.write(50); Notes(d5,Qrt,0);  Notes(d5,Qrt*1.5,0); Notes(c5,Qrt/2,Qrt/2); Notes(c5,Hf,Hf); beats.write(100);
 
  Notes(a4,Qrt,0); Notes(b4,Qrt,0); Notes(c5,Qrt*1.5,0); beats.write(50);  Notes(d5,Qrt/2,0); Notes(c5,Qrt,0);  Notes(b4,Qrt/2,Qrt/2); beats.write(0); 
  Notes(e5,Qrt/2,Qrt/2); Notes(c5,Qrt/2,Qrt/2); 
  
  Notes(a4,Hf*1.5,0); chear(); delay (full); 


  //second chorus
  // a4 b4 cs5 d5 e5    a4 cs5 e5 g5 f5 e5 f5 
  Notes(a4,Qrt/2,0); Notes(b4,Qrt/2,0); Notes(cs5,Qrt/2,0); Notes(d5,Qrt/2,0); Notes(e5,Hf,0);
  Notes(a4,Hf,0); Notes(cs5,Qrt,0); Notes(e5,Qrt,0); Notes(g5,Qrt,0); Notes(f5,Qrt*1.5,0); Notes(e5,Qrt/2,0); Notes(f5,Qrt*3,0); 
  // d5 g4 g4           b4 d5  f5 e5 ds5 e5
  Notes(d5 Notes(g4 Notes(g4          Notes(b4 Notes(d5  Notes(f5 Notes(e5 Notes(ds5 Notes(e5
  // a4 b4 c5           g4 e5 f5 e5 b4 
  // c5 d5 e5           a4 a5 a5 gs5 a5 b5 gs5 e5

  //third chorus (main)
}

void chear() {
  beats.write(135);
  delay(full);
  beats.write(-135);
  delay(full);
  beats.write(0);
  delay(full);
}

void bass() {
  beats.write(45);
  delay(Qrt);
  beats.write(0);
  delay(Qrt);
}
 
void setup() {
  beats.attach(7);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    state = Serial.read();
  }
  
  else if (state == '1') {
    beats.write(0); 
  }

  else if (state == '2'){
    bass();
  }

  else if (state == '3') {
    chear();
  }

  else if (state == '4') {
    MusicScale();
  }

  else {
    
  }
}
