//
//  Clocks.h
//  ICGroup
//
//  Created by kinochen on 12/3/19.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#ifndef ICGroup_Clocks_h
#define ICGroup_Clocks_h
#include "Arduino.h"
class Clocks{

public:
    Clocks();
    void setOutputByte(int pL, int pR);
    void update();
    void setInterval(int in);
    int  getInterval();
    
    int writeLOut();
    int writeROut();
    int getLOutByte();
    int getROutByte();
    
private:
    int LOut,ROut;
    int bytePositionL;//for LOut
    int bytePositionR;//for ROut
    
    int interval;
    long previousMillis;
    int state;
    

};
#endif
