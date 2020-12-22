#include"Wing.h"

class ExampleLayer : public Wing::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{}

	void OnUpdate() override
	{
		W_INFO("ExampleLayer :: Update");
	}

	void OnEvent(Wing::Event& event) override
	{
		W_TRACE("{0}", event);
	}
};

class Sandbox : public Wing::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Wing::ImGuiLayer());
	}

	~Sandbox()
	{

	}
};

Wing::Application* Wing::CreateApplication()
{
	return new Sandbox();
}