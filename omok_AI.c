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


NODE * createNode(int newX, int newY, int(*preboard)[N], int color) // ��带 ����� �Լ�.
{
	int i; int j;

	NODE *newNode = (NODE*)malloc(sizeof(NODE));
	if (newNode == NULL)
	{
		printf("malloc error!\n");
		return NULL;
	}

	//board�� x,y��ǥ�� �������� ���� ���´�
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
			newNode->board[i][j] = preboard[i][j]; // �� ��忡 ���带 ����
		}
	}
	

	if (color%2 == 0)
	{
			newNode->board[newX][newY] = BLACK; //�����̸� 2
	}
	else
	{
		newNode->board[newX][newY] = WHITE; //����̸� 3
	}


	newNode->val = eval(newNode);//�ش� ������ ��ġ�� ����Ͽ� ����.
	
	return newNode;
}




//2�̸� �浹, 3�̸� �鵹
int alphabeta(NODE *node, int depth,int a, int b, bool Max) //����-��Ÿ pruning �˰���
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

NODE *createTree(NODE * root,int depth,int turn) //�޾ƿ� root ��带�̿��� ������ Ʈ���� �����.
{
	int x,y;
	
	if (depth == 0)
	{
		return root;
	}
	if (turn == 2)
	{
		for (x = root->x - 2; x < root->x + 3; x++) //ù �ڽĳ��� 4x4
		{
			for (y = root->y - 2; y < root->y + 3; y++)
			{
				if (x < 1 || y < 1)
				{
					continue;
				}

				if (root->board[x][y] != 0) //���� �̹� �������ٸ� ���� ��ǥ�� �Ѿ
				{

					continue;

				}
				else
				{
					{
						NODE *temp = createNode(x, y, root->board, turn + 1);
						root->child[root->index] = temp; //���� ���� ���� �ڽ� ��尡 �ȴ�.
						root->index++;

						temp = createTree(temp, depth - 1, turn + 1);//�ڽ� ����� �ڽĳ�带 ����� ���� ���ȣ��.

					}
				}
			}
		}
	}
	else
	{
		for (x = root->x - 1; x < root->x + 2; x++) //���� ������������ 3x3�������� ���� ��带 �����.
		{
			for (y = root->y - 1; y < root->y + 2; y++)
			{
				if (x < 1 || y < 1)
				{
					continue;
				}

				if (root->board[x][y] != 0) //���� �̹� �������ٸ� ���� ��ǥ�� �Ѿ
				{

					continue;

				}
				else
				{
					{
						NODE *temp = createNode(x, y, root->board, turn + 1);
						root->child[root->index] = temp; //���� ���� ���� �ڽ� ��尡 �ȴ�.
						root->index++;

						temp = createTree(temp, depth - 1, turn + 1);//�ڽ� ����� �ڽĳ�带 ����� ���� ���ȣ��.

					}
				}
			}

		}
	}
	return root;

}
void destroyTree(NODE *node)//Ʈ���� ���ִ� �Լ�.
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