/*
 * controllo_inserimenti.h
 *
 *  Created on: 27 ott 2022
 *      Author: Elisa e Catherine
 */
/**
 *manipolazione_inserimenti.h
 *
 *Sottoprogrammi per la gestione degli input.
 *
 *@date 27/10/2022
 *
 *@authors Catherine Martin, Elisa Stufano.
 */

#ifndef MANIPOLAZIONI_INSERIMENTI_H_
#define MANIPOLAZIONI_INSERIMENTI_H_

/**
 * Funzione per la generazione del codice registrazioni random.
 * @param max: Numero massimo che il codice generato può assumere.
 * @param min: Numero minimo che il codice generato può assumere.
 * @return Codice generato.
 */
int  generazione_codice_random(int max, int min);

/**
 * Funzione di stampa per la visualizzazione dei codici delle registrazioni.
 * @param registrazione: FILE che contiene le registrazioni inserite dall'utente.
 */
void visualizza_codici(FILE* registrazione);

/**
 * Funzione che conta quante registrazioni stanno nel file.
 * @param registrazione: FILE che contiene le registrazioni inserite dall'utente.
 * @return Il numero delle registrazioni contenute nel FILE.
 */
int  conteggio_file (FILE* registrazione);

/**
 * Funzione che riceve la tipologia in enumerativo e la stampa a schermo in stringa.
 * @param tipo: Tipologia inserita dall'utente.
 * @param tipologia: Array di tutte le tipologie in stringhe.
 */
void conversione_tipologia (tipologia *tipo, char tipologia[]);

/**
 *Funzione che permette all'utente di modificare le registrazioni presenti nel FILE.
 * @param struct_appoggio: Struct contenente tutti i dati di una registrazione.
 * @param scelta: Inserimento dell'utente che indica quale campo di una registrazione vuol modificare.
 * @param contrassegno: Numero che specifica se una registrazione è importante o no.
 */
void inserimento_modifica (registrazioni *struct_appoggio , int *scelta, int *contrassegno);


#endif
