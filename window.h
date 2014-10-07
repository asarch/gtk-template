#ifndef _WINDOW_H_
#define _WINDOW_H_

#ifndef _MAIN_H_
#include "main.h"
#endif

#ifndef _MENU_H_
#include "menu.h"
#endif

#ifndef _TOOLBAR_H_
#include "toolbar.h"
#endif

void init_window(const char *);

GtkWidget *window;
GtkWidget *client_area;

GtkWidget *menu_bar_handle_box;
GtkWidget *toolbar_handle_box;

#endif /* #ifndef _WINDOW_H_ */
