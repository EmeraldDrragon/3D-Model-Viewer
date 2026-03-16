#include <iostream>
#include "objParser.h"
#include "convert16.h"
#include "exportc.h"

int main(int argc, char** argv)
{
    if (argc < 3) 
    {
        return 1;
    }

    const char* input = argv[1];
    const char* output = argv[2];
    Mesh mesh = ObjParser::load(input);
    MeshFixed fixed = Converter::toFixed(mesh);

    exportModelC(fixed, output);

    std::cout << "Model in " << output << "\n";
    return 0;
}
