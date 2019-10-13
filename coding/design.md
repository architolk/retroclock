# Design

## 0. Initialisatie
De initialisatie bestaat uit drie onderdelen:

1. Configuratie van de hardware en scanvariabelen resetten;
2. Laden van de defaultconfiguratie;
3. Aanroep van gotoNormalOperation.

The clock has eight "alarms":
- alarm 1, 2 and 3 are stopwatch alarms and will sound after some interval;
- alarm 4, 5 and 6 are timer alarms and will sound at a specific point in time;
- alarm 7 is the hour chime and will sound every hour at full hour;
- alarm 8 is the halve-hour chime and will sound every hour at halve hour.

## 0.1 currentTime()
The function currentTime() gives the currentTime, calculated from the clock:
- currentTime = seconds + 60 * minutes + 3600 * hours

## 0.2 remainingTime(timepoint)
The function remainingTime() give the remaining seconds between the timepoint and the currentTime():
- if timepoint > currentTime() then remainingTime = timepoint - currentTime();
- if timepoint + 12*3600 < currentTime() then remainingTime = timepoint + 24*3600 - currentTime(); (different days)
- in other cases, the remainingTime is actually negative, so it is set to 24*3600

If the alarm is passed, not pausedTime is used instead of currentTime()

## 0.3 seconds(timepoint)
Returns the seconds-part of a timepoint

## 0.4 minutes(timepoint)
Returns the minutes-part of a timepoint

## 0.5 hours(timepoint)
Returns the hours-part of a timepoint

## 1. Main loop
Calls the scan methods and the display and chime methods

An important variable is the clockMode variable. This variable controles what mode the clock is:
- 0: Normal mode (display is black) [M0]
- 1: Alarm countdown mode [M1]
- 2: Alarm paused mode [M1]
- 3: Chime mode (alarm is sounding) [Chime]
- 4: Clock mode (display shows hours/minutes/seconds) [M2]
- 5: Configuration select mode [M3]
- 6: Set alarm time [M3 P]
- 7: Set alarm repeat configuration mode [M3 r]
- 8: Set alarm melody [M3 A]
- 9: Set alarm tempo [M3 t]
- 10: Set display mode [M3 d]
- 11: Fine tune clock [M3 F]
- 12: Set night mode [M3 n]

## 1.1 scanButtons
Method scans the buttons and calls the appropriate method when a button is pressed:

1. button1pressed
2. button2pressed
3. button3pressed
4. button1and3pressed

The call performed on the down-side of the button-gate, otherwise it is not possible to know when the combination buttons are pressed.

## 1.2 scanClockTick
Method scans the clock tick operation. Every clock tick, a call to the clockTick method is performed. The call is performed on the up-side of the clock tick.

## 1.3 clockTick
advances the seconds, minutes and/or hours every other clocktick. When clockMode is 4 (clock mode), the display is set according to the showHourMinutesSecondsStatus:

- 0: show seconds, dotMode = 0;
- 1: show minutes, dotMode alternates between 0 en 1 (right dot flashes every second)
- 2: show hours, dotMode alternates between 0 en 2 (left dot flashes every second)

showing seconds, minutes and hours is done by setting the leftDigitChar and rightDigitChar to the value of seconds(currentTime()), minutes(...) or hours(...).

## 1.4 showDisplay
Method activates the display, using the multiplex operation (switching between left and right digit). The showDisplay uses the globally defined variables:

- leftDigitChar (int)
- rightDigitChar (int)
- digitMode (int)
- dotMode (int)
- rightDigitSegments (int)
- rightDigitSegmentFlash (int)

digitMode specifies which mode the digits are operating in:
- 0: both digits off (black)
- 1: normal operation (char digits)
- 2: flash operation (char digits)
- 3: segment mode (left and right digit char are ignored, segments and segmentFlash are used)

The left and right digit chars are defined as:
- 0 = 0
- 1 = 1
- 2 = 2
- 3 = 3
- 4 = 4
- 5 = 5
- 6 = 6
- 7 = 7
- 8 = 8
- 9 = 9
- 10 = <empty>
- 11 = C
- 12 = P
- 13 = H
- 14 = ..

The dotMode is defined as:
- 0 (000): dots off
- 1 (001): right dot on
- 2 (010): left dot on
- 3 (011): both dots on
- 4 (100): both dots off
- 5 (101): right dot flashing
- 6 (110): left dot flashing
- 7 (111): both dots flashing
- 8 (1000): dots alternating flashing

