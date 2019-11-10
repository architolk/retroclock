/*
 * PIN ASSIGNMENT
 * Change this, if the pins are routed differently on the board
 */
                 //segment: 1  2  3  4  5  6  7
const int SEGMENT_PINS[]= { 8, 7, 9, 5, 3, 4, 6};
const int DIGIT_LEFT_PIN = 11;
const int DIGIT_RIGHT_PIN =  10;
const int DOT_PIN = 2;
const int QUARTZ_PIN = A0;
const int BUTTON_ONE_PIN = A1;
const int BUTTON_TWO_PIN = A2;
const int BUTTON_THREE_PIN = A3;
const int CHIME_PINS[3]= { 1, 12, 13};

/*
 * DEBUG MODE
 * Change this, to put the arduino in debug mode
 * In debug mode, the arduino communicates only with the serial port and not with the display pins or inputs
 */
const boolean DEBUG_OFF = false;
const boolean DEBUG_ON = true;
const boolean DEBUG_MODE = DEBUG_OFF;

/*
 * TIMING CONSTANTS
 * Change this, if hardware doesn't operate correctly
 */
const uint32_t DISPLAY_REFRESH_RATE = 300;
const uint32_t QUARTZ_SCAN_RATE = 50000; //0.05 seconds
const uint32_t BUTTON_SCAN_RATE = 90000; //0.09 seconds
const uint32_t BUTTON_HOLD_TIME = 1000000; //1 second
const uint32_t MELODY_TEMPO = 2000000; //2 seconds
const uint32_t HAMMER_STRENGTH[3] = {13000, 14000, 13000}; // Larger is more strength
const uint32_t FAST_FLASH_RATE = 120000; //0.12 seconds
const uint32_t SLOW_FLASH_RATE = 600000; //0.6 seconds
const uint32_t HALF_SECOND = 500000; //0.5 seconds
const uint32_t SECOND = 1000000; //1 second

const uint32_t TEMPOS[10] = {
  2000000, // 0,  30 bpm
  1000000, // 1,  60 bpm
   666666, // 2,  90 bpm
   500000, // 3, 120 bpm
   400000, // 4, 150 bpm
   333333, // 5, 280 bpm
   285714, // 6, 210 bpm
   250000, // 7, 240 bpm
   100000, // 8, 600 bpm (every 0.1 seconds)
    10000  // 9,6000 bpm (every 0.01 seconds)
};

/*
 * SEGMENT CODING
 */
const int CHARS[]= { 
 B0111111, //0
 B0100100, //1
 B1011110, //2
 B1110110, //3
 B1100101, //4
 B1110011, //5
 B1111011, //6
 B0100110, //7
 B1111111, //8
 B1110111, //9
 B0000000, //  10 (blank)
 B0000010, //~ 11 (upper dash)
 B1000000, //- 12 (middle dash)
 B0010000, //_ 13 (lower dash)
 B1101111, //A 14
 B1111001, //b 15
 B0011011, //C 16
 B1111100, //d 17
 B1011011, //E 18
 B1001011, //F 19
 B1101101, //H 20
 B1101001, //h 21
 B1101100, //h 22 (backwards)
 B1101010, //m 23 (displayed as n with ~)
 B1101000, //n 24
 B1111000, //o 25
 B1001111, //P 26
 B1001000, //r 27
 B1110011, //S 28
 B1011001, //t 29
 B0111101, //U 30
 B0111000, //u 31
 B0111010, //w 32 (displayed as u with ~)
 B0110110, //] 33
 B1111010, //10 34 (op z'n kant)
 B0101101, //11 35 (naast elkaar)
 B1010010  //- 36 (alle drie streepjes)
};

const int DOTS_BOTH_OFF = B0000; //Both dots are off
const int DOTS_RIGHT = B0001; //Right dot is on
const int DOTS_LEFT = B0010; //Left dot is on
const int DOTS_BOTH = B0011; //Both dots are on
const int DOTS_RIGHT_FLASH = B0101; //Right dot flashes
const int DOTS_LEFT_FLASH = B0110; //Left dot flashes
const int DOTS_BOTH_FLASH = B0111; //Both dots flash
const int DOTS_ALT_FLASH = B1011; //Both dots flash alternating

const int DIGITS_OFF = 0;
const int DIGITS_ON = 1;
const int DIGITS_FLASH = 2;
const int DIGITS_SEGMENT = 3;

const int MAX_CONFIG_MODES = 34;
const int CONFIG_DISPLAY[MAX_CONFIG_MODES] = {
  1616, //CC
  2601, //P1
  2602, //P2
  2603, //P3
  2604, //P4
  2605, //P5
  2606, //P6
  2701, //r1
  2702, //r2
  2703, //r3
  2704, //r4
  2705, //r5
  2706, //r6
  2720, //rH
  2712, //r-
  1401, //A1
  1402, //A2
  1403, //A3
  1404, //A4
  1405, //A5
  1406, //A6
  1420, //AH
  1412, //A-
  2901, //t1
  2902, //t2
  2903, //t3
  2904, //t4
  2905, //t5
  2906, //t6
  2920, //tH
  2912, //t-
  1710, //d
  1910, //F
  2410  //n
};

const int MAX_DOW_MODES = 11;
const int DOW_DISPLAY[MAX_DOW_MODES] = {
  1212, //--
  2325, //mo
  2931, //tu
  3218, //wE
  2921, //th
  1927, //Fr
  2814, //SA
  2830, //SU
  1717, //dd
  2828, //SS
  1414  //AA
};

