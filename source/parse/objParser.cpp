#include "objParser.h"

#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "objParser.h"
#include <fstream>
#include <sstream>
#include <iostream>

Mesh ObjParser::load(const std::string& path)
{
    Mesh mesh;
    std::ifstream file(path);
    std::string line;

    if (!file.is_open())
    {
        std::cout << "File failed";
        return mesh;
    }

    while (std::getline(file, line))
    {
        if (line.empty() || line[0] == '#')
        {
            continue;
        }

        std::stringstream ss(line);
        std::string type;
        ss >> type;

        if (type == "v")
        {
            Point p;
            ss >> p.x >> p.y >> p.z;
            mesh.verts.push_back(p);
        }
        else if (type == "f")
        {
            Face f{};
            std::string a, b, c;

            ss >> a >> b >> c;

            auto idx = [](const std::string& s)
            {
                return std::stoi(s.substr(0, s.find('/'))) - 1;
            };

            f.v1 = idx(a);
            f.v2 = idx(b);
            f.v3 = idx(c);

            mesh.faces.push_back(f);
        }
    }

    return mesh;
}

