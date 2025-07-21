#include<iostream>
#include<ctime>
#include"help.h"
using namespace std;

void printboard(int arr[][8], int row);

//The word Score
void score()
{
	myLine(480, 300, 520, 300, 255);	//next 6 lines for S
	myLine(480, 300, 480, 340, 255);
	myLine(480, 340, 520, 340, 255);
	myLine(520, 340, 520, 380, 255);
	myLine(480, 380, 520, 380, 255);

	myLine(540, 300, 580, 300, 255);	//next 3 lines for C
	myLine(540, 300, 540, 380, 255);
	myLine(540, 380, 580, 380, 255);


	myLine(620, 300, 680, 300, 255);	//next 4 lines for O
	myLine(620, 300, 620, 380, 255);
	myLine(620, 380, 680, 380, 255);
	myLine(680, 300, 680, 380, 255);

	myLine(720, 300, 780, 300, 255);	//next 6 lines for R
	myLine(720, 300, 720, 340, 255);
	myLine(780, 300, 780, 340, 255);
	myLine(720, 340, 780, 340, 255);
	myLine(720, 340, 720, 380, 255);
	myLine(720, 340, 780, 380, 255);

	myLine(820, 300, 880, 300, 255);	//next 4 lines for E
	myLine(820, 300, 820, 380, 255);
	myLine(820, 340, 880, 340, 255);
	myLine(820, 380, 880, 380, 255);
}

//numbers print
void num1(int x) {

	if (x == 0)
	{
		myLine(480, 20, 540, 20, 255);	//  top line
		myLine(540, 20, 540, 65, 255);	//  right top 
		myLine(540, 65, 540, 110, 255);	//  right bottom
		myLine(480, 20, 480, 65, 255);	//  left top
		myLine(480, 65, 480, 110, 255); //  left bottom
		myLine(480, 110, 540, 110, 255);	//  bottom line
	}
	else if (x == 1)
	{
		myLine(540, 20, 540, 65, 255);	//  right top 
		myLine(540, 65, 540, 110, 255);	//  right bottom
	}
	else if (x == 2)
	{
		myLine(480, 20, 540, 20, 255);	//  top line
		myLine(540, 20, 540, 65, 255);	//  right top 
		myLine(480, 65, 540, 65, 255);	//  middle
		myLine(480, 65, 480, 110, 255); //  left bottom
		myLine(480, 110, 540, 110, 255);	//  bottom line
	}
	else if (x == 3)
	{
		myLine(480, 20, 540, 20, 255);	//  top line
		myLine(540, 20, 540, 65, 255);	//  right top 
		myLine(480, 65, 540, 65, 255);	//  middle
		myLine(540, 65, 540, 110, 255);	//  right bottom
		myLine(480, 110, 540, 110, 255);	//  bottom line
	}
	else if (x == 4)
	{
		myLine(540, 20, 540, 65, 255);	//  right top 
		myLine(540, 65, 540, 110, 255);	//  right bottom
		myLine(480, 65, 540, 65, 255);	//  middle
		myLine(480, 20, 480, 65, 255);	//  left top
	}
	else if (x == 5)
	{
		myLine(480, 20, 540, 20, 255);	//  top line
		myLine(480, 20, 480, 65, 255);	//  left top
		myLine(480, 65, 540, 65, 255);	//  middle
		myLine(540, 65, 540, 110, 255);	//  right bottom
		myLine(480, 110, 540, 110, 255);	//  bottom line
	}
	else if (x == 6)
	{
		myLine(480, 20, 540, 20, 255);	//  top line
		myLine(480, 20, 480, 65, 255);	//  left top
		myLine(480, 65, 540, 65, 255);	//  middle
		myLine(540, 65, 540, 110, 255);	//  right bottom
		myLine(480, 65, 480, 110, 255); //  left bottom
		myLine(480, 110, 540, 110, 255);	//  bottom line
	}
	else if (x == 7)
	{
		myLine(480, 20, 540, 20, 255);	//  top line
		myLine(540, 20, 540, 65, 255);	//  right top 
		myLine(540, 65, 540, 110, 255);	//  right bottom
		myLine(510, 65, 540, 65, 255);	//  middle

	}
	else if (x == 8)
	{
		myLine(480, 20, 540, 20, 255);	//  top line
		myLine(540, 20, 540, 65, 255);	//  right top 
		myLine(540, 65, 540, 110, 255);	//  right bottom
		myLine(480, 20, 480, 65, 255);	//  left top
		myLine(480, 65, 480, 110, 255); //  left bottom
		myLine(480, 65, 540, 65, 255);	//  middle
		myLine(480, 110, 540, 110, 255);	//  bottom line
	}
	else if (x == 9)
	{
		myLine(480, 20, 540, 20, 255);	//  top line
		myLine(540, 20, 540, 65, 255);	//  right top 
		myLine(540, 65, 540, 110, 255);	//  right bottom
		myLine(480, 65, 540, 65, 255);	//  middle
		myLine(480, 20, 480, 65, 255);	//  left top

	}

}

