/*    UQAM / Département d'informatique                          *
 *    INF3105 - Structures de données et algorithmes             *
 *    Hiver 2014 / TP1                                           *
 *    http://ericbeaudry.ca/INF3105/tp1/                         */

#if !defined(__TERRAIN_H__)
#define __TERRAIN_H__

#include <iostream>
#include "fraction.h"
#include "tableau.h"

class Terrain{
   public:
      Fraction getPotentielSite  (const int y, const int x, const int dimension);
      void     resetCouverture   (const int y, const int x, const int dimension);
      void     printCouverture   ();
      int      getLargeur        ();
      int      getHauteur        ();

  
   private:
      Tableau<Tableau<Fraction> >   potentiel;
      Tableau<Tableau<int> >        couverture;
      int largeur;
      int hauteur;

      friend std::istream& operator >>(std::istream&, Terrain& t);
};

#endif

