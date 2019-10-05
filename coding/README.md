# Coding

The coding for the Arduino contains a couple of separate modules:

1. A module for the 2 8-segment digits (7 segments for the digit, and one for the dot) (the clock);
2. A module for the chime;
3. A module for handling the buttons.

## Configuration

The arduino is controlled by three push buttons:

- Button 1 (B1) is the select-button;
- Button 2 (B2) is the mode-button;
- Button 3 (B3) is the set-button.

The arduino has four different modes:

- M0 Normal operation, set an alarm;
- M1 Alarm countdown mode, an alarm is bound to set off;
- M2 Clock mode;
- M3 Configuration mode;
- MC Chime mode.

The buttons have different functions, regarding the specific mode. By looking at the display, you can alway make clear what mode is selected. In all modes B1+B3 will let you enter configuration mode. In all modes except configuration and normal operation, B2 brings you back to normal operation.

- Display black: normal operation (M0);
- Display black, both dots flashing: alarm mode (M1);
- Display black, both dots are on: alarm paused (M1);
- Display shows a number or H1..H9, both dots flashing at the same time: alarm mode (M1);
- Display shows a number or H1..H9, both dots are on: alarm paused (M1);
- Display shows a number, both dots are off: clock mode (M2), showing seconds;
- Display shows a number, right dot flashes: clock mode (M2), showing minutes;
- Display shows a number, left dot flashes: clock mode (M2), showing hours;
- First digit is a letter and both dots flash alternated: configuration select mode (M3);
- First digit is a flashing A, bot dots are off: set alarm repeat mode (M3 A);
- First digit is a flashing C, both dots are off: set chime hour mode (M3 C);
- First digit is a flashing d, both dots are off: set display mode (M3 d);
- First digit is a flashing t, both dots are off: set tempo mode (M3 t);
- First digit is a flashing F, both dots are off: set clock fine tune mode (M3 f);
- First digit is a flashing h, both dots are off: set clock chime night mode (M3 n);
- First digit is a flashing segment, both dots are off: set chime melody mode (M3 M);
- Display shows a flashing number, bot dots are off: set alarm time (M3 P), showing seconds;
- Display shows a flashing number, right dot is flashing: set alarm time (M3 P), showing minutes;
- Display shows a flashing H1..H9, left dot is flashing: set alarm time (M3 P), showing hours;

### M0 Normal operation

In normal operation, the display is totally off, and the chime will operate according to the chime configuration.

- B1: Set alarm-1;
- B2: Set alarm-2;
- B3: Set alarm-3;
- B1+B3 (pressing B1 en B3 at the same time): go into configuration mode (M3).

After setting the alarm, the alarm countdown will be shown for a couple of seconds.

### M1 Alarm countdown mode

In alarm operation, the display is off, except for the dots: they will flash at the same time. The chime will operate according to the alarm.

- B1: Show/hide alarm countdown toggle;
- B2: Stop alarm, go back to M0 mode;
- B3: Pause alarm countdown (the dots will stop flashing and light continuously);
- B1+B3: go into configuration mode (M3).

When the alarm countdown is selected, the minutes before the alarm will go off are displayed. When the countdown reaches 99 secondes, the display will show the countdown in seconds. If the alarm is more than 99 minutes, the display will show the number of hours as H1 to (at most) H9.

In alarm countdown mode, the clock-chime will ring according to the table below:

- Alarm-1: No clock chime;
- Alarm-2: Only hour clock chime;
- Alarm-3: Both hour and halve-hour clock chime.

### M2 Clock mode

In clock mode, the display will show seconds (both dots off), minutes (right dot is flashing) or hours (left dot is flashing). The chime will operate according to the chime configuration (alarm will be off).

- B1: toggle between seconds, minutes and hours;
- B2: back to M0 mode;
- B3: for seconds: set seconds to zero, for minutes and hours: add one;
- B1+B3: got into configuration mode (M3).

### M3 Configuration mode

In configuration mode, you will enter the configurion-select mode. The digits will show a submode. The left display will always be a letter, not a number. The dots will alternate. Using button 1 (B1) you can toggle between the submodes. Using button 2 (B2) will take you to the particular configuration submode. In this particular configuration submode, the digits will show the current status. Using B3 you can toggle between these status. Using button 2 brings you back to normal operation and button 1 back to the configuration-select mode.

Submodes:

