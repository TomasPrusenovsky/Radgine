#include "rpch.h"
#include "Application.h"
#include "Window/Window.h"

#include "glad/glad.h"

namespace Rg
{
	Application::Application() :
		m_Window(std::unique_ptr<WindowTemplate>(new Window())),
		m_Scenes(Scenes())
	{
		gladLoadGL();
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
		m_Scenes.PushScene(scene);
		m_Scenes.SetCurrentScene(0);
	}
}