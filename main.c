#define _CRT_SECURE_NO_WARNINGS
#include "omok.h"

int main()
{

	int board[N][N] = { 0 }; //맨 처음 사용할 board.
	int board_cal[N][N] = { 0 };
	int xy[2] = { 0 };

	int x = 0;
	int y = 0;
	int ai_x, ai_y;

	int i,j;
	int whichplayer;//1이면 플레이어가 black, 2이면 플레이어가 white
	int best;
	int newt1 = 0;
	int now;
	int limit;

	do {
		printf("select Color(1.Black, 2.White) : ");
		scanf("%d", &whichplayer);
		printf("time limit? (second) : ");
		scanf("%d", &limit);
		system("cls");
	} while (whichplayer != 1 && whichplayer != 2);

	printBoard();//첫 화면을 출력한다.

	if (whichplayer == 1)
	{
		while (1) {
			now = GetTickCount();
			do {
				printf("검은색 좌표는? (시간제한 %d초) ->",limit);
				scanf("%d, %d", &y, &x);

				if (x >= N || y >= N || x < 1 || y < 1)
				{
					printf("Out of range, try again\n");//범위를 벗어났을 때
					fflush(stdin);
					continue;

				}
				else if (board[x][y] != 0)
				{
					printf("Not available, try again\n");//이미 돌이 놓여있을 때
					fflush(stdin);
					continue;
				}
				else
					break;
			} while (1);
						
			putStone(x, y, BLACK); //흑돌 좌표를 받아 돌을 놓는다.
			calculate(board_cal, board, BLACK, x, y, &ai_x, &ai_y); //

			if (blackwinTest() == 1)//승리자가 나왔는지 확인
			{
				printf("black wins\n");
				break;
			}

			printf("흰색 계산중...\n");
			
			putStone(ai_x, ai_y, WHITE);//그 좌표에 돌을 놓는다.
			calculate(board_cal, board, WHITE, ai_x, ai_y, &ai_x, &ai_y);

			if (whitewinTest() == 1)//승리자가 나왔는지 체크.
			{
				printf("white wins\n");
				break;
			}
		}
	}
	else if (whichplayer == 2)
	{
		putStone(10, 10, BLACK);//컴퓨터가 검은색으로 시작
		calculate(board_cal, board, BLACK, 10, 10, &ai_x, &ai_y);

		while (1) {
			now = GetTickCount();
			do {
				printf("흰색 좌표는? (시간제한 %d초) ->",limit);
				scanf("%d, %d", &y, &x);

				if (x >= N || y >= N || x < 1 || y < 1)
				{
					printf("Out of range, try again\n");//범위를 벗어났을 때
					fflush(stdin);
					continue;

				}
				else if (board[x][y] != 0)
				{
					printf("Not available, try again\n");//이미 돌이 놓여있을 때
					fflush(stdin);
					continue;
				}
				else
					break;
			} while (1);

			putStone(x, y, WHITE);
			calculate(board_cal, board, WHITE, x, y, &ai_x, &ai_y);
			
			if (whitewinTest() == 1)//승리자가 나왔는지 체크.
			{
				printf("white wins\n");
				break;
			}

			printf("검은색 계산중...\n");

			putStone(ai_x, ai_y, BLACK);//그 좌표에 돌을 놓는다.
			calculate(board_cal, board, BLACK, ai_x, ai_y, &ai_x, &ai_y);
			
			if (blackwinTest() == 1)//승리자가 나왔는지 체크.
			{
				printf("black wins\n");
				break;
			}
		}

	}
	
	
	fflush(stdin);
	getch();
	return 0;

	
}