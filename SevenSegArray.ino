/*
  Multi-digit 7-segment Display Array Controller
 
  Controls N-digit 7-segment display. Both Common Anode and Common Cathode displays supported.
 
 created 2 Jul 2013
 by A. Saieed - a DOT saieed AT gmail.com

 Licensed under CC-BY-NC-SA 3.0 - http://creativecommons.org/licenses/by-nc-sa/3.0/
 
*/

#include "math.h"

// Tested on Arduino 2560. Might not work with UNO.

void intTo7Seg(int num);

int a,b,c,d,e,f,g;

int number = 12345;

int freq;

// The number of pins for the digit enablers in enable_digit[], implicitly defines the
// number of 7-segment used.

// Example:
// enable_digit[] = {1, 2, 3};
// defines a 3-digit 7-segment whose selector pins are connected to the Arduino at pins 1, 2 and 3.

enable_digit[] = { 3, 4, 5, 6, 7};

const int num_digits = 5;

int enable_digit[num_digits];
int digits[num_digits+1];

void setPins(int a, int b, int c, int d, int e, int f, int g)



setPins(int a_pin, int b_pin, int c_pin, int d_pin, int e_pin, int f_pin, int g_pin) {
  a = a_pin;
  b = b_pin;
  c = c_pin;
  d = d_pin;
  e = e_pin;
  f = f_pin;
  g = g_pin;
  
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
}

void sevseg_off() {
 // initialize to OFF
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

void setup() {

  // call setpins to set it up.
  setPins(28, 30, 26, 24, 22, 32, 34);
  
  sevseg_off();

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

