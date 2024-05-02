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
#ifndef SENECA_UTILITIES_H
#define SENECA_UTILITIES_H

#include <iostream>
#include "Person.h"

namespace seneca
{
    Person* buildInstance(std::istream& in);
}
#endif //!SENECA_UTILITIES_H