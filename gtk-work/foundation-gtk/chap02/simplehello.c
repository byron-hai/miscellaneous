/**
 * simplehello.c
 * first example of GTK developing.
 */
#include <gtk/gtk.h>

int main( int argc, char **argv ) {
  gtk_init( &argc, &argv );

  GtkWidget *window = gtk_window_new( GTK_WINDOW_TOPLEVEL );
  gtk_window_set_title( GTK_WINDOW(window), "Simple Hello" );
  gtk_widget_show( window );
  gtk_main();

  return 0;
}
