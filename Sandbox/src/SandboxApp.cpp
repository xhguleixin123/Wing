#include"Wing.h"

class Sandbox : public Wing::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Wing::Application* Wing::CreateApplication()
{
	return new Sandbox();
}