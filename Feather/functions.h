void SendTempHumToWeb(String tempHumValue)
{
  server.send(200, "text/plain", tempHumValue);
}

void GetTempHumFromArduino()
{
  uint8_t buflen = 32;
  uint8_t buf[32]= "";
  if(driver.recv(buf, &buflen)) 
  {
    String tempHumMsg = String((char*)buf);
    SendTempHumToWeb(tempHumMsg);
  }
}

void SendTextToArduino(String textValue)
{
  const char* textCharArray = textValue.c_str();
  driver.send((uint8_t *)textCharArray, strlen(textCharArray));
  driver.waitPacketSent();
}

void GetTextFromWeb()
{
  String textMsg = server.arg("text");
  SendTextToArduino(textMsg);
}
