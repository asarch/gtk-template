#!/usr/bin/perl

use strict;
use warnings;

use Glib qw/FALSE TRUE/;
use Gtk3 '-init';

#---------------------------------------------------------------------
#  Window
#---------------------------------------------------------------------
my $window = Gtk3::Window->new('toplevel');
$window->signal_connect(destroy => sub {Gtk3->main_quit});
$window->set_title('GTK+ Perl Template Script');
$window->set_default_size(640, 480);

#---------------------------------------------------------------------
#  Window Content
#---------------------------------------------------------------------
my $content = Gtk3::Box->new('vertical', 0);
$window->add($content);

#---------------------------------------------------------------------
#  Menu Bar
#---------------------------------------------------------------------
my $menu_bar = Gtk3::MenuBar->new;
$content->pack_start($menu_bar, FALSE, FALSE, 0);

my $file_menu_item = Gtk3::MenuItem->new_with_mnemonic("_File");
$menu_bar->add($file_menu_item);

my $file_menu = Gtk3::Menu->new;
$file_menu_item->set_submenu($file_menu);

my $quit_menu_item = Gtk3::MenuItem->new_with_mnemonic("_Quit");
$file_menu->add($quit_menu_item);
$quit_menu_item->signal_connect(activate => sub {Gtk3->main_quit});

#---------------------------------------------------------------------
#  Tool Bar
#---------------------------------------------------------------------
my $toolbar = Gtk3::Toolbar->new;
$content->pack_start($toolbar, FALSE, FALSE, 0);

my $quit_tool_button = Gtk3::ToolButton->new_from_stock('gtk-quit');
$toolbar->insert($quit_tool_button, -1);
$quit_tool_button->set_tooltip_text("Quit Application");
$quit_tool_button->signal_connect(clicked => sub {Gtk3->main_quit});

$toolbar->insert(Gtk3::SeparatorToolItem->new, -1);

my $add_tool_button = Gtk3::ToolButton->new_from_stock('gtk-add');
$add_tool_button->set_tooltip_text("Agregar elemento");
$toolbar->insert($add_tool_button, -1);

my $edit_tool_button = Gtk3::ToolButton->new_from_stock('gtk-edit');
$edit_tool_button->set_tooltip_text("Editar elemento");
$toolbar->insert($edit_tool_button, -1);

my $delete_tool_button = Gtk3::ToolButton->new_from_stock('gtk-delete');
$delete_tool_button->set_tooltip_text("Eliminar elemento");
$toolbar->insert($delete_tool_button, -1);

$toolbar->insert(Gtk3::SeparatorToolItem->new, -1);

my $execute_tool_button = Gtk3::ToolButton->new_from_stock('gtk-execute');
$execute_tool_button->set_tooltip_text("Ejecutar");
$toolbar->insert($execute_tool_button, -1);

#---------------------------------------------------------------------
#  Scrolled Window
#---------------------------------------------------------------------
my $scrolled_window = Gtk3::ScrolledWindow->new;
$scrolled_window->set_policy('always', 'always');
$content->pack_start($scrolled_window, TRUE, TRUE, 0);

#---------------------------------------------------------------------
#  Treeview
#---------------------------------------------------------------------
my $store = Gtk3::ListStore->new('Glib::String', 'Glib::String');
my $treeview = Gtk3::TreeView->new_with_model($store);
$scrolled_window->add($treeview);

$treeview->append_column(Gtk3::TreeViewColumn->new_with_attributes("id", Gtk3::CellRendererText->new, text => 0));
$treeview->append_column(Gtk3::TreeViewColumn->new_with_attributes("url", Gtk3::CellRendererText->new, text => 1));

$treeview->get_column(0)->set_resizable(TRUE);
$treeview->get_column(1)->set_resizable(TRUE);

$treeview->get_column(0)->set_sort_column_id(0);
$treeview->get_column(1)->set_sort_column_id(1);

#---------------------------------------------------------------------
#  Status Bar
#---------------------------------------------------------------------
my $statusbar = Gtk3::Statusbar->new;
$content->pack_start($statusbar, FALSE, FALSE, 0);

$window->show_all;
Gtk3->main;
