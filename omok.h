#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <Windows.h>

#define SIZE 9
#define N 20
#define BLACK 2
#define WHITE 3


void putStone(int x, int y,int color);
int blackwinTest();
int whitewinTest();


void printBoard();



typedef struct tree {

	struct tree *child[5];
	int val;

}TREE;

typedef struct omokT {

	int x;
	int y;
	int val;
	
	int board[N][N];
	int next;

	struct omokT *child[25];

	int index;

}NODE;


int eval(NODE * node);
NODE * createNode(int newX, int newY, int (*preboard)[N],int color);
NODE *createTree(NODE * root, int depth,int turn);



int alphabeta(NODE *node, int depth,int a, int b, bool Max);

void destroyTree(NODE *node);