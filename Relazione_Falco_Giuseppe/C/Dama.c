#include <stdio.h>  //contiene definizioni di macro, costanti e dichiarazioni di funzioni e tipi usati per le varie operazioni di input/output.
#include <stdlib.h>  //allocazione della memoria, controllo dei processi, e altre funzioni generali comprendenti anche i tipi di dato.
#include <time.h>   //fornisce un accesso standardizzato alle funzioni di acquisizione e manipolazione del tempo.

#define RIGHE 8 //definiamo  la costante RIGHE uguale a 8
#define COLONNE 8  //definiamo  la costante COLONNE uguale a 8
char conversione_colonna(int);  //prototipo  funzione per la coversione da numeri a lettere delle colonne
//Creazione del campo da gioco
char Scacchiera [RIGHE][COLONNE]= {{' ','X',' ','X',' ','X',' ','X'},
                                   {'X',' ','X',' ','X',' ','X',' '},
                                   {' ','X',' ','X',' ','X',' ','X'},
                                   {'X',' ','X',' ','X',' ','X',' '},
                                   {' ','X',' ','X',' ','X',' ','X'},
                                   {'X',' ','X',' ','X',' ','X',' '},
                                   {' ','X',' ','X',' ','X',' ','X'},
                                   {'X',' ','X',' ','X',' ','X',' '},
                                  };
