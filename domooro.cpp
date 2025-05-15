#include <gtk/gtk.h>
#include <string>
#include <cstdlib>
#include <windows.h>

static void on_sign_in_with_google_clicked(GtkWidget *widget, gpointer data) {
    const char *supabaseUrl = "https://ibavqwvkyqblsqcrayud.supabase.co/auth/v1/authorize?provider=google&redirect_to=https://Bemba1.github.io/domooro/domooro/";
    std::string command = "cmd.exe /c start \"\" \"" + std::string(supabaseUrl) + "\"";
    system(command.c_str());
}

static void on_sign_in_with_apple_clicked(GtkWidget *widget, gpointer data) {
    g_print("Inscription avec Apple non implémentée\n");
}

static void on_create_account_clicked(GtkWidget *widget, gpointer data) {
    g_print("Créer un compte cliqué\n");
}

static void apply_css(GtkWidget *widget, gpointer data) {
    GtkCssProvider *provider = gtk_css_provider_new();
    gtk_css_provider_load_from_data(provider,
        "window { background-color: #ffffff; }"
        "button { border-radius: 5px; padding: 10px; margin: 5px; }"
        ".google-button { background-color: #ffffff; border: 1px solid #ccc; }"
        ".google-button:hover { background-color: #f0f0f0; }"
        ".apple-button { background-color: #ffffff; border: 1px solid #ccc; }"
        ".apple-button:hover { background-color: #f0f0f0; }"
        ".create-account { background-color: #1da1f2; color: #ffffff; }"
        ".create-account:hover { background-color: #1a91da; }"
        ".terms { font-size: 12px; color: #666; margin-top: 20px; }",
        -1,
        NULL);
    gtk_style_context_add_provider(gtk_widget_get_style_context(widget),
                                  GTK_STYLE_PROVIDER(provider),
                                  GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
    g_object_unref(provider);
}

static void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window;
    GtkWidget *box;
    GtkWidget *logo;
    GtkWidget *slogan_label;
    GtkWidget *signup_label;
    GtkWidget *google_button;
    GtkWidget *apple_button;
    GtkWidget *or_label;
    GtkWidget *create_account_button;
    GtkWidget *terms_label;

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Connexion");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 600);
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);

    apply_css(window, NULL);

    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_container_add(GTK_CONTAINER(window), box);
    gtk_widget_set_halign(box, GTK_ALIGN_CENTER);
    gtk_widget_set_valign(box, GTK_ALIGN_CENTER);

    logo = gtk_image_new_from_file("x_logo.png");
    gtk_widget_set_halign(logo, GTK_ALIGN_CENTER);
    gtk_box_pack_start(GTK_BOX(box), logo, FALSE, FALSE, 0);

    slogan_label = gtk_label_new("Ça se passe maintenant");
    gtk_widget_set_halign(slogan_label, GTK_ALIGN_CENTER);
    gtk_label_set_use_markup(GTK_LABEL(slogan_label), TRUE);
    gtk_label_set_markup(GTK_LABEL(slogan_label), "<span weight='bold' size='xx-large'>Ça se passe maintenant</span>");
    gtk_box_pack_start(GTK_BOX(box), slogan_label, FALSE, FALSE, 0);

    signup_label = gtk_label_new("Inscrivez-vous.");
    gtk_widget_set_halign(signup_label, GTK_ALIGN_CENTER);
    gtk_box_pack_start(GTK_BOX(box), signup_label, FALSE, FALSE, 0);

    google_button = gtk_button_new_with_label("S'inscrire avec Google");
    gtk_widget_set_name(google_button, "google-button");
    gtk_widget_set_halign(google_button, GTK_ALIGN_CENTER);
    gtk_widget_set_size_request(google_button, 300, -1); // Définir la taille du bouton
    g_signal_connect(google_button, "clicked", G_CALLBACK(on_sign_in_with_google_clicked), NULL);
    gtk_box_pack_start(GTK_BOX(box), google_button, FALSE, FALSE, 0);

    apple_button = gtk_button_new_with_label("S'inscrire avec Apple");
    gtk_widget_set_name(apple_button, "apple-button");
    gtk_widget_set_halign(apple_button, GTK_ALIGN_CENTER);
    gtk_widget_set_size_request(apple_button, 300, -1); // Définir la taille du bouton
    g_signal_connect(apple_button, "clicked", G_CALLBACK(on_sign_in_with_apple_clicked), NULL);
    gtk_box_pack_start(GTK_BOX(box), apple_button, FALSE, FALSE, 0);

    or_label = gtk_label_new("OU");
    gtk_widget_set_halign(or_label, GTK_ALIGN_CENTER);
    gtk_box_pack_start(GTK_BOX(box), or_label, FALSE, FALSE, 0);

    create_account_button = gtk_button_new_with_label("Créer un compte");
    gtk_widget_set_name(create_account_button, "create-account");
    gtk_widget_set_halign(create_account_button, GTK_ALIGN_CENTER);
    gtk_widget_set_size_request(create_account_button, 300, -1); // Définir la taille du bouton
    g_signal_connect(create_account_button, "clicked", G_CALLBACK(on_create_account_clicked), NULL);
    gtk_box_pack_start(GTK_BOX(box), create_account_button, FALSE, FALSE, 0);

    terms_label = gtk_label_new("En vous inscrivant, vous acceptez les Conditions d'utilisation et la Politique de confidentialité, notamment l'Utilisation des cookies.");
    gtk_widget_set_name(terms_label, "terms");
    gtk_widget_set_halign(terms_label, GTK_ALIGN_CENTER);
    gtk_box_pack_start(GTK_BOX(box), terms_label, FALSE, FALSE, 0);

    gtk_widget_show_all(window);
}

int main(int argc, char **argv) {
    GtkApplication *app;
    int status;

    app = gtk_application_new("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}