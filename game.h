//
// Created by Dakota Prince on 8/6/2017.
//

#ifndef GTKTTT_GAME_H
#define GTKTTT_GAME_H

#include <gtk/gtk.h>

#define HUPLAYER 88
#define AIPLAYER 79

extern GtkWidget *uL;
extern GtkWidget *uM;
extern GtkWidget *uR;
extern GtkWidget *mL;
extern GtkWidget *mM;
extern GtkWidget *mR;
extern GtkWidget *bL;
extern GtkWidget *bM;
extern GtkWidget *bR;

extern GtkWidget *w;
extern const gchar *f;

int checkWin(int p,int b[9]);
void activate_GTK();
void UserInput(GtkButton *widget, gpointer data);

#endif //GTKTTT_GAME_H
