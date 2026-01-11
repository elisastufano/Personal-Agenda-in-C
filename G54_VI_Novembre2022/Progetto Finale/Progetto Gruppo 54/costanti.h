/*
 * costanti.h
 *
 *  Created on: 27 ott 2022
 *      Author: Elisa e Catherine
 */
/**
 *@file costanti.h
 *
 *
 *@date 27/10/2022
 *
 *@authors Catherine Martin, Elisa Stufano.
 */

#ifndef COSTANTI_H_
#define COSTANTI_H_
///Numero minimo di opzioni del menu principale.
#define MIN 1
///Numero massimo di opzioni del menu principale.
#define MAX 5
///Numero minimo che la variabile tipologia può assumere.
#define MIN_TIPOLOGIA 0
///Numero massimo che la variabile tipologia può assumere.
#define MAX_TIPOLOGIA 4
///Numero massimo opzioni menu modifica.
#define OPZIONE_CONTRASSEGNO 2
///Numero massimo caratteri che possono essere inseriti nella descrizione della registrazione.
#define DESCRIZIONE 26
///Numero massimo di eventi/appuntamenti/promemoria che possono essere inseriti.
#define NUMERO_REGISTRAZIONI_MAX 99
///Numero minimo che può essere generato nella funzione random.
#define MIN_CODICE 0
///Numero massimo che può essere generato nella funzione random.
#define MAX_CODICE 99
///Lunghezza massima che può avere la stringa tipologia o contrassegno.
#define MAX_TIPO 20
///Opzione massima dei menu registrazioni.
#define MAX_MENU 6
///Costante caratteri massima per il controllo del della stringa.
#define MAX_CONTROLLO_STRINGA 50
///Costante di minuti minimi della durata
#define DURATA_MIN 0
///Costante di minuti massimi della durata
#define DURATA_MAX 1000
///Costante numerica del mese di febbraio
#define FEBBRAIO 2
///Costante numerica del mese di aprile
#define APRILE 4
///Costante numerica del mese di giugno
#define GIUGNO 6
///Costante numerica del mese di settembre
#define SETTEMBRE 9
///Costante numerica del mese di novrembre
#define NOVEMBRE 11


///Struct contenente il numero di ricorrenze di una data tipologia.
typedef struct {

	int n_lavoro;
	int n_svago;
	int n_studio;
	int n_varie;
	int n_salute;

}statistiche_tipo;

///Dati sulla data.
typedef struct {

	int giorno;
	int mese;
	int anno;

}data;


///Dati sulla tipologia.
typedef enum { Lavoro , Svago , Studio , Salute , Varie } tipologia;



///Dati sull'orario.
typedef struct {

	int ora;
	int minuti;

}orario;





///Dati sulle varie registrazioni.
typedef struct {
	data data_registrazione;
	int codice_registrazione;
	char descrizione[DESCRIZIONE];
    int durata;
    orario ora_inizio;
    int contrassegno;
    tipologia tipo;

}registrazioni ;


#endif
