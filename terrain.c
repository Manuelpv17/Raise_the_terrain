#include "grid.h"

/**
 * terrain_func - data of the terrain
 * @copy: matrix to pass the info of the terrain
 */
void terrain_func(int (*copy)[8][8])
{
	int i, j;
	int terrain[8][8] = {
		120,
		60,
		40,
		60,
		20,
		-20,
		-80,
		-120,
		40,
		20,
		30,
		30,
		-10,
		-40,
		-90,
		-110,
		20,
		30,
		10,
		06,
		-6,
		-20,
		-26,
		-90,
		00,
		-6,
		10,
		10,
		-6,
		-20,
		-20,
		-40,
		-20,
		-20,
		-18,
		-14,
		-40,
		-20,
		-20,
		-30,
		-10,
		-10,
		-10,
		-10,
		-8,
		-20,
		-20,
		-30,
		20,
		10,
		10,
		10,
		10,
		04,
		10,
		-10,
		30,
		24,
		24,
		22,
		20,
		18,
		14,
		16,
	};

	for (i = 0; i < 8; i++)
		for (j = 0; j < 8; j++)
			(*copy)[i][j] = terrain[i][j];
}