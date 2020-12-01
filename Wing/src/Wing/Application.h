#pragma once
#include"Core.h"
namespace Wing {
	class WING_API  Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();

}

