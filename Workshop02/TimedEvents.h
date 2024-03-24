/************************************************************************
*                           Workshop 02
* Name       : Manav Alpeshbhai Zadafiya
* Email      : mazadafiya@myseneca.ca
* Student ID : 144095221
* Date       : 2024-01-25
* Authentication Declaration:
* I have done all the coding by myself and only copied the code that my
* professor provided to complete my workshops and assignments.
************************************************************************/
#ifndef SENECA_TIMEDEVENTS_H
#define SENECA_TIMEDEVENTS_H

#include <iostream>
#include <iomanip>
#include <chrono>

namespace seneca 
{
	class TimedEvents {
        static const int maxEvents = 10;

        int numRecords;
        std::chrono::steady_clock::time_point startTime;
        std::chrono::steady_clock::time_point endTime;

        struct Event {
            std::string eventName{};
            std::string unitsOfTime{};
            std::chrono::steady_clock::duration duration{};
        } events[maxEvents];

    public:
        void startClock();
        void stopClock();
        void addEvent(const char* eventName);

        friend std::ostream& operator<<(std::ostream& os, const TimedEvents& te);

        TimedEvents();
        TimedEvents(TimedEvents&&) = default;
        TimedEvents(const TimedEvents&) = default;
        TimedEvents& operator=(TimedEvents&&) = default;
        TimedEvents& operator=(const TimedEvents&) = default;
        ~TimedEvents() = default;
	};
}
#endif //!SENECA_TIMEDEVENTS_H