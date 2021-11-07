#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"


typedef struct
{
	int x, y;
} coord;


int main(int argc, char** argv)
{
	coord coords[10];
	coord* coords1;
	linked_list llist = {0,0};

	for (int i = 0; i < 10; ++i)
	{
		coords[i].x = i;
		coords[i].y = 9 - i;
	}

	for (int i = 0; i < 10; ++i)
		llist_add(&llist, llist.length, &coords[i]);

	coords1 = llist_get_array(&llist, sizeof(coord));

	for (int i = 0; i < 10; ++i)
		printf("%d %d\n", coords1[i].x, coords1[i].y);

	free(coords1);
	llist_clear(&llist);
	return 0;
}