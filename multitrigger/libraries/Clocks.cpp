//
//  Clocks.cpp
//  ICGroup
//
//  Created by kinochen on 12/3/19.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#include "Clocks.h"

Clocks::Clocks(){
    interval = 150;
    LOut = 1;
    ROut = 1;
    previousMillis = 0;
    state = 0;
    bytePositionL = 0;
    bytePositionR = 0;
    
}
void Clocks::setOutputByte(int pL, int pR){
    bytePositionL = pL;
    bytePositionR = pR;
}
void Clocks::update(){
    
    unsigned long currentMillis = millis();
    if(currentMillis - previousMillis > interval){
        previousMillis = currentMillis;
        if(state == LOW)
            state = 1;
        else
            state = 0;
        
        LOut = state;
        ROut = 1-state;
        
    }



}

void Clocks::setInterval(int in){
    interval = in;
}    
int  Clocks::getInterval(){
    return interval;
}
int Clocks::writeLOut(){
    return LOut;
}
int Clocks::writeROut(){
    return ROut;
}
int Clocks::getLOutByte(){
    return bytePositionL;
}
int Clocks::getROutByte(){
    return bytePositionR;
}