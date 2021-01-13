#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "wenze.h"

int main(){
baza*wszystko=tworzymy_baze();
uzupelnij_plansze_jedzeniem(wszystko);
uzupelnij_plansze_wenzami(wszystko);
wypisz(wszystko->plansza);
int skucha;
char znak;
for(int p=0;p<100;p++){
    if (p%2==0){ //rusza sie pierwszy
     printf("Kolej na pierwszego gracza.\n");
     scanf(" %c",&znak);
        if(znak=='w'){
        skucha = gora1(wszystko);
        uzupelnij_plansze_wenzami(wszystko);
        wypisz(wszystko->plansza);
            if(skucha==1){
            printf("Drugi gracz wygrał.\n");
            exit(0);
            }
            else if(skucha==2){
            wszystko->zjadl1=1;
            }
        }
        else if(znak=='a'){
        skucha =lewo1(wszystko);
        uzupelnij_plansze_wenzami(wszystko);
        wypisz(wszystko->plansza);
            if(skucha==1){
            printf("Drugi gracz wygrał.\n");
            exit(0);
            }
            else if(skucha==2){
            wszystko->zjadl1=1;
            }
        }
        else if(znak=='s'){
        skucha =dol1(wszystko);
        uzupelnij_plansze_wenzami(wszystko);
        wypisz(wszystko->plansza);
            if(skucha==1){
            printf("Drugi gracz wygrał.\n");
            exit(0);
            }
            else if(skucha==2){
            wszystko->zjadl1=1;
            }
        }
        else if(znak=='d'){
        skucha =prawo1(wszystko);
        uzupelnij_plansze_wenzami(wszystko);
        wypisz(wszystko->plansza);
            if(skucha==1){
            printf("Drugi gracz wygrał.\n");
            exit(0);
            }
            else if(skucha==2){
            wszystko->zjadl1=1;
            }
        }
    }
    if (p%2==1){ //rusza sie drugi
    printf("Kolej na drugiego gracza.\n");
    scanf(" %c",&znak);
        if(znak=='w'){
        skucha =gora2(wszystko);
        pokaz_liste_wenza(wszystko->waz2);
        uzupelnij_plansze_wenzami(wszystko);
        wypisz(wszystko->plansza);
            if(skucha==1){
            printf("Pierwszy gracz wygrał.\n");
            exit(0);
            }
            else if(skucha==2){
            wszystko->zjadl2=1;
            }
        }
        else if(znak=='a'){
        skucha =lewo2(wszystko);
        uzupelnij_plansze_wenzami(wszystko);
        wypisz(wszystko->plansza);
            if(skucha==1){
            printf("Pierwszy gracz wygrał.\n");
            exit(0);
            }
            else if(skucha==2){
            wszystko->zjadl2=1;
            } 
        }
        else if(znak=='s'){
        skucha =dol2(wszystko);
        uzupelnij_plansze_wenzami(wszystko);
        wypisz(wszystko->plansza);
            if(skucha==1){
            printf("Pierwszy gracz wygrał.\n");
            exit(0);
            }
            else if(skucha==2){
            wszystko->zjadl2=1;
            }
        }
        else if(znak=='d'){
        skucha =prawo2(wszystko);
        uzupelnij_plansze_wenzami(wszystko);
        wypisz(wszystko->plansza);
            if(skucha==1){
            printf("Pierwszy gracz wygrał.\n");
            exit(0);
            }
            else if(skucha==2){
            wszystko->zjadl2=1;
            }
        }
    }
}
printf("Długość X:%d\nDługość Y:%d\n",dlugosc(wszystko->waz1),dlugosc(wszystko->waz2));
pokaz_wynik(wszystko);
zwolnij_baze(wszystko);
printf("Main is done.\n");
}
