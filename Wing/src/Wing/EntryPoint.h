#pragma once
#ifdef W_PLATFORM_WINDOWS

Wing::Application* Wing::CreateApplication();

int main()
{
	Wing::Log::Init();
	W_ERROR("TEST!");
	Wing::Application* app = Wing::CreateApplication();
	app->Run();
	delete app;
}

#else
#error Wing only supports Windows
#endif // W_PLATFORM_WINDOWS