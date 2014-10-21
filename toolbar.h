#ifndef _TOOLBAR_H_
#define _TOOLBAR_H_

#ifndef __GTK_H__
#include <gtk/gtk.h>
#endif

void set_up_toolbar();

GtkWidget *toolbar;

GtkToolItem *new_tool_item;
GtkToolItem *open_tool_item;
GtkToolItem *save_tool_item;
GtkToolItem *save_as_tool_item;

GtkToolItem *undo_tool_item;
GtkToolItem *redo_tool_item;

GtkToolItem *cut_tool_item;
GtkToolItem *copy_tool_item;
GtkToolItem *paste_tool_item;

GtkToolItem *find_tool_item;
GtkToolItem *replace_tool_item;

GtkToolItem *quit_tool_item;

#endif /* #ifndef _TOOLBAR_H_ */
