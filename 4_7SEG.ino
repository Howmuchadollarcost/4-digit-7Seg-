/** Code by Muluberhan Yonas
 *  This is a 4 digit 7 segment counter. The pins from 2 upto 8 control the led of the 7 segments, while pins 9-13 control the digit that are being activated   
 *  
 *  pin 2 = a
 *  pin 3 = b
 *  pin 4 = c
 *  pin 5 = d
 *  pin 6 = e
 *  pin 7 = f
 *  pin 8 = g
 *  
 *  pin 9 = D4
 *  pin 10 = D3
 *  pin 11 = D2
 *  pin 13 = D3
 *  
 *  The variable time controls the speed of the counter. Num_array is a 2D array with different combinations of led lightings that makes decimal numbers from 0-9(and hex, from 0 to f).
*/



int pins[] = {2, 3, 4, 5, 6, 7, 8};

//Digits placing
int D1 = 12;
int D2 = 11;
int D3 = 10;
int D4 = 9;

int time = 1000;


int buttonState =  0;

int num_array[16][7] = {  { 1, 1, 1, 1, 1, 1, 0 }, // 0
  { 0, 1, 1, 0, 0, 0, 0 }, // 1
  { 1, 1, 0, 1, 1, 0, 1 }, // 2
  { 1, 1, 1, 1, 0, 0, 1 }, // 3
  { 0, 1, 1, 0, 0, 1, 1 }, // 4
  { 1, 0, 1, 1, 0, 1, 1 }, // 5
  { 1, 0, 1, 1, 1, 1, 1 }, // 6
  { 1, 1, 1, 0, 0, 0, 0 }, // 7
  { 1, 1, 1, 1, 1, 1, 1 }, // 8
  { 1, 1, 1, 0, 0, 1, 1 }, // 9
  { 1, 1, 1, 0, 1, 1, 1 }, // A
  { 0, 0, 1, 1, 1, 1, 1 }, // B
  { 1, 0, 0, 1, 1, 1, 0 }, // C
  { 0, 1, 1, 1, 1, 0, 1 }, // D
  { 1, 0, 0, 1, 1, 1, 1 }, // E
  { 1, 0, 0, 0, 1, 1, 1 }
}; // F


void setup() {
  for (int i = 2; i < 13; i++) {
    pinMode(i, OUTPUT);
  }

}

void loop() {
  offd(D1);
  offd(D2);
  offd(D3);
  offd(D4);

  int i, j;

  //The counter
  for (i = 0; i < 10000; i++) {
    for (j = 0; j <= (time / 20); j++) {
      ond(D1);
      num(i % 10);
      delay(5);
      offd(D1);

      ond(D2);
      num(i / 10 - 10 * (i / 100));
      delay(5);
      offd(D2);

      ond(D3);
      num(i / 100 - 10 * (i / 1000));
      delay(5);
      offd(D3);

      ond(D4);
      num(i / 1000);
      delay(5);
      offd(D4);
    }
  }


}


void on(int i) {
  digitalWrite(i, HIGH);
}

void off(int i) {
  digitalWrite(i, LOW);
}

void ond(int i) {
  digitalWrite(i, LOW);
}

void offd(int i) {
  digitalWrite(i, HIGH);
}


void num(int number)
{
  int pin = 2;
  for (int j = 0; j < 7; j++) {
    digitalWrite(pin, num_array[number][j]);
    pin++;
  }
}