void num2(int y) {
	if (y == 0)
	{
		myLine(600, 20, 660, 20, 255);	//2 top line
		myLine(660, 20, 660, 65, 255);	//2 right top
		myLine(660, 65, 660, 110, 255);	//2 right bottom
		myLine(600, 20, 600, 65, 255);	//2 left top
		myLine(600, 65, 600, 110, 255);	//2 left bottom
		myLine(600, 110, 660, 110, 255);	//2 bottom line
	}
	else if (y == 1)
	{
		myLine(660, 20, 660, 65, 255);	//2 right top
		myLine(660, 65, 660, 110, 255);	//2 right bottom
	}
	else if (y == 2)
	{
		myLine(600, 20, 660, 20, 255);	//2 top line
		myLine(660, 20, 660, 65, 255);	//2 right top
		myLine(600, 65, 660, 65, 255);	//2 middle
		myLine(600, 65, 600, 110, 255);	//2 left bottom
		myLine(600, 110, 660, 110, 255);	//2 bottom line
	}
	else if (y == 3)
	{
		myLine(600, 20, 660, 20, 255);	//2 top line
		myLine(660, 20, 660, 65, 255);	//2 right top
		myLine(660, 65, 660, 110, 255);	//2 right bottom
		myLine(600, 65, 660, 65, 255);	//2 middle
		myLine(600, 110, 660, 110, 255);	//2 bottom line
	}
	else if (y == 4)
	{
		myLine(660, 20, 660, 65, 255);	//2 right top
		myLine(600, 20, 600, 65, 255);	//2 left top
		myLine(660, 65, 660, 110, 255);	//2 right bottom
		myLine(600, 65, 660, 65, 255);	//2 middle
	}
	else if (y == 5)
	{
		myLine(600, 20, 660, 20, 255);	//2 top line
		myLine(600, 20, 600, 65, 255);	//2 left top
		myLine(600, 65, 660, 65, 255);	//2 middle
		myLine(660, 65, 660, 110, 255);	//2 right bottom
		myLine(600, 110, 660, 110, 255);	//2 bottom line
	}
	else if (y == 6)
	{
		myLine(600, 20, 660, 20, 255);		//2 top line
		myLine(600, 20, 600, 65, 255);		//2 left top
		myLine(600, 65, 660, 65, 255);		//2 middle
		myLine(660, 65, 660, 110, 255);		//2 right bottom
		myLine(600, 110, 660, 110, 255);	//2 bottom line
		myLine(600, 65, 600, 110, 255);		//2 left bottom
	}
	else if (y == 7)
	{
		myLine(600, 20, 660, 20, 255);		//2 top line
		myLine(660, 20, 660, 65, 255);		//2 right top
		myLine(620, 65, 660, 65, 255);		//2 middle
		myLine(660, 65, 660, 110, 255);		//2 right bottom
	}
	else if (y == 8)
	{
		myLine(600, 20, 660, 20, 255);	//2 top line
		myLine(660, 20, 660, 65, 255);	//2 right top
		myLine(660, 65, 660, 110, 255);	//2 right bottom
		myLine(600, 20, 600, 65, 255);	//2 left top
		myLine(600, 65, 600, 110, 255);	//2 left bottom
		myLine(600, 65, 660, 65, 255);		//2 middle
		myLine(600, 110, 660, 110, 255);	//2 bottom line
	}
	else if (y == 9)
	{
		myLine(600, 20, 660, 20, 255);		//2 top line
		myLine(600, 20, 600, 65, 255);		//2 left top
		myLine(660, 20, 660, 65, 255);		//2 right top
		myLine(600, 65, 660, 65, 255);		//2 middle
		myLine(660, 65, 660, 110, 255);		//2 right bottom
		myLine(600, 110, 660, 110, 255);	//2 bottom line
	}
}

//function calling above two functions for numbers
void score_print(int score_total)
{
	int x, y;
	y = score_total / 10;
	x = score_total % 10;
	myRect(450, 10, 700, 150, 255, 20, 40, 55, 95, 255);
	num1(y);
	num2(x);
}

