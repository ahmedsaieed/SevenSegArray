#include "math.h"


void intTo7Seg(int num);
int a,b,c,d,e,f,g;
int number = 12345;
int freq;

const int num_digits = 5;

int enable_digit[num_digits];
int digits[num_digits+1];


void setup() {

  a = 28;
  b = 30;
  c = 26;
  d = 24;
  e = 22;
  f = 32;
  g = 34;

  enable_digit[0] = 3;
  enable_digit[1] = 4;
  enable_digit[2] = 5;
  enable_digit[3] = 6;
  enable_digit[4] = 7;

  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);

  pinMode(enable_digit[0], OUTPUT);
  pinMode(enable_digit[1], OUTPUT);
  pinMode(enable_digit[2], OUTPUT);
  pinMode(enable_digit[3], OUTPUT);
  pinMode(enable_digit[4], OUTPUT);

  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);

  digitalWrite(enable_digit[0], LOW);
  digitalWrite(enable_digit[1], LOW);
  digitalWrite(enable_digit[2], LOW);
  digitalWrite(enable_digit[3], LOW);
  digitalWrite(enable_digit[4], LOW);



}

void loop() {
  number++;
  freq = number;
  //  Serial.println(myEnc1000.read()); 
  if (freq < 0)
    freq = 0;
  else if (freq > 25000)
    freq = 25000;

  digits[4] = freq % 10;
  //Serial.println(digits[4]);
  freq = freq / 10;
  digits[3] = freq % 10;
  //Serial.println(digits[3]);
  freq = freq / 10;
  digits[2] = freq % 10;
  //Serial.println(digits[2]);
  freq = freq / 10;  
  digits[1] = freq % 10;
  //Serial.println(digits[1]);
  freq = freq / 10;
  digits[0] = freq % 10;
  //Serial.println(digits[0]);

  digitalWrite(enable_digit[0],LOW);
  digitalWrite(enable_digit[1],LOW);
  digitalWrite(enable_digit[2],LOW);
  digitalWrite(enable_digit[3],LOW);
  digitalWrite(enable_digit[4],LOW);


  int current_digit = 0;

  for(current_digit = 0; current_digit < 5; current_digit++) {

    digitalWrite(enable_digit[current_digit],HIGH);

    intTo7Seg (digits[current_digit]);
    
    delay(1);
    digitalWrite(enable_digit[current_digit],LOW);
    

    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);

    //delay(1);


  }
}


void intTo7Seg(int num) {


  switch (num) {
  case 0:
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, LOW);

    break;

  case 1:
    digitalWrite(a, LOW);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);

    break;

  case 2:
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, LOW);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, LOW);
    digitalWrite(g, HIGH);

    break;

  case 3:
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, HIGH);

    break;


  case 4:
    digitalWrite(a, LOW);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);

    break;

  case 5:
    digitalWrite(a, HIGH);
    digitalWrite(b, LOW);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, LOW);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);

    break;

  case 6:
    digitalWrite(a, HIGH);
    digitalWrite(b, LOW);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);

    break;

  case 7:
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);

    break;

  case 8:
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);

    break;

  case 9:
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, LOW);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);

    break;



  }

}

