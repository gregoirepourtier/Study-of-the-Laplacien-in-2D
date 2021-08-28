#ifndef _DECOMPOLU_HPP_
#define _DECOMPOLU_HPP_

#include "tools.hpp"


// Décomposition LU pleine de la matrice A --> OK
void Decomp_LU_plein (matrix a, matrix& u, matrix& l) ;

/* Decomposition LU pleine adaptée à la matrice A 
   qui est nulle sous la diagonale j-i=-(m-1) et 
   au-dessus de la diagonale j-i=m-1 */
void Decomp_LU_adapte_plein (matrix a, matrix& u, matrix& l, uint m) ;

// Decomposition LU pivot partiel (Stockage plein pour les matrices)
void Decomp_LU_partiel_plein (matrix& u, matrix& l, matrix& p) ;


#endif // _DECOMPOLU_HPP_