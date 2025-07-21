#include<iostream>
#include "help.h"


using namespace std;

int main()
{
	int x1 = 0,y1=0,x2=100,y2=100;
	int key,whichKey;

	myRect(x1, y1, x2, y2, 255, 255, 255);

	
	while (1)
	{
		key = isCursorKeyPressed(whichKey);
		if (key == 1)
		{
			if (whichKey == 1)
			{
				myRect(x1, y1, x2, y2, 0, 0, 0);
				x1 -= 30;
				x2 -= 30;
				myRect(x1, y1, x2, y2, 255, 255, 255);
			}
			if (whichKey == 2)
			{
				myRect(x1, y1, x2, y2, 0, 0, 0);
				y1 -= 30;
				y2 -= 30;
				myRect(x1, y1, x2, y2, 255, 255, 255);
			}
			if (whichKey == 3)
			{
				myRect(x1, y1, x2, y2, 0, 0, 0);
				x1 += 30;
				x2 += 30;
				myRect(x1, y1, x2, y2, 255, 255, 255);
			}
			if (whichKey == 4)
			{
				myRect(x1, y1, x2, y2, 0, 0, 0);
				y1 += 30;
				y2 += 30;
				myRect(x1, y1, x2, y2, 255, 255, 255);
			}
		}
	}
	return 0;
}