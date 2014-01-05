/**
 * button.c
 * show how to draw button on window.
 */
#include <gtk/gtk.h>

static void destroy( GtkWidget *widget, gpointer pointer );

int main( int argc, char *argv[] ) {
  gtk_init( &argc, &argv );

  GtkWidget *window = gtk_window_new( GTK_WINDOW_TOPLEVEL );
  gtk_window_set_title( GTK_WINDOW( window ), "Button" );
  gtk_widget_set_size_request( window, 320, 240 );
  gtk_container_set_border_width( GTK_CONTAINER( window ), 20 );
  GtkWidget *button = gtk_button_new_with_mnemonic( "_Click" );
  gtk_button_set_relief( GTK_BUTTON( button ), GTK_RELIEF_NORMAL );
  g_signal_connect( G_OBJECT( window ), "destroy",
		    G_CALLBACK( destroy ), NULL );
  g_signal_connect_swapped( G_OBJECT( button ), "clicked",
		    G_CALLBACK( gtk_widget_destroy ), (gpointer) window );
  gtk_container_add( GTK_CONTAINER( window ), button );

  gtk_widget_show_all( window );

  gtk_main();
  return 0;
}

static void destroy( GtkWidget *widget, gpointer pointer ) {
  gtk_main_quit();
}