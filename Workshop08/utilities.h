/*******************************************************************
*                            Workshop 08 
* Name       : Manav Alpeshbhai Zadafiya
* Email      : mazadafiya@myseneca.ca
* Student ID : 144095221
* Date       : 2024-03-23
* Authentication Declaration:
* I declare that this submission is the result of my own work and I
* only copied the code that my professor provided to complete my
* workshops and assignments. This submitted piece of work has not
* been shared with any other student or 3rd party content provider.
*******************************************************************/
#ifndef SENECA_UTILITIES_H
#define SENECA_UTILITIES_H

#include "list.h"
#include "element.h"

namespace seneca
{
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price);
	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price);
}

#endif //SENECA_UTILITIES_H!