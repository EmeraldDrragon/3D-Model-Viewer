#include "convert16.h"
#include <algorithm>
#include <fstream>

void Converter::addEdge(std::vector<Edge>& edges, uint16_t a, uint16_t b)
{
    if (a > b)
    {
        std::swap(a, b);
    }

    for (const auto& e : edges)
    {
        if (e.a == a && e.b == b)
        {
            return;
        }
    }
    edges.push_back({a, b});
}

std::vector<Edge> Converter::buildEdges(const std::vector<Face>& faces)
{
    std::vector<Edge> edges;

    for (const Face& f : faces)
    {
        addEdge(edges, (uint16_t)f.v1, (uint16_t)f.v2);
        addEdge(edges, (uint16_t)f.v2, (uint16_t)f.v3);
        addEdge(edges, (uint16_t)f.v3, (uint16_t)f.v1);
    }

    return edges;
}

MeshFixed Converter::toFixed(const Mesh& m)
{
    MeshFixed out;
    float minx = 1e9f, maxx = -1e9f;
    float miny = 1e9f, maxy = -1e9f;
    float minz = 1e9f, maxz = -1e9f;

    for (auto& v : m.verts)
    {
        minx = std::min(minx, v.x);
        maxx = std::max(maxx, v.x);
        miny = std::min(miny, v.y);
        maxy = std::max(maxy, v.y);
        minz = std::min(minz, v.z);
        maxz = std::max(maxz, v.z);
    }

    float cx = (minx + maxx) * 0.5f;
    float cy = (miny + maxy) * 0.5f;
    float cz = (minz + maxz) * 0.5f;

    float size = std::max({ maxx - minx, maxy - miny, maxz - minz });
    float scale = 1000.0f / size;

    for (const auto& v : m.verts)
    {
        PointI vi;
        vi.x = (int16_t)((v.x - cx) * scale);
        vi.y = (int16_t)((v.y - cy) * scale);
        vi.z = (int16_t)((v.z - cz) * scale);

        out.verts.push_back(vi);
    }

    out.edges = buildEdges(m.faces);
    return out;
}