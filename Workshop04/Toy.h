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
#ifndef SENECA_TOY_H
#define SENECA_TOY_H

namespace seneca
{
    class Toy
    {
        unsigned int orderID{};
        std::string toyName{};
        int noOfItems{};
        double price{};
        double hst{ 0.13 };

        static std::string trim(const std::string& str, const std::string& ws);
        static std::string reduce(const std::string& str, const std::string& fill, const std::string& whitespace);
        static void setPos(std::string::size_type& end, const char* ch, std::string& str);

    public:
        Toy();
        void update(int numToys);
        Toy(const std::string& T);
        std::ostream& display(std::ostream& os = std::cout) const;
    };
    std::ostream& operator<<(std::ostream& os, const Toy& T);
}
#endif // !SENECA_TOY_H
