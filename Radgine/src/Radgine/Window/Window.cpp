#include "rpch.h"
#include "Window.h"

namespace Rg
{
	static bool s_GLFWInitialized = false;

	Window::Window()
	{
		Init();
	}

	Window::Window(int width, int height, const char* title) :
		WindowTemplate(width, height, title)
	{
		Init();
	}

	Window::~Window()
	{
		glfwDestroyWindow(m_Window);
		glfwTerminate();
		s_GLFWInitialized = false;
	}

	void Window::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void Window::Init()
	{
		if (!s_GLFWInitialized)
		{
			glfwInit();
			s_GLFWInitialized = true;
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		// Only use this if you don't have a framebuffer
		glfwWindowHint(GLFW_SAMPLES, 8);
		// Tell GLFW we are using the CORE profile
		// So that means we only have the modern functions
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


		m_Window = glfwCreateWindow(m_Data.width, m_Data.height, m_Data.title, NULL, NULL);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(false);

		// GLFW callbacks
		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
								   {
									   WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
									   data.shouldRun = false;
								   });

		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
								  {
									  WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
									  data.height = height;
									  data.width = width;

									  if (width < 1 && height < 1)
										  data.isMinimized = true;
									  else
										  data.isMinimized = false;
								  });
	}

	void Window::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_Data.VSync = enabled;
	}

	bool Window::IsVSync()
	{
		return m_Data.VSync;
	}
}