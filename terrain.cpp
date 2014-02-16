/*    UQAM / Département d'informatique                          *
 *    INF3105 - Structures de données et algorithmes             *
 *    Hiver 2014 / TP1                                           *
 *    http://ericbeaudry.ca/INF3105/tp1/                         */
#include <assert.h> 
#include "terrain.h"

Fraction Terrain::getPotentielSite(const int x, const int y, const int dimension)
{
    Fraction p =0;
    for (int i = y; i < y + dimension; ++i){
        for (int j = x; j < x + dimension; ++j){
            if(matrice[i][j].couverture < 1){
                p += matrice[i][j].potentiel;    
            }
            matrice[i][j].couverture++;
        }
    }
    return p;
}

void Terrain::resetCouverture(const int x, const int y, const int dimension)
{
    for (int i = y; i < y + dimension; ++i){
        for (int j = x; j < x + dimension; ++j){
            matrice[i][j].couverture--;
            //assert(couverture[j][i] >= 0);
        }
    }
}

void Terrain::printCouverture(){
    for (int i = 0; i < hauteur; ++i){
        for (int j = 0; j < 0 + largeur; ++j){
            std::cout << matrice[i][j].couverture << " ";
        }
        std::cout << std::endl;
    }
     std::cout << std::endl;
}

void Terrain::printPotentiel(){
    for (int i = 0; i < hauteur; ++i){
        for (int j = 0; j < 0 + largeur; ++j){
            std::cout << matrice[i][j].potentiel << " ";
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
    Emplacement e;
    for(int y=0;y<t.hauteur;++y){
        Tableau<Emplacement> es;
        t.matrice.ajouter(es);
        for(int x=0;x<t.largeur;++x){
            is >> e.potentiel;
            e.couverture = 0;
            t.matrice[y].ajouter(e);  
        }
    }
    return is;
}

