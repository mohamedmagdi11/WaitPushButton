

class waitpb{

private:
uint8_t ledpin;
uint8_t onbuttonpin;
uint8_t offbuttonpin;
uint16_t MILLISEC;
bool ledstate;
bool onbuttonstate;
bool offbuttonstate;

 unsigned long onTime;
 unsigned long previousMillis;

public:
waitpb(uint8_t ledpin,uint8_t onbuttonpin,uint8_t offbuttonpin,uint16_t SEC);
void begin();
void waits(uint16_t time_s);
void waitms(uint16_t time_ms);

};

waitpb::waitpb(uint8_t pin,uint8_t onbutton,uint8_t offbutton,uint16_t SEC){

ledpin = pin;
onbuttonpin = onbutton;
offbuttonpin = offbutton;
MILLISEC = SEC;
ledstate = false;
onbuttonstate = false;
offbuttonstate = false;

      
previousMillis = 0;
}

void waitpb::begin(){
pinMode(ledpin,OUTPUT);
pinMode(onbuttonpin,INPUT_PULLUP);
pinMode(offbuttonpin,INPUT_PULLUP);

}

void waitpb::waits(uint16_t time_s ){
  
  MILLISEC = time_s*1000;

onbuttonstate = digitalRead(onbuttonpin);
offbuttonstate = digitalRead(offbuttonpin);

if(onbuttonstate==LOW)
{
ledstate = true;
digitalWrite(ledpin,HIGH);
previousMillis = millis();


}
if(offbuttonstate==LOW)
{
ledstate = false;
digitalWrite(ledpin,LOW);


}
if(ledstate==true && millis()-previousMillis>=MILLISEC)
{
ledstate = false;
digitalWrite(ledpin,LOW);

}
}


void waitpb::waitms(uint16_t time_ms ){
  
   MILLISEC = time_ms;

onbuttonstate = digitalRead(onbuttonpin);
offbuttonstate = digitalRead(offbuttonpin);

if(onbuttonstate==LOW)
{
ledstate = true;
digitalWrite(ledpin,HIGH);
previousMillis = millis();


}
if(offbuttonstate==LOW)
{
ledstate = false;
digitalWrite(ledpin,LOW);


}
if(ledstate==true && millis()-previousMillis>=MILLISEC)
{
ledstate = false;
digitalWrite(ledpin,LOW);

}
}







waitpb x(13,7,6,0);

void setup() {
  x.begin();
}

void loop() {
  x.waits(6);
  //x.waitms(5000);
}

