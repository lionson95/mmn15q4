#include "Camera.h"
#include <GL/glut.h>

Camera::Camera() : mode(ORTHOGRAPHIC) {}

void Camera::applyProjection(int width, int height) const {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    double aspect = static_cast<double>(width) / static_cast<double>(height);
    if (mode == ORTHOGRAPHIC) {
        double size = 2.0;
        if (aspect >= 1.0) {
            glOrtho(-size * aspect, size * aspect, -size, size, -10.0, 10.0);
        } else {
            glOrtho(-size, size, -size / aspect, size / aspect, -10.0, 10.0);
        }
    } else {
        gluPerspective(60.0, aspect, 1.0, 20.0);
        glTranslatef(0.0f, 0.0f, -5.0f);
    }
}

void Camera::setPerspective() {
    mode = PERSPECTIVE;
}

void Camera::setOrthographic() {
    mode = ORTHOGRAPHIC;
}
