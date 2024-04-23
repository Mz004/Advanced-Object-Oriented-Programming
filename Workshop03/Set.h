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
#ifndef SENECA_SET_H
#define SENECA_SET_H

#include <cmath>
#include "Collection.h"

namespace seneca 
{
    template <typename T>
    class Set : public Collection<T, 100> {
    public:
        bool add(const T& item);
    };

    template<typename T>
    bool Set<T>::add(const T& item) {
        bool res{}, found{};
        size_t size = this->size();
        for (auto i = 0ul; i < size && !found; ++i) {
            if ((*this)[i] == item) {
                found = true;
            }
        }
        if (!found) {
            Collection<T, 100>::add(item);
            res = true;
        }
        return res;
    }

    template<>
    bool Set<double>::add(const double& item) {
        bool res{}, found{};
        size_t size = this->size();
        for (auto i = 0ul; i < size && !found; ++i) {
            if (fabs((*this)[i] - item) < 0.01) {
                found = true;
            }
        }
        if (!found) {
            Collection<double, 100>::add(item);
            res = true;
        }
        return res;
    }
}
#endif // !SENECA_SET_H
