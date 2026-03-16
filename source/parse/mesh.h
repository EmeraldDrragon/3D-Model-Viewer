#pragma once
#include <vector>

struct Point
{
    float x, y, z;
};

struct Face
{
    int v1, v2, v3;
};

struct Mesh
{
    std::vector<Point> verts;
    std::vector<Face> faces;
};