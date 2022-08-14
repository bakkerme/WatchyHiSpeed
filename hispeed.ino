#define ARDUINO_WATCHY_V20

#include "Watchy_hispeed.h"
#include "settings.h"

WatchyHiSpeed watchy(settings);

void setup(){
  watchy.init();
}

void loop(){}
