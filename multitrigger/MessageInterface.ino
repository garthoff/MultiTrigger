
union message{
 // String read_string; 
  byte read_byte[3];
  float  val; 
  unsigned int valint;
} msg;

void receiver(){
  if(Serial.available()>0  ){ // >2
//    msg.read_byte[0]=Serial.read();
//    msg.read_byte[1]=Serial.read();
//    msg.read_byte[2]=Serial.read();

int test = Serial.read();



     // checkFirstByte(msg.read_byte[0]);
     
//        Serial.print(  msg.read_byte[0]);
//       Serial.print(  msg.read_byte[1]);
//        Serial.print(  msg.read_byte[2]);
 Serial.print(test);

    }

  
}

void checkFirstByte(byte mFirst){
   
  
  
}

void checkSecondByte(byte mSecond){


}
