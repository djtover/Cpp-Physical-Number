
#include "PhysicalNumber.h"
#include <stdexcept>
using namespace ariel;

// This is an operator overload on addition
PhysicalNumber PhysicalNumber::operator+(PhysicalNumber other)
{
  int currentType = (int)type;
  int otherType = (int)other.getType();
  double v;
  double ret;
  if (currentType == otherType)
  {
    v = value + other.getValue();
  }
  else
  {
    ret = sameTypeValue(*this, other);
    v = value + ret;
  }
  return PhysicalNumber(v, type);
}
// This is an operator overload on Unary+
PhysicalNumber PhysicalNumber::operator+()
{
  return PhysicalNumber(value, type);
}
// This is an operator overload on plus equals
PhysicalNumber PhysicalNumber::operator+=(PhysicalNumber other)
{
  int currentType = (int)type;
  int otherType = (int)other.getType();
  double ret;
  if (currentType == otherType)
  {
    value = value + other.getValue();
  }
  else
  {
    ret = sameTypeValue(*this, other);
    value += ret;
  }
  return *this;
}
// This is an operator overload on plus plus prefix
PhysicalNumber& PhysicalNumber::operator++()
{
  value++;
  return *this;
   
 
}
// This is an operator overload on plus plus postfix
PhysicalNumber PhysicalNumber::operator++(int other)
{
  PhysicalNumber temp = *this;
  ++value;
  return temp;
}
// This is an operator overload on subtraction
PhysicalNumber PhysicalNumber::operator-(PhysicalNumber other)
{
  int currentType = (int)type;
  int otherType = (int)other.getType();
  double v;
  double ret;
  if (currentType == otherType)
  {
    v = value - other.getValue();
  }
  else
  {
    ret = sameTypeValue(*this, other);
    v = value - ret;
  }
  return PhysicalNumber(v, type);
}
// This is an operator overload on unary-
PhysicalNumber PhysicalNumber::operator-()
{
  return PhysicalNumber(-value, type);
}
// This is an operator overload on minus equals
PhysicalNumber PhysicalNumber::operator-=(PhysicalNumber other)
{
  int currentType = (int)type;
  int otherType = (int)other.getType();
  double ret;
  if (currentType == otherType)
  {
    value = value - other.getValue();
  }
  else
  {
    ret = sameTypeValue(*this, other);
    value -= ret;
  }
  return *this;
}
// This is an operator overload on decrement prefix
PhysicalNumber& PhysicalNumber::operator--()
{
  value--;
  return *this;
}
// This is an operator overload on decrement postfix
PhysicalNumber PhysicalNumber::operator--(int other)
{
  PhysicalNumber temp = *this;
  value--;
  return temp;
}
// This is an operator overload on less than
bool PhysicalNumber::operator<(PhysicalNumber other)
{
  int currentType = (int)type;
  int otherType = (int)other.getType();
  bool ans;
  double v;

  if (currentType == otherType)
  {
    ans = value < other.getValue() ? true : false;
  }
  else
  {
    v = sameTypeValue(*this, other);
    ans = value < v ? true : false;
  }
  return ans;
}
// This is an operator overload on at most
bool PhysicalNumber::operator<=(PhysicalNumber other)
{
  int currentType = (int)type;
  int otherType = (int)other.getType();
  bool ans;
  double v;

  if (currentType == otherType)
  {
    ans = value <= other.getValue() ? true : false;
  }
  else
  {
    v = sameTypeValue(*this, other);
    ans = value <= v ? true : false;
  }
  return ans;
}
// This is an operator overload on greater than
bool PhysicalNumber::operator>(PhysicalNumber other)
{

  int currentType = (int)type;
  int otherType = (int)other.getType();
  bool ans;
  double v;

  if (currentType == otherType)
  {
    ans = value > other.getValue() ? true : false;
  }
  else
  {
    v = sameTypeValue(*this, other);
    ans = value > v ? true : false;
  }
  return ans;
}
// This is an operator overload on at least
bool PhysicalNumber::operator>=(PhysicalNumber other)
{
  int currentType = (int)type;
  int otherType = (int)other.getType();
  bool ans;
  double v;

  if (currentType == otherType)
  {
    ans = value >= other.getValue() ? true : false;
  }
  else
  {
    v = sameTypeValue(*this, other);
    ans = value >= v ? true : false;
  }
  return ans;
}
// This is an operator overload on if they are equal
bool PhysicalNumber::operator==(PhysicalNumber other)
{
  int currentType = (int)type;
  int otherType = (int)other.getType();
  bool ans;
  double v;

  if (currentType == otherType)
  {
    ans = value == other.getValue() ? true : false;
  }
  else
  {
    v = sameTypeValue(*this, other);
    ans = value == v ? true : false;
  }
  return ans;
}
// This is an operator overload on if they aren't equal
bool PhysicalNumber::operator!=(PhysicalNumber other)
{
  int currentType = (int)type;
  int otherType = (int)other.getType();
  bool ans;
  double v;

  if (currentType == otherType)
  {
    ans = value != other.getValue() ? true : false;
  }
  else
  {
    v = sameTypeValue(*this, other);
    ans = value != v ? true : false;
  }
  return ans;
}
// A private method to convert the type that is being compared to to the type the physical number has
double PhysicalNumber::sameTypeValue(PhysicalNumber a, PhysicalNumber b)
{
  int t1 = (int)a.getType();
  int t2 = (int)b.getType();
  double v;
  double div60 = 1/60;
  double div3600 = 1/3600;
  switch (t1)
  {
  case (0):
    if (t2 == 1)
    {
      v = b.getValue() * 100;
    }
    else if (t2 == 2)
    {
      v = b.getValue() * 100000;
    }
    else
    {
      throw std::out_of_range("Different units");
    }

    break;
  case (1):
    if (t2 == 0)
    {
      v = b.getValue() * 0.01;
    }
    else if (t2 == 2)
    {
      v = b.getValue() * 1000;
    }
    else
    {
      throw std::out_of_range("Different units");
    }

    break;
  case (2):
    if (t2 == 0)
    {
      v = b.getValue() * 0.00001;
    }
    else if (t2 == 1)
    {
      v = b.getValue() * 0.001;
    }
    else
    {
      throw std::out_of_range("Different units");
    }

    break;
  case (3):
    if (t2 == 4)
    {
      v = b.getValue() * 60;
    }
    else if (t2 == 5)
    {
      v = b.getValue() * 3600;
    }
    else
    {
      throw std::out_of_range("Different units");
    }
    break;
  case (4):
    if (t2 == 3)
    {
      v = b.getValue() /60;
    }
    else if (t2 == 5)
    {
      v = b.getValue() * 60;
    }
    else
    {
      throw std::out_of_range("Different units");
    }
    break;
  case (5):
    if (t2 == 3)
    {
      v = b.getValue() /3600;
    }
    else if (t2 == 4)
    {
      v = b.getValue() /60 ;
    }
    else
    {
      throw std::out_of_range("Different units");
    }
    break;
  case (6):
    if (t2 == 7)
    {
      v = b.getValue() * 1000;
    }
    else if (t2 == 8)
    {
      v = b.getValue() * 1000000;
    }
    else
    {
      throw std::out_of_range("Different units");
    }
    break;
  case (7):
    if (t2 == 6)
    {
      v = b.getValue() * 0.001;
    }
    else if (t2 == 8)
    {
      v = b.getValue() * 1000;
    }
    else
    {
      throw std::out_of_range("Different units");
    }
    break;
  case (8):
    if (t2 == 6)
    {
      v = b.getValue() * 0.000001;
    }
    else if (t2 == 7)
    {
      v = b.getValue() * 0.001;
    }
    else
    {
      throw std::out_of_range("Different units");
    }
    break;
  }
  return v;
}
// A private method to get and check what the next char is
istream &PhysicalNumber::getAndCheckNextCharIs(istream &input, char expectedChar)
{
  char actualChar;
  input >> actualChar;
  if (!input)
    return input;

  if (actualChar != expectedChar)
    // failbit is for format error
    input.setstate(ios::failbit);
  return input;
}
