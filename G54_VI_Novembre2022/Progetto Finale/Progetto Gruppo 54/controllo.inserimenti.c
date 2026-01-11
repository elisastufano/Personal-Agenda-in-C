#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "menu.h"
#include "costanti.h"
#include "manipolazioni_inserimenti.h"
#include "operazioni.h"


void controllo_generazione_codice (FILE* registrazione, int codice) {


	registrazioni struct_appoggio  = { {0, 0, 0} ,  0 , "" , 0 , {0 , 0} };

		rewind(registrazione);
		fread(&struct_appoggio, sizeof(registrazioni), 1, registrazione);

	    while (!feof(registrazione)){
	    	 if (struct_appoggio.codice_registrazione == codice){

	    		 generazione_codice_random(MAX_CODICE, MIN_CODICE);

	    	}
	    	  fread(&struct_appoggio, sizeof(registrazioni), 1, registrazione);
	    	}
}


int controllo_inserimento_menu (int minimo, int massimo, int num) {

fflush(stdin);
int numero= num;

while (numero<minimo || numero>massimo) {

	printf ("\nValore inserito errato, riprova--> ");
	scanf ("%d", &numero);
	setbuf(stdout,NULL);
	fflush(stdin);
   }

return numero;

}



void controllo_codice (FILE* registrazione, int *codice_inserito) {


	int flag = 0;
    int c=0; //variabile controllo stringa

	do{

	       fflush(stdin);

	   c =scanf("\n%d", codice_inserito);


    fseek(registrazione, (*codice_inserito - 1) * sizeof(registrazioni), SEEK_SET);

	registrazioni struct_appoggio;

	fread(&struct_appoggio, sizeof(registrazioni), 1, registrazione);

    fflush(stdin);


           while (struct_appoggio.codice_registrazione != *codice_inserito) {


        	   while(c==0) {
        	  	     printf ("Attenzione: input non valido. Riprova. \n ");
        	  	     c =scanf("\n%d", codice_inserito);
        	  	    fflush(stdin);

        	   }

         	flag=1;
    	    printf ("\nIl codice inserito non esiste! Riprova ---> ");
    	    c=scanf("%d", codice_inserito);
    	    fseek(registrazione, (*codice_inserito - 1) * sizeof(registrazioni), SEEK_SET);
    		fread(&struct_appoggio, sizeof(registrazioni), 1, registrazione);
         }

	} while ( (flag == 1) && (c==0) );

}


/**
 *Funzione che controlla se l'orario inserito è corretto e non è una stringa
 *@param puntatore :puntatore alla struct di due interi inseriti dall'utente, ora e minuti.
 */
void controllo_orario(orario *puntatore){

	 int flag= 0;
	 int c= 0;

	 do{

	       fflush(stdin);

	       c =scanf("\n%d%d", &puntatore->ora, &puntatore->minuti);

	       if (c == 0) {

	     while (getchar() != '\n');
	     printf ("Attenzione: input non valido. Riprova. \n ");
	     }

		 while (puntatore->ora>23 || puntatore->ora<0){
		 printf("\nL'ora inserita non e valida! Riprova! \n");
		 c =scanf("\n%d%d", &puntatore->ora, &puntatore->minuti);

		 fflush(stdin);
		 flag=1;
		 }

		 while (puntatore->minuti>59 || puntatore->minuti<0 ){
		 printf("\nI minuti inseriti non sono validi! Riprova! \n");
		 c =scanf("\n%d%d", &puntatore->ora, &puntatore->minuti);

		 fflush(stdin);
		 flag=1;
		 }

		 } while ( (c==0) && (flag ==0) );
 }


/**
 *Funziona che controlla se la data inserita dall'utente è un intero ed è nel range giusto.
 *
 * @param puntatore: puntatore alla struct di tre interi inseriti dall'utente, giorno mese e anno..
 */
