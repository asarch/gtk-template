#include "toolbar.h"

void init_toolbar()
{
	toolbar = gtk_toolbar_new();
	gtk_toolbar_set_style(GTK_TOOLBAR(toolbar), GTK_TOOLBAR_ICONS);
	gtk_container_set_border_width(GTK_CONTAINER(toolbar), 2);

	/*
	toolbar_new_button = gtk_tool_button_new_from_stock("text-x-generic",
	toolbar_open_button = gtk_tool_button_new_from_stock("text-x-generic",
	toolbar_save_button = gtk_tool_button_new_from_stock("text-x-generic",
	toolbar_save_as_button = gtk_tool_button_new_from_stock("text-x-generic",
	toolbar_quit_button = gtk_tool_button_new_from_stock("text-x-generic",

	toolbar_undo_button = gtk_tool_button_new_from_stock("text-x-generic",
	toolbar_redo_button = gtk_tool_button_new_from_stock("text-x-generic",

	toolbar_cut_button = gtk_tool_button_new_from_stock("text-x-generic",
	toolbar_copy_button = gtk_tool_button_new_from_stock("text-x-generic",
	toolbar_paste_button = gtk_tool_button_new_from_stock("text-x-generic",

	toolbar_find_button = gtk_tool_button_new_from_stock("text-x-generic",
	toolbar_replace_button = gtk_tool_button_new_from_stock("text-x-generic",
	*/

	toolbar_new_button = gtk_tool_button_new(
		gtk_image_new_from_icon_name(
			"gtk-new",
			GTK_ICON_SIZE_SMALL_TOOLBAR
		),
		"New File"
	);

	toolbar_open_button = gtk_tool_button_new(
		gtk_image_new_from_icon_name(
			"gtk-open",
			GTK_ICON_SIZE_SMALL_TOOLBAR
		),
		"Open File"
	);

	toolbar_save_button = gtk_tool_button_new(
		gtk_image_new_from_icon_name(
			"gtk-save",
			GTK_ICON_SIZE_SMALL_TOOLBAR
		),
		"Save File"
	);

	toolbar_save_as_button = gtk_tool_button_new(
		gtk_image_new_from_icon_name(
			"gtk-save-as",
			GTK_ICON_SIZE_SMALL_TOOLBAR
		),
		"Save As New File"
	);

	toolbar_quit_button = gtk_tool_button_new(
		gtk_image_new_from_icon_name(
			"gtk-quit",
			GTK_ICON_SIZE_SMALL_TOOLBAR
		),
		"Quit Application"
	);

	toolbar_undo_button = gtk_tool_button_new(
		gtk_image_new_from_icon_name(
			"gtk-undo",
			GTK_ICON_SIZE_SMALL_TOOLBAR
		),
		"Undo Operation"
	);

	toolbar_redo_button = gtk_tool_button_new(
		gtk_image_new_from_icon_name(
			"gtk-redo",
			GTK_ICON_SIZE_SMALL_TOOLBAR
		),
		"Redo Operation"
	);

	toolbar_cut_button = gtk_tool_button_new(
		gtk_image_new_from_icon_name(
			"gtk-cut",
			GTK_ICON_SIZE_SMALL_TOOLBAR
		),
		"Cut"
	);

	toolbar_copy_button = gtk_tool_button_new(
		gtk_image_new_from_icon_name(
			"gtk-copy",
			GTK_ICON_SIZE_SMALL_TOOLBAR
		),
		"Copy"
	);

	toolbar_paste_button = gtk_tool_button_new(
		gtk_image_new_from_icon_name(
			"paste",
			GTK_ICON_SIZE_SMALL_TOOLBAR
		),
		"Paste"
	);

	toolbar_find_button = gtk_tool_button_new(
		gtk_image_new_from_icon_name(
			"gtk-find",
			GTK_ICON_SIZE_SMALL_TOOLBAR
		),
		"Find"
	);

	toolbar_replace_button = gtk_tool_button_new(
		gtk_image_new_from_icon_name(
			"gtk-find-replace",
			GTK_ICON_SIZE_SMALL_TOOLBAR
		),
		"Replace"
	);

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
}
