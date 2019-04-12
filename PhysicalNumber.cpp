
#include "PhysicalNumber.h"
#include <stdexcept>
using namespace ariel;
// ariel::PhysicalNumber::~PhysicalNumber(){
//     delete type;
// }

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

PhysicalNumber PhysicalNumber::operator+()
{
  return PhysicalNumber(value, type);
}
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
PhysicalNumber PhysicalNumber::operator++()
{
  value++;
  return *this;
}
PhysicalNumber PhysicalNumber::operator++(int other)
{
  PhysicalNumber temp = *this;
  ++value;
  return temp;
}
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
PhysicalNumber PhysicalNumber::operator-()
{
  return PhysicalNumber(-value, type);
}
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
PhysicalNumber PhysicalNumber::operator--()
{
  value--;
  return *this;
}
PhysicalNumber PhysicalNumber::operator--(int other)
{
  PhysicalNumber temp = *this;
  value--;
  return temp;
}
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
