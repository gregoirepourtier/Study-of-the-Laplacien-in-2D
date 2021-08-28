#include "tools.hpp"
#include <iostream>
#include <cmath>

using std::cout ;
using std::endl ;

// Fonction pour transposer la matrice
void transpose_plein(matrix& a){
  matrix b (a.size(), rvec (a.size(),0.)) ;
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < a.size(); j++)
      b[i][j] = a[i][j] ;
  }
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < a.size(); j++)
      a[i][j] = b[j][i] ;
  }
}


// Remplie de façon "plein" la matrice A
void remplissage_A_plein(matrix& a, double alpha, uint n, uint m, double h, double k) {
  
  for (int i = 0 ; i < a.size(); i++) {
    a[i][i] = ((2*(pow(h,2)+pow(k,2)))/((pow(h,2)*pow(k,2))))+alpha ;
    for (int j = i+1; j < a.size(); j++) {
      if (j == i+1 & (j%(n-1))!= 0) {
        a[i][j] = (-1/(pow(k,2))) ;
        a[j][i] = (-1/(pow(k,2))) ;
      }
      else if (j == (i+m-1)) {
        a[i][j] = (-1/(pow(h,2))) ;
        a[j][i] = (-1/(pow(h,2))) ;
      }
    }
  }
}

// Affiche les matrices pleines
void display_plein(matrix a) {
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < a.size(); j++)
      cout << a[i][j] << " " ;
    cout << endl ;
  }
}

// Fonction max entiers
int max_entiers(int a, int b){
  if(a<b)
    return b;
  else
    return a;
}

// Fonction min entiers
int min_entiers(int a, int b){
  if(a>b)
    return b;
  else
    return a;
}

// Produit matrice-matrice avec des matrices en stockage plein, renvoie la matrice résultat en stockage plein
matrix produit_mat_mat_plein (matrix a, matrix b){
  matrix res (a.size(), rvec (a.size(),0.)) ;
  for (int i=0;i<a.size();i++){
    for (int j=0;j<a.size();j++){
      for (int k=0;k<a.size();k++)
        res[i][j]=a[i][k]*b[k][j]+res[i][j] ;
  	}
  }
  return res ;
}

// Produit matrice-vecteur avec une matrice en stockage plein
rvec produit_mat_vec_plein(matrix a, rvec x){
  rvec res(a.size(), 0.) ;
  for (int k=0; k<a.size();k++){ // k parcours les lignes du tableau a
    for (int j=0; j<a[0].size();j++)
      res[k] += a[k][j]*x[j] ;
  }
  return res ;
}

// U = A (stockage plein)
void affectation_pleine (matrix a ,matrix& u){
  for (int i=0 ; i<a.size() ; i++){
    for (int j=0 ; j<a.size() ; j++)
      u[i][j] = a[i][j] ;
  }
}

// L = Id (stockage plein)
void affectation_pleine_id (matrix& l){
  for (int i=0 ; i<l.size() ; i++){
    for (int j=0 ; j<l.size() ; j++){
      if(i==j)
        l[i][j]=1 ;
      else
        l[i][j]=0 ;
    }
  }
}

double norm(rvec x) {
  double norm = 0. ;
  for (int i = 0; i < x.size(); i++)
    norm += pow(x[i],2) ;
  return sqrt(norm) ;
}

// Création du second membre
// vector<double> second_membre(int n, int m,double alpha){
//      vector<double> B(n*m,0.) ;
//
//      double h = 1./n ;
//      double k = 1./m ;
//
//     for (int i=1; i<n;i++){
//       for(int j=1;j<m;j++){
//         B[(i-1)*m+j-1] = f(i*h, j*k, alpha);
//         if (i==1){
//           B[(i-1)*m+j-1] += g((i-1)*h,j*k)/pow(h,2);
//         }
//         if (i==n){
//           B[(i-1)*m+j-1]+= g((i+1)*h,j*k)/pow(h,2);
//         }
//         if (j==1){
//           B[(i-1)*m+j-1]+= g(i*h,(j-1)*k)/pow(k,2);
//         }
//         if (j==m){
//           B[(i-1)*m+j-1]+= g(i*h,(j+1)*k)/pow(k,2);
//         }
//       }
//     }
//     return B ;
// }

void second_membre (uint n, uint m, double a, double b, double h, double k, double alpha, rvec& B){
    int l = 0 ;

    for (int i=1; i<n;i++){
      for(int j=1;j<m;j++){
        B[l]=f(i*h, j*k, alpha);
        if (i==1)
          B[l]+= g(0,j*k)/pow(h,2);
        if (i==n-1)
          B[l]+= g(a,j*k)/pow(h,2);
        if (j==1)
          B[l]+= g(i*h,0)/pow(k,2);
        if (j==m-1)
          B[l]+= g(i*h,b)/pow(k,2);
        l+=1;
      }
    }
}


//foncton solution sol(x,y)=u(x,y)
double sol(double x, double y){
  return sin(x*y);
}

// fonctions f et g
double f (double x, double y, double alpha){
  double res;
  res = (pow(x,2) + pow(y,2) + alpha)*sin(x*y);
  return res ;
}

double g (double x, double y){
  double res;
  res=sin(x*y);
  return res ;
}
