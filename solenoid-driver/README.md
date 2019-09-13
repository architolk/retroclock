# Simple solenoid driver

![](solenoid-driver_schema.svg)

This version of the solenoid driver is pretty simple. It uses a IRF540 transistor for handling the large amount of current for the solenoid. A 2.2mF (= 2200uF) capacitor is used the give the voltage source some buffer. 2200uF is actually not enough for one push of the solenoid (tested at 9V), but enough to give the voltage source some support without effecting the other parts of the circuit.

A more elaborate version would include a resistor and a capacitor the handle the difference between the voltage needed to get the solenoid moving and the voltage needed to keep the solenoid in place. We don't need this, because in this case, the solenoid is used as a "hammer", so we really want the solenoid to get back to its original position.

The diode is needed to protect the circuit, because the solenoid will produce current as it goes back to its original position.

The 1K resistor is used as a current protection to the arduino digital out pin. Don't think this is really necessary, just to be safe.

![](solenoid-driver_bb.svg)

|Part|Description|
|----|-----------|
| Q1 | IRF540 Power MOSFET |
| D1 | 1N4004 Diode |
| C1 | 2200uF Electrolite capacitor |
| R1 | 1K resistor |
