
#include <stdlib.h>
#include <stdio.h>

int min(int x, int y)
{
	if (x < y)
		return x;
	else
		return y;
}

void print(int *array, int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf(" %d", array[i]);
	printf("\n");
}

void merge_split(int* array, int start, int end, int* buffer)
{
	printf("a ");
	print(&array[start], end-start);

	if (end - start == 1)
	{
		// left with only one element
		return;
	}
	else
	{
		// left with more than one lement, split
		int length = end - start;
		int middle = length / 2;

		// send new parts for another mergesplit
		merge_split(array, start, start+middle, buffer);
		merge_split(array, start+middle, end, buffer);

		// create pointers to use during merge
		int l = start;
		int r = start + middle;
		int i;

		// merge the arrays
		for (i = 0; i < length; i++)
		{
			//printf("l %d, r %d, start %d, middle %d, end %d, length %d\n", l, r, start, middle, end, length );
			
			// if left is empty, right is not
			if (l == start+middle && r < end)
			{
				buffer[i] = array[r];
				r++;
			}
			// if left is not empty, right is
			else if (l < start+middle && r == end)
			{
				buffer[i] = array[l];
				l++;
			}
			// otherwise, compare
			else
			{
				if (min(array[l], array[r]) == array[l])
				{
					buffer[i] = array[l];
					l++;
				}
				else
				{
					buffer[i] = array[r];
					r++;
				}
			}
		}
		printf("b ");
		print(buffer, 10);

		for (i = start; i < end; i++)
			array[i] = buffer[i-start];
	}

}

int merge_sort(int* sortme, int size)
{
	int* buffer = (int*)malloc(size * sizeof(int));
	if (sortme == NULL)
	{
		return 0;
	}
	else
	{
		merge_split(sortme, 0, size, buffer);
		free(buffer);
		return 1;
	}

}






int main()
{
	int size = 10;
	int* sortme = (int*)malloc(size * sizeof(int));

	sortme[0] = 15;
	sortme[1] = 10;
	sortme[2] = 21;
	sortme[3] = 0;
	sortme[4] = -10;
	sortme[5] = 5;
	sortme[6] = 6;
	sortme[7] = 100;
	sortme[8] = 1;
	sortme[9] = 78;

	print(sortme, size);

	int isComplete = merge_sort(sortme, size);

	print(sortme, size);

}

// leveraged from:
// http://www.cprogramming.com/tutorial/computersciencetheory/merge.html