#include "resol.hpp"

// Resolution pour une matrice pleine
void resysLin_plein(matrix l, matrix u, rvec b, rvec& x){

  // Goal is to have the missing vector x --> from the equation Ax=b
  // 1st case : Solve LY=B

  rvec y (l.size(),0.) ;

  for (int k = 0; k < l.size(); k++) {
    if (k==0){
      y[0] = b[0]/l[k][k] ;
    }
    else {
      for (int i = 0; i < k; i++) {
        y[k] = y[k] + l[k][i] * y[i] ;
      }
      y[k] = (b[k] - y[k])/l[k][k] ;
    }
  }

  // 2nd case : Solve UX = Y
  
  for (int k = u.size()-1; k > -1; k--) {
    if (k == u.size()-1){
      x[k] = y[k]/u[k][k] ;
    }
    else {
      for (int i = u.size()-1; i > k; i--) {
        x[k] = x[k] + u[k][i] * x[i] ;
      }
      x[k] = (y[k] - x[k])/u[k][k] ;
    }
  }
}
   