/*
 * TIME CONSTANTS
 */
const long FULL_DAY = 86400;
const long EXTRA_SECOND_INTERVAL = 12960; // The number of seconds after which an extra second is added to the clock time (to mitigate incorrect timing of the crystal)
const long EXTRA_SECOND_DISABLED = -1;

/*
 * CONFIG MODE CONSTANTS
 */
const int MODE_NORMAL = 0;
const int MODE_ALARM_COUNTDOWN = 1;
const int MODE_ALARM_PAUSED = 2;
const int MODE_CHIME_SOUNDING = 3;
const int MODE_CLOCK_DISPLAY = 4;
const int MODE_CONFIG_SELECT = 5;
const int MODE_SET_ALARM_TIME = 6;
const int MODE_SET_ALARM_REPEAT = 7;
const int MODE_SET_ALARM_MELODY = 8;
const int MODE_SET_ALARM_TEMPO = 9;
const int MODE_SET_DISPLAY_MODE = 10;
const int MODE_SET_FINE_TUNE = 11;
const int MODE_SET_NIGHT_MODE = 12;
const int MODE_DEMO = 13;

const int DISPLAY_BLACK = 0;
const int DISPLAY_ALARM_DOTS = 1;
const int DISPLAY_COUNTDOWN = 2;
const int DISPLAY_ALARM_NUMBER = 3;

const int SHOW_SECONDS = 0;
const int SHOW_MINUTES = 1;
const int SHOW_HOURS = 2;
const int SHOW_DAY_OF_WEEK = 3;

const int CHIME_ONE = 0;
const int CHIME_TWO = 1;
const int CHIME_THREE = 2;

const int PARAM_NIGHT_START = 0;
const int PARAM_NIGHT_END = 1;

const int REPEAT_ALWAYS = 20;
const int REPEAT_HOURS = 30;

/*
 * CONFIGURATION GLOBALS
 */
int clockTicks = 0;
int clockSeconds = 0; //The current second, set this to current time
int clockMinutes = 0; //The current minute, set this to current time
int clockHours = 0; // The current hour, set this to current time
int clockDayOfWeek = 0; // The current day of the week, set this to current time
long extraSecondCountdown = EXTRA_SECOND_INTERVAL; // Set this to EXTRA_SECOND_DISABLED to disable extra seconds
int alarmSeconds[8] =   { 0,  0,  0,  0,  0,  0, 0, 0};
int alarmMinutes[8] =   {30,  8,  1, 10, 30, 59, 0, 0};
int alarmHours[8] =     { 0,  0,  0,  8, 19, 17, 0, 0};
int alarmDayOfWeek[8] = { 0,  0,  0, 10, 10,  9, 0, 0};
int alarmTempo[8] = {3, 0, 0, 2, 0, 0, 0, 2};
int alarmChimeMelody[8][3] = {
  {B100000, B010000, B001000}, //alarm 1
  {B000000, B000000, B100000}, //alarm 2
  {B000000, B100000, B000000}, //alarm 3
  {B100100, B010010, B001001}, //alarm 4
  {B100100, B010010, B001001}, //alarm 5
  {B000000, B000000, B000000}, //alarm 6
  {B000000, B000000, B100000}, //hour alarm
  {B100000, B010000, B100000}, //half hour alarm
};
int alarmMelodyRepeat[8] = {4, 1, 1, 1, 1, 1, REPEAT_HOURS, 1};
int displayMode = DISPLAY_ALARM_DOTS;
int clockFineTune = 0;
int nightStart = 0;
int nightEnd = 6;

/*
 * HARDWARE RELATED GLOBALS
 */
uint32_t now = 0;
uint32_t lastDisplayRefresh = 0;
uint32_t lastQuartzScan = 0;
uint32_t lastButtonScan = 0;
uint32_t lastButton1UpScan = 0;
uint32_t lastButton2UpScan = 0;
uint32_t lastButton3UpScan = 0;
uint32_t lastChimeSounding = 0;
uint32_t lastSegmentFlash = 0;
int activeDigitPin = DIGIT_LEFT_PIN;
boolean lastQuartzState = LOW;
boolean lastButton1State = LOW;
boolean lastButton2State = LOW;
boolean lastButton3State = LOW;

/*
 * OPERATION GLOBALS
 */
long alarmTime[8] = {FULL_DAY, FULL_DAY, FULL_DAY, 0, 0, 0, 0, 0};
boolean alarmActivated[8] = {LOW, LOW, LOW, HIGH, HIGH, HIGH, HIGH, HIGH};
boolean alarmPaused = LOW;
int clockMode = MODE_NORMAL;
int configMode = 0;
int sectionMode = SHOW_SECONDS;
int selectedChime = CHIME_ONE;
int melodyPosition = 0;
int selectedNightParam = PARAM_NIGHT_START;

/*
 * DISPLAY GLOBALS
 */
int leftDigitChar = 10;
int rightDigitChar = 10;
int digitMode = DIGITS_ON;
int dotMode = 0;
int rightDigitSegements = B0000000;
int rightDigitSegmentFlash = 0;
boolean segmentFlashState = 0;

/*
 * CHIME GLOBALS
 */
int chimeMelody[3] = {B000000, B000000, B000000};
int melodyCount = 0;
uint32_t melodyTempo = MELODY_TEMPO;
int melodyStep = 0;
boolean chimeSounding = LOW;

