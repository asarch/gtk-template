#include "menu.h"

GtkWidget* get_menu(GtkWidget *window)
{
	GtkWidget *menu_bar;
	GtkAccelGroup *accel_group;

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

	accel_group = gtk_accel_group_new();
	gtk_window_add_accel_group(GTK_WINDOW(window), accel_group);

	menu_bar = gtk_menu_bar_new();

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

	gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), new_menu_item);
	gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), open_menu_item);
	gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), gtk_separator_menu_item_new());
	gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), save_menu_item);
	gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), save_as_menu_item);
	gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), gtk_separator_menu_item_new());
	gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), quit_menu_item);
	
	g_signal_connect(G_OBJECT(open_menu_item), "activate", G_CALLBACK(open_file_callback1), NULL);
	g_signal_connect(G_OBJECT(quit_menu_item), "activate", G_CALLBACK(gtk_main_quit), NULL);

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
	g_signal_connect(G_OBJECT(about_menu_item), "activate", G_CALLBACK(about_menu_item_callback1), NULL);

	return menu_bar;
}

