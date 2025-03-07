#include "render/renderer.h"

#include "asset/cube.h"

using namespace TempRenderer;

int main() {
    auto cube = createCube();
    Renderer renderer{800, 600};

    return 0;
}