void setup() {
  if (DEBUG_MODE) {
    Serial.begin(9600);
  }
  // Setting pins for chime
  for (int i=0; i < 3; i++) {
    pinMode(CHIME_PINS[i], OUTPUT);
    digitalWrite(CHIME_PINS[i], LOW);
  }
  // Setting pins for display
  for (int i=0; i < 7; i++) {
    pinMode(SEGMENT_PINS[i], OUTPUT);
    digitalWrite(SEGMENT_PINS[i], LOW);
  }
  pinMode(DOT_PIN, OUTPUT);
  pinMode(DIGIT_LEFT_PIN, OUTPUT);
  pinMode(DIGIT_RIGHT_PIN, OUTPUT);
  digitalWrite(DIGIT_LEFT_PIN, LOW);
  digitalWrite(DIGIT_RIGHT_PIN, LOW);
  // Setting the operation globals
  recalcAlarmTimes();
  // Going to normal operation
  gotoNormalOperation();
}

void recalcAlarmTimes() {
  alarmTime[3] = getAlarmTime(3);
  alarmTime[4] = getAlarmTime(4);
  alarmTime[5] = getAlarmTime(5);
  alarmTime[6] = getNextHourTime();
  alarmTime[7] = getNextHalfHourTime();
}

int getFirstMelodyStep() {
  int firstStep = 0;
  boolean looking = HIGH;
  while (looking) {
    boolean hit = bitRead(chimeMelody[0],firstStep) || bitRead(chimeMelody[1],firstStep) || bitRead(chimeMelody[2],firstStep);
    looking = not(hit or (firstStep > 4));
    if (looking) firstStep++;
  }
  return firstStep;
}

int getActiveAlarm() {
  int firstAlarm = -1; // No active alarms
  for (int i=3; i < 8; i++) {
    if (alarmActivated[i]) {
      if (firstAlarm == -1) {
        firstAlarm = i;
      } else {
        if (getRemainingSeconds(i) < getRemainingSeconds(firstAlarm)) {
          firstAlarm = i;
        }
      }
    }
  }
  if (alarmActivated[0]) return 0; // Alarm 1 countdown
  if (alarmActivated[1]) return 1; // Alarm 2 countdown
  if (alarmActivated[2]) return 2; // Alarm 3 countdown
  return firstAlarm; // One of the clock alarms
}

boolean isNightMode(int addHour) {
  int hourCheck = (clockHours + addHour) % 24;
  if (nightStart < nightEnd) {
    return ((hourCheck >= nightStart) && (hourCheck < nightEnd));
  } else if (nightStart > nightEnd) {
    return ((hourCheck >= (nightStart+12)) || (hourCheck< nightEnd));
  } else {
    return false;
  }
}

long getSeconds(long seconds, long minutes, long hours) {
  return seconds + 60*minutes + 3600*hours;
}

long getCurrentTime() {
  return getSeconds(clockSeconds, clockMinutes, clockHours);
}

long getAlarmTime(int alarm) {
  return getSeconds(alarmSeconds[alarm], alarmMinutes[alarm], alarmHours[alarm]);
}

long getNextHourTime() {
  if (isNightMode(1)) {
    return FULL_DAY;
  } else {
    return getSeconds(0, 0, (clockHours+1) % 24);
  }
}

long getNextHalfHourTime() {
  if (clockMinutes < 30) {
    if (isNightMode(0)) {
      return FULL_DAY;
    } else {
      return getSeconds(0, 30, clockHours);
    }
  } else {
    if (isNightMode(1)) {
      return FULL_DAY;
    } else {
      return getSeconds(0, 30, (clockHours+1) % 24);
    }
  }
}

long getRemainingSeconds(int alarm) {
  long remaining = alarmTime[alarm] - getCurrentTime();
  // Check to see if the alarmTime is the next day
  if (remaining < 0) {
    remaining = FULL_DAY + remaining;
  }
  if (remaining < 0) {
    remaining = FULL_DAY; //Safety, should not occur
  }
  return remaining; // This is incomplete: what about days of week...
}

void loop() {
  now = micros();
  if (DEBUG_MODE) {
    internalClockTick();
    sendSerialDisplay(); 
  } else {
    scanButtons();
    scanClockTick();
    checkAlarmAndClock();
    soundChime();
    showDisplay();
  }
}

void scanButtons() {
  if (now - lastButtonScan < BUTTON_SCAN_RATE) return;
  lastButtonScan = now;
  int button1State = digitalRead(BUTTON_ONE_PIN);
  int button2State = digitalRead(BUTTON_TWO_PIN);
  int button3State = digitalRead(BUTTON_THREE_PIN);
  boolean button1Pressed = LOW;
  boolean button2Pressed = LOW;
  boolean button3Pressed = LOW;
  if (button1State != lastButton1State) {
    lastButton1State = button1State;
    button1Pressed = not button1State;
    if (button1State == HIGH) lastButton1UpScan = lastButtonScan;
  }
  if (button2State != lastButton2State) {
    lastButton2State = button2State;
    button2Pressed = not button2State;
    if (button2State == HIGH) lastButton2UpScan = lastButtonScan;
  }
  if (button3State != lastButton3State) {
    lastButton3State = button3State;
    button3Pressed = not button3State;
    if (button3State == HIGH) lastButton3UpScan = lastButtonScan;
  }
  if ((button1Pressed == HIGH) && (button3Pressed == HIGH)) {
    buttonOneAndThreePressed();
  } else {
    if (button1Pressed == HIGH) {
      if (now - lastButton1UpScan > BUTTON_HOLD_TIME) {
        buttonOneHold();
      } else {
        buttonOnePressed();
      }
    }
    if (button2Pressed == HIGH) {
      if (now - lastButton2UpScan > BUTTON_HOLD_TIME) {
        buttonTwoHold();
      } else {
        buttonTwoPressed();
      }
    }
    if (button3Pressed == HIGH) {
      if (now - lastButton3UpScan > BUTTON_HOLD_TIME) {
        buttonThreeHold();
      } else {
        buttonThreePressed();
      }
    }
  }
  if ((button1State == HIGH) && (now - lastButton1UpScan > BUTTON_HOLD_TIME)) buttonOneHolding();
  if ((button2State == HIGH) && (now - lastButton2UpScan > BUTTON_HOLD_TIME)) buttonTwoHolding();
  if ((button3State == HIGH) && (now - lastButton3UpScan > BUTTON_HOLD_TIME)) buttonThreeHolding();
}

