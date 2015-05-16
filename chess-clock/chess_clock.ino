const int buttonPin = 2;
const int cooldownPin = 13;
const int steepPin = 12;
const int warningPin = 11;
const int buzzerPin = 9;
const int songLength = 15;

char notes[] = "cdefgabCbagfedc";
char rickRoll[] = "cdfda ag cdfdg gf ";
int tempo = 150;
bool reachedEnd = false;

void setup() {
  // put your setup code here, to run once:
  pinMode( buttonPin, INPUT );
  pinMode( cooldownPin, OUTPUT );
  pinMode( steepPin, OUTPUT );
  pinMode( warningPin, OUTPUT );
  pinMode( buzzerPin, OUTPUT );
}

void loop() {
  // put your main code here, to run repeatedly:
  int buttonState;
  int cooldownPinState;
  int steepPinState;
  int warningPinState;
  
  buttonState = digitalRead( buttonPin );
  
  if ( buttonState == LOW ) {
    resetPins();
    coolDownTimer();
    resetPins();
    steepTimer();
    reachedEnd = true;
  }
  
  if ( reachedEnd == true ) {
    resetPins();
    playRickRoll();
    celebrate();
  }
}

void coolDownTimer() {
  for ( int i = 1 ; i <= 60 ; ++i ) {
    digitalWrite( cooldownPin, HIGH );
    if ( i == 50 ) {
      digitalWrite( warningPin, HIGH );
      playAlarm();
    }
    delay( 1000 );
  }
}

void steepTimer() {
  for ( int i = 1 ; i <= (5 * 60) ; ++i ) {
    digitalWrite( steepPin, HIGH );
    if ( i == 50 ) {
      digitalWrite( warningPin, HIGH );
      playAlarm();
    }
    if ( i == 60 ) {
      digitalWrite( warningPin, LOW );
    }
    if ( i == ((5 * 60) - 10) ) {
      digitalWrite( warningPin, HIGH );
      playAlarm();
    }
    delay ( 1000 );
  }
}

void playRickRoll() {
  int i, duration;
  
  for ( i = 0 ; i < 18 ; ++i ) {
    duration = tempo;
    
    if ( rickRoll[i] == ' ' ) {
      delay(duration);
    }
    else {
      tone( buzzerPin, frequency(rickRoll[i]), duration );
      delay( duration );
    }
    delay( tempo/10 );
  }
}

void resetPins() {
  digitalWrite( cooldownPin, LOW );
  digitalWrite( steepPin, LOW );
  digitalWrite( warningPin, LOW );
}

void playAlarm() {
  int i, duration;
  
  for ( i = 0 ; i < songLength ; ++i ) {
    duration = tempo;
    
    if ( notes[i] == ' ' ) {
      delay(duration);
    }
    else {
      tone( buzzerPin, frequency(notes[i]), duration );
      delay( duration );
    }
    delay( tempo/10 );
  }
}

int frequency( char note ) {
  int i;
  const int numNotes = 8;

  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int frequencies[] = { 262, 294, 330, 349, 392, 440, 494, 523 };
  
  for ( i = 0 ; i < numNotes ; ++i ) {
    if ( names[i] == note ) {
      return( frequencies[i] );
    }
  }
  return( 0 );
}

void celebrate() {
  for ( int i = 0 ; i < 10 ; ++i ) {
    digitalWrite( cooldownPin, HIGH );
    digitalWrite( steepPin, LOW );
    digitalWrite( warningPin, LOW);
    delay( 400 );
    digitalWrite( cooldownPin, LOW );
    digitalWrite( steepPin, HIGH );
    digitalWrite( warningPin, LOW);
    delay( 400 );
    digitalWrite( cooldownPin, LOW );
    digitalWrite( steepPin, LOW );
    digitalWrite( warningPin, HIGH);
    delay( 400 );
    digitalWrite( cooldownPin, LOW );
    digitalWrite( steepPin, HIGH );
    digitalWrite( warningPin, LOW);
    delay(400);
  }
}
  
  
