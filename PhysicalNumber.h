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
  double getValue() 
  {
    return value;
  }
  Unit getType() 
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

  PhysicalNumber operator+(PhysicalNumber other);

  PhysicalNumber operator+();
  
  PhysicalNumber operator+=(PhysicalNumber other); 
  
  PhysicalNumber operator++();
 
  PhysicalNumber operator-( PhysicalNumber other);
  
  PhysicalNumber operator-();
  
  PhysicalNumber operator-=(PhysicalNumber other);
  
  PhysicalNumber operator--();
  
  bool operator<(PhysicalNumber other);
  
  bool operator<=(PhysicalNumber other);
  
  bool operator>(PhysicalNumber other);

  bool operator>=( PhysicalNumber other);
  
  bool operator==( PhysicalNumber other);

  friend ostream &operator<<(ostream &os, PhysicalNumber pn)
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
  friend istream &operator>>(istream &input, PhysicalNumber pn)
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