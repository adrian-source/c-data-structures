
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
There is a sorted array of infinite numbers (can contain duplicates). 
Given a number. Find the last occurring instance of that number 
in the array.
*/
int find_last(int* a, int size, int num)
{
	
	int pos = 0;
	int power = 1;
	while(pos <= size)
	{
		// check if we found the number
		if (a[pos] == num)
			break;

		// check if we passed the number
		if (a[pos] > num)
		{
			pos = pow(2, power-1);
			break;
		}

		// if we're not there yet, make a step
		power++;
		pos = pow(2, power);
	}

	// now, where did we leave off...

	// if we didn't find the number yet, 
	// do a little binary search
	if (a[pos] != num || pos > size)
	{
		int l, r;
		if (pos > size)
		{
			l = pow(2, power-1);
			r = size;
		}
		else
		{
			l = pos;
			r = pow(2, power);
			if (r > size)
				r = size;
		}

		int mid = l + (r - l)/2;

		// lets loop until we find the number
		while (1)
		{
			mid = l + (r - l)/2;

			// take care of corner cases
			if (a[l] == num)
			{
				pos = l;
				break;
			}
			else if (a[r] == num)
			{
				pos = r;
				break;
			}
			else if (a[mid] == num)
			{
				pos = mid;
				break;
			}

			// too far?
			if (num > a[mid])
				l = mid;
			// not far enough?
			else if (num < a[mid])
				r = mid;

			// i guess we didn't find what we came for...
			if (l+1 == r && a[l] != num && a[r] != num)
				return -1;
		}

	}

	// by now we should have found our number, 
	// lets find the last occurence
	while (a[pos+1] == num && pos <= size)
		pos++;

	return pos;

}

int main()
{
	int array[] = {0, 1, 1, 2, 3, 4, 4, 5, 6, 7, 8};
	int size = (int)(sizeof(array)/sizeof(int));

	int location = find_last(array, size-1, 4);
	printf("location: %d\n", location);
}