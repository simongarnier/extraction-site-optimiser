/*    UQAM / Département d'informatique                          *
 *    INF3105 - Structures de données et algorithmes             *
 *    Hiver 2014 / TP1                                           *
 *    http://ericbeaudry.ca/INF3105/tp1/                         */
 
#include "terrain.h"



std::istream& operator >>(std::istream& is, Terrain& t){
    // À compléter.
    int largeur, hauteur;
    is >> largeur >> hauteur;
    t.largeur = largeur;
    t.hauteur = hauteur;
    Fraction f;
    for(int x=0;x<largeur;x++)
        for(int y=0;y<hauteur;y++){
            is >> f;
            t.matrice[x][y] = f;            
        }
    return is;
}

