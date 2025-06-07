#ifndef POLYHEDRON_H
#define POLYHEDRON_H

#include <array>
#include <vector>

class Polyhedron {
public:
    Polyhedron();
    void draw() const;
    void setRotation(float angle);

private:
    float rotation;
    std::vector<std::array<float, 3>> vertices;
    std::vector<std::array<int, 4>> faces;
};

#endif // POLYHEDRON_H
