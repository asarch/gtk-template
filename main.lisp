(ql:quickload :cl-cffi-gtk)

(defpackage :aplicacion
  (:use :gtk :gdk :gdk-pixbuf :gobject
	:glib :gio :pango :cairo :common-lisp))

(in-package :aplicacion)

;;(within-main-loop
;;  (let ((builder (make-instance 'gtk-builder)) window)
;;    (gtk-builder-add-from-file builder "agenda.glade")
;;    (setf window (gtk-builder-get-object builder "window"))
;;    (g-signal-connect window "destroy" (lambda (widget) (declare (ignore widget)) (leave-gtk-main)))
;;    (gtk-widget-show-all window)))

(within-main-loop
  (let ((window (make-instance 'gtk-window :title "Agenda" :type :toplevel))
	(box (make-instance 'gtk-box :orientation :vertical))
	(statusbar (make-instance 'gtk-statusbar))
       
	(menu-bar (make-instance 'gtk-menu-bar))
	(file-menu (make-instance 'gtk-menu))
	(file-menu-item (make-instance 'gtk-menu-item))
	(quit-menu-item (make-instance 'gtk-menu-item))
	
	(scrolled-window (make-instance 'gtk-scrolled-window))
	(store (make-instance 'gtk-list-store :column-types '("guint" "gchararray" "gchararray" "gchararray" "gchararray")))
	(tree-view (make-instance 'gtk-tree-view))
       
	(toolbar (make-instance 'gtk-toolbar))
	(quit-tool-button (make-instance 'gtk-tool-button :icon-widget (gtk-image-new-from-icon-name "gtk-quit" :small-toolbar)))
	(add-tool-button (make-instance 'gtk-tool-button :icon-widget (gtk-image-new-from-icon-name "gtk-add" :small-toolbar)))
	(edit-tool-button (make-instance 'gtk-tool-button :icon-widget (gtk-image-new-from-icon-name "gtk-edit" :small-toolbar)))
	(delete-tool-button (make-instance 'gtk-tool-button :icon-widget (gtk-image-new-from-icon-name "gtk-delete" :small-toolbar)))
	(execute-tool-button (make-instance 'gtk-tool-button :icon-widget (gtk-image-new-from-icon-name "gtk-execute" :small-toolbar))))
    
    ;;------------------------------------------------------------------
    ;;  Window
    ;;------------------------------------------------------------------
    (g-signal-connect window "destroy" (lambda (widget) (declare (ignore widget)) (leave-gtk-main)))
    (gtk-container-add window box)
    (gtk-window-set-default-geometry window 1024 748)

    ;;------------------------------------------------------------------
    ;;  Menu bar
    ;;------------------------------------------------------------------
    (gtk-box-pack-start box menu-bar :expand nil)
    (setf (gtk-menu-item-label file-menu-item) "_File")
    (gtk-menu-item-set-use-underline file-menu-item t)
    ;; gtk-menu-add -> gtk-container-add
    (gtk-container-add menu-bar file-menu-item)
    (setf (gtk-menu-item-submenu file-menu-item) file-menu)
    (setf (gtk-menu-item-label quit-menu-item) "_Quit")
    (gtk-menu-item-set-use-underline quit-menu-item t)
    (gtk-container-add file-menu quit-menu-item)
   
    ;;------------------------------------------------------------------
    ;;  Toolbar
    ;;------------------------------------------------------------------
    (gtk-box-pack-start box toolbar :expand nil)
    (gtk-toolbar-insert toolbar quit-tool-button -1)
    (gtk-toolbar-insert toolbar (make-instance 'gtk-separator-tool-item) -1)
    (gtk-toolbar-insert toolbar add-tool-button -1)
    (gtk-toolbar-insert toolbar edit-tool-button -1)
    (gtk-toolbar-insert toolbar delete-tool-button -1)
    (gtk-toolbar-insert toolbar (make-instance 'gtk-separator-tool-item) -1)
    (gtk-toolbar-insert toolbar execute-tool-button -1)
    
    (gtk-tool-item-set-tooltip-text quit-tool-button "Quit Application")
    (gtk-tool-item-set-tooltip-text add-tool-button "Add Entry")
    (gtk-tool-item-set-tooltip-text edit-tool-button "Edit Entry")
    (gtk-tool-item-set-tooltip-text delete-tool-button "Delete Entry")
    (gtk-tool-item-set-tooltip-text execute-tool-button "SQL Query")

    ;;-----------------------------------------------------------------
    ;;  Scrolled window
    ;;-----------------------------------------------------------------
    (gtk-box-pack-start box scrolled-window :expand t :fill t)
    (gtk-scrolled-window-set-policy scrolled-window :always :always)
    (gtk-container-add scrolled-window tree-view)

    ;;-----------------------------------------------------------------
    ;;  Treeview
    ;;-----------------------------------------------------------------
    (setf (gtk-tree-view-model tree-view) store)
    (gtk-tree-view-append-column tree-view (gtk-tree-view-column-new-with-attributes "id" (make-instance 'gtk-cell-renderer-text) "text" 0))
    (gtk-tree-view-append-column tree-view (gtk-tree-view-column-new-with-attributes "Nombre" (make-instance 'gtk-cell-renderer-text) "text" 1))
    (gtk-tree-view-append-column tree-view (gtk-tree-view-column-new-with-attributes "Descripción" (make-instance 'gtk-cell-renderer-text) "text" 2))
    (gtk-tree-view-append-column tree-view (gtk-tree-view-column-new-with-attributes "Fecha" (make-instance 'gtk-cell-renderer-text) "text" 3))
    (gtk-tree-view-append-column tree-view (gtk-tree-view-column-new-with-attributes "Tipo de Nota" (make-instance 'gtk-cell-renderer-text) "text" 4))

    (gtk-tree-view-column-set-resizable (gtk-tree-view-get-column tree-view 0) t)
    (gtk-tree-view-column-set-resizable (gtk-tree-view-get-column tree-view 1) t)
    (gtk-tree-view-column-set-resizable (gtk-tree-view-get-column tree-view 2) t)
    (gtk-tree-view-column-set-resizable (gtk-tree-view-get-column tree-view 3) t)
    (gtk-tree-view-column-set-resizable (gtk-tree-view-get-column tree-view 4) t)
    
    (gtk-tree-view-column-set-sort-column-id (gtk-tree-view-get-column tree-view 0) 0)
    (gtk-tree-view-column-set-sort-column-id (gtk-tree-view-get-column tree-view 1) 1)
    (gtk-tree-view-column-set-sort-column-id (gtk-tree-view-get-column tree-view 2) 2)
    (gtk-tree-view-column-set-sort-column-id (gtk-tree-view-get-column tree-view 3) 3)
    (gtk-tree-view-column-set-sort-column-id (gtk-tree-view-get-column tree-view 4) 4)
    
    ;;------------------------------------------------------------------
    ;;  Statusbar
    ;;------------------------------------------------------------------
    (gtk-box-pack-start box statusbar :expand nil :fill nil)
    (gtk-widget-show-all window)

    ;;-----------------------------------------------------------------
    (gtk-list-store-set store (gtk-list-store-append store) 0 "Common" "Lisp" "simply" "rocks!")))
