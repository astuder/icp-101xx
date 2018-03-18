/******************************************************************
 Example for the ICP10xx library for the TDK InvenSense ICP-101xx
 series of barometric pressure sensors.

 This sketch outputs the current temperature in Fahrenheit, and the
 pressure in Pascal. Use the Serial Monitor to view the output.
 
 Measurements are made using the non-blocking method measureStart().
 This method immediately returns control to the caller while the
 sensor takes its measurement. Use the method dataReady() to check
 when the new sensor data is available.

 Written by Adrian Studer.
******************************************************************/

#include <icp101xx.h>

// Sensor is an ICP101xx object
ICP101xx sensor;

void setup() {
  // Initialize sensor.
  // Optional: Pass pointer to Wire to use other than default I2C port.
  //    For example: sensor.begin(&Wire1);
  sensor.begin();
  Serial.begin(9600);
  
  // Start a first measurement cycle, immediately returning control.
  // Optional: Measurement mode
  //    sensor.FAST: ~3ms
  //    sensor.NORMAL: ~7ms (default)
  //    sensor.ACCURATE: ~24ms
  //    sensor.VERY_ACCURATE: ~95ms
  sensor.measureStart(sensor.VERY_ACCURATE);
}

void loop() {
  // Do all the other things you need to do.
  
  // When the measurement is complete, dataReady() will return true.
  if (sensor.dataReady()) {
    // Read and output measured temperature in Fahrenheit and pressure in
	// Pascal.
    Serial.print(sensor.getTemperatureF());
    Serial.print(",");
    Serial.println(sensor.getPressurePa());

	// And start the next measurement cycle.
    sensor.measureStart(sensor.VERY_ACCURATE);
  }

  // Do more things.
  delay(100);
}
