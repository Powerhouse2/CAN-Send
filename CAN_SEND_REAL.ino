// Send CAN Commands
//

#include <mcp_can.h>
#include <SPI.h>

MCP_CAN CAN0(10);     // Set CS to pin 10

  // Fake RPM Data
 byte rpm[30][8] = {
  {0x04, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x06, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x08, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x08, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x0A, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x0C, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x10, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x14, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x18, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x1C, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x24, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x2A, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x2E, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x35, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x3D, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  
  {0x04, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x06, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x08, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x08, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x0A, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x0C, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x10, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x14, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x18, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x1C, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x24, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x2A, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x2E, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x35, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x3D, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
 };

  // Fake Speed Data
 byte vehicleSpeed[30][8] = {
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x0B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x0D, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x12, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x15, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x1A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x1C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x1E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x21, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x23, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  
  {0x1E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x21, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x23, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x25, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x28, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x2A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x2D, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x2F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x32, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x35, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x3B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x3D, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x4B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
 };

void setup()
{
  Serial.begin(115200);

  // Initialize MCP2515 running at 16MHz with a baudrate of 500kb/s and the masks and filters disabled.
  if(CAN0.begin(MCP_ANY, CAN_500KBPS, MCP_16MHZ) == CAN_OK) Serial.println("MCP2515 Initialized Successfully!");
  else Serial.println("Error Initializing MCP2515...");

  CAN0.setMode(MCP_NORMAL);   // Change to normal mode to allow messages to be transmitted
}

void loop()
{
  for(int i = 0; i < 30; i++){
    // send data:  ID = 0x100, Standard CAN Frame, Data length = 8 bytes, 'data' = array of data bytes to send
    byte sndStat = CAN0.sendMsgBuf(0x0C, 0, 8, rpm[i]);
    if(sndStat == CAN_OK){
      Serial.println("Message Sent Successfully!");
    } else {
      Serial.println("Error Sending Message...");
    }
    delay(100);   // send data per 100ms

     // send data:  ID = 0x100, Standard CAN Frame, Data length = 8 bytes, 'data' = array of data bytes to send
    sndStat = CAN0.sendMsgBuf(0x0D, 0, 8, vehicleSpeed[i]);
    if(sndStat == CAN_OK){
      Serial.println("Message Sent Successfully!");
    } else {
      Serial.println("Error Sending Message...");
    }
    delay(100);   // send data per 100ms
  }
}
