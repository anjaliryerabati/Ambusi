
// Hardware: NodeMCU

#include <ESP8266WiFi.h>
#include <Wire.h>


String apiKey = "UITOVF4DP3DC4FBJ";     //  Enter your Write API key from ThingSpeak

const char *ssid =  "SIGMASOLUTION";     // replace with your wifi ssid and wpa2 key
const char *pass =  "asdfgfgf@1";
const char* server = "api.thingspeak.com";

char strl[5][10]={0};
char snames[5][13]={"North :","East :","South :","West :"};
char flag=0;
char str[30]={'\0'};

WiFiClient client;

int readSerial(char result[]) 
{
  int i = 0;
  char inChar;
  do
   {
    while (Serial.available() > 0) 
    {
       inChar = Serial.read();
      if (inChar == '#') 
         {
          result[i] = '\0';
          Serial.flush();
          return 0;
         }
      else// (inChar != '\r') 
         {
          result[i] = inChar;
          i++;
         }
    }
  }while(inChar!='#');
}

void setup() 
{
       Serial.begin(9600);
       delay(10);
       ESP.wdtDisable();
       Serial.println("Connecting to ");
       Serial.println(ssid);
 
 
       WiFi.begin(ssid, pass);
 
      while (WiFi.status() != WL_CONNECTED) 
     {
            delay(500);
            Serial.print(".");
     }
      Serial.println("");
      Serial.println("WiFi connected");
}
 
void loop() 
{      
                    Serial.println("Waiting...");
                    char rcv;
                      do{
                       rcv = Serial.read();
                      }while(rcv != '*');
                       readSerial(str);
                       Serial.println("Data Recieved...");
                       Serial.println(str);
                    int i;
                    int j=0;
                    int k=0;
                    for(i=0;str[i]!='\0';i++)
                    {
                      if(str[i]!=',')
                      {
                        strl[j][k]=str[i];
                        k++;
                      }
                      else
                      {
                        j++;
                        k=0;
                      }
                    }          
                   Serial.print("*");
                  for(int i=0;i<4;i++)
                    {
                    Serial.print(snames[i]);
                    Serial.print(strl[i]);
                    Serial.print(", ");
                    }
                    Serial.println("*");
 
                         if (client.connect(server,80))   //   "184.106.153.149" or api.thingspeak.com
                      {                              
                             String postStr = apiKey;
                             postStr +="&field1=";
                             postStr += strl[0];
                             postStr +="&field2=";
                             postStr += strl[1];
                             postStr +="&field3=";
                             postStr += strl[2];
                             postStr +="&field4=";
                             postStr += strl[3];
//                             postStr +="&field5=";
//                             postStr += strl[4];
                             postStr += "\r\n\r\n";
 
                             client.print("POST /update HTTP/1.1\n");
                             client.print("Host: api.thingspeak.com\n");
                             client.print("Connection: close\n");
                             client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
                             client.print("Content-Type: application/x-www-form-urlencoded\n");
                             client.print("Content-Length: ");
                             client.print(postStr.length());
                             client.print("\n\n");
                             client.print(postStr);
 
                            
                             
                        }
                        flag=0;
                   client.stop();
                   Serial.println("Updated...");
             
          
  delay(1000);
}







