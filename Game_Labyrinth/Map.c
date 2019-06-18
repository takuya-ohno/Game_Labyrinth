/*=============================================================================
  Author
	Ohno Takuya

  Create
	2017/6/10
=============================================================================*/
/*-----------------------------------------------------------------------------
	Include
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include "Map.h"

/*-----------------------------------------------------------------------------
	Macro
-----------------------------------------------------------------------------*/
#define MAP_WIDTH (50)
#define MAP_HEIGHT (23)

/*-----------------------------------------------------------------------------
	Global
-----------------------------------------------------------------------------*/
char g_MAPdata[MAP_HEIGHT][MAP_WIDTH] = {
		"||G--------------------------------------------**",
		"||                                             ||",
		"|| * * * * * * * * * * * * * * * * * * * * * * ||",
		"||                                             ||",
		"|| * * * * * * * * * * * * * * * * * * * * * * ||",
		"||                                             ||",
		"|| * * * * * * * * * * * * * * * * * * * * * * ||",
		"||                                             ||",
		"|| * * * * * * * * * * * * * * * * * * * * * * ||",
		"||                                             ||",
		"|| * * * * * * * * * * * * * * * * * * * * * * ||",
		"||                                             ||",
		"|| * * * * * * * * * * * * * * * * * * * * * * ||",
		"||                                             ||",
		"|| * * * * * * * * * * * * * * * * * * * * * * ||",
		"||                                             ||",
		"|| * * * * * * * * * * * * * * * * * * * * * * ||",
		"||                                             ||",
		"|| * * * * * * * * * * * * * * * * * * * * * * ||",
		"||                                             ||",
		"|| * * * * * * * * * * * * * * * * * * * * * * ||",
		"||                                             ||",
		"**---------------------------------------------**" };


void InitializeMap(void)
{
	srand((unsigned)time(NULL));// ���ݎ�����������ɃV�[�h�l�𐶐�

	int _x, _z;
	int _random;

	/*�㉺���E�ɕǂ��o��*/
	for (_z = 2;_z < 21;_z += 2)
	{
		for (_x = 3;_x < 46;_x += 2)
		{
			_random = rand() % 4;

			switch (_random)
			{
			case 0:/*Left*/
				g_MAPdata[_z][_x - 1] = '*';
				break;

			case 1:/*Right*/
				g_MAPdata[_z][_x + 1] = '*';
				break;

			case 2:/*Up*/
				g_MAPdata[_z - 1][_x] = '*';
				break;

			case 3:/*Down*/
				g_MAPdata[_z + 1][_x] = '*';
				break;
			}
		}
	}
}

void DrawMap(void)
{
	int _y;

	for (_y = 0;_y < MAP_HEIGHT;_y++)
	{
		printf("%s", &g_MAPdata[_y][0]);
		printf("\n");
	}
}

char GetMap(int x, int y)
{
	return g_MAPdata[y][x];
}

void SetMap(int x, int y, char icon)
{
	g_MAPdata[y][x] = icon;
}