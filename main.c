/*
/*  Autor              : Alef Sheridan Ariel R. Ch.
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

	GtkWidget *toolbar_handle_box;
	GtkWidget *toolbar;
	GtkToolItem *toolbar_quit_button;

	GtkWidget *scrolled_window;

	GtkWidget *text_view;
	GtkTextBuffer *text_buffer;

	GtkWidget *statusbar;

	gtk_init(&argc, &argv);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), WINDOW_TITLE);
	gtk_window_set_default_size(GTK_WINDOW(window), 640, 480);
	gtk_container_set_border_width(GTK_CONTAINER(window), 5);

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

	g_signal_connect(G_OBJECT(quit_menu_item), "activate", G_CALLBACK(gtk_main_quit), NULL);

	gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), new_menu_item);
	gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), open_menu_item);
	gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), gtk_separator_menu_item_new());
	gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), save_menu_item);
	gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), save_as_menu_item);
	gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), gtk_separator_menu_item_new());
	gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), quit_menu_item);
	
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

	/* Toolbar */
	toolbar_handle_box = gtk_handle_box_new();
	gtk_box_pack_start(GTK_BOX(client_area), toolbar_handle_box, FALSE, FALSE, 0);

	toolbar = gtk_toolbar_new();
	gtk_container_add(GTK_CONTAINER(toolbar_handle_box), toolbar);
	gtk_toolbar_set_style(GTK_TOOLBAR(toolbar), GTK_TOOLBAR_ICONS);
	gtk_container_set_border_width(GTK_CONTAINER(toolbar), 2);

	toolbar_quit_button = gtk_tool_button_new_from_stock(GTK_STOCK_QUIT);
	gtk_toolbar_insert(GTK_TOOLBAR(toolbar), toolbar_quit_button, -1);
	g_signal_connect(
		G_OBJECT(toolbar_quit_button),
		"clicked",
		G_CALLBACK(gtk_main_quit),
		NULL
	);

	/* Scrolled Window */
	scrolled_window = gtk_scrolled_window_new(NULL, NULL);
	gtk_scrolled_window_set_shadow_type(GTK_SCROLLED_WINDOW(scrolled_window), GTK_SHADOW_IN);

	gtk_scrolled_window_set_policy(
		GTK_SCROLLED_WINDOW(scrolled_window),
		GTK_POLICY_NEVER,
		GTK_POLICY_ALWAYS
	);

	gtk_box_pack_start(GTK_BOX(client_area), scrolled_window, TRUE, TRUE, 0);

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
