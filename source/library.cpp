#include "imgui.h"

namespace ImGuiSample
{
	void update_sample_window(bool* is_open);
}

namespace ImGui
{
	void ShowDemoWindow(bool* is_open)
	{
		bool is_hidden = false;
		::ImGuiSample::update_sample_window(&is_hidden);

		// Hide example window
		ImVec2 position{ 10000, 10000 };
		ImGui::SetNextWindowPos(position);
	}
}