- CC goto clock mode (M2)
- P1 set alarm-1 time
- P2 set alarm-2 time
- P3 set alarm-3 time
- A set alarm repeat mode
- A1 set alarm-1 chime melody
- A2 set alarm-2 chime melody
- A3 set alarm-3 chime melody
- AH set hour chime melody
- A- set halve hour chime melody
- C set hour chime mode
- tt set melody tempo
- dd set display mode
- F set clock fine-tune
- n set night mode
- C0 goto normal operation (M0)

### M3 P configuration mode

In set alarm mode, the display will show seconds (both dots off) or minutes (right dot is flashing) or hours (left dot is flashing). In set alarm mode the numbers themselves are also flashing. Hours are displayed as "H1" to "H9".

- B1: toggle between seconds, minutes and hours;
- B2: back to M0 mode;
- B3: add one;
- B1+B3: go back to configuration mode.

### M3 M melody configuration mode

In set chime melody mode, both digits will flash, the dots are black. the left digit displays the particular chime (low, middle, high), the right displays the position at which the chime will be active. Using button-1 you can toggle between the particular chimes, using button-3 you can toggle between the different positions. And button-2 will bring you back to M0:
- Digit off: no chime;
- Top left segment: first position;
- Top segment: second position;
- Top right segment: third position;
- Bottom left segment: fourth position;
- Bottom segment: fifth position;
- Bottom right hash: sixth position.

This way, you can create a six step melody, with three chimes. Empty positions at the start of the melody will be ignored, so if you want to repeate a three step melody, you should only use the bottom segments. If you use the top segments, you will actually create a six step melody! This is important when you want to repeat melodies.

### M3 A alarm repeat configuration mode

In set alarm repeat mode, the left display will show a flashing "A", the left display will show the current status. Using B3 you can toggle between status. Using B1 brings you back to the configuration mode, B2 brings you back to M0.

A0: chime off;
A1: chime ones;
A2: chime twice;
A3: chime three times;
...etc...
AA: chime until a button is pressed.

### M3 C configuration mode

In set hour chime mode, the left display will show a flashing "C", the right display will show the current status. Using B3 you can toggle between status. Using B1 brings you back to the configuration mode, B2 brings you back to M0.

C0: chime off;
C1: chime only ones;
C2: chime twice;
C3: chime three times;
CH: chime number of hours;

### M3 t configuration mode

In set tempo configuration mode, the left display will show a flashing "t", right display will show the tempo (0 is really slow, 9 is really fast). Using B3 you can toggle between status. Using B1 brings you back to the configuration mode, B2 brings you back to M0.

### M3 d display mode

In set display configuration mode, the left display will show a flashing "d", right display will show the current status. Using B3 you can toggle between status. Using B1 brings you back to the configuration mode, B2 brings you back to M0.

d0: display totally dark, except in configuration and clock modes;
d1: (default), same as d0, except dots are lit for alarm countdown (see above);
d2: same as d1, except the countdown display is on by default;
d3: same as d1, except in chime mode, the display is lit;
d4: combination of d2 and d3.

In d0 mode, you cannot see if an alarm is active. This means that it is not clear what the buttons will do:

B1: either set alarm-1 or display countdown;
B2: either set alarm-2 or reset alarm;
B3: either set alarm-3 or pause alarm.

So if you don't want confusion, don't use display mode d0 :-)

### M3 F fine tune mode

In set clock fine tune mode, you can offset the seconds that are added or substracted ones every month. F1..F9 means adding  seconds, A backwards F and 1..9 means substracting seconds. F0 is default mode: no change. Using B1 you can change between adding or substracting, using B3 you can select the number of seconds. Button B2 brings you back to normal mode.

### M3 n set night mode

In set night mode, you can select at which time the clock chime is silent. The first digit is an h (start of night mode) or a backward h (end of night mode). You can toggle between these to with button B1. The second digit is the hour itself. You can change this with button B3. If both digits are the same, night mode is off. 0-1 means: between twelve o'clock and one o'clock. The chime will not sound at twelve o'clock and half past twelve, and start again at one o'clock.

### MC chime mode

The chime mode is only active when a chime rings. This is during an alarm or when the hour or halve hour chime rings. In Chime mode, the first digit shows the remaining times the chime will occur (or the chime segment when more than 9 times). The second digit will show the currently activated chime. Mark that in default display mode (d1), the digits will remain black in chime mode!

In chime mode, all three buttons have the same function: stop the chime, and go back to normal operation (M0).
