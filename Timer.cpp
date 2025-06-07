#include "Timer.h"
#include "Constants.h"

Timer::Timer() : angle(0.0f) {}

void Timer::update() {
    angle += 1.0f;
    if (angle >= 360.0f) {
        angle -= 360.0f;
    }
}

float Timer::getAngle() const {
    return angle;
}
