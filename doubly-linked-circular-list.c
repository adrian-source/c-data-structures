#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node* prev;
	struct node* next;
	int data;
};

struct node* last;

void add(int data)
{
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = data;
	
	if (last == NULL)
	// no elements present
	{
		newnode->next = newnode;
		newnode->prev = newnode;
		last = newnode;
	}
	else if (last->next == last)
	// one element present
	{
		last->next = newnode;
		last->prev = newnode;
		newnode->prev = last;
		newnode->next = last;
		
		if (last->data < newnode->data)
			last = newnode;
	}
	// more than one element present
	else
	{
		struct node* curr = last->next;
		while(curr != NULL)
		{
			if (curr == last->next && data < curr->data)
			// newnode needs to be places before first element
			{
				last->next = newnode;
				newnode->prev = last;
				curr->prev = newnode;
				newnode->next = curr;
				break;
			}
			else if (curr == last && curr->data < data)
			// newnode needs to be placed after the last element
			{
				last->next->prev = newnode;
				newnode->next = last->next;
				newnode->prev = last;
				last->next = newnode;
				last = newnode;	
				break;
			}
			else if (curr->data < data && data < curr->next->data)
			{
				newnode->next = curr->next;
				newnode->next->prev = newnode;
				newnode->prev = curr;
				curr->next = newnode;				
				break;
			}
			else if (curr->data == data)
			{
				return; // element already exists
			}

			curr = curr->next;
	
		}
	}
	
}

void print()
{
	if (last == NULL)
		printf("empty dlst");
	else
	{
		struct node* curr = last->next;
		while (curr != NULL)
		{
			printf("%d ", curr->data);
			if (curr == last)
			{
				printf("\n");
				break;
			}
			else
				curr = curr->next;
		}

	}
}

int main()
{
	last = NULL;

	add(3);
	print();
	add(5);
	print();
	add(4);
	print();
	add(4);  // adding in the middle
	print();
	add(1);	 // adding in the front
	print(); 
	add(10);
	print(); // adding at the end 
}

