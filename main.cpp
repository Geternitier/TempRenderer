#include "util/application.h"

using namespace TempRenderer;

int main() {
    Application::Init();

    while (true) {
        Application::Update();
    }
}
