
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

  PhysicalNumber PhysicalNumber::operator+()
  {
    return *this;
  }
  PhysicalNumber PhysicalNumber::operator+=(PhysicalNumber other) 
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
        throw std::out_of_range("Different units");
      }
    }
    return *this;
  }
  PhysicalNumber PhysicalNumber::operator++()
  {
    return *this;
  }
  PhysicalNumber PhysicalNumber::operator++(int other){
    return *this;
  }
  PhysicalNumber PhysicalNumber::operator-( PhysicalNumber other)
  {
    int currentType = (int)type;
    int otherType = (int)other.getType();
    double v;
    if (currentType == otherType)
    {
      v = value - other.getValue();
    }
    else
    {
      if ((currentType >= 0 && currentType <= 2) && otherType >= 0 && otherType <= 2)
      {
       v = subLength(other);
      }
      else if ((currentType >= 3 && currentType <= 5) && otherType >= 3 && otherType <= 5)
      {
        v = subTime(other);
      }
      else if ((currentType >= 6 && currentType <= 8) && otherType >= 6 && otherType <= 8)
      {
        v = subMass(other);
      }
      else
      {
        throw std::out_of_range("Different units");
      }
    }
    return PhysicalNumber(v, type);
    // return *this;
  }
  PhysicalNumber PhysicalNumber::operator-()
  {
    return *this;
  }
  PhysicalNumber PhysicalNumber::operator-=(PhysicalNumber other)
  {
      int currentType = (int)type;
    int otherType = (int)other.getType();
   
    if (currentType == otherType)
    {
      value = value - other.getValue();
    }
    else
    {
      if ((currentType >= 0 && currentType <= 2) && otherType >= 0 && otherType <= 2)
      {
        value = subLength(other);
        
      }
      else if ((currentType >= 3 && currentType <= 5) && otherType >= 3 && otherType <= 5)
      {
       value = subTime(other);
      }
      else if ((currentType >= 6 && currentType <= 8) && otherType >= 6 && otherType <= 8)
      {
        value = subMass(other);
      }
      else
      {
        cout << currentType << "," << otherType << endl;
        throw std::out_of_range("Different units");
      }
    }
    return *this;
  }
  PhysicalNumber PhysicalNumber::operator--()
  {
    return *this;
  }
  PhysicalNumber PhysicalNumber::operator--(int other){
    return *this;
  }
  bool PhysicalNumber::operator<(PhysicalNumber other)
  {
    return false;
  }
  bool PhysicalNumber::operator<=(PhysicalNumber other)
  {
    return false;
  }
  bool PhysicalNumber::operator>(PhysicalNumber other)
  {
    return false;
  }
  bool PhysicalNumber::operator>=( PhysicalNumber other)
  {
    return false;
  }
  bool PhysicalNumber::operator==( PhysicalNumber other)
  {
    return false;
  }
  bool PhysicalNumber::operator!=( PhysicalNumber other){
    return false;
  }


double PhysicalNumber::addMass(PhysicalNumber other)
{
    int currentType = (int)type;
    int otherType = (int)other.getType();
    double v;

    if (currentType > otherType)
    {
        //  currentType is in TON
        if (currentType == 8)
        {
            // otherType is in KG
            if (otherType == 7)
            {
                v = value + (other.getValue()) * 0.001;
            }
            // otherType is in G
            else
            {
                v = value + (other.getValue()) * 0.000001;
            }
        }
        // currentType is in KG and otherType is in G
        else
        {
            v = value + (other.getValue()) * 0.001;
        }
    }
    else
    {
        //  otherType is in TON
        if (otherType == 8)
        {
            // currentType is in KG
            if (currentType == 7)
            {
                v = value + (other.getValue()) * 1000;
            }
            // currenType is in G
            else
            {
                v = value + (other.getValue()) * 1000000;
            }
        }
        // otherType is in KG and currentType is in G
        else
        {
            v = value + (other.getValue()) * 1000;
        }
    }
    return v;
}

