
#pragma once
#ifndef SENECA_EVENT_H
#define SENECA_EVENT_H

namespace seneca 
{
	extern unsigned int g_sysClock;

	class Event 
	{	
		char* desc;		
		unsigned int start_time;

	public:
		Event();
		Event(const Event& other);
		Event& operator=(const Event& r_side);
		void display() const;
		void set(const char* new_desc);
		~Event();
	};
}
#endif