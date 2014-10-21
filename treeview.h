#ifndef _TREEVIEW_H_
#define _TREEVIEW_H_

#ifndef __GTK_H__
#include <gtk/gtk.h>
#endif

void set_up_treeview();

GtkWidget *treeview;
GtkTreeStore *model;
GtkTreeIter iterator;

GtkCellRenderer *bool_renderer;
GtkCellRenderer *text_renderer;

GtkTreeViewColumn *bool_column;
GtkTreeViewColumn *text_column;

#endif /* #ifndef _TREEVIEW_H_ */
