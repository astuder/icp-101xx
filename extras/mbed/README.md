# ICP-101xx library adopted to be used with Mbed OS

This is a basic adoption of the original Arduino library to be used with Mbed OS.

The only difference to the Arduino library is the initialization with ```begin()```

This library is currently lacking any HAL error handling.

### begin()

To initialize the sensor, use the `begin` method.

To initialize, a pointer to an [Mbed I2C Master interface](https://os.mbed.com/docs/mbed-os/v6.7/apis/i2c.html) must be provided. The handle must be of type ```I2C```. For example:

```
I2C hi2c(sda, scl);
mysensor.begin(&hi2c);
```

The `begin` method connects to the sensor and reads the calibration data. It will return `false`, if the sensor does not respond. This can be used for error handling.

```
if (!mysensor.begin(&hi2c)) {
    // sensor did not respond, do error handling here
}
```
