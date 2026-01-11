#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "controllo_inserimenti.h"
#include "menu.h"
#include "costanti.h"
#include "operazioni.h"
#include "manipolazioni_inserimenti.h"
#include "statistiche.h"
#include "ricerca.h"


void ricerca_registrazione(){

	int scelta_ricerca=0;
	data valore_ricerca;
	char scelta;

	FILE *promemoria;
		promemoria= fopen ("Promemoria.dat", "rb+") ;
	FILE *appuntamento;
		appuntamento= fopen ("Appuntamento.dat", "rb+");
	FILE* evento;
        evento = fopen ("Eventi.dat", "rb+");

		   if (evento == NULL) {

			 printf("\n\n\n*********** Impossibile aprire il file************* \n\n");
		 }

		   else if (promemoria == NULL) {

             printf("\n\n\n*********** Impossibile aprire il file************* \n\n");
		 }

            else if (appuntamento == NULL) {

             printf("\n\n\n*********** Impossibile aprire il file************* \n\n");

            }

           printf("\n=================================================================\n");
		   printf ("\nINSERIRE:");
		   printf("\n\n(1) EFFETTUARE UNA RICERCA IN BASE ALLA DATA DELLA REGISTRAZIONE\n(2) EFFETTUARE UNA RICERCA DELLE REGISTRAZIONI IMPORTANTI\n");
		   printf("\n=================================================================");
		   printf("\n----> ");
		   scanf("%d", &scelta_ricerca);

   if (scelta_ricerca == 1) {

       do {
        printf ("\nInserire la data della registrazione desiderata [FORMATO: GG MM AAAA] ---> ");
        controllo_data(&valore_ricerca.giorno, &valore_ricerca.mese, &valore_ricerca.anno);

        if (ricerca_data(evento, valore_ricerca, 1)==0){
	     printf ("\nNon ci sono eventi corrispondenti alla data inserita.\n");
        }
        if(ricerca_data(appuntamento, valore_ricerca, 2)==0){
	    printf("\nNon ci sono appuntamenti corrispondenti alla data inserita.\n");
        }
        if(ricerca_data(promemoria, valore_ricerca, 3)==0){
	    printf("\nNon ci sono promemoria corrispondenti alla data inserita.\n");
        }


     printf ("\nVuoi cercare un'altra registrazione? [S] si , qualsiasi altro tasto per tornare al menu\n");
     fflush(stdin);
     scanf ("%c", &scelta);

   } while (scelta == 's' || scelta == 'S' );

		   } else if (scelta_ricerca==2){

			   if(ricerca_contrassegno(evento, 1)==0){
			   		 printf ("\nNon ci sono eventi importanti.\n\n");
			   }
			   if(ricerca_contrassegno(appuntamento, 2)==0){
			   	   printf("\nNon ci sono appuntamenti importanti.\n\n");
			    }
			   if(ricerca_contrassegno(promemoria, 3)==0){
			   	printf("\nNon ci sono promemoria importanti.\n\n");
			    }

 fclose(evento);
 fclose(appuntamento);
 fclose(promemoria);

		   } else {
		   	  printf("\nOpzione non valida.\n");
		   	  fflush(stdin);
		   	  ricerca_registrazione();
		   }

menu_iniziale();

}