//four gem explode to make code efficient
void four_gem_explode(int arr[][8], int i,int j)
{
	int k = i;
	arr[k][j] = (rand() % 5) + 1;
	arr[k][j + 1] = (rand() % 5) + 1;
	arr[k][j - 1] = (rand() % 5) + 1;
	arr[k - 1][j] = (rand() % 5) + 1;
	arr[k - 1][j + 1] = (rand() % 5) + 1;
	arr[k - 1][j - 1] = (rand() % 5) + 1;
	arr[k + 1][j] = (rand() % 5) + 1;
	arr[k + 1][j - 1] = (rand() % 5) + 1;
	arr[k + 1][j + 1] = (rand() % 5) + 1;
	while (k != 1)
	{
		swap(arr[k][j], arr[k - 1][j]);
		swap(arr[k + 1][j], arr[k - 1 + 1][j]);
		swap(arr[k - 1][j], arr[k - 1 - 1][j]);
		swap(arr[k][j], arr[k - 1][j + 1]);
		swap(arr[k + 1][j], arr[k - 1 + 1][j + 1]);
		swap(arr[k - 1][j], arr[k - 1 - 1][j + 1]);
		swap(arr[k][j], arr[k - 1][j - 1]);
		swap(arr[k + 1][j], arr[k - 1 + 1][j - 1]);
		swap(arr[k - 1][j], arr[k - 1 - 1][j - 1]);
		k--;
	}
}

//five explode to make code efficient
void five_gem_explode(int arr[][8], int i, int j)
{
	for (int k = 0; k < 8; k++)
	{
		arr[k][j] = rand() % 5 + 1;
		arr[i][k] = rand() % 5 + 1;
	}
	for (int l = i; l > 0; l--)
	{
		for (int k = 0; k < 8; k++)
		{
			swap(arr[l][k], arr[l - 1][k]);
		}
	}
	
}

//all the possibilities in which blue special gem can explode
bool five_special_vertical_possible_one(int arr[][8], int& score)
{
	bool flag = 0;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (arr[i][j] - 10 == arr[i + 1][j] && arr[i][j] - 10 == arr[i + 2][j])
			{
				score = score + 3;
				flag = 1;
				five_gem_explode(arr, i, j);
			}
		}
	}
	return flag;
}
bool five_special_vertical_possible_two(int arr[][8], int& score)
{
	
	bool flag = 0;
	for (int i = 1; i < 7; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (arr[i][j] - 10 == arr[i + 1][j] && arr[i][j] - 10 == arr[i - 1][j])
			{
				score = score + 3;
				flag = 1;
				five_gem_explode(arr, i, j);
			}
		}
	}
	return flag;
}
bool five_special_vertical_possible_three(int arr[][8], int& score)
{
	
	bool flag = 0;
	for (int i = 2; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (arr[i][j] - 10 == arr[i - 1][j] && arr[i][j] -10== arr[i - 2][j])
			{
				score = score + 3;
				flag = 1;
				five_gem_explode(arr, i, j);
			}
		}
	}
	return flag;
}
bool five_special_horizontal_possible_one(int arr[][8], int& score)
{
	bool flag = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (arr[i][j] - 10 == arr[i][j+1] && arr[i][j] - 10 == arr[i][j+2])
			{
				score = score + 3;
				flag = 1;
				five_gem_explode(arr, i, j);
			}
		}
	}
	return flag;
}
bool five_special_horizontal_possible_two(int arr[][8], int& score)
{

	bool flag = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 1; j < 7; j++)
		{
			if (arr[i][j] - 10 == arr[i][j+1] && arr[i][j] - 10 == arr[i][j-1])
			{
				score = score + 3;
				flag = 1;
				five_gem_explode(arr, i, j);
			}
		}
	}
	return flag;
}
bool five_special_horizontal_possible_three(int arr[][8], int& score)
{

	bool flag = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 2; j < 8; j++)
		{
			if (arr[i][j] - 10 == arr[i][j-1] && arr[i][j] - 10 == arr[i][j-2])
			{
				score = score + 3;
				flag = 1;
				five_gem_explode(arr, i, j);
			}
		}
	}
	return flag;
}
//all the possibilities in which red special gem can explode
bool four_special_vertical_possible_one(int arr[][8], int& score)
{
	
	bool flag = 0;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (arr[i][j]-5 == arr[i + 1][j] && arr[i][j]-5 == arr[i + 2][j])
			{
				score = score + 2;
				flag = 1;
				four_gem_explode(arr, i, j);
			}
		}
	}
	return flag;
}
bool four_special_vertical_possible_two(int arr[][8], int& score)
{
	bool flag = 0;
	for (int i = 1; i < 7; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (arr[i][j]-5 == arr[i + 1][j] && arr[i][j]-5 == arr[i - 1][j])
			{
				score = score + 2;
				flag = 1;
				four_gem_explode(arr, i, j);
			}
		}
	}
	return flag;
}
bool four_special_vertical_possible_three(int arr[][8], int& score)
{
	bool flag = 0;
	for (int i = 2; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (arr[i][j] - 5 == arr[i - 1][j] && arr[i][j] -5 == arr[i - 2][j])
			{
				score = score + 2;
				flag = 1;
				four_gem_explode(arr, i, j);
			}
		}
	}
	return flag;
}

