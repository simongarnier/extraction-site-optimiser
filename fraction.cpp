/*    UQAM / Département d'informatique                          *
 *    INF3105 - Structures de données et algorithmes             *
 *    Hiver 2014 / TP1                                           *
 *    http://ericbeaudry.ca/INF3105/tp1/                         */
 
#include <assert.h>
#include "fraction.h"

using namespace std;
//constructor
Fraction::Fraction(long numerateur, long denominateur, long entier) : n(numerateur), d(denominateur), e(entier){
	if(d == 0){
		d = 1;
	}
	simplifier();
}
Fraction::Fraction(const Fraction& fraction) : n(fraction.n), d(fraction.d), e(fraction.e){}


Fraction& Fraction::operator+=(const Fraction& autre){
    *this = *this + autre;
    return *this;
}

Fraction Fraction::operator+(const Fraction& autre) const{
	Fraction result = Fraction(n * autre.d + autre.n * d, d * autre.d, e + autre.e);
    return result;
}
    
bool Fraction::operator < (const Fraction& autre) const{
	if(e == autre.e){
		if(n*autre.d < autre.n*d){
			return true;
		}else{
			return false;
		}
	}else{
		if(e < autre.e){
			return true;
		}else{
			return false;
		}
	}
}

bool Fraction::operator > (const Fraction& autre) const{
    if(e == autre.e){
		if(n*autre.d > autre.n*d){
			return true;
		}else{
			return false;
		}
	}else{
		if(e > autre.e){
			return true;
		}else{
			return false;
		}
	}
}

void Fraction::simplifier(){
	int div = pgcd(d, n);
	n = n/div;
	d = d/div;
	if(n >= d){
		int retenu 		= n % d;
		int quotient  	= n / d;
		e += quotient;
		n = retenu;
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
            f.e = a;
            f.n = b;
            f.d = c;
            break;
        case '/':
            // forme a/b   (fraction seulement)
            is.get();
            is >> b;
            f.e = 0;
            f.n = a;
            f.d = b;
            break;
        default:
            // forme a     (entier seulement)
            f.e = a;
            f.n = 0;
            f.d = 1;
            break;
    }
    f.simplifier();
    return is;
}

std::ostream& operator << (std::ostream& os, const Fraction& f){
    if(f.e != 0){
		os << f.e;
		if(f.n != 0){
			os << '+';	
		}
	}
	if(f.n != 0){
		os << f.n << '/' << f.d;
	}
	if(f.n == 0 && f.e == 0){
		os << '0';
	}
	os << endl;
    return os;
}

