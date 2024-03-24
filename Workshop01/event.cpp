
#define _CRT_SECURE_NO_WARNINGS
#include "event.h"
#include <string>
#include <cstring>
#include <iostream>
#include <iomanip>

using namespace std;

namespace seneca
{
	unsigned int g_sysClock = 0u;
	static unsigned int display_counter = 0u;

	Event::Event()
	{
		desc = nullptr;
		start_time = 0;
	}

	Event::Event(const Event& other) 
	{	
		start_time = other.start_time;	
		if (other.desc != nullptr) {
			desc = new char[strlen(other.desc) + 1];
			strcpy(desc, other.desc);
		}
		else {
			desc = nullptr;
		}
	}

	Event& Event::operator=(const Event& r_side)
	{
		if (this != &r_side) {
			start_time = r_side.start_time;
			delete[] desc;
			if (r_side.desc != nullptr) {
				desc = new char[strlen(r_side.desc) + 1];
				strcpy(desc, r_side.desc);
			}
			else {
				desc = nullptr;
			}
		}	
		return *this;
	}

	void Event::display() const
	{
		++display_counter;
		
		if (desc == nullptr) {

			if (display_counter > 0 && display_counter < 13) {
				std::cout << " ";
				std::cout << display_counter << ". ";
				std::cout << "| No Event |\n";
			}
			else {
				std::cout << display_counter << ". ";
				std::cout << "| No Event |\n";
			}
		}
		else {
			unsigned int ss = start_time % 60u;
			unsigned int mm = (start_time / 60u) % 60u;
			unsigned int hh = ((start_time / 60u) / 60u) % 24u;
			std::cout.fill('0');
			if (display_counter >= 1 && display_counter <= 9) {
				std::cout << " ";
				std::cout << display_counter << ". ";
				std::cout.width(2);
				std::cout << hh << ":";
				std::cout.width(2);
				std::cout << mm << ":";
				std::cout.width(2);
				std::cout << ss;
				std::cout.fill(' ');
				std::cout << " => " << desc << std::endl;
			}
			else {
				std::cout << display_counter << ". ";
				std::cout.width(2);
				std::cout << hh << ":";
				std::cout.width(2);
				std::cout << mm << ":";
				std::cout.width(2);
				std::cout << ss;
				std::cout.fill(' ');
				std::cout << " => " << desc << std::endl;
			}
		}
	}

	void Event::set(const char* new_desc) {
		if (new_desc != nullptr && new_desc[0] != '\0') {	
			delete[] desc; 
			desc = new char[strlen(new_desc) + 1];
			strcpy(desc, new_desc);
			start_time = g_sysClock;
		}
		else {
			delete[] desc;
			desc = nullptr;
			start_time = 0;
		}
	}

	Event::~Event()
	{
		delete[] desc;
		desc = nullptr;
	}
}