bool four_special_horizontal_possible_one(int arr[][8], int& score)
{

	bool flag = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (arr[i][j] - 5 == arr[i][j+1] && arr[i][j] - 5 == arr[i][j+2])
			{
				score = score + 2;
				flag = 1;
				four_gem_explode(arr, i, j);
			}
		}
	}
	return flag;
}
bool four_special_horizontal_possible_two(int arr[][8], int& score)
{
	bool flag = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 1; j < 7; j++)
		{
			if (arr[i][j] - 5 == arr[i][j+1] && arr[i][j] - 5 == arr[i][j-1])
			{
				score = score + 2;
				flag = 1;
				four_gem_explode(arr, i, j);
			}
		}
	}
	return flag;
}
bool four_special_horizontal_possible_three(int arr[][8], int& score)
{

	bool flag = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 2; j < 8; j++)
		{
			if (arr[i][j] - 5 == arr[i][j-1] && arr[i][j] - 5 == arr[i][j-2])
			{
				score = score + 2;
				flag = 1;
				four_gem_explode(arr, i, j);
			}
		}
	}
	return flag;
}
//L shape possibility
bool L_possible_one(int arr[][8], int& score)
{
	int k;
	bool flag = 0;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j] && arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2])
			{
				score = score + 3;
				flag = 1;
				k = i;
				arr[k][j] = arr[k][j] + 10;;
				arr[k + 1][j] = (rand() % 5) + 1;
				arr[k + 2][j] = (rand() % 5) + 1;
				arr[k][j + 1] = rand() % 5 + 1;
				arr[k][j + 2] = rand() % 5 + 1;				
				while (k != 0)
				{					
					swap(arr[k + 1][j], arr[k - 1 + 1][j]);
					swap(arr[k + 2][j], arr[k - 1 + 2][j]);
					swap(arr[k][j + 1], arr[k - 1][j + 1]);
					swap(arr[k][j + 1], arr[k - 1][j + 2]);
					k--;
				}
			}
		}
	}
	return flag;
}

bool L_possible_two(int arr[][8], int& score)
{
	int k;
	bool flag = 0;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 2; j < 8; j++)
		{
			if (arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j] && arr[i][j] == arr[i][j - 1] && arr[i][j] == arr[i][j - 2])
			{
				score = score + 3;
				flag = 1;
				k = i;
				arr[k][j] = arr[k][j]+10;
				arr[k + 1][j] = (rand() % 5) + 1;
				arr[k + 2][j] = (rand() % 5) + 1;
				arr[k][j - 1] = rand() % 5 + 1;
				arr[k][j - 2] = rand() % 5 + 1;				
				while (k != 0)
				{					
					swap(arr[k + 1][j], arr[k - 1 + 1][j]);
					swap(arr[k + 2][j], arr[k - 1 + 2][j]);
					swap(arr[k][-1], arr[k - 1][j - 1]);
					swap(arr[k][-2], arr[k - 1][j - 2]);
					k--;

				}
			}
		}
	}
	return flag;
}

bool L_possible_three(int arr[][8], int& score)
{
	int k;
	bool flag = 0;
	for (int i = 2; i < 8; i++)
	{
		for (int j = 2; j < 8; j++)
		{
			if (arr[i][j] == arr[i - 1][j] && arr[i][j] == arr[i - 2][j] && arr[i][j] == arr[i][j - 1] && arr[i][j] == arr[i][j - 2])
			{
				score = score + 3;
				flag = 1;
				k = i;
				arr[k][j] = arr[k][j]+10;
				arr[k - 1][j] = (rand() % 5) + 1;
				arr[k - 2][j] = (rand() % 5) + 1;
				arr[k][j - 1] = rand() % 5 + 1;
				arr[k][j - 2] = rand() % 5 + 1;
				
				while (k != 2)
				{
					swap(arr[k][j], arr[k - 1][j]);
					swap(arr[k - 1][j], arr[k - 1 - 1][j]);
					swap(arr[k - 2][j], arr[k - 1 - 2][j]);
					swap(arr[k][j - 1], arr[k - 1][j - 1]);
					swap(arr[k][j - 2], arr[k - 1][j - 2]);
					k--;
				}
				while (k != 0)
				{
					swap(arr[k][j - 1], arr[k - 1][j - 1]);
					swap(arr[k][j - 2], arr[k - 1][j - 2]);
					k--;
				}
			}
		}
	}
	return flag;
}