void buttonOneHolding() {
  //About to go into configuration select mode
  leftDigitChar = 16;
  rightDigitChar = 16;
  digitMode = DIGITS_FLASH;
  dotMode = DOTS_BOTH_OFF;
}

void buttonTwoHolding() {
  //About to go into demo mode
  leftDigitChar = 10;
  rightDigitChar = 33;
  digitMode = DIGITS_FLASH;
  dotMode = DOTS_BOTH_OFF;
}

void buttonThreeHolding() {
  //About to go into alarm countdown display mode
  leftDigitChar = 10;
  rightDigitChar = 10;
  digitMode = DIGITS_FLASH;
  dotMode = DOTS_BOTH_FLASH;
}

void buttonOneHold() {
  switch (clockMode) {
    case MODE_NORMAL: gotoConfigurationSelectMode(); break;
    case MODE_CONFIG_SELECT: gotoNormalOperation(); break;
    case MODE_DEMO: gotoConfigurationSelectMode(); break;
    default: returntoConfigurationSelectMode(); break;
  }
}

void buttonTwoHold() {
  if (clockMode == MODE_DEMO) {
    gotoNormalOperation();
  } else {
    gotoDemoMode();
  }
  /*
  if (clockMode == MODE_CONFIG_SELECT) {
    gotoNormalOperation();
  } else {
    gotoConfigurationSelectMode();
  }
  */
}

void buttonThreeHold() {
  clockMode = MODE_ALARM_COUNTDOWN;
  showCountdown();
}

void buttonOnePressed() {
  switch (clockMode) {
    case MODE_NORMAL: activateAlarm1countdown(); break;
    case MODE_ALARM_COUNTDOWN: toggleAlarmCountdownDisplay(); break;
    case MODE_CHIME_SOUNDING: gotoNormalOperation(); break;
    case MODE_CLOCK_DISPLAY: toggleHourMinutesSeconds(); break;
    case MODE_CONFIG_SELECT: toggleConfigurationMode(); break;
    case MODE_SET_ALARM_TIME: toggleAlarmHourMinutesSeconds(); break;
    case MODE_SET_ALARM_REPEAT: returntoConfigurationSelectMode(); break;
    case MODE_SET_ALARM_MELODY: toggleChimes(); break;
    case MODE_SET_ALARM_TEMPO: returntoConfigurationSelectMode(); break;
    case MODE_SET_DISPLAY_MODE: returntoConfigurationSelectMode(); break;
    case MODE_SET_FINE_TUNE: returntoConfigurationSelectMode(); break;
    case MODE_SET_NIGHT_MODE: toggleStartEnd(); break;
    case MODE_DEMO: activateChime(0); break;
  }
}

void buttonTwoPressed() {
  switch (clockMode) {
    case MODE_NORMAL: activateAlarm2countdown(); break;
    case MODE_SET_ALARM_MELODY: toggleMelodyPosition(); break;
    case MODE_DEMO: activateChime(1); break;
    default: gotoNormalOperation(); break;
  }
}

void buttonThreePressed() {
  switch (clockMode) {
    case MODE_NORMAL: activateAlarm3countdown(); break;
    case MODE_ALARM_COUNTDOWN: pauseAlarm(); break;
    case MODE_CHIME_SOUNDING: gotoNormalOperation(); break;
    case MODE_CLOCK_DISPLAY: setHourMinutesSeconds(); break;
    case MODE_CONFIG_SELECT: gotoConfigurationMode(); break;
    case MODE_SET_ALARM_TIME: setAlarmHourMinutesSeconds(); break;
    case MODE_SET_ALARM_REPEAT: setAlarmRepeat(); break;
    case MODE_SET_ALARM_MELODY: setMelodyPosition(); break;
    case MODE_SET_ALARM_TEMPO: setAlarmTempo(); break;
    case MODE_SET_DISPLAY_MODE: setDisplayMode(); break;
    case MODE_SET_FINE_TUNE: setFineTune(); break;
    case MODE_SET_NIGHT_MODE: setNightMode(); break;
    case MODE_DEMO: activateChime(2); break;
  }
}

void buttonOneAndThreePressed() {
  if (clockMode == MODE_CONFIG_SELECT) {
    gotoNormalOperation();
  } else {
    gotoConfigurationSelectMode();
  }
}

void activateAlarm1countdown() {
  alarmActivated[0] = HIGH;
  alarmActivated[1] = LOW;
  alarmActivated[2] = LOW;
  alarmPaused = LOW;
  clockMode = MODE_ALARM_COUNTDOWN;
  alarmTime[0] = getCurrentTime() + getAlarmTime(0);
  showCountdown();
}

