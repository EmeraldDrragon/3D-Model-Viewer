#pragma once
#include "mesh.h"
#include <vector>
#include <cstdint>
#include <string>
#include "../model/model.h"

struct MeshFixed
{
    std::vector<PointI> verts;
    std::vector<Edge> edges;
};

class Converter
{
public:
    static void addEdge(std::vector<Edge>& edges, uint16_t a, uint16_t b);
    static std::vector<Edge> buildEdges(const std::vector<Face>& faces);
    static MeshFixed toFixed(const Mesh& m);
    //static void exportBin(const MeshFixed& m, const std::string& path);
};