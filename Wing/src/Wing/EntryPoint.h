#pragma once
#include"Application.h"

#ifdef W_PLATFORM_WINDOWS

Wing::Application* Wing::CreateApplication();

int main()
{
	Wing::Application* app = Wing::CreateApplication();
	app->Run();
	delete app;
}

#else
#error Wing only supports Winows
#endif // W_PLATFORM_WINDOWS