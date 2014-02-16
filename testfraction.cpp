/*    UQAM / Département d'informatique                          *
 *    INF3105 - Structures de données et algorithmes             *
 *    Hiver 2014 / TP1                                           *
 *    http://ericbeaudry.ca/INF3105/tp1/                         */
 
#include <iostream>
#include "fraction.h"
#include <sstream>

using namespace std;

int main(int argc, const char** argv){
    cout << "Ce programme sert à tester votre classe Fraction." << endl;
    cout << "Par exemples, entrez : 2/4, 3/9, 2/10, 20/100, etc." << endl;
    cout << "Tapez [Ctrl]+[C] (termine le programme) ou [Ctrl]+[D] (envoie fin de fichier, EOF) pour terminer." << endl << endl;
    
    Fraction somme;
    Fraction f1, f2;
    while(cin && !cin.eof()){
        cout << "Entrez une fraction : ";
        cin >> f1;
        cout << "f1=" << f1 << '\t' << "f2=" << f2 << endl;
        cout << "f1<f2=" << (f1<f2 ? "true" : "false") << endl;
        cout << "f2<f1=" << (f2<f1 ? "true" : "false") << endl;
        somme += f1;
        cout << "somme+=f1;  ===>  somme=" << somme << endl;
        f2 = f1;
    }
    return 0;
}

