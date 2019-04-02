
#include "PhysicalNumber.h"
#include <stdexcept>
using namespace ariel;
    PhysicalNumber(int x, Unit u){
        value = x;
        type = u;
}
~PhysicalNumber(){

}