void activateAlarm2countdown() {
  alarmActivated[0] = LOW;
  alarmActivated[1] = HIGH;
  alarmActivated[2] = LOW;
  alarmPaused = LOW;
  clockMode = MODE_ALARM_COUNTDOWN;
  alarmTime[1] = getCurrentTime() + getAlarmTime(1);
  showCountdown();
}

void activateAlarm3countdown() {
  alarmActivated[0] = LOW;
  alarmActivated[1] = LOW;
  alarmActivated[2] = HIGH;
  alarmPaused = LOW;
  clockMode = MODE_ALARM_COUNTDOWN;
  alarmTime[2] = getCurrentTime() + getAlarmTime(2);
  showCountdown();
}

void toggleAlarmCountdownDisplay() {
  if (displayMode == DISPLAY_COUNTDOWN) {
    displayMode = DISPLAY_ALARM_NUMBER;
  } else {
    displayMode = DISPLAY_COUNTDOWN;
  }
  showCountdown();
}

void pauseAlarm() {
  //TODO
}

void gotoNormalOperation() {
  clockMode = MODE_NORMAL;
  leftDigitChar = 10;
  rightDigitChar = 10;
  digitMode = DIGITS_OFF;
  dotMode = DOTS_BOTH_OFF;
  sectionMode = SHOW_SECONDS;
  melodyCount = 0;
  alarmActivated[0] = LOW;
  alarmActivated[1] = LOW;
  alarmActivated[2] = LOW;
  resetChime();
}

void gotoConfigurationSelectMode() {
  clockMode = MODE_CONFIG_SELECT;
  configMode = 0;
  melodyCount = 0;
  alarmActivated[0] = LOW;
  alarmActivated[1] = LOW;
  alarmActivated[2] = LOW;
  resetChime();
  showConfig();
}

void returntoConfigurationSelectMode() {
  clockMode = MODE_CONFIG_SELECT;
  showConfig();
}

void toggleHourMinutesSeconds() {
  sectionMode = (sectionMode + 1) % 4;
  showClock();
}

void toggleAlarmHourMinutesSeconds() {
  if ((configMode > 0) && (configMode < 4)) {
    sectionMode = (sectionMode + 1) % 3;
  } else {
    sectionMode = (sectionMode % 3) +1 ;
  }
  showConfig();
}

void toggleChimes() {
  selectedChime = (selectedChime + 1) % 3;
  showConfig();
}

void toggleMelodyPosition() {
  melodyPosition = (melodyPosition + 1) % 6;
  showConfig();
}

void toggleStartEnd() {
  selectedNightParam = 1 - selectedNightParam;
  showConfig();
}

void setHourMinutesSeconds() {
  if (sectionMode == SHOW_SECONDS) {
    clockSeconds = 0;
  }
  if (sectionMode == SHOW_MINUTES) {
    clockMinutes = (clockMinutes+1) % 60;
  }
  if (sectionMode == SHOW_HOURS) {
    clockHours = (clockHours+1) % 24;
  }
  if (sectionMode == SHOW_DAY_OF_WEEK) {
    clockDayOfWeek = (clockDayOfWeek % 7) + 1;
  }
  recalcAlarmTimes();
  showClock();
}

void setAlarmHourMinutesSeconds() {
  if (sectionMode == SHOW_SECONDS) {
    alarmSeconds[configMode-1] = (alarmSeconds[configMode-1]+1) % 60;
  }
  if (sectionMode == SHOW_MINUTES) {
    alarmMinutes[configMode-1] = (alarmMinutes[configMode-1]+1) % 60;
  }
  if (sectionMode == SHOW_HOURS) {
    alarmHours[configMode-1] = (alarmHours[configMode-1]+1) % 24;
  }
  if (sectionMode == SHOW_DAY_OF_WEEK) {
    alarmDayOfWeek[configMode-1] = (alarmDayOfWeek[configMode-1] % 10) + 1;
  }
  showConfig();
}

void setAlarmRepeat() {
  if (configMode == 13) {
    if (alarmMelodyRepeat[configMode-7] == REPEAT_HOURS) {
      alarmMelodyRepeat[configMode-7] = 0;
    } else {
      alarmMelodyRepeat[configMode-7] = (alarmMelodyRepeat[configMode-7]+1) % 12;
      if (alarmMelodyRepeat[configMode-7] == 10) alarmMelodyRepeat[configMode-7] = REPEAT_HOURS;
    }
  }
  else if (configMode == 14) {
    alarmMelodyRepeat[configMode-7] = (alarmMelodyRepeat[configMode-7]+1) % 10;
  } else {
    if (alarmMelodyRepeat[configMode-7] == REPEAT_ALWAYS) {
      alarmMelodyRepeat[configMode-7] = 0;
    } else {
      alarmMelodyRepeat[configMode-7] = (alarmMelodyRepeat[configMode-7]+1) % 11;
      if (alarmMelodyRepeat[configMode-7] == 10) alarmMelodyRepeat[configMode-7] = REPEAT_ALWAYS;
    }
  }
  showConfig();
}

void setMelodyPosition() {
  if (bitRead(alarmChimeMelody[configMode-15][selectedChime], melodyPosition)) {
    bitClear(alarmChimeMelody[configMode-15][selectedChime], melodyPosition);
  } else {
    bitSet(alarmChimeMelody[configMode-15][selectedChime], melodyPosition);
  }
  showConfig();
}

void setAlarmTempo() {
  alarmTempo[configMode-23] = (alarmTempo[configMode-23] + 1) % 10;
  showConfig();
}

