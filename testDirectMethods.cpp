#include "testDirectMethods.hpp"
#include "decompoLU.hpp"
#include "decompoCholesky.hpp"
#include "resol.hpp"

void test_LU_plein(matrix a, rvec b, rvec& x){

  matrix l (a.size(), rvec(a.size(),0.));
  matrix u (a.size(), rvec(a.size(),0.));

  Decomp_LU_plein (a, u, l) ;

  // cout << "Affichage de la matrice U : " << endl ;
  // display_plein(u) ;

  //cout << endl ;

  //cout << "Affichage de la matrice L : " << endl ;
  //display_plein(l) ;

  //cout << endl ;

  // display_plein(produit_mat_mat_plein(l,u)) ;

  resysLin_plein(l,u,b,x) ;
  // cout << "Vecteur solution X = " << endl ;
  // for (int i = 0; i < a.size(); i++) {
  //   cout << x[i] << endl ;
  // }
  // cout << endl ;
  // cout << "Vérification AX=B : " << endl ;
  // for (int i = 0; i < a.size(); i++) {
  //   cout << "B[" << i << "]= " << produit_mat_vec_plein(a,x)[i] << endl  ;
  // }
}


void test_LU_plein_adaptee(matrix a, rvec b, rvec& x, int m){
  matrix l (a.size(), rvec(a.size(),0.));
  matrix u (a.size(), rvec(a.size(),0.));

  affectation_pleine(a,u) ;
  affectation_pleine_id(l) ;
  
  Decomp_LU_adapte_plein (u,l,m) ;

  // cout << "Affichage de la matrice U : " << endl ;
  // display_plein(u) ;
  //
  // cout << endl ;
  //
  // cout << "Affichage de la matrice L : " << endl ;
  // display_plein(l) ;
  //
  // cout << endl ;

  // display_plein(produit_mat_mat_plein(l,u)) ;

  resysLin_plein(l,u,b,x) ;
  // cout << "Vecteur solution X = " << endl ;
  // for (int i = 0; i < a.size(); i++) {
  //   cout << x[i] << endl ;
  // }
  // cout << endl ;
  // cout << "Vérification AX=B : " << endl ;
  // for (int i = 0; i < a.size(); i++) {
  //   cout << "B[" << i << "]= " << produit_mat_vec_plein(a,x)[i] << endl  ;
  // }
}


void test_LU_partiel_plein(matrix a, rvec b, rvec& x){
  matrix l (a.size(), rvec(a.size(),0.));
  matrix u (a.size(), rvec(a.size(),0.));
  matrix p (a.size(), rvec(a.size(),0.));

  affectation_pleine(a,u) ;
  affectation_pleine_id(l) ;
  Decomp_LU_partiel_plein (u,l,p) ;

  // cout << "Affichage de la matrice U : " << endl ;
  // display_plein(u) ;
  //
  // cout << endl ;
  //
  // cout << "Affichage de la matrice L : " << endl ;
  // display_plein(l) ;
  //
  // cout << endl ;

  // display_plein(produit_mat_mat_plein(l,u)) ;

  resysLin_plein(l,u,b,x) ;
  // cout << "Vecteur solution X = " << endl ;
  // for (int i = 0; i < a.size(); i++) {
  //   cout << x[i] << endl ;
  // }
  // cout << endl ;
  // cout << "Vérification AX=B : " << endl ;
  // for (int i = 0; i < a.size(); i++) {
  //   cout << "B[" << i << "]= " << produit_mat_vec_plein(a,x)[i] << endl  ;
  // }
}


