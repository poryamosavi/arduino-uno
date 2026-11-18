#include <EEPROM.h>

void setup() {
  Serial.begin(9600);
  int addr = 0;
//  int testInt = 12345;
//  char testString[] = "Namatek!!!";
//  char testChar = 'z';
//  
//  EEPROM.put(addr, testInt);
//  addr += sizeof(testInt);
//  EEPROM.put(addr, testString);
//  addr += sizeof(testString);
//  EEPROM.put(addr, testChar);

  int data1;
  char data2[11];
  char data3;

  EEPROM.get(addr, data1);
  addr += sizeof(data1);
  EEPROM.get(addr, data2);
  addr += sizeof(data2);
  EEPROM.get(addr, data3);

  Serial.println(data1);
  Serial.println(data2);
  Serial.println(data3);
  

  
  //char test[] = "namatek";
  //EEPROM.put(0, test);
  //char test[7];
  //EEPROM.get(0, test);
  //Serial.println(test);
  
}

void loop() {

}
