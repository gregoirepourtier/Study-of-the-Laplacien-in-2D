#ifndef _ITERATIF_HPP_
#define _ITERATIF_HPP_

#include "tools.hpp"

// Méthodes itératives
void SOR_plein (matrix A, rvec b, rvec& x, double w, uint k_max, double eps, uint& k) ;

//le x0 de départ est à mettre dans x en paramètre
void jacobi_plein (matrix A, rvec b, rvec & x, uint k_max, double eps, uint& k) ;


#endif // _ITERATIF_HPP_