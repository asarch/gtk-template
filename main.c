/*
 *  Autor              : Alef Sheridan Ariel R. Ch.
 *  Fecha              : Julio del 2014
 *  Version            : 1.0
 *  Nombre del programa: GTK+ Template
 *  Descipcion         : Programa en C con lo minimo para crear
 *                       una aplicacion basada en GTK+ 3.x
 *  Nombre de los iconos:
 *
 *  - Icon Naming Specification
 *    http://standards.freedesktop.org/icon-naming-spec/icon-naming-spec-latest.html
 *
 *  - Icon Naming Specification (GNOME Site)
 *    https://developer.gnome.org/icon-naming-spec/
 */
#include <gtk/gtk.h>

int main(int argc, char *argv[])
{
	/* Main window */
	GtkWidget *window;
	GtkWidget *content;

	GtkWidget *menu_bar;

	GtkWidget *file_menu_item;
	GtkWidget *file_menu;
	GtkWidget *quit_menu_item;

	GtkWidget *help_menu_item;
	GtkWidget *help_menu;
	GtkWidget *about_menu_item;

	/* Toolbar */
	GtkWidget *toolbar;
	GtkToolItem *quit_tool_item;
	GtkToolItem *about_tool_item;

	/* Tree View */
	GtkWidget *scrolled;

	GtkListStore *model;
	GtkWidget *tree_view;
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;

	/* Statusbar */
	GtkWidget *statusbar;

	gtk_init(&argc, &argv);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "GTK+ Template Application");
	gtk_window_set_default_size(GTK_WINDOW(window), 640, 480);
	g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

	content = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	gtk_container_add(GTK_CONTAINER(window), content);

	/* Menu bar */
	menu_bar = gtk_menu_bar_new();
	gtk_box_pack_start(GTK_BOX(content), menu_bar, FALSE, FALSE, 0);

	file_menu_item = gtk_menu_item_new_with_mnemonic("_File");
	gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), file_menu_item);

	file_menu = gtk_menu_new();
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(file_menu_item), file_menu);

	quit_menu_item = gtk_menu_item_new_with_mnemonic("_Quit");
	gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), quit_menu_item);
	g_signal_connect(G_OBJECT(quit_menu_item), "activate", G_CALLBACK(gtk_main_quit), NULL);

	help_menu_item = gtk_menu_item_new_with_mnemonic("_Help");
	gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), help_menu_item);

	help_menu = gtk_menu_new();
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(help_menu_item), help_menu);

	about_menu_item = gtk_menu_item_new_with_mnemonic("_About");
	gtk_menu_shell_append(GTK_MENU_SHELL(help_menu), about_menu_item);

	/* Toolbar */
	toolbar = gtk_toolbar_new();
	gtk_toolbar_set_style(GTK_TOOLBAR(toolbar), GTK_TOOLBAR_ICONS);
	gtk_box_pack_start(GTK_BOX(content), toolbar, FALSE, FALSE, 0);

	quit_tool_item = gtk_tool_button_new(gtk_image_new_from_icon_name("application-exit", GTK_ICON_SIZE_SMALL_TOOLBAR), "Quit");
	g_signal_connect(G_OBJECT(quit_tool_item), "clicked", G_CALLBACK(gtk_main_quit), NULL);
	gtk_tool_item_set_tooltip_text(GTK_TOOL_ITEM(quit_tool_item), "Quit application");
	gtk_toolbar_insert(GTK_TOOLBAR(toolbar), quit_tool_item, -1);

	gtk_toolbar_insert(GTK_TOOLBAR(toolbar), gtk_separator_tool_item_new(), -1);

	about_tool_item = gtk_tool_button_new(gtk_image_new_from_icon_name("help-about", GTK_ICON_SIZE_SMALL_TOOLBAR), "About");
	gtk_toolbar_insert(GTK_TOOLBAR(toolbar), about_tool_item, -1);
	gtk_tool_item_set_tooltip_text(GTK_TOOL_ITEM(about_tool_item), "About");

	/* Statusbar */
	statusbar = gtk_statusbar_new();
	gtk_box_pack_start(GTK_BOX(content), statusbar, FALSE, FALSE, 0);

	gtk_widget_show_all(window);
	gtk_main();
	
	return 0;
}
