//
// Created by jeune on 31/01/2023.
//

#pragma once

/*
 * 1) Choose prime number for the finite field over which the EC will be defined (Galois Field order
 * curve equation : y² = x^3 + ax + b
 * 2) Generate public && private key pair
 *      Private key <-- randomly generated between 1 && order of curve
 *      Public key <-- Point obtenu en multipliant la PKey avec le generateur de point de la courbe
 * 3) Perform Key Agreement :
 *      - Exchange public keys
 *      - Agree on shared secret aka key to encrypt messages
 * 4) Encrypt Message :
 */

class ECIH {
    
};


//EVA01_ECC_NCRYPT_MODULE