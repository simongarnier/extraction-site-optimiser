/*    UQAM / Département d'informatique                          *
 *    INF3105 - Structures de données et algorithmes             *
 *    Hiver 2014 / TP1                                           *
 *    http://ericbeaudry.ca/INF3105/tp1/                         */
 
#include "terrain.h"


Fraction Terrain::getPotentiel(int x, int y)
{
    return potentiel[x][y];
}

Fraction Terrain::getPotentielSite(int x, int y, int dimension)
{
    Fraction p = 0;
    for (int i = x; i < x + dimension; ++i){
        for (int j = y; j < y + dimension; ++j){
            if (couverture[i][j] < 1){
                p += potentiel[i][j];
            }
            couverture[i][j]++;
        }
    }
    return p;
}

void Terrain::resetCouverture(int x, int y, int dimension)
{
    for (int i = x; i < x + dimension; ++i){
        for (int j = y; j < y + dimension; ++j){
            couverture[i][j]--;
        }
    }
}

int Terrain::getLargeur()
{
    return largeur;
}

int Terrain::getHauteur()
{
    return hauteur;
}

void Terrain::printCouverture(){
    for (int x = 0; x < largeur; ++x){
        for (int y = 0; y < 0 + hauteur; ++y){
            std::cout << couverture[x][y] << " ";
        }
        std::cout << std::endl;
    }
     std::cout << std::endl;
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
            t.potentiel[x][y] = f; 
            t.couverture[x][y] = 0;             
        }
    return is;
}

