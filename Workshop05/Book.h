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
#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>


namespace seneca
{
    class Book
    {
    private:
        std::string m_author{};
        std::string m_title{};
        std::string m_country{};
        size_t m_year{};
        double m_price{};
        std::string m_description{};

    public:
        Book();
        const std::string& title() const;
        const std::string& country() const;
        const size_t& year() const;
        double& price();
        Book(const std::string& strBook);
        friend std::ostream& operator<<(std::ostream& os, const Book& book);

        template <typename T>
        void fixSpelling(T& spellChecker) 
        { 
            spellChecker(m_description); 
        }
    };
}

#endif // !SENECA_BOOK_H
