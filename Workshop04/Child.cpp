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
#include "Child.h"
#include "Toy.h"

using namespace std;

namespace seneca
{
    Child::Child(const Child& C) { *this = C; }
    Child& Child::operator=(const Child& C)
    {
        if(this != &C) {
            for(auto i = 0ul; i < numToys; ++i)
                delete toys[i];
            delete[] toys;
            name = C.name;
            age = C.age;
            numToys = C.numToys;
            toys = new const Toy * [numToys];
            for(auto i = 0ul; i < numToys; ++i)
                toys[i] = new Toy(*C.toys[i]);
        }
        return *this;
    }

    Child::Child(Child&& C) noexcept { *this = move(C); }
    Child& Child::operator=(Child&& C) noexcept
    {
        if(this != &C) {
            for(auto i = 0ul; i < numToys; ++i)
                delete toys[i];
            delete[] toys;
            name = C.name;
            age = C.age;
            numToys = C.numToys;
            toys = C.toys;
            C.toys = nullptr;
            C.numToys = 0;
            C.age = 0;
            C.name = "";
        }
        return *this;
    }
    Child::~Child()
    {
        for(auto i = 0ul; i < numToys; ++i)
            delete toys[i];
        delete[] toys;
    }

    Child::Child(std::string name, int age, const Toy* toys[], size_t count)
    {
        name = name;
        age = age;
        numToys = count;
        toys = new const Toy * [count];
        for(auto i = 0ul; i < count; ++i)
            toys[i] = new Toy(*toys[i]);
    }


    size_t Child::size() const
    {
        return numToys;
    }

    std::ostream& Child::display(std::ostream& os) const
    {
        static int count = 0;
        ++count;
        os << "--------------------------" << endl;
        os << "Child " << count << ": " << name << " " << age << " years old:" << endl;
        os << "--------------------------" << endl;
        if(toys != nullptr) {
            for(auto i = 0ul; i < numToys; ++i)
                os << *toys[i];
        }
        else {
            os << "This child has no toys!" << endl;
        }
        os << "--------------------------" << endl;

        return os;
    }
    std::ostream& operator<<(std::ostream& os, const Child& C)
    {
        return C.display(os);
    }
}
