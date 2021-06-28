#include <gtk/gtk.h>
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>

 /* Well, by golly, this program uses widgets: */
typedef struct {
	GtkWidget* window;
	GtkWidget* entry1;
	GtkWidget* entry2;
} AppWidgets;
/* Make the copy, cut, paste, delete menu items work */
#if 1
#define UNUSED gpointer _x_ G_GNUC_UNUSED
#define FOCUSED GTK_EDITABLE( \
	(GTK_WIDGET_HAS_FOCUS(app->entry2))?app->entry2:app->entry1)
#undef define
#endif
//main
int main(int argc, char *argv[])
{
    GtkBuilder      *builder; 
    GtkWidget       *window;
  
	AppWidgets* app = g_slice_new(AppWidgets);

    gtk_init(&argc, &argv);

    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "glade/window_main.glade", NULL);
    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));
    gtk_builder_connect_signals(builder, NULL);
    
    
    gtk_widget_show(window);     
    //Get handles to our app widgets.
#define appGET(xx) \
	app->xx=GTK_WIDGET(gtk_builder_get_object(builder,#xx))
	appGET(entry1);
	appGET(entry2);
	appGET(window);
	gtk_builder_connect_signals(builder, app);
	g_object_unref(G_OBJECT(builder));

	gtk_main();
	g_slice_free(AppWidgets, app);           
    //gtk_main();
    //g_object_unref(builder);

    return 0;
}

// called when click on button login
G_MODULE_EXPORT void on_btn_login_clicked(AppWidgets* app)
{
    //printf("ddddd");
	//gchar* hash = make_hash(gtk_entry_get_text(GTK_ENTRY(app->entry1)));
	//gtk_entry_set_text(GTK_ENTRY(app->entry2), hash);
	//g_free(hash);
}

// called when click on login with fingerprint
G_MODULE_EXPORT void on_btn_f_clicked()
{   
    
    //ShellExecute(NULL, "open", "C:\\Users\\MR-INT\\Music\\Documents\\9raya\\prog C\\projet\\fingerprint\\src\\insert_db\\for_testing\\run.bat", NULL, NULL, SW_SHOWNORMAL);
    ShellExecute(NULL, "open", "authenticate.exe", NULL, NULL, SW_SHOWNORMAL);
    //gtk_main_quit();
}
//called when window main is closed
G_MODULE_EXPORT void on_window_main_destroy()
{
    gtk_main_quit();
}

//called when click on help
G_MODULE_EXPORT void on_btn_aboutclicked(int argc, char *argv[])
{   
    GtkBuilder      *builder; 
    GtkWidget       *window;
  

    gtk_init(&argc, &argv);

    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "glade/window_main.glade", NULL);

    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_help"));
    gtk_builder_connect_signals(builder, NULL);
    
    
    gtk_widget_show(window);                
    gtk_main();
    g_object_unref(builder);
    

}
//called when window help is closed
G_MODULE_EXPORT void on_window_help_destroy()
{
    gtk_main_quit();
    
}