/************************************************************************
*                              Workshop 06
* Name       : Manav Alpeshbhai Zadafiya
* Email      : mazadafiya@myseneca.ca
* Student ID : 144095221
* Date       : 2024-03-09
* Authentication Declaration:
* I declare that this submission is the result of my own work and I only
* copied the code that my professor provided to complete my workshops and
* assignments. This submitted piece of work has not been shared with any
* other student or 3rd party content provider.
************************************************************************/
#ifndef SENECA_COLLEGE_H
#define SENECA_COLLEGE_H

#include <iostream>
#include <vector>
#include <list>
#include "Person.h"

namespace seneca
{
    class College
    {
        std::vector<Person*> m_persons{};
    public:
        College() = default;
        College(const College&) = delete;
        College& operator=(const College&) = delete;
        College(College&&) = delete;

        College& operator=(College&&) = delete;
        College& operator+=(Person* thePerson);
        void display(std::ostream& os) const;
        virtual ~College();

        template <typename T>
        void select(const T& test, std::list<const Person*>& persons);
    };

    template<typename T>
    void College::select(const T& test, std::list<const Person*>& persons)
    {
        for(auto it = m_persons.begin(); it != m_persons.end(); ++it)
            if(test(*it))
                persons.push_back(*it);
    }
}
#endif //!SENECA_COLLEGE_H
