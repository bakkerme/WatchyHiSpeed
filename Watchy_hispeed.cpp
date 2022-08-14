#include "Watchy_hispeed.h"

#define DARKMODE true

void WatchyHiSpeed::drawTime(){
  display.setFont(&SquaredDisplayMonospaced40pt7b);

  int8_t hourTwelve = currentTime.Hour % 12;
  char timeHour[3];
  timeHour[0] = '0' + ((hourTwelve/10)%10);
  timeHour[1] = '0' + (hourTwelve%10);
  timeHour[2] = 0;

  char timeMinute[3];
  timeMinute[0] = '0' + ((currentTime.Minute/10)%10);
  timeMinute[1] = '0' + (currentTime.Minute%10);
  timeMinute[2] = 0;

  // Hour
  display.setCursor(21, 65);
  display.println(timeHour);
  // Minute
  display.setCursor(107, 65);
  display.println(timeMinute);

  // Draw colon
  int8_t colonX = 99;
  int8_t colonWidth = 2;
  display.drawRect(colonX, 30, colonWidth, 8, DARKMODE ? GxEPD_WHITE : GxEPD_BLACK);
  display.drawRect(colonX, 50, colonWidth, 8, DARKMODE ? GxEPD_WHITE : GxEPD_BLACK);
}

void WatchyHiSpeed::drawTemperature(){
    // Temperature
    display.setFont(&SquaredDisplayMonospaced27pt7b);
    weatherData currentWeather = getWeatherData();
    int8_t temperature = currentWeather.temperature;
    display.setCursor(105, 150);
    display.println(temperature);

    // Unit
    display.setFont(&Squared_Display19pt7b);
    char unit = settings.weatherUnit == "metric" ? 'c' : 'f';
    display.setCursor(162, 132);
    display.println(unit);
}

void WatchyHiSpeed::drawStepCounter(){
    // Step Counter
    display.setFont(&Squared_Display19pt7b);
    uint32_t stepCount = sensor.getCounter();
    
    display.setCursor(105, 181);
    display.println(stepCount);
}

void WatchyHiSpeed::drawSeperator(){
  int8_t startX = 23;
  int8_t y = 82;
  int8_t width = 10;
  int8_t margin = 3;
  int8_t height = 18;
  int8_t count = 12;

  for(int8_t i=0; i<count; i++) {
    display.drawRect(startX+(i*(width+margin)), y, width, height, DARKMODE ? GxEPD_WHITE : GxEPD_BLACK);
  }

  // Optional second row. You'll probably need to halve the height and reduce y to position it correctly
  // y += 13;
  // for(int8_t i=0; i<count; i++) {
  //   display.drawRect(startX+(i*12), y, width, height, DARKMODE ? GxEPD_WHITE : GxEPD_BLACK);
  // }

  float batteryLevel = 0;
  float VBAT = getBatteryVoltage();
  if(VBAT > 4.1){
      batteryLevel = 1;
  }
  else if(VBAT > 3.95 && VBAT <= 4.1){
      batteryLevel = 0.66;
  }
  else if(VBAT > 3.80 && VBAT <= 3.95){
      batteryLevel = 0.33;
  }
  else if(VBAT <= 3.80){
      batteryLevel = 0;
  }

  uint8_t battLineWidth = ((width + margin) * count) - margin;
  battLineWidth = battLineWidth * batteryLevel;
  int8_t battY = y + (height/2) - 2;
  display.fillRect(startX, battY, battLineWidth, 4, DARKMODE ? GxEPD_BLACK : GxEPD_WHITE);
  display.drawRect(startX, battY, battLineWidth, 4, DARKMODE ? GxEPD_WHITE : GxEPD_BLACK);
}

void WatchyHiSpeed::drawAngledSeperator(){
  int8_t margin = 3;
  int8_t count = 14;
  int8_t width = 9;

  int8_t initialX = 13;
  int8_t initialY = 85;

  uint16_t color = DARKMODE ? GxEPD_WHITE : GxEPD_BLACK;

  for(int8_t i=0; i<count; i++) {
    drawAngledSeperatorElement(initialX+(i*(width+margin)), initialY, color);
  }

  // drawAngledSeperatorElementEndcap(initialX - 2, initialY, false, color);
  // drawAngledSeperatorElementEndcap(initialX+(count*(width+margin)), initialY, true, color);
}

void WatchyHiSpeed::drawAngledSeperatorElement(uint8_t x, uint8_t y, uint16_t color){
  int8_t width = 9;
  int8_t height = 15;

  uint8_t yTop = y;
  uint8_t yBottom = yTop+height;

  uint8_t bottomStartX = x;
  uint8_t topStartX = bottomStartX+width/2;

  // Horizontal top
  display.drawLine(topStartX, yTop, topStartX+width, yTop, color);
  // Horizotal bottom
  display.drawLine(bottomStartX, yBottom, bottomStartX+width, yBottom, color);
  // Diagonal left
  display.drawLine(bottomStartX, yBottom, topStartX, yTop, color);
  // Diagonal right
  display.drawLine(bottomStartX+width, yBottom, topStartX+width, yTop, color);
}

void WatchyHiSpeed::drawAngledSeperatorElementEndcap(uint8_t x, uint8_t y, bool end, uint16_t color){
  int8_t width = 3;
  int8_t height = 15;

  if(!end){
    display.drawTriangle(x, y, x, y+height, x+width, y, color);
  } else {
    display.drawTriangle(x, y, x, y+height, x-width, y+height, color);
  }
}

void WatchyHiSpeed::drawDate(){
    display.setFont(&SquaredDisplayMonospaced27pt7b);
    display.setCursor(43, 150);  
    display.println(currentTime.Day);

    display.setFont(&SquaredDisplayMonospaced24pt7b);
    String month = monthShortStr(currentTime.Month);
    display.setCursor(24, 177);
    display.println(month);
}

void WatchyHiSpeed::drawWatchFace(){      
    display.fillScreen(DARKMODE ? GxEPD_BLACK : GxEPD_WHITE);
    display.setTextColor(DARKMODE ? GxEPD_WHITE : GxEPD_BLACK);
    
    drawTime();
    drawTemperature();
    drawStepCounter();
    drawDate();

    // Seperator options
    // display.drawFastHLine(21, 92, 157, DARKMODE ? GxEPD_WHITE : GxEPD_BLACK);
    drawSeperator();
    // drawAngledSeperator();
}
