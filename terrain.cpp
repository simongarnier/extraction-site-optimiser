/*    UQAM / Département d'informatique                          *
 *    INF3105 - Structures de données et algorithmes             *
 *    Hiver 2014 / TP1                                           *
 *    http://ericbeaudry.ca/INF3105/tp1/                         */
 
#include "terrain.h"


Fraction Terrain::getPotentiel(int x, int y)
{
    return matrice[x][y];
}

int Terrain::getLargeur()
{
    return largeur;
}

int Terrain::getHauteur()
{
    return hauteur;
}




std::istream& operator >>(std::istream& is, Terrain& t){
    // À compléter.
    int largeur, hauteur;
    is >> largeur >> hauteur;
    t.largeur = largeur;
    t.hauteur = hauteur;
    Fraction f;
    for(int y=0;y<hauteur;++y)
        for(int x=0;x<hauteur;++x){
            is >> f;
            t.matrice[x][y] = f;            
        }
    return is;
}

