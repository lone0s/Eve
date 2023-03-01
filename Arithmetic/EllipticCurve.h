//
// Created by jeune on 07/02/2023.
//
#pragma once
// y² = x^3 + ax + b

//Symétrie A(x,y) => B(x,-y)

#include <cmath>
#include <iostream>
#include "Point.h"
#include "Modulus.h"
#include "utils.h"

/**
 *
 * TODO:
 *  2/ Point doubling: Given a point P on the curve, this method calculates
 *  the point 2P such that 2P is another point on the curve.
 *  This is done by finding the tangent to the curve at P and finding
 *  the second point where this tangent intersects the curve.
 *
 * TODO:
 *  3/Scalar multiplication: Given a point P on the curve and a scalar value k,
 *  this method calculates the point kP such that kP is another point on the curve.
 *  This is done by repeatedly adding P to itself k times,
 *  or by using faster algorithms such as double-and-add or Montgomery ladder.
 *
 * TODO:
 *  4/Point compression: Given a point P on the curve, this method compresses the point
 *  into a fixed-length representation for efficient storage and transmission.
 *  This is typically done by encoding the x-coordinate of the point
 *  and a flag indicating whether the y-coordinate is even or odd.
 *
 * TODO:
 *  5/Point decompression: Given a compressed point representation,
 *  this method decompresses the point back into its original form on the curve.
 *
 * TODO:
 *  6/Key generation: This method generates a public/private key pair for use in EllipticCurveEnc.
 *  The private key is a scalar value and the public key is a point on the curve.
 *  The public key is generated by multiplying the private key by the generator point of the curve.
 *
 * TODO:
 *  7/Signature generation: Given a message and a private key,
 *  this method generates a digital signature for the message.
 *  The signature is typically a pair of values that can be verified using the public key and the message.
 *
 * TODO:
 *  8/Signature verification: Given a signature, a message, and a public key,
 *  this method verifies whether the signature is a valid signature for the message.
 *  If the signature is valid, the method returns true, otherwise it returns false.
 */

template<typename T>
class EllipticCurve {
    // Field = P ; Fp = {0,1,...,p-1}
        T A;
        T B;
        T P;

        public:
    EllipticCurve(T a,
                  T b,
                  T modulo)
                  : A(a), B(b), P(modulo) {};

    ~EllipticCurve() = default;

    Point<T> addition(Point<T> &p, Point<T> &q) const {
        T m = p != q ?
                fmod((q.y - p.y),P) * Mod::qMod( T(1), (q.x - p.x), P) :
                fmod(((3* p.x * p.x) + A) , P) * Mod::qMod(T(1), (2*p.y), P) ;
        T resX = Mod::qMod(m*m - p.x - q.x ,T(1), P);
        T resY = Mod::qMod(m * (p.x - resX) - p.y ,T(1), P);
        return Point<T>{resX, resY};
    };

    //NonSingular ECCs, have tangents defined for each points
    bool isNonSingularECC() const {
        return ((A < P && B < P) && (4*pow(A,3) + 27*pow(B,2) != 0));
    }

    /**
     * @brief   Function to evaluate the number of existing points
     *          on the elliptic curve using the Legendre Formula
     * @return  blabla
     */
    T order() const {
        T res = P + 1;
        for (T i = 0; i < P; ++i) {
            if (Mod::legendre(i,P) == T(1))
                res++;
        }
        return ++res; // +1 for the point at infinity
    }

    //TODO: Check weither point is on curve or not
    bool pointIsOnCurve(Point<T>& P) const {
        T l = fmod(P.y * P.y , this -> P);
        T r = fmod((P.x * P.x * P.x) + (T(3) * A * P.x) + (B * P.x) , this -> P);
        return l == r;
    }

    //TODO: Generate Infinity Point
    Point<T> generateInfinityPoint() {
        return Point<T>{0,0};
    }

    uint64_t generatorPointOrder(Point<T> genPoint) {
        uint64_t cpt = 0;
        Point<T> temp = genPoint;
        Point<T> copy = temp;
        if(this->isNonSingularECC()) {
            //TODO: CORRECT IT, THIS SHJIT FAULTY
            while(temp.x != 0 && temp.y != 0) {
                cpt++;
                copy = addition(temp, temp);
                temp = copy;
            }
        }
        return cpt;
    }

    Point<T> generatorPoint() {
        T max = P - T(1);
        uint64_t cpt = 0;
        uint64_t itMax = 10*max;
        while(cpt < max) {
            T x = Utils::rand<T>(0,max);
            T yy = Mod::qMod<T>((x*x*x) + A*x + B, 1, P);
            if(Mod::legendre<T>(yy, P) != 1) {
                T y = Mod::qMod<T>(std::sqrt(yy),1,P);
                return Point<T>{x,y};
            }
            cpt++;
        }
        throw std::runtime_error("No");
    }

    //TODO: Verify Point at Infinity
    bool validPointAtInfinity() {
        return isNonSingularECC();
    }

    //TODO: Function double and add
    //TODO: Function to compress point
    //TODO: Function to decompress point

    //TODO: Function to generate public key
    //TODO: Function to generate private key
    //TODO: Function to generate key pair
    //TODO: Function to generate signature
    //TODO: Function to verify signature
    //TODO: Function to generate SEED
    //TODO: Function to generate Nothing Up My Sleeve Number (Maybe not?)




};

//EVA01_ELLIPTICCURVE_H
