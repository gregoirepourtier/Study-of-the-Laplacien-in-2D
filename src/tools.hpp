#ifndef _TOOLS_HPP_
#define _TOOLS_HPP_

#include <vector>

typedef std::vector< std::vector<double> > matrix ;
typedef std::vector<double> rvec ;
typedef unsigned int uint ;


// Fonction pour transposer la matrice
void transpose_plein(matrix& a) ;


// Remplie de façon "plein" la matrice A
void remplissage_A_plein(matrix& a, double alpha, uint n, uint m, double h, double k) ;
// Affiche les matrices pleines
void display_plein(matrix a) ;


// Création du second membre
void second_membre (uint n, uint m, double a, double b, double h, double k, double alpha, rvec& B) ;
// vector<double> second_membre(int n, int m,double alpha) ;


// Fonction max entiers
int max_entiers(int a, int b) ;
// Fonction min entiers
int min_entiers(int a, int b) ;


// Produit matrice-matrice avec des matrices en stockage bande, renvoie la matrice résultat en stockage plein
matrix produit_mat_mat_plein (matrix a, matrix b) ;

// Produit matrice-vecteur avec une matrice en stockage plein
rvec produit_mat_vec_plein(matrix a, rvec x) ;

// Norme euclidienne d'un vector
double norm(rvec x) ;


// U = A (stockage plein)
void affectation_pleine (matrix a ,matrix& u) ;
// L = Id (stockage plein)
void affectation_pleine_id (matrix& l) ;


// Fonction solution sol(x,y) = u(x,y)
double sol(double x, double y) ;

// fonctions f enoncé (partie du second_membre)
double f (double x, double y, double alpha) ;
// fonctions g enoncé (conditions aux bords)
double g (double x, double y) ;


#endif // _TOOLS_HPP_