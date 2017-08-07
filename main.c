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
 *    Websites for Learning Algorithms:
 *      https://en.wikipedia.org/wiki/Alpha-beta_pruning
 *      https://en.wikipedia.org/wiki/Minimax
 *
 *    If you download this code and find flaws email me.
 *
 */


#include <stdio.h>
#include <gtk/gtk.h>
#include "game.h"

int openS[9] = {1,2,3,4,5,6,7,8,9};
int open= 9;

int main(int argc, char *argv[]) {

    //GTK Game Loop
    gtk_init(&argc, &argv);
    activate_GTK();
    game_loop();

}
