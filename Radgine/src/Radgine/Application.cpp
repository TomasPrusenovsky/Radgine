#include "rpch.h"
#include "Application.h"
#include "Window/Window.h"

namespace Rg
{
	Application::Application() :
		m_Window(std::unique_ptr<WindowTemplate>(new Window())),
		m_Scenes(Scenes())
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
			m_Scenes.UpdateCurrent();
		}
	}

	void Application::PushScene(Scene* scene)
	{

	}
}