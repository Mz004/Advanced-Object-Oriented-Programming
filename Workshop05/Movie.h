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
#ifndef SENECA_MOVIE_H
#define SENECA_MOVIE_H

#include <iostream>
#include <string>
#include <sstream>

namespace seneca
{
    class Movie
    {
        std::string m_title;
        int m_year;
        std::string m_description;

    public:
        Movie();
        const std::string& title() const;
        Movie(const std::string& strMovie);
        friend std::ostream& operator<<(std::ostream& os, const Movie& movie);

        template <typename T>
        void fixSpelling(T& spellChecker)
        {
            spellChecker(m_title);
            spellChecker(m_description);
        }
    };
}

#endif // !SENECA_MOVIE_H