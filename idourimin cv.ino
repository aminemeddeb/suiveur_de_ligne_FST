int mr1=9;//imin l9odem
int mr0=8;//imin lteli
int ml1=6;//issar l9odem
int ml0=7;//issar lteli
int c2 = 3;
int c3 = A5 ;
int c4 = A4;
int c5 = A3;
int c6 = A0;
int c7 = A1;
int c8 = A2;
int c9 = 11;
int ena = 5;
int enb = 10;
int star=0;
//////
int angle;
int angledroit=200;
int angle2;
int dd=200;
int dd1=200;
/////
int bleu=0;
int comp=1;
int d=40;
float bms = 180;
float rms;
float lms;
float kp =8.5;
float kd =1;
int maxs=200;
int maxrms = 200;
int maxlms = 200;
int ms;
int lasterror = 0;
int currenttime=0;
void setup() {
  pinMode(c2, INPUT);
  pinMode(c3, INPUT);
  pinMode(c4, INPUT);
  pinMode(c5, INPUT);
  pinMode(c6, INPUT);
  pinMode(c7, INPUT);
  pinMode(c8, INPUT);
  pinMode(c9, INPUT);
  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);

pinMode(mr1, OUTPUT);            
  pinMode(ml1, OUTPUT);    
  digitalWrite(mr1, HIGH); 
  digitalWrite(ml1, HIGH); 

  analogWrite(enb,90);
  analogWrite(ena,125);


}

void loop() {
 
   int capt2 = digitalRead(c2);
   int capt3 = digitalRead(c3);
   int capt4 = digitalRead(c4);
   int capt5 = digitalRead(c5);
   int capt6 = digitalRead(c6);
   int capt7 = digitalRead(c7);
   int capt8 = digitalRead(c8);
   int capt9 = digitalRead(c9);
   int somme=capt2+capt3+capt4+capt5+capt6+capt7+capt8+capt9;
   ////doura loula 
      if (comp==1 && somme==4)
  {
    stops();
    delay(d+50);
    forward();
delay(230);

douraimin(1);
    comp+=2;
  }
  ////fas3a 
else if (comp==2&& capt2+capt3+capt4+capt5>=3)
{
  stops();
  delay(d+20);
  forward();
  delay(200);

  douraimin(2);
  comp++;
}
///triangle 60 
else if (comp==3&& capt2+capt3+capt4+capt5>=3)
{
    stops();
    delay(d);
    forward();
    delay(200);
    douraisar(3);
    comp++;
}
///triangle 60 
else if (comp==4&& capt2+capt3+capt4+capt5>=3)
{
    stops();
    delay(d);
    forward();
    delay(200);
    douraisar(4);
    comp++;
}
//baad 60
else if (comp==5&& capt9+capt8+capt7>=2)
{
    stops();
  delay(d);
  forward();
  delay(100);
  douraimin(5);
  comp++;
}
//9bal el nos doura 
else if (comp==6&& capt9+capt8+capt7+capt6>=4)
{
    stops();
  delay(d);
  forward();
  delay(100);
  douraimin(6);
  comp++;
  bms=100;
}
//baad el nos doura 
else if (comp==7&& capt9+capt8+capt7+capt6>=3)
{
    stops();
  delay(d);
  forward();
  delay(100);
  douraimin(7);
  comp++;
  bms=180;
}
//9bal el nos doura thenia 
else if (comp==8&& capt9+capt8+capt7+capt6>=3)
{
    stops();
  delay(d);
  forward();
  delay(100);
  douraimin(8);
  comp++;
}
//bidha 
else if ((comp>=9&& capt2+capt3+capt4+capt5+capt6+capt7+capt8+capt9==0)&&comp<11)
{ if ((millis()-currenttime)>500) 
  {currenttime= millis();
  
    stops();
  delay(d);
  forward();
  delay(100);
  douraisar(9);
  comp++;
  }
}
//starr
else if ((comp>=9&& capt2+capt3+capt4+capt5+capt6+capt7+capt8+capt9==8)&&comp<=11)
{
    stops();
  delay(d);
  kodem();
  delay(100);
 star=1;
  comp=12;
}
//doura zar9a
else if ((comp==12&& capt2+capt3+capt4+capt5+capt6+capt7+capt8+capt9>=4)&&star)
{
    stops();
  delay(d);
  forward();
  delay(100);
  douraisar(10);
  comp++;
  kodem();
  delay(100);
  stops();
  delay(5000);
  bleu=1;
}
//irawaaaa7
else if ((comp==13&& capt2+capt3+capt4+capt5+capt6+capt7+capt8+capt9>=4)&&bleu)
{
  stops();
  delay(d);
 
  douraimin(11);
  comp++;
  bleu=0;
}
else if ((comp>=14&& capt2+capt3+capt4+capt5+capt6+capt7+capt8+capt9==0))
{
    stops();
  delay(d);
 
  
}


else{PID();}
}
 
      void stops(){
    digitalWrite(ena, 0);
    digitalWrite(enb, 0);
    }
