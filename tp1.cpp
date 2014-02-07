/*    UQAM / Département d'informatique                          *
 *    INF3105 - Structures de données et algorithmes             *
 *    Hiver 2014 / TP1                                           *
 *    http://ericbeaudry.ca/INF3105/tp1/                         */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include "terrain.h"
#include "fraction.h"

using namespace std;

int main(int argc, const char** argv)
{
    if(argc<3){
        cout << "Syntaxe : ./tp1 carte.txt dimension1 [dimension2 [... [dimensionN]]]" << endl;
        return 1;
    }
    // argv[0] : contient de nom l'exécutable (tp1).
    // argv[1] : nom de la carte.
    ifstream fichiercarte(argv[1]);
    Terrain terrain;
    fichiercarte >> terrain;
    fichiercarte.close(); 
	
    
    int dimensionSite1 = atoi(argv[2]);
    if(argc==3){
        Fraction meilleureValeur;
        Fraction potentiel;
        int solX = 0;
        int solY = 0;
        for (int y = 0; y <= terrain.getHauteur() - dimensionSite1; ++y) {
            for (int x = 0; x <= terrain.getLargeur() - dimensionSite1; ++x) {
                //Évaluation du potentiel du carré (x,y)-(x+dimsite1-1,y+dimsite1-1)
                potentiel = 0;
                for (int i = x; i < x + dimensionSite1; ++i) {
                    for (int j = y; j < y + dimensionSite1; ++j) {
                        potentiel += terrain.getPotentiel(i,j);
                    }
                }
                if(potentiel > meilleureValeur){
                    meilleureValeur = potentiel;
                    solX = x;
                    solY = y;
                }
                    
                
            }
        }
        
        cout << solX << " " << solY << endl;
        cout << meilleureValeur << endl;
    }

    // Critère E
    if(argc==4){
        int dimensionSite2 = atoi(argv[3]);
        Fraction meilleureValeur;
        cerr << "Ce programme ne supporte pas 2 sites d'extraction!" << endl;
        cout << "0\t0" << endl;
        cout << "0\t0" << endl;
        cout << meilleureValeur << endl;
        return 1;
    }
    
    // Boni H
    if(argc>4){
        cout << "Ce programme ne supporte pas 3 ou + sites d'extraction!" << endl;
        int nbSites = argc-2;
        for(int i=0;i<nbSites;i++)
            cout << "0\t0" << endl;
        cout << "0" << endl;
        return 1;
    }
        
    return 0; // fin normal
}

