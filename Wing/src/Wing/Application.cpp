#include "wpch.h"
#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace Wing {
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		W_TRACE(e);
		while (true)
		{

		}
	}


}
