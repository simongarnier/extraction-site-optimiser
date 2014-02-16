/*    UQAM / Département d'informatique                          *
 *    INF3105 - Structures de données et algorithmes             *
 *    Hiver 2014 / TP1                                           *
 *    http://ericbeaudry.ca/INF3105/tp1/                         */

#if !defined(__TERRAIN_H__)
#define __TERRAIN_H__

#include <iostream>
#include "fraction.h"
#include "tableau.h"

<<<<<<< HEAD
class Emplacement;
=======
class Emplacement{
   public:
      Fraction potentiel;
      int      couverture;

   friend class Terrain;

};

>>>>>>> 9d903b2eaa64d8a7a0cce1274cfb69bf3ff2294b

class Terrain{
    
   public:
      Fraction getPotentielSite  (const int y, const int x, const int dimension);
      void     resetCouverture   (const int y, const int x, const int dimension);
      void     printCouverture   ();
      void     printPotentiel    ();
      int      getLargeur        ();
      int      getHauteur        ();

  
   private:
<<<<<<< HEAD
      Tableau<Tableau<Emplacement> >  matrice;
=======
      Tableau<Tableau<Emplacement> >   matrice;
>>>>>>> 9d903b2eaa64d8a7a0cce1274cfb69bf3ff2294b
      int largeur;
      int hauteur;

      friend std::istream& operator >>(std::istream&, Terrain& t);
};

class Emplacement{
private:
    Fraction potentiel;
    int      couverture;
    
    friend class Terrain;
    friend std::istream& operator >>(std::istream&, Terrain& t);
};

#endif