void setDisplayMode() {
  displayMode = (displayMode+1) % 4;
  showConfig();
}

void setFineTune() {
  clockFineTune = (clockFineTune+1) % 10;
  showConfig();
}

void setNightMode() {
  if (selectedNightParam == PARAM_NIGHT_START) {
    nightStart = (nightStart + 1) % 12;
  } else {
    nightEnd = (nightEnd + 1 ) % 12;
  }
  recalcAlarmTimes();
  showConfig();
}

void toggleConfigurationMode() {
  configMode = (configMode+1) % MAX_CONFIG_MODES;
  showConfig();
}

void gotoConfigurationMode() {
  if (configMode == 0) {
    clockMode = MODE_CLOCK_DISPLAY;
    sectionMode = SHOW_SECONDS;
    showClock();
  }
  if ((configMode > 0) && (configMode < 7)) {
    clockMode = MODE_SET_ALARM_TIME;
    sectionMode = SHOW_MINUTES;
    showConfig();
  }
  if ((configMode > 6) && (configMode < 15)) {
    clockMode = MODE_SET_ALARM_REPEAT;
    showConfig();
  }
  if ((configMode > 14) && (configMode < 23)) {
    clockMode = MODE_SET_ALARM_MELODY;
    selectedChime = CHIME_ONE;
    melodyPosition = 0;
    showConfig();
  }
  if ((configMode > 22) && (configMode < 31)) {
    clockMode = MODE_SET_ALARM_TEMPO;
    showConfig();
  }
  if (configMode == 31) {
    clockMode = MODE_SET_DISPLAY_MODE;
    showConfig();
  }
  if (configMode == 32) {
    clockMode = MODE_SET_FINE_TUNE;
    showConfig();
  }
  if (configMode == 33) {
    clockMode = MODE_SET_NIGHT_MODE;
    showConfig();
  }
}

void gotoDemoMode() {
  clockMode = MODE_DEMO;
  leftDigitChar = 10;
  rightDigitChar = 33;
  digitMode = DIGITS_ON;
  dotMode = DOTS_BOTH_OFF;
}

void activateChime(int chime) {
  leftDigitChar = 11 + chime;
  melodyCount = 1;
  melodyStep = 5;
  for (int i=0; i < 3; i++) {
    if (i == chime) {
      chimeMelody[i] = B100000;
    } else {
      chimeMelody[i] = 0;
    }
  }
}

void scanClockTick() {
  if (now - lastQuartzScan < QUARTZ_SCAN_RATE) return;
  lastQuartzScan = now;
  int quartzState = digitalRead(QUARTZ_PIN);
  if (quartzState != lastQuartzState) {
    lastQuartzState = quartzState;
    if (quartzState == HIGH) {
      clockTick();
    }
  }
}

void internalClockTick() {
  if (now - lastQuartzScan < HALF_SECOND) return;
  lastQuartzScan = now;
  clockTick();
}

void clockTick() {
  clockTicks++;
  if (clockTicks > 1) {
    clockTicks = 0;
    clockAddSecond();
    if (extraSecondCountdown!=-1) {
      extraSecondCountdown--;
      if (extraSecondCountdown<=0) {
        extraSecondCountdown = EXTRA_SECOND_INTERVAL;
        checkAlarmAndClock(); //Extra checkAlarmAndClock, because we will add a second...
        clockAddSecond();
      }
    }
  }
  if (clockMode == MODE_CLOCK_DISPLAY) showClock();
  if (clockMode == MODE_ALARM_COUNTDOWN) showCountdown();
}

void clockAddSecond() {
  if (clockSeconds>58) recalcAlarmTimes(); //Way to hacky, but it works??
  clockSeconds++;
  if (clockSeconds > 59) {
    clockSeconds = 0;
    clockMinutes++;
    resetActiveAlarms(); //A bit hacky, but it works (clocktick is before checkAlarm)
    if (clockMinutes > 59) {
      clockMinutes = 0;
      clockHours++;
      if (clockHours > 23) {
        clockHours = 0;
        clockDayOfWeek++;
        if (clockDayOfWeek > 7) {
          clockDayOfWeek = 1;
        }
      }
    }
  }
}

void resetActiveAlarms() {
  for (int i=3; i < 8; i++) {
    alarmActivated[i] = HIGH;
  }
}

void showClock() {
  if (sectionMode == SHOW_SECONDS) {
    leftDigitChar = clockSeconds / 10;
    rightDigitChar = clockSeconds % 10;
    digitMode = DIGITS_ON;
    dotMode = DOTS_BOTH_OFF;
  }
  if (sectionMode == SHOW_MINUTES) {
    leftDigitChar = clockMinutes / 10;
    rightDigitChar = clockMinutes % 10;
    digitMode = DIGITS_ON;
    dotMode = DOTS_LEFT_FLASH;
  }
  if (sectionMode == SHOW_HOURS) {
    leftDigitChar = clockHours / 10;
    rightDigitChar = clockHours % 10;
    digitMode = DIGITS_ON;
    dotMode = DOTS_RIGHT_FLASH;
  }
  if (sectionMode == SHOW_DAY_OF_WEEK) {
    leftDigitChar = DOW_DISPLAY[clockDayOfWeek] / 100;
    rightDigitChar = DOW_DISPLAY[clockDayOfWeek] % 100;
    digitMode = DIGITS_ON;
    dotMode = DOTS_BOTH_OFF;
  }
}

