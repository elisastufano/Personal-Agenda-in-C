/*
 * operazioni.h
 *
 *  Created on: 27 ott 2022
 *      Author: Elisa e Catherine
 */
/**
 *@file operazioni.h
 *
 *Sottoprogrammi che permettono le varie operazioni e modifiche sulle registrazioni.
 *
 *@date 27/10/2022
 *
 *@authors Catherine Martin, Elisa Stufano.
 */


#ifndef OPERAZIONI_H_
#define OPERAZIONI_H_

/**
 * Funzione che consente di aggiungere un'evento, un appuntamento o un promemoria.
 * @param registrazione: FILE che contiene le registrazioni inserite dall'utente.
 */
void aggiungere (FILE *registrazione);

/**
 * Funzione che consente di modificare uno o più campi di una o più registrazioni.
 * @param registrazione:  FILE che contiene le registrazioni inserite dall'utente.
 */
void modifica(FILE* registrazione);

/**
 * Funzione che consente all'utente di eliminare una o più registrazioni.
 * @param registrazione: FILE che contiene le registrazioni inserite dall'utente.
 */
void eliminazione( FILE* registrazione);

/**
 * Funzione che stampa tutte le registrazioni presenti nel FILE scelto.
 * @param registrazione
 */
void visualizza(FILE *registrazione);


#endif