void test_choleski_plein(matrix a, rvec b, rvec& x) {
  matrix s (a.size(), rvec(a.size(),0.));
  matrix st (a.size(), rvec(a.size(),0.));

  affectation_pleine(a,s) ;
  Decomp_choleski_plein(s) ;

  // cout << "Affichage de la matrice S^t : " << endl ;
  // display_plein(s) ;
  //
  // cout << endl ;

  affectation_pleine(s,st) ;
  transpose_plein(s);

  // cout << "Affichage de la matrice S : " << endl ;
  // display_plein(s) ;
  //
  // cout << endl ;

  // display_plein(produit_mat_mat_plein(s,st)) ;

  resysLin_plein(s,st,b,x) ;
  // cout << "Vecteur solution X = " << endl ;
  // for (int i = 0; i < a.size(); i++) {
  //   cout << x[i] << endl ;
  // }
  // cout << endl ;
  // cout << "Vérification AX=B : " << endl ;
  // for (int i = 0; i < a.size(); i++) {
  //   cout << "B[" << i << "]= " << produit_mat_vec_plein(a,x)[i] << endl  ;
  // }
}


void test_choleski_plein_adaptee(matrix a, rvec b, rvec& x, int m) {
  matrix s (a.size(), rvec(a.size(),0.));
  matrix st (a.size(), rvec(a.size(),0.));

  affectation_pleine(a,s) ;
  Decomp_choleski_adapte_plein(s,m) ;

  // cout << "Affichage de la matrice S^t : " << endl ;
  // display_plein(s) ;
  //
  // cout << endl ;

  affectation_pleine(s,st) ;
  transpose_plein(s);
  //
  // cout << "Affichage de la matrice S : " << endl ;
  // display_plein(s) ;
  //
  // cout << endl ;

  // display_plein(produit_mat_mat_plein(s,st)) ;

  resysLin_plein(s,st,b,x) ;
  // cout << "Vecteur solution X = " << endl ;
  // for (int i = 0; i < a.size(); i++) {
  //   cout << x[i] << endl ;
  // }
  // cout << endl ;
  // cout << "Vérification AX=B : " << endl ;
  // for (int i = 0; i < a.size(); i++) {
  //   cout << "B[" << i << "]= " << produit_mat_vec_plein(a,x)[i] << endl  ;
  // }
}


void test_choleski_v2_plein(matrix a, rvec b, rvec& x) {
  matrix s (a.size(), rvec(a.size(),0.));
  matrix st (a.size(), rvec(a.size(),0.));

  Decomp_choleski_v2_plein(a,st) ;

  // cout << "Affichage de la matrice S : " << endl ;
  // display_plein(st) ;
  //
  // cout << endl ;

  affectation_pleine(st,s) ;
  transpose_plein(st);

  // cout << "Affichage de la matrice S^t : " << endl ;
  // display_plein(st) ;
  //
  // cout << endl ;

  // display_plein(produit_mat_mat_plein(s,st)) ;

  resysLin_plein(s,st,b,x) ;
  // cout << "Vecteur solution X = " << endl ;
  // for (int i = 0; i < a.size(); i++) {
  //   cout << x[i] << endl ;
  // }
  // cout << endl ;
  // cout << "Vérification AX=B : " << endl ;
  // for (int i = 0; i < a.size(); i++) {
  //   cout << "B[" << i << "]= " << produit_mat_vec_plein(a,x)[i] << endl  ;
  // }
}


void test_choleski_v2_plein_adaptee(matrix a, rvec b, rvec& x, int m) {
  matrix s (a.size(), rvec(a.size(),0.));
  matrix st (a.size(), rvec(a.size(),0.));

  Decomp_choleski_v2_adapte_plein(a,st,m) ;

  // cout << "Affichage de la matrice S : " << endl ;
  // display_plein(st) ;
  //
  // cout << endl ;

  affectation_pleine(st,s) ;
  transpose_plein(st);

  // cout << "Affichage de la matrice S^t : " << endl ;
  // display_plein(st) ;
  //
  // cout << endl ;

  // display_plein(produit_mat_mat_plein(s,st)) ;

  resysLin_plein(s,st,b,x) ;
  // cout << "Vecteur solution X = " << endl ;
  // for (int i = 0; i < a.size(); i++) {
  //   cout << x[i] << endl ;
  // }
  // cout << endl ;
  // cout << "Vérification AX=B : " << endl ;
  // for (int i = 0; i < a.size(); i++) {
  //   cout << "B[" << i << "]= " << produit_mat_vec_plein(a,x)[i] << endl  ;
  // }
}
