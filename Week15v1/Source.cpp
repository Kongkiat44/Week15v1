#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>

int stop = 0, i = 0;
double moveX[503] = {}, moveY[503] = {};
double trsX = 0, trsY = 0, distance = 0;
double* pointX = 0, * pointY = 0, * pointDistance = 0;
const double neg = -1, zero = 0, pos = 1;
const double stX = 0, stY = 0;
double finX = 0, finY = 0;

void moveDirection(int diPoint);
void finalCoordinate(double* trsX, double* trsY);
void Calculate_distance(double* distance);

int main()
{
	while (stop == 0)
	{
		if (i >= 499)
		{
			break;
		}
		char data[10] = {};
		char inpnum[6] = {};
		int stlen = 0;
		int numInp = 0;
		int diPoint = 0;
		scanf("%s", data);
		stlen = strlen(data);
		for (int k = 0; k < stlen; k++)
		{
			if (data[k] != '*')
			{
				if (isdigit(data[k]))
				{
					inpnum[numInp] = data[k];
					numInp++;
				}
				else
				{
					if (isalpha(data[k]))
					{
						if (data[k] == 'W')
						{
							diPoint = 8;
						}
						else if (data[k] == 'E')
						{
							diPoint = 4;
						}
						else if (data[k] == 'N')
						{
							if (k != stlen - 1)
							{
								if (data[k + 1] == 'W')
								{
									diPoint = 1;

								}
								else if (data[k + 1] == 'E')
								{
									diPoint = 3;
								}
								else return 0;
							}
							else
							{
								diPoint = 2;
							}
						}
						else if (data[k] == 'S')
						{
							if (k != stlen - 1)
							{
								if (data[k + 1] == 'W')
								{
									diPoint = 7;
								}
								else if (data[k + 1] == 'E')
								{
									diPoint = 5;
								}
								else return 0;
							}
							else
							{
								diPoint = 6;
							}
						}
						break; 
					}
					else return 0;
				}
			}
			else
			{
				stop = 1;
				break;
			}

		}
		if (data[0] != '*')
		{
			moveX[i] = atof(inpnum);
			moveY[i] = atof(inpnum);
			moveDirection(diPoint);
		}

		i++;
	}
	if (stop == 1)
	{
		finalCoordinate(&trsX, &trsY);
		pointX = &trsX;
		pointY = &trsY;
		finX = *pointX;
		finY = *pointY;
		Calculate_distance(&distance);
		pointDistance = &distance;
		printf("%.3f %.3f\n%.3f\n", *pointX, *pointY, *pointDistance);//final Output
	}
}

void moveDirection(int diPoint)
{
	switch (diPoint)
	{
	case 1:	moveX[i] = (moveX[i] * (neg)) / sqrt(2);
			moveY[i] = (moveY[i] * (pos)) / sqrt(2);
			break;

	case 2:	moveX[i] = moveX[i] * (zero);
			moveY[i] = moveY[i] * (pos);
			break;

	case 3:	moveX[i] = (moveX[i] * (pos)) / sqrt(2);
		moveY[i] = (moveY[i] * (pos)) / sqrt(2);
		break;

	case 4:	moveX[i] = moveX[i] * (pos);
		moveY[i] = moveY[i] * (zero);
		break;

	case 5:	moveX[i] = (moveX[i] * (pos)) / sqrt(2);
		moveY[i] = (moveY[i] * (neg)) / sqrt(2);
		break;

	case 6:	moveX[i] = moveX[i] * (zero);
		moveY[i] = moveY[i] * (neg);
		break;

	case 7:	moveX[i] = (moveX[i] * (neg)) / sqrt(2);
		moveY[i] = (moveY[i] * (neg)) / sqrt(2);
		break;

	case 8:	moveX[i] = moveX[i] * (neg);
		moveY[i] = moveY[i] * (zero);
		break;
	default:	break;
	}
}

void finalCoordinate(double*trsX, double* trsY)
{
	for (int k = 0; k < i; k++)
	{
		*trsX += moveX[k];
		*trsY += moveY[k];
	}
}
void Calculate_distance(double*distance)
{
	double num=0;
	num = pow((stX - finX), 2) + pow((stY - finY), 2);
	*distance = sqrt(num);
}