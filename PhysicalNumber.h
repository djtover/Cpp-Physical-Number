#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;
namespace ariel
{

class PhysicalNumber
{
  private:
    enum Unit
    {
        CM,
        M,
        KM,
        SEC,
        MIN,
        HOUR,
        G,
        KG,
        TON
    }

    int value;
    Unit type;
    public:

    Unit operator+(const Unit& obj);
    Unit operator+=(const Unit& obj);
    Unit operator++();
    Unit operator-(const Unit& obj);
    Unit operator-=(const Unit& obj);
    Unit operator--();


    PhysicalNumber(int value, Unit u);
    ~PhysicalNumber();
    void hello()
    {
    }
};
}; // namespace ariel