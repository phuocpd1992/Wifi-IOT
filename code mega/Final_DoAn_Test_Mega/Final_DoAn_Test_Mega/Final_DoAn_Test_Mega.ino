#include <Wire.h>
#include <BH1750.h>
#include <DHT.h>
#define DHTPIN1 10
#define DHTPIN2 11
#define DHTPIN3 12
#define DHTTYPE DHT11
const int ledPin =  LED_BUILTIN;
const int i00 =  22;
const int i01 =  24;
const int i02 =  26;
const int i03 =  28;
const int i04 =  30;
const int i05 =  32;
const int i06 =  34;
const int i07 =  36;

const int i10 =  38;
const int i11 =  40;
const int i12 =  42;
const int i13 =  44;
const int i14 =  46;
const int i15 =  48;
const int i16 =  50;
const int i17 =  52;

int shumi1 = A0;
int shumi2 = A1;
int shumi3 = A2;

const int lx1 =  7; 
const int lx2 =  8; 
const int lx3 =  9; 

DHT dht1(DHTPIN1, DHTTYPE);
DHT dht2(DHTPIN2, DHTTYPE);
DHT dht3(DHTPIN3, DHTTYPE);

BH1750 lightMeter(0x23);

float lux;
int t1,t2,t3,g1,g2,g3;
int h1,h2,h3,h4,h5,h6;
int Q00 = 0;
int Q01 = 0;
int Q02 = 0;
int Q03 = 0;
int Q04 = 0;
int Q05 = 0;
int Q06 = 0;
int Q07 = 0;

int Q10 = 0;
int Q11 = 0;
int Q12 = 0;
int Q13 = 0;
int Q14 = 0;
int Q15 = 0;
int Q16 = 0;
int Q17 = 0;
String data;



void setup(){
 Serial.begin(115200);
 Wire.begin();

 lightMeter.begin();
// Serial.println(F("BH1750 Test sensors"));
 pinMode(lx1, OUTPUT); 
 pinMode(lx2, OUTPUT);
 pinMode(lx3, OUTPUT);
 
 digitalWrite(lx1, LOW); digitalWrite(lx2, LOW); digitalWrite(lx3, LOW);
 delay(1000);
 digitalWrite(lx1, LOW); digitalWrite(lx2, HIGH); digitalWrite(lx3, HIGH);
 delay(500);
// Serial.println(F("DHTxx test!"));
 dht1.begin(); dht2.begin(); dht3.begin();

 pinMode(shumi1, INPUT);
 pinMode(shumi2, INPUT);
 pinMode(shumi3, INPUT);
 Serial.begin(115200);
 delay(300);
 pinMode(ledPin, OUTPUT);
 pinMode(i00, INPUT);
 pinMode(i01, INPUT);
 pinMode(i02, INPUT);
 pinMode(i03, INPUT);
 pinMode(i04, INPUT);
 pinMode(i05, INPUT);
 pinMode(i06, INPUT);
 pinMode(i07, INPUT);
 pinMode(i10, INPUT);
 pinMode(i11, INPUT);
 pinMode(i12, INPUT);
 pinMode(i13, INPUT);
 pinMode(i14, INPUT);
 pinMode(i15, INPUT);
 pinMode(i16, INPUT);
 pinMode(i07, INPUT); 
 
}

void loop() 
{
  Nhiet_Do_Do_Am();
  Do_Am_Dat();
  digitalWrite(ledPin,HIGH);
  Do_Sang_Lux();
  Q00 = 0;
  Q01 = 0;
  Q02 = 0;
  Q03 = 0;
  Q04 = 0;
  Q05 = 0;
  Q06 = 0;
  Q07 = 0;
  
  Q10 = 0;
  Q11 = 0;
  Q12 = 0;
  Q13 = 0;
  Q14 = 0;
  Q15 = 0;
  Q16 = 0;
  Q17 = 0;    
  Q00 = digitalRead(i00);
  Q01 = digitalRead(i01);
  Q02 = digitalRead(i02);
  Q03 = digitalRead(i03);
  Q04 = digitalRead(i04);
  Q05 = digitalRead(i05);
  Q06 = digitalRead(i06);
  Q07 = digitalRead(i07);

  Q10 = digitalRead(i10);
  Q11 = digitalRead(i11);
  Q12 = digitalRead(i12);
  Q13 = digitalRead(i13);
  Q14 = digitalRead(i14);
  Q15 = digitalRead(i15);
  Q16 = digitalRead(i16);
  Q17 = digitalRead(i17);
Debounce();
   data =  "?" + String(t1) + "a" + String(t2) + "b" + String(t3) + "c" + String(g1) + "d" + String(g2) + "e" + String(g3) + "f" + String(h1) + "g" + String(h2) + "h" + String(h3) + "i" + String(h4) + "j" + String(h5) + "k" + String(h6) + "l" + String(Q00) + "m" + String(Q01) + "n" + String(Q02) + "o" + String(Q03) + "p" + String(Q04) + "q" + String(Q05) + "r" + String(Q06) + "s" + String(Q07) + "t" + String(Q10) + "u" + String(Q11) + "v" + String(Q12) + "w" + String(Q13) + "x" + String(Q14) + "y" + String(Q15) + "z" + String(Q16)+ "*" + String(Q17);
   Serial.println(data);
   digitalWrite(ledPin,LOW);  
   delay(300);
}

