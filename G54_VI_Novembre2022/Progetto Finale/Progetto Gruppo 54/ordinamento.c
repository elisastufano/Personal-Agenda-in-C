#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "costanti.h"
#include "operazioni.h"
#include "menu.h"
#include "controllo_inserimenti.h"
#include "ordinamento.h"
#include "manipolazioni_inserimenti.h"

void stampa_ordinata(FILE *registrazione, int array[], int l) {
	system("cls");

	char scelta;
	registrazioni struct_appoggio;
	int i=0;
    char tipologia[MAX_TIPO];
	char stringa_appoggio[MAX_TIPO];
	printf ("\n========================================== LISTA REGISTRAZIONI INSERITE PER ORDINE CRESCENTE DI DURATA ========================================\n\n\n\n");
    printf("  %-1s\t %-10s\t %-9s\t %-9s \t%10s\t\t %-10s\t\t %-7s\n", "*DATA* ", "*CODICE*", "*DURATA*", "*ORARIO*","*CONTRASSEGNO*", "*TIPOLOGIA*", "*DESCRIZIONE*\n" );

	while (i<l){
		rewind (registrazione);


	while(!feof(registrazione)){
		fread(&struct_appoggio, sizeof(registrazioni),1, registrazione);
		if (struct_appoggio.codice_registrazione != 0){

		                  conversione_tipologia(&struct_appoggio.tipo, tipologia);

		                  if (struct_appoggio.contrassegno==2){
		                    	char temporaneo[] = "IMPORTANTE!";
		                    	strcpy(stringa_appoggio, temporaneo);
		                  } else {
		                    	char temporaneo[] = "          ";
		                    	strcpy(stringa_appoggio, temporaneo);
		                  }

		if ((!feof(registrazione)) && (struct_appoggio.durata==array[i])){

    		printf("%.2d/%.2d/%d\t   %d\t\t  %d min\t   %.2d:%.2d  \t %s\t\t   %s\t \t  %s\n", struct_appoggio.data_registrazione.giorno, struct_appoggio.data_registrazione.mese, struct_appoggio.data_registrazione.anno, struct_appoggio.codice_registrazione ,  struct_appoggio.durata, struct_appoggio.ora_inizio.ora, struct_appoggio.ora_inizio.minuti, stringa_appoggio, tipologia , struct_appoggio.descrizione);
    		i++;
	  }

    }

  }

}
	         int num_reg = conteggio_file(registrazione);
	         printf("\n\n\n==================================================== IL NUMERO DI REGISTRAZIONI TOTALI E: %d ===================================================\n\n", num_reg);
		     printf ("\n\n*********FINE LISTA CODICI*********\n\n\n");
		     printf ("Inserire qualsiasi tasto per tornare al menu principale\n\n");
	         scanf ("%s", &scelta);
	         system("cls");
}



void copia_ordinamento (FILE *registrazione) {

	short int l=0;
	int i=0;
	int array_durata[l];
	l= conteggio_file(registrazione);
	registrazioni prova;
	registrazioni struct_appoggio[l];

	rewind(registrazione);
    fread(&prova, sizeof(registrazioni), 1, registrazione);

	 while (!feof(registrazione)) {
		 if (prova.codice_registrazione != 0){

				 struct_appoggio[i]=prova;
				 i++;
			 }

		 fread(&prova, sizeof(registrazioni), 1, registrazione);
	 }

	 for (int j=0; j<l ; j++){
	    array_durata[j]=struct_appoggio[j].durata;
	 }

	 ShellSort(array_durata, l);
     stampa_ordinata(registrazione,array_durata, l);
}



void ShellSort(int vett[], int dim){

    	int i=0;
    	int j=0;
    	int gap=0;
    	int k=0;
    	int x =0;
    	int a[5];
    	a[0]=9; a[1]=5; a[2]=3; a[3]=2; a[4]=1;

    	for(k=0; k<5; k++){
    		gap = a[k];
    		for(i=gap; i<dim; i++){
    			x= vett[i];
    			for(j=i-gap;(x<vett[j]) && (j>=0); j=j-gap){
    				vett[j+gap]=vett[j];
    				vett[j]=x;
    			}
    		}
    	}
    }
