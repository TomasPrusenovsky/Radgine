#pragma once
#include "rpch.h"
#include "Window/WindowTemplate.h"
#include "Scene/Scenes.h"

namespace Rg
{
	class Application
	{
	public:
		Application();
		~Application();

		void Run();
		void PushScene(Scene* scene);

	private:
		Scenes m_Scenes;

		std::unique_ptr<WindowTemplate> m_Window;

	};
}