bool L_possible_four(int arr[][8], int& score)
{
	int k;
	bool flag = 0;
	for (int i = 2; i < 8; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (arr[i][j] == arr[i - 1][j] && arr[i][j] == arr[i - 2][j] && arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2])
			{
				score = score + 3;
				flag = 1;
				k = i;
				arr[k][j] = arr[k][j]+10;
				arr[k - 1][j] = (rand() % 5) + 1;
				arr[k - 2][j] = (rand() % 5) + 1;
				arr[k][j + 1] = rand() % 5 + 1;
				arr[k][j + 2] = rand() % 5 + 1;		
				while (k != 2)
				{					
					swap(arr[k - 1][j], arr[k - 1 - 1][j]);
					swap(arr[k - 2][j], arr[k - 1 - 2][j]);
					swap(arr[k][j + 1], arr[k - 1][j + 1]);
					swap(arr[k][j + 2], arr[k - 1][j + 2]);
					k--;
				}
				while (k != 0)
				{
					swap(arr[k][j + 1], arr[k - 1][j + 1]);
					swap(arr[k][j + 2], arr[k - 1][j + 2]);
					k--;
				}
			}
		}
	}
	return flag;
}
//4 possible
bool four_vertical_possible(int arr[][8], int& score)
{
	int k;
	bool flag = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j] && arr[i][j] == arr[i + 3][j])
			{
				score = score + 2;
				flag = 1;
				k = i;
				arr[k][j] = arr[k][j]+5;
				arr[k + 1][j] = (rand() % 5) + 1;
				arr[k + 2][j] = (rand() % 5) + 1;
				arr[k + 3][j] = rand() % 5 + 1;
				while (k != 0)
				{
					swap(arr[k + 1][j], arr[k - 1 + 1][j]);
					swap(arr[k + 2][j], arr[k - 1 + 2][j]);
					swap(arr[k + 3][j], arr[k - 1 + 3][j]);
					k--;
				}
			}
		}
	}
	return flag;
}

bool four_horizontal_possible(int arr[][8], int& score)
{
	int k;

	bool flag = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2] && arr[i][j] == arr[i][j + 3])
			{
				score = score + 2;
				flag = 1;
				k = i;
				arr[k][j] = arr[k][j]+5;
				arr[k][j + 1] = (rand() % 5) + 1;
				arr[k][j + 2] = (rand() % 5) + 1;
				arr[k][j + 3] = (rand() % 5) + 1;
				while (k != 0)
				{
					swap(arr[k][j + 1], arr[k - 1][j + 1]);
					swap(arr[k][j + 2], arr[k - 1][j + 2]);
					swap(arr[k][j + 3], arr[k - 1][j + 3]);
					k--;
				}
			}
		}
	}
	return flag;
}

//3 gem possible
bool vertical_possible(int arr[][8], int& score)
{
	int k;
	bool flag = 0;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j])
			{
				score = score + 1;
				flag = 1;
				k = i;
				arr[k][j] = (rand() % 5) + 1;
				arr[k + 1][j] = (rand() % 5) + 1;
				arr[k + 2][j] = (rand() % 5) + 1;
				while (arr[k][j] == arr[k + 2][j])
					arr[k + 2][j] = (rand() % 5) + 1;
				while (k != 0)
				{
					swap(arr[k][j], arr[k - 1][j]);
					swap(arr[k + 1][j], arr[k - 1 + 1][j]);
					swap(arr[k + 2][j], arr[k - 1 + 2][j]);
					k--;
				}
			}
		}
	}
	return flag;
}


bool horizontal_possible(int arr[][8],int& score)
{
	int k;

	bool flag = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2])
			{
				score = score + 1;
				flag = 1;
				k = i;
				arr[k][j] = (rand() % 5) + 1;
				arr[k][j + 1] = (rand() % 5) + 1;
				arr[k][j + 2] = (rand() % 5) + 1;
				while (arr[k][j] == arr[k][j + 2])
					arr[k][j + 2] = (rand() % 5) + 1;
				while (k != 0)
				{
					swap(arr[k][j], arr[k - 1][j]);
					swap(arr[k][j + 1], arr[k - 1][j + 1]);
					swap(arr[k][j + 2], arr[k - 1][j + 2]);
					k--;
				}
			}
		}
	}
	return flag;
}

