/************************************************************************
*                           Workshop 05
* Name       : Manav Alpeshbhai Zadafiya
* Email      : mazadafiya@myseneca.ca
* Student ID : 144095221
* Date       : 2024-02-17
* Authentication Declaration:
* I declare that this submission is the result of my own work and I only
* copied the code that my professor provided to complete my workshops and
* assignments. This submitted piece of work has not been shared with any
* other student or 3rd party content provider.
************************************************************************/
#include <iostream>
#include <iomanip>
#include <string>
#include "Movie.h"

using namespace std;

namespace seneca
{
    Movie::Movie() : m_year(0) {}

    const std::string& Movie::title() const { return m_title; }

    Movie::Movie(const std::string& strMovie)
    {
        size_t pos = 0, next;
        next = strMovie.find(',');
        m_title = strMovie.substr(pos, next - pos);
        m_title = m_title.erase(m_title.find_last_not_of(' ') + 1);
        m_title = m_title.erase(0, m_title.find_first_not_of(' '));
        pos = next + 1;
        next = strMovie.find(',', pos);
        m_year = std::stoi(strMovie.substr(pos, next - pos));
        pos = next + 1;
        m_description = strMovie.substr(pos);
        m_description = m_description.erase(m_description.find_last_not_of(' ') + 1);
        m_description = m_description.erase(0, m_description.find_first_not_of(' '));
    }

    std::ostream& operator<<(std::ostream& os, const Movie& movie)
    {
        os << std::right << std::setw(40) << movie.title() << " | ";
        os << std::left << std::setw(4) << movie.m_year << " | ";
        os << std::left << movie.m_description << std::endl;
        return os;
    }
}
