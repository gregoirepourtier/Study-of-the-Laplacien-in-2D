#ifndef _DECOMPOCHOLESKY_HPP_
#define _DECOMPOCHOLESKY_HPP_

#include "tools.hpp"


// Decomposition de Choleski (A=SS^T) basique en utilisant le fait que S^T = (1/sqrt(D))*U
void Decomp_choleski_plein (matrix& s) ;

// Decomposition de Choleski (A=SS^T) en utilisant le fait que S^T = (1/sqrt(D))*U et adaptée à notre matrice A
void Decomp_choleski_adapte_plein (matrix& s, uint m) ;

/* Decomposition de Choleski (A=SS^T) basique avec une formule pour les coefficients diagonaux de S et 
   une autre pour le reste des coefficients de S  */
void Decomp_choleski_v2_plein (matrix a, matrix& s) ;

/* Decomposition de Choleski (A=SS^T) avec une formule pour les coefficients diagonaux de S et 
   une autre pour le reste des coefficients de S */
void Decomp_choleski_v2_adapte_plein (matrix a, matrix& s, uint m) ;



#endif // _DECOMPOCHOLESKY_HPP_