#include "Global.h"

extern const Point node[TOTAL_NODE] = { Point(450, 450),
								Point(450, 810), Point(810, 450), Point(450, 90), Point(90, 450),
								Point(630, 630), Point(630, 270), Point(270, 270), Point(270, 630),
								Point(450, 630), Point(630, 450), Point(450, 270), Point(270, 450),
								Point(540, 540), Point(540, 360), Point(360, 360), Point(360, 540),
							  };

//                                                  0   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16
extern const int dis[TOTAL_NODE][TOTAL_NODE] = {
													0,  NC, NC, NC, NC, NC, NC, NC, NC, D2, D2, D2, D2, D1, D1, D1, D1,//0
													NC, 0,  NC, NC, NC, D3, NC, NC, D3, D2, NC, NC, NC, NC, NC, NC, NC,//1
													NC, NC, 0,  NC, NC, D3, D3, NC, NC, NC, D2, NC, NC, NC, NC, NC, NC,//2
													NC, NC, NC, 0,  NC, NC, D3, D3, NC, NC, NC, D2, NC, NC, NC, NC, NC,//3
													NC, NC, NC, NC, 0,  NC, NC, D3, D3, NC, NC, NC, D2, NC, NC, NC, NC,//4
													NC, D3, D3, NC, NC, 0,  NC, NC, NC, D2, D2, NC, NC, D1, NC, NC, NC,//5
													NC, NC, D3, D3, NC, NC, 0,  NC, NC, NC, D2, D2, NC, NC, D1, NC, NC,//6
													NC, NC, NC, D3, D3, NC, NC, 0,  NC, NC, NC, D2, D2, NC, NC, D1, NC,//7
													NC, D3, NC, NC, D3, NC, NC, NC, 0 , D2, NC, NC, D2, NC, NC, NC, D1,//8
													D2, D2, NC, NC, NC, D2, NC, NC, D2, 0,  NC, NC, NC, D1, NC, NC, D1,//9
													D2, NC, D2, NC, NC, D2, D2, NC, NC, NC, 0,  NC, NC, D1, D1, NC, NC,//10
													D2, NC, NC, D2, NC, NC, D2, D2, NC, NC, NC, 0,  NC, NC, D1, D1, NC,//11
													D2, NC, NC, NC, D2, NC, NC, D2, D2, NC, NC, NC, 0,  NC, NC, D1, D1,//12
													D1, NC, NC, NC, NC, D1, NC, NC, NC, D1, D1, NC, NC, 0,  NC, NC, NC,//13
													D1, NC, NC, NC, NC, NC, D1, NC, NC, NC, D1, D1, NC, NC, 0,  NC, NC,//14
													D1, NC, NC, NC, NC, NC, NC, D1, NC, NC, NC, D1, D1, NC, NC, 0,  NC,//15
													D1, NC, NC, NC, NC, NC, NC, NC, D1, D1, NC, NC, D1, NC, NC, NC, 0, //16
};

int randNum(int size, int probability[])
{
	int sum = 0;
	for (int i = 0; i < size; ++i)
	{
		sum += probability[i];
	}
	float r = rand_0_1()*sum;

	sum = 0;
	for (int i = 0; i < size; ++i)
	{
		sum += probability[i];
		if (r < sum)
		{
			return i;
		}
	}
	return -1;
}