void showConfig() {
  if (clockMode == MODE_CONFIG_SELECT) {
    digitMode = DIGITS_ON;
    dotMode = DOTS_ALT_FLASH;
    leftDigitChar = CONFIG_DISPLAY[configMode] / 100;
    rightDigitChar = CONFIG_DISPLAY[configMode] % 100;
  }
  if (clockMode == MODE_SET_ALARM_TIME) {
    if (sectionMode == SHOW_SECONDS) {
      leftDigitChar = alarmSeconds[configMode-1] / 10;
      rightDigitChar = alarmSeconds[configMode-1] % 10;
      digitMode = DIGITS_FLASH;
      dotMode = DOTS_BOTH_OFF;
    }
    if (sectionMode == SHOW_MINUTES) {
      leftDigitChar = alarmMinutes[configMode-1] / 10;
      rightDigitChar = alarmMinutes[configMode-1] % 10;
      digitMode = DIGITS_FLASH;
      dotMode = DOTS_LEFT_FLASH;
    }
    if (sectionMode == SHOW_HOURS) {
      leftDigitChar = alarmHours[configMode-1] / 10;
      rightDigitChar = alarmHours[configMode-1] % 10;
      digitMode = DIGITS_FLASH;
      dotMode = DOTS_RIGHT_FLASH;
    }
    if (sectionMode == SHOW_DAY_OF_WEEK) {
      leftDigitChar = DOW_DISPLAY[alarmDayOfWeek[configMode-1]] / 100;
      rightDigitChar = DOW_DISPLAY[alarmDayOfWeek[configMode-1]] % 100;
      digitMode = DIGITS_FLASH;
      dotMode = DOTS_BOTH_OFF;
    }
  }
  if (clockMode == MODE_SET_ALARM_REPEAT) {
    leftDigitChar = 27; //r
    if (alarmMelodyRepeat[configMode-7] == REPEAT_ALWAYS) {
      rightDigitChar = 14;
    } else if (alarmMelodyRepeat[configMode-7] == REPEAT_HOURS) {
      rightDigitChar = 20;
    } else {
      rightDigitChar = alarmMelodyRepeat[configMode-7];
    }
    digitMode = DIGITS_FLASH;
    dotMode = DOTS_BOTH_OFF;
  }
  if (clockMode == MODE_SET_ALARM_MELODY) {
    leftDigitChar = 11 + selectedChime;
    digitMode = DIGITS_SEGMENT;
    rightDigitSegements = alarmChimeMelody[configMode-15][selectedChime];
    rightDigitSegmentFlash = melodyPosition;
    dotMode = DOTS_BOTH_OFF;
  }
  if (clockMode == MODE_SET_ALARM_TEMPO) {
    leftDigitChar = 29;
    rightDigitChar = alarmTempo[configMode-23];
    digitMode = DIGITS_FLASH;
    dotMode = DOTS_BOTH_OFF;
  }
  if (clockMode == MODE_SET_DISPLAY_MODE) {
    leftDigitChar = 17;
    rightDigitChar = displayMode;
    digitMode = DIGITS_FLASH;
    dotMode = DOTS_BOTH_OFF;
  }
  if (clockMode == MODE_SET_FINE_TUNE) {
    leftDigitChar = 19;
    rightDigitChar = clockFineTune;
    digitMode = DIGITS_FLASH;
    dotMode = DOTS_BOTH_OFF;
  }
  if (clockMode == MODE_SET_NIGHT_MODE) {
    if (selectedNightParam == 0) {
      leftDigitChar = 21;
      rightDigitChar = nightStart;
    } else {
      leftDigitChar = 22;
      rightDigitChar = nightEnd;
    }
    if (rightDigitChar > 9) rightDigitChar = rightDigitChar + 24;
    digitMode = DIGITS_FLASH;
    dotMode = DOTS_BOTH_OFF;
  }
}

void showCountdown() {
  int activeAlarm = getActiveAlarm();
  if (activeAlarm!=-1) {
    if (displayMode == DISPLAY_BLACK) {
      leftDigitChar = 10;
      rightDigitChar = 10;
      digitMode = DIGITS_OFF;
      dotMode = DOTS_BOTH_OFF;
    }
    if (displayMode == DISPLAY_ALARM_DOTS) {
      leftDigitChar = 10;
      rightDigitChar = 10;
      digitMode = DIGITS_OFF;
      dotMode = DOTS_BOTH_FLASH;
    }
    if (displayMode == DISPLAY_ALARM_NUMBER) {
      leftDigitChar = 14;
      if (activeAlarm == 6) {
        rightDigitChar = 20;
      } else if (activeAlarm == 7) {
        rightDigitChar = 12;
      } else {
        rightDigitChar = activeAlarm;
      }
      digitMode = DIGITS_ON;
      dotMode = DOTS_BOTH_FLASH;
    }
    if (displayMode == DISPLAY_COUNTDOWN) {
      long remaining = getRemainingSeconds(activeAlarm);
      if (remaining <= 0) {
        leftDigitChar = 10;
        rightDigitChar = 16;
      } else if (remaining < 100) {
        leftDigitChar = remaining / 10;
        rightDigitChar = remaining % 10;
      } else {
        remaining = remaining / 60;
        if (remaining < 100) {
          leftDigitChar = remaining / 10;
          rightDigitChar = remaining % 10;
        } else {
          remaining = remaining / 60;
          leftDigitChar = 20;
          if (remaining < 10) {
            rightDigitChar = remaining;
          } else {
            rightDigitChar = 20;
          }
        }
      }
      digitMode = DIGITS_ON;
      dotMode = DOTS_BOTH_FLASH;
    }
  }
}

