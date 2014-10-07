#ifndef _TOOLBAR_H_
#define _TOOLBAR_H_

#ifndef _MAIN_H_
#include "main.h"
#endif

void init_toolbar();

GtkWidget *toolbar;

GtkToolItem *toolbar_new_button;
GtkToolItem *toolbar_open_button;
GtkToolItem *toolbar_save_button;
GtkToolItem *toolbar_save_as_button;

GtkToolItem *toolbar_undo_button;
GtkToolItem *toolbar_redo_button;

GtkToolItem *toolbar_cut_button;
GtkToolItem *toolbar_copy_button;
GtkToolItem *toolbar_paste_button;

GtkToolItem *toolbar_find_button;
GtkToolItem *toolbar_replace_button;

GtkToolItem *toolbar_quit_button;

#endif /* #ifndef _TOOLBAR_H_ */
