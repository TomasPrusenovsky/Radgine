#include "Radgine.h"
#include "ExampleScene.h"

class SandboxApp : public Rg::Application
{
public:
	SandboxApp()
	{
		PushScene(new ExampleScene());
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