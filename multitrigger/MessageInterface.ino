
union message{
  byte content[2];

} msg;

void receiver(){
  if(Serial.available() > 1 ){ 
    msg.content[0]=Serial.read();
    msg.content[1]=Serial.read();
    
//    Serial.print(msg.content[0],byte);   
//    Serial.print(msg.content[1],byte);  
      checkFirstByte(msg.content[0]);
      
    }
  
  
}

void checkFirstByte(byte mFirst){
   
  
  
}

void checkSecondByte(byte mSecond){


}
