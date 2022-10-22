#include <stdio.h>
#include <gtk/gtk.h>
#include <stddef.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <glib.h>
//Make items global
GtkWidget* window;
GtkWidget* fixed1;
GtkWidget* button1;
GtkWidget* lbl1;
GtkWidget* txt1;
GtkWidget* txt2;
GtkWidget* button2;
GtkBuilder* builder;//pointer to load the xml file

void on_button1_clicked (GtkButton* pBtn);

void square (const int x, int* value);
void copy_text (GtkWidget *wid, gpointer ptr);
void endProgram (GtkWidget *wid, gpointer ptr);

int main (int argc, char * argv[])
{
    gtk_init (&argc, &argv);
    //establish contact with xml code from glade
    builder = gtk_builder_new_from_file ("myglade.glade");
    window = GTK_WIDGET (gtk_builder_get_object (builder, "window"));
    gtk_window_set_resizable (GTK_WINDOW (window), FALSE);
    g_signal_connect (window, "destroy", G_CALLBACK (endProgram), NULL);
    g_signal_connect (button2, "clicked", G_CALLBACK(endProgram), NULL);
    gtk_builder_connect_signals (builder, NULL);
    fixed1 = GTK_WIDGET (gtk_builder_get_object (builder, "fixed1"));
    button1 = GTK_WIDGET (gtk_builder_get_object (builder, "button1"));
    lbl1 = GTK_WIDGET (gtk_builder_get_object (builder, "lbl1"));
    txt1 = GTK_WIDGET (gtk_builder_get_object (builder, "txt1"));
    txt2 = GTK_WIDGET (gtk_builder_get_object (builder, "txt2"));
    g_signal_connect(button1, "clicked", G_CALLBACK (copy_text), lbl1);
    gtk_widget_show (window);
    gtk_main();//watches for events and signals.
    return EXIT_SUCCESS;
}

void on_button1_clicked (GtkButton* pBtn)
{
    int value = 0;
    square(50, &value);
    char data[10];
    sprintf(data, "%d", value);
    printf("%d", value);
    gtk_label_set_label (GTK_LABEL (lbl1), (const gchar*) data);
}

void square (const int x, int* value)
{
    *value = pow(x, 2);
}

void copy_text (GtkWidget *wid, gpointer ptr){
    const char* input = gtk_entry_get_text (GTK_ENTRY (txt1));
    gtk_label_set_text (GTK_LABEL (ptr), input);
}

void endProgram (GtkWidget *wid, gpointer ptr)
{
    gtk_main_quit ();
}