//Visualizzazione del campo da gioco creato
void visualizza_scacchiera(){
int i,j;
printf("  A B C D E F G H\n");
for(i=0;i<RIGHE;i++){
    printf("%d ",i+1);
    for(j=0;j<COLONNE;j++){
        printf("%c ",Scacchiera[i][j]);
    }
    printf("\n");
}
}
//Posizionamento del tipo randomico di tutte le pedine sul campo da gioco
void posizionamento_pedine(){
int i;
int rig_random,col_random;
for(i=0;i<5;i++){ //viene utilizzato il ciclo di ripetizione for, in modo che al passo i-esimo viene assegnata la posizione ad una pedina bianca
    do{
       rig_random = rand()%8;   //viene utilizzata la funzione rand,genera un numero randomico da 0 a 7, per quel che riguarda le righe
       col_random = rand()%8;   //viene utilizzata la funzione rand,genera un numero randomico da 0 a 7, per quel che riguarda le colonne
    }while(Scacchiera[rig_random][col_random]!='X');  //il ciclo finisce quando abbiamo come  valore X nella posizione random
    Scacchiera[rig_random][col_random]= 'B';//inserimento pedina bianca
}
for(i=0;i<5;i++){//viene utilizzato il ciclo di ripetizione for, in modo che al passo i-esimo viene assegnata la posizione ad una pedina nera
    do{
       rig_random = rand()%8;  //viene utilizzata la funzione rand,genera un numero randomico da 0 a 7, per quel che riguarda le righe
       col_random = rand()%8;  //viene utilizzata la funzione rand,genera un numero randomico da 0 a 7, per quel che riguarda le colonne
    }while(Scacchiera[rig_random][col_random]!='X');  //il ciclo finisce quando abbiamo come  valore X nella posizione random
    Scacchiera[rig_random][col_random]= 'N';//inserimento pedina nera
}
}
//Funzione principale in cui viene effettuato il calcolo riguardante le possibili pedine(sia nere che bianche)catturabili
void calcolo_pedine_catturabili(){
int i,j;
for(i=0;i<RIGHE;i++){   //primo ciclo for che al passo i_esimo scorre le righe
    for(j=0;j<COLONNE;j++){  //secondo ciclo for che al passo j_esimo scorre le colonne
        if(Scacchiera[i][j]=='B'){
        trova_possibili_pedine_nere_catturabili(i,j);  //Quando il valore della  posizione data dagli indici [i][j] e' uguale a B richiama la funzione per il calcolo delle pedine nere catturabili
        }
        if(Scacchiera[i][j]=='N'){
        trova_possibili_pedine_bianche_catturabili(i,j);  //Quando il valore della  posizione data dagli indici [i][j] e' uguale a B richiama la funzione per il calcolo delle pedine bianche catturabili
        }
    }
}

}
//Funzione calcolo pedine nere catturabili richiamata da funzione principale
void trova_possibili_pedine_nere_catturabili(int riga_bianca,int colonna_bianca){
if(riga_bianca>1){
        if(colonna_bianca==7||colonna_bianca==6){
            if(Scacchiera[riga_bianca-1][colonna_bianca-1]=='N'){
                if(Scacchiera[riga_bianca-2][colonna_bianca-2]=='X'){
                    printf("La pedina bianca che si trova in %c%d mangia la pedina nera che si trova in %c%d\n",conversione_colonna(colonna_bianca),riga_bianca+1,conversione_colonna(colonna_bianca-1),riga_bianca);
                    return;
                }
            }
        }
        if(colonna_bianca==0||colonna_bianca==1){
            if(Scacchiera[riga_bianca-1][colonna_bianca+1]=='N'){
                if(Scacchiera[riga_bianca-2][colonna_bianca+2]=='X'){
                    printf("La pedina bianca che si trova in %c%d mangia la pedina nera che si trova in %c%d\n",conversione_colonna(colonna_bianca),riga_bianca+1,conversione_colonna(colonna_bianca+1),riga_bianca);
                    return;
                }
            }
        }
        if(Scacchiera[riga_bianca-1][colonna_bianca-1]=='N'){
                if(Scacchiera[riga_bianca-2][colonna_bianca-2]=='X'){
                    printf("La pedina bianca che si trova in %c%d mangia la pedina nera che si trova in %c%d\n",conversione_colonna(colonna_bianca),riga_bianca+1,conversione_colonna(colonna_bianca-1),riga_bianca);
                }
            }
        if(Scacchiera[riga_bianca-1][colonna_bianca+1]=='N'){
                if(Scacchiera[riga_bianca-2][colonna_bianca+2]=='X'){
                    printf("La pedina bianca che si trova in %c%d mangia la pedina nera che si trova in %c%d\n",conversione_colonna(colonna_bianca),riga_bianca+1,conversione_colonna(colonna_bianca+1),riga_bianca);
                }
            }
}
}
//Funzione calcolo pedine bianche catturabili richiamata da funzione principale
void trova_possibili_pedine_bianche_catturabili(int riga_nera,int colonna_nera){
    if(riga_nera<7){
        if(colonna_nera==7||colonna_nera==6){
            if(Scacchiera[riga_nera+1][colonna_nera-1]=='B'){
                if(Scacchiera[riga_nera+2][colonna_nera-2]=='X'){
                    printf("La pedina nera che si trova in %c%d mangia la pedina bianca che si trova in %c%d\n",conversione_colonna(colonna_nera),riga_nera+1,conversione_colonna(colonna_nera-1),riga_nera+2);
                    return;
                }
            }
        }
        if(colonna_nera==0||colonna_nera==1){
            if(Scacchiera[riga_nera+1][colonna_nera+1]=='B'){
                if(Scacchiera[riga_nera+2][colonna_nera+2]=='X'){
                    printf("La pedina nera che si trova in %c%d mangia la pedina bianca che si trova in %c%d\n",conversione_colonna(colonna_nera),riga_nera+1,conversione_colonna(colonna_nera+1),riga_nera+2);
                    return;
                }
            }
        }
        if(Scacchiera[riga_nera+1][colonna_nera-1]=='B'){
                if(Scacchiera[riga_nera+2][colonna_nera-2]=='X'){
                    printf("La pedina nera che si trova in %c%d mangia la pedina bianca che si trova in %c%d\n",conversione_colonna(colonna_nera),riga_nera+1,conversione_colonna(colonna_nera-1),riga_nera+2);
                }
            }
        if(Scacchiera[riga_nera+1][colonna_nera+1]=='B'){
                if(Scacchiera[riga_nera+2][colonna_nera+2]=='X'){
                    printf("La pedina nera che si trova in %c%d mangia la pedina bianca che si trova in %c%d\n",conversione_colonna(colonna_nera),riga_nera+1,conversione_colonna(colonna_nera+1),riga_nera+2);
                }
            }
}
}
//Funzione per la conversione da numeri a lettere riguardante le colonne
char conversione_colonna(int colonna){
switch(colonna){
    case 0:
       return 'A';
    case 1:
       return 'B';
    case 2:
       return 'C';
    case 3:
       return 'D';
    case 4:
       return 'E';
    case 5:
       return 'F';
    case 6:
       return 'G';
    case 7:
       return 'H';
}
}
//main del programma
int main()
{
srand(time(NULL));
posizionamento_pedine();
visualizza_scacchiera();
calcolo_pedine_catturabili();
}
