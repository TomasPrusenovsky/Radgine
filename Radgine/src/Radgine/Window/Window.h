#pragma once

#include "WindowTemplate.h"
#include "GLFW/glfw3.h"

namespace Rg
{
	class Window : public WindowTemplate
	{
	public:
		Window();
		Window(int width, int height, const char* title);
		~Window() override;

		void OnUpdate() override;

		void SetVSync(bool enabled);
		bool IsVSync();
		void* GetWinPtr() override { return m_Window; }

	private:
		void Init() override;
		GLFWwindow* m_Window = nullptr;
		bool m_ShouldRun = true;
	};
}
