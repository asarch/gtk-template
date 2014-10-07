/*
 *  Autor              : Alef Sheridan Ariel R. Ch.
 *  Fecha              : Julio del 2014
 *  Version            : 1.0
 *  Nombre del programa: GTK+ Template
 *  Descipcion         : Programa en C con lo minimo para crear
 *                       una aplicacion basada en GTK+ 3.x
 */
#include <string.h>

#include "callbacks.h"

int main(int argc, char *argv[])
{
	GtkWidget *scrolled_window;

	GtkWidget *text_view;
	GtkTextBuffer *text_buffer;

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
	gtk_container_add(GTK_CONTAINER(scrolled_window), treeview);

	/* Status bar */
	init_statusbar();
	gtk_box_pack_start(GTK_BOX(client_area), statusbar, FALSE, FALSE, 0);

	gtk_widget_show_all(window);
	gtk_main();

	return EXIT_SUCCESS;
}
