#pragma once
#include "wpch.h"
#include "Wing/Core.h"
#include "Wing/Events/Event.h"

namespace Wing
{
	struct WindowProps
	{
		std::string Ttile;
		unsigned int Width;
		unsigned int Height;
		WindowProps(const std::string& title = "Wing Engine", unsigned int width = 1280, unsigned int height = 720)
			: Ttile(title), Width(width), Height(height){}
	};

	class Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(WindowProps& props = WindowProps());
	};
}