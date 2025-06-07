cmake_minimum_required(VERSION 3.21)
project(mmn15q4)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

add_executable(mmn15q4
    main.cpp
    App.cpp
    Camera.cpp
    Polyhedron.cpp
    Timer.cpp
)

target_include_directories(mmn15q4 PRIVATE ${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})
target_link_libraries(mmn15q4 PRIVATE ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})
