#include "wenze.h"

waz * tworz_glowe(int r, int c){
waz*snake = (waz*) malloc(sizeof(waz)); 
snake->r = r;
snake->c = c;
snake->nast = NULL;                  
snake->poprz = NULL;

return snake;
}

baza* tworzymy_baze(){
baza*Sbaza = (baza*) malloc(sizeof(baza));
Sbaza->zjadl1 =0;
Sbaza->zjadl2 =0;
Sbaza->waz1=tworz_glowe(0,0);
Sbaza->waz2=tworz_glowe(M-1,N-1);
return Sbaza;
}

int dlugosc(waz*tesciowa) {
    int n = 0;
    waz*snake = tesciowa;
    while (snake != NULL) {
        n++;
        snake = snake->nast;
    }
    return n;
}

void pokaz_wynik(baza*wszystko){
int x = dlugosc(wszystko->waz1);
int y = dlugosc(wszystko->waz2);
if(x>y){                         //wygrywa 1
    printf("Wygrywa wąż1\n");
    }
else if(x<y){                     //wygrywa 2
    printf("Wygrywa wąż2\n");
    }
else                              //remis
{
    printf("Remis\n");
    }

}

void zwolnij_weza(waz*snake) {
    waz *n;
    while (snake != NULL) {
        n = snake->nast;
        free(snake);
        snake = n;
    }
}

void zwolnij_baze(baza*Sbaza){
zwolnij_weza(Sbaza->waz1);
zwolnij_weza(Sbaza->waz2);
free(Sbaza);
}

void wypisz(char plansza[M][N])
{
     for(int i=0;i<M;i++)
    {
        printf("| ");
        for(int j=0;j<N;j++)
        {
            printf("%c | ",plansza[i][j]);
        }
        printf("\n");
        for(int j=0;j<N;j++)
        {
            printf("----");
        }
        printf("\n");
    }
}

void uzupelnij_plansze_jedzeniem(baza*Sbaza){
    for (int i = 0; i<M; i++)
    for (int j = 0;j<N;j++){
    Sbaza->plansza[i][j] = ' ';
}
for(int i=0;i<iloscJedzenia;i++)
   {
    int x,y;
    time(NULL); 
    x=rand()%(M);  // losowe
    y=rand()%(N); // loswe
    //printf("%d  %d\n",x,y);
    Sbaza->plansza[x][y]='*';
   }
}

void uzupelnij_plansze_wenzami(baza*Sbaza){
waz*x;
x=Sbaza->waz1;
waz*y;
y=Sbaza->waz2;
    while (x != NULL){
        Sbaza->plansza[x->r][x->c] = 'X';
        x= x->nast;
    }
     while (y != NULL){
        Sbaza->plansza[y->r][y->c] = 'Y';
        y= y->nast;
    }
}

void pokaz_liste_wenza(waz*tesciowa){
    while(tesciowa!=NULL){
    printf("x-%d,y-%d\n",tesciowa->r,tesciowa->c);
    tesciowa=tesciowa->nast;
    }

}





int gora1(baza*wszystko){
if(wszystko->waz1->r==0){
    printf("ściana baranie\n");
    return(1);
}
else if(wszystko->plansza[(wszystko->waz1->r)-1][wszystko->waz1->c]=='X'){
    printf("Wjechałeś w gracza1\n");
    return(1);
}
else if(wszystko->plansza[(wszystko->waz1->r)-1][wszystko->waz1->c]=='Y'){
    printf("Wjechałeś w gracza2\n");
    return(1);
}
else if(wszystko->plansza[(wszystko->waz1->r)-1][wszystko->waz1->c]=='*'){
printf("bonus\n");
    if(wszystko->zjadl1==1){ //jeśli zjada ale poprzednio tez zjadl czyli dodaje segment

    }
    else{ //jeśli zjada ale poprzednio nie zjadl czyli dodaje segment a ostatni usuwam
}
return(2);
}
    if(wszystko->zjadl1==1){ //jeśli nie zjada ale poprzednio zjadl czyli ostatni zostaje

    }
    else{ //jeśli nie zjada ale poprzednio nie zjadl czyli ostatni sie usuwa
    printf("dupa\n");
    waz*snake = (waz*) malloc(sizeof(waz)); 
    snake->r = wszystko->waz1->r-1;
    snake->c = wszystko->waz1->c;
    snake->nast = wszystko->waz1;                  
    wszystko->waz1->poprz = snake;
    wszystko->waz1=snake;
    while(wszystko->waz1->nast != NULL){
        wszystko->waz1 =wszystko->waz1->nast;
      }
      wszystko->waz1= NULL;
    }
return(0);
}

