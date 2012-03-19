//
//  ICGroup.cpp
//  ICGroup
//
//  Created by kinochen on 12/3/19.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//
#include "ICGroup.h"
#include "Arduino.h"

ICGroup::ICGroup(int latch, int clock, int data){

    latchPin = latch;
    clockPin = clock;
    dataPin = data;
    
}
void ICGroup::setup(){
    pinMode(latchPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(dataPin, OUTPUT);
    
    for(int i = 0;i<4;i++){
        for(int j = 0;j < 8;j++){
            clocks[i][j].setOutputByte(j*2, j*2+1);       
        }
    } 
    
       // c1.setOutputByte(0, 1);
    
}

void ICGroup::update(){
    
    for(int i = 0;i<4;i++){
        for(int j = 0;j < 8;j++){
            clocks[i][j].update();
        
        }
    } 
    // c1.update();
    writeOut();
    
}
void ICGroup::writeOut(){
    

 

    for (int i=0; i<4; i++) {
         for(int j = 0;j < 8;j++){
             setBytes(i,j);
         }
    }
   //   setBytes(0);
            // 送資料前要先把 latchPin 拉成低電位
        digitalWrite(latchPin, LOW);       
      
        for (int i=0; i<4; i++) {
            passValue(i);
        }
       // passValue(0); 

        digitalWrite(latchPin, HIGH);
    
    
    
    
    
    
    
    for (int i=0; i<4; i++) {
        for(int j = 0;j < 8;j++){
            setBytes2(i,j);
        }
    }
    digitalWrite(latchPin, LOW);       
    for (int i=0; i<4; i++) {
        passValue(i);
    }
    digitalWrite(latchPin, HIGH);
    
        //delay(100);

}
void ICGroup::passValue(int ic ){

    shiftOut(dataPin, clockPin, MSBFIRST, highByte(HC595[ic]) );  
    shiftOut(dataPin, clockPin, MSBFIRST, lowByte( HC595[ic]) ); 
    
}

void ICGroup::setBytes(int ic,int c){
    bitWrite(HC595[ic], clocks[ic][c].getLOutByte() ,clocks[ic][c].writeLOut());
    bitWrite(HC595[ic], clocks[ic][c].getROutByte() ,clocks[ic][c].writeROut());
     
}
void ICGroup::setBytes2(int ic,int c){

    
    bitWrite(HC595[ic], clocks[ic][c].getLOutByte() ,0);
    bitWrite(HC595[ic], clocks[ic][c].getROutByte() ,0);
    
    
}
void ICGroup::setInterval(int ic,int clock,int interValue){
    clocks[ic][clock].setInterval(interValue);
}














