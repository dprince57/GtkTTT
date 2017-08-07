//
// Created by Dakota Prince on 8/6/2017.
//

#include "ai.h"
#include "game.h"

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
            tS = alphaBeta(open-1,openS,88);
            if(tS>bS){bMa = i;bS=tS;}
            openS[i] = i;
        }
    }
    printf("bma = %d\n",bMa);
    if(bMa > 9){bMa = 0;}
    //made place AI so it doesnt loop crowded. We all know how to assign variables.
    placeAi(bMa);
    open -= 1;
    if(open == 0){
        printf("Game over Tie!\n");
        exit(0);
    }
    j = checkWin(AIPLAYER,openS);
    //print win for ai. if this happens you should feel really bad.
    if(j == TRUE){
        printf("HA! The AI won and you lost\n");
        exit(0);
    }
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
                if(bV < -10)return bV;
                board[i] = i;
            }
        }
    }
    return bV;
}
void placeAi(int b){
    //Add AI token to board.
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