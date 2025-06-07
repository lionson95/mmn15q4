#include "App.h"
#include "Constants.h"
#include <GL/glut.h>

Camera App::camera;
Polyhedron App::polyhedron;
Timer App::timer;

App::App(int& argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutCreateWindow("Rotating Polyhedron");

    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(App::displayCallback);
    glutReshapeFunc(App::reshapeCallback);
    glutKeyboardFunc(App::keyboardCallback);
    glutTimerFunc(TIMER_INTERVAL, App::timerCallback, 0);
}

void App::run() {
    glutMainLoop();
}

void App::displayCallback() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    camera.applyProjection(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    polyhedron.draw();

    glutSwapBuffers();
}

void App::reshapeCallback(int width, int height) {
    glViewport(0, 0, width, height);
}

void App::keyboardCallback(unsigned char key, int, int) {
    switch (key) {
    case 'p':
    case 'P':
        camera.setPerspective();
        break;
    case 'o':
    case 'O':
        camera.setOrthographic();
        break;
    case 27: // ESC
        std::exit(0);
    default:
        break;
    }
    glutPostRedisplay();
}

void App::timerCallback(int) {
    timer.update();
    polyhedron.setRotation(timer.getAngle());
    glutPostRedisplay();
    glutTimerFunc(TIMER_INTERVAL, App::timerCallback, 0);
}
