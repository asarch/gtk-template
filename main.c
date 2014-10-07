/*
 *  Autor              : Alef Sheridan Ariel R. Ch.
 *  Fecha              : Julio del 2014
 *  Version            : 1.0
 *  Nombre del programa: GTK+ Template
 *  Descipcion         : Programa en C con lo minimo para crear
 *                       una aplicacion basada en GTK+ 3.x
 */
#include "menu.h"
#include "toolbar.h"
#include "statusbar.h"
#include "window.h"

#include <string.h>

int main(int argc, char *argv[])
{
	GtkWidget *client_area;

	GtkWidget *menu_bar_handle_box;
	GtkWidget *toolbar_handle_box;

	GtkWidget *scrolled_window;

	GtkWidget *text_view;
	GtkTextBuffer *text_buffer;

	GtkWidget *treeview;
	GtkTreeStore *model;
	GtkTreeIter iterator;

	GtkCellRenderer *bool_renderer;
	GtkCellRenderer *text_renderer;

	GtkTreeViewColumn *bool_column;
	GtkTreeViewColumn *text_column;

	int i;
	char buf[80];

	gtk_init(&argc, &argv);
	init_window("Template 1.0");

	g_signal_connect_swapped(
		G_OBJECT(window),		/* El widget			*/
		"destroy",			/* El mensaje que deseas	*/
		G_CALLBACK(gtk_main_quit),	/* La funcion que respondera	*/
		NULL				/* Los datos que le daras	*/
	);

	/* Main container */
	client_area = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	gtk_container_add(GTK_CONTAINER(window), client_area);

	/* Menu bar */
	menu_bar_handle_box = gtk_handle_box_new();
	gtk_box_pack_start(GTK_BOX(client_area), menu_bar_handle_box, FALSE, FALSE, 0);

	init_menu();
	gtk_container_add(GTK_CONTAINER(menu_bar_handle_box), menu_bar);

	/* Toolbar */
	toolbar_handle_box = gtk_handle_box_new();
	gtk_box_pack_start(GTK_BOX(client_area), toolbar_handle_box, FALSE, FALSE, 0);

	init_toolbar();
	gtk_container_add(GTK_CONTAINER(toolbar_handle_box), toolbar);

	/* Scrolled Window */
	scrolled_window = gtk_scrolled_window_new(NULL, NULL);
	gtk_scrolled_window_set_shadow_type(GTK_SCROLLED_WINDOW(scrolled_window), GTK_SHADOW_IN);

	gtk_scrolled_window_set_policy(
		GTK_SCROLLED_WINDOW(scrolled_window),
		GTK_POLICY_ALWAYS,
		GTK_POLICY_ALWAYS
	);

	gtk_box_pack_start(GTK_BOX(client_area), scrolled_window, TRUE, TRUE, 0);

	/* Textview widget */
	/*
	text_view = gtk_text_view_new();
	text_buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));
	gtk_container_add(GTK_CONTAINER(scrolled_window), text_view);
	*/

	/* Treeview */
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

	gtk_container_add(GTK_CONTAINER(scrolled_window), treeview);

	/* Status bar */
	init_statusbar();
	gtk_box_pack_start(GTK_BOX(client_area), statusbar, FALSE, FALSE, 0);

	gtk_widget_show_all(window);
	gtk_main();

	return EXIT_SUCCESS;
}
