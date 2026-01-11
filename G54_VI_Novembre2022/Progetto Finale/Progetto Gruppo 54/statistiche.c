#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "costanti.h"
#include "operazioni.h"
#include "menu.h"
#include "controllo_inserimenti.h"
#include "statistiche.h"
#include "manipolazioni_inserimenti.h"


void statistiche(statistiche_tipo tipo, int n_reg, int durata_totale) {
system("cls");
char risposta[MIN];

if (durata_totale!=0) {
printf("\nLE PERCENTUALI DELLE REGISTRAZIONI IN BASE ALLA TIPOLOGIA SONO:\n\n");
printf ("\n*LAVORO* : %.2f PERCENTO", (((float)tipo.n_lavoro*100)/n_reg));
printf ("\n*STUDIO* : %.2f PERCENTO", ((float)tipo.n_studio*100)/n_reg);
printf ("\n*SALUTE* : %.2f PERCENTO", ((float)(tipo.n_salute*100)/n_reg));
printf ("\n*SVAGO*  : %.2f PERCENTO", ((float)tipo.n_svago*100)/n_reg);
printf ("\n*VARIE*  : %.2f PERCENTO", ((float)tipo.n_varie*100)/n_reg);
printf("\n==============================================================\n\n");
printf("LA DURATA MEDIA DELLE REGISTRAZIONI E: \n\n");
printf("%.1fmin",((float)durata_totale/n_reg));
printf("\n\n==============================================================\n\n");
printf ("\nPREMI QUALISASI TASTO PER TORNARE AL MENU PRINCIPALE\n");
scanf("%s",risposta);

system("cls");

} else {
	printf ("*****NON ESISTONO REGISTRAZIONI PER LE STATISTICHE!*****");
}

}



void valori_statistiche(FILE *registrazione) {

int n_reg=0;
statistiche_tipo tipologie= {0 , 0, 0, 0, 0};
int durata_totale=0;
registrazioni struct_temporanea = { {0, 0, 0} ,  0 , "" , 0 , {0 , 0} };

  rewind(registrazione);
  fread(&struct_temporanea, sizeof(registrazioni), 1, registrazione);

      while (!feof(registrazione)) {

	if (struct_temporanea.codice_registrazione != 0){

          switch (struct_temporanea.tipo) {
          case 0:
	      ++tipologie.n_lavoro;
	      break;
          case 1:
	      ++tipologie.n_svago;
	      break;
          case 2:
       	  ++tipologie.n_studio;
	      break;
          case 3:
	      ++tipologie.n_salute;
	      break;
          case 4:
	      ++tipologie.n_varie;
	      break;
         }

	 }

	fread(&struct_temporanea, sizeof(registrazioni), 1, registrazione);

  }

 n_reg = conteggio_file(registrazione);
 statistica_durata(registrazione, &durata_totale);
 statistiche(tipologie, n_reg, durata_totale);

}



void statistica_durata(FILE* registrazione,  int *durata_tot) {

	registrazioni struct_temporanea = { {0, 0, 0} ,  0 , "" , 0 , {0 , 0} };

	rewind(registrazione);
	fread(&struct_temporanea, sizeof(registrazioni), 1, registrazione);

	while (!feof(registrazione)) {

		if (struct_temporanea.codice_registrazione != 0){
			*durata_tot += struct_temporanea.durata;
		}

		fread(&struct_temporanea, sizeof(registrazioni), 1, registrazione);
    }
}
