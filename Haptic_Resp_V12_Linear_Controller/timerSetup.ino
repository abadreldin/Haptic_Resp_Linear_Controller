// Timer0 for Blue Motor position, Timer2 for Red Motor position

void timerSetup (void){



  /* //set timer1 interrupt at 8kHz
  TCCR1A = 0;// set entire TCCR2A register to 0
  TCCR1B = 0;// same for TCCR2B
  TCNT1  = 0;//initialize counter value to 0
  // set compare match register for 8khz increments
  OCR1A = 249;// = (16*10^6) / (8000*8) - 1 (must be <256)
  // turn on CTC mode
  TCCR1A |= (1 << WGM11);
  // Set CS21 bit for 8 prescaler
  TCCR1B |= (1 << CS11);   
  // enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A);*/

     //set timer1 interrupt at 8kHz
  /*TCCR5A = 0;// set entire TCCR2A register to 0
  TCCR5B = 0;// same for TCCR2B
  TCNT5  = 0;//initialize counter value to 0
  // set compare match register for 8khz increments
  OCR5A = 249;// = (16*10^6) / (8000*8) - 1 (must be <256)
  // turn on CTC mode
  TCCR5A |= (1 << WGM51);
  // Set CS21 bit for 8 prescaler
  TCCR5B |= (1 << CS51);   
  // enable timer compare interrupt
  TIMSK5 |= (1 << OCIE5A);*/
  
  //set timer0 interrupt at 2kHz
  TCCR5A = 0;// set entire TCCR2A register to 0
  TCCR5B = 0;// same for TCCR2B
  TCNT5  = 0;//initialize counter value to 0
  // set compare match register for 2khz increments
  OCR5A = 249;// = (16*10^6) / (8000*8) - 1(must be <256)
  // turn on CTC mode
  TCCR5A |= (1 << WGM12);
  // Set CS01 and CS00 bits for 64 prescaler
  TCCR5B |= (1 << CS21);  
  // enable timer compare interrupt
  TIMSK5 |= (1 << OCIE5A);

  /*//set timer2 interrupt at 8kHz
  TCCR2A = 0;// set entire TCCR2A register to 0
  TCCR2B = 0;// same for TCCR2B
  TCNT2  = 0;//initialize counter value to 0
  // set compare match register for 8khz increments
  OCR2A = 249;// = (16*10^6) / (8000*8) - 1 (must be <256)
  // turn on CTC mode
  TCCR2A |= (1 << WGM21);
  // Set CS21 bit for 8 prescaler
  TCCR2B |= (1 << CS21);   
  // enable timer compare interrupt
  TIMSK2 |= (1 << OCIE2A);*/

}

