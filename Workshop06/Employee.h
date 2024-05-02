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
#ifndef SENECA_EMPLOYEE_H
#define SENECA_EMPLOYEE_H

#include <iostream>
#include "Person.h"

namespace seneca
{
    class Employee : public Person
    {
        std::string m_name{};
        std::string m_age{};
        std::string m_id{};
        static std::string trim(const std::string& str,
            const std::string& whitespace)
        {
            const auto strBegin = str.find_first_not_of(whitespace);
            if(strBegin == std::string::npos)
                return "";
            const auto strEnd = str.find_last_not_of(whitespace);
            const auto strRange = strEnd - strBegin + 1;
            return str.substr(strBegin, strRange);
        }
    public:
        Employee(std::istream& is = std::cin);
        std::string status() const;
        std::string name() const;
        std::string id() const;
        std::string age() const;
        void display(std::ostream& os) const;
    };
}
#endif //!SENECA_EMPLOYEE_H