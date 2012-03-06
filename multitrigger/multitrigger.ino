// Lab12 使用兩顆 74HC595 和三支腳位控制 16 顆 LED

// 接 74HC595 的 ST_CP (pin 12,latch pin)
int latchPin = 8;
// 接 74HC595 的 SH_CP (pin 11, clock pin)
int clockPin = 12;
// 接 74HC595 的 DS (pin 14)
int dataPin = 11;
//-------------
int command;





//--------------
void setup() {
  // 將 latchPin, clockPin, dataPin 設置為輸出
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop() {      
  for (int led = 0; led < 16; led++) {
    int numberToDisplay  = 1 << led;
    byte high_Byte = highByte(numberToDisplay);
    byte low_Byte = lowByte(numberToDisplay);
    
    // 送資料前要先把 latchPin 拉成低電位
    digitalWrite(latchPin, LOW);
    
    // 先送高位元組 (Hight Byte), 給離 Arduino 較遠的那顆 74HC595
    shiftOut(dataPin, clockPin, MSBFIRST, high_Byte);  
    // 再送低位元組 (Low Byte), 給離 Arduino 較近的那顆 74HC595
    shiftOut(dataPin, clockPin, MSBFIRST, low_Byte);  

    // 送完資料後要把 latchPin 拉回成高電位
    digitalWrite(latchPin, HIGH);
   
    delay(40);
  }
}
//再次提醒：在送資料前，記得要先把 latchPin 拉成低電位，
//緊接著使用 shiftOut() 函式送出資料，送完資料後還要把 latchPin 拉回高電位。
