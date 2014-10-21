#include "menu.h"

void set_up_menu(GtkWidget *window)
{
	GtkAccelGroup *accel_group;

	/* This should be done in the main function */
	accel_group = gtk_accel_group_new();
	gtk_window_add_accel_group(GTK_WINDOW(window), accel_group);

	menu_bar = gtk_menu_bar_new();

	/* File menu item */
	file_menu_item = gtk_menu_item_new_with_mnemonic("_File");
	gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), file_menu_item);

	file_menu = gtk_menu_new();
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(file_menu_item), file_menu);

	new_menu_item = gtk_image_menu_item_new_with_mnemonic("_New");
	open_menu_item = gtk_image_menu_item_new_with_mnemonic("_Open");
	save_menu_item = gtk_image_menu_item_new_with_mnemonic("_Save");
	save_as_menu_item = gtk_image_menu_item_new_with_mnemonic("Save _as");
	quit_menu_item = gtk_image_menu_item_new_with_mnemonic("_Quit");

	gtk_widget_add_accelerator(
		new_menu_item,
		"activate",
		accel_group,
		GDK_KEY_N,
		GDK_CONTROL_MASK,
		GTK_ACCEL_VISIBLE
	);

	gtk_widget_add_accelerator(
		open_menu_item,
		"activate",
		accel_group,
		GDK_KEY_O,
		GDK_CONTROL_MASK,
		GTK_ACCEL_VISIBLE
	);

	gtk_widget_add_accelerator(
		save_menu_item,
		"activate",
		accel_group,
		GDK_KEY_S,
		GDK_CONTROL_MASK,
		GTK_ACCEL_VISIBLE
	);

	gtk_widget_add_accelerator(
		save_as_menu_item,
		"activate",
		accel_group,
		GDK_KEY_S,
		GDK_SHIFT_MASK | GDK_CONTROL_MASK,
		GTK_ACCEL_VISIBLE
	);

	gtk_widget_add_accelerator(
		quit_menu_item,
		"activate",
		accel_group,
		GDK_KEY_Q,
		GDK_CONTROL_MASK,
		GTK_ACCEL_VISIBLE
	);

	gtk_image_menu_item_set_image(
		GTK_IMAGE_MENU_ITEM(new_menu_item),
		gtk_image_new_from_icon_name("gtk-new", GTK_ICON_SIZE_MENU)
	);

	gtk_image_menu_item_set_image(
		GTK_IMAGE_MENU_ITEM(open_menu_item),
		gtk_image_new_from_icon_name("gtk-open", GTK_ICON_SIZE_MENU)
	);

	gtk_image_menu_item_set_image(
		GTK_IMAGE_MENU_ITEM(save_menu_item),
		gtk_image_new_from_icon_name("gtk-save", GTK_ICON_SIZE_MENU)
	);

	gtk_image_menu_item_set_image(
		GTK_IMAGE_MENU_ITEM(save_as_menu_item),
		gtk_image_new_from_icon_name("gtk-save-as", GTK_ICON_SIZE_MENU)
	);

	gtk_image_menu_item_set_image(
		GTK_IMAGE_MENU_ITEM(quit_menu_item),
		gtk_image_new_from_icon_name("gtk-quit", GTK_ICON_SIZE_MENU)
	);

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

	undo_menu_item = gtk_image_menu_item_new_with_mnemonic("_Undo");
	redo_menu_item = gtk_image_menu_item_new_with_mnemonic("_Redo");
	cut_menu_item = gtk_image_menu_item_new_with_mnemonic("_Cut");
	copy_menu_item = gtk_image_menu_item_new_with_mnemonic("_Copy");
	paste_menu_item = gtk_image_menu_item_new_with_mnemonic("_Paste");
	clear_menu_item = gtk_image_menu_item_new_with_mnemonic("_Delete");
	select_all_menu_item = gtk_image_menu_item_new_with_mnemonic("_Select All");

	gtk_widget_add_accelerator(
		undo_menu_item,
		"activate",
		accel_group,
		GDK_KEY_Z,
		GDK_CONTROL_MASK,
		GTK_ACCEL_VISIBLE
	);

	gtk_widget_add_accelerator(
		redo_menu_item,
		"activate",
		accel_group,
		GDK_KEY_Z,
		GDK_SHIFT_MASK | GDK_CONTROL_MASK,
		GTK_ACCEL_VISIBLE
	);

	gtk_widget_add_accelerator(
		cut_menu_item,
		"activate",
		accel_group,
		GDK_KEY_X,
		GDK_CONTROL_MASK,
		GTK_ACCEL_VISIBLE
	);

	gtk_widget_add_accelerator(
		copy_menu_item,
		"activate",
		accel_group,
		GDK_KEY_C,
		GDK_CONTROL_MASK,
		GTK_ACCEL_VISIBLE
	);

	gtk_widget_add_accelerator(
		paste_menu_item,
		"activate",
		accel_group,
		GDK_KEY_V,
		GDK_CONTROL_MASK,
		GTK_ACCEL_VISIBLE
	);

	gtk_widget_add_accelerator(
		select_all_menu_item,
		"activate",
		accel_group,
		GDK_KEY_A,
		GDK_CONTROL_MASK,
		GTK_ACCEL_VISIBLE
	);

	gtk_image_menu_item_set_image(
		GTK_IMAGE_MENU_ITEM(undo_menu_item),
		gtk_image_new_from_icon_name("edit-undo", GTK_ICON_SIZE_MENU)
	);

	gtk_image_menu_item_set_image(
		GTK_IMAGE_MENU_ITEM(redo_menu_item),
		gtk_image_new_from_icon_name("edit-redo", GTK_ICON_SIZE_MENU)
	);

	gtk_image_menu_item_set_image(
		GTK_IMAGE_MENU_ITEM(cut_menu_item),
		gtk_image_new_from_icon_name("gtk-cut", GTK_ICON_SIZE_MENU)
	);

	gtk_image_menu_item_set_image(
		GTK_IMAGE_MENU_ITEM(copy_menu_item),
		gtk_image_new_from_icon_name("gtk-copy", GTK_ICON_SIZE_MENU)
	);

	gtk_image_menu_item_set_image(
		GTK_IMAGE_MENU_ITEM(paste_menu_item),
		gtk_image_new_from_icon_name("gtk-paste", GTK_ICON_SIZE_MENU)
	);

	gtk_image_menu_item_set_image(
		GTK_IMAGE_MENU_ITEM(clear_menu_item),
		gtk_image_new_from_icon_name("gtk-delete", GTK_ICON_SIZE_MENU)
	);

	gtk_image_menu_item_set_image(
		GTK_IMAGE_MENU_ITEM(select_all_menu_item),
		gtk_image_new_from_icon_name("edit-select-all", GTK_ICON_SIZE_MENU)
	);

	gtk_menu_shell_append(GTK_MENU_SHELL(edit_menu), undo_menu_item);
	gtk_menu_shell_append(GTK_MENU_SHELL(edit_menu), redo_menu_item);
	gtk_menu_shell_append(GTK_MENU_SHELL(edit_menu), gtk_separator_menu_item_new());
	gtk_menu_shell_append(GTK_MENU_SHELL(edit_menu), cut_menu_item);
	gtk_menu_shell_append(GTK_MENU_SHELL(edit_menu), copy_menu_item);
	gtk_menu_shell_append(GTK_MENU_SHELL(edit_menu), paste_menu_item);
	gtk_menu_shell_append(GTK_MENU_SHELL(edit_menu), clear_menu_item);
	gtk_menu_shell_append(GTK_MENU_SHELL(edit_menu), gtk_separator_menu_item_new());
	gtk_menu_shell_append(GTK_MENU_SHELL(edit_menu), select_all_menu_item);

	/* Search menu item */
	search_menu_item = gtk_menu_item_new_with_mnemonic("_Search");
	gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), search_menu_item);

	search_menu = gtk_menu_new();
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(search_menu_item), search_menu);

	find_menu_item = gtk_image_menu_item_new_with_mnemonic("_Find");
	find_next_menu_item = gtk_image_menu_item_new_with_mnemonic("Find Ne_xt");
	find_previous_menu_item = gtk_image_menu_item_new_with_mnemonic("Find Pre_vious");
	replace_menu_item = gtk_image_menu_item_new_with_mnemonic("_Replace");
	clear_highlight_menu_item = gtk_image_menu_item_new_with_mnemonic("Clear Hightlight");
	goto_line_menu_item = gtk_image_menu_item_new_with_mnemonic("Goto Line");

	gtk_widget_add_accelerator(
		find_next_menu_item,
		"activate",
		accel_group,
		GDK_KEY_G,
		GDK_CONTROL_MASK,
		GTK_ACCEL_VISIBLE
	);

	gtk_widget_add_accelerator(
		find_previous_menu_item,
		"activate",
		accel_group,
		GDK_KEY_G,
		GDK_SHIFT_MASK | GDK_CONTROL_MASK,
		GTK_ACCEL_VISIBLE
	);

	gtk_widget_add_accelerator(
		clear_highlight_menu_item,
		"activate",
		accel_group,
		GDK_KEY_K,
		GDK_SHIFT_MASK | GDK_CONTROL_MASK,
		GTK_ACCEL_VISIBLE
	);

	gtk_widget_add_accelerator(
		goto_line_menu_item,
		"activate",
		accel_group,
		GDK_KEY_I,
		GDK_CONTROL_MASK,
		GTK_ACCEL_VISIBLE
	);

	gtk_image_menu_item_set_image(
		GTK_IMAGE_MENU_ITEM(find_menu_item),
		gtk_image_new_from_icon_name("gtk-find", GTK_ICON_SIZE_MENU)
	);

	/*
	gtk_image_menu_item_set_image(
		GTK_IMAGE_MENU_ITEM(find_next_menu_item),
		gtk_image_new_from_icon_name("", GTK_ICON_SIZE_MENU)
	);

	gtk_image_menu_item_set_image(
		GTK_IMAGE_MENU_ITEM(select_all_menu_item),
		gtk_image_new_from_icon_name("edit-select-all", GTK_ICON_SIZE_MENU)
	);
	*/

	gtk_image_menu_item_set_image(
		GTK_IMAGE_MENU_ITEM(replace_menu_item),
		gtk_image_new_from_icon_name("edit-find-replace", GTK_ICON_SIZE_MENU)
	);

	gtk_image_menu_item_set_image(
		GTK_IMAGE_MENU_ITEM(clear_highlight_menu_item),
		gtk_image_new_from_icon_name("edit-clear", GTK_ICON_SIZE_MENU)
	);

	gtk_image_menu_item_set_image(
		GTK_IMAGE_MENU_ITEM(goto_line_menu_item),
		gtk_image_new_from_icon_name("edit-goto-jump", GTK_ICON_SIZE_MENU)
	);

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

	about_menu_item = gtk_image_menu_item_new_with_mnemonic("_About");

	gtk_image_menu_item_set_image(
		GTK_IMAGE_MENU_ITEM(about_menu_item),
		gtk_image_new_from_icon_name("gtk-about", GTK_ICON_SIZE_MENU)
	);

	gtk_menu_shell_append(GTK_MENU_SHELL(help_menu), about_menu_item);
}
