#ifndef SYSTRAY_HPP
#define SYSTRAY_HPP

#include <gtk-2.0/gtk/gtk.h>

class Systray {
public:
  Systray(int argc, char **argv);

  ~Systray();

  void tray_icon_on_click(GtkStatusIcon *status_icon, gpointer user_data);

  void tray_icon_on_menu(GtkStatusIcon *status_icon, guint button,
                         guint activate_time, gpointer user_data);

private:
  GtkStatusIcon *create_tray_icon();
};

#endif
