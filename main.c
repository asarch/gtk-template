/*
 *  Autor              : Alef Sheridan Ariel R. Ch.
 *  Fecha              : Julio del 2014
 *  Version            : 1.0
 *  Nombre del programa: GTK+ Template
 *  Descipcion         : Programa en C con lo minimo para crear
 *                       una aplicacion basada en GTK+ 3.x
 */
#include <gtk/gtk.h>
#include <gdk/gdkkeysyms.h>

#include <stdlib.h>

const char WINDOW_TITLE[] = "Template 1.0";

void about_menu_item_callback(GtkWidget*, gpointer);
void open_file_callback(GtkWidget*, gpointer);

int main(int argc, char *argv[])
{
	GtkWidget *window;
	GtkWidget *client_area;
	GtkAccelGroup *accel_group;

	GtkWidget *menu_bar;
	GtkWidget *menu_bar_handle_box;

	GtkWidget *file_menu_item;
	GtkWidget *file_menu;
	GtkWidget *new_menu_item;
	GtkWidget *open_menu_item;
	GtkWidget *save_menu_item;
	GtkWidget *save_as_menu_item;
	GtkWidget *quit_menu_item;

	GtkWidget *edit_menu_item;
	GtkWidget *edit_menu;
	GtkWidget *undo_menu_item;
	GtkWidget *redo_menu_item;
	GtkWidget *cut_menu_item;
	GtkWidget *copy_menu_item;
	GtkWidget *paste_menu_item;
	GtkWidget *delete_menu_item;
	GtkWidget *select_all_menu_item;

	GtkWidget *search_menu_item;
	GtkWidget *search_menu;
	GtkWidget *find_menu_item;
	GtkWidget *find_next_menu_item;
	GtkWidget *find_previous_menu_item;
	GtkWidget *replace_menu_item;
	GtkWidget *clear_highlight_menu_item;
	GtkWidget *goto_line_menu_item;

	GtkWidget *help_menu_item;
	GtkWidget *help_menu;
	GtkWidget *about_menu_item;

	GtkWidget *toolbar_handle_box;
	GtkWidget *toolbar;

	GtkToolItem *toolbar_new_button;
	GtkToolItem *toolbar_open_button;
	GtkToolItem *toolbar_save_button;
	GtkToolItem *toolbar_save_as_button;

	GtkToolItem *toolbar_undo_button;
	GtkToolItem *toolbar_redo_button;

	GtkToolItem *toolbar_cut_button;
	GtkToolItem *toolbar_copy_button;
	GtkToolItem *toolbar_paste_button;

	GtkToolItem *toolbar_find_button;
	GtkToolItem *toolbar_replace_button;

	GtkToolItem *toolbar_quit_button;

	GtkWidget *scrolled_window;

	GtkWidget *text_view;
	GtkTextBuffer *text_buffer;

	GtkWidget *statusbar;

	gtk_init(&argc, &argv);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), WINDOW_TITLE);
	gtk_window_set_default_size(GTK_WINDOW(window), 640, 480);
	gtk_container_set_border_width(GTK_CONTAINER(window), 2);

	accel_group = gtk_accel_group_new();
	gtk_window_add_accel_group(GTK_WINDOW(window), accel_group);

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

	menu_bar = gtk_menu_bar_new();
	gtk_container_add(GTK_CONTAINER(menu_bar_handle_box), menu_bar);

	/* File menu item */
	file_menu_item = gtk_menu_item_new_with_mnemonic("_File");
	gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), file_menu_item);

	file_menu = gtk_menu_new();
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(file_menu_item), file_menu);

	new_menu_item = gtk_image_menu_item_new_from_stock(GTK_STOCK_NEW, accel_group);
	open_menu_item = gtk_image_menu_item_new_from_stock(GTK_STOCK_OPEN, accel_group);
	save_menu_item = gtk_image_menu_item_new_from_stock(GTK_STOCK_SAVE, accel_group);
	save_as_menu_item = gtk_image_menu_item_new_from_stock(GTK_STOCK_SAVE_AS, accel_group);
	quit_menu_item = gtk_image_menu_item_new_from_stock(GTK_STOCK_QUIT, accel_group);

	gtk_widget_add_accelerator(new_menu_item, "activate", accel_group, GDK_KEY_N, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
	gtk_widget_add_accelerator(open_menu_item, "activate", accel_group, GDK_KEY_O, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
	gtk_widget_add_accelerator(save_menu_item, "activate", accel_group, GDK_KEY_S, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
	gtk_widget_add_accelerator(save_as_menu_item, "activate", accel_group, GDK_KEY_S, GDK_SHIFT_MASK | GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
	gtk_widget_add_accelerator(quit_menu_item, "activate", accel_group, GDK_KEY_Q, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);

	g_signal_connect(G_OBJECT(open_menu_item), "activate", G_CALLBACK(open_file_callback), NULL);
	g_signal_connect(G_OBJECT(quit_menu_item), "activate", G_CALLBACK(gtk_main_quit), NULL);

	gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), new_menu_item);
	gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), open_menu_item);
	gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), gtk_separator_menu_item_new());
	gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), save_menu_item);
	gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), save_as_menu_item);
	gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), gtk_separator_menu_item_new());
	gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), quit_menu_item);
	
	/* Edit menu item */
	edit_menu_item = gtk_menu_item_new_with_mnemonic("_Edit");
	gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), edit_menu_item);

	edit_menu = gtk_menu_new();
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(edit_menu_item), edit_menu);

	undo_menu_item = gtk_image_menu_item_new_from_stock(GTK_STOCK_UNDO, accel_group);
	redo_menu_item = gtk_image_menu_item_new_from_stock(GTK_STOCK_REDO, accel_group);

	cut_menu_item = gtk_image_menu_item_new_from_stock(GTK_STOCK_CUT, accel_group);
	copy_menu_item = gtk_image_menu_item_new_from_stock(GTK_STOCK_COPY, accel_group);
	paste_menu_item = gtk_image_menu_item_new_from_stock(GTK_STOCK_PASTE, accel_group);

	delete_menu_item = gtk_menu_item_new_with_mnemonic("_Delete");
	select_all_menu_item = gtk_menu_item_new_with_mnemonic("_Select All");

	gtk_widget_add_accelerator(undo_menu_item, "activate", accel_group, GDK_KEY_Z, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
	gtk_widget_add_accelerator(redo_menu_item, "activate", accel_group, GDK_KEY_Z, GDK_SHIFT_MASK | GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
	gtk_widget_add_accelerator(cut_menu_item, "activate", accel_group, GDK_KEY_X, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
	gtk_widget_add_accelerator(copy_menu_item, "activate", accel_group, GDK_KEY_C, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
	gtk_widget_add_accelerator(paste_menu_item, "activate", accel_group, GDK_KEY_V, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
	gtk_widget_add_accelerator(select_all_menu_item, "activate", accel_group, GDK_KEY_A, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);

	gtk_menu_shell_append(GTK_MENU_SHELL(edit_menu), undo_menu_item);
	gtk_menu_shell_append(GTK_MENU_SHELL(edit_menu), redo_menu_item);
	gtk_menu_shell_append(GTK_MENU_SHELL(edit_menu), gtk_separator_menu_item_new());
	gtk_menu_shell_append(GTK_MENU_SHELL(edit_menu), cut_menu_item);
	gtk_menu_shell_append(GTK_MENU_SHELL(edit_menu), copy_menu_item);
	gtk_menu_shell_append(GTK_MENU_SHELL(edit_menu), paste_menu_item);
	gtk_menu_shell_append(GTK_MENU_SHELL(edit_menu), delete_menu_item);
	gtk_menu_shell_append(GTK_MENU_SHELL(edit_menu), gtk_separator_menu_item_new());
	gtk_menu_shell_append(GTK_MENU_SHELL(edit_menu), select_all_menu_item);

	/* Search menu item */
	search_menu_item = gtk_menu_item_new_with_mnemonic("_Search");
	gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), search_menu_item);

	search_menu = gtk_menu_new();
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(search_menu_item), search_menu);

	find_menu_item = gtk_image_menu_item_new_from_stock(GTK_STOCK_FIND, accel_group);
	find_next_menu_item = gtk_menu_item_new_with_mnemonic("Find Next");
	find_previous_menu_item = gtk_menu_item_new_with_mnemonic("Find Previous");
	replace_menu_item = gtk_image_menu_item_new_from_stock(GTK_STOCK_FIND_AND_REPLACE, accel_group);
	clear_highlight_menu_item = gtk_menu_item_new_with_mnemonic("Clear Hightlight");
	goto_line_menu_item = gtk_menu_item_new_with_mnemonic("Goto Line");

	gtk_widget_add_accelerator(find_next_menu_item , "activate", accel_group, GDK_KEY_G, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
	gtk_widget_add_accelerator(find_previous_menu_item , "activate", accel_group, GDK_KEY_G, GDK_SHIFT_MASK | GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
	gtk_widget_add_accelerator(clear_highlight_menu_item , "activate", accel_group, GDK_KEY_K, GDK_SHIFT_MASK | GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
	gtk_widget_add_accelerator(goto_line_menu_item , "activate", accel_group, GDK_KEY_I, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);

	gtk_menu_shell_append(GTK_MENU_SHELL(search_menu), find_menu_item);
	gtk_menu_shell_append(GTK_MENU_SHELL(search_menu), find_next_menu_item);
	gtk_menu_shell_append(GTK_MENU_SHELL(search_menu), find_previous_menu_item);
	gtk_menu_shell_append(GTK_MENU_SHELL(search_menu), gtk_separator_menu_item_new());
	gtk_menu_shell_append(GTK_MENU_SHELL(search_menu), replace_menu_item);
	gtk_menu_shell_append(GTK_MENU_SHELL(search_menu), gtk_separator_menu_item_new());
	gtk_menu_shell_append(GTK_MENU_SHELL(search_menu), clear_highlight_menu_item);
	gtk_menu_shell_append(GTK_MENU_SHELL(search_menu), gtk_separator_menu_item_new());
	gtk_menu_shell_append(GTK_MENU_SHELL(search_menu), goto_line_menu_item);

	/* Help menu item */
	help_menu_item = gtk_menu_item_new_with_mnemonic("_Help");
	gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), help_menu_item);

	help_menu = gtk_menu_new();
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(help_menu_item), help_menu);

	about_menu_item = gtk_menu_item_new_with_mnemonic("_About");
	gtk_menu_shell_append(GTK_MENU_SHELL(help_menu), about_menu_item);
	g_signal_connect(G_OBJECT(about_menu_item), "activate", G_CALLBACK(about_menu_item_callback), NULL);

	/* Toolbar */
	toolbar_handle_box = gtk_handle_box_new();
	gtk_box_pack_start(GTK_BOX(client_area), toolbar_handle_box, FALSE, FALSE, 0);

	toolbar = gtk_toolbar_new();
	gtk_container_add(GTK_CONTAINER(toolbar_handle_box), toolbar);
	gtk_toolbar_set_style(GTK_TOOLBAR(toolbar), GTK_TOOLBAR_ICONS);
	gtk_container_set_border_width(GTK_CONTAINER(toolbar), 2);

	toolbar_new_button = gtk_tool_button_new_from_stock(GTK_STOCK_NEW);
	toolbar_open_button = gtk_tool_button_new_from_stock(GTK_STOCK_OPEN);
	toolbar_save_button = gtk_tool_button_new_from_stock(GTK_STOCK_SAVE);
	toolbar_save_as_button = gtk_tool_button_new_from_stock(GTK_STOCK_SAVE_AS);
	toolbar_quit_button = gtk_tool_button_new_from_stock(GTK_STOCK_QUIT);

	toolbar_undo_button = gtk_tool_button_new_from_stock(GTK_STOCK_UNDO);
	toolbar_redo_button = gtk_tool_button_new_from_stock(GTK_STOCK_REDO);

	toolbar_cut_button = gtk_tool_button_new_from_stock(GTK_STOCK_CUT);
	toolbar_copy_button = gtk_tool_button_new_from_stock(GTK_STOCK_COPY);
	toolbar_paste_button = gtk_tool_button_new_from_stock(GTK_STOCK_PASTE);

	toolbar_find_button = gtk_tool_button_new_from_stock(GTK_STOCK_FIND);
	toolbar_replace_button = gtk_tool_button_new_from_stock(GTK_STOCK_FIND_AND_REPLACE);

	gtk_toolbar_insert(GTK_TOOLBAR(toolbar), toolbar_new_button, -1);
	gtk_toolbar_insert(GTK_TOOLBAR(toolbar), toolbar_open_button, -1);
	gtk_toolbar_insert(GTK_TOOLBAR(toolbar), toolbar_save_button, -1);
	gtk_toolbar_insert(GTK_TOOLBAR(toolbar), toolbar_save_as_button, -1);

	gtk_toolbar_insert(GTK_TOOLBAR(toolbar), gtk_separator_tool_item_new(), -1);

	gtk_toolbar_insert(GTK_TOOLBAR(toolbar), toolbar_undo_button, -1);
	gtk_toolbar_insert(GTK_TOOLBAR(toolbar), toolbar_redo_button, -1);

	gtk_toolbar_insert(GTK_TOOLBAR(toolbar), gtk_separator_tool_item_new(), -1);

	gtk_toolbar_insert(GTK_TOOLBAR(toolbar), toolbar_cut_button, -1);
	gtk_toolbar_insert(GTK_TOOLBAR(toolbar), toolbar_copy_button, -1);
	gtk_toolbar_insert(GTK_TOOLBAR(toolbar), toolbar_paste_button, -1);

	gtk_toolbar_insert(GTK_TOOLBAR(toolbar), gtk_separator_tool_item_new(), -1);

	gtk_toolbar_insert(GTK_TOOLBAR(toolbar), toolbar_find_button, -1);
	gtk_toolbar_insert(GTK_TOOLBAR(toolbar), toolbar_replace_button, -1);

	gtk_toolbar_insert(GTK_TOOLBAR(toolbar), gtk_separator_tool_item_new(), -1);

	gtk_toolbar_insert(GTK_TOOLBAR(toolbar), toolbar_quit_button, -1);

	gtk_tool_item_set_tooltip_text(toolbar_new_button, "New document");
	gtk_tool_item_set_tooltip_text(toolbar_open_button, "Open document");
	gtk_tool_item_set_tooltip_text(toolbar_save_button, "Save document");
	gtk_tool_item_set_tooltip_text(toolbar_save_as_button, "Save document with different name");

	gtk_tool_item_set_tooltip_text(toolbar_undo_button, "Undo changes");
	gtk_tool_item_set_tooltip_text(toolbar_redo_button, "Redo changes");

	gtk_tool_item_set_tooltip_text(toolbar_cut_button, "Cut selected text");
	gtk_tool_item_set_tooltip_text(toolbar_copy_button, "Copy selected text");
	gtk_tool_item_set_tooltip_text(toolbar_paste_button, "Paste content from clipboard");

	gtk_tool_item_set_tooltip_text(toolbar_find_button, "Find text");
	gtk_tool_item_set_tooltip_text(toolbar_replace_button, "Find and replace text");

	gtk_tool_item_set_tooltip_text(toolbar_quit_button, "Quit application");

	g_signal_connect(G_OBJECT(toolbar_quit_button), "clicked", G_CALLBACK(gtk_main_quit), NULL);
	g_signal_connect(G_OBJECT(toolbar_open_button), "clicked", G_CALLBACK(open_file_callback), NULL);

	/* Scrolled Window */
	scrolled_window = gtk_scrolled_window_new(NULL, NULL);
	gtk_scrolled_window_set_shadow_type(GTK_SCROLLED_WINDOW(scrolled_window), GTK_SHADOW_IN);

	gtk_scrolled_window_set_policy(
		GTK_SCROLLED_WINDOW(scrolled_window),
		GTK_POLICY_NEVER,
		GTK_POLICY_ALWAYS
	);

	gtk_box_pack_start(GTK_BOX(client_area), scrolled_window, TRUE, TRUE, 0);

	/* Textview widget */
	text_view = gtk_text_view_new();
	text_buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));
	gtk_container_add(GTK_CONTAINER(scrolled_window), text_view);

	/* Status bar */
	statusbar = gtk_statusbar_new();
	gtk_box_pack_start(GTK_BOX(client_area), statusbar, FALSE, FALSE, 0);

	gtk_widget_show_all(window);
	gtk_main();

	return EXIT_SUCCESS;
}

void about_menu_item_callback(GtkWidget *widget, gpointer data)
{
	fprintf(stderr, "About!\n");
}

void open_file_callback(GtkWidget *widget, gpointer data)
{
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
		char *filename;

		filename = gtk_file_chooser_get_filename (GTK_FILE_CHOOSER (dialog));
		/* open_file (filename); */

		/*
		 * En esta parte es donde se lee el archivo y
		 * se escribe su contenido al widget de TextVie
		 *
		 */

		fprintf(stderr, filename);
		g_free (filename);
	}

	gtk_widget_destroy (dialog);
}
