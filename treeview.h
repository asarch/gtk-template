#ifndef _TREEVIEW_H_
#define _TREEVIEW_H_

#ifndef _MAIN_H_
#include "main.h"
#endif

GtkWidget *treeview;
GtkTreeStore *model;
GtkTreeIter iterator;

GtkCellRenderer *bool_renderer;
GtkCellRenderer *text_renderer;

GtkTreeViewColumn *bool_column;
GtkTreeViewColumn *text_column;

#endif /* #ifndef _TREEVIEW_H_ */
