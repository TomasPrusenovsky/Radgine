#pragma once

namespace Rg
{
	class Scene
	{
	public:
		Scene(const char* name) { m_Name = name; }
		virtual ~Scene() = 0;

		virtual void OnUpdate() = 0;
		virtual void OnImGuiUpdate() = 0;

	private:
		const char* m_Name = nullptr;
	};
}