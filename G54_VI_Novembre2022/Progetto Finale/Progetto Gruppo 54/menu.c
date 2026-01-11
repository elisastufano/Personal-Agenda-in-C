#include <stdlib.h>
#include <stdio.h>
#include "controllo_inserimenti.h"
#include "menu.h"
#include "costanti.h"
#include "operazioni.h"
#include "manipolazioni_inserimenti.h"
#include "statistiche.h"
#include "ricerca.h"



int menu_iniziale () {
	int opzione=0;

			puts ("\n\n************************************************************\n");
	     	puts ("           # BENVENUTO NELLA TUA AGENDA PERSONALE #");
	     	puts ("\n************************************************************\n");
	     	puts ("SCEGLIERE UN'OPZIONE:\n");
			puts ("(1)\tGESTIONE EVENTI\t\t\t\t(DIGITARE 1)\n(2)\tGESTIONE APPUNTAMENTI\t\t\t(DIGITARE 2)\n(3)\tGESTIONE PROMEMORIA\t\t\t(DIGITARE 3)\n(4)\tRICERCA REGISTRAZIONE\t\t\t(DIGITARE 4)\n(5)\tPER CHIUDERE L'ESECUZIONE DEL PROGRAMMA\t(DIGITARE 5)");
			printf ("\n-------> ");
			fflush(stdin);
			scanf ("%d", &opzione);
			scelta_menu_iniziale(opzione);
			return opzione;

}




void scelta_menu_iniziale (int opzione) {

	int scelta = opzione;
	scelta = controllo_inserimento_menu(MIN, MAX, scelta);


			switch (scelta) {

					case 1:
						gestione_eventi();
					    break;
					case 2:
						gestione_appuntamenti();
					    break;
					case 3:
						gestione_promemoria();
						break;
					case 4:
						ricerca_registrazione();
						break;
					case 5:
						exit(0);
					default:
						printf ("valore errato\n");
					  break;
				    }

menu_iniziale();
}




void gestione_eventi() {

	system("cls");
	int scelta=0;
	printf("__________________________________________________________________");
    printf ("\n\n  ******************  MENU GESTIONE EVENTI  ******************  \t\t\n");
    printf("__________________________________________________________________\n\n");
 	puts ("\nSCEGLIERE UN'OPZIONE:\n");
    printf ("\n\n(1)\tAGGIUNGERE EVENTO\t\t(DIGITARE 1)\n(2)\tMODIFICA EVENTO\t\t\t(DIGITARE 2)\n(3)\tVISUALIZZA TABELLA EVENTI\t(DIGITARE 3)\n(4)\tELIMINA EVENTO\t\t\t(DIGITARE 4)\n(5)\tVISUALIZZA STATISTICHE\t\t(DIGITARE 5)\n(6)\tRITORNA AL MENU PRINCIPALE \t(DIGITARE 6)\n") ;
    printf ("\n\n-------> ");
    scanf ("%d", &scelta);
    scelta =controllo_inserimento_menu(MIN, MAX_MENU, scelta);

	FILE* evento;

	evento = fopen ("Eventi.dat", "rb+");

	if (evento==NULL) {

			             printf("\n\n\n*********** Impossibile aprire il file************* \n\n");

			  }


	else {
        	switch (scelta) {
					case 1:
						printf ("\n\nInserire i dettagli dell'evento:\n");
						aggiungere(evento);
					    break;
					case 2:
						modifica(evento);
					    break;
					case 3:
						visualizza(evento);
						break;
					case 4:
						eliminazione(evento);
						break;
					case 5:
						printf("\n__________________________________________________________________");
						printf ("\n\n  ****************** STATISTICHE EVENTI  ******************  \t\t\n");
						printf("__________________________________________________________________\n\n");
						printf("\n==============================================================");
					    valori_statistiche(evento);
						break;
					case 6:
						menu_iniziale();
						break;
					default:
						printf ("valore errato\n");
					  break;
				    }

	}

fclose(evento);

}



