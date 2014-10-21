#include "treeview.h"

void set_up_treeview()
{
	int i;
	char buf[80];

	model = gtk_tree_store_new(2, G_TYPE_BOOLEAN, G_TYPE_STRING);

	treeview = gtk_tree_view_new_with_model(GTK_TREE_MODEL(model));

	bool_renderer = gtk_cell_renderer_toggle_new();
	text_renderer = gtk_cell_renderer_text_new();

	bool_column = gtk_tree_view_column_new_with_attributes(
		" ", 
		bool_renderer,
		"active",
		0,
		NULL
	);

	text_column = gtk_tree_view_column_new_with_attributes(
		"Nombre",
		text_renderer,
		"text",
		1,
		NULL
	);

	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), bool_column);
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), text_column);

	for (i = 1; i <= 1000; i++){
		sprintf(buf, "Item %d", i);
		gtk_tree_store_append(model, &iterator, NULL);

		gtk_tree_store_set(
			model,
			&iterator,
			0, 0,
			1, buf,
			-1
		);
	}
}
