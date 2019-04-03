#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
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
  static istream &getAndCheckNextCharIs(istream &input, char expectedChar);

public:
  double getValue() const
  {
    return value;
  }
  Unit getType() const
  {
    return type;
  }
  void setValue(double v) 
  {
    value = v;
  }
  void setType(string s) 
  {
    if (s == "cm")
    {
      type = Unit::CM;
    }
    else if (s == "m")
    {
      type = Unit::M;
    }
    else if (s == "km")
    {
      type = Unit::KM;
    }
    else if (s == "sec")
    {
      type = Unit::SEC;
    }
    else if (s == "min")
    {
      type = Unit::MIN;
    }
    else if (s == "hour")
    {
      type = Unit::HOUR;
    }
    else if (s == "g")
    {
      type = Unit::G;
    }
    else if (s == "kg")
    {
      type = Unit::KG;
    }
    else if (s == "ton")
    {
      type = Unit::TON;
    }
    else
    {
      throw std::out_of_range("Thats not a type");
    }
  }
  void setType(Unit u) 
  {
    type = u;
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
  PhysicalNumber &operator+=(const PhysicalNumber &other)
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
  friend ostream &operator<<(ostream &os, const PhysicalNumber &pn)
  {
    double v = pn.getValue();
    int t = (int)pn.getType();
    return (os << v << ' ' << t << endl);
  }
  friend istream &operator>>(istream &input, PhysicalNumber &pn)
  {
    double newValue;
    string newType;

    // remember place for rewinding
    ios::pos_type startPosition = input.tellg();

    if ((!(input >> newValue)) ||
        (!getAndCheckNextCharIs(input, '[')) ||
        (!(input >> newType)) ||
        (!(getAndCheckNextCharIs(input, ']'))))
    {

      // rewind on error
      auto errorState = input.rdstate(); // remember error state
      input.clear();                     // clear error so seekg will work
      input.seekg(startPosition);        // rewind
      input.clear(errorState);           // set back the error flag
    }
    else
    {
     pn.setValue(newValue);
     pn.setType(newType);
    }

    return input;
  }

  PhysicalNumber(int x, ariel::Unit u)
  {
    PhysicalNumber::value = x;
    PhysicalNumber::type = u;
  }
  // ~PhysicalNumber();
};
}; // namespace ariel