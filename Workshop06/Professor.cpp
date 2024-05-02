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
#include <string>
#include "Professor.h"
#include "Employee.h"

namespace seneca
{
    Professor::Professor(std::istream& is) : Employee(is)
    {
        std::string dept{};
        getline(is, dept, '\n');
        m_department = trim(dept, " ");
    }

    void Professor::display(std::ostream& os) const
    {
        Employee::display(os);
        os << m_department << "| Professor";
    }

    std::string Professor::status() const
    {
        return "Professor";
    }

    std::string Professor::department() const
    {
        return m_department;
    }
}