void PID(){ 
  int capt2 = digitalRead(c2);
  int capt3 = digitalRead(c3);
  int capt4 = digitalRead(c4);
  int capt5 = digitalRead(c5);
  int capt6 = digitalRead(c6);
  int capt7 = digitalRead(c7);
  int capt8 = digitalRead(c8);
  int capt9 = digitalRead(c9);

 int error= -55*capt2 + -40*capt3 + -25*capt4 + -10*capt5 + 10*capt6+ 25*capt7+ 40*capt8 + 55*capt9;
 
 ms = kp*error +kd*(error-lasterror);
 
 rms = bms - ms;
 lms = bms + ms;
 lasterror = error;

 if(lms > maxlms){lms = maxlms;}

 if(lms < 0){lms = 0;}

 if(rms < 0){rms = 0;}

 if(rms > maxrms){rms = maxrms;}

  analogWrite(ena,rms);
  analogWrite(enb,lms);
  
if( capt9 || capt8 || capt7){right();}


else if(capt2 || capt3 || capt4){left();}


else {forward();}



}
void kodem(){
analogWrite(enb,bms);
  analogWrite(ena,bms);
 
  
}
void forward(){
  analogWrite(enb,lms);
  analogWrite(ena,rms);
 
}
void right(){

  analogWrite(enb,lms);
 

}
void left (){
 analogWrite(ena,rms); 

}
void douraimin(int a){
   switch(a-1) {
  //angle droit 
  case 0:
  angle=angledroit;
 break;

  case 4:
  case 5:
  case 6:
  case 7:
    angle=angledroit-65;
    break;
    case 2: 
    angle=280 ;
    break;
    case 3: 
    angle =300 ;
    break;
   
    
    
  case 8:
angle= 130;  
  break;
  case 9:
angle= 400;  
  break;
  case 10:
    angle=260;
  break;
}

  digitalWrite(mr1, HIGH); 
  digitalWrite(mr0, LOW); 
  digitalWrite(ml1, LOW); 
  digitalWrite(ml0, HIGH); 
  analogWrite(enb,maxs);
  analogWrite(ena,70);

 
  delay(angle);
  digitalWrite(mr1, HIGH); 
  digitalWrite(mr0, LOW); 
  digitalWrite(ml0, LOW); 
  digitalWrite(ml1, HIGH); 
  
  forward();
  delay(100);
}

void douraisar(int a){
  switch(a-1) {
  //angle droit 
   case 0:
  angle=angledroit;
 break;
 case 1:
angle=150;  
break;
  case 2:  
  angle=280;
  break;
    case 3:

    angle =300 ;
    break;
  case 4:

  case 5:
  case 6:
 case 7:
  {
    angle=angledroit-65;
}
break;
  case 8:
angle= 130;  
  
    break;
  case 9:
angle= 400;  
  break;
     case 10:
    angle=260;
  break;
}
digitalWrite(mr0, HIGH); 
  digitalWrite(mr1, LOW); 
  digitalWrite(ml0, LOW); 
  digitalWrite(ml1, HIGH); 
  analogWrite(ena,maxs);
  analogWrite(enb,70);

 
  delay(angle);
    digitalWrite(mr1, HIGH); 
  digitalWrite(mr0, LOW); 
  digitalWrite(ml0, LOW); 
  digitalWrite(ml1, HIGH); 


  forward();
  delay(100);

  
}