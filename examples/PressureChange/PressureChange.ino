/******************************************************************
 Example for the ICP10xx library for the TDK InvenSense ICP-101xx
 series of barometric pressure sensors.

 This sketch outputs the current temperature in Celsius, and the
 pressure difference in Pascal since the sketch was started. Use
 the Arduino Serial Monitor or Serial Plotter to view the output.

 Written by Adrian Studer.
******************************************************************/

#include <icp101xx.h>

// Sensor is an ICP101xx object
ICP101xx sensor;

// variable to keep initial pressure as reference point
float reference_pressure = 0.0;

void setup() {
  // Initialize sensor.
  // Optional: Pass pointer to Wire to use other than default I2C port.
  //    For example: sensor.begin(&Wire1);
  sensor.begin();
  Serial.begin(9600);
  
  // Make a first pressure measurement and store as reference.
  sensor.measure(sensor.VERY_ACCURATE);
  reference_pressure = sensor.getPressurePa();
}

void loop() {
  // Check if sensor is responding.
  if (!sensor.isConnected()) {
    Serial.println("sensor not responding!");
  } else {
    // Start measurement cycle, waiting until it is completed.
    // Optional: Measurement mode
    //    sensor.FAST: ~3ms
    //    sensor.NORMAL: ~7ms (default)
    //    sensor.ACCURATE: ~24ms
    //    sensor.VERY_ACCURATE: ~95ms
    sensor.measure(sensor.VERY_ACCURATE);

    // Read and output measured temperature in Celsius and pressure in Pascal.
    Serial.print(sensor.getTemperatureC());
    Serial.print(",");
    Serial.println(sensor.getPressurePa() - reference_pressure);
  }

  delay(100);
}

