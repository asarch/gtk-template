#ifndef _WINDOW_H_
#define _WINDOW_H_

#ifndef __GTK_H__
#include <gtk/gtk.h>
#endif

void set_up_window(const char *);

GtkWidget *window;
GtkWidget *client_area;

GtkWidget *menu_bar_handle_box;
GtkWidget *toolbar_handle_box;

#endif /* #ifndef _WINDOW_H_ */
