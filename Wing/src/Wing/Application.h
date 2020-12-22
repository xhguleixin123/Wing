#pragma once
#include"Core.h"
#include "Wing/Window.h"
#include "Wing/Events/ApplicationEvent.h"
#include "Wing/LayerStack.h"
#include <memory>
namespace Wing {
	class WING_API  Application
	{
	public:
		Application();
		virtual ~Application();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetWindow() { return *m_Window; }
		inline static Application& Get() { return *s_Instance; }

		bool OnWindowClose(WindowCloseEvent& e);

		void Run();
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	private:
		static Application* s_Instance;
	};

	Application* CreateApplication();

}

