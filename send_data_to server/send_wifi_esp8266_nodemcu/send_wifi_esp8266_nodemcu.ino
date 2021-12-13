#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
ESP8266WiFiMulti WiFiMulti;

int t1,t2,t3,g1,g2,g3,h1,h2,h3,h4,h5,h6,q00,q01,q02,q03,q04,q05,q06,q07,q10,q11,q12,q13,q14,q15,q16,q17;
int dv, chuc, tram, nghin, chucnghin;
int s;
String data;


void setup() {
  Serial.begin(115200);
  // Serial.setDebugOutput(true);
  Serial.println();
  Serial.println();

  Serial.println();
  for (uint8_t t = 4; t > 0; t--) {
    Serial.printf("[SETUP] WAIT %d...\n", t);
    Serial.flush();
    delay(1000);
  }

  WiFi.mode(WIFI_STA);
//  WiFiMulti.addAP("Connectify-me", "12345678");
  WiFiMulti.addAP("ZenPhongLanh", "59vutung");

}


void reveive_sensor_data(){
   String str;
   while(Serial.available()){
        char c = Serial.read();
        str += c;
   }
 // ?46a100b27c184d202e451f117g79h26i23j11k25l0m0n1o1p0q0r0s0t1u1v0w0x0y1z0*1
  Serial.println(str);
   s= str.indexOf("a")-str.indexOf("?");
  if(s==2){  t1 =str[str.indexOf("?")+1]-'0';}
  else if(s==3){  chuc =str[str.indexOf("?")+1]-'0'; dv =str[str.indexOf("?")+2]-'0'; t1= chuc*10 +dv;} 
  else if(s==4){  tram =str[str.indexOf("?")+1]-'0'; chuc =str[str.indexOf("?")+2]-'0'; dv =str[str.indexOf("?")+3]-'0'; t1= tram*100 + chuc*10 +dv;} 
//  Serial.println(t1);

  s= str.indexOf("b")-str.indexOf("a");
  if(s==2){  t2 =str[str.indexOf("a")+1]-'0';}
  else if(s==3){ chuc =str[str.indexOf("a")+1]-'0'; dv =str[str.indexOf("a")+2]-'0'; t2= chuc*10 +dv;} 
  else if(s==4){  tram =str[str.indexOf("a")+1]-'0'; chuc =str[str.indexOf("a")+2]-'0'; dv =str[str.indexOf("a")+3]-'0'; t2= tram*100 + chuc*10 +dv;} 
//  Serial.println(t2);

  s= str.indexOf("c")-str.indexOf("b");
  if(s==2){ t3 =str[str.indexOf("b")+1]-'0';}
  else if(s==3){  chuc =str[str.indexOf("b")+1]-'0'; dv =str[str.indexOf("b")+2]-'0'; t3= chuc*10 +dv;} 
  else if(s==4){  tram =str[str.indexOf("b")+1]-'0'; chuc =str[str.indexOf("b")+2]-'0'; dv =str[str.indexOf("b")+3]-'0'; t3= tram*100 + chuc*10 +dv;} 
//  Serial.println(t3);

   s= str.indexOf("d")-str.indexOf("c");
  if(s==2){  g1 =str[str.indexOf("c")+1]-'0';}
  else if(s==3){  chuc =str[str.indexOf("c")+1]-'0'; dv =str[str.indexOf("c")+2]-'0'; g1= chuc*10 +dv;} 
  else if(s==4){  tram =str[str.indexOf("c")+1]-'0'; chuc =str[str.indexOf("c")+2]-'0'; dv =str[str.indexOf("c")+3]-'0'; g1= tram*100 + chuc*10 +dv;} 
  else if(s==5){ nghin =str[str.indexOf("c")+1]-'0'; tram =str[str.indexOf("c")+2]-'0'; chuc =str[str.indexOf("c")+3]-'0'; dv =str[str.indexOf("c")+4]-'0'; g1= nghin*1000 + tram*100 + chuc*10 +dv;} 
  else if(s==6){ chucnghin =str[str.indexOf("c")+1]-'0'; nghin =str[str.indexOf("c")+2]-'0';  tram =str[str.indexOf("c")+3]-'0'; chuc =str[str.indexOf("c")+4]-'0'; dv =str[str.indexOf("c")+5]-'0'; g1= chucnghin*10000 + nghin*1000 + tram*100 + chuc*10 +dv;} 

//  Serial.println(g1);

     s= str.indexOf("e")-str.indexOf("d");
  if(s==2){  g2 =str[str.indexOf("d")+1]-'0';}
  else if(s==3){ chuc =str[str.indexOf("d")+1]-'0'; dv =str[str.indexOf("d")+2]-'0'; g2= chuc*10 +dv;} 
  else if(s==4){  tram =str[str.indexOf("d")+1]-'0'; chuc =str[str.indexOf("d")+2]-'0'; dv =str[str.indexOf("d")+3]-'0'; g2= tram*100 + chuc*10 +dv;} 
  else if(s==5){ nghin =str[str.indexOf("c")+1]-'0'; tram =str[str.indexOf("c")+2]-'0'; chuc =str[str.indexOf("c")+3]-'0'; dv =str[str.indexOf("c")+4]-'0'; g2= nghin*1000 + tram*100 + chuc*10 +dv;} 
  else if(s==6){ chucnghin =str[str.indexOf("c")+1]-'0'; nghin =str[str.indexOf("c")+2]-'0';  tram =str[str.indexOf("c")+3]-'0'; chuc =str[str.indexOf("c")+4]-'0'; dv =str[str.indexOf("c")+5]-'0'; g2= chucnghin*10000 + nghin*1000 + tram*100 + chuc*10 +dv;} 

//  Serial.println(g2);

     s= str.indexOf("f")-str.indexOf("e");
  if(s==2){ g3 =str[str.indexOf("e")+1]-'0';}
  else if(s==3){ chuc =str[str.indexOf("e")+1]-'0'; dv =str[str.indexOf("e")+2]-'0'; g3= chuc*10 +dv;} 
  else if(s==4){  tram =str[str.indexOf("e")+1]-'0'; chuc =str[str.indexOf("e")+2]-'0'; dv =str[str.indexOf("e")+3]-'0'; g3= tram*100 + chuc*10 +dv;} 
  else if(s==5){ nghin =str[str.indexOf("c")+1]-'0'; tram =str[str.indexOf("c")+2]-'0'; chuc =str[str.indexOf("c")+3]-'0'; dv =str[str.indexOf("c")+4]-'0'; g3= nghin*1000 + tram*100 + chuc*10 +dv;} 
  else if(s==6){ chucnghin =str[str.indexOf("c")+1]-'0'; nghin =str[str.indexOf("c")+2]-'0';  tram =str[str.indexOf("c")+3]-'0'; chuc =str[str.indexOf("c")+4]-'0'; dv =str[str.indexOf("c")+5]-'0'; g3= chucnghin*10000 + nghin*1000 + tram*100 + chuc*10 +dv;} 

//  Serial.println(g3);

     s= str.indexOf("g")-str.indexOf("f");
  if(s==2){ h1 =str[str.indexOf("f")+1]-'0';}
  else if(s==3){  chuc =str[str.indexOf("f")+1]-'0'; dv =str[str.indexOf("f")+2]-'0'; h1= chuc*10 +dv;} 
  else if(s==4){ tram =str[str.indexOf("f")+1]-'0'; chuc =str[str.indexOf("f")+2]-'0'; dv =str[str.indexOf("f")+3]-'0'; h1= tram*100 + chuc*10 +dv;} 
//  Serial.println(h1);

   s= str.indexOf("h")-str.indexOf("g");
  if(s==2){ h2 =str[str.indexOf("g")+1]-'0';}
  else if(s==3){  chuc =str[str.indexOf("g")+1]-'0'; dv =str[str.indexOf("g")+2]-'0'; h2= chuc*10 +dv;} 
  else if(s==4){  tram =str[str.indexOf("g")+1]-'0'; chuc =str[str.indexOf("g")+2]-'0'; dv =str[str.indexOf("g")+3]-'0'; h2= tram*100 + chuc*10 +dv;} 
//  Serial.println(h2);

     s= str.indexOf("i")-str.indexOf("h");
  if(s==2){ h3 =str[str.indexOf("h")+1]-'0';}
  else if(s==3){  chuc =str[str.indexOf("h")+1]-'0'; dv =str[str.indexOf("h")+2]-'0'; h3= chuc*10 +dv;} 
  else if(s==4){  tram =str[str.indexOf("h")+1]-'0'; chuc =str[str.indexOf("h")+2]-'0'; dv =str[str.indexOf("h")+3]-'0'; h3= tram*100 + chuc*10 +dv;} 
//  Serial.println(h3);

     s= str.indexOf("j")-str.indexOf("i");
  if(s==2){  h4 =str[str.indexOf("i")+1]-'0';}
  else if(s==3){  chuc =str[str.indexOf("i")+1]-'0'; dv =str[str.indexOf("i")+2]-'0'; h4= chuc*10 +dv;} 
  else if(s==4){  tram =str[str.indexOf("i")+1]-'0'; chuc =str[str.indexOf("i")+2]-'0'; dv =str[str.indexOf("i")+3]-'0'; h4= tram*100 + chuc*10 +dv;} 
//  Serial.println(h4);

     s= str.indexOf("k")-str.indexOf("j");
  if(s==2){ h5 =str[str.indexOf("j")+1]-'0';}
  else if(s==3){  chuc =str[str.indexOf("j")+1]-'0'; dv =str[str.indexOf("j")+2]-'0'; h5= chuc*10 +dv;} 
  else if(s==4){  tram =str[str.indexOf("j")+1]-'0'; chuc =str[str.indexOf("j")+2]-'0'; dv =str[str.indexOf("j")+3]-'0'; h5= tram*100 + chuc*10 +dv;} 
//  Serial.println(h5);

     s= str.indexOf("l")-str.indexOf("k");
  if(s==2){  h6 =str[str.indexOf("k")+1]-'0';}
  else if(s==3){  chuc =str[str.indexOf("k")+1]-'0'; dv =str[str.indexOf("k")+2]-'0'; h6= chuc*10 +dv;} 
  else if(s==4){  tram =str[str.indexOf("k")+1]-'0'; chuc =str[str.indexOf("k")+2]-'0'; dv =str[str.indexOf("k")+3]-'0'; h6= tram*100 + chuc*10 +dv;} 
//  Serial.println(h6);
     
     s= str.indexOf("m")-str.indexOf("l");
  if(s==2){ q00 =str[str.indexOf("l")+1]-'0';}
  else if(s==3){  chuc =str[str.indexOf("l")+1]-'0'; dv =str[str.indexOf("l")+2]-'0'; q00= chuc*10 +dv;} 
  else if(s==4){  tram =str[str.indexOf("l")+1]-'0'; chuc =str[str.indexOf("l")+2]-'0'; dv =str[str.indexOf("l")+3]-'0'; q00= tram*100 + chuc*10 +dv;} 
//  Serial.println(q00);

     s= str.indexOf("n")-str.indexOf("m");
  if(s==2){ q01 =str[str.indexOf("m")+1]-'0';}
  else if(s==3){  chuc =str[str.indexOf("m")+1]-'0'; dv =str[str.indexOf("m")+2]-'0'; q01= chuc*10 +dv;} 
  else if(s==4){  tram =str[str.indexOf("m")+1]-'0'; chuc =str[str.indexOf("m")+2]-'0'; dv =str[str.indexOf("m")+3]-'0'; q01= tram*100 + chuc*10 +dv;} 
  Serial.println(q01);
  
   s= str.indexOf("o")-str.indexOf("n");
  if(s==2){  q02 =str[str.indexOf("n")+1]-'0';}
  else if(s==3){  chuc =str[str.indexOf("n")+1]-'0'; dv =str[str.indexOf("n")+2]-'0'; q02= chuc*10 +dv;} 
  else if(s==4){ tram =str[str.indexOf("n")+1]-'0'; chuc =str[str.indexOf("n")+2]-'0'; dv =str[str.indexOf("n")+3]-'0'; q02= tram*100 + chuc*10 +dv;} 
  Serial.println(q02);

   s= str.indexOf("p")-str.indexOf("o");
  if(s==2){  q03 =str[str.indexOf("o")+1]-'0';}
  else if(s==3){  chuc =str[str.indexOf("o")+1]-'0'; dv =str[str.indexOf("o")+2]-'0'; q03= chuc*10 +dv;} 
  else if(s==4){ tram =str[str.indexOf("o")+1]-'0'; chuc =str[str.indexOf("o")+2]-'0'; dv =str[str.indexOf("o")+3]-'0'; q03= tram*100 + chuc*10 +dv;} 
  Serial.println(q03);

   s= str.indexOf("q")-str.indexOf("p");
  if(s==2){  q04 =str[str.indexOf("p")+1]-'0';}
  else if(s==3){ chuc =str[str.indexOf("p")+1]-'0'; dv =str[str.indexOf("p")+2]-'0'; q04= chuc*10 +dv;} 
  else if(s==4){ tram =str[str.indexOf("p")+1]-'0'; chuc =str[str.indexOf("p")+2]-'0'; dv =str[str.indexOf("p")+3]-'0'; q04= tram*100 + chuc*10 +dv;} 
  Serial.println(q04);

     s= str.indexOf("r")-str.indexOf("q");
  if(s==2){  q05 =str[str.indexOf("q")+1]-'0';}
  else if(s==3){  chuc =str[str.indexOf("q")+1]-'0'; dv =str[str.indexOf("q")+2]-'0'; q05= chuc*10 +dv;} 
  else if(s==4){  tram =str[str.indexOf("q")+1]-'0'; chuc =str[str.indexOf("q")+2]-'0'; dv =str[str.indexOf("q")+3]-'0'; q05= tram*100 + chuc*10 +dv;} 
  Serial.println(q05);

     s= str.indexOf("s")-str.indexOf("r");
  if(s==2){  q06 =str[str.indexOf("r")+1]-'0';}
  else if(s==3){  chuc =str[str.indexOf("r")+1]-'0'; dv =str[str.indexOf("r")+2]-'0'; q06= chuc*10 +dv;} 
  else if(s==4){  tram =str[str.indexOf("r")+1]-'0'; chuc =str[str.indexOf("r")+2]-'0'; dv =str[str.indexOf("r")+3]-'0'; q06= tram*100 + chuc*10 +dv;} 
  Serial.println(q06);

     s= str.indexOf("t")-str.indexOf("s");
  if(s==2){  q07 =str[str.indexOf("s")+1]-'0';}
  else if(s==3){  chuc =str[str.indexOf("s")+1]-'0'; dv =str[str.indexOf("s")+2]-'0'; q07= chuc*10 +dv;} 
  else if(s==4){  tram =str[str.indexOf("s")+1]-'0'; chuc =str[str.indexOf("s")+2]-'0'; dv =str[str.indexOf("s")+3]-'0'; q07= tram*100 + chuc*10 +dv;} 
  Serial.println(q07);

   s= str.indexOf("u")-str.indexOf("t");
  if(s==2){  q10 =str[str.indexOf("t")+1]-'0';}
  else if(s==3){  chuc =str[str.indexOf("t")+1]-'0'; dv =str[str.indexOf("t")+2]-'0'; q10= chuc*10 +dv;} 
  else if(s==4){  tram =str[str.indexOf("t")+1]-'0'; chuc =str[str.indexOf("t")+2]-'0'; dv =str[str.indexOf("t")+3]-'0'; q10= tram*100 + chuc*10 +dv;} 
  Serial.println(q10);

     s= str.indexOf("v")-str.indexOf("u");
  if(s==2){  q11 =str[str.indexOf("u")+1]-'0';}
  else if(s==3){  chuc =str[str.indexOf("u")+1]-'0'; dv =str[str.indexOf("u")+2]-'0'; q11= chuc*10 +dv;} 
  else if(s==4){  tram =str[str.indexOf("u")+1]-'0'; chuc =str[str.indexOf("u")+2]-'0'; dv =str[str.indexOf("u")+3]-'0'; q11= tram*100 + chuc*10 +dv;} 
  Serial.println(q11);

   s= str.indexOf("w")-str.indexOf("v");
  if(s==2){  q12 =str[str.indexOf("v")+1]-'0';}
  else if(s==3){ chuc =str[str.indexOf("v")+1]-'0'; dv =str[str.indexOf("v")+2]-'0'; q12= chuc*10 +dv;} 
  else if(s==4){  tram =str[str.indexOf("v")+1]-'0'; chuc =str[str.indexOf("v")+2]-'0'; dv =str[str.indexOf("v")+3]-'0'; q12= tram*100 + chuc*10 +dv;} 
  Serial.println(q12);

     s= str.indexOf("x")-str.indexOf("w");
  if(s==2){  q13 =str[str.indexOf("w")+1]-'0';}
  else if(s==3){  chuc =str[str.indexOf("w")+1]-'0'; dv =str[str.indexOf("w")+2]-'0'; q13= chuc*10 +dv;} 
  else if(s==4){  tram =str[str.indexOf("w")+1]-'0'; chuc =str[str.indexOf("w")+2]-'0'; dv =str[str.indexOf("w")+3]-'0'; q13= tram*100 + chuc*10 +dv;} 
  Serial.println(q13);

     s= str.indexOf("y")-str.indexOf("x");
  if(s==2){ q14 =str[str.indexOf("x")+1]-'0';}
  else if(s==3){  chuc =str[str.indexOf("x")+1]-'0'; dv =str[str.indexOf("x")+2]-'0'; q14= chuc*10 +dv;} 
  else if(s==4){ tram =str[str.indexOf("x")+1]-'0'; chuc =str[str.indexOf("x")+2]-'0'; dv =str[str.indexOf("x")+3]-'0'; q14= tram*100 + chuc*10 +dv;} 
  Serial.println(q14);

     s= str.indexOf("z")-str.indexOf("y");
  if(s==2){  q15 =str[str.indexOf("y")+1]-'0';}
  else if(s==3){  chuc =str[str.indexOf("y")+1]-'0'; dv =str[str.indexOf("y")+2]-'0'; q15= chuc*10 +dv;} 
  else if(s==4){ tram =str[str.indexOf("y")+1]-'0'; chuc =str[str.indexOf("y")+2]-'0'; dv =str[str.indexOf("y")+3]-'0'; q15= tram*100 + chuc*10 +dv;} 
  Serial.println(q15);

   s= str.indexOf("*")-str.indexOf("z");
  if(s==2){  q16 =str[str.indexOf("z")+1]-'0';}
  else if(s==3){  chuc =str[str.indexOf("z")+1]-'0'; dv =str[str.indexOf("z")+2]-'0'; q16= chuc*10 +dv;} 
  else if(s==4){  tram =str[str.indexOf("z")+1]-'0'; chuc =str[str.indexOf("z")+2]-'0'; dv =str[str.indexOf("z")+3]-'0'; q16= tram*100 + chuc*10 +dv;} 
  Serial.println(q16);

  q17 = str[str.indexOf("*")+1]-'0';
  Serial.println(q17);
  
}


