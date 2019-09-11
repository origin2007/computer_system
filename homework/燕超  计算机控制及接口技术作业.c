int led=13;
int T=1000;
float dc=0.5;
//int temp;
String incomingByte = ""; 
void setup() {
  Serial.begin(9600);     
  pinMode(led, OUTPUT);
  Serial.print("默认周期：");
  Serial.println(T);
  Serial.print("默认占空比：");
  Serial.println(dc);
}
void loop() {
  while (Serial.available() > 0) { 
    incomingByte += char(Serial.read());
    delay(2);
  }
  if ( incomingByte.length() > 0 ) { 
    Serial.println("串口输入:"+incomingByte);
    if (incomingByte.startsWith("T")) {
      T=incomingByte.substring(2).toInt();
      Serial.print("周期:");
      Serial.println(T);
    }else {
      dc=incomingByte.substring(3).toFloat();
      //t=temp/10;
      Serial.print("占空比:");
      Serial.println(dc);
    }
    incomingByte = ""; 
  }
  
  digitalWrite(led,HIGH);
  //Serial.println(HIGH);
  delay(dc*T);
  //Serial.println(t*T/10);
  digitalWrite(led,LOW);
  //Serial.println(LOW);
  delay(T-dc*T);
  //Serial.println(T-t*T/10);
}