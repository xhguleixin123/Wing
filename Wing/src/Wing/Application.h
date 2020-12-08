#pragma once
#include"Core.h"
#include "Wing/Window.h"
#include "Wing/Events/ApplicationEvent.h"
#include <memory>
namespace Wing {
	class WING_API  Application
	{
	public:
		Application();
		virtual ~Application();

		void OnEvent(Event& e);

		bool OnWindowClose(WindowCloseEvent& e);

		void Run();
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	Application* CreateApplication();

}

