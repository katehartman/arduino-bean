/*
This stores the following data in the bean's 10 characteristics:
-accelerometer
-temperature sensor
-pins A0, A1, 0, 1, 2, 3
Feel free to make changes!
 */


// Global Variables
static int8_t temp = 0;

// This runs once,
// Treat as Arduino setup.
void logicSetup() {

  // For switches. No additional resistors required.
  pinMode(0, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);

}

// This runs continuously until powered off.
// Treat as arduino loop.
void logicLoop() {

  // read and store input values
  int8_t newTemp = Bean.getTemperature(); // in Celcius

  AccelerationReading accel = {0, 0, 0};
  accel = Bean.getAcceleration();

  long x = accel.xAxis;
  long y = accel.yAxis;
  long z = accel.zAxis;
  int sensor1 = analogRead(A0);
  int sensor2 = analogRead(A1);
  int switch1 = digitalRead(0);
  int switch2 = digitalRead(1);
  int switch3 = digitalRead(2);
  int switch4 = digitalRead(3);

  //This determines what data to store in each characteristic.
  set(1, x);
  set(2, y);
  set(3, z);
  set(4, newTemp);
  set(5, sensor1);
  set(6, sensor2);
  set(7, switch1);
  set(8, switch2);
  set(9, switch3);
  set(10, switch4);

}