//all the possibility are combined to make code efficient
bool possible(int arr[][8],int& score)
{
	int flag = 0;
	while(five_special_vertical_possible_one(arr,score) == true)
		flag = 1;
	while (five_special_vertical_possible_two(arr, score) == true)
		flag = 1;
	while (five_special_vertical_possible_three(arr, score) == true)
		flag = 1;
	while (five_special_horizontal_possible_one(arr, score) == true)
		flag = 1;
	while (five_special_horizontal_possible_two(arr, score) == true)
		flag = 1;
	while (five_special_horizontal_possible_three(arr, score) == true)
		flag = 1;
	while (four_special_vertical_possible_one(arr, score) == true)
		flag = 1;
	while (four_special_vertical_possible_two(arr, score) == true)
		flag = 1;
	while (four_special_vertical_possible_three(arr, score) == true)
		flag = 1;
	while (four_special_horizontal_possible_one(arr, score) == true)
		flag = 1;
	while (four_special_horizontal_possible_two(arr, score) == true)
		flag = 1;
	while (four_special_horizontal_possible_three(arr, score) == true)
		flag = 1;
	while(L_possible_one(arr, score) == true)
		flag = 1;
	while(L_possible_two(arr, score) == true)
		flag = 1;
	while (L_possible_three(arr, score) == true)
		flag = 1;
	while (L_possible_four(arr, score) == true)
		flag = 1;
	while (four_vertical_possible(arr, score) == true)
		flag = 1;
	while(four_horizontal_possible(arr, score) == true)
		flag = 1;
	while (vertical_possible(arr, score) == true)
		flag = 1;
	while(horizontal_possible(arr, score) == true)
		flag = 1;
	return flag;
}

// below two are for the marker
void cursor_b(int x1, int x2, int y1, int y2, int ln) //7)line 93 to 157 are working and used just for moving the marker
{
	myLine(5 + x1 * ln, 5 + y1 * ln, 5 + x2 * ln, 20 + y2 * ln, 0);
	myLine(5 + x1 * ln, 30 + y1 * ln, 5 + x2 * ln, 45 + y2 * ln, 0);
	myLine(45 + x1 * ln, 5 + y1 * ln, 45 + x2 * ln, 20 + y2 * ln, 0);
	myLine(45 + x1 * ln, 30 + y1 * ln, 45 + x2 * ln, 45 + y2 * ln, 0);
	myLine(5 + x1 * ln, 5 + y1 * ln, 20 + x2 * ln, 5 + y2 * ln, 0);
	myLine(30 + x1 * ln, 5 + y1 * ln, 45 + x2 * ln, 5 + y2 * ln, 0);
	myLine(5 + x1 * ln, 45 + y1 * ln, 20 + x2 * ln, 45 + y2 * ln, 0);
	myLine(30 + x1 * ln, 45 + y1 * ln, 45 + x2 * ln, 45 + y2 * ln, 0);
}

void cursor_w(int x1, int x2, int y1, int y2, int ln)
{
	myLine(5 + x1 * ln, 5 + y1 * ln, 5 + x2 * ln, 20 + y2 * ln, 255);
	myLine(5 + x1 * ln, 30 + y1 * ln, 5 + x2 * ln, 45 + y2 * ln, 255);
	myLine(45 + x1 * ln, 5 + y1 * ln, 45 + x2 * ln, 20 + y2 * ln, 255);
	myLine(45 + x1 * ln, 30 + y1 * ln, 45 + x2 * ln, 45 + y2 * ln, 255);
	myLine(5 + x1 * ln, 5 + y1 * ln, 20 + x2 * ln, 5 + y2 * ln, 255);
	myLine(30 + x1 * ln, 5 + y1 * ln, 45 + x2 * ln, 5 + y2 * ln, 255);
	myLine(5 + x1 * ln, 45 + y1 * ln, 20 + x2 * ln, 45 + y2 * ln, 255);
	myLine(30 + x1 * ln, 45 + y1 * ln, 45 + x2 * ln, 45 + y2 * ln, 255);
}