int dol1(baza*wszystko){
if(wszystko->waz1->r==M-1){
    printf("ściana baranie\n");
    return(1);
}
else if(wszystko->plansza[(wszystko->waz1->r)+1][wszystko->waz1->c]=='*'){
printf("bonus\n");

return(2);
}
return(0);
}

int lewo1(baza*wszystko){
if(wszystko->waz1->c==0){
    printf("ściana baranie\n");
    return(1);
}
else if(wszystko->plansza[wszystko->waz1->r][(wszystko->waz1->c)-1]=='*'){
printf("bonus\n");

return(2);
}
return(0);
}

int prawo1(baza*wszystko){


if(wszystko->waz1->c==N-1){
    printf("ściana baranie\n");
    return(1);
}
else if(wszystko->plansza[wszystko->waz1->r][(wszystko->waz1->c)+1]=='*'){
printf("bonus\n");

return(2);
}
return(0);
}


int gora2(baza*wszystko){
if(wszystko->waz2->r==0){
    printf("ściana baranie\n");
    return(1);
}
else if(wszystko->plansza[(wszystko->waz2->r)-1][wszystko->waz2->c]=='X'){
    printf("Wjechałeś w gracza1\n");
    return(1);
}
else if(wszystko->plansza[(wszystko->waz2->r)-1][wszystko->waz2->c]=='Y'){
    printf("Wjechałeś w gracza2\n");
    return(1);
}
else if(wszystko->plansza[(wszystko->waz2->r)-1][wszystko->waz2->c]=='*'){
printf("bonus\n");
    if(wszystko->zjadl2==1){ //jeśli zjada ale poprzednio tez zjadl czyli dodaje segment

    }
    else{ //jeśli zjada ale poprzednio nie zjadl czyli dodaje segment a ostatni usuwam
}
return(2);
}
    if(wszystko->zjadl2==1){ //jeśli nie zjada ale poprzednio zjadl czyli ostatni zostaje

    }
    else{ //jeśli nie zjada ale poprzednio nie zjadl czyli ostatni sie usuwa
    printf("dupa\n");
    waz*snake = (waz*) malloc(sizeof(waz)); 
    snake->r = wszystko->waz2->r-1;
    snake->c = wszystko->waz2->c;
    snake->nast = wszystko->waz2;                  
    wszystko->waz2->poprz = snake;
    wszystko->waz2=snake;
    while(wszystko->waz2->nast!=NULL){
        wszystko->waz2 =wszystko->waz2->nast;
      }
      wszystko->waz2 = NULL;
    }
return(0);
}

int dol2(baza*wszystko){
if(wszystko->waz2->r==M-1){
    printf("ściana baranie\n");
    return(1);
}
else if(wszystko->plansza[(wszystko->waz2->r)+1][wszystko->waz2->c]=='*'){
printf("bonus\n");

return(2);
}
return(0);
}

int lewo2(baza*wszystko){
if(wszystko->waz2->c==0){
    printf("ściana baranie\n");
    return(1);
}
else if(wszystko->plansza[wszystko->waz2->r][(wszystko->waz2->c)-1]=='*'){
printf("bonus\n");

return(2);
}
return(0);
}

int prawo2(baza*wszystko){
if(wszystko->waz2->c==N-1){
    printf("ściana baranie\n");
    return(1);
}
else if(wszystko->plansza[wszystko->waz2->r][(wszystko->waz2->c)+1]=='*'){
printf("bonus\n");

return(2);
}
return(0);
}