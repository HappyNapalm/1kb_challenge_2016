uint8_t safe_time = 0;

void setup() {
  noInterrupts();
  //Look up data sheets for more information
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1  = 0;
  OCR1A = 31250;            // compare match register 16MHz/256/[2Hz]
  //0.5 timer
  TCCR1B |= (1 << WGM12);   // CTC mode
  TCCR1B |= (1 << CS12);    // 256 prescaler 
  TIMSK1 |= (1 << OCIE1A);  // enable timer compare interrupt
  interrupts();

  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);

  TCNT1H = 0;//clears timer High Byte
  safe_time = 0;//reset time counter
  TCNT1L = 0;//clears timer Low Byte 
}

ISR(TIMER1_COMPA_vect){//timer 1
  safe_time++;
}

void loop() {
  if (safe_time%2 == 1){
    digitalWrite(13,HIGH);
    digitalWrite(12,LOW);
  }
  else if (safe_time%3 == 1){
    digitalWrite(12,HIGH);
    digitalWrite(13,LOW);
  }
  else{
    digitalWrite(13,LOW);
    digitalWrite(12,LOW);
  }
}





