#include "Radgine.h"

class SandboxApp : public Rg::Application
{
public:
	SandboxApp()
	{

	}

	~SandboxApp()
	{

	}
};


int main()
{
	auto app = new SandboxApp();
	app->Run();
	delete app;
}