void gestione_appuntamenti(){

	system("cls");
	FILE *appuntamento;
	appuntamento= fopen ("Appuntamento.dat", "rb+");


	 if (appuntamento == NULL) {

					   printf("\n\n\n*********** Impossibile aprire il file************* \n\n");
			   }

	 else {


	int scelta=0;
	    printf("__________________________________________________________________");
	    printf ("\n\n****************** MENU GESTIONE APPUNTAMENTI ******************\t\t\n");
	    printf("__________________________________________________________________\n\n");
	 	puts ("\nSCEGLIERE UN'OPZIONE:\n");
	    printf ("\n\n(1)\tAGGIUNGERE APPUNTAMENTO\t\t(DIGITARE 1)\n(2)\tMODIFICA APPUNTAMENTO\t\t(DIGITARE 2)\n(3)\tVISUALIZZA TABELLA APPUNTAMENTI\t(DIGITARE 3)\n(4)\tELIMINA APPUNTAMENTO\t\t(DIGITARE 4)\n(5)\tVISUALIZZA STATISTICHE\t\t(DIGITARE 5)\n(6)\tRITORNA AL MENU PRINCIPALE \t(DIGITARE 6)\n") ;
	    printf ("\n\nSCELTA ---> ");
	    scanf ("%d", &scelta);
	    scelta =controllo_inserimento_menu (MIN,  MAX_MENU, scelta);



		     switch (scelta) {
						case 1:
							printf ("\n\nInserire i dettagli dell'appuntamento:\n");
							aggiungere(appuntamento);
						    break;
						case 2:
							modifica(appuntamento);
						    break;
						case 3:
							visualizza(appuntamento);
							break;
						case 4:
							eliminazione(appuntamento);
							break;
						case 5:
							printf("\n__________________________________________________________________");
							printf ("\n\n  ****************** STATISTICHE APPUNTAMENTI  ******************  \t\t\n");
							printf("__________________________________________________________________\n\n");
						    printf("\n==============================================================");
		                    valori_statistiche(appuntamento);
							break;
						case 6:
							menu_iniziale();
							break;
                        default:
							printf ("valore errato\n");
							break;
					    }

	 }

fclose(appuntamento);

}



void gestione_promemoria() {

	system("cls");
	FILE *promemoria;
	promemoria= fopen ("Promemoria.dat", "rb+") ;

	 if (promemoria == NULL) {

		                printf("\n\n\n*********** Impossibile aprire il file************* \n\n");
	 }



    else {


	int scelta=0;

	        printf("__________________________________________________________________");
		    printf ("\n\n  ****************** MENU GESTIONE PROMEMORIA ******************\t\t\n");
		    printf("__________________________________________________________________\n\n");
		 	puts ("\nSCEGLIERE UN'OPZIONE:\n");
		    printf ("\n\n(1)\tAGGIUNGERE PROMEMORIA\t\t(DIGITARE 1)\n(2)\tMODIFICA PROMEMORIA\t\t(DIGITARE 2)\n(3)\tVISUALIZZA TABELLA PROMEMORIA\t(DIGITARE 3)\n(4)\tELIMINA PROMEMORIA\t\t(DIGITARE 4)\n(5)\tVISUALIZZA STATISTICHE\t\t(DIGITARE 5)\n(6)\tRITORNA AL MENU PRINCIPALE \t(DIGITARE 6)\n") ;
		    printf ("\nSCELTA ----> ");
		    scanf ("%d", &scelta);
		    scelta =controllo_inserimento_menu (MIN, MAX_MENU, scelta);



			    switch (scelta) {
			 				case 1:
								printf ("\n\nInserire i dettagli del promemoria:\n");

								aggiungere(promemoria);
							    break;
							case 2:
								modifica(promemoria);
							    break;
							case 3:
								visualizza(promemoria);
								break;
							case 4:
								eliminazione(promemoria);
								break;
							case 5:
								printf("\n__________________________________________________________________");
								printf ("\n\n  ****************** STATISTICHE PROMEMORIA  ******************  \t\t\n");
								printf("__________________________________________________________________\n\n");
								printf("\n==============================================================");
								valori_statistiche(promemoria);
								break;
							case 6:
								menu_iniziale();
								break;
							default:
								printf ("valore errato\n");

							  break;
						    }

		                }
   fclose(promemoria);

}

