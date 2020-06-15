#include "testDirectMethods.hpp"
#include "testIteratMethods.hpp"
#include "erreurResidu.hpp"
#include "decompoLU.hpp"

#include <stdio.h>
#include <time.h>
#include <fstream>
#include <iostream>
#include <cmath>

using std::ofstream ;
using std::cout ;
using std::endl ;

int main() {

  // Filling the testMatrix 
  matrix mat(4,rvec(4, 0.)) ;

  mat[0][0] = 1. ;
  mat[0][1] = 2. ;
  mat[0][2] = 1. ;
  mat[0][3] = 2. ;
  mat[1][0] = 2. ;
  mat[1][1] = 2. ;
  mat[1][2] = 3. ;
  mat[1][3] = 4. ;
  mat[2][0] = -1. ;
  mat[2][1] = -3. ;
  mat[2][2] = 0.e0 ;
  mat[2][3] = 13. ;
  mat[3][0] = 1. ;
  mat[3][1] = -4 ;
  mat[3][2] = 23 ;
  mat[3][3] = 1 ;

  // Display the testMatrix
  display_plein(mat) ;

  cout << endl ;

  // Filling the second member b
  rvec b(mat.size(), 0.) ;

  b[0] = -4. ;
  b[1] = 9. ;
  b[2] = -8. ;

  // Test Linear Solvers

  matrix L(mat.size(), rvec(mat.size(), 0.)) ; // Initialisation of L
  matrix U(mat.size(), rvec(mat.size(), 0.)) ; // Iniatialisation of U

  display_plein(U) ;

  cout << endl ;

  display_plein(L) ;






  /*

  uint n, m ;

  double h, k ;
  double a = 1. , b = 1. ;

  double alpha = 0. ;
  double w = 1.2 ;

  // h = q / n ;
  // k = r / m ;

  // matrix a ((n-1)*(m-1),rvec((n-1)*(m-1),0.)) ;
  // matrix a_b ((2*m)-1, rvec((n-1)*(m-1),0.));
  // remplissage_A_plein(a,alpha,n,m,h,k) ;
  // display_plein(a) ;

  // cout << endl ;

  // rvec b (a.size(),0.) ;
  // rvec x (a.size(),0.);

  // second_membre (n, m, q, r, h, k, alpha, b) ;

  // cout << "Second membre : " << endl ;
  // for (int i = 0; i < b.size(); i++) {
  //   cout << "B[" << i << "]= " << b[i] << endl ;
  // }
  // cout << endl ;

  // cout << "Vecteur solution X = " << endl ;
  // for (int i = 0; i < a.size(); i++) {
  //   cout << x[i] << endl ;
  // }
  //
  // cout << "erreur = " << erreur_2(n,m,h,k,x) << endl ;

  float temps, cpt = 0.e0 ;
  clock_t t1, t2 ;

  ofstream of ;
  ofstream off ;
  ofstream offf ;
  ofstream offff ;
  ofstream offfff ;
  ofstream offffff ;

  of.open("residu2_jacobi.dat") ;
  off.open("residuinf_jacobi.dat") ;
  // offf.open(".dat") ;
  // offff.open(".dat") ;
  // offfff.open(".dat") ;
  // offffff.open(".dat") ;

  for (uint i = 1u ; i < 8 ; i++) {

    n = pow(2,i) ;
    m = pow(2,i) ;
    h = a/n ;
    k = b/m ;

    matrix q ((n-1)*(m-1), rvec((n-1)*(m-1),0.)) ;

    remplissage_A_plein(q,alpha,n,m,h,k) ;
    cout << "remplissage de A fini" << endl ;

    rvec r (q.size(),0.) ;
    rvec x (q.size(),0.) ;

    second_membre (n, m, a, b, h, k, alpha, r) ;
    cout<<"remplissage de B fini"<<endl;

    t1 = clock() ;

    //test_LU_plein(a,b,x) ; //
    //
    // test_LU_plein_adaptee(a,b,x,m) ; //
    //
    // test_LU_partiel_plein(a,b,x) ; //
    //
    // test_choleski_plein(a,b,x) ; //
    //
    //test_choleski_plein_adaptee(a,b,x,m) ; //
    //
    // test_choleski_v2_plein(a,b,x) ; //
    //
    // test_choleski_v2_plein_adaptee(a,b,x,m) ; //
    //
    //SOR_plein(a, b, x, w, 100, 1e-10, cpt_SOR) ; //
    //
    // jacobi_plein(a, b, x, 100, 1e-10, cpt_Jaco) ; //

    t2 = clock() ;

    temps = (float)(t2-t1)/CLOCKS_PER_SEC ;
    cout << "test fini" << endl ;

    // cout << "Temps = " << temps << endl ;
    // of << log10(n) << " " << log10(temps) << endl ;

    double residu2 = residu_2_plein(r,q,x) ;
    cout << "Residu 2 plein = " << residu2 << endl ;
    of << log10(n) << " " << log10(residu2) << endl ;

    double residuinf = residu_inf_plein(r,q,x) ;
    cout << "Residu inf plein = " << residuinf << endl ;
    off << log10(n) << " " << log10(residuinf) << endl ;

    // double erreur2 = erreur_2(n,m,h,k,x);
    // cout << "erreur_2 = " << erreur2 << endl ;
    // off << log10(n) << " " << log10(erreur2) << endl ;

    // double erreurinf = erreur_inf(n,m,h,k,x);
    // cout << "erreur_inf = " << erreurinf << endl ;
    // offfff << 2*log10(n) << " " << log10(erreurinf) << endl ;
    //
    // cout << "Nombre iterations SOR = " << cpt_SOR << endl ;
    // offffff << cpt_SOR << endl ;

    cout << endl ;
  }

   of.close() ;
   off.close() ;
   // offf.close() ;
   // offff.close() ;
   // offfff.close() ;
   // offffff.close() ;

   */

  return 0;
}
