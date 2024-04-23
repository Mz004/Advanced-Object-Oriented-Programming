/************************************************************************
*                       Workshop 04 
* Name       : Manav Alpeshbhai Zadafiya
* Email      : mazadafiya@myseneca.ca
* Student ID : 144095221
* Date       : 2024-02-11
* Authentication Declaration:
* I have done all the coding by myself and only copied the code that my
* professor provided to complete my workshops and assignments.
************************************************************************/
#include <iostream>
#include "ConfirmOrder.h"
#include "Toy.h"

using namespace std;

namespace seneca
{
    ConfirmOrder::ConfirmOrder() {}

    ConfirmOrder::~ConfirmOrder() { delete[] toys; }

    ConfirmOrder::ConfirmOrder(const ConfirmOrder& C)
    {
        *this = C;
    }

    ConfirmOrder& ConfirmOrder::operator=(const ConfirmOrder& C)
    {
        if(this != &C) {
            delete[] toys;
            numToys = C.numToys;
            toys = new const Toy * [numToys];
            for(auto i = 0ul; i < numToys; ++i)
                toys[i] = C.toys[i];
        }
        return *this;
    }

    ConfirmOrder::ConfirmOrder(ConfirmOrder&& C) noexcept
    {
        *this = move(C);
    }

    ConfirmOrder& ConfirmOrder::operator=(ConfirmOrder&& C) noexcept
    {
        if(this != &C) {
            delete[] toys;
            numToys = C.numToys;
            toys = C.toys;
            C.toys = nullptr;
            C.numToys = 0;
        }
        return *this;
    }

    ConfirmOrder& ConfirmOrder::operator+=(const Toy& toy)
    {
        bool found{};
        size_t spot{ 0 };
        for(auto i = 0ul; i < numToys && !found; ++i) {
            if(toys[i] == &toy) found = true;
        }
        if(!found) {
            for(auto i = 0ul; i < numToys && !spot; ++i) {
                if(toys[i] == nullptr) spot = i;
            }
            if(spot)
                toys[spot] = &toy;
            else {
                const Toy** temp{};
                temp = new const Toy * [numToys + 1];
                for(auto i = 0ul; i < numToys; ++i)
                    temp[i] = toys[i];
                temp[numToys++] = &toy;
                delete[] toys;
                toys = temp;
            }
        }
        return *this;
    }

    ConfirmOrder& ConfirmOrder::operator-=(const Toy& toy)
    {
        for(auto i = 0ul; i < numToys; ++i)
            if(toys[i] == &toy) toys[i] = nullptr;
        return *this;
    }

    std::ostream& ConfirmOrder::display(std::ostream& os) const
    {
        os << "--------------------------" << endl;
        os << "Confirmations to Send" << endl;
        os << "--------------------------" << endl;
        if(toys != nullptr) {
            for(auto i = 0ul; i < numToys && toys[i]; ++i)
                os << *toys[i];
        }
        else {
            os << "There are no confirmations to send!" << endl;
        }
        os << "--------------------------" << endl;

        return os;
    }

    std::ostream& operator<<(std::ostream& os, const ConfirmOrder& C)
    {
        return C.display(os);
    }
}