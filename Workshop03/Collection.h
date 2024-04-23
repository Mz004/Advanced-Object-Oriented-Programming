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

#ifndef SENECA_COLLECTION_H

#include <iostream>
#include <iomanip>
#include "Pair.h"

namespace seneca 
{
    template <typename T, size_t CAPACITY>
    class Collection {
        T m_data[CAPACITY]{};
        static T m_dummy;
        size_t m_count{};
    public:
        Collection();
        virtual ~Collection();
        size_t size() const;
        std::ostream& display(std::ostream& os = std::cout) const;
        virtual bool add(const T& item);
        T operator[](const int index) const;
    };

    template <typename T, size_t CAPACITY>
    T Collection<T, CAPACITY>::m_dummy{};

    template <>
    Pair Collection<Pair, 100>::m_dummy("No Key", "No Value");

    template <typename T, size_t CAPACITY>
    Collection<T, CAPACITY>::Collection() {}

    template <typename T, size_t CAPACITY>
    Collection<T, CAPACITY>::~Collection() {}

    template <typename T, size_t CAPACITY>
    size_t Collection<T, CAPACITY>::size() const { return m_count; }

    template <typename T, size_t CAPACITY>
    std::ostream& Collection<T, CAPACITY>::display(std::ostream& os) const {
        os << "----------------------" << std::endl;
        os << "| Collection Content |" << std::endl;
        os << "----------------------" << std::endl;
        for (auto i = 0ul; i < m_count; ++i)
            os << m_data[i] << std::endl;
        os << "----------------------" << std::endl;
        return os;
    }

    template <typename T, size_t CAPACITY>
    bool Collection<T, CAPACITY>::add(const T& item) {
        bool res{};
        if (m_count < CAPACITY - 1) {
            m_data[m_count++] = item;
            res = true;
        }
        return res;
    }

    template <typename T, size_t CAPACITY>
    T Collection<T, CAPACITY>::operator[](const int index) const {
        T res{};
        if (index < (int)m_count) res = m_data[index];
        else res = m_dummy;
        return res;
    }
}
#endif // !SENECA_COLLECTION_H