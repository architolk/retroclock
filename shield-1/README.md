# Shield-1

For shield-1 a protoshield is used ([this](https://www.adafruit.com/product/51) one, version 5)

This particular version has the female headers soldered on the inside. This has the disadvantage that you can't stack shields, but in this case this is actually quite nice, because we made a custom shield that is actually a bit to small for a normal shields, so the female headers on the inside actually fit pretty need.

The only downside is that no easy hole is available to solder any of the arduino pins, except for the GND and 5V rails.

This is fixed with a jumper wire attached to one of the pins of female header of the shield itself. We only need one jumper wire, connected to A0 for the 2Hz trigger.

Inspiration:
- https://learn.adafruit.com/adafruit-proto-shield-arduino/download
