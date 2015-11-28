
/*
  A 12-bit sampler to record sampled audio to SRAM.
  Input is sampled at 44.1 kHz and reproduced on the output.
  Recordings sampled at 22 kHz and stored to SRAM.

  See Audio Hacker project page for details.
  http://nootropicdesign.com/audiohacker/projects.html
 */


#include <AudioHacker.h>
#include "file_voice_recorded.h"


unsigned int passthroughSampleRate;
static volatile unsigned int timer1Start;
static volatile unsigned int index=0;

void setup() {
    passthroughSampleRate = 42000;
    timer1Start = UINT16_MAX - (F_CPU / passthroughSampleRate);
    AudioHacker.begin();
}

void loop() {}

ISR(TIMER1_OVF_vect) {
    TCNT1 = timer1Start;
    AudioHacker.writeDAC(voice[index++]);
    if (index == MAX_SIZE_ARRAY) {
        index = 0;
    }
}


