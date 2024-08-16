# imgui-sample
A simple package to automate sample creation for custom imgui widgets with CMake build system.

# Example Usage

Create a new executable target and link `fox::imgui_sample` to it. Provide special `update_sample_window` function where you draw your sample. Check [sample](/sample) folder for more.

```cpp
#include <imgui.h>

namespace ImGuiSample
{
	void update_sample_window([[maybe_unused]] bool* is_open)
	{
        	ImGui::Begin("ImGui-Sample Sample");
        	ImGui::Text("Check out sample/sample.cpp!");
        	ImGui::End();
	}
}
```

```cmake
include(FetchContent)

FetchContent_Declare(
    imgui-sample
    GIT_REPOSITORY https://github.com/RedSkittleFox/imgui-sample.git
    GIT_TAG main
)

FetchContent_MakeAvailable(imgui-sample)

add_executable(
    my_sample
)

target_link_libraries(
    my_sample
    my_imgui_library
    fox::imgui_sample
)
```

# Github Pages Deployment

This repository provides an action to automatically build and deploy ImGui Sample with Emscripten and deploy it to github pages. You can check a simple demo [here](https://redskittlefox.github.io/imgui-sample/).

You can create a custom workflow for your repository by creating a following yaml file in the `.github/workflows/imgui_demo.yml` directory of your repository.
```yml
name: Build and Deploy ImGui Sample

on:
  push:
    branches: [ "main" ]

permissions:
  id-token: write
  pages: write

jobs:
  build:
    runs-on: ubuntu-latest

    steps:
    - uses: actions/checkout@v3

    - uses: redskittlefox/imgui-sample@main
      with:
        cmake-target: imgui_sample_sample  # Name of the imgui sample target
```

Make sure to also enable github pages in your repository's settings.
![image](https://github.com/user-attachments/assets/2d198092-54ea-4539-994b-63ef9f772507)
