#include "iteratif.hpp"

//Méthodes itératives

//le x0 de départ est à mettre dans x en paramètre
void SOR_plein (matrix A, rvec b, rvec& x, double w, uint k_max, double eps, uint& k){
  k = 0 ;
  rvec xk = x ;
  rvec erreur (x.size(),1.);
  double somme ;
  while (k<k_max && norm(erreur)/norm(xk)>eps) {
    k+=1 ;
    for (int i=0; i<A.size();i++){
      somme = 0 ;
      for (int j=0;j<A.size();j++){
        if(j>i){
        somme += A[i][j]*x[j];
        }
        else if(j<i){
          somme += A[i][j]*xk[j] ;
        }
      }
      xk[i] = (1-w)*x[i]+(w/A[i][i])*(b[i]-somme) ;
    }
    for (int i = 0; i < x.size(); i++) {
      erreur[i] = xk[i] - x[i];
    }
    x=xk;
  }
}

//le x0 de départ est à mettre dans x en paramètre
void jacobi_plein (matrix A, rvec b, rvec & x, uint k_max, double eps, uint& k){

  k=0 ;
  double somme ;

  rvec xk = x ;
  rvec erreur (x.size(),1.) ;

  while (k<k_max && norm(erreur)/norm(xk) > eps){
    k+=1;
    for (int i=0; i<A.size();i++){
      somme=0;
      for (int j=0;j<A.size();j++){
        if(j!=i){
          somme+=A[i][j]*x[j];
        }
      }
      xk[i]=(b[i]-somme)/A[i][i];
    }
    for (int i = 0; i < x.size(); i++) {
      erreur[i] = xk[i] - x[i];
    }
    x = xk ;
  }
}
