/************************************************************************
*                           Workshop 02 
* Name       : Manav Alpeshbhai Zadafiya
* Email      : mazadafiya@myseneca.ca
* Student ID : 144095221
* Date       : 2024-01-27
* Authentication Declaration:
* I have done all the coding by myself and only copied the code that my
* professor provided to complete my workshops and assignments.
************************************************************************/
#ifndef SENECA_STRINGSET_H
#define SENECA_STRINGSET_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

namespace seneca 
{
	class StringSet {
        std::string* strings;
        std::size_t numStrings;

    public:
        void set();
        size_t size() const;
        std::string operator[](size_t index) const;

        StringSet();
        StringSet(const StringSet& S);
        StringSet(const char* filename);
        StringSet(StringSet&& SS);
        StringSet& operator=(StringSet&& SS);
        StringSet& operator=(const StringSet& S);
        ~StringSet();
	};
}

#endif //!SENECA_STRINGSET_H