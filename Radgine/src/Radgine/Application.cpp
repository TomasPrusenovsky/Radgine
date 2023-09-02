#include "rpch.h"
#include "Application.h"
#include "Window/Window.h"

namespace Rg
{
	Application::Application() :
		m_Window(std::unique_ptr<WindowTemplate>(new Window()))
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		while (m_Window->IsRunning())
		{
			m_Window->OnUpdate();
		}
	}
}