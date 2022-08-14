#ifndef WATCHY_HI_SPEED_H
#define WATCHY_HI_SPEED_H
#include <Watchy.h>

#include "SquaredDisplayMonospaced40pt7b.h"
#include "SquaredDisplayMonospaced27pt7b.h"
#include "SquaredDisplayMonospaced24pt7b.h"
#include "Squared_Display19pt7b.h"

class WatchyHiSpeed : public Watchy{
    using Watchy::Watchy;
    public:
        void drawWatchFace();
        void drawTime();
        void drawTemperature();
        void drawStepCounter();
        void drawDate();
        void drawSeperator();
        void drawAngledSeperator();
        void drawAngledSeperatorElement(uint8_t x, uint8_t y, uint16_t color);
        void drawAngledSeperatorElementEndcap(uint8_t x, uint8_t y, bool end, uint16_t color);
};

#endif
