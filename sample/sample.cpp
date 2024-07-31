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