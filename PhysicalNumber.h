#pragma once
#include <iostream>
#include <cstdlib>
#include "Unit.h"
using namespace std;
namespace ariel
{

class PhysicalNumber
{
private:
  double value;
  Unit type;

  // private methods
  void addMass(PhysicalNumber &other);
  void addTime(PhysicalNumber &other);
  void addLength(PhysicalNumber &other);

public:
  double getValue()
  {
    return value;
  }
  Unit getType()
  {
    return type;
  }

  PhysicalNumber operator+(PhysicalNumber &other)
  {
    int currentType = (int)type;
    int otherType = (int)other.getType();
    if (currentType == otherType)
    {
      value = value + other.getValue();
    }
    else
    {
      if ((currentType >= 0 && currentType <= 2) && otherType >= 0 && otherType <= 2)
      {
        addLength(other);
      }
      else if ((currentType >= 3 && currentType <= 5) && otherType >= 3 && otherType <= 5)
      {
        addTime(other);
      }
      else if ((currentType >= 6 && currentType <= 8) && otherType >= 6 && otherType <= 8)
      {
        addMass(other);
      }
      else
      {
        throw std::out_of_range("Different units");
      }
    }
    return *this;
  }
  PhysicalNumber operator+()
  {
    return *this;
  }
  PhysicalNumber& operator+=(const PhysicalNumber &other)
  {
    return *this;
  }
  PhysicalNumber &operator++()
  {
    return *this;
  }
  PhysicalNumber operator-(const PhysicalNumber &other)
  {
    return *this;
  }
  PhysicalNumber operator-()
  {
    return *this;
  }
  PhysicalNumber &operator-=(const PhysicalNumber &other)
  {
    return *this;
  }
  PhysicalNumber &operator--()
  {
    return *this;
  }
  bool operator<(const PhysicalNumber &other)
  {
    return false;
  }
  bool operator<=(const PhysicalNumber &other)
  {
    return false;
  }
  bool operator>(const PhysicalNumber &other)
  {
    return false;
  }
  bool operator>=(const PhysicalNumber &other)
  {
    return false;
  }
  bool operator==(const PhysicalNumber &other)
  {
    return false;
  }
  friend ostream &operator<<(ostream &os, const PhysicalNumber &c)
  {
  }
  friend istream &operator>>(istream &is, PhysicalNumber &c)
  {
  }

  PhysicalNumber(int x, ariel::Unit u)
  {
    PhysicalNumber::value = x;
    PhysicalNumber::type = u;
  }
  // ~PhysicalNumber();
};
}; // namespace ariel