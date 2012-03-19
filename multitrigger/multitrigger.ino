
#include <ICGroup.h>
// Lab12 使用兩顆 74HC595 和三支腳位控制 16 顆 LED

// 接 74HC595 的 ST_CP (pin 12,latch pin)
//int latchPin = 8;
//// 接 74HC595 的 SH_CP (pin 11, clock pin)
//int clockPin = 12;
//// 接 74HC595 的 DS (pin 14)
//int dataPin = 11;
//-------------
int command;

ICGroup g1(2,3,4);



//--------------
void setup() {

  g1.setup();
  Serial.begin(9600);
}

void loop() {      
  receiver();  
  g1.update();
  
}
//再次提醒：在送資料前，記得要先把 latchPin 拉成低電位，
//緊接著使用 shiftOut() 函式送出資料，送完資料後還要把 latchPin 拉回高電位。
