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
        int solx = 0;
        int soly = 0;
        for (int y = 0; y <= terrain.getHauteur() - dimensionSite1; ++y) {
            for (int x = 0; x <= terrain.getLargeur() - dimensionSite1; ++x) {
                //Évaluation du potentiel du carré (x,y)-(x+dimsite1-1,y+dimsite1-1)
                potentiel = terrain.getPotentielSite(x, y, dimensionSite1);
                //terrain.printCouverture();
                terrain.resetCouverture(x, y, dimensionSite1);
                if(potentiel > meilleureValeur){
                    meilleureValeur = potentiel;
                    solx = x;
                    soly = y;
                }
                    
                
            }
        }
        cout << solx << " " << soly << endl;
        cout << meilleureValeur << endl;
    }

    // Critère E
    if(argc==4){
        int dimensionSite2 = atoi(argv[3]);
        Fraction meilleureValeur;
        Fraction potentiel1;
        Fraction potentiel2;
        int sol1x = 0;
        int sol1y = 0;
        int sol2x = 0;
        int sol2y = 0;
        for (int y1 = 0; y1 <= terrain.getHauteur() - dimensionSite1; ++y1) {
            for (int x1 = 0; x1 <= terrain.getLargeur() - dimensionSite1; ++x1) {
                potentiel1 = terrain.getPotentielSite(x1, y1, dimensionSite1);
                //terrain.printCouverture();
                for (int y2 = 0; y2 <= terrain.getHauteur() - dimensionSite2; ++y2){
                    for (int x2 = 0; x2 <= terrain.getLargeur() - dimensionSite2; ++x2){
                        potentiel2 = potentiel1 + terrain.getPotentielSite(x2, y2, dimensionSite2);
                        //terrain.printCouverture();
                        terrain.resetCouverture(x2,y2,dimensionSite2);

                        if(potentiel2 > meilleureValeur){
                            meilleureValeur = potentiel2;
                            sol1x = x1;
                            sol1y = y1;
                            sol2x = x2;
                            sol2y = y2;
                        }
                    }
                }

                terrain.resetCouverture(x1,y1,dimensionSite1);

            }
        }
        cout << sol1x << " " << sol1y << endl;
        cout << sol2x << " " << sol2y << endl;
        cout << meilleureValeur << endl;
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

