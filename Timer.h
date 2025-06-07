#ifndef TIMER_H
#define TIMER_H

class Timer {
public:
    Timer();
    void update();
    float getAngle() const;

private:
    float angle;
};

#endif // TIMER_H
