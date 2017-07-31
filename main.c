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
 *      NOTE: DO NOT PICK THE MIDDLE BUTTON OR AI WILL CRASH.
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

#define HUPLAYER 88
#define AIPLAYER 79

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
int status = 9;
const gchar *f;

//Prototyped functions
void ai();
void placeAi(int b);
int checkWin(int player,int b[9]);
int alphaBeta(int depth,int board[9],int mM);
void activate_GTK();
void UserInput(GtkButton *widget, gpointer data);

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
    if(status == 0){return 0;}
    g_signal_connect(w, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_main();

}
void UserInput(GtkButton *widget, gpointer data){
    //User clicked widget. get widget text and convert to int. then let Ai take turn.
    int j;
    gint64 i;
    //get text
    f = gtk_button_get_label(widget);
    //convert to gint64
    i = g_ascii_strtoll(f,NULL,0);
    openS[i-1] = 88;
    gtk_button_set_label(widget,"O");
    j = checkWin(HUPLAYER,openS);
    //if win print to console. if this happens email me.
    if(j == 1){printf("Holy Hell you beat the AI!\n");exit(0);}
    ai();
}
void ai(){
    int j,tS,wC;
    int bS = -1;
    int bMa;
    //Main AI for loop
    for(int i = 0;i<9;i++){
        if(openS[i] != 88 && openS[i] != 79){
            //Win check Human. If he wins block him
            openS[i] = 88;
            wC = checkWin(HUPLAYER,openS);
            if(wC == TRUE){
                bMa = i;
                break;
            }
            //Win check AI. If AI has it in the bag. DO IT!
            openS[i] = 79;
            wC = checkWin(AIPLAYER,openS);
            if(wC == TRUE){
                bMa = i;
                break;
            }
            //if no winstate alphabeta the bestscore
            tS = alphaBeta(status-1,openS,88);
            if(tS>bS){bMa = i;bS=tS;}
            openS[i] = i;
        }
    }
    if(bMa > 20){printf("Tie.");exit(0);}
    //made place AI so it doesnt loop crowded. We all know how to assign variables.
    placeAi(bMa);
    j = checkWin(AIPLAYER,openS);
    //print win for ai. if this happens you should feel really bad.
    if(j == TRUE){status = 0;printf("HA! The AI won and you lost\n");exit(0);}
}
int alphaBeta(int depth, int board[9],int mM){
    int bV = 0;
    int j = checkWin(mM,board);

    //Terminal State Checker. Will check for terminal states in game and return value for it.
    if(j == TRUE) {
        if (mM == HUPLAYER) {
            return -10;
        } else {
            return 10;
        }
    }
    if(depth == 0)return 0;
    //If terminal state is not found we will recurse Alpha Beta until we find a winning or losing combo
    for(int i = 0;i<9;i++){
        if(board[i] != 88 && board[i] != 79) {
            //AI player Loop
            if (mM == AIPLAYER) {
                board[i] = 79;
                bV += alphaBeta(depth - 1, board, 88);
                board[i] = i;
                if(bV > 0)return bV;
            }else{          //Human player check.
                board[i] = 88;
                bV += alphaBeta(depth - 1, board, 79);
                board[i] = i;
                if(bV < 0)return bV;
                board[i] = i;
            }
        }
    }
    return bV;
}
void placeAi(int b){
    openS[b] = 79;
    switch(b){
        case 0:
            gtk_button_set_label((GtkButton *) uL, "X");
            break;
        case 1:
            gtk_button_set_label((GtkButton *) uM, "X");
            break;
        case 2:
            gtk_button_set_label((GtkButton *) uR, "X");
            break;
        case 3:
            gtk_button_set_label((GtkButton *) mL, "X");
            break;
        case 4:
            gtk_button_set_label((GtkButton *) mM, "X");
            break;
        case 5:
            gtk_button_set_label((GtkButton *) mR, "X");
            break;
        case 6:
            gtk_button_set_label((GtkButton *) bL, "X");
            break;
        case 7:
            gtk_button_set_label((GtkButton *) bM, "X");
            break;
        case 8:
            gtk_button_set_label((GtkButton *) bR, "X");
            break;
    }
}
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
int checkWin(int player,int b[9]) {
    if (b[0] == player && b[1] == player && b[2] == player ||
        b[3] == player && b[4] == player && b[5] == player ||
        b[6] == player && b[7] == player && b[8] == player ||
        b[0] == player && b[3] == player && b[6] == player ||
        b[1] == player && b[4] == player && b[7] == player ||
        b[2] == player && b[5] == player && b[8] == player ||
        b[0] == player && b[4] == player && b[8] == player ||
        b[2] == player && b[4] == player && b[6] == player)
    {
        return TRUE;
    }else{
        return FALSE;
    }
}