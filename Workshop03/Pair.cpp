/************************************************************************
*                           Workshop 03
* Name       : Manav Alpeshbhai Zadafiya
* Email      : mazadafiya@myseneca.ca
* Student ID : 144095221
* Date       : 2024-02-03
* Authentication Declaration:
* I have done all the coding by myself and only copied the code that my
* professor provided to complete my workshops and assignments.
************************************************************************/
#include <iostream>
#include <iomanip>
#include "Pair.h"

using namespace std;

namespace seneca 
{
    Pair::Pair() {}

    bool Pair::operator==(const Pair& P) {
        return this->getKey() == P.m_key;
    }

    std::ostream& Pair::display(std::ostream& os) const {
        os << right << setw(20) << m_key << ": " << left << m_value;
        return os;
    }

    std::ostream& operator<<(std::ostream& os, const Pair& P) {
        return P.display(os);
    }
}