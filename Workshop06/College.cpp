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
#include <iostream>
#include <iomanip>
#include "College.h"
#include "Employee.h"
#include "Person.h"

namespace seneca
{
    College& College::operator+=(Person* thePerson)
    {
        m_persons.push_back(thePerson);
        return *this;
    }

    void College::display(std::ostream& os) const
    {
        os << "------------------------------------------------------------------------------------------------------------------------\n";
        os << "|                                        Test #1 Persons in the college!                                               |\n";
        os << "------------------------------------------------------------------------------------------------------------------------\n";
        for(auto it = m_persons.begin(); it != m_persons.end(); ++it) {
            (*it)->display(os);
            std::cout << std::endl;
        }
        os << "------------------------------------------------------------------------------------------------------------------------\n";
        os << "|                                        Test #2 Persons in the college!                                               |\n";
        os << "------------------------------------------------------------------------------------------------------------------------\n";
        for(auto it = m_persons.begin(); it != m_persons.end(); ++it)
            os << "| " << std::setw(10) << (*it)->status() << "| " << std::setw(10) << (*it)->id() << "| " << std::setw(20) << (*it)->name()
            << " | " << std::setw(3) << (*it)->age() << " |\n";
        os << "------------------------------------------------------------------------------------------------------------------------\n";
    }

    College::~College()
    {
        for(auto it = m_persons.begin(); it != m_persons.end(); ++it) {
            delete* it;
        }
    }
}