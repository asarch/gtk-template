#ifndef _MENU_H_
#define _MENU_H_

#ifndef _MAIN_H_
#include "main.h"
#endif

void open_file_callback1(GtkWidget *widget, gpointer data);
void about_menu_item_callback1(GtkWidget *widget, gpointer data);


/*
 * void open_file(GtkWidget *widget, gpointer data)
 *
 */

GtkWidget *get_menu(GtkWidget *);

#endif /* #ifndef _MAIN_H_ */