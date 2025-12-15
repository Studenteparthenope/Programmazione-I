# Programmazione-I
In questo progetto sono state elaborate due tracce distinte con linguaggio C dove in una prima traccia si è pensato a creare la simulazione del classico gioco da tavola che è la Dama; e nella seconda traccia è stata invece sviluppata una interrogazione di dizionario.

Il progetto d'esame si articola in due sezioni distinte, entrambe incentrate sull'implementazione di algoritmi e strutture dati in un contesto applicativo.

### 1. Gioco della Dama (Algoritmo di Cattura)

L'obiettivo è simulare una fase iniziale del gioco della Dama su una scacchiera 8x8. L'algoritmo prevede:

* **Inizializzazione:** Disposizione casuale di 5 Pedine Bianche ('B') e 5 Pedine Nere ('N') esclusivamente sulle caselle nere.
* **Visualizzazione:** Rappresentazione della scacchiera dove le caselle nere libere sono indicate con 'X' e le caselle bianche con uno spazio.
* **Logica di Cattura:** Determinazione delle possibili catture effettuate dalle Pedine Bianche. Una cattura è valida solo se:
    1.  La Pedina Nera è adiacente in diagonale e "in avanti" (verso l'alto).
    2.  La casella successiva a quella della Pedina Nera, lungo la stessa diagonale, è libera.
* **Output:** Visualizzazione dell'elenco delle Pedine Nere catturabili, specificando la Pedina Bianca che può effettuare la cattura, utilizzando la notazione standard della Dama (es. `colonna` + `riga`, come `b2`).

### 2. Dizionario della Lingua Italiana (Struttura Dati)

Questa sezione si concentra sulla simulazione di un dizionario con funzionalità di gestione del testo e implementazione di strutture dati appropriate.

* **Struttura:** Il dizionario deve essere indicizzato per lettera alfabetica. Ogni voce (parola) deve includere la spiegazione e un massimo di 5 sinonimi.
* **Funzionalità Richieste:**
    * **Inserimento:** L'utente deve poter inserire nuove parole, assicurando che il dizionario mantenga l'ordine alfabetico.
    * **Ricerca:** L'utente deve poter ricercare una parola esistente e visualizzarne il significato (spiegazione).
* **Implementazione:** Si richiede l'algoritmo che simuli tale gestione, unitamente all'esecuzione di almeno un test per ciascuna delle operazioni (`Inserimento` e `Ricerca`).
