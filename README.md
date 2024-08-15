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
