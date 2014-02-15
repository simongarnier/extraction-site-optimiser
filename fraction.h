/*    UQAM / Département d'informatique                          *
*    INF3105 - Structures de données et algorithmes             *
*    Hiver 2014 / TP1                                           *
*    http://ericbeaudry.ca/INF3105/tp1/                         */

#if !defined(__FRACTION_H__)
#define __FRACTION_H__
#include <iostream>
class Fraction{

   public:
      Fraction(long num = 0, long den = 0, long ent = 0);     //constructeur standart	
      Fraction(const Fraction&);                                                 //constructeur par copie


      Fraction& operator+=(const Fraction& autre);
      Fraction operator+(const Fraction& autre) const;

      bool operator < (const Fraction& autre) const;
      bool operator > (const Fraction& autre) const;

   private:
      long num;
      long den;
      long ent;
      
      void simplifier();
      int pgcd(int x,int y);
      // Ceci n'est pas des déclarations, mais des liens d'amitiés avec des opérateurs hors de la classe.
      friend std::istream& operator >> (std::istream& is, Fraction& f);
      friend std::ostream& operator << (std::ostream& os, const Fraction& f);
};

#endif

