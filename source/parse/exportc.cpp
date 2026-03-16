#include "exportc.h"
#include <fstream>

void exportModelC(const MeshFixed& mesh, const std::string& outPath)
{
    std::ofstream out(outPath);
    if (!out.is_open())
        return;

    out << "#include \"model.h\"\n\n";

    out << "PointI modelVerts[] = {\n";
    for (const auto& v : mesh.verts)
    {
        out << "    { "
            << v.x << ", "
            << v.y << ", "
            << v.z << " },\n";
    }
    out << "};\n\n";

    out << "Edge modelEdges[] = {\n";
    for (const auto& e : mesh.edges)
    {
        out << "    { "
            << e.a << ", "
            << e.b << " },\n";
    }
    out << "};\n\n";

    out << "uint16_t vertCount = "
        << mesh.verts.size() << ";\n";

    out << "uint16_t edgeCount = "
        << mesh.edges.size() << ";\n";
}
