//
//  ICGroup.h
//  ICGroup
//
//  Created by kinochen on 12/3/19.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#ifndef ICGroup_ICGroup_h
#define ICGroup_ICGroup_h

#include "Arduino.h"
#include "Clocks.h"

class ICGroup{
public:
    ICGroup(int latch, int clock, int data);
    void setup();
    void update();
    void setInterval(int ic,int clock,int interValue);
private:
    void writeOut();
    void passValue(int ic);
    void setBytes(int ic, int c);
    void setBytes2(int ic, int c);
    int latchPin;
    int clockPin;
    int dataPin;
    
    int HC595[4]; //0 for 01; 1 for 23; 2 for 45 ; 3 for 67
    
//        int HC595_1_0; 
//        //highByte(HC595_1_0)is for IC1 ;lowByte(HC595_1_0)is for IC0;
//        int HC595_3_2; //
//        //highByte(HC595_3_2)is for IC3 ;lowByte(HC595_3_2)is for IC2;
//        int HC595_5_4; 
//        //highByte(HC595_5_4)is for IC5 ;lowByte(HC595_5_4)is for IC4;
//        int HC595_7_6; //
//        //highByte(HC595_7_6)is for IC7 ;lowByte(HC595_7_6)is for IC6;

    
    //Clocks c1;
    Clocks clocks[4][8];
    
};
#endif