double PhysicalNumber::addTime(PhysicalNumber other)
{
    int currentType = (int)type;
    int otherType = (int)other.getType();
    double v;
    if (currentType > otherType)
    {
        //  currentType is in HOUR
        if (currentType == 5)
        {
            // otherType is in MIN
            if (otherType == 4)
            {
                v = value + (other.getValue()) * 0.01667;
            }
            // otherType is in SEC
            else
            {
                v = value + (other.getValue()) * 0.0002777;
            }
        }
        // currentType is in MIN and otherType is in SEC
        else
        {
            v = value + (other.getValue()) * 0.01667;
        }
    }
    else
    {
        //  otherType is in HOUR
        if (otherType == 5)
        {
            // currentType is in MIN
            if (currentType == 4)
            {
                v = value + (other.getValue()) * 60;
            }
            // currenType is in SEC
            else
            {
                v = value + (other.getValue()) * 3600;

            }
        }
        // otherType is in MIN and currentType is in SEC
        else
        {
            v = value + (other.getValue()) * 60;
        }
        
    }
    return v;
}
double PhysicalNumber::addLength(PhysicalNumber other)
{
    int currentType = (int)type;
    int otherType = (int)other.getType();
    double v;
    if (currentType > otherType)
    {
        //  currentType is in KM
        if (currentType == 2)
        {
            // otherType is in M
            if (otherType == 1)
            {
                v = value + (other.getValue()) * 0.001;
            }
            // otherType is in CM
            else
            {
                v = value + (other.getValue()) * 0.00001;
            }
        }
        // currentType is in M and otherType is in CM
        else
        {
            v = value + (other.getValue()) * 0.01;
        }
    }
    else
    {
        //  otherType is in KM
        if (otherType == 2)
        {
            // currentType is in M
            if (currentType == 1)
            {
                v = value + (other.getValue()) * 1000;
            }
            // currenType is in CM
            else
            {
                v = value + (other.getValue()) * 100000;
            }
        }
        // otherType is in M and currentType is in CM
        else
        {
            v = value + (other.getValue()) * 100;
        }
        
    }
    return v;
}

 double PhysicalNumber::subMass(PhysicalNumber other){
    int currentType = (int)type;
    int otherType = (int)other.getType();
    double v;

    if (currentType > otherType)
    {
        //  currentType is in TON
        if (currentType == 8)
        {
            // otherType is in KG
            if (otherType == 7)
            {
                v = value - (other.getValue()) * 0.001;
            }
            // otherType is in G
            else
            {
                v = value - (other.getValue()) * 0.000001;
            }
        }
        // currentType is in KG and otherType is in G
        else
        {
            v = value - (other.getValue()) * 0.001;
        }
    }
    else
    {
        //  otherType is in TON
        if (otherType == 8)
        {
            // currentType is in KG
            if (currentType == 7)
            {
                v = value - (other.getValue()) * 1000;
            }
            // currenType is in G
            else
            {
                v = value - (other.getValue()) * 1000000;
            }
        }
        // otherType is in KG and currentType is in G
        else
        {
            v = value - (other.getValue()) * 1000;
        }
    }
    return v;

 }
  double  PhysicalNumber::subTime(PhysicalNumber other){
    int currentType = (int)type;
    int otherType = (int)other.getType();
    double v;
    if (currentType > otherType)
    {
        //  currentType is in HOUR
        if (currentType == 5)
        {
            // otherType is in MIN
            if (otherType == 4)
            {
                v = value - (other.getValue()) * 0.01667;
            }
            // otherType is in SEC
            else
            {
                v = value - (other.getValue()) * 0.0002777;
            }
        }
        // currentType is in MIN and otherType is in SEC
        else
        {
            v = value - (other.getValue()) * 0.01667;
        }
    }
    else
    {
        //  otherType is in HOUR
        if (otherType == 5)
        {
            // currentType is in MIN
            if (currentType == 4)
            {
                v = value - (other.getValue()) * 60;
            }
            // currenType is in SEC
            else
            {
                v = value - (other.getValue()) * 3600;

            }
        }
        // otherType is in MIN and currentType is in SEC
        else
        {
            v = value - (other.getValue()) * 60;
        }
        
    }
    return v;

  }
  double  PhysicalNumber::subLength(PhysicalNumber other){
    int currentType = (int)type;
    int otherType = (int)other.getType();
    double v;
    if (currentType > otherType)
    {
        //  currentType is in KM
        if (currentType == 2)
        {
            // otherType is in M
            if (otherType == 1)
            {
                v = value - (other.getValue()) * 0.001;
            }
            // otherType is in CM
            else
            {
                v = value - (other.getValue()) * 0.00001;
            }
        }
        // currentType is in M and otherType is in CM
        else
        {
            v = value - (other.getValue()) * 0.01;
        }
    }
    else
    {
        //  otherType is in KM
        if (otherType == 2)
        {
            // currentType is in M
            if (currentType == 1)
            {
                v = value - (other.getValue()) * 1000;
            }
            // currenType is in CM
            else
            {
                v = value - (other.getValue()) * 100000;
            }
        }
        // otherType is in M and currentType is in CM
        else
        {
            v = value - (other.getValue()) * 100;
        }
        
    }
    return v;

  }
istream& PhysicalNumber::getAndCheckNextCharIs(istream& input, char expectedChar) {
    char actualChar;
    input >> actualChar;
    if (!input) return input;

    if (actualChar!=expectedChar) 
        // failbit is for format error
        input.setstate(ios::failbit);
    return input;
}
