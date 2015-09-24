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
$quit_tool_button->signal_connect(clicked => sub {Gtk3->main_quit});
$quit_tool_button->set_tooltip_text("Quit Application");

#---------------------------------------------------------------------
#  Status Bar
#---------------------------------------------------------------------
my $statusbar = Gtk3::Statusbar->new;
$content->pack_start($statusbar, FALSE, FALSE, 0);

$window->show_all;
Gtk3->main;
