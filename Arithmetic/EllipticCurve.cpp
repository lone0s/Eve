//
// Created by jeune on 07/02/2023.
//

#include "EllipticCurve.h"

Point<unsigned long long> EllipticCurve::addition(const Point<unsigned long long> &P, const Point<unsigned long long> &Q) {
    unsigned long long m = (P == Q) ?
            (3*(P.x*P.x) + this->A)/(2*P.y) % this -> P : ((P.y - Q.y)/(P.x - Q.x)) % this -> P;
    //Probleme du modulo sur des fractions, on doit remplacer par un inverse
    // | m = (yP - yQ)(xP-xQ)^-1 mod P
    // | m = (3xP² + A)*(2yP)^-1 mod P
    unsigned long long resX = ((m*m) - P.x - Q.x) % this -> P;
    return Point<unsigned long long>{resX, (P.y + m * (resX - P.x)) % this -> P};
}

/*Point<unsigned long long> EllipticCurve::doubling(const Point<unsigned long long int> &P) {
    unsigned long long m = (3*(P.x*P.x) + this->A)/(2*P.y) % this -> P; //Slope pour la tangente
    unsigned long long resX = ((m*m) - P.x - Q.x) % this -> P;

}*/
