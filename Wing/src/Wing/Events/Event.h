#pragma once
#include "Wing/Core.h"
#include <string>
#include <ostream>
namespace Wing
{
	enum class EventType
	{
		None = 0,
		WindowResize, WindowClose
	};

	enum EventCategory
	{
		None = 0,
		EventCategoryApplication = BIT(0),
	};

#define EVENT_CLASS_TYPE(type)	static EventType GetStaticType(){ return EventType::##type;}\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	class WING_API Event
	{
		friend class EventDispatcher;
	public:
		bool Handled = false;
		virtual  EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;

		virtual std::string ToString() const { return GetName(); }
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}

	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event)
			: m_Event(event)
		{
		}

		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.Handled = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}

	private:
		Event& m_Event;
	};

}
