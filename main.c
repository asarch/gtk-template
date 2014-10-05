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

const char WINDOW_TITLE[] = "Template 1.0";

int main(int argc, char *argv[])
{
	GtkWidget *window;
	GtkWidget *client_area;

	GtkWidget *menu_bar_handle_box;
	GtkWidget *toolbar_handle_box;

	GtkWidget *scrolled_window;

	GtkWidget *text_view;
	GtkTextBuffer *text_buffer;

	gtk_init(&argc, &argv);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), WINDOW_TITLE);
	gtk_window_set_default_size(GTK_WINDOW(window), 640, 480);
	gtk_container_set_border_width(GTK_CONTAINER(window), 2);

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
	gtk_container_add(GTK_CONTAINER(menu_bar_handle_box), get_menu(window));

	/* Toolbar */
	toolbar_handle_box = gtk_handle_box_new();
	gtk_box_pack_start(GTK_BOX(client_area), toolbar_handle_box, FALSE, FALSE, 0);
	gtk_container_add(GTK_CONTAINER(toolbar_handle_box), get_toolbar());

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
	text_view = gtk_text_view_new();
	text_buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));
	gtk_container_add(GTK_CONTAINER(scrolled_window), text_view);

	gtk_box_pack_start(GTK_BOX(client_area), get_statusbar(), FALSE, FALSE, 0);

	gtk_widget_show_all(window);
	gtk_main();

	return EXIT_SUCCESS;
}
