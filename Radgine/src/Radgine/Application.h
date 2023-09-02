#pragma once
#include "rpch.h"
#include "Window/WindowTemplate.h"

namespace Rg
{
	class Application
	{
	public:
		Application();
		~Application();

		void Run();

	private:
		std::unique_ptr<WindowTemplate> m_Window;

	};
}

