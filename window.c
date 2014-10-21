#include "window.h"

void set_up_window(const char *window_title)
{
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), window_title);
	gtk_window_set_default_size(GTK_WINDOW(window), 640, 480);
	gtk_container_set_border_width(GTK_CONTAINER(window), 2);

	/* Main container */
	client_area = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	gtk_container_add(GTK_CONTAINER(window), client_area);
}
