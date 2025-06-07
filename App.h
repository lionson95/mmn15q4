#ifndef APP_H
#define APP_H

#include "Camera.h"
#include "Polyhedron.h"
#include "Timer.h"

class App {
public:
    App(int& argc, char** argv);
    void run();

private:
    static void displayCallback();
    static void reshapeCallback(int width, int height);
    static void keyboardCallback(unsigned char key, int x, int y);
    static void timerCallback(int value);

    static Camera camera;
    static Polyhedron polyhedron;
    static Timer timer;
};

#endif // APP_H
