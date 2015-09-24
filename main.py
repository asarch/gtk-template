#!/usr/bin/env python

from gi.repository import Gtk

#---------------------------------------------------------------------
#  Main window
#---------------------------------------------------------------------
window = Gtk.Window(Gtk.WindowType.TOPLEVEL)
window.set_title("GTK+ Python Template Script");
window.set_default_size(640, 480)
window.connect('destroy', Gtk.main_quit)

#---------------------------------------------------------------------
#  Window content
#---------------------------------------------------------------------
content = Gtk.Box(orientation=Gtk.Orientation.VERTICAL, spacing=0)
window.add(content)

#---------------------------------------------------------------------
#  Main menu
#---------------------------------------------------------------------
menu_bar = Gtk.MenuBar()
content.pack_start(menu_bar, False, False, 0)

file_menu_item = Gtk.MenuItem.new_with_mnemonic(label="_File")
menu_bar.insert(file_menu_item, -1)

file_menu = Gtk.Menu()
file_menu_item.set_submenu(file_menu);

quit_menu_item = Gtk.MenuItem.new_with_mnemonic("_Quit")
file_menu.insert(quit_menu_item, -1)
quit_menu_item.connect('activate', Gtk.main_quit)

#---------------------------------------------------------------------
#  Toolbar
#---------------------------------------------------------------------
toolbar = Gtk.Toolbar()
content.pack_start(toolbar, False, False, 0)

quit_tool_button = Gtk.ToolButton(Gtk.STOCK_QUIT)
toolbar.insert(quit_tool_button, -1)
quit_tool_button.connect("clicked", Gtk.main_quit)
quit_tool_button.set_tooltip_text("Quit application")

#---------------------------------------------------------------------
#  Status bar
#---------------------------------------------------------------------
statusbar = Gtk.Statusbar()
content.pack_start(statusbar, False, False, 0)

window.show_all()
Gtk.main()
