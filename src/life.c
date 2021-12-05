#include "../inc/draw_call.h"

gchar buf[256];

gboolean on_expose_event(GtkWidget *widget,
    GdkEventExpose *event,
    gpointer data) {

    // draw_callback(widget, );

  return FALSE;
}

gboolean time_handler(GtkWidget *widget) {
    
//   if (widget->window == NULL) return FALSE;

  GDateTime *now = g_date_time_new_now_local(); 
  gchar *my_time = g_date_time_format(now, "%H:%M:%S");
  
//   g_sprintf(buf, "%s", my_time);
  
  g_free(my_time);
  g_date_time_unref(now);

  gtk_widget_queue_draw(widget);
  
  return TRUE;
}


gint main(int argc,char *argv[])
{
    int** mat = init_matrix(MATRIX_HEIGHT, MATRIX_LENGTH);

    GtkWidget *window, *drawing_area;
    
    gtk_init (&argc, &argv);
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL); // exit function
    
    drawing_area = gtk_drawing_area_new();
    gtk_container_add (GTK_CONTAINER (window), drawing_area);
    gtk_widget_set_size_request (drawing_area, 1700, 1000);
    g_signal_connect (G_OBJECT (drawing_area), "draw", G_CALLBACK (draw_callback), mat); // draw call, spring board for all logic
    gtk_widget_show_all (window);
    // g_timeout_add(1000, (GSourceFunc) draw_callback, (gpointer) window);
    gtk_main ();
    return 0;
}
