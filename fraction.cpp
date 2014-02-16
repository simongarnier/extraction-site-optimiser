/*    UQAM / Département d'informatique                          *
 *    INF3105 - Structures de données et algorithmes             *
 *    Hiver 2014 / TP1                                           *
 *    http://ericbeaudry.ca/INF3105/tp1/                         */
 
#include <assert.h>
#include "fraction.h"

using namespace std;
//constructor
Fraction::Fraction(long _num, long _den, long _ent) 
	: num(_num), den(_den), ent(_ent){
	if(den == 0){
		den = 1;
	}
	simplifier();
}
Fraction::Fraction(const Fraction& fraction) 
	: num(fraction.num), den(fraction.den), ent(fraction.ent){}


Fraction& Fraction::operator+=(const Fraction& autre){
    *this = *this + autre;
    return *this;
}

Fraction Fraction::operator+(const Fraction& autre) const{
	Fraction result = Fraction(num * autre.den + autre.num * den, den * autre.den, ent + autre.ent);
    return result;
}
    
bool Fraction::operator < (const Fraction& autre) const{
	if(ent == autre.ent){
		if(num * autre.den < autre.num * den){
			return true;
		}else{
			return false;
		}
	}else{
		if(ent < autre.ent){
			return true;
		}else{
			return false;
		}
	}
}

bool Fraction::operator > (const Fraction& autre) const{
    if(ent == autre.ent){
		if(num * autre.den > autre.num * den){
			return true;
		}else{
			return false;
		}
	}else{
		if(ent > autre.ent){
			return true;
		}else{
			return false;
		}
	}
}

void Fraction::simplifier(){
	int div = pgcd(den, num);
	num = num/div;
	den = den/div;
	if(num >= den){
		int retenu 		= num % den;
		int quotient  	= num / den;
		ent += quotient;
		num = retenu;
	}
}
int Fraction::pgcd(int x, int y){
	int retenu = y % x;
	if (retenu != 0){
		return pgcd(retenu, x);
	}

	return x; 
}

std::istream& operator >> (std::istream& is, Fraction& f){
    long a, b, c;
    is >> a;
    char p = is.peek();
    switch(p){
        case '+':
            // forme a+b/c (entier + fraction)
            is.get();
            is >> b;
            assert(is.get()=='/');
            is >> c;
            f.ent = a;
            f.num = b;
            f.den = c;
            break;
        case '/':
            // forme a/b   (fraction seulement)
            is.get();
            is >> b;
            f.ent = 0;
            f.num = a;
            f.den = b;
            break;
        default:
            // forme a     (entier seulement)
            f.ent = a;
            f.num = 0;
            f.den = 1;
            break;
    }
    f.simplifier();
    return is;
}

std::ostream& operator << (std::ostream& os, const Fraction& f){
    if(f.ent != 0){
		os << f.ent;
		if(f.num != 0){
			os << '+';	
		}
	}
	if(f.num != 0){
		os << f.num << '/' << f.den;
	}
	if(f.num == 0 && f.ent == 0){
		os << '0';
	}
    return os;
}

