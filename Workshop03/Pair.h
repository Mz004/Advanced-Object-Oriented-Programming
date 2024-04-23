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
#ifndef SENECA_PAIR_H
#define SENECA_PAIR_H

#include <string>

namespace seneca 
{
    class Pair 
    {
        std::string m_key{};
        std::string m_value{};
    public:
        const std::string& getKey() { return m_key; }
        const std::string& getValue() { return m_value; }
        Pair(const std::string& key, const std::string& value) : m_key{ key }, m_value{ value } {};

        //TO DO:
        Pair();
        bool operator==(const Pair& P);
        std::ostream& display(std::ostream& os) const;
    };

    std::ostream& operator<<(std::ostream& os, const Pair& P);
}
#endif // !SENECA_PAIR_H