# arduino-greenhouse-temp-normalizer

An Arduino softwares that automatically turns on the exhaust fan
if the humudity, temperature inside of a greenhouse is higher
than expected.

## Module in used
- Arduino
- LCD (16x2 I2C display)
- DHT Sensor
- Relay
- Rotary Encoder

## Circuit
 
 ![Diagram](./schema/Diagram.png?raw=true)

> Note: You can replace the red LED with a 
> jumper that connects into the back of an
> I2C display where the backlight is jumped.
> With that, the I2C display will transition 
> to dim and brighten the screen brightness
> by interval. If the rotary encoder has been
> moved or the critical temp (Threshold) is
> equal below the current reading the
> brightness of an I2C display will be fixed
> at highest at possible.

## Extra

You can also change the loading screen (boot screen)
by going to `include/DEFINITION.h` and changing the 
`USE_BLOCK_BOOT` into 1.

More config you can see there.

## Social

If you have any question you can message me 
via email `jovandeguia@gmail.com` or sending 
via facebook `https://fb.com/deguia25` or 
instagram `https://instagrm.com/jxmked`.

Contribution is open. Feel free to make changes. Thanks a lt. =)

