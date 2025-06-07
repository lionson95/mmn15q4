# Rotating Convex Polyhedron Animation

This program demonstrates a rotating cube rendered with OpenGL using GLUT. Press `p` to switch to perspective projection and `o` to return to orthographic.

## Build Instructions

1. Install OpenGL and GLUT development libraries. On Debian/Ubuntu based systems:
   ```sh
   sudo apt-get install build-essential freeglut3-dev
   ```
2. Create a build directory and compile using CMake:
   ```sh
   mkdir build && cd build
   cmake .. && make
   ```
3. Run the executable:
   ```sh
   ./mmn15q4
   ```

The program requires an X11 display; running in a headless environment will fail to open a window.
