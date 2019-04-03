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
  void addEqualMass(PhysicalNumber &other);
  void addEqualTime(PhysicalNumber &other);
  void addEqualLength(PhysicalNumber &other);
  

public:
  double getValue() const
  {
    return value;
  }
  Unit getType() const
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
        addEqualLength(other);
      }
      else if ((currentType >= 3 && currentType <= 5) && otherType >= 3 && otherType <= 5)
      {
        addEqualTime(other);
      }
      else if ((currentType >= 6 && currentType <= 8) && otherType >= 6 && otherType <= 8)
      {
        addEqualMass(other);
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
  friend ostream& operator<<(ostream &os, const PhysicalNumber &pn) 
  {
      double v = pn.getValue();
      int t = (int)pn.getType();
        return (os << v << ' ' << t << endl);
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