void loop() {
  // wait for WiFi connection
 
  
  if ((WiFiMulti.run() == WL_CONNECTED)) {
    WiFiClient client;
    HTTPClient http;
    Serial.print("[HTTP] begin...\n");
     reveive_sensor_data();
    data = "t1=" + String(t1) + "&t2=" + String(t2) + "&t3=" + String(t3) + "&g1=" + String(g1) + "&g2=" + String(g2) + "&g3=" + String(g3) + "&h1=" + String(h1) + "&h2=" + String(h2) + "&h3=" + String(h3) + "&h4=" + String(h4) + "&h5=" + String(h5) + "&h6=" + String(h6) + "&Q00=" + String(q00) + "&Q01=" + String(q01) + "&Q02=" + String(q02) + "&Q03=" + String(q03) + "&Q04=" + String(q04) + "&Q05=" + String(q05) + "&Q06=" + String(q06) + "&Q07=" + String(q07) + "&Q10=" + String(q10) + "&Q11=" + String(q11) + "&Q12=" + String(q12) + "&Q13=" + String(q13) + "&Q14=" + String(q14) + "&Q15=" + String(q15) + "&Q16=" + String(q16) + "&Q17=" + String(q17);

    String url= "http://cpanel.doantotnghiep.info/?mod=ethernet&controller=ethernet&action=nhanhang_get&" + data;
    Serial.print(url);
    if (http.begin(client, url)) {  // HTTP


      Serial.print("[HTTP] GET...\n");
      // start connection and send HTTP header
      int httpCode = http.GET();

      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        Serial.printf("[HTTP] GET... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload = http.getString();
          Serial.println(payload);
        }
      } else {
        Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }

      http.end();
    } else {
      Serial.printf("[HTTP} Unable to connect\n");
    }
  }

  delay(1000);
}
