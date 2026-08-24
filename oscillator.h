#ifndef OSCILLATOR_H
#define OSCILLATOR_H
#include <cmath>

struct Oscillator{
  float phase = 0;
  float frequency = 440;
  float sampleRate = 44100;
  float amplitude = 0.5;
  int waveType = 0;
  
  Oscillator(){}
  
  Oscillator(float freq): frequency(freq) {}
  
  float nextSample(){
    float sample;
    
    if (waveType == 0){
      sample = sin(phase);
    } else if (waveType == 1){
      sample = (phase / 3.14159265f) - 1;
    } else if (waveType == 2){
      if (phase < 3.14159265f){
        sample = 1;
      } else {
        sample = -1;
      }
    } else {
      sample = sin(phase);
    }
    
    phase += (2 * 3.14159265f * frequency) / sampleRate;
    
    if (phase >= 2 * 3.14159265f){
      phase = phase - (2 * 3.14159265f);
    }

    sample = sample * amplitude;

    return sample;
  }
};

#endif