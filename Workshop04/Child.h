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
#ifndef SENECA_CHILD_H
#define SENECA_CHILD_H

#include <iostream>
#include <string>
#include "Toy.h"

namespace seneca
{
    class Child
    {
        std::string name{};
        int age{};
        const Toy** toys{};
        size_t numToys{};
    public:
        Child() {}
        Child(std::string name, int age, const Toy* toys[], size_t count);
        Child(const Child& C);
        Child& operator=(const Child& C);
        Child(Child&& C) noexcept;
        Child& operator=(Child&& C) noexcept;
        ~Child();
        size_t size() const;
        std::ostream& display(std::ostream& os = std::cout) const;
    };
    std::ostream& operator<<(std::ostream& os, const Child& C);
}
#endif // !SENECA_CHILD_H