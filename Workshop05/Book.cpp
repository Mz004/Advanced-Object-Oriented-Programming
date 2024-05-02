/************************************************************************
*                           Workshop 05
* Name       : Manav Alpeshbhai Zadafiya
* Email      : mazadafiya@myseneca.ca
* Student ID : 144095221
* Date       : 2024-02-13
* Authentication Declaration:
* I declare that this submission is the result of my own work and I only
* copied the code that my professor provided to complete my workshops and
* assignments. This submitted piece of work has not been shared with any
* other student or 3rd party content provider.
************************************************************************/

#include <iostream>
#include <iomanip>
#include "Book.h"

using namespace std;

namespace seneca
{
    Book::Book()
    {
        m_year = 0;
        m_price = 0;
    }

    const std::string& Book::title() const { return m_title; }
    const std::string& Book::country() const { return m_country; }
    const size_t& Book::year() const { return m_year; }
    double& Book::price() { return m_price; }

    Book::Book(const std::string& strBook)
    {

        std::string delimiter = ",";
        size_t pos = 0;
        std::string book = strBook;
        std::string token;
        int i = 0;
        while((pos = book.find(delimiter)) != std::string::npos && i < 6) {
            token = book.substr(0, pos);
            token = token.erase(token.find_last_not_of(' ') + 1);
            token = token.erase(0, token.find_first_not_of(' '));
            switch(i) {
            case 0:
                m_author = token;
                break;
            case 1:
                m_title = token;
                break;
            case 2:
                m_country = token;
                break;
            case 3:
                m_price = std::stod(token);
                break;
            case 4:
                m_year = std::stoi(token);
                delimiter = ".";
                break;
            case 5:
                m_description = token;
                m_description += ".";
                break;
            }
            book.erase(0, pos + 1);
            i++;
        }
    }

    std::ostream& operator<<(std::ostream& os, const Book& book)
    {
        os << std::right << std::setw(20) << book.m_author << " | ";
        os << std::right << std::setw(22) << book.title() << " | ";
        os << std::right << std::setw(5) << book.country() << " | ";
        os << std::right << std::setw(4) << book.year() << " | ";
        os << std::fixed << std::setprecision(2) << std::setw(6) << book.m_price << " | ";
        os << std::left << book.m_description << std::endl;

        return os;
    }
}