void sendSerialDisplay() {
  if (now - lastDisplayRefresh < SECOND) return;
  lastDisplayRefresh = now;
  int activeAlarm = getActiveAlarm();
  Serial.println("Time: " + String(clockHours,DEC) + ":" + String(clockMinutes,DEC) + ":" + String(clockSeconds,DEC) + " Active alarm: " + String(activeAlarm,DEC) + " Remaining seconds: " + String(getRemainingSeconds(activeAlarm),DEC));
}

void showDisplay() {
  if (now - lastDisplayRefresh < DISPLAY_REFRESH_RATE) return;
  lastDisplayRefresh = now;
  int flashing = 1;
  if (dotMode > 3) {
    flashing = clockTicks % 2;
  }
  boolean activeDigits = ((digitMode == DIGITS_ON) || (digitMode == DIGITS_SEGMENT));
  if (digitMode == DIGITS_FLASH) activeDigits = ((clockTicks %2) == 1);
  if (activeDigitPin == DIGIT_LEFT_PIN) {
    if (dotMode > 7) {
      flashing = 1-flashing;
    }
    digitalWrite(DIGIT_LEFT_PIN,LOW);
    showDigit(leftDigitChar, flashing * (dotMode % 2), activeDigits);
    activeDigitPin = DIGIT_RIGHT_PIN;
  } else {
    digitalWrite(DIGIT_RIGHT_PIN,LOW);
    if (digitMode == DIGITS_SEGMENT) {
      showSegment(rightDigitSegements, rightDigitSegmentFlash, flashing * (dotMode % 4) / 2);
    } else {
      showDigit(rightDigitChar, flashing * (dotMode % 4) / 2, activeDigits);
    }
    activeDigitPin = DIGIT_LEFT_PIN;
  }
  digitalWrite(activeDigitPin,HIGH);
}

void showDigit(int digitChar, int dotState, boolean activeDigit) {
  for (int segment= 0; segment < 7; segment++) {
    boolean isBitSet= bitRead(CHARS[digitChar], segment);
    digitalWrite(SEGMENT_PINS[segment], isBitSet && activeDigit);
  }
  digitalWrite(DOT_PIN, dotState);
}

void showSegment(int segmentCode, int segmentFlash, int dotState) {
  if (now - lastSegmentFlash > SLOW_FLASH_RATE) {
    segmentFlashState = LOW;
    lastSegmentFlash = now;
  } else if (now - lastSegmentFlash > FAST_FLASH_RATE) {
    segmentFlashState = HIGH;
  }
  for (int segment= 0; segment < 7; segment++) {
    boolean isBitSet= bitRead(segmentCode, segment);
    if (segment == segmentFlash) {
      isBitSet = not(isBitSet ^ segmentFlashState);
    }
    digitalWrite(SEGMENT_PINS[segment], isBitSet);
  }
  digitalWrite(DOT_PIN, dotState);
}

void checkAlarmAndClock() {
  int activeAlarm = getActiveAlarm();
  if (activeAlarm!=-1) {
    long remaining = getRemainingSeconds(activeAlarm);
    if (remaining <= 0) {
      clockMode = MODE_CHIME_SOUNDING;
      leftDigitChar = 10;
      rightDigitChar = 36;
      digitMode = DIGITS_ON;
      dotMode = DOTS_BOTH_OFF;
      alarmActivated[0] = LOW;
      alarmActivated[1] = LOW;
      alarmActivated[2] = LOW;
      alarmActivated[activeAlarm] = LOW;
      chimeMelody[0] = alarmChimeMelody[activeAlarm][0];
      chimeMelody[1] = alarmChimeMelody[activeAlarm][1];
      chimeMelody[2] = alarmChimeMelody[activeAlarm][2];
      melodyCount = alarmMelodyRepeat[activeAlarm];
      if (melodyCount == REPEAT_HOURS) {
        melodyCount = (clockHours % 12);
        if (melodyCount == 0) {
          melodyCount = 12;
        }
      }
      melodyTempo = TEMPOS[alarmTempo[activeAlarm]];
      melodyStep = getFirstMelodyStep();
      lastChimeSounding = now - melodyTempo;
    }
  }
}

void soundChime() {
  if (melodyCount == 0) {
    lastChimeSounding = now - melodyTempo;
  } else {
    if (chimeSounding == LOW) {
      if (now - lastChimeSounding < melodyTempo) return;
      lastChimeSounding = now;
      chimeSounding = HIGH;
      for (int chime=0; chime < 3; chime++) {
        boolean hit = bitRead(chimeMelody[chime],melodyStep);
        digitalWrite(CHIME_PINS[chime], hit);
      }
    } else {
      int upcount = 3;
      for (int chime=0; chime < 3; chime++) {
        if (now - lastChimeSounding > HAMMER_STRENGTH[chime]) {
          digitalWrite(CHIME_PINS[chime], LOW);
          upcount--;
        }
      }
      if (upcount==0) {
        leftDigitChar=10;
        lastChimeSounding = now;
        chimeSounding = LOW;
        melodyStep++;
        if (melodyStep > 5) {
          melodyStep = getFirstMelodyStep();
          if (melodyCount != REPEAT_ALWAYS) melodyCount--;
        }
      }
      if ((melodyCount==0) && (clockMode == MODE_CHIME_SOUNDING)) {
        gotoNormalOperation();
      }
    }
  }
}

void resetChime() {
  for (int chime=0; chime < 3; chime++) {
    digitalWrite(CHIME_PINS[chime], LOW);
  }
}
