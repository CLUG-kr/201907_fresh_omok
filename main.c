#include "omok.h"

int main()
{

	int board[N][N] = { 0 }; //맨 처음 사용할 board.
	
	int x, y;

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
				scanf("%d,%d", &x, &y);

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
						
			if (GetTickCount() - now > limit*1000)//시간제한
			{
				printf("time over, white wins\n");
				break;
			}
			putStone(x, y, BLACK); //흑돌 좌표를 받아 돌을 놓는다.
			if (blackwinTest() == 1)//승리자가 나왔는지 확인
			{
				printf("black wins\n");
				break;
			}

			printf("흰색 계산중...\n");
			now = GetTickCount();
			NODE * t1 = createNode(x, y, board, BLACK);//흑돌이 놓은곳을 root 노드로 만든다.
			board[x][y] = 2;//흑돌이 놓인곳에 2를 저장

			t1 = createTree(t1,5, 2);//depth가 5인 트리를 만든다.
			for (i = 0; i < 3; i++)//1,3,5깊이로 Search
			{
				newt1 = alphabeta(t1, i*2+1, INT_MIN, INT_MAX, false);
				if (GetTickCount() - now > limit*1000)
					break;
			}
			if (GetTickCount() - now > limit*1000)
			{
				printf("time over, black wins\n");
				break;
			}
			putStone(t1->child[t1->next]->x, t1->child[t1->next]->y, WHITE);//그 좌표에 돌을 놓는다.
			board[t1->child[t1->next]->x][t1->child[t1->next]->y] = WHITE;//보드에 3을 저장.
			if (whitewinTest() == 1)//승리자가 나왔는지 체크.
			{
				printf("white wins\n");
				break;
			}
		
			destroyTree(t1);//트리를 없앰


		}
	}
	else if (whichplayer == 2)
	{
		putStone(10, 10, BLACK);//컴퓨터가 검은색으로 시작
		board[10][10] = BLACK;

		while (1) {
			now = GetTickCount();
			do {
				printf("흰색 좌표는? (시간제한 %d초) ->",limit);
				scanf("%d,%d", &x, &y);

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


			if (GetTickCount() - now > limit*1000)//시간제한30초
			{
				printf("time over, black wins\n");
				break;
			}

			putStone(x, y, WHITE); //흑돌 좌표를 받아 돌을 놓는다.
			if (whitewinTest() == 1)//승리자가 나왔는지 확인
			{
				printf("white wins\n");
				break;
			}

			now = GetTickCount();
			printf("검은색 계산중...\n");
			NODE * t1 = createNode(x, y, board, WHITE);//백돌이 놓은곳을 root 노드로 만든다.
			board[x][y] = WHITE;//백돌이 놓인곳에 3를 저장


			t1 = createTree(t1, 5, 2);//depth가 5인 트리를 만든다.
			for (i = 0; i < 3; i++)//1,3,5깊이로 Search
			{
				newt1 = alphabeta(t1, i * 2 + 1, INT_MIN, INT_MAX, true);
				if (GetTickCount() - now > limit*1000)
					break;
			}
			if (GetTickCount() - now > limit*1000)
			{
				printf("time over, white wins\n");
				break;
			}
			
			putStone(t1->child[t1->next]->x, t1->child[t1->next]->y, BLACK);//그 좌표에 돌을 놓는다.
			board[t1->child[t1->next]->x][t1->child[t1->next]->y] = BLACK;//보드에 3을 저장.

			if (blackwinTest() == 1)//승리자가 나왔는지 체크.
			{
				printf("black wins\n");
				break;
			}
			destroyTree(t1);//트리를 없앰


		}

	}
	
	
	fflush(stdin);
	getch();
	return 0;

	
}