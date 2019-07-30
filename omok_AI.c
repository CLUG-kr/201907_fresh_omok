#include "omok.h"


int maxValue(int a, int b)
{
	if (a >= b)
		return a;
	else
		return b;
}

int minValue(int a, int b)
{
	if (a >= b)
		return b;
	else
		return a;
}


NODE * createNode(int newX, int newY, int(*preboard)[N], int color) // 노드를 만드는 함수.
{
	int i; int j;

	NODE *newNode = (NODE*)malloc(sizeof(NODE));
	if (newNode == NULL)
	{
		printf("malloc error!\n");
		return NULL;
	}

	//board에 x,y좌표로 받은곳에 돌을 놓는다
	newNode->x = newX;
	newNode->y = newY;
	newNode->index = 0;
	newNode->next = 0;
	
	for(i = 0; i < 25; i++) {
		newNode->child[i] = NULL;
	}
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			newNode->board[i][j] = preboard[i][j]; // 새 노드에 보드를 복사
		}
	}
	

	if (color%2 == 0)
	{
			newNode->board[newX][newY] = BLACK; //검정이면 2
	}
	else
	{
		newNode->board[newX][newY] = WHITE; //흰색이면 3
	}


	newNode->val = eval(newNode);//해당 보드의 가치를 계산하여 저장.
	
	return newNode;
}




//2이면 흑돌, 3이면 백돌
int alphabeta(NODE *node, int depth,int a, int b, bool Max) //알파-베타 pruning 알고리즘
{
	int i;
	
	int temp;


	if (depth == 0||node->index==0) 
		return node->val;
	

	if (Max == true)
	{
		temp = INT_MIN;
		for (i = 0; i <node->index; i++)
		{
			if (node->child[i] != NULL)
			{
				temp = maxValue(a, (alphabeta(node->child[i], depth - 1,a,b, false)));
				if (temp > a)
				{
					node->next = i;
				}
				a = maxValue(a, temp);
								
				if (b <= a)
				{
					break;
				}
			}

		}
				
		return a;
	}

	if (Max == false)
	{
		temp = INT_MAX;
		for (i = 0; i <node->index; i++)
		{
			if (node->child[i] != NULL)
			{
				
				temp =  minValue(b, alphabeta(node->child[i], depth - 1,a,b, true));
				if (temp < b)
				{
					node->next = i;
				}
				b = minValue(b,temp);

				if (b <= a)
				{
					
				break;
				}
			}
		}
		
		return b;
	}

}

NODE *createTree(NODE * root,int depth,int turn) //받아온 root 노드를이용해 가능한 트리를 만든다.
{
	int x,y;
	
	if (depth == 0)
	{
		return root;
	}
	if (turn == 2)
	{
		for (x = root->x - 2; x < root->x + 3; x++) //첫 자식노드는 4x4
		{
			for (y = root->y - 2; y < root->y + 3; y++)
			{
				if (x < 1 || y < 1)
				{
					continue;
				}

				if (root->board[x][y] != 0) //돌이 이미 놓여졌다면 다음 좌표로 넘어감
				{

					continue;

				}
				else
				{
					{
						NODE *temp = createNode(x, y, root->board, turn + 1);
						root->child[root->index] = temp; //새로 만든 노드는 자식 노드가 된다.
						root->index++;

						temp = createTree(temp, depth - 1, turn + 1);//자식 노드의 자식노드를 만들기 위해 재귀호출.

					}
				}
			}
		}
	}
	else
	{
		for (x = root->x - 1; x < root->x + 2; x++) //돌이 놓여진곳에서 3x3범위에서 다음 노드를 만든다.
		{
			for (y = root->y - 1; y < root->y + 2; y++)
			{
				if (x < 1 || y < 1)
				{
					continue;
				}

				if (root->board[x][y] != 0) //돌이 이미 놓여졌다면 다음 좌표로 넘어감
				{

					continue;

				}
				else
				{
					{
						NODE *temp = createNode(x, y, root->board, turn + 1);
						root->child[root->index] = temp; //새로 만든 노드는 자식 노드가 된다.
						root->index++;

						temp = createTree(temp, depth - 1, turn + 1);//자식 노드의 자식노드를 만들기 위해 재귀호출.

					}
				}
			}

		}
	}
	return root;

}
void destroyTree(NODE *node)//트리를 없애는 함수.
{
	int i;

	if (node==NULL)
	{
		return;
	}

	for (i = 0; i < node->index; i++)
	{
		
			destroyTree(node->child[i]);
	}

	free(node);


	return;
	
}