# 6ense
## Main Structure in Arduino Code:

### Interfaces:
- `I_Component`: every object that should have a setup and be called in the main loop inherits from this interface
- `I_BTSender` : every object that should send data through bluetooth inherits from this interface
### Interation:
- `button` object allows you to get a signal from the button.
    - `button.wasPressedOnce()` returns True if shortly pressed
    - `button.wasPressedOnceLong()` returns True if pressed longer than *duration* seconds
- `display` object allows you to print in the LCD-Screen
    - `display.setCursor(col, lin)`
    - `display.print("Hello")` prints at the cursor
### Sensors:
- `sonar` object allows you to get values from one sonar (not used)
- `sonarCollection` object allows you to get values from multiple sonar objects. It contains a vector of sonars
- `imu` object interacts with the IMU through the I2C bus
- `gps` object allows you to get the values of the current position.

### Communication:
- `bluetooth` object gathers the data from the bluetooth sender objects and deals with the bluetooth connection.

### Utilities
- `timer` TODO

## Branching:
- `main`: main code for the product. Never push on it.
- `develop`: development branch with changes coming.
- `feature branches` : short living branches to implement new features. Merge them on `develop` with --no-ff to prevent fast forwarting if you are sure that the code works.


