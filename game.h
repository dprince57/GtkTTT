//
// Created by Dakota Prince on 8/6/2017.
//

#ifndef GTKTTT_GAME_H
#define GTKTTT_GAME_H

#include <gtk/gtk.h>
#include <unistd.h>

#define HUPLAYER 88
#define AIPLAYER 79

GtkWidget *uL;
GtkWidget *uM;
GtkWidget *uR;
GtkWidget *mL;
GtkWidget *mM;
GtkWidget *mR;
GtkWidget *bL;
GtkWidget *bM;
GtkWidget *bR;
GtkWidget *bottom;

GtkWidget *w;
const gchar *f;

extern int openS[9];
extern int openp;

int who_f();
int checkWin(int p,int b[9]);
void activate_GTK();
void UserInput(GtkButton *widget, gpointer data);
void game_loop();
void resetG();

#endif //GTKTTT_GAME_H
