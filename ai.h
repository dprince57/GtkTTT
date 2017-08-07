//
// Created by Dakota Prince on 8/6/2017.
//

#ifndef GTKTTT_AI_H
#define GTKTTT_AI_H

#include <stdlib.h>
#include <gtk/gtk.h>

extern int openS[9];
extern int open;

void ai();
void placeAi(int b);

int alphaBeta(int depth,int board[9],int mM);

#endif //GTKTTT_AI_H
