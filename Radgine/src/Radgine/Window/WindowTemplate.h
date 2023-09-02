#pragma once

namespace Rg
{
	class WindowTemplate
	{
	public:
		WindowTemplate(int width = 900, int height = 900, const char* title = "Engine") :
			m_Data({ width, height, title })
		{
		}
		virtual ~WindowTemplate() {};
		virtual void OnUpdate() = 0;

		virtual void* GetWinPtr() = 0;

		inline bool IsRunning() { return m_Data.shouldRun; }
		inline bool IsMinimized() { return m_Data.isMinimized; }
		inline int GetWidth() { return m_Data.width; };
		inline int GetHeight() { return m_Data.height; };

	protected:
		virtual void Init() = 0;

		struct WindowData
		{
			int width;
			int height;
			const char* title;
			bool VSync = true;
			bool shouldRun = true;
			bool isMinimized = false;
		};

		WindowData m_Data;
	};
}