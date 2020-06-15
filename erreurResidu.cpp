#include "erreurResidu.hpp"
#include <cmath>

// Erreur en 2
// X solution trouvée (appelé U dans le sujet)
double erreur_2 (uint n, uint m, double h, double k, rvec X){
  double E_2 = 0. ;
  for (double i=1 ; i<n ; i++){
    for(double j=1 ; j<m ; j++){
      //cout << "solexa = " << sol(i*h,j*k) << endl ;
      //cout << "sol = " << X[(i-1)*(m-1)+(j-1)] << endl ;
        E_2 += h*k*(pow(sol(i*h,j*k)-X[(i-1)*(m-1)+(j-1)],2)) ;   //u ij est l'élément d'indice (i-1)(m-1)+(j-1) dans X
    }
  }
  E_2 = sqrt(E_2);
  return E_2;
}


// Erreur en l'infini
// X solution trouvée (appelé U dans le sujet)
double erreur_inf (int n, int m, double h, double k, rvec X){
  double e = 0. ;
  double e1 = 0. ;
  for (int i=1 ; i<n+1 ; i++){
    for (int j=1 ; j<m+1 ; j++){
      e = fabs(sol(i*h,j*k)-X[(i-1)*(m-1)+(j-1)]) ;
      if (e > e1){
        e1 = e ;   //u ij est l'élément d'indice (i-1)(m-1)+(j-1) dans X
      }
    }
  }
  return e1 ;
}

// Residu 2 plein
double residu_2_plein (rvec B, matrix A, rvec X){
  double res=0.0;

  for (int i=0; i<X.size();i++){
    res+=pow(B[i]-produit_mat_vec_plein(A,X)[i],2);
  }
  return sqrt(res);
}


// Residu infini plein
double residu_inf_plein (rvec B, matrix A, rvec X){
  double res=0.0, test;

  for (int i=0; i<X.size();i++){
    test = fabs(B[i]-produit_mat_vec_plein(A,X)[i]);
    if(test>res){
      res = test ;
    }
  }
  return res;
}
