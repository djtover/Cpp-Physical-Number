
#include "PhysicalNumber.h"
#include <stdexcept>
// ariel::PhysicalNumber::~PhysicalNumber(){
//     delete type;
// }

void ariel::PhysicalNumber::addEqualMass(PhysicalNumber &other)
{
    int currentType = (int)type;
    int otherType = (int)other.getType();

    if (currentType > otherType)
    {
        //  currentType is in TON
        if (currentType == 8)
        {
            // otherType is in KG
            if (otherType == 7)
            {
                value = value + (other.getValue()) * 0.001;
            }
            // otherType is in G
            else
            {
                value = value + (other.getValue()) * 0.000001;
            }
        }
        // currentType is in KG and otherType is in G
        else
        {
            value = value + (other.getValue()) * 0.001;
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
                value = value + (other.getValue()) * 1000;
            }
            // currenType is in G
            else
            {
                value = value + (other.getValue()) * 1000000;
            }
        }
        // otherType is in KG and currentType is in G
        else
        {
            value = value + (other.getValue()) * 1000;
        }
    }
}

void ariel::PhysicalNumber::addEqualTime(PhysicalNumber &other)
{
    int currentType = (int)type;
    int otherType = (int)other.getType();
    if (currentType > otherType)
    {
        //  currentType is in HOUR
        if (currentType == 5)
        {
            // otherType is in MIN
            if (otherType == 4)
            {
                value = value + (other.getValue()) * 0.01667;
            }
            // otherType is in SEC
            else
            {
                value = value + (other.getValue()) * 0.0002777;
            }
        }
        // currentType is in MIN and otherType is in SEC
        else
        {
            value = value + (other.getValue()) * 0.01667;
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
                value = value + (other.getValue()) * 60;
            }
            // currenType is in SEC
            else
            {
                value = value + (other.getValue()) * 3600;
            }
        }
        // otherType is in MIN and currentType is in SEC
        else
        {
            value = value + (other.getValue()) * 60;
        }
    }
}
void ariel::PhysicalNumber::addEqualLength(PhysicalNumber &other)
{
    int currentType = (int)type;
    int otherType = (int)other.getType();
    if (currentType > otherType)
    {
        //  currentType is in KM
        if (currentType == 2)
        {
            // otherType is in M
            if (otherType == 1)
            {
                value = value + (other.getValue()) * 0.001;
            }
            // otherType is in CM
            else
            {
                value = value + (other.getValue()) * 0.0001;
            }
        }
        // currentType is in M and otherType is in CM
        else
        {
            value = value + (other.getValue()) * 0.01;
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
                value = value + (other.getValue()) * 1000;
            }
            // currenType is in CM
            else
            {
                value = value + (other.getValue()) * 100000;
            }
        }
        // otherType is in M and currentType is in CM
        else
        {
            value = value + (other.getValue()) * 100;
        }
    }
}
istream& ariel::PhysicalNumber::getAndCheckNextCharIs(istream& input, char expectedChar) {
    char actualChar;
    input >> actualChar;
    if (!input) return input;

    if (actualChar!=expectedChar) 
        // failbit is for format error
        input.setstate(ios::failbit);
    return input;
}
