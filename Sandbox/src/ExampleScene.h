#pragma once
#include "Radgine.h"

class ExampleScene : public Rg::Scene
{
public:
	ExampleScene();
	~ExampleScene();

	void OnUpdate();
	void OnImGuiUpdate();
};

