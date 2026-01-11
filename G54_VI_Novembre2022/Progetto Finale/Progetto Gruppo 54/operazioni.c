#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "costanti.h"
#include "operazioni.h"
#include "menu.h"
#include "controllo_inserimenti.h"
#include "manipolazioni_inserimenti.h"
#include "ordinamento.h"


void aggiungere ( FILE *registrazione) {

system("cls");

	registrazioni struct_temporanea = { {0, 0, 0} ,  0 , "" , 0 , {0 , 0} };
    char risposta;
    int contrassegno = 0;
    int tipologia = 0;

	do {
	   printf ("\nInserisci la descrizione [MASSIMO 25 CARATTERI]:\n");
	   fflush(stdin);
	   fgets(struct_temporanea.descrizione, MAX_CONTROLLO_STRINGA, stdin) ;
	   controllo_lung_descrizione(struct_temporanea.descrizione);

	   printf ("\nInserisci la durata [in minuti]:\n");
	   controllo_durata(&struct_temporanea.durata);


       printf ("\n\nInserisci la data\t\t[FORMATO: GG MM AAAA]:\n");
	   controllo_data(&struct_temporanea.data_registrazione);


       printf ("\n\nInserisci l'orario di inizio\t\t[FORMATO: HH MM]:\n");
       controllo_orario(&struct_temporanea.ora_inizio);


       printf ("\n\nInserisci una tipologia \n\n [0]. LAVORO\n [1]. SVAGO\n [2]. STUDIO\n [3]. SALUTE\n [4]. VARIE\n");
       controllo_tipologia(&tipologia);
       struct_temporanea.tipo = tipologia;

       fflush(stdin);
       printf ("Vuoi contrassegnarla come importante? [PER INSERIRE IL CONTRASSEGNO PREMERE 2 , ALTRIMENTI PREMERE 1]\n");
       scanf ("%d", &contrassegno);
       contrassegno= controllo_inserimento_menu(MIN , OPZIONE_CONTRASSEGNO ,contrassegno);

       struct_temporanea.contrassegno = contrassegno;
       struct_temporanea.codice_registrazione = generazione_codice_random(MAX_CODICE, MIN_CODICE);

       printf ("\nREGISTRAZIONE EFFETTUATA CON SUCCESSO.\n IL CODICE DELLA REGISTRAZIONE E ---> \t%d\n", struct_temporanea.codice_registrazione );
       fseek(registrazione, (struct_temporanea.codice_registrazione-1)*sizeof(registrazioni), SEEK_SET );
       fwrite(&struct_temporanea, sizeof(registrazioni), 1, registrazione);

       fflush(stdin);
	   printf ("\nPREMI 'S' PER INSEIRE UN'ALTRA REGISTRAZIONE OPPURE PREMI QUALSIASI ALTRO TASTO PER TORNARE AL MENU INIZIALE\n\n");
	   scanf ("%c", &risposta);

	   system("cls");


	} while (risposta == 'S' || risposta == 's' );

	system("cls");

 }



void modifica(FILE* registrazione) {

	system("cls");
    rewind(registrazione);
	registrazioni struct_appoggio  = { {0, 0, 0} ,  0 , "" , 0 , {0 , 0} };
	int codice=0;
	int scelta=0;
	int contrassegno =0 ;
    char opzione ='s'; //opzione che verifica se l'utente vuole cointinuare a modificare//

    if (conteggio_file(registrazione)  == 0 ){

    printf (" ");

    }
    	else {


    while ((opzione =='s' || opzione == 'S' ) ){

    visualizza_codici(registrazione); //funzione che visalizza i codici//
	printf ("Inserire il codice della registrazione che vorresti modificare\n\n");
	//scanf("%d", &codice); //ricordati il controllo se il codice esiste e anche di mettere la stampa delle informazioni della registrazione
	controllo_codice (registrazione,&codice);

	printf ("Cosa vorresti modificare? \n(1)La descrizione\n(2)La data\n(3)L'orario\n(4)La durata\n(5)Tipologia\n(6)Contrassegno\n\n");
	scanf ("%d", &scelta);
	scelta = controllo_inserimento_menu(MIN, MAX, scelta);

	fseek(registrazione, (codice - 1) * sizeof(registrazioni), SEEK_SET);
	fread(&struct_appoggio, sizeof(registrazioni), 1, registrazione);
	fseek(registrazione, (codice - 1) * sizeof(registrazioni), SEEK_SET);

    inserimento_modifica (&struct_appoggio, &scelta, &contrassegno);
    fseek(registrazione, (codice - 1) * sizeof(registrazioni), SEEK_SET);
    fwrite(&struct_appoggio, sizeof(registrazioni), 1, registrazione);

    printf ("\nMODIFICA EFFETTUATA CON SUCCESSO\n");
    printf ("Vuoi effettuare un'altra modifica?\nPREMI S SE SI O QUALSIASI ALTRO TASTO PER TORNARE AL MENU\n");
    scanf ("%s", &opzione);
    }

}
    system("cls");

}



void eliminazione(FILE* registrazione) {
	system("cls");

    int codice_eliminazione=0;
    char risposta = 's';
    registrazioni struct_da_copiare;
    while ( (risposta == 's' || risposta == 'S') && (conteggio_file(registrazione)  != 0 ) ) {
	visualizza_codici(registrazione);
	printf ("*Inserisci il codice della registrazione che vorresti eliminare*\n");

    controllo_codice(registrazione, &codice_eliminazione);
    fseek(registrazione, (codice_eliminazione - 1) * sizeof(registrazioni), SEEK_SET);
    fread(&struct_da_copiare, sizeof(registrazioni),1, registrazione);
    printf("\n#DATA#: %d/%d/%d\t #DESCRIZIONE#: %s \n", struct_da_copiare.data_registrazione.giorno, struct_da_copiare.data_registrazione.mese, struct_da_copiare.data_registrazione.anno, struct_da_copiare.descrizione);

	registrazioni struct_da_eliminare  = { {0, 0, 0} ,  0 , "" , 0 , {0 , 0} };
    fseek(registrazione, (codice_eliminazione - 1) * sizeof(registrazioni), SEEK_SET);
	fwrite (&struct_da_eliminare, sizeof (registrazioni), 1, registrazione);

    puts ("****ELIMINAZIONE EFFETTUATA CON SUCCESSO****");
    puts ("VUOI ELIMNARE UN'ALTRA PRENOTAZIONE? CLICCA (S) SE si E QUALSISASI ALTRO TASTO SE VUOI RITORNARE AL MENU PRINCIPALE");
    scanf ("%s", &risposta);

    }

    system("cls");
}



void visualizza(FILE* registrazione){
	system("cls");
    fflush(stdin);
	copia_ordinamento(registrazione);
}
