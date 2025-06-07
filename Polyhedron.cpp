#include "Polyhedron.h"
#include <GL/glut.h>

Polyhedron::Polyhedron() : rotation(0.0f) {
    // define cube vertices
    vertices = {
        {-1.0f, -1.0f,  1.0f},
        { 1.0f, -1.0f,  1.0f},
        { 1.0f,  1.0f,  1.0f},
        {-1.0f,  1.0f,  1.0f},
        {-1.0f, -1.0f, -1.0f},
        { 1.0f, -1.0f, -1.0f},
        { 1.0f,  1.0f, -1.0f},
        {-1.0f,  1.0f, -1.0f}
    };

    faces = {
        {0, 1, 2, 3}, // front
        {1, 5, 6, 2}, // right
        {5, 4, 7, 6}, // back
        {4, 0, 3, 7}, // left
        {3, 2, 6, 7}, // top
        {4, 5, 1, 0}  // bottom
    };
}

void Polyhedron::setRotation(float angle) {
    rotation = angle;
}

void Polyhedron::draw() const {
    static const float colors[6][3] = {
        {1.0f, 0.0f, 0.0f},
        {0.0f, 1.0f, 0.0f},
        {0.0f, 0.0f, 1.0f},
        {1.0f, 1.0f, 0.0f},
        {1.0f, 0.0f, 1.0f},
        {0.0f, 1.0f, 1.0f}
    };

    glPushMatrix();
    glRotatef(rotation, 0.0f, 1.0f, 0.0f);

    for (size_t i = 0; i < faces.size(); ++i) {
        glColor3fv(colors[i % 6]);
        glBegin(GL_QUADS);
        for (int index : faces[i]) {
            glVertex3fv(vertices[index].data());
        }
        glEnd();
    }

    glPopMatrix();
}
