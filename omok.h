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

void eval(int(*board_cal)[N], int(*board)[N], int x, int y);
void putStone(int x, int y,int color);
int blackwinTest();
int whitewinTest();

void printBoard();