void Do_Sang_Lux()
{
 digitalWrite(lx1, HIGH); digitalWrite(lx2, LOW); digitalWrite(lx3, LOW);
 g1=0;
 lux = lightMeter.readLightLevel(true); delay(200);
 g1 = lux;
 g2 = 0;
 g3 = 0;
// 
  Serial.print("----------G1: "); Serial.print(g1); Serial.println(" lx");
  Serial.print("----------G2: "); Serial.print(g2); Serial.println(" lx");
  Serial.print("----------G3: "); Serial.print(g3); Serial.println(" lx");
  lux=0;
}

void  Nhiet_Do_Do_Am()
{
  h1 = dht1.readHumidity()-10;
  t1 = dht1.readTemperature();
  h2 = dht2.readHumidity()-22;
  t2 = dht2.readTemperature();
  h3 = dht3.readHumidity();
  t3 = dht3.readTemperature();
  
  if (isnan(h1) || isnan(t1)) 
  {
    Serial.println(F("Failed to read from DHT1 sensor!"));
    h1=0; t1=0;
  }

  if (isnan(h2) || isnan(t2)) 
  {
    Serial.println(F("Failed to read from DHT1 sensor!"));
    h2=0; t2=0;
  }

    if (isnan(h3) || isnan(t3)) 
  {
    Serial.println(F("Failed to read from DHT1 sensor!"));
    h3=0; t3=0;
  }


  
//  if (isnan(h2) || isnan(t2)) 
//  {
//    Serial.println(F("Failed to read from DHT1 sensor!"));
//    return;
//  }
//  if (isnan(h3) || isnan(t3)) 
//  {
//    Serial.println(F("Failed to read from DHT1 sensor!"));
//    return;
//  }

  Serial.print("H1: "); Serial.print(h1); Serial.println(" %");
  Serial.print("H2: "); Serial.print(h2); Serial.println(" %");
  Serial.print("H3: "); Serial.print(h3); Serial.println(" %");
  
  Serial.print("T1: "); Serial.print(t1); Serial.println(" °C ");
  Serial.print("T2: "); Serial.print(t2); Serial.println(" °C ");
  Serial.print("T3: "); Serial.print(t3); Serial.println(" °C ");
}

void Do_Am_Dat()
{
  int a = 350;
  int ex1 = analogRead(shumi1); 
  if(ex1 < a) ex1 = a;
  int value_ex1 = map(ex1, a, 1023, 0, 100);
  h4 = 100 - value_ex1;

  int ex2 = analogRead(shumi2);
  if(ex2 < a) ex2 = a;
  int value_ex2 = map(ex2, a, 1023, 0, 100);
  h5 = 100 - value_ex2;
  
  int ex3 = analogRead(shumi3); 
  if(ex3 < a) ex3 = a;
  int value_ex3 = map(ex3, a, 1023, 0, 100);
  h6 = 100 - value_ex3;

  Serial.print("H4: "); Serial.print(h4); Serial.println(" %");
  Serial.print("H5: "); Serial.print(h5); Serial.println(" %");
  Serial.print("H6: "); Serial.print(h6); Serial.println(" %");
}

void Debounce(){
    Q00 = digitalRead(i00);
    if(Q00==1){
      delay(200);
      if(Q00==1){
        Q00=1;
      }
    }

    Q01 = digitalRead(i01);
    if(Q01==1){
      delay(200);
      if(Q01==1){
        Q01=1;
      }
    }
    Q02 = digitalRead(i02);
    if(Q02==1){
      delay(200);
      if(Q02==1){
        Q02=1;
      }
    }
    Q03 = digitalRead(i03);
    if(Q03==1){
      delay(200);
      if(Q03==1){
        Q03=1;
      }
    }
    Q04 = digitalRead(i04);
    if(Q04==1){
      delay(200);
      if(Q04==1){
        Q04=1;
      }
    }
    Q05 = digitalRead(i05);
    if(Q05==1){
     delay(200);
      if(Q05==1){
        Q05=1;
      }
    }
    Q06 = digitalRead(i06);
    if(Q06==1){
      delay(200);
      if(Q06==1){
        Q06=1;
      }
    }    
    Q07 = digitalRead(i07);
    if(Q07==1){
      delay(200);
      if(Q07==1){
        Q07=1;
      }
    }       
    
}
  
