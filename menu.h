#ifndef _MENU_H_
#define _MENU_H_

#ifndef __GTK_H__
#include <gtk/gtk.h>
#endif

#ifndef __GDK_KEYSYMS_H__
#include <gdk/gdkkeysyms.h>
#endif

void set_up_menu(GtkWidget *);

GtkWidget *menu_bar;

GtkWidget *file_menu_item;
GtkWidget *file_menu;
GtkWidget *new_menu_item;
GtkWidget *open_menu_item;
GtkWidget *save_menu_item;
GtkWidget *save_as_menu_item;
GtkWidget *quit_menu_item;

GtkWidget *edit_menu_item;
GtkWidget *edit_menu;
GtkWidget *undo_menu_item;
GtkWidget *redo_menu_item;
GtkWidget *cut_menu_item;
GtkWidget *copy_menu_item;
GtkWidget *paste_menu_item;
GtkWidget *clear_menu_item;
GtkWidget *select_all_menu_item;

GtkWidget *search_menu_item;
GtkWidget *search_menu;
GtkWidget *find_menu_item;
GtkWidget *find_next_menu_item;
GtkWidget *find_previous_menu_item;
GtkWidget *replace_menu_item;
GtkWidget *clear_highlight_menu_item;
GtkWidget *goto_line_menu_item;

GtkWidget *help_menu_item;
GtkWidget *help_menu;
GtkWidget *about_menu_item;

#endif /* #ifndef _MAIN_H_ */
