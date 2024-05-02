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
#include "Employee.h"
#include "Student.h"
#include "Professor.h"
#include "Utilities.h"
#include "Person.h"

namespace seneca
{
    Person* buildInstance(std::istream& in)
    {
        char ch{};
        Person* p{};
        in >> ch;
        in.ignore();
        if(ch == 'e' || ch == 'E')
            p = new Employee(in);
        else if(ch == 's' || ch == 'S')
            p = new Student(in);
        else if(ch == 'p' || ch == 'P')
            p = new Professor(in);
        return p;
    }
}