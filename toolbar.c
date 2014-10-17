#include "toolbar.h"

void init_toolbar()
{
	toolbar = gtk_toolbar_new();
	gtk_toolbar_set_style(GTK_TOOLBAR(toolbar), GTK_TOOLBAR_ICONS);
	gtk_container_set_border_width(GTK_CONTAINER(toolbar), 2);

	/* Initializing tool items */
	new_tool_item = gtk_tool_button_new(
		gtk_image_new_from_icon_name(
			"gtk-new",
			GTK_ICON_SIZE_SMALL_TOOLBAR
		),
		"New File"
	);

	open_tool_item = gtk_tool_button_new(
		gtk_image_new_from_icon_name(
			"gtk-open",
			GTK_ICON_SIZE_SMALL_TOOLBAR
		),
		"Open File"
	);

	save_tool_item = gtk_tool_button_new(
		gtk_image_new_from_icon_name(
			"gtk-save",
			GTK_ICON_SIZE_SMALL_TOOLBAR
		),
		"Save File"
	);

	save_as_tool_item = gtk_tool_button_new(
		gtk_image_new_from_icon_name(
			"gtk-save-as",
			GTK_ICON_SIZE_SMALL_TOOLBAR
		),
		"Save As New File"
	);

	quit_tool_item = gtk_tool_button_new(
		gtk_image_new_from_icon_name(
			"gtk-quit",
			GTK_ICON_SIZE_SMALL_TOOLBAR
		),
		"Quit Application"
	);

	undo_tool_item = gtk_tool_button_new(
		gtk_image_new_from_icon_name(
			"edit-undo",
			GTK_ICON_SIZE_SMALL_TOOLBAR
		),
		"Undo Operation"
	);

	redo_tool_item = gtk_tool_button_new(
		gtk_image_new_from_icon_name(
			"edit-redo",
			GTK_ICON_SIZE_SMALL_TOOLBAR
		),
		"Redo Operation"
	);

	cut_tool_item = gtk_tool_button_new(
		gtk_image_new_from_icon_name(
			"gtk-cut",
			GTK_ICON_SIZE_SMALL_TOOLBAR
		),
		"Cut"
	);

	copy_tool_item = gtk_tool_button_new(
		gtk_image_new_from_icon_name(
			"gtk-copy",
			GTK_ICON_SIZE_SMALL_TOOLBAR
		),
		"Copy"
	);

	paste_tool_item = gtk_tool_button_new(
		gtk_image_new_from_icon_name(
			"gtk-paste",
			GTK_ICON_SIZE_SMALL_TOOLBAR
		),
		"Paste"
	);

	find_tool_item = gtk_tool_button_new(
		gtk_image_new_from_icon_name(
			"gtk-find",
			GTK_ICON_SIZE_SMALL_TOOLBAR
		),
		"Find"
	);

	replace_tool_item = gtk_tool_button_new(
		gtk_image_new_from_icon_name(
			"edit-find-replace",
			GTK_ICON_SIZE_SMALL_TOOLBAR
		),
		"Replace"
	);

	/* Inserting items */
	gtk_toolbar_insert(GTK_TOOLBAR(toolbar), new_tool_item, -1);
	gtk_toolbar_insert(GTK_TOOLBAR(toolbar), open_tool_item, -1);
	gtk_toolbar_insert(GTK_TOOLBAR(toolbar), save_tool_item, -1);
	gtk_toolbar_insert(GTK_TOOLBAR(toolbar), save_as_tool_item, -1);

	gtk_toolbar_insert(GTK_TOOLBAR(toolbar), gtk_separator_tool_item_new(), -1);

	gtk_toolbar_insert(GTK_TOOLBAR(toolbar), undo_tool_item, -1);
	gtk_toolbar_insert(GTK_TOOLBAR(toolbar), redo_tool_item, -1);

	gtk_toolbar_insert(GTK_TOOLBAR(toolbar), gtk_separator_tool_item_new(), -1);

	gtk_toolbar_insert(GTK_TOOLBAR(toolbar), cut_tool_item, -1);
	gtk_toolbar_insert(GTK_TOOLBAR(toolbar), copy_tool_item, -1);
	gtk_toolbar_insert(GTK_TOOLBAR(toolbar), paste_tool_item, -1);

	gtk_toolbar_insert(GTK_TOOLBAR(toolbar), gtk_separator_tool_item_new(), -1);

	gtk_toolbar_insert(GTK_TOOLBAR(toolbar), find_tool_item, -1);
	gtk_toolbar_insert(GTK_TOOLBAR(toolbar), replace_tool_item, -1);

	gtk_toolbar_insert(GTK_TOOLBAR(toolbar), gtk_separator_tool_item_new(), -1);

	gtk_toolbar_insert(GTK_TOOLBAR(toolbar), quit_tool_item, -1);

	/* Setting tool tips */
	gtk_tool_item_set_tooltip_text(new_tool_item, "New document");
	gtk_tool_item_set_tooltip_text(open_tool_item, "Open document");
	gtk_tool_item_set_tooltip_text(save_tool_item, "Save document");
	gtk_tool_item_set_tooltip_text(save_as_tool_item, "Save document with different name");

	gtk_tool_item_set_tooltip_text(undo_tool_item, "Undo changes");
	gtk_tool_item_set_tooltip_text(redo_tool_item, "Redo changes");

	gtk_tool_item_set_tooltip_text(cut_tool_item, "Cut selected text");
	gtk_tool_item_set_tooltip_text(copy_tool_item, "Copy selected text");
	gtk_tool_item_set_tooltip_text(paste_tool_item, "Paste content from clipboard");

	gtk_tool_item_set_tooltip_text(find_tool_item, "Find text");
	gtk_tool_item_set_tooltip_text(replace_tool_item, "Find and replace text");

	gtk_tool_item_set_tooltip_text(quit_tool_item, "Quit application");
}
