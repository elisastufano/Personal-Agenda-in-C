#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "costanti.h"
#include "operazioni.h"
#include "menu.h"
#include "controllo_inserimenti.h"


int generazione_codice_random (int max, int min) {

	int seed = time(NULL);
	srand(seed);

	int valore =rand() % (max-min+1) + min;
	return valore;
}



void visualizza_codici(FILE* registrazione) {

	registrazioni struct_appoggio  = { {0, 0, 0} ,  0 , "" , 0 , {0 , 0} };

	rewind(registrazione);
	fread(&struct_appoggio, sizeof(registrazioni), 1, registrazione);
    printf ("\n\nCODICI REGISTRAZIONI EFFETTUATE:\n\n");

    while (!feof(registrazione)){

    	 if (struct_appoggio.codice_registrazione != 0){
    		printf("----> %d\n", struct_appoggio.codice_registrazione);
    	}
    	  fread(&struct_appoggio, sizeof(registrazioni), 1, registrazione);
    	}

        printf ("\n*********FINE LISTA CODICI*********\n\n\n");
}



void conversione_tipologia(tipologia *tipo , char tipologia[]) {

	    char lavoro[] = "lavoro";
		char svago [] = "svago";
		char studio[] = "studio";
		char salute[] = "salute";
		char varie [] = "varie";

		switch (*tipo) {

			        case Lavoro:
			          strcpy(tipologia, lavoro);
			          break;

			        case Svago :
			          strcpy(tipologia, svago);
		 			  break;

					case Studio:
					  strcpy(tipologia, studio);
				      break;

			        case Salute:
					  strcpy(tipologia, salute);
				      break;

					case  Varie:
					  strcpy(tipologia, varie);
				      break;
	   }
}



void inserimento_modifica (registrazioni *struct_appoggio, int *scelta, int *contrassegno){

	int tipologia= 0;

	switch(*scelta){

		case 1:
			printf("\nDescrizione precedente: %s",struct_appoggio->descrizione);
			printf ("\nInserire la descrizione aggiornata: ");
			fgets(struct_appoggio->descrizione, MAX_CONTROLLO_STRINGA, stdin) ;
			controllo_lung_descrizione(struct_appoggio->descrizione);
			break;

		case 2:
			printf("\nData precedente: %d/%d/%d\n",struct_appoggio->data_registrazione.giorno, struct_appoggio->data_registrazione.mese, struct_appoggio->data_registrazione.anno);
			printf ("\nInserire la data aggiornata [GG MM AAAA]: ");
			controllo_data(&struct_appoggio->data_registrazione);
	        break;

		case 3:
			printf("\nOrario precedente: %d:%d", struct_appoggio->ora_inizio.ora, struct_appoggio->ora_inizio.minuti);
			printf("\nInserire l'orario aggiornato [HH MM]: ");
			controllo_orario(&struct_appoggio->ora_inizio);
			break;

		case 4:
			printf("\nDurata precedente: %u", struct_appoggio->durata);
			printf("\nInserire la durata aggiornata [in minuti]: ");
			controllo_durata(&struct_appoggio->durata);
			break;

		case 5:
			printf("\nTipologia precedente: %u", struct_appoggio->tipo);
			printf ("\nInserisci la tipologia aggiornata:\n [0]. LAVORO\n [1]. SVAGO\n [2]. STUDIO\n [3]. SALUTE\n [4]. VARIE\n\n");
		    controllo_tipologia(&tipologia);
		    struct_appoggio->tipo = tipologia;
			break;

	    case 6:
			printf ("\nVuoi contrassegnarla come importante?[PER INSERIRE IL CONTRASSEGNO PREMERE 1 , ALTRIMENTI PREMERE 2]\n");
			scanf ("%d", contrassegno);
			struct_appoggio->contrassegno = controllo_inserimento_menu(MIN, OPZIONE_CONTRASSEGNO,struct_appoggio->contrassegno);
	        break;

		default:
			break;
		}

}




int conteggio_file (FILE* registrazione) {

	registrazioni struct_appoggio  = { {0, 0, 0} ,  0 , "" , 0 , {0 , 0} };
    int n_reg=0;

			rewind(registrazione);
			fread(&struct_appoggio, sizeof(registrazioni), 1, registrazione);

       while (!feof(registrazione)) {

		  if (struct_appoggio.codice_registrazione != 0){
		   n_reg++;
		   }

	   fread(&struct_appoggio, sizeof(registrazioni), 1, registrazione);
	  }

		  if (n_reg==0) {
		    setbuf(stdout, NULL);
		    printf ("\n\n\t\t\t\t      ---------------------LA LISTA E VUOTA----------------------\n");
		   }

return n_reg;
}


