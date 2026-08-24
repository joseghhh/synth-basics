#include <iostream>
#include <string>
#include "engine.h"

int main(){
  std::string type;
  float freq;

  std::cout<<"type frequency"<<std::endl;
  std::cin>> type >> freq;
  std::cin.get();

  osc.frequency = freq;
  
  if (type == "sin"){
    osc.waveType = 0;
  } else if (type == "saw"){
    osc.waveType = 1;
  } else if (type == "sqr"){
    osc.waveType = 2;
  } else {
    std::cout<<"invalid wave type, using: sin";
    osc.waveType = 0;
  }

  bool init = startEngine();

  if (init){
    std::cout<<"all good...";
    std::cin.get();
    stopEngine();
  } else {
    std::cout<<"init is not true.";
    return 0;
  }
}
