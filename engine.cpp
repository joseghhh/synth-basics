#define MINIAUDIO_IMPLEMENTATION
#include "miniaudio.h"
#include "oscillator.h"

Oscillator osc;
ma_device device;

void data_callback(ma_device* pDevice, void* pOutput, const void* pInput, ma_uint32 frameCount){
  (void)pDevice;
  (void)pInput;

  float* pOutputF32 = (float*)pOutput;

  for (ma_uint32 i=0; i<frameCount; i++){
    pOutputF32[i] = osc.nextSample();
  }
}

bool startEngine(){
    ma_device_config config = ma_device_config_init(ma_device_type_playback);
    config.playback.format = ma_format_f32;
    config.playback.channels = 1;
    config.sampleRate = 44100;
    config.dataCallback = data_callback;

    ma_result result;

    result = ma_device_init(NULL, &config, &device);

    if (result == MA_SUCCESS){
      result = ma_device_start(&device);
      if (result == MA_SUCCESS){
        return true;
      } else {
        return false;
      }
    } else {
      return false;
    }
}

void stopEngine(){
  ma_device_uninit(&device);
}