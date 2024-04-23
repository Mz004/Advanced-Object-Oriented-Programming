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
#ifndef SENECA_CONFIRMORDER_H
#define SENECA_CONFIRMORDER_H

#include <iostream>
#include "Toy.h"

namespace seneca
{
    class ConfirmOrder
    {
        const Toy** toys{};
        size_t numToys{ 0 };
    public:
        ConfirmOrder();
        ConfirmOrder(const ConfirmOrder& C);
        ConfirmOrder& operator=(const ConfirmOrder& C);
        ConfirmOrder(ConfirmOrder&& C) noexcept;
        ConfirmOrder& operator=(ConfirmOrder&& C) noexcept;
        ~ConfirmOrder();
        ConfirmOrder& operator+=(const Toy& toy);
        ConfirmOrder& operator-=(const Toy& toy);
        std::ostream& display(std::ostream& os = std::cout) const;
    };
    std::ostream& operator<<(std::ostream& os, const ConfirmOrder& C);
}

#endif // !SENECA_CONFIRMORDER_H