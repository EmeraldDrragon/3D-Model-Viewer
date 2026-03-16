#pragma once
#include <string>
#include "mesh.h"

class ObjParser
{
public:
    static Mesh load(const std::string& path);
};