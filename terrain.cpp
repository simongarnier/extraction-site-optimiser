/*    UQAM / Département d'informatique                          *
 *    INF3105 - Structures de données et algorithmes             *
 *    Hiver 2014 / TP1                                           *
 *    http://ericbeaudry.ca/INF3105/tp1/                         */
#include <assert.h> 
#include "terrain.h"

Fraction Terrain::getPotentielSite(const int x, const int y, const int dimension)
{
    Fraction p =0;
    for (int i = x; i < x + dimension; ++i){
        for (int j = y; j < y + dimension; ++j){
            if(couverture[i][j] < 1){
                p += potentiel[i][j];    
            }
            couverture[i][j]++;
        }
    }
    return p;
}

void Terrain::resetCouverture(const int x, const int y, const int dimension)
{
    for (int i = x; i < x + dimension; ++i){
        for (int j = y; j < y + dimension; ++j){
            couverture[i][j]--;
            //assert(couverture[j][i] >= 0);
        }
    }
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

int Terrain::getLargeur(){ return largeur; }

int Terrain::getHauteur(){ return hauteur; } 

std::istream& operator >>(std::istream& is, Terrain& t)
{
    is >> t.largeur >> t.hauteur;
    Fraction f;
    for(int y=0;y<t.hauteur;++y){
        Tableau<Fraction>   fs;
        Tableau<int>        ints;
        t.potentiel.ajouter(fs);
        t.couverture.ajouter(ints);
        for(int x=0;x<t.largeur;++x){
            is >> f;
            t.potentiel[y].ajouter(f);
            t.couverture[y].ajouter(0);           
        }
    }
    return is;
}

