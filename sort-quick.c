
#include <stdlib.h>
#include <stdio.h> 

void print(int *array, int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf(" %d", array[i]);
	printf("\n");
}

void swap(int* x, int* y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
	printf("swap %d and %d\n", *x, *y);
}

int quick_sort(int* data, int left, int right) 
{ 
	int i, l, r, pivot, pivotval;

	if (left < right)
	{
		printf("left %d right %d\n", left, right);
		// find midpoint
		pivot = (right+left)/2;
		pivotval = data[pivot];

		// put the pivot to the side...
		swap(&data[left], &data[pivot]);

		// set up pointers for sorting
		l = left+1;
		r = right;

		// swap elements to the correct side of the pivot
		while (l <= r)
		{
			while (l <= right && data[l] <= pivotval)
				l++;
			while (r >= left && data[r] > pivotval)
				r--;
			if (l < r)
			{
				swap(&data[l], &data[r]);
			}
		}

		// reposition the pivot
		swap(&data[left], &data[r]);

		print(data, 10);

		quick_sort(data, left, r-1);
		quick_sort(data, r+1, right);
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

	quick_sort(sortme, 0, size-1);

	print(sortme, 10);

}

