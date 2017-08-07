//
// Created by Dakota Prince on 8/6/2017.
//
#include "ai.h"
#include "game.h"

void activate_GTK(){
    //Function to build GTK Window
    w = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    GtkWidget *grid = gtk_grid_new();

    gtk_window_set_title(GTK_WINDOW(w),"Tic Tac Toe Scrub");
    gtk_window_set_position(GTK_WINDOW(w), GTK_WIN_POS_CENTER);

    //Activate Buttons
    uL = gtk_button_new_with_label("1");
    uM = gtk_button_new_with_label("2");
    uR = gtk_button_new_with_label("3");
    mL = gtk_button_new_with_label("4");
    mM = gtk_button_new_with_label("5");
    mR = gtk_button_new_with_label("6");
    bL = gtk_button_new_with_label("7");
    bM = gtk_button_new_with_label("8");
    bR = gtk_button_new_with_label("9");

    //Add buttons to grid
    gtk_grid_attach(GTK_GRID(grid),uL,0,0,1,1);
    gtk_grid_attach_next_to(GTK_GRID(grid),uM,uL,GTK_POS_RIGHT,1,1);
    gtk_grid_attach_next_to(GTK_GRID(grid),uR,uM,GTK_POS_RIGHT,1,1);

    gtk_grid_attach(GTK_GRID(grid),mL,0,1,1,1);
    gtk_grid_attach_next_to(GTK_GRID(grid),mM,mL,GTK_POS_RIGHT,1,1);
    gtk_grid_attach_next_to(GTK_GRID(grid),mR,mM,GTK_POS_RIGHT,1,1);

    gtk_grid_attach(GTK_GRID(grid),bL,0,2,1,1);
    gtk_grid_attach_next_to(GTK_GRID(grid),bM,bL,GTK_POS_RIGHT,1,1);
    gtk_grid_attach_next_to(GTK_GRID(grid),bR,bM,GTK_POS_RIGHT,1,1);

    //Add grid to window
    gtk_container_add(GTK_CONTAINER(w),grid);
}

int checkWin(int p, int b[9]) {
    if (b[0] == p && b[1] == p && b[2] == p ||
        b[3] == p && b[4] == p && b[5] == p ||
        b[6] == p && b[7] == p && b[8] == p ||
        b[0] == p && b[3] == p && b[6] == p ||
        b[1] == p && b[4] == p && b[7] == p ||
        b[2] == p && b[5] == p && b[8] == p ||
        b[0] == p && b[4] == p && b[8] == p ||
        b[2] == p && b[4] == p && b[6] == p)
    {
        return TRUE;
    }else{
        return FALSE;
    }
}
void UserInput(GtkButton *widget, gpointer data){
    //User clicked widget. get widget text and convert to int. then let Ai take turn.
    int j;
    gint64 i;
    //get text
    f = gtk_button_get_label(widget);
    //convert to gint64
    i = g_ascii_strtoll(f,NULL,0);
    //Add player token to game board
    openS[i-1] = 88;
    gtk_button_set_label(widget,"O");
    //check for human win
    j = checkWin(HUPLAYER,openS);
    //if win print to console. if this happens email me.
    if(j == 1){
        printf("Holy Hell you beat the AI!\n");
        exit(0);
    }
    open -=1;
    if(open == 0)exit(0);
    ai();
}