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
  double sameTypeValue(PhysicalNumber a, PhysicalNumber b);
  static istream &getAndCheckNextCharIs(istream &input, char expectedChar);

public:
  PhysicalNumber(double x, ariel::Unit u)
  {
    value = x;
    type = u;
  }
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
    if (s == "cm]")
    {
      type = Unit::CM;
    }
    else if (s == "m]")
    {
      type = Unit::M;
    }
    else if (s == "km]")
    {
      type = Unit::KM;
    }
    else if (s == "sec]")
    {
      type = Unit::SEC;
    }
    else if (s == "min]")
    {
      type = Unit::MIN;
    }
    else if (s == "hour]")
    {
      type = Unit::HOUR;
    }
    else if (s == "g]")
    {
      type = Unit::G;
    }
    else if (s == "kg]")
    {
      type = Unit::KG;
    }
    else if (s == "ton]")
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
// Addition operator overload
  PhysicalNumber operator+(PhysicalNumber other);
// Unary+ operator overload
  PhysicalNumber operator+();
// Increment with value operator overload
  PhysicalNumber operator+=(PhysicalNumber other);
// Increment prefix operator overload
  PhysicalNumber& operator++();
// increment postfix operator overload
  PhysicalNumber operator++(int other);
// Subtraction operator overload
  PhysicalNumber operator-(PhysicalNumber other);
// Unary- operator overload
  PhysicalNumber operator-();
// Decrement with value operator overload
  PhysicalNumber operator-=(PhysicalNumber other);
// Decrement prefix operator overload
  PhysicalNumber& operator--();
// Decrement postfix  operator overload
  PhysicalNumber operator--(int other);
// Less than operator overload
  bool operator<(PhysicalNumber other);
// At most operator overload
  bool operator<=(PhysicalNumber other);
// Greater than operator overload
  bool operator>(PhysicalNumber other);
// At least operator overload
  bool operator>=(PhysicalNumber other);
// Equal operator overload
  bool operator==(PhysicalNumber other);
// Not equal operator overload
  bool operator!=(PhysicalNumber other);
// Output stream method
  friend ostream &operator<<(ostream &os, PhysicalNumber pn)
  {
    os.precision(6);
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
  // Input stream method
  friend istream &operator>>(istream &input, PhysicalNumber &pn)
  {
    double newValue;
    string newType;

    // remember place for rewinding
    ios::pos_type startPosition = input.tellg();

    if ((!(input >> newValue)) ||
        (!getAndCheckNextCharIs(input, '[')) ||
        (!(input >> newType))) //||
                               //(!getAndCheckNextCharIs(input, ']')))
    {
      // rewind on error
      auto errorState = input.rdstate(); // remember error state
      input.clear();                     // clear error so seekg will work
      input.seekg(startPosition);        // rewind
      input.clear(errorState);           // set back the error flag
    }
    else
    {
      try{
      pn.setType(newType);
      pn.setValue(newValue);
      }
      catch (std::exception& ex) {
	 	cout << "   caught exception: " << ex.what() << endl;
	}
    }

    return input;
  }
}; // namespace ariel
}; // namespace ariel