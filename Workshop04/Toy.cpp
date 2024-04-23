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
#include <iomanip>
#include <string>
#include "Toy.h"

using namespace std;

namespace seneca
{
    std::string Toy::trim(const std::string& str, const std::string& ws)
    {
        const auto strBegin = str.find_first_not_of(ws);
        if(strBegin == std::string::npos) 
            return "";
        const auto strEnd = str.find_last_not_of(ws);
        const auto strRange = strEnd - strBegin + 1;
        return str.substr(strBegin, strRange);
    }

    std::string Toy::reduce(const std::string& str, const std::string& fill, const std::string& ws)
    {
        auto result = trim(str, ws);
        auto beginSpace = result.find_first_of(ws);
        while(beginSpace != std::string::npos) {
            const auto endSpace = result.find_first_not_of(ws, beginSpace);
            const auto range = endSpace - beginSpace;
            result.replace(beginSpace, range, fill);
            const auto newStart = beginSpace + fill.length();
            beginSpace = result.find_first_of(ws, newStart);
        }
        return result;
    }

    void Toy::setPos(std::string::size_type& end, const char* ch, string& str)
    {
        str.erase(0, end + 1);
        end = str.find(ch);
    }

    Toy::Toy() {}

    void Toy::update(int numToys)
    {
        noOfItems = numToys;
    }

    Toy::Toy(const std::string& T)
    {

        string temp = reduce(T, " ", " ");
        string::size_type end = temp.find(":");
        orderID = stoi(temp.substr(0, end));
        setPos(end, ":", temp);
        toyName = trim(temp.substr(0, end), " ");
        setPos(end, ":", temp);
        noOfItems = stoi(temp.substr(0, end));
        setPos(end, "\0", temp);
        price = stof(temp.substr(0, end - 1));
    }

    std::ostream& Toy::display(std::ostream& os) const
    {
        os.setf(ios::fixed);
        os << setprecision(2);
        os << "Toy" << setw(8) << orderID << ":" << right << setw(18)
            << toyName << setw(3) << noOfItems << " items" << setw(8)
            << price << "/item  subtotal:" << setw(7)
            << noOfItems * price << " tax:" << setw(6)
            << noOfItems * price * hst << " total:"
            << setw(7) << noOfItems * price * (hst + 1) << endl;
        os.unsetf(ios::fixed);
        return os;
    }
    std::ostream& operator<<(std::ostream& os, const Toy& T)
    {
        return T.display(os);
    }
}