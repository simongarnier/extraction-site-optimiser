/*    UQAM / Département d'informatique                          *
 *    INF3105 - Structures de données et algorithmes             *
 *    Hiver 2014 / TP1                                           *
 *    http://ericbeaudry.ca/INF3105/tp1/                         */

#if !defined(__TERRAIN_H__)
#define __TERRAIN_H__

#include <cstdlib>
#include <iostream>
#include "fraction.h"
#include "tableau.h"


class Terrain{
   
   public:
      //Donne l'emplacement à la coordonnée donnée
      Fraction getPotentiel      (int x, int y);
      Fraction getPotentielSite  (int x, int y, int dimension);
      void     printCouverture   ();
      void     resetCouverture   (int x, int y, int dimension);
      int      getLargeur();
      int      getHauteur();

      Tableau<Tableau<int> > couverture;
   
   private:
      Tableau<Tableau<Fraction> > potentiel;
      int largeur;
      int hauteur;

   

   // Ceci n'est pas des déclarations, mais des liens d'amitiés avec des opérateurs hors de la classe.
    
   friend std::istream& operator >>(std::istream&, Terrain& t);
};



#endif

