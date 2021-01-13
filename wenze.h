#ifndef wenze
#define wenze
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define M 3 //wiersze planszy
#define N 12 //kolunny planszy
#define iloscJedzenia 4


typedef struct waz{
int r; 
int c; 
struct waz*nast; 
struct waz*poprz; 
}waz;

typedef struct baza{
waz *waz1; 
waz *waz2;
int zjadl1; // potrzebna zmienna 1/0 żeby wiedzieć czy przy nastepnym ruchu mamy mu dodać segment czy nie
int zjadl2;
char plansza[M][N];
}baza;

waz * tworz_glowe(int r, int c);
baza* tworzymy_baze();
int dlugosc(waz*tesciowa);
void pokaz_wynik(baza*wszystko);
void zwolnij_weza(waz*snake);
void zwolnij_baze(baza*Sbaza);
void wypisz(char plansza[M][N]);
void uzupelnij_plansze_jedzeniem(baza*Sbaza);
void uzupelnij_plansze_wenzami(baza*Sbaza);
void pokaz_liste_wenza(waz*tesciowa);
int gora1(baza*wszystko);
int dol1(baza*wszystko);
int lewo1(baza*wszystko);
int prawo1(baza*wszystko);
int gora2(baza*wszystko);
int dol2(baza*wszystko);
int lewo2(baza*wszystko);
int prawo2(baza*wszystko);

#endif