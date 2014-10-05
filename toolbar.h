#ifndef _TOOLBAR_H_
#define _TOOLBAR_H_

#ifndef _MAIN_H_
#include "main.h"
#endif

GtkWidget *get_toolbar();

void open_file_callback(GtkWidget *widget, gpointer data);
void about_menu_item_callback(GtkWidget *widget, gpointer data);

#endif /* #ifndef _TOOLBAR_H_ */
