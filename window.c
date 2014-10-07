#include "window.h"

void init_window(const char *window_title)
{
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), window_title);
	gtk_window_set_default_size(GTK_WINDOW(window), 640, 480);
	gtk_container_set_border_width(GTK_CONTAINER(window), 2);

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
}
