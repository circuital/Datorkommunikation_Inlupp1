const char tempMsg[50];
const char humMsg[50];
const char tempHumMsg[50];

void SendTextToConsole(String textValue)
{
  Serial.println(textValue);
  delay(1000);
}

void GetTextFromFeather()
{
  uint8_t buflen = 32;
  uint8_t buf[32]= "";
  if(driver.recv(buf, &buflen)) 
  {
    String textMsg = String((char*)buf);
    SendTextToConsole(textMsg);
  }
}

void SendTempHumToFeather(const char* tempHumValue)
{
  driver.send((uint8_t *)tempHumValue, strlen(tempHumValue));
  driver.waitPacketSent();
}

void GetTempHumFromSensor()
{
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();
  dtostrf(temp, 4, 2, tempMsg);
  dtostrf(hum, 2, 0, humMsg);
  strcpy(tempHumMsg, "{\"temperature\": ");
  strcat(tempHumMsg, tempMsg);
  strcat(tempHumMsg, ", \"humidity\": ");
  strcat(tempHumMsg, humMsg);
  strcat(tempHumMsg, "}");
  SendTempHumToFeather(tempHumMsg);
}
