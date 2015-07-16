/*
Based on "arduino_bean" by Boris Kourtoukov
Modified by Kate Hartman - added more inputs

Workshop participants:
Click on the 'logic' tab and write your code there! 
*/


void setup() {

  Bean.setLed(0,0,0);

  logicSetup();
  
  writeScratchData();
  
  Bean.enableWakeOnConnect( true ); 
  
}

void loop() {

  bool connected = Bean.getConnectionState();

  if ( connected ) {
    
    Bean.setLed(0, 100, 0);
    // This function contains your code:
    logicLoop();
    // Always run this after you have updated all your data.
    writeScratchData();
    // Power off arduino for a little bit to save power.
    Bean.sleep(12);
    
  } else {
    
    Bean.setLed(0, 0, 0);
    // Power off arduino until you connect to it.
    Bean.sleep( 0xFFFFFFFF );
    
  }

}
