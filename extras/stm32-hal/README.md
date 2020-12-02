# ICP-101xx library adopted to be used with STM32 HAL

This is a basic adoption of the original Arduino library to be used with the STM32 HAL.

The only difference to the Arduino library is the initialization with ```begin()```

This library is currently lacking any HAL error handling.

### begin()

To initialize the sensor, use the `begin` method.

To initialize, a pointer to the handle of an I2C peripheral must be provided. The handle must be of type ```I2C_HandleTypeDef```. For example:

```
mysensor.begin(&hi2c);
```

The `begin` method connects to the sensor and reads the calibration data. It will return `false`, if the sensor does not respond. This can be used for error handling.

```
if (!mysensor.begin(&hi2c)) {
    // sensor did not respond, do error handling here
}
```
