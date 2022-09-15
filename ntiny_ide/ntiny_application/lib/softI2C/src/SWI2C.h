#ifndef SWI2C_H
#define SWI2C_H
#include <stdint.h>

void SWI2C(uint8_t sda_pin, uint8_t scl_pin, uint8_t deviceID);
void SWI2C_begin();
int write1bToRegister(int regAddress, uint8_t data, int sendStopBit);
int write2bToRegister(int regAddress, uint16_t data, int sendStopBit);
int write2bToRegisterMSBFirst(int regAddress, uint16_t data, int sendStopBit) ;
int writeToRegister(int regAddress, uint8_t data, int sendStopBit);
int writeBytesToRegister(int regAddress, uint8_t* data, uint8_t count, int sendStopBit);
int read1bFromRegister(int regAddress, uint8_t* data, int sendStopBit);
int read2bFromRegister(int regAddress, uint16_t* data, int sendStopBit);
int read2bFromRegisterMSBFirst(int regAddress, uint16_t* data, int sendStopBit);
int readBytesFromRegister(int regAddress, uint8_t* data, uint8_t count, int sendStopBit);
void sclHi();
void sclLo();
void sdaHi();
void sdaLo();
void startBit();
void writeAddress(int r_w);
uint8_t checkAckBit();
void writeAck();
void writeRegister(int regAddress);
void stopBit();
uint8_t read1Byte();
uint16_t read2Byte();
void writeByte(int data);
unsigned long getStretchTimeout();
void setStretchTimeout(unsigned long t);
int checkStretchTimeout();

  
#endif
