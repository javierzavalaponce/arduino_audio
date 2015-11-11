
/*
  A 12-bit sampler to record sampled audio to SRAM.
  Input is sampled at 44.1 kHz and reproduced on the output.
  Recordings sampled at 22 kHz and stored to SRAM.

  See Audio Hacker project page for details.
  http://nootropicdesign.com/audiohacker/projects.html
 */


#include <AudioHacker.h>
#include "file_audio.h"

unsigned int passthroughSampleRate;
static volatile unsigned int timer1Start;
static volatile unsigned int index=0;
static volatile unsigned int cnt=0;
int incomingByte = 0;   // for incoming serial data
void setup() {
  //Serial.begin(115200);
  passthroughSampleRate = DEFAULT_SAMPLE_RATE;
  timer1Start = UINT16_MAX - (F_CPU / passthroughSampleRate);
  AudioHacker.begin();
  //Serial.print("hola");
  cnt = 0;
  
}

void loop() {}

ISR(TIMER1_OVF_vect) {
  TCNT1 = timer1Start;
  if (cnt < 42000){
    cnt++;
    AudioHacker.writeDAC(signal[index++]>>4);
    if (index == MAX_SIZE_ARRAY){
      index = 0;
    }
  }
}


