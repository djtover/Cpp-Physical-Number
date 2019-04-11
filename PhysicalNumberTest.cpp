/**
 * Examples of automatic tests for the exercise on physical numbers.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
#include <sstream>
using std::cout, std::endl, std::istringstream;
#include "PhysicalNumber.h"
using ariel::PhysicalNumber, ariel::Unit;
#include "badkan.hpp"

int main() {
  badkan::TestCase testcase;
  int grade=0;
  int signal = setjmp(badkan::longjmp_buffer);
  if (signal == 0) {

    // BASIC TESTS - DO NOT CHANGE
    PhysicalNumber a(2, Unit::KM);
    PhysicalNumber b(300, Unit::M);
    PhysicalNumber c(2, Unit::HOUR);
    PhysicalNumber d(30, Unit::MIN);

    // My values
    PhysicalNumber x1(4, Unit::CM);
    PhysicalNumber x2(4, Unit::M);
    PhysicalNumber x3(4, Unit::KM);
    PhysicalNumber x4(4, Unit::SEC);
    PhysicalNumber x5(4, Unit::MIN);
    PhysicalNumber x6(4, Unit::HOUR);
    PhysicalNumber x7(4, Unit::G);
    PhysicalNumber x8(4, Unit::KG);
    PhysicalNumber x9(4, Unit::TON);


    testcase
    .setname("Basic output")
    .CHECK_OUTPUT(a, "2[km]")
    .CHECK_OUTPUT(b, "300[m]")

    .setname("Compatible dimensions")
    .CHECK_OUTPUT(b+a, "2300[m]")
    .CHECK_OUTPUT((a+=b), "2.3[km]")
    .CHECK_OUTPUT(a, "2.3[km]")
    .CHECK_OUTPUT(a+a, "4.6[km]")
    .CHECK_OUTPUT(b-b, "0[m]")
    .CHECK_OUTPUT(c, "2[hour]")
    .CHECK_OUTPUT(d, "30[min]")
    .CHECK_OUTPUT(d+c, "150[min]")

    .setname("Incompatible dimensions")
    .CHECK_THROWS(a+c)
    .CHECK_THROWS(a+d)
    .CHECK_THROWS(b+c)
    .CHECK_THROWS(b+d)

    .setname("Basic input")
    .CHECK_OK(istringstream("700[kg]") >> a)
    .CHECK_OUTPUT(a,"700[kg]")
    .CHECK_OUTPUT((a += PhysicalNumber(1, Unit::TON)), "1700[kg]")

    // YOUR TESTS - INSERT AS MANY AS YOU WANT

      .setname("Compatible Dimensions on meters")
      .CHECK_OUTPUT(x1,"4[cm]")
      .CHECK_OUTPUT(x2,"4[m]")
      .CHECK_OUTPUT(x3,"4[km]")
      .CHECK_OUTPUT(x1+x2,"404[cm]")
      .CHECK_OUTPUT(x1+x3,"400004[cm]")
      .CHECK_OUTPUT(x2+x1,"4.04[m]")
      .CHECK_OUTPUT(x2+x3,"4004[m]")
      .CHECK_OUTPUT(x3+x1,"4.00004[km]")
      .CHECK_OUTPUT(x3+x2,"4.004[km]")

      .CHECK_OUTPUT(x1-x2,"-396[cm]")
      .CHECK_OUTPUT(x1-x3,"-399996[cm]")
      .CHECK_OUTPUT(x2-x1,"3.96[m]")
      .CHECK_OUTPUT(x2-x3,"-3996[m]")
      .CHECK_OUTPUT(x3-x1,"3.99996[km]")
      .CHECK_OUTPUT(x3-x2,"3.996[km]")
      
    .setname("Incompatible dimensions from meters")
    .CHECK_THROWS(x1+x4)
    .CHECK_THROWS(x1+x5)
    .CHECK_THROWS(x1+x6)
    .CHECK_THROWS(x1+x7)
    .CHECK_THROWS(x1+x8)
    .CHECK_THROWS(x1+x9)
    .CHECK_THROWS(x2+x4)
    .CHECK_THROWS(x2+x5)
    .CHECK_THROWS(x2+x6)
    .CHECK_THROWS(x2+x7)
    .CHECK_THROWS(x2+x8)
    .CHECK_THROWS(x2+x9)
    .CHECK_THROWS(x3+x4)
    .CHECK_THROWS(x3+x5)
    .CHECK_THROWS(x3+x6)
    .CHECK_THROWS(x3+x7)
    .CHECK_THROWS(x3+x8)
    .CHECK_THROWS(x3+x9)


    .CHECK_THROWS(x1-x4)
    .CHECK_THROWS(x1-x5)
    .CHECK_THROWS(x1-x6)
    .CHECK_THROWS(x1-x7)
    .CHECK_THROWS(x1-x8)
    .CHECK_THROWS(x1-x9)
    .CHECK_THROWS(x2-x4)
    .CHECK_THROWS(x2-x5)
    .CHECK_THROWS(x2-x6)
    .CHECK_THROWS(x2-x7)
    .CHECK_THROWS(x2-x8)
    .CHECK_THROWS(x2-x9)
    .CHECK_THROWS(x3-x4)
    .CHECK_THROWS(x3-x5)
    .CHECK_THROWS(x3-x6)
    .CHECK_THROWS(x3-x7)
    .CHECK_THROWS(x3-x8)
    .CHECK_THROWS(x3-x9)

       .setname("Compatible Dimensions on time")
      .CHECK_OUTPUT(x4,"4[sec]")
      .CHECK_OUTPUT(x5,"4[min]")
      .CHECK_OUTPUT(x6,"4[hour]")
      .CHECK_OUTPUT(x4+x5,"244[sec]")
      .CHECK_OUTPUT(x4+x6,"14404[sec]")
      .CHECK_OUTPUT(x5+x4,"4.06668[min]")
      .CHECK_OUTPUT(x5+x6,"244[min]")
      .CHECK_OUTPUT(x6+x4,"4.001111[hour]")
      .CHECK_OUTPUT(x6+x5,"4.06668[hour]")

      .CHECK_OUTPUT(x4-x5,"-236[sec]")
      .CHECK_OUTPUT(x4-x6,"-14396[sec]")
      .CHECK_OUTPUT(x5-x4,"3.93332[min]")
      .CHECK_OUTPUT(x5-x6,"-236[min]")
      .CHECK_OUTPUT(x6-x4,"3.998889[hour]")
      .CHECK_OUTPUT(x6-x5,"3.93332[hour]")

    .setname("Incompatible dimensions from time")
    .CHECK_THROWS(x4+x1)
    .CHECK_THROWS(x4+x2)
    .CHECK_THROWS(x4+x3)
    .CHECK_THROWS(x4+x7)
    .CHECK_THROWS(x4+x8)
    .CHECK_THROWS(x4+x9)
    .CHECK_THROWS(x5+x1)
    .CHECK_THROWS(x5+x2)
    .CHECK_THROWS(x5+x3)
    .CHECK_THROWS(x5+x7)
    .CHECK_THROWS(x5+x8)
    .CHECK_THROWS(x5+x9)
    .CHECK_THROWS(x6+x1)
    .CHECK_THROWS(x6+x2)
    .CHECK_THROWS(x6+x3)
    .CHECK_THROWS(x6+x7)
    .CHECK_THROWS(x6+x8)
    .CHECK_THROWS(x6+x9)


    .CHECK_THROWS(x4-x1)
    .CHECK_THROWS(x4-x2)
    .CHECK_THROWS(x4-x3)
    .CHECK_THROWS(x4-x7)
    .CHECK_THROWS(x4-x8)
    .CHECK_THROWS(x4-x9)
    .CHECK_THROWS(x5-x1)
    .CHECK_THROWS(x5-x2)
    .CHECK_THROWS(x5-x3)
    .CHECK_THROWS(x5-x7)
    .CHECK_THROWS(x5-x8)
    .CHECK_THROWS(x5-x9)
    .CHECK_THROWS(x6-x1)
    .CHECK_THROWS(x6-x2)
    .CHECK_THROWS(x6-x3)
    .CHECK_THROWS(x6-x7)
    .CHECK_THROWS(x6-x8)
    .CHECK_THROWS(x6-x9) 

      .setname("Compatible Dimensions on mass")
      .CHECK_OUTPUT(x7,"4[g]")
      .CHECK_OUTPUT(x8,"4[kg]")
      .CHECK_OUTPUT(x9,"4[ton]")
      .CHECK_OUTPUT(x7+x8,"4004[g]")
      .CHECK_OUTPUT(x7+x9,"4000004[g]")
      .CHECK_OUTPUT(x8+x7,"4.004[kg]")
      .CHECK_OUTPUT(x8+x9,"4004[kg]")
      .CHECK_OUTPUT(x9+x7,"4.000004[ton]")
      .CHECK_OUTPUT(x9+x8,"4.004[ton]")

      .CHECK_OUTPUT(x7-x8,"-3996[g]")
      .CHECK_OUTPUT(x7-x9,"-3999996[g]")
      .CHECK_OUTPUT(x8-x7,"3.996[kg]")
      .CHECK_OUTPUT(x8-x9,"-3996[kg]")
      .CHECK_OUTPUT(x9-x7,"3.999996[ton]")
      .CHECK_OUTPUT(x9-x8,"3.996[ton]")

    .setname("Incompatible dimensions from grams")
    .CHECK_THROWS(x7+x4)
    .CHECK_THROWS(x7+x5)
    .CHECK_THROWS(x7+x6)
    .CHECK_THROWS(x7+x1)
    .CHECK_THROWS(x7+x2)
    .CHECK_THROWS(x7+x3)
    .CHECK_THROWS(x8+x4)
    .CHECK_THROWS(x8+x5)
    .CHECK_THROWS(x8+x6)
    .CHECK_THROWS(x8+x1)
    .CHECK_THROWS(x8+x2)
    .CHECK_THROWS(x8+x3)
    .CHECK_THROWS(x9+x4)
    .CHECK_THROWS(x9+x5)
    .CHECK_THROWS(x9+x6)
    .CHECK_THROWS(x9+x1)
    .CHECK_THROWS(x9+x2)
    .CHECK_THROWS(x9+x3)


    .CHECK_THROWS(x1-x4)
    .CHECK_THROWS(x1-x5)
    .CHECK_THROWS(x1-x6)
    .CHECK_THROWS(x1-x7)
    .CHECK_THROWS(x1-x8)
    .CHECK_THROWS(x1-x9)
    .CHECK_THROWS(x2-x4)
    .CHECK_THROWS(x2-x5)
    .CHECK_THROWS(x2-x6)
    .CHECK_THROWS(x2-x7)
    .CHECK_THROWS(x2-x8)
    .CHECK_THROWS(x2-x9)
    .CHECK_THROWS(x3-x4)
    .CHECK_THROWS(x3-x5)
    .CHECK_THROWS(x3-x6)
    .CHECK_THROWS(x3-x7)
    .CHECK_THROWS(x3-x8)
    .CHECK_THROWS(x3-x9) 


    
      
.setname("Plus equal compatible dimensions for meters")
.CHECK_OUTPUT((x1 += PhysicalNumber(4, Unit::CM)), "8[cm]")
.CHECK_OK(x1 = PhysicalNumber(4, Unit::CM))
.CHECK_OUTPUT((x1 += PhysicalNumber(4, Unit::M)), "404[cm]")
.CHECK_OK(x1 = PhysicalNumber(4, Unit::CM))
.CHECK_OUTPUT((x1 += PhysicalNumber(4, Unit::KM)), "400004[cm]")
.CHECK_OK(x1 = PhysicalNumber(4, Unit::CM))
.CHECK_OUTPUT((x2 += PhysicalNumber(4, Unit::CM)), "4.04[m]")
.CHECK_OK(x2 = PhysicalNumber(4, Unit::M))
.CHECK_OUTPUT((x2 += PhysicalNumber(4, Unit::M)), "8[m]")
.CHECK_OK(x2 = PhysicalNumber(4, Unit::M))
.CHECK_OUTPUT((x2 += PhysicalNumber(4, Unit::KM)), "4004[m]")
.CHECK_OK(x2 = PhysicalNumber(4, Unit::M))
.CHECK_OUTPUT((x3 += PhysicalNumber(4, Unit::CM)), "4.00004[km]")
.CHECK_OK(x3 = PhysicalNumber(4, Unit::KM))
.CHECK_OUTPUT((x3 += PhysicalNumber(4, Unit::M)), "4.004[km]") 
.CHECK_OK(x3 = PhysicalNumber(4, Unit::KM))
.CHECK_OUTPUT((x3 += PhysicalNumber(4, Unit::KM)), "8[km]")
.CHECK_OK(x3 = PhysicalNumber(4, Unit::KM))    

.setname("Plus equal incompatible dimensions for meters")

.CHECK_THROWS(x1 += PhysicalNumber(4, Unit::SEC))
.CHECK_THROWS(x1 += PhysicalNumber(4, Unit::MIN))
.CHECK_THROWS(x1 += PhysicalNumber(4, Unit::HOUR))
.CHECK_THROWS(x1 += PhysicalNumber(4, Unit::G))
.CHECK_THROWS(x1 += PhysicalNumber(4, Unit::KG))
.CHECK_THROWS(x1 += PhysicalNumber(4, Unit::TON))

.CHECK_THROWS(x2 += PhysicalNumber(4, Unit::SEC))
.CHECK_THROWS(x2 += PhysicalNumber(4, Unit::MIN))
.CHECK_THROWS(x2 += PhysicalNumber(4, Unit::HOUR))
.CHECK_THROWS(x2 += PhysicalNumber(4, Unit::G))
.CHECK_THROWS(x2 += PhysicalNumber(4, Unit::KG))
.CHECK_THROWS(x2 += PhysicalNumber(4, Unit::TON))

.CHECK_THROWS(x3 += PhysicalNumber(4, Unit::SEC))
.CHECK_THROWS(x3 += PhysicalNumber(4, Unit::MIN))
.CHECK_THROWS(x3 += PhysicalNumber(4, Unit::HOUR))
.CHECK_THROWS(x3 += PhysicalNumber(4, Unit::G))
.CHECK_THROWS(x3 += PhysicalNumber(4, Unit::KG))
.CHECK_THROWS(x3 += PhysicalNumber(4, Unit::TON))


    

.setname("Plus equal compatible dimensions for time")
.CHECK_OUTPUT((x4 += PhysicalNumber(4, Unit::SEC)), "8[sec]")
.CHECK_OK(x4 = PhysicalNumber(4, Unit::SEC))
.CHECK_OUTPUT((x4 += PhysicalNumber(4, Unit::MIN)), "244[sec]")
.CHECK_OK(x4 = PhysicalNumber(4, Unit::SEC))
.CHECK_OUTPUT((x4 += PhysicalNumber(4, Unit::HOUR)), "14404[sec]")
.CHECK_OK(x4 = PhysicalNumber(4, Unit::SEC))
.CHECK_OUTPUT((x5 += PhysicalNumber(4, Unit::SEC)), "4.06668[min]")
.CHECK_OK((x5 = PhysicalNumber(4, Unit::MIN)))
.CHECK_OUTPUT((x5 += PhysicalNumber(4, Unit::MIN)), "8[min]")
.CHECK_OK((x5 = PhysicalNumber(4, Unit::MIN)))
.CHECK_OUTPUT((x5 += PhysicalNumber(4, Unit::HOUR)), "244[min]")
.CHECK_OK(x5 = PhysicalNumber(4, Unit::MIN))
.CHECK_OUTPUT((x6 += PhysicalNumber(4, Unit::SEC)), "4.001111[hour]")
.CHECK_OK((x6 = PhysicalNumber(4, Unit::HOUR)))
.CHECK_OUTPUT((x6 += PhysicalNumber(4, Unit::MIN)), "4.06668[hour]") 
.CHECK_OK((x6 = PhysicalNumber(4, Unit::HOUR)))
.CHECK_OUTPUT((x6 += PhysicalNumber(4, Unit::HOUR)), "8[hour]")
.CHECK_OK(x6 = PhysicalNumber(4, Unit::HOUR))

.setname("Plus equal incompatible dimensions for time")

.CHECK_THROWS(x4 += PhysicalNumber(4, Unit::CM))
.CHECK_THROWS(x4 += PhysicalNumber(4, Unit::M))
.CHECK_THROWS(x4 += PhysicalNumber(4, Unit::KM))
.CHECK_THROWS(x4 += PhysicalNumber(4, Unit::G))
.CHECK_THROWS(x4 += PhysicalNumber(4, Unit::KG))
.CHECK_THROWS(x4 += PhysicalNumber(4, Unit::TON))

.CHECK_THROWS(x5 += PhysicalNumber(4, Unit::CM))
.CHECK_THROWS(x5 += PhysicalNumber(4, Unit::M))
.CHECK_THROWS(x5 += PhysicalNumber(4, Unit::KM))
.CHECK_THROWS(x5 += PhysicalNumber(4, Unit::G))
.CHECK_THROWS(x5 += PhysicalNumber(4, Unit::KG))
.CHECK_THROWS(x5 += PhysicalNumber(4, Unit::TON))

.CHECK_THROWS(x6 += PhysicalNumber(4, Unit::CM))
.CHECK_THROWS(x6 += PhysicalNumber(4, Unit::M))
.CHECK_THROWS(x6 += PhysicalNumber(4, Unit::KM))
.CHECK_THROWS(x6 += PhysicalNumber(4, Unit::G))
.CHECK_THROWS(x6 += PhysicalNumber(4, Unit::KG))
.CHECK_THROWS(x6 += PhysicalNumber(4, Unit::TON))

.setname("Plus equal compatible dimensions for mass")
.CHECK_OUTPUT((x7 += PhysicalNumber(4, Unit::G)), "8[g]")
.CHECK_OK(x7 = PhysicalNumber(4, Unit::G))
.CHECK_OUTPUT((x7 += PhysicalNumber(4, Unit::KG)), "4004[g]")
.CHECK_OK(x7 = PhysicalNumber(4, Unit::G))
.CHECK_OUTPUT((x7 += PhysicalNumber(4, Unit::TON)), "4000004[g]")
.CHECK_OK(x7 = PhysicalNumber(4, Unit::G))
.CHECK_OUTPUT((x8 += PhysicalNumber(4, Unit::G)), "4.004[kg]")
.CHECK_OK((x8 = PhysicalNumber(4, Unit::KG)))
.CHECK_OUTPUT((x8 += PhysicalNumber(4, Unit::KG)), "8[kg]")
.CHECK_OK((x8 = PhysicalNumber(4, Unit::KG)))
.CHECK_OUTPUT((x8 += PhysicalNumber(4, Unit::TON)), "4004[kg]")
.CHECK_OK(x8 = PhysicalNumber(4, Unit::KG))
.CHECK_OUTPUT((x9 += PhysicalNumber(4, Unit::G)), "4.000004[ton]")
.CHECK_OK((x9 = PhysicalNumber(4, Unit::TON)))
.CHECK_OUTPUT((x9 += PhysicalNumber(4, Unit::KG)), "4.004[ton]") 
.CHECK_OK((x9 = PhysicalNumber(4, Unit::TON)))
.CHECK_OUTPUT((x9 += PhysicalNumber(4, Unit::TON)), "8[ton]") 
.CHECK_OK(x9 = PhysicalNumber(4, Unit::TON))

.setname("Plus equal incompatible dimensions for mass")

.CHECK_THROWS(x7 += PhysicalNumber(4, Unit::SEC))
.CHECK_THROWS(x7 += PhysicalNumber(4, Unit::MIN))
.CHECK_THROWS(x7 += PhysicalNumber(4, Unit::HOUR))
.CHECK_THROWS(x7 += PhysicalNumber(4, Unit::CM))
.CHECK_THROWS(x7 += PhysicalNumber(4, Unit::M))
.CHECK_THROWS(x7 += PhysicalNumber(4, Unit::KM))

.CHECK_THROWS(x8 += PhysicalNumber(4, Unit::SEC))
.CHECK_THROWS(x8 += PhysicalNumber(4, Unit::MIN))
.CHECK_THROWS(x8 += PhysicalNumber(4, Unit::HOUR))
.CHECK_THROWS(x8 += PhysicalNumber(4, Unit::CM))
.CHECK_THROWS(x8 += PhysicalNumber(4, Unit::M))
.CHECK_THROWS(x8 += PhysicalNumber(4, Unit::KM))

.CHECK_THROWS(x9 += PhysicalNumber(4, Unit::SEC))
.CHECK_THROWS(x9 += PhysicalNumber(4, Unit::MIN))
.CHECK_THROWS(x9 += PhysicalNumber(4, Unit::HOUR))
.CHECK_THROWS(x9 += PhysicalNumber(4, Unit::CM))
.CHECK_THROWS(x9 += PhysicalNumber(4, Unit::M))
.CHECK_THROWS(x9 += PhysicalNumber(4, Unit::KM))



  
.setname("Minus equal compatible dimensions for meters")
.CHECK_OUTPUT((x1 -= PhysicalNumber(4, Unit::CM)), "0[cm]")
.CHECK_OK(x1 = PhysicalNumber(4, Unit::CM))
.CHECK_OUTPUT((x1 -= PhysicalNumber(4, Unit::M)), "-396[cm]")
.CHECK_OK(x1 = PhysicalNumber(4, Unit::CM))
.CHECK_OUTPUT((x1 -= PhysicalNumber(4, Unit::KM)), "-399996[cm]")
.CHECK_OK(x1 = PhysicalNumber(4, Unit::CM))
.CHECK_OUTPUT((x2 -= PhysicalNumber(4, Unit::CM)), "3.96[m]")
.CHECK_OK(x2 = PhysicalNumber(4, Unit::M))
.CHECK_OUTPUT((x2 -= PhysicalNumber(4, Unit::M)), "0[m]")
.CHECK_OK(x2 = PhysicalNumber(4, Unit::M))
.CHECK_OUTPUT((x2 -= PhysicalNumber(4, Unit::KM)), "-3996[m]")
.CHECK_OK(x2 = PhysicalNumber(4, Unit::M))
.CHECK_OUTPUT((x3 -= PhysicalNumber(4, Unit::CM)), "3.99996[km]")
.CHECK_OK(x3 = PhysicalNumber(4, Unit::KM))
.CHECK_OUTPUT((x3 -= PhysicalNumber(4, Unit::M)), "3.996[km]") 
.CHECK_OK(x3 = PhysicalNumber(4, Unit::KM))
.CHECK_OUTPUT((x3 -= PhysicalNumber(4, Unit::KM)), "0[km]") 
.CHECK_OK(x3 = PhysicalNumber(4, Unit::KM))   

.setname("Minus equal incompatible dimensions for meters")

.CHECK_THROWS(x1 -= PhysicalNumber(4, Unit::SEC))
.CHECK_THROWS(x1 -= PhysicalNumber(4, Unit::MIN))
.CHECK_THROWS(x1 -= PhysicalNumber(4, Unit::HOUR))
.CHECK_THROWS(x1 -= PhysicalNumber(4, Unit::G))
.CHECK_THROWS(x1 -= PhysicalNumber(4, Unit::KG))
.CHECK_THROWS(x1 -= PhysicalNumber(4, Unit::TON))

.CHECK_THROWS(x2 -= PhysicalNumber(4, Unit::SEC))
.CHECK_THROWS(x2 -= PhysicalNumber(4, Unit::MIN))
.CHECK_THROWS(x2 -= PhysicalNumber(4, Unit::HOUR))
.CHECK_THROWS(x2 -= PhysicalNumber(4, Unit::G))
.CHECK_THROWS(x2 -= PhysicalNumber(4, Unit::KG))
.CHECK_THROWS(x2 -= PhysicalNumber(4, Unit::TON))

.CHECK_THROWS(x3 -= PhysicalNumber(4, Unit::SEC))
.CHECK_THROWS(x3 -= PhysicalNumber(4, Unit::MIN))
.CHECK_THROWS(x3 -= PhysicalNumber(4, Unit::HOUR))
.CHECK_THROWS(x3 -= PhysicalNumber(4, Unit::G))
.CHECK_THROWS(x3 -= PhysicalNumber(4, Unit::KG))
.CHECK_THROWS(x3 -= PhysicalNumber(4, Unit::TON))


    
      
.setname("Minus equal compatible dimensions for time")
.CHECK_OUTPUT((x4 -= PhysicalNumber(4, Unit::SEC)), "0[sec]")
.CHECK_OK(x4 = PhysicalNumber(4, Unit::SEC))
.CHECK_OUTPUT((x4 -= PhysicalNumber(4, Unit::MIN)), "-236[sec]")
.CHECK_OK(x4 = PhysicalNumber(4, Unit::SEC))
.CHECK_OUTPUT((x4 -= PhysicalNumber(4, Unit::HOUR)), "-14396[sec]")
.CHECK_OK(x4 = PhysicalNumber(4, Unit::SEC))
.CHECK_OUTPUT((x5 -= PhysicalNumber(4, Unit::SEC)), "3.93332[min]")
.CHECK_OK((x5 = PhysicalNumber(4, Unit::MIN)))
.CHECK_OUTPUT((x5 -= PhysicalNumber(4, Unit::MIN)), "0[min]")
.CHECK_OK((x5 = PhysicalNumber(4, Unit::MIN)))
.CHECK_OUTPUT((x5 -= PhysicalNumber(4, Unit::HOUR)), "-236[min]")
.CHECK_OK(x5 = PhysicalNumber(4, Unit::MIN))
.CHECK_OUTPUT((x6 -= PhysicalNumber(4, Unit::SEC)), "3.998889[hour]")
.CHECK_OK((x6 = PhysicalNumber(4, Unit::HOUR)))
.CHECK_OUTPUT((x6 -= PhysicalNumber(4, Unit::MIN)), "3.93332[hour]") 
.CHECK_OK((x6 = PhysicalNumber(4, Unit::HOUR)))
.CHECK_OUTPUT((x6 -= PhysicalNumber(4, Unit::HOUR)), "0[hour]")
.CHECK_OK(x6 = PhysicalNumber(4, Unit::HOUR))

.setname("Minus equal incompatible dimensions for time")

.CHECK_THROWS(x4 -= PhysicalNumber(4, Unit::CM))
.CHECK_THROWS(x4 -= PhysicalNumber(4, Unit::M))
.CHECK_THROWS(x4 -= PhysicalNumber(4, Unit::KM))
.CHECK_THROWS(x4 -= PhysicalNumber(4, Unit::G))
.CHECK_THROWS(x4 -= PhysicalNumber(4, Unit::KG))
.CHECK_THROWS(x4 -= PhysicalNumber(4, Unit::TON))

.CHECK_THROWS(x5 -= PhysicalNumber(4, Unit::CM))
.CHECK_THROWS(x5 -= PhysicalNumber(4, Unit::M))
.CHECK_THROWS(x5 -= PhysicalNumber(4, Unit::KM))
.CHECK_THROWS(x5 -= PhysicalNumber(4, Unit::G))
.CHECK_THROWS(x5 -= PhysicalNumber(4, Unit::KG))
.CHECK_THROWS(x5 -= PhysicalNumber(4, Unit::TON))

.CHECK_THROWS(x6 -= PhysicalNumber(4, Unit::CM))
.CHECK_THROWS(x6 -= PhysicalNumber(4, Unit::M))
.CHECK_THROWS(x6 -= PhysicalNumber(4, Unit::KM))
.CHECK_THROWS(x6 -= PhysicalNumber(4, Unit::G))
.CHECK_THROWS(x6 -= PhysicalNumber(4, Unit::KG))
.CHECK_THROWS(x6 -= PhysicalNumber(4, Unit::TON))


  
.setname("Minus equal compatible dimensions for mass")
.CHECK_OUTPUT((x7 -= PhysicalNumber(4, Unit::G)), "0[g]")
.CHECK_OK(x7 = PhysicalNumber(4, Unit::G))
.CHECK_OUTPUT((x7 -= PhysicalNumber(4, Unit::KG)), "-3996[g]")
.CHECK_OK(x7 = PhysicalNumber(4, Unit::G))
.CHECK_OUTPUT((x7 -= PhysicalNumber(4, Unit::TON)), "-3999996[g]")
.CHECK_OK(x7 = PhysicalNumber(4, Unit::G))
.CHECK_OUTPUT((x8 -= PhysicalNumber(4, Unit::G)), "3.996[kg]")
.CHECK_OK((x8 = PhysicalNumber(4, Unit::KG)))
.CHECK_OUTPUT((x8 -= PhysicalNumber(4, Unit::KG)), "0[kg]")
.CHECK_OK((x8 = PhysicalNumber(4, Unit::KG)))
.CHECK_OUTPUT((x8 -= PhysicalNumber(4, Unit::TON)), "-3996[kg]")
.CHECK_OK(x8 = PhysicalNumber(4, Unit::KG))
.CHECK_OUTPUT((x9 -= PhysicalNumber(4, Unit::G)), "3.999996[ton]")
.CHECK_OK((x9 = PhysicalNumber(4, Unit::TON)))
.CHECK_OUTPUT((x9 -= PhysicalNumber(4, Unit::KG)), "3.996[ton]") 
.CHECK_OK((x9 = PhysicalNumber(4, Unit::TON)))
.CHECK_OUTPUT((x9 -= PhysicalNumber(4, Unit::TON)), "0[ton]") 
.CHECK_OK(x9 = PhysicalNumber(4, Unit::TON))

.setname("Minus equal incompatible dimensions for mass")

.CHECK_THROWS(x7 -= PhysicalNumber(4, Unit::SEC))
.CHECK_THROWS(x7 -= PhysicalNumber(4, Unit::MIN))
.CHECK_THROWS(x7 -= PhysicalNumber(4, Unit::HOUR))
.CHECK_THROWS(x7 -= PhysicalNumber(4, Unit::CM))
.CHECK_THROWS(x7 -= PhysicalNumber(4, Unit::M))
.CHECK_THROWS(x7 -= PhysicalNumber(4, Unit::KM))

.CHECK_THROWS(x8 -= PhysicalNumber(4, Unit::SEC))
.CHECK_THROWS(x8 -= PhysicalNumber(4, Unit::MIN))
.CHECK_THROWS(x8 -= PhysicalNumber(4, Unit::HOUR))
.CHECK_THROWS(x8 -= PhysicalNumber(4, Unit::CM))
.CHECK_THROWS(x8 -= PhysicalNumber(4, Unit::M))
.CHECK_THROWS(x8 -= PhysicalNumber(4, Unit::KM))

.CHECK_THROWS(x9 -= PhysicalNumber(4, Unit::SEC))
.CHECK_THROWS(x9 -= PhysicalNumber(4, Unit::MIN))
.CHECK_THROWS(x9 -= PhysicalNumber(4, Unit::HOUR))
.CHECK_THROWS(x9 -= PhysicalNumber(4, Unit::CM))
.CHECK_THROWS(x9 -= PhysicalNumber(4, Unit::M))
.CHECK_THROWS(x9 -= PhysicalNumber(4, Unit::KM))



      .print(cout, /*show_grade=*/false);
      grade = testcase.grade();
    } else {
      testcase.print_signal(signal);
      grade = 0;
    }
    cout <<  "*** Grade: " << grade << " ***" << endl;
    return grade;
}
