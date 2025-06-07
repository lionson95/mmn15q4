#ifndef CAMERA_H
#define CAMERA_H

class Camera {
public:
    enum Mode { ORTHOGRAPHIC, PERSPECTIVE };

    Camera();
    void applyProjection(int width, int height) const;
    void setPerspective();
    void setOrthographic();

private:
    Mode mode;
};

#endif // CAMERA_H
