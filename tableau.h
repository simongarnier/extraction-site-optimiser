/* UQAM / Département d'informatique
   INF3105 - Structures de données et algorithmes
   Squelette pour classe générique Tableau<T> pour le Lab3.
*/

// Ces deux lignes permettent d'éviter d'inclure 2 fois ce .h à la compilation.
#if !defined(__TABLEAU_H__)
#define __TABLEAU_H__

template <class T>
class Tableau
{
  public:
    Tableau(int capacite_initiale=8);
    Tableau(const Tableau&);
    ~Tableau();

    // Ajouter un element à la fin
    void           ajouter(const T& element);
    // Vider le tableau
    void           vider();
    // Retourne le nombre d'éléments dans le tableau
    int            taille() const;
    // Insère element à position index. Les éléments à partir de index sont décalés d'une position au préalable.
    void           inserer(const T& element, int index=0);
    // Enlève l'element à position index. Les éléments après index sont décalés d'une position après.
    void           enlever(int index=0);
    // Cherche et retourne la position de l'élément. Si non trouvé, retourne -1.
    // Voir la méthode "trouver" dans les notes de cours. Il suffit de l'adapter pour retourner la position au lieu d'un booléen
    int            trouver(const T& element);
    

    T&             operator[] (int index);
    const T&       operator[] (int index) const;


    Tableau<T>&    operator = (const Tableau<T>& autre);

    bool           operator == (const Tableau<T>& autre) const;

  private:
    T*             elements;
    int            capacite;
    int            nbElements;
    void	   	   redimensionner(int nouvCapacite);
};

/*
 Puisque Tableau<T> est une classe générique, toutes ses définitions doivent être
 inclues après les déclarations. On peut quand même séparer les déclarations et
 les définitions en deux fichiers (tableau.h et tableau.hcc), à condition d'inclure le
 deuxième (tableau.hcc) à la fin du premier (tableau.h). Ainsi, un fichier source
 (.cc, .cpp, c++) qui inclut tableau.h inclura indirectement aussi tableau.hcc.

*/

//#include "tableau.hcc"
/**** Début des définitions pouvant être mises dans tableau.hcc. ****/
#include <assert.h>

template <class T>
Tableau<T>::Tableau(int capacite_initiale)
{
    capacite = capacite_initiale;
	nbElements = 0;
	elements = new T[capacite];

}

template <class T>
Tableau<T>::Tableau(const Tableau& autre)
{
    capacite = autre.nbElements; // ou autre.capacite
	nbElements = autre.nbElements;
	elements = new T[capacite];
	for(int i=0;i<nbElements;i++)
		elements[i] = autre.elements[i];
}

template <class T>
Tableau<T>::~Tableau()
{
    delete[] elements;
	elements = NULL;
}

template <class T>
int Tableau<T>::taille() const
{
    return nbElements;
}

template <class T>
void Tableau<T>::ajouter(const T& item)
{
	assert(nbElements <= capacite);
	if(nbElements == capacite)
		redimensionner(capacite*2);
	elements[nbElements++] = item;
}

template <class T>
void Tableau<T>::inserer(const T& element, int index)
{
	assert(nbElements <= capacite);
    if(index >= capacite) {
		capacite = std::max(2*capacite, index);
   
    }
    T* temp = new T[capacite];
	for(int i = 0; i < index;++i)
		temp[i] = elements[i];
	temp[index] = element;
	for(int i = index; i < nbElements;++i)
		temp[i+1] = elements[i];
	elements = temp;
	
	++nbElements;
    
}

template <class T>
void Tableau<T>::enlever(int index)
{
	
	for(int i = index; i < nbElements; ++i)
	{
		elements[i] = elements[i+1];
	}
    --nbElements;
}

template <class T>
int Tableau<T>::trouver(const T& element)
{
    for(int i=0;i<nbElements;++i)
		if(elements[i] == element)
			return i;
    return -1;
}

template <class T>
void Tableau<T>::vider()
{
    nbElements = 0;
}

template <class T>
T& Tableau<T>::operator[] (int index)
{
    if(index>=capacite)
		redimensionner(std::max(index, 2*capacite));
		return elements[index];
}

template <class T>
const T& Tableau<T>::operator[] (int index) const
{
    
	assert(index<nbElements);
	return elements[index];
}

template <class T>
Tableau<T>& Tableau<T>::operator = (const Tableau<T>& autre)
{
	//cas special lorsqu’on affecte un objet a lui-meme
    if(this==&autre) return *this;
	nbElements = autre.nbElements;
	if(capacite<autre.nbElements){
	delete[] elements;
	capacite = autre.nbElements; //ou autre.capacite
	elements = new T[capacite];
	}
	for(int i=0;i<nbElements;i++)
		elements[i] = autre.elements[i];
	return *this;

}

template <class T>
bool Tableau<T>::operator == (const Tableau<T>& autre) const
{
    if(this==&autre) return true; // meme Tableau
	if(nbElements!=autre.nbElements) return false;
	for(int i=0;i<nbElements;++i)
		if(elements[i] != autre.elements[i])
			return false;
	return true;
}

template <class T>
void Tableau<T>::redimensionner(int nouvCapacite){
   capacite = nouvCapacite;
   T* temp = new T[capacite];
   for(int i=0;i<nbElements;++i)
      temp[i] = elements[i];
   delete [] elements;
   elements = temp;
}


#endif
