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
#include "TimedEvents.h"

using namespace std;

namespace seneca 
{
    void TimedEvents::startClock() 
    {
        startTime = std::chrono::steady_clock::now();
    }

    void TimedEvents::stopClock() 
    {
        endTime = std::chrono::steady_clock::now();
    }

    void TimedEvents::addEvent(const char* eventName) 
    {
        if (numRecords < maxEvents) {
            if (eventName) {
                events[numRecords].eventName = eventName;
                events[numRecords].unitsOfTime = "nanoseconds";
                events[numRecords].duration = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
                numRecords++;
            }
        }
    }

    std::ostream& operator<<(std::ostream& os, const TimedEvents& te) 
    {
        os << "--------------------------" << endl;
        os << "Execution Times:" << endl;
        os << "--------------------------" << endl;

        for (int i = 0; i < te.numRecords; i++) {
            os << left << setw(21) << te.events[i].eventName
                << right << setw(13) << te.events[i].duration.count()
                << " " << te.events[i].unitsOfTime << endl;
        }

        os << "--------------------------" << endl;
        return os;
    }

    TimedEvents::TimedEvents() : numRecords(0) {}
}