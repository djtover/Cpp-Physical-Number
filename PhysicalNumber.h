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
  double addMass(PhysicalNumber &other);
  double addTime(PhysicalNumber &other);
  double addLength(PhysicalNumber &other);
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

  PhysicalNumber operator+(PhysicalNumber other)
  {
    int currentType = (int)type;
    int otherType = (int)other.getType();
    double v;
    if (currentType == otherType)
    {
      v = value + other.getValue();
    }
    else
    {
      if ((currentType >= 0 && currentType <= 2) && otherType >= 0 && otherType <= 2)
      {
       v = addLength(other);
      }
      else if ((currentType >= 3 && currentType <= 5) && otherType >= 3 && otherType <= 5)
      {
        v = addTime(other);
      }
      else if ((currentType >= 6 && currentType <= 8) && otherType >= 6 && otherType <= 8)
      {
        v = addMass(other);
      }
      else
      {
        throw std::out_of_range("Different units");
      }
    }
    return PhysicalNumber(v, type);
  }
  PhysicalNumber operator+()
  {
    return *this;
  }
  PhysicalNumber operator+=(PhysicalNumber other) 
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
        value = addLength(other);
        
      }
      else if ((currentType >= 3 && currentType <= 5) && otherType >= 3 && otherType <= 5)
      {
       value = addTime(other);
      }
      else if ((currentType >= 6 && currentType <= 8) && otherType >= 6 && otherType <= 8)
      {
        value = addMass(other);
      }
      else
      {
        cout << currentType << "," << otherType << endl;
        throw std::out_of_range("Different units");
      }
    }
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
    int s = (int)pn.getType();
      if (s == 0)
    {
    return (os << v << "[cm]"); 
       }
    else if (s == 1)
    {
    return (os << v << "[m]"); 
    }
    else if (s == 2)
    {
    return (os << v << "[km]"); 
    }
    else if (s == 3)
    {
    return (os << v << "[sec]"); 
    }
    else if (s == 4)
    {
    return (os << v << "[min]"); 
    }
    else if (s == 5)
    {
    return (os << v << "[hour]"); 
    }
    else if (s == 6)
    {
    return (os << v << "[g]"); 
    }
    else if (s == 7)
    {
    return (os << v << "[kg]"); 
    }
    else if (s == 8)
    {
    return (os << v << "[ton]"); 
    }
    else
    {
      throw std::out_of_range("Thats not a type");
    }
  }
  friend istream &operator>>(istream &input, PhysicalNumber &pn)
  {
    double newValue;
    string newType;

    // remember place for rewinding
    ios::pos_type startPosition = input.tellg();

    if ((!(input >> newValue)) ||
        (!getAndCheckNextCharIs(input, '[')) ||
        (!(input >> newType))
        || (!(getAndCheckNextCharIs(input, ']'))))
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
     cout << pn.getValue() << endl;
     pn.setType(newType);
     cout << (int)pn.getType() << endl;
    }

    return input;
  }

  PhysicalNumber(double x, ariel::Unit u)
  {
    PhysicalNumber::value = x;
    PhysicalNumber::type = u;
  }
  // ~PhysicalNumber();
};
}; // namespace ariel