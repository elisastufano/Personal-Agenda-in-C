/*
 * statistiche.h
 *
 *  Created on: 27 ott 2022
 *      Author: Elisa e Catherine
 */
/**
 *@file statistiche.h
 *
 *Sottoprogrammi per le statistiche delle registrazioni.
 *
 *@date 27/10/2022
 *
 *@authors Catherine Martin, Elisa Stufano.
 */



#ifndef STATISTICHE_H_
#define STATISTICHE_H_

/**
 * Funzione che stampa a schermo le statistiche.
 * @param tipo: Struct che contiene la ricorrenza della tipologia delle registrazioni.
 * @param l: numero di registrazioni nel FILE.
 * @param durata_totale: somma di tutte le durate delle registrazioni.
 */
void statistiche(statistiche_tipo tipo, int l, int durata_totale);

/**
 * Funzione che calcola la ricorrenza delle tipologie delle registrazioni.
 * @param registrazione: FILE che contiene le registrazioni inserite dall'utente.
 */
void valori_statistiche(FILE *registrazione);

/**
 * Funzione che somma la durata di tutte le registrazioni.
 * @param registrazione: FILE che contiene le registrazioni inserite dall'utente.
 * @param durata_tot: somma delle durate di tutte le registrazioni.
 */
void statistica_durata(FILE *registrazione,  int *durata_tot);
#endif
