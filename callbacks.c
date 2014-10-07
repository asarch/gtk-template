#include "callbacks.h"

void open_file_callback(GtkWidget *widget, gpointer data)
{
#ifdef _ALEF_H_
	GtkWidget *dialog;

	dialog = gtk_file_chooser_dialog_new(
		"Open File",
		NULL, /* parent_window, */
		GTK_FILE_CHOOSER_ACTION_OPEN,
		GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
		GTK_STOCK_OPEN, GTK_RESPONSE_ACCEPT,
		NULL
	);

	if (gtk_dialog_run (GTK_DIALOG (dialog)) == GTK_RESPONSE_ACCEPT) {
		/*
		char *filename;

		filename = gtk_file_chooser_get_filename (GTK_FILE_CHOOSER (dialog));
		*/
		/* open_file (filename); */

		/*
		 * En esta parte es donde se lee el archivo y
		 * se escribe su contenido al widget de TextView
		 *

		fprintf(stderr, filename);
		g_free (filename);
		 */
	}

	gtk_widget_destroy(dialog);
#endif
}
