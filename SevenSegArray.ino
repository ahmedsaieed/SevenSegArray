/*
  Multi-digit 7-segment Display Array Controller
 
  Controls N-digit 7-segment display. Both Common Anode and Common Cathode displays supported.
 
 created 2 Jul 2013
 by A. Saieed - a DOT saieed AT gmail.com

 Licensed under CC-BY-NC-SA 3.0 - http://creativecommons.org/licenses/by-nc-sa/3.0/
 
*/

#include "math.h"

// Tested on Arduino 2560. Might not work with UNO.

#define SEG_ON HIGH
#define SEG_OFF LOW
#define DIGIT_ON HIGH // Inverted
#define DIGIT_OFF LOW // Inverted

void intTo7Seg(int num);

int a,b,c,d,e,f,g;

int number = 1;

int freq;

// Example:
// enable_digit[] = {1, 2, 3};
// defines a 3-digit 7-segment display whose selector pins are connected to the Arduino at pins 1, 2 and 3.
int enable_digit[] = { 3, 4, 5, 6, 7};

const int num_digits = 5;

int digits[num_digits];

void setPins(int a_pin, int b_pin, int c_pin, int d_pin, int e_pin, int f_pin, int g_pin) {
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
};

void allOff() {
 // initialize to OFF
  digitalWrite(a, SEG_OFF);
  digitalWrite(b, SEG_OFF);
  digitalWrite(c, SEG_OFF);
  digitalWrite(d, SEG_OFF);
  digitalWrite(e, SEG_OFF);
  digitalWrite(f, SEG_OFF);
  digitalWrite(g, SEG_OFF);

  digitalWrite(enable_digit[0], DIGIT_OFF);
  digitalWrite(enable_digit[1], DIGIT_OFF);
  digitalWrite(enable_digit[2], DIGIT_OFF);
  digitalWrite(enable_digit[3], DIGIT_OFF);
  digitalWrite(enable_digit[4], DIGIT_OFF);
 
};

void setup() {

  // call setPins to set it up.
  setPins(28, 30, 26, 24, 22 ,32, 34);
  
  allOff();

}

void loop() {
  number++;
  freq = number;

  //  Serial.println(myEnc1000.read()); 
  if (freq < 0)
    freq = 0;
  else if (freq > 25000)
    freq = 25000;

  for (int current_digit = num_digits-1; current_digit >= 0; current_digit--) {
    digits[current_digit] = freq % 10;
    freq/=10;
  }
  
//  digits[4] = freq % 10;
//  //Serial.println(digits[4]);
//  freq = freq / 10;
//  digits[3] = freq % 10;
//  //Serial.println(digits[3]);
//  freq = freq / 10;
//  digits[2] = freq % 10;
//  //Serial.println(digits[2]);
//  freq = freq / 10;  
//  digits[1] = freq % 10;
//  //Serial.println(digits[1]);
//  freq = freq / 10;
//  digits[0] = freq % 10;
//  //Serial.println(digits[0]);

  allOff();


  for(int current_digit = 0; current_digit < num_digits; current_digit++) {

    digitalWrite(enable_digit[current_digit],DIGIT_ON);

    intTo7Seg (digits[current_digit]);
    
    delay(1);
    digitalWrite(enable_digit[current_digit],DIGIT_OFF);
    

//    digitalWrite(a, SEG_OFF);
//    digitalWrite(b, SEG_OFF);
//    digitalWrite(c, SEG_OFF);
//    digitalWrite(d, SEG_OFF);
//    digitalWrite(e, SEG_OFF);
//    digitalWrite(f, SEG_OFF);
//    digitalWrite(g, SEG_OFF);

    //delay(1);


  }
}


void intTo7Seg(int num) {


  switch (num) {
  case 0:
    digitalWrite(a, SEG_ON);
    digitalWrite(b, SEG_ON);
    digitalWrite(c, SEG_ON);
    digitalWrite(d, SEG_ON);
    digitalWrite(e, SEG_ON);
    digitalWrite(f, SEG_ON);
    digitalWrite(g, SEG_OFF);

    break;

  case 1:
    digitalWrite(a, SEG_OFF);
    digitalWrite(b, SEG_ON);
    digitalWrite(c, SEG_ON);
    digitalWrite(d, SEG_OFF);
    digitalWrite(e, SEG_OFF);
    digitalWrite(f, SEG_OFF);
    digitalWrite(g, SEG_OFF);

    break;

  case 2:
    digitalWrite(a, SEG_ON);
    digitalWrite(b, SEG_ON);
    digitalWrite(c, SEG_OFF);
    digitalWrite(d, SEG_ON);
    digitalWrite(e, SEG_ON);
    digitalWrite(f, SEG_OFF);
    digitalWrite(g, SEG_ON);

    break;

  case 3:
    digitalWrite(a, SEG_ON);
    digitalWrite(b, SEG_ON);
    digitalWrite(c, SEG_ON);
    digitalWrite(d, SEG_ON);
    digitalWrite(e, SEG_OFF);
    digitalWrite(f, SEG_OFF);
    digitalWrite(g, SEG_ON);

    break;


  case 4:
    digitalWrite(a, SEG_OFF);
    digitalWrite(b, SEG_ON);
    digitalWrite(c, SEG_ON);
    digitalWrite(d, SEG_OFF);
    digitalWrite(e, SEG_OFF);
    digitalWrite(f, SEG_ON);
    digitalWrite(g, SEG_ON);

    break;

  case 5:
    digitalWrite(a, SEG_ON);
    digitalWrite(b, SEG_OFF);
    digitalWrite(c, SEG_ON);
    digitalWrite(d, SEG_ON);
    digitalWrite(e, SEG_OFF);
    digitalWrite(f, SEG_ON);
    digitalWrite(g, SEG_ON);

    break;

  case 6:
    digitalWrite(a, SEG_ON);
    digitalWrite(b, SEG_OFF);
    digitalWrite(c, SEG_ON);
    digitalWrite(d, SEG_ON);
    digitalWrite(e, SEG_ON);
    digitalWrite(f, SEG_ON);
    digitalWrite(g, SEG_ON);

    break;

  case 7:
    digitalWrite(a, SEG_ON);
    digitalWrite(b, SEG_ON);
    digitalWrite(c, SEG_ON);
    digitalWrite(d, SEG_OFF);
    digitalWrite(e, SEG_OFF);
    digitalWrite(f, SEG_OFF);
    digitalWrite(g, SEG_OFF);

    break;

  case 8:
    digitalWrite(a, SEG_ON);
    digitalWrite(b, SEG_ON);
    digitalWrite(c, SEG_ON);
    digitalWrite(d, SEG_ON);
    digitalWrite(e, SEG_ON);
    digitalWrite(f, SEG_ON);
    digitalWrite(g, SEG_ON);

    break;

  case 9:
    digitalWrite(a, SEG_ON);
    digitalWrite(b, SEG_ON);
    digitalWrite(c, SEG_ON);
    digitalWrite(d, SEG_ON);
    digitalWrite(e, SEG_OFF);
    digitalWrite(f, SEG_ON);
    digitalWrite(g, SEG_ON);

    break;



  }

}

