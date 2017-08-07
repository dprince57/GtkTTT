/*  Design and code by: Dakota Prince
 *
 *  Algorithm used for unbeatable AI:
 *      Minimax W/ Alpha Beta Pruning
 *      Used if statements to check for
 *          immediate win for human to block win
 *
 *  Dependencies are:
 *      GTK
 *      GLIB
 *
 *    Websites for Learning Algos:
 *      https://en.wikipedia.org/wiki/Alpha-beta_pruning
 *      https://en.wikipedia.org/wiki/Minimax
 *
 *    If you download this code and find flaws email me.
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include "ai.h"
#include "game.h"


//GTK Globals
GtkWidget *w;

//The Buttons
GtkWidget *uL;
GtkWidget *uM;
GtkWidget *uR;
GtkWidget *mL;
GtkWidget *mM;
GtkWidget *mR;
GtkWidget *bL;
GtkWidget *bM;
GtkWidget *bR;

//Global Vars
int openS[9] = {1,2,3,4,5,6,7,8,9};
int open = 9;
const gchar *f;

//Prototyped functions


int main(int argc, char *argv[]) {

    //GTK Game Loop
    gtk_init(&argc, &argv);
    activate_GTK();
    gtk_widget_show_all(w);
    g_signal_connect(G_OBJECT(uL), "clicked", G_CALLBACK(UserInput), NULL);
    g_signal_connect(G_OBJECT(mL), "clicked", G_CALLBACK(UserInput), NULL);
    g_signal_connect(G_OBJECT(bL), "clicked", G_CALLBACK(UserInput), NULL);
    g_signal_connect(G_OBJECT(uM), "clicked", G_CALLBACK(UserInput), NULL);
    g_signal_connect(G_OBJECT(mM), "clicked", G_CALLBACK(UserInput), NULL);
    g_signal_connect(G_OBJECT(bM), "clicked", G_CALLBACK(UserInput), NULL);
    g_signal_connect(G_OBJECT(uR), "clicked", G_CALLBACK(UserInput), NULL);
    g_signal_connect(G_OBJECT(mR), "clicked", G_CALLBACK(UserInput), NULL);
    g_signal_connect(G_OBJECT(bR), "clicked", G_CALLBACK(UserInput), NULL);
    if(open == 0){return 0;}
    g_signal_connect(w, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_main();

}
