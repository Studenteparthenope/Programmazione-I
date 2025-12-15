#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
/*
Dizionario della lingua italiana
Si vuole simulare la gestione di un dizionario della lingua italiana.
Il dizionario è  indicizzato tramite le lettere dell’alfabeto ed
ogni parola contiene i sinonimi (massimo 5) e la sua spiegazione.
Permettere all’utente di:
• Inserire una parola (mantenere l’ordine alfabetico)
• Ricercare una parola nel dizionario e visualizzare il significato
Provvedere all’implementazione dell’algoritmo per la simulazione del dizionario.
Effettuare almeno un test per ognuna delle opzioni richieste dall’utente.
*/
typedef struct{
char parola [100];
char significato[100];
char *sinonimi[5];
}Parola;

/*Prototipi*/

void opzioni();
void visualizza_significato(char *);
void creazione_dizionario();
Parola Dizionario[20];
int parole_dizionario=5;

int main(){
    creazione_dizionario();
    ordinamento();
    opzioni();
    return 0;
}

void opzioni(){
        char scelta;
        char parola[30];
        while(1){
            printf("[1]Inserire parola\n");
            printf("[2]Visualizza il significato\n");
            printf("[3]Exit");
            printf("\n");
            scelta = getch();
                switch(scelta){
                    case '1':
                        Inserimento_parola();
                        break;
                    case '2':
        printf("\nInserisci la parola da ricercare: ");
                scanf("%s",&parola);
                fflush(stdin);
                    visualizza_significato(parola);
                printf("\n");
                system("pause");
                break;
        }
                if(scelta == '3')
                    break;
                system("cls");
    }
}

void visualizza_significato(char parola[]){
        int i;
        for(i=0;i<parole_dizionario;i++){
            if(strcmp(Dizionario[i].parola,parola) == 0){
        printf("\n%s",Dizionario[i].significato);
                return;
        }
    }
    printf("\nLa parola non si trova nel Dizionario!\n");
}
void Inserimento_parola(){
    char parola[100];
    char significato[100];
    printf("\nDigita la parola da inserire: ");
    gets(parola);
    fflush(stdin);
    printf("\nInserire il suo significato: ");
    gets(significato);
    fflush(stdin);
    strcpy(Dizionario[parole_dizionario].parola,parola);
    strcpy(Dizionario[parole_dizionario].significato,significato);
    parole_dizionario++;
    ordinamento();
}
void ordinamento(){
    int i,j;
    Parola el_da_ins;
for(i=1;i<parole_dizionario;i++){
    el_da_ins=Dizionario[i];
    j=i-1;
while(j>0 && strcmp(el_da_ins.parola,Dizionario[j].parola)<0){
    Dizionario[j+1]=Dizionario[j];
    j--;
  }
    Dizionario[j+1]=el_da_ins;
  }
}

void creazione_dizionario(){
strcpy(Dizionario[0].parola,"vedere");
strcpy(Dizionario[0].significato,"Percepire con gli occhi, cogliere con la facoltà della vista");
Dizionario[0].sinonimi[0]="Osservare";
Dizionario[0].sinonimi[1]="Guardare";
Dizionario[0].sinonimi[2]="Percepire";
Dizionario[0].sinonimi[3]="Scorgere";
Dizionario[0].sinonimi[4]="Scrutare";

strcpy(Dizionario[1].parola,"ascoltare");
strcpy(Dizionario[1].significato,"Udire attentamente qualcuno,accogliere come consiglio, ammonimento o direttiva morale.");
Dizionario[1].sinonimi[0]="Origliare";
Dizionario[1].sinonimi[1]="Usciolare";
Dizionario[1].sinonimi[2]="Auscultare";
Dizionario[1].sinonimi[3]="Sentire";
Dizionario[1].sinonimi[4]="Assistere";

strcpy(Dizionario[2].parola,"giocare");
strcpy(Dizionario[2].significato,"Dedicarsi a un gioco per ricreazione o passatempo");
Dizionario[2].sinonimi[0]="Distrarsi";
Dizionario[2].sinonimi[1]="Divertirsi";
Dizionario[2].sinonimi[2]="Giochicchiare";
Dizionario[2].sinonimi[3]="Giocherellare";
Dizionario[2].sinonimi[4]="Svagarsi";

strcpy(Dizionario[3].parola,"camminare");
strcpy(Dizionario[3].significato,"Spostarsi, procedere andando a piedi");
Dizionario[3].sinonimi[0]="Procedere";
Dizionario[3].sinonimi[1]="Dirigersi";
Dizionario[3].sinonimi[2]="Andare";
Dizionario[3].sinonimi[3]="Avviarsi";
Dizionario[3].sinonimi[4]="Avanzare";

strcpy(Dizionario[4].parola,"lanciare");
strcpy(Dizionario[4].significato,"Gettare con forza e lontano.");
Dizionario[4].sinonimi[0]="Buttare";
Dizionario[4].sinonimi[1]="Gettare";
Dizionario[4].sinonimi[2]="Scagliare";
Dizionario[4].sinonimi[3]="Scaraventare";
Dizionario[4].sinonimi[4]="Tirare";
}
