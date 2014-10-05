#ifndef _CALLBACKS_H_
#define _CALLBACKS_H_

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

GtkWidget *get_toolbar();

void open_file_callback(GtkWidget *widget, gpointer data);
void about_menu_item_callback(GtkWidget *widget, gpointer data);

#endif /* #ifndef _CALLBACKS_H_ */
