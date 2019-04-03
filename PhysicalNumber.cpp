
#include "PhysicalNumber.h"
#include <stdexcept>
// ariel::PhysicalNumber::~PhysicalNumber(){
//     delete type;
// }

double ariel::PhysicalNumber::addMass(PhysicalNumber &other)
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
                // return v;
            }
            // otherType is in G
            else
            {
                v = value + (other.getValue()) * 0.000001;
                // return v;
            }
        }
        // currentType is in KG and otherType is in G
        else
        {
            v = value + (other.getValue()) * 0.001;
            // return v;
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
                // return v;
            }
            // currenType is in G
            else
            {
                v = value + (other.getValue()) * 1000000;
                // return v;
            }
        }
        // otherType is in KG and currentType is in G
        else
        {
            v = value + (other.getValue()) * 1000;
            // return v;
        }
    }
    return v;
}

double ariel::PhysicalNumber::addTime(PhysicalNumber &other)
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
                // return v;
            }
            // otherType is in SEC
            else
            {
                v = value + (other.getValue()) * 0.0002777;
                // return v;
            }
        }
        // currentType is in MIN and otherType is in SEC
        else
        {
            v = value + (other.getValue()) * 0.01667;
            // return v;
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
                // return v;
            }
            // currenType is in SEC
            else
            {
                v = value + (other.getValue()) * 3600;
                // return v;

            }
        }
        // otherType is in MIN and currentType is in SEC
        else
        {
            v = value + (other.getValue()) * 60;
            // return v;
        }
        
    }
    return v;
}
double ariel::PhysicalNumber::addLength(PhysicalNumber &other)
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
                // return v;
            }
            // otherType is in CM
            else
            {
                v = value + (other.getValue()) * 0.0001;
                // return v;
            }
        }
        // currentType is in M and otherType is in CM
        else
        {
            v = value + (other.getValue()) * 0.01;
            // return v;
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
                // return v;
            }
            // currenType is in CM
            else
            {
                v = value + (other.getValue()) * 100000;
                // return v;
            }
        }
        // otherType is in M and currentType is in CM
        else
        {
            v = value + (other.getValue()) * 100;
            // return v;
        }
        
    }
    return v;
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
