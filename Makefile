# Makefile pour INF3105 / TP1

OPTIONS = -Wall
# Choisir l'une des deux configuration (-g: Debug | -O3: Release)
#OPTIONS = -g -O0 -Wall
OPTIONS = -O2 -Wall

#Cibles construites sur l'appel de make
all : tp1 testfraction

#Modele de fichier Makefile
#
#<cible>: <dependances>
#<tabulation><Commandes>
#
# Attention : les dépendances ne sont pas automatique. Vous devez ajouter les .h manuellement.
#

tp1: tp1.cpp fraction.o terrain.o
	g++ $(OPTIONS) -o tp1 tp1.cpp fraction.o terrain.o

fraction.o: fraction.h fraction.cpp
	g++ -c $(OPTIONS) fraction.cpp

terrain.o: terrain.cpp terrain.h fraction.h tableau.h
	g++ -c $(OPTIONS) terrain.cpp

testfraction : testfraction.cpp fraction.o
	g++ $(OPTIONS) -o testfraction testfraction.cpp fraction.o


clean :
	rm -f *.o
	rm -f tp1
	rm -f testfraction
	rm -f *~

