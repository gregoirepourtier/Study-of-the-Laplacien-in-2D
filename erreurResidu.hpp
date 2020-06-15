#ifndef _ERREURRESIDU_HPP_
#define _ERREURRESIDU_HPP_

#include "tools.hpp"

// Erreur en 2 (matrice pleine)
double erreur_2 (uint n, uint m, double h, double k, rvec X) ;
// Erreur en infini (matrice pleine)
double erreur_inf (uint n, uint m, double h, double k, rvec X) ;


// Residu 2 plein
double residu_2_plein (rvec B, matrix A, rvec X) ;
// Residu infini plein
double residu_inf_plein (rvec B, matrix A, rvec X) ;



#endif // _ERREURRESIDU_HPP_