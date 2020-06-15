#include "decompoLU.hpp"
#include <cmath>

// Initialisation des matrices à prendre avant d'appeler la fonction
// matrix a(M, rvec(M)); matrix U (M, rvec (M)); matrix L (M, rvec (M));
void Decomp_LU_plein (matrix a, matrix& u, matrix& l){

  affectation_pleine_id(l) ;
  affectation_pleine(a, u) ;

  for (uint k = 0 ; k<u.size()-1 ; k++){
    for (uint i = k+1 ; i<u.size() ; i++){
      l[i][k] = u[i][k]/u[k][k] ;
      for (uint j=k ; j<u.size() ; j++)
        u[i][j] = u[i][j]-l[i][k]*u[k][j] ;
    }
  }
}

// Decomposition LU pleine adaptée à la matrice A qui est nulle sous la diagonale j-i=-(m-1) et 
// au-dessus de la diagonale j-i=m-1
// Valeurs des matrices à prendre avant d'appeler la fonction
// matrix U (M, rvec (M)); matrix L (M, rvec (M))
void Decomp_LU_adapte_plein (matrix a, matrix& u, matrix& l, uint m){
  
  affectation_pleine_id(l) ;
  affectation_pleine(a, u) ;

  for (int k=0 ; k<u.size()-1 ; k++){
    for (int i=k+1 ; i< min_entiers(k+m,u.size()) ; i++){ //les U[i][j] sont nuls pour i>=k+m
      l[i][k] = u[i][k]/u[k][k] ;
      for (int j=k ; j< min_entiers(k+m,u.size()) ; j++){ //les U[k][j] sont nuls pour j>=k+m
        u[i][j] = u[i][j] - l[i][k]*u[k][j] ;
      }
    }
  }
}

// Decomposition LU pivot partiel (Stockage plein pour les matrices)
// Valeurs des matrices à prendre avant d'appeler la fonction
// vector<vector<double>> U (M,vector<double> (M)); vector<vector<double>> L (M,vector<double> (M));
// Remplir avant U avec A et P avec l'identité et L identité aussi
void Decomp_LU_partiel_plein (matrix& u, matrix& l, matrix& p){

  int kp, kmax;
  double temp, temp1, temp2 ;

  for (int k=0 ; k<u.size()-1 ; k++){
    kp=k;
    kmax=kp;
    while(kp<u.size()-1){
      kp+=1;
      if(abs(u[kp][k])>abs(u[kmax][k])){
        kmax=kp;
      }
    }
    if(kmax!=k){
      for (int j = 0; j < u.size(); j++) {
        //on échange les lignes k et kmax de u
        temp = u[k][j] ;
        u[k][j] = u[kmax][j] ;
        u[kmax][j] = temp ;
        //on échange les lignes k et kmax de p
        temp1 = p[k][j] ;
        p[k][j] = p[kmax][j] ;
        p[kmax][j] = temp1 ;
        //on échange les lignes k et kmax de l sous la diagonale
        if (j < k){
          temp2 = l[k][j] ;
          l[k][j] = l[kmax][j] ;
          l[kmax][j] = temp2 ;
        }
      }
    }
    for (int i=k+1 ; i<u.size() ; i++){
      l[i][k]=u[i][k]/u[k][k];
      for (int j=k ; j<u.size() ; j++){
        u[i][j]= u[i][j] - l[i][k]*u[k][j] ;
      }
    }
  }
}
