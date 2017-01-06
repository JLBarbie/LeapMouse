#include <gtk-2.0/gtk/gtk.h>

class systray {
public:
  systray();

  ~systray();

  void tray_icon_on_click(GtkStatusIcon *status_icon, gpointer user_data);

  void tray_icon_on_menu(GtkStatusIcon *status_icon, guint button,
                         guint activate_time, gpointer user_data);

private:
  GtkStatusIcon *systray::create_tray_icon();
};
