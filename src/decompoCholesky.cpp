#include "decompoCholesky.hpp"
#include <cmath>

// Decomposition de Choleski (A=SS_T) basique en utilisant le fait que S_T = (1/sqrt(D))*U
// vector<vector<double>> S_T (M,vector<double> (M)) ;
// Remplir avant S^T avec A
void Decomp_choleski_plein (matrix& s){
  double inter;
  double d;

  for(int k=0 ; k<s.size()-1 ; k++){
    for(int i=k+1 ; i<s.size() ; i++){
      inter=s[i][k]/s[k][k];

      for(int j=k; j<s.size() ; j++){
        s[i][j]=s[i][j]-inter*s[k][j];
      }
    }
    d=s[k][k];
    for(int i = k ; i<s.size() ; i++){
      s[k][i]=(1/sqrt(d))*s[k][i];
    }
  }
  s[s.size()-1][s.size()-1]=(1/sqrt(s[s.size()-1][s.size()-1]))*s[s.size()-1][s.size()-1];
}

// Decomposition de Choleski (A=SS^T) en utilisant le fait que S^T = (1/sqrt(D))*U ET adaptée à notre matrice A
// avec A en stockage plein
// vector<vector<double>> S^T (M,vector<double> (M));
// Remplir avant S^T avec A
void Decomp_choleski_adapte_plein (matrix& s, uint m){
  double inter;
  double d;

  for(int k=0 ; k<s.size()-1 ; k++){
    for(int i=k+1 ; i<min_entiers(k+m,s.size()) ; i++){
      inter=s[i][k]/s[k][k];

      for(int j=k; j<min_entiers(k+m,s.size()) ; j++){
        s[i][j]=s[i][j]-inter*s[k][j];
      }
    }
    d=s[k][k];
    for(int i = k ; i<min_entiers(k+m,s.size()) ; i++){
      s[k][i]=(1/sqrt(d))*s[k][i];
    }
  }

  s[s.size()-1][s.size()-1]=(1/sqrt(s[s.size()-1][s.size()-1]))*s[s.size()-1][s.size()-1];

}

// Decomposition de Choleski (A=SS^T) basique avec une formule pour les coefficients diagonaux de S et 
// une autre pour le reste des coefficients de S
// vector<vector<double>> S (M,vector<double> (M));
void Decomp_choleski_v2_plein (matrix a, matrix& s){
  double somme = 0 ;
  for (int j = 0 ; j<a.size() ; j++){
    somme = 0 ;
    for(int k=0; k<j ; k++){
      somme+=(pow(s[j][k],2)) ; //normalement on prend le module de s[j][k]
    }
    s[j][j]=sqrt(a[j][j]-somme);

    for(int i=j+1 ; i<a.size() ; i++){
      somme=0;
      for (int k=0 ; k<j ; k++){
        somme+=s[i][k]*s[j][k]; //normalement c'est le conjugué de sjk
      }
      s[i][j]=(1/s[j][j])*(a[i][j]-somme);
    }
  }
}

// Decomposition de Choleski (A=SS^T) avec une formule pour les coefficients diagonaux de S et 
// une autre pour le reste des coefficients de S
// adaptée à la matrice A avec A stockée en stockage plein
// vector<vector<double>> S (M,vector<double> (M));
void Decomp_choleski_v2_adapte_plein (matrix a, matrix& s, uint m){
  double somme = 0 ;
  for (int j=0 ; j<a.size() ; j++){
    somme=0;
    for(int k=0; k<j ; k++){
      if(k>=j-m+1){
        somme+=pow((s[j][k]),2) ; //normalement on prend le module de s[j][k]
      }
    }
    s[j][j]=sqrt(a[j][j]-somme);

    for(int i=j+1 ; i< min_entiers(j+m,s.size()) ; i++){
      somme=0;
      for (int k=0 ; k<j ; k++){
        if(k>=-m+1+j & k>=-m+1+i){
          somme+=s[i][k]*s[j][k]; //normalement c'est le conjugué de sjk
        }
      }
      s[i][j]=(1/s[j][j])*(a[i][j]-somme) ;
    }
  }
}