int ricerca_data (FILE *file, data ricerca_data, int stampa){

	int flag =0;
	char tipologia[MAX_TIPO];
	char contrassegno[MAX_TIPO];
	registrazioni struct_appoggio;

	    switch(stampa) {
	     case 1 :
	     printf("\n\n===========================================================================================================================================\n");
	     printf ("\nEVENTI TROVATI:\n\n");
	     printf("  %-1s\t %-10s\t %-9s\t %-9s \t%10s\t\t %-10s\t\t %-7s\n", "*DATA* ", "*CODICE*", "*DURATA*", "*ORARIO*","*CONTRASSEGNO*", "*TIPOLOGIA*", "*DESCRIZIONE*\n" );

	     break;
	     case 2:
	     printf("\n\n===========================================================================================================================================\n");
	     printf ("\nAPPUNTAMENTI TROVATI:\n\n");
	     printf("  %-1s\t %-10s\t %-9s\t %-9s \t%10s\t\t %-10s\t\t %-7s\n", "*DATA* ", "*CODICE*", "*DURATA*", "*ORARIO*","*CONTRASSEGNO*", "*TIPOLOGIA*", "*DESCRIZIONE*\n" );
	     break;
	     case 3:
	     printf("\n\n===========================================================================================================================================\n");
	     printf ("\nPROMEMORIA TROVATI:\n\n");
	     printf("  %-1s\t %-10s\t %-9s\t %-9s \t%10s\t\t %-10s\t\t %-7s\n", "*DATA* ", "*CODICE*", "*DURATA*", "*ORARIO*","*CONTRASSEGNO*", "*TIPOLOGIA*", "*DESCRIZIONE*\n" );
	     break;
	    }

	rewind(file);
	fread(&struct_appoggio, sizeof(registrazioni), 1, file);


	do {
          if ((struct_appoggio.data_registrazione.giorno == ricerca_data.giorno) && (struct_appoggio.data_registrazione.mese == ricerca_data.mese) && (struct_appoggio.data_registrazione.anno == ricerca_data.anno)){

	               if (struct_appoggio.contrassegno==2){
	               char temporaneo[] = "IMPORTANTE!";
	               strcpy(contrassegno, temporaneo);
	               } else {
	               char temporaneo[] = "          ";
	               strcpy(contrassegno, temporaneo);
	               }

	               conversione_tipologia(&struct_appoggio.tipo, tipologia);

	    	       printf("\n%.2d/%.2d/%.2d\t   %d\t\t  %d min\t  %.2d:%.2d \t %s\t\t   %s\t \t  %s", struct_appoggio.data_registrazione.giorno, struct_appoggio.data_registrazione.mese, struct_appoggio.data_registrazione.anno, struct_appoggio.codice_registrazione ,  struct_appoggio.durata, struct_appoggio.ora_inizio.ora, struct_appoggio.ora_inizio.minuti, contrassegno, tipologia , struct_appoggio.descrizione);
                   flag=1;
	         }

          fread(&struct_appoggio, sizeof(registrazioni), 1, file);

		} while (!feof(file));

return flag;

}


int ricerca_contrassegno(FILE* file, int stampa) {
	 int flag =0 ;
     char tipologia[MAX_TIPO];
     char contrassegno[MAX_TIPO];
	 registrazioni struct_appoggio;

		  switch(stampa) {
		        case 1 :
		        printf("\n\n===========================================================================================================================================\n");
		        printf ("\nEVENTI TROVATI:\n\n");
		        printf("  %-1s\t %-10s\t %-9s\t %-9s \t%10s\t\t %-10s\t\t %-7s\n", "*DATA* ", "*CODICE*", "*DURATA*", "*ORARIO*","*CONTRASSEGNO*", "*TIPOLOGIA*", "*DESCRIZIONE*\n" );
		        break;
		        case 2:
		        printf("\n\n===========================================================================================================================================\n");
		        printf ("\nAPPUNTAMENTI TROVATI:\n\n");
		        printf("  %-1s\t %-10s\t %-9s\t %-9s \t%10s\t\t %-10s\t\t %-7s\n", "*DATA* ", "*CODICE*", "*DURATA*", "*ORARIO*","*CONTRASSEGNO*", "*TIPOLOGIA*", "*DESCRIZIONE*\n" );
		        break;
		        case 3:
		        printf("\n\n===========================================================================================================================================\n");
		        printf ("\nPROMEMORIA TROVATI:\n\n");
		        printf("  %-1s\t %-10s\t %-9s\t %-9s \t%10s\t\t %-10s\t\t %-7s\n", "*DATA* ", "*CODICE*", "*DURATA*", "*ORARIO*","*CONTRASSEGNO*", "*TIPOLOGIA*", "*DESCRIZIONE*\n" );
		        break;
		 }

		rewind(file);
		fread(&struct_appoggio, sizeof(registrazioni), 1, file);

		do {
		if (struct_appoggio.contrassegno == 2){

			char temporaneo[] = "IMPORTANTE!";
		    strcpy(contrassegno, temporaneo);

		    conversione_tipologia(&struct_appoggio.tipo, tipologia);

		    printf("%.2d/%.2d/%d\t   %d\t\t  %d min\t   %.2d:%.2d  \t %s\t\t   %s\t \t  %s\n", struct_appoggio.data_registrazione.giorno, struct_appoggio.data_registrazione.mese, struct_appoggio.data_registrazione.anno, struct_appoggio.codice_registrazione ,  struct_appoggio.durata, struct_appoggio.ora_inizio.ora, struct_appoggio.ora_inizio.minuti, contrassegno, tipologia , struct_appoggio.descrizione);
            flag=1;
		}
		    fread(&struct_appoggio, sizeof(registrazioni), 1, file);

		} while (!feof(file));

return flag;

}
