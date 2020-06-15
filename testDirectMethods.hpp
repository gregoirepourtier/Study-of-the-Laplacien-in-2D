#ifndef _TESTDIRECTMETHODS_HPP_
#define _TESTDIRECTMETHODS_HPP_

#include "tools.hpp"

// Test decomposition LU plein
void test_LU_plein(matrix a, rvec b, rvec& x) ;

// Test decomposition LU adaptée plein
void test_LU_plein_adaptee(matrix a, rvec b, rvec& x, uint m) ;

// Test decomposition LU pivot partiel
void test_LU_partiel_plein(matrix a, rvec b, rvec& x) ;



// Test decomposition de Choleski plein
void test_choleski_plein(matrix a, rvec b, rvec& x) ;

// Test decomposition de Choleski adaptée plein
void test_choleski_plein_adaptee(matrix a, rvec b, rvec& x, uint m) ;

// Test decomposition de Choleski plein v2
void test_choleski_v2_plein(matrix a, rvec b, rvec& x) ;

// Test decomposition de Choleski adaptée plein v2
void test_choleski_v2_plein_adaptee(matrix a, rvec b, rvec& x, uint m) ;


#endif // _TESTDIRECTMETHODS_HPP_