//to move the marker and swap
void marker(int& x1, int& x2, int& y1, int& y2, int arr[][8],int& score_marker)
{
	int ln = 50;
	int whichkey;
	if (isCursorKeyPressed(whichkey) == true)
	{
		if (whichkey == 1 && x1 > 0)
		{
			cursor_b(x1, x2, y1, y2, ln);
			x1 = x1--;
			x2 = x2--;
			myRect(0, 0, 400, 400, 0, 0, 0, 0, 0, 0);
			printboard(arr, 8);
			cursor_w(x1, x2, y1, y2, ln);
		}
		else if (whichkey == 2 && y1 > 0)
		{
			cursor_b(x1, x2, y1, y2, ln);
			y1 = y1--;
			y2 = y2--;
			myRect(0, 0, 400, 400, 0, 0, 0, 0, 0, 0);
			printboard(arr, 8);
			cursor_w(x1, x2, y1, y2, ln);
		}
		else if (whichkey == 3 && x1 < 7)
		{
			cursor_b(x1, x2, y1, y2, ln);
			x1 = x1++;
			x2 = x2++;
			myRect(0, 0, 400, 400, 0, 0, 0, 0, 0, 0);
			printboard(arr, 8);
			cursor_w(x1, x2, y1, y2, ln);
		}
		else if (whichkey == 4 && y1 < 7)
		{
			cursor_b(x1, x2, y1, y2, ln);
			y1 = y1++;
			y2 = y2++;
			myRect(0, 0, 400, 400, 0, 0, 0, 0, 0, 0);
			printboard(arr, 8);
			cursor_w(x1, x2, y1, y2, ln);
		}
		if (whichkey == 5 && x1 > 0)
		{
			cursor_b(x1, x2, y1, y2, ln);
			swap(arr[y1][x1], arr[y1][x1 - 1]);
			if (possible(arr,score_marker) == true)
			{
				myRect(0, 0, 400, 400, 0, 0, 0, 0, 0, 0);
				printboard(arr, 8);
				x1 = x1--;
				x2 = x2--;
				cursor_w(x1, x2, y1, y2, ln);
			}
			else
			{
				swap(arr[y1][x1], arr[y1][x1 - 1]);
				cursor_w(x1, x2, y1, y2, ln);
			}
		}
		else if (whichkey == 6 && y1 > 0)
		{
			cursor_b(x1, x2, y1, y2, ln);
			swap(arr[y1][x1], arr[y1 - 1][x1]);
			if (possible(arr, score_marker) == true)
			{
				myRect(0, 0, 400, 400, 0, 0, 0, 0, 0, 0);
				printboard(arr, 8);
				y1 = y1--;
				y2 = y2--;
			}
			else
			{
				swap(arr[y1][x1], arr[y1 - 1][x1]);
				cursor_w(x1, x2, y1, y2, ln);
			}
		}
		else if (whichkey == 7 && x1 < 7)
		{
			cursor_b(x1, x2, y1, y2, ln);
			swap(arr[y1][x1], arr[y1][x1 + 1]);
			if (possible(arr, score_marker) == true)
			{
				myRect(0, 0, 400, 400, 0, 0, 0, 0, 0, 0);
				printboard(arr, 8);
				x1 = x1++;
				x2 = x2++;
				cursor_w(x1, x2, y1, y2, ln);
			}
			else
			{
				swap(arr[y1][x1], arr[y1][x1 + 1]);
				cursor_w(x1, x2, y1, y2, ln);
			}
		}
		else if (whichkey == 8 && y1 < 7)
		{
			cursor_b(x1, x2, y1, y2, ln);
			swap(arr[y1][x1], arr[y1 + 1][x1]);
			if (possible(arr, score_marker) == true)
			{
				myRect(0, 0, 400, 400, 0, 0, 0, 0, 0, 0);
				printboard(arr, 8);
				y1 = y1++;
				y2 = y2++;
				cursor_w(x1, x2, y1, y2, ln);
			}
			else
			{
				swap(arr[y1][x1], arr[y1 + 1][x1]);
				cursor_w(x1, x2, y1, y2, ln);
			}
		}
	}
}

