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
#ifndef SENECA_PROFESSOR_H
#define SENECA_PROFESSOR_H

#include <iostream>
#include <string>
#include "Employee.h"

namespace seneca
{
    class Professor : public Employee
    {
        std::string m_department{};
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
        Professor(std::istream& is = std::cin);
        void display(std::ostream& os) const;
        std::string status() const;
        std::string department() const;
    };
}
#endif //!SENECA_PROFESSOR_H