rightDigitSegments and rightDigitSegmentFlash are special modes. The rightDigitSegments will specify which segments need to light up. this is according to the following mapping, with bit-1 being the least significant bit and bit-7 the most significant bit. The right digitSegmentFlash will specify with segment need to flash (only one segment will flash at a particular point in time, although the method will allow more than one).

```
7     1
0000000

 22
1  3
1  3
 77
4  6
4  6
 55

```

The rightDigitSegmentFlash will flash long-on/short-off for segments that are "on" in the rightDigitSegments variable, and will flash short-on/long-off for segments that are "off" in the rightDigitSegments variable.

## 1.5 checkAlarmAndClock
Method checks if an alarm needs to sound. It also checks if the clock chime needs to sound. Six alarms are possible. The check is a simple comparison between the `currentTime()` function and the global variable containing the moment the alarm should sound. The alarmTime should exactly the currentTime(). If the alarm is sounding, the alarm should not be triggered again. This means that the alarmActivated value is immediately to false (because the check is done more than ones a second, which means that the value will be exactly the same more than ones). After one second the alarmActivated is reset to true for alarms 4, 5, 6, 7 and 8. The first three alarms are only activated by a button press. The alarmTime for alarms 7 and 8 are increased by a full hour.

- alarmTime[8] (longint): the time the alarm should sound
- alarmActivated[8] (boolean): false when the alarm should not go off, true when the alarm is activated.
- alarmPaused: true if the alarm is paused (in such a case, the checkAlarmAndClock will immediately return and won't do any other function)

The checkAlarmAndClock will set the melodyCount to the configured melodyCount for the particular alarm and the melodyNumber will be the alarm number. The variable melodyStep will be set to 0:

- melodyNumber = number of the alarm that should sound;
- melodyCount = alarmRepeatMode[melodyNumber];
- melodyStep = 0.

when the alarm is the hour chime alarm and melodyCount = 20 (continuously), the melodyCount is set to the hours variable, modulo 12.

## 1.6 soundChime
Method sounds the chime, when appropriate. The soundChime method uses the following globally defined variables (set by the checkAlarmAndClock method):

- melodyNumber: the specific melody that needs to sound
- chimeTempo: the tempo of the melody
- melodyStep: the particular step of the melody (updated by this method itself)
- melodyCount: the number the melody needs to sound

After each completed melody, the melodyCount is decreased by one, except when the melodyCount is 20. The chime will stop when the melodyCount is zero. When a chime sounds, the chime can also be stopped by pressing a button (this will set the melodyCount to zero).

## 1.7 showConfigDisplay
This function is called to set the display to the corresponding value, according to the configMode, the clockMode and other configuration variables, using this table:

|clockMode|Display|digitMode|dotMode|Description|
|---|----|---|---|---------|
| 5 | .. | 1 | 8 | See table in gotoConfigurationSubmode
| 6 | 00 | 2 | . | alarmHours/alarmMinutes/alarmSeconds[configMode-1] from showHourMinutesSecondsStatus. It also sets the dotMode between 0, 1 and 2 |
| 7 | r0 | 2 | 0 | leftDigitChar = r, rightDigitChar = alarmRepeatMode[0..8] |
| 8 | -. | 2 | 0 | leftDigitChar = selectedChime, rightDigitSegment = melody bar [0..8] and melodyPosition
| 9 | t0 | 2 | 0 | leftDigitChar = t, rightDigitChar = alarmTempo[0..8]
|10 | d0 | 2 | 0 | leftDigitChar = d, rightDigitChar = displayMode
|11 | F0 | 2 | 0 | leftDigitChar = F, rightDigitChar = clockFineTune
|12 | n0 | 2 | 0 | leftDigitChar = h or reverse h depening on the showStartEndStatus variable, rightDigitChar = nightStart / nightEnd

In clockMode 8 (set melody), the rightDigit is controlled as a segment. This means that the segements that are "on" in the melody bar are lit. The segment that is at the melodyPosition flashes. The "on" period is short for off segments and "off" for long segments.

In clockMode 6 (set alarm), in case of alarms 4, 5 and 6 no seconds are displayed, but a value that stated at which day of the week the alarm will sound (see setAlarmHourMinutesSeconds below).

## 2.1 button1pressed

Depending on the clockMode the button1pressed will operate as follows:

- 0: activateAlarm1countdown;
- 1: toggleAlarmCountdownDisplay;
- 2: toggleAlarmCountdownDisplay;
- 3: gotoNormalOperation (stop alarm);
- 4: toggleHourMinutesSeconds;
- 5: toggleConfigurationMode;
- 6: toggleAlarmHourMinutesSeconds;
- 7: gotoConfigurationMode;
- 8: toggleChimes;
- 9: gotoConfigurationMode;
- 10: gotoConfigurationMode;
- 11: gotoConfigurationMode;
- 12: toggleStartEndStatus;

## 2.2 button2pressed

Depending on the clockMode the button2pressed will operate as follows:

- 0: activateAlarm2countdown;
- 1: gotoNormalOperation (stop alarm countdown);
- 2: gotoNormalOperation (stop alarm countdown);
- 3: gotoNormalOperation (stop alarm);
- 4: gotoNormalOperation;
- 5: gotoNormalOperation;
- 6: gotoNormalOperation;
- 7: gotoNormalOperation;
- 8: toggleMelodyPosition;
- 9: gotoNormalOperation;
- 10: gotoNormalOperation;
- 11: gotoNormalOperation;
- 12: gotoNormalOperation;

## 2.3 button3pressed

Depending on the clockMode the button3pressed will operate as follows:

- 0: activateAlarm3countdown;
- 1: pauseAlarmCountdown;
- 2: unpauseAlarmCountdown;
- 3: gotoNormalOperation (stop alarm);
- 4: setHourMinutesSeconds;
- 5: gotoConfigurationSubmode;
- 6: setAlarmHourMinutesSeconds;
- 7: setRepeatMode;
- 8: setMelodyPosition;
- 9: setAlarmTempo;
- 10: setDisplayMode;
- 11: setClockFineTune;
- 12: setNightMode;

## 2.4 button1and3pressed

Pressing buttons 1 and 3 at the same time will always bring you in configuration select mode:

- gotoConfigurationMode;
- gotoNormalOperation (only in clockMode = 5, configurationMode)

## 3.1 activateAlarm1countdown

The alarm time is calculated and the alarm is activated. The clockmode is set to 1 (alarm countdown mode). The display is black and the dots are flashing.

- alarmTime[0] = currentTime() + alarmPeriod[0], modulo 24*3600;
- alarmActivated[0] = true;
- alarmActivate[1] = false;
- alarmActivate[2] = false;
- alarmPaused = false;
- clockMode = 1;
- leftDigitChar = 10;
- rightDigitChar = 10;
- digitMode = 0;
- dotMode = 7;

## 3.2 activateAlarm2countdown

The alarm time is calculated and the alarm is activated. The clockmode is set to 1 (alarm countdown mode). The display is black and the dots are flashing. See 3.1 for exact variables.

## 3.3 activateAlarm3countdown

The alarm time is calculated and the alarm is activated. The clockmode is set to 1 (alarm countdown mode). The display is black and the dots are flashing. See 3.1 for exact variables.

## 3.4 gotoNormalOperation

Goto normal operation means that any alarm countdown should be deactivated and if the alarm is sounding, this should be stopped as well. The display should be black.

- alarmActivated[0..2] = false;
- alarmPaused = false;
- clockMode = 0;
- melodyCount = 0;
- leftDigitChar = 10;
- rightDigitChar = 10;
- digitMode = 0;
- dotMode = 0;
- showHourMinutesSecondsStatus = 0;

## 3.5 pauseAlarmCountdown

- alarmPaused = true;
- pauseTime = currentTime();
- clockMode = 2;
- melodyCount = 0;
- dotMode = 3;

## 3.6 unpauseAlarmCountdown

The alarm time should be increased with the time passed between the current time and the moment the alarm was passed.

- alarmPaused = false;
- alarmTime[0..2] = alarmTime[0..2] + currentTime() - pauseTime;
- clockMode = 1;
- melodyCount = 0;
- dotMode = 7;

## 3.7 toggleAlarmCountdownDisplay

When the digitMode is 0 (black display), the digitMode is set to 1 (normal mode) and the left- and right digit characters are set to the remaining time. When the digitMode is 1 (display shows countdown), the digitMode is set to 0.

For the alarmTime[x] that is activated (with x between 0..2), do the following:

- When remainingTime(alarmTime) is less than 100 seconds, set left- and right digit chars to the seconds remaining value;
- When remainingTime(alarmTime) is more than 99 seconds and less than 100 minutes, set left- and right digit chars to the minutes remaining value;
- When remainingTime(alarmTime) is more than 99 minutes and less than 10 hours, set left char to 13 (H) and right char to hours remaining value;
- In other cases, set left- and right digit characters to 13 (H).

When the alarm is paused, instead of currentTime(), the value of pausedTime should be used for the remaining time.

## 3.8 toggleHourMinutesSeconds

This simple toggles the showHourMinutesSecondsStatus values between 0 en 2. The actual display is done in the clockTick method.

## 3.9 toggleAlarmHourMinutesSeconds

This toggles the showHourMinutesSecondsStatus values between 0 en 2 and calls the showConfigDisplay().

## 3.10 setHourMinutesSeconds

Depending on the status of setHourMinutesSeconds it does the following:

- Reset the seconds to 0;
- Increase minutes with 1, modulo 60;
- Increase hours with 1, module 24;

(the actual display is controlled by clockTick).

## 3.11 setAlarmHourMinutesSeconds

Depending on the status of setHourMinutesSeconds it increases the values of alarmHours, alarmMinutes or alarmSeconds [0..2], and calls showConfigDisplay().

For alarms 4, 5 and 6, the alarmSeconds are not displayed, but the following:

- AA alarm will sound on every day
- SA: alarm will only sound on saturday
- SU: alarm will only sound on sunday
- SS: alarm will sound on saterday and sunday
- dd: alarm will only sound from monday to friday

## 3.12 gotoConfigurationMode

Goto configurationMode means going tot clockMode 5:

- clockMode = 5;
- clockConfigMode = 0

To display this, showConfigDisplay() is called.

## 3.13 toggleConfigurationMode

This changes the configuration mode:

- clockMode = 5
- clockConfigMode = clockConfigMode +1 (after maximum, back to 0);

To display this, showConfigDisplay() is called.

## 3.14 gotoConfigurationSubmode

This changes the clock mode, depending on the configuration mode:

|Configmode|Clockmode|Display|Description|
|----------|-------|---------|-----------|
| 0 | 4 | CC | Clock mode |
| 1 | 6 | P1 | Set alarm-1 time |
| 2 | 6 | P2 | Set alarm-2 time |
| 3 | 6 | P3 | Set alarm-3 time |
| 4 | 6 | P4 | Set alarm-4 time |
| 5 | 6 | P5 | Set alarm-5 time |
| 6 | 6 | P6 | Set alarm-6 time |
| 7 | 7 | r1 | Set alarm-1 repeat mode |
| 8 | 7 | r2 | Set alarm-2 repeat mode |
| 9 | 7 | r3 | Set alarm-3 repeat mode |
|10 | 7 | r4 | Set alarm-4 repeat mode |
|11 | 7 | r5 | Set alarm-5 repeat mode |
|12 | 7 | r6 | Set alarm-6 repeat mode |
|13 | 7 | rH | Set hour chime repeat mode |
|14 | 7 | r- | Set halve hour chime repeat mode |
|15 | 8 | A1 | Set alarm-1 melody |
|16 | 8 | A2 | Set alarm-2 melody |
|17 | 8 | A3 | Set alarm-3 melody |
|18 | 8 | A4 | Set alarm-4 melody |
|19 | 8 | A5 | Set alarm-5 melody |
|20 | 8 | A6 | Set alarm-6 melody |
|21 | 8 | AH | Set hour chime melody |
|22 | 8 | A- | Set halve hour chime melody |
|23 | 9 | t1 | Set alarm-1 melody tempo |
|24 | 9 | t2 | Set alarm-1 melody tempo |
|25 | 9 | t3 | Set alarm-1 melody tempo |
|26 | 9 | t4 | Set alarm-1 melody tempo |
|27 | 9 | t5 | Set alarm-1 melody tempo |
|28 | 9 | t6 | Set alarm-1 melody tempo |
|29 | 9 | tH | Set hour chime melody tempo |
|30 | 9 | t- | Set halve hour melody tempo |
|31 |10 | dd | Set display mode |
|32 |11 | F  | Set clock fine-tune |
|33 |12 | n  | Set night mode |

The clockMode is changed to the value depicted in the table below and the showConfigDisplay() method is called.

## 3.15 setRepeatMode

Increases the alarmRepeatMode[0.8] and calls showConfigDisplay().

## 3.16 toggleChime

Toggles the selectedChime between 0 and 2 and calls showConfigDisplay().

## 3.17 toggleMelodyPosition

Toggles the melodyPosition between 1, 2, 4, 8, 16, 32, 64 and calls showConfigDisplay().

## 3.18 setMelodyPosition

Adds a bit in the melody[0..2] [0..8] at the corresponding melodyPosition or removes it.

## 3.19 setAlarmTempo

Increases alarmTempo[0..8] and calls showConfigDisplay().

## 3.20 toggleStartEndStatus

Toggles the status of showStartEndStatus

## 3.21 setNightMode

increase the value of nightStart or nightEnd, depending on the value of showStartEndStatus.
