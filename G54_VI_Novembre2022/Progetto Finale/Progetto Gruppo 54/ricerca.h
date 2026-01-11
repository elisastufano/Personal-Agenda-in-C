/*
 * ricerca.h
 *
*  Created on: 27 ott 2022
 *      Author: Elisa e Catherine
 */

/**
 *ricerca.h
 *
 *Sottoprogrammi per la ricerca delle registrazioni.
 *
 *@date 27/10/2022
 *
 *@authors Catherine Martin, Elisa Stufano.
 */


#ifndef RICERCA_H_
#define RICERCA_H_


/**
 * Funzione di ricerca di una registrazione.
 */
void ricerca_registrazione();


/**
 * Funzione di ricerca di una registrazionie in base alla data.
 * @param file: FILE che contiene le registrazioni inserite dall'utente.
 * @param ricerca_data: Data ricercata dall'utente.
 * @param stampa: Valore che può assumere 1 2 o 3 in base a che file trovata la registrazione.
 * @return Flag di ricerca andata a buon fine o meno.
 */
int ricerca_data (FILE *file, data ricerca_data, int stampa );


/**
 *
 * @param file: FILE che contiene le registrazioni inserite dall'utente.
 * @param stampa: Valore che può assumere 1 2 o 3 in base a che file trovata la registrazione.
 * @return Flag di ricerca andata a buon fine o meno.
 */
int ricerca_contrassegno(FILE* file, int stampa);

#endif
