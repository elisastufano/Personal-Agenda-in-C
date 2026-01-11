/*
 * ordinamento.h
 *
 *  Created on: 3 Nov 2022
 *      Author: elisa
 */


/**
 *@file ordinamento.h
 *
 *Sottoprogrammi per l'ordinamento dei FILE in base alla durata.
 *
 *@date 27/10/2022
 *
 *@authors Catherine Martin, Elisa Stufano.
 */


#ifndef ORDINAMENTO_H_
#define ORDINAMENTO_H_

/**
 * Funzione che copia le durate dal FILE ad un array temporaneo.
 * @param registrazione: FILE che contiene le registrazioni inserite dall'utente.
 */
void copia_ordinamento(FILE* registrazione);

/**
 * Funzione che ordina l'array delle durate.
 * @param vett: Array delle durate delle registrazioni.
 * @param dim: dimensione dell'array delle durate.
 */
void ShellSort(int vett[], int dim);

/**
 * Funzione che stampa a schermo il FILE ordinato.
 * @param registrazione:  FILE che contiene le registrazioni inserite dall'utente.
 * @param array: Array delle durate delle registrazioni.
 * @param l: lunghezza dell'array delle durate.
 */
void stampa_ordinata(FILE *registrazione, int *array, int l );


#endif

