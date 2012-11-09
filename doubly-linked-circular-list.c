
#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node* prev;
	struct node* next;
	int data;
}*last;

add(int data)
{
	printf("adding %d...\n", data);

	struct node* tmp;
	struct node* curr;
	tmp = (struct node*)malloc(sizeof(struct node));
	tmp->data = data;

	if (last == NULL)
	{
		last = tmp;
		last->data = data;
		last->next = last;
		last->prev = last;
	}
	else
	{
		// there is onle one element
		if (last->next == last)
		{

			last->next = tmp;
			last->prev = tmp;
			tmp->next = last;
			tmp->prev = last;

			if (last->data < tmp->data)
				last = tmp;
			
		}
		else
		{
			curr = last->next;
			while(curr != NULL)
			{
				if (tmp->data > curr->data && tmp->data < curr->next->data)
				{
					tmp->next = curr->next;
					curr->next->prev = tmp;
					tmp->prev = curr;
					curr->next = tmp;
					break;
				}
				else if (curr->data < tmp->data)
				{
					curr = curr->next;
				}
			}

		}

	}
}

void print()
{
	if (last->next == last)
	{
		printf("one item %d\n", last->data);
	}
	else
	{
		struct node* curr;
		curr = last->next;
		while (curr != NULL)
		{
			printf("%d\n", curr->data);
			curr = curr->next;
			if (curr == last)
			{
				printf("%d last \n", curr->data);
				break;
			}
		}
	}
}

int main()
{
	last = NULL;
	add(3);
	add(5);
	add(4);
	add(100);
	add(1);

	print();
}