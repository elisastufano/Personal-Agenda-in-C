/*
 * controllo_inserimenti.h
 *
 *  Created on: 27 ott 2022
 *      Author: Elisa e Catherine
 */
/**
 *@file menu.h
 *
 *Sottoprogrammi dei Menu che contengono le varie operazioni.
 *
 *@date 27/10/2022
 *
 *@authors Catherine Martin, Elisa Stufano.
 */

#ifndef MENU_H_
#define MENU_H_

/**
 * Funzione che chiama i menu di gestione di eventi, appuntamenti e promemoria.
 * @param opzione: Scelta di qualche menu aprire.
 */
void scelta_menu_iniziale (int opzione); //funzione che contiene lo switch con le diverse scelte del menu//

/**
 * Menu iniziale che permette la scelta di varie operazioni.
 * @return opzione scelta dall'utente dal menu.
 */
int  menu_iniziale ();

/**
 * Menu di gestione degli eventi con le varie operazioni ammesse.
 */
void gestione_eventi();

/**
 * Menu di gestione degli appuntamenti con le varie operazioni annesse.
 */
void gestione_appuntamenti();

/**
 * Menu di gestione dei promemoria con le varie operazioni annesse.
 */
void gestione_promemoria();


#endif