//this prints the board with the changed/current value in 2d arr
void printboard(int arr[][8], int row)
{
	for (int i = 0; i <= 400; i = i + 50)// 3)loop for a grid
	{
		myLine(0, 0 + i, 400, 0 + i, 255);
		myLine(0 + i, 0, 0 + i, 400, 255);
	}

	for (int i = 0; i < row; i++) //4) shapes for each specified number
	{
		for (int j = 0; j < 8; j++)
		{
			if (arr[i][j] == 1)
			{
				myEllipse(10 + j * 50, 10 + i * 50, 40 + j * 50, 40 + i * 50, 255, 0, 0, 0, 255, 255); //5) rgb colors then rgb for background
				myEllipse(15 + j * 50, 15 + i * 50, 35 + j * 50, 35 + i * 50, 255, 0, 0, 0, 0, 0);
			}
			else if (arr[i][j] == 2)
			{
				myEllipse(10 + j * 50, 10 + i * 50, 40 + j * 50, 40 + i * 50, 255, 255, 255, 153, 0, 0);
			}
			else if (arr[i][j] == 3)
			{
				myRect(10 + j * 50, 10 + i * 50, 40 + j * 50, 40 + i * 50, 204, 0, 204, 76, 0, 153);
			}
			else if (arr[i][j] == 4)
			{
				myRect(20 + j * 50, 10 + i * 50, 30 + j * 50, 40 + i * 50, 255, 255, 255, 22, 255, 0);
				myEllipse(10 + j * 50, 20 + i * 50, 40 + j * 50, 40 + i * 50, 255, 255, 255, 255, 128, 0);
			}
			else if (arr[i][j] == 5)
			{
				myEllipse(10 + j * 50, 10 + i * 50, 40 + j * 50, 40 + i * 50, 255, 0, 0, 0, 255, 255);
				myRect(10 + j * 50, 20 + i * 50, 40 + j * 50, 35 + i * 50, 204, 0, 204, 255, 255, 0);
			}
			else if (arr[i][j] == 6)
			{
				myEllipse(10 + j * 50, 10 + i * 50, 40 + j * 50, 40 + i * 50, 255, 0, 0, 255, 0, 0); //5) rgb colors then rgb for background
				myEllipse(15 + j * 50, 15 + i * 50, 35 + j * 50, 35 + i * 50, 255, 0, 0, 0, 0, 0);
			}
			else if (arr[i][j] == 7)
			{
				myEllipse(10 + j * 50, 10 + i * 50, 40 + j * 50, 40 + i * 50, 255, 0, 0, 255, 0, 0);
			}
			else if (arr[i][j] == 8)
			{
				myRect(10 + j * 50, 10 + i * 50, 40 + j * 50, 40 + i * 50, 255, 0, 0, 255, 0, 0);
			}
			else if (arr[i][j] == 9)
			{
				myRect(20 + j * 50, 10 + i * 50, 30 + j * 50, 40 + i * 50, 255, 0, 0, 255, 0, 0);
				myEllipse(10 + j * 50, 20 + i * 50, 40 + j * 50, 40 + i * 50, 255, 0, 0, 255, 0, 0);
			}
			else if (arr[i][j] == 10)
			{
				myEllipse(10 + j * 50, 10 + i * 50, 40 + j * 50, 40 + i * 50, 255, 0, 0, 255, 0, 0);
				myRect(10 + j * 50, 20 + i * 50, 40 + j * 50, 35 + i * 50, 255, 0, 0, 255, 0, 0);
			}
			if (arr[i][j] == 11)
			{
				myEllipse(10 + j * 50, 10 + i * 50, 40 + j * 50, 40 + i * 50, 0, 0, 255, 0, 0, 255); //5) rgb colors then rgb for background
				myEllipse(15 + j * 50, 15 + i * 50, 35 + j * 50, 35 + i * 50, 0, 0, 255, 0, 0, 0);
			}
			else if (arr[i][j] == 12)
			{
				myEllipse(10 + j * 50, 10 + i * 50, 40 + j * 50, 40 + i * 50, 0, 0, 255, 0, 0, 255);
			}
			else if (arr[i][j] == 13)
			{
				myRect(10 + j * 50, 10 + i * 50, 40 + j * 50, 40 + i * 50, 0, 0, 255, 0, 0, 255);
			}
			else if (arr[i][j] == 14)
			{
				myRect(20 + j * 50, 10 + i * 50, 30 + j * 50, 40 + i * 50, 0, 0, 255, 0, 0, 255);
				myEllipse(10 + j * 50, 20 + i * 50, 40 + j * 50, 40 + i * 50, 0, 0, 255, 0, 0, 255);
			}
			else if (arr[i][j] == 15)
			{
				myEllipse(10 + j * 50, 10 + i * 50, 40 + j * 50, 40 + i * 50, 0, 0, 255, 0, 0, 255);
				myRect(10 + j * 50, 20 + i * 50, 40 + j * 50, 35 + i * 50, 0, 0, 255, 0, 0, 255);
			}
		}
	}
}

// here all the 60 seconds game occurs.
//1.score is added from both the marker and the possible
void countdown(int arr[][8]) {
	int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
	int score_total=0;
	int score_marker;
	int score_possible;
	score();
	
	myRect(5, 420, 400, 460, 255, 0, 0, 0, 0, 0); //outer rect

	for (int i = 15; i <= 395; i++) 
	{
		score_marker = 0;
		score_possible = 0;
		myRect(10, 425, i, 455, 255, 255, 0, 255, 255, 0); // inner rect yellow
		marker(x1, x2, y1, y2, arr,score_marker); //6) for moving marker continuously

		while (possible(arr, score_possible) == true)
		{
			myRect(0, 0, 400, 400, 0, 0, 0, 0, 0, 0);
			printboard(arr, 8);
		}

		score_total = score_total + score_possible + score_marker;
		score_print(score_total);

		Sleep(155);//155*380=60000~ for the game to run for 60000ms
	}
}

int main()
{
	srand(time(0));
	int arr[8][8];

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			arr[i][j] = (rand() % 5) + 1;
		}
	}
//randomize to remove possible in start
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (arr[i][j + 1] == arr[i][j])
			{
				while (arr[i][j + 2] == arr[i][j])
				{
					arr[i][j + 2] = (rand() % 5) + 1;
				}
			}
		}
	}
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (arr[i + 1][j] == arr[i][j])
			{
				while (arr[i + 2][j] == arr[i][j])
				{
					arr[i + 2][j] = (rand() % 5) + 1;
				}
			}
		}
	}
	printboard(arr, 8); // 2) go to function prints board with different shapes for each number of 1-5
	countdown(arr);

	Sleep(10000);
	return 0;
}