void controllo_data(data *puntatore){

int flag=0;
int c=0;


	do {
	       fflush(stdin);

		 c =scanf("\n%d%d%d", &puntatore->giorno, &puntatore->mese, &puntatore->anno);

		if (c == 0) {

	   while (getchar() != '\n');
       printf ("Attenzione: input non valido. Riprova. \n ");
	}
	 else{

	   while (puntatore->giorno>31||puntatore->giorno<1){
	   printf("\nIl giorno inserito non e valido. Riprova. \n");
	   c =scanf("\n%d%d%d", &puntatore->giorno, &puntatore->mese, &puntatore->anno);

	   fflush(stdin);
	   flag=1;

	} while (puntatore->mese>12 || puntatore->mese<1){

		printf("\nIl mese inserito non e valido. Riprova. \n");
		c =scanf("\n%d%d%d", &puntatore->giorno, &puntatore->mese, &puntatore->anno);

		fflush(stdin);
		flag=1;

	} while (puntatore->anno<2020 || puntatore->anno>2030){
		printf("\nL'anno inserito non e valido. Riprova. \n");
		c =scanf("\n%d%d%d", &puntatore->giorno, &puntatore->mese, &puntatore->anno);
		fflush(stdin);
		flag =1;

	}

	if (puntatore->mese == APRILE || puntatore->mese == GIUGNO || puntatore->mese == SETTEMBRE || puntatore->mese == NOVEMBRE) {
	   while (puntatore->giorno > 30){
			 fflush(stdin);
			 printf ("Il giorno inserito non e' valido, inserire la data nuovamente:\n");
             c =scanf("\n%d%d%d", &puntatore->giorno, &puntatore->mese, &puntatore->anno);
	   }

	}

	   while (puntatore->mese == FEBBRAIO && (puntatore->anno %4 ==0) && (puntatore->giorno >29)) {
				 fflush(stdin);
                 printf ("Il giorno inserito non e' valido, inserire la data nuovamente:\n");
				 c =scanf("\n%d%d%d", &puntatore->giorno, &puntatore->mese, &puntatore->anno);
	   }


	   while ( (puntatore->mese == FEBBRAIO) && (puntatore->anno %4!=0) && (puntatore->giorno >28) ) {
				 fflush(stdin);
                 printf ("Il giorno inserito non e' valido, inserire la data nuovamente:\n");
				 c =scanf("\n%d%d%d", &puntatore->giorno, &puntatore->mese, &puntatore->anno);
	   }
	}

 } while ( (c==0) && (flag ==0) );

}



void controllo_durata (int* durata) {

	int flag=0;
	int c=0;

	do {
		     fflush(stdin);
			 c =scanf("\n%d", durata);

		   if (c == 0) {
		    while (getchar() != '\n');
            printf ("Attenzione: input non valido. Riprova. \n ");
		}
		   while ( (*durata<DURATA_MIN) || (*durata>DURATA_MAX) ){
			printf("\nLa durata inserita non e valida. Riprova. \n");
			c =scanf("\n%d", durata);

			fflush(stdin);
			flag=1;
			}

	} while ( (c==0) && (flag ==0) );
}



void controllo_lung_descrizione(char *stringa){

	while (strlen(stringa)>=DESCRIZIONE){
		fflush(stdin);
		printf ("\nDescrizione troppo lunga. Riprova.\n");
		scanf ("%s", stringa);
	}
}



void controllo_tipologia(int *scelta){

 int c=0;
 int flag=0;
 do {
	     fflush(stdin);
		 c =scanf("\n%d", scelta);

	  if (c == 0) {
		   printf ("Attenzione: input non valido. Riprova. \n ");
			   }
	  while((*scelta<MIN_TIPOLOGIA) || (*scelta>MAX_TIPOLOGIA)){
				printf("\nLa tipologia inserita non e valida. Riprova. \n");
				c =scanf("\n%d", scelta);

				fflush(stdin);
				flag=1;
				}

			} while ( (c==0) && (flag==0) ) ;
}
