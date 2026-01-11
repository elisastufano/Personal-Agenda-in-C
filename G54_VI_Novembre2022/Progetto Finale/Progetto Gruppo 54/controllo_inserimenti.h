/*
 * controllo_inserimenti.h
 *
 *  Created on: 27 ott 2022
 *      Author: Elisa e Catherine
 */

/**
 *@file controllo_inserimenti.h
 *
 *Sottoprogrammi per controllare gli input inseriti dall'utente.
 *
 *@date 27/10/2022
 *
 *@authors Catherine Martin, Elisa Stufano.
 */


#ifndef CONTROLLO_INSERIMENTI_H_
#define CONTROLLO_INSERIMENTI_H_

/**
 *
 * @param registrazione: FILE che contiene le registrazioni inserite dall'utente.
 * @param codice: codice generato dalla funzione random.
 */
void controllo_generazione_codice (FILE* registrazione, int codice);

/**
 * Funzione che controlla se l'utente ha i nserito correttamente il codice di scelta del menu principale.
 * @param minimo: numero minimo del range della scelta del menu.
 * @param massimo: numero massimo del range della scelta del menu.
 * @param num: numero che inserisce l'utente.
 * @return numero corretto inserito dall'utente.
 */
int controllo_inserimento_menu (int minimo , int massimo, int num );

/**
 * Funzione che controlla che il codice inserito dall'utente corrisponde ad una registrazione esistente.
 * @param registrazione: FILE che contiene le registrazioni inserite dall'utente.
 * @param codice_inserito: codice inserito in input dall'utente.
 * @return codice corretto inserito dall'utente.
 */
void controllo_codice (FILE* registrazione , int *codice_inserito);

void controllo_orario();
void controllo_data();

/**
 *Funzione che controlla se la durata inserita è una stringa o un intero.
 * @param durata: puntatore alla durata inserita dall'utente.
 */
void controllo_durata(int* durata);

/**
 *Funzione che controlla se la lunghezza della descrizione è corretta.
 * @param stringa: descrizione inserita dall'utente
 */
void controllo_lung_descrizione(char *stringa);

/**
 * Funzione che controlla se la tipologia inserita dall'utente.
 * @param scelta: intero inserito dall'utente
 */
void controllo_tipologia(int *scelta);


#endif
