
#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node* prev;
	struct node* next;

	int data;
} *first, *last;

int pop()
{
	int tmp;
	if (first == NULL)
	{
		return -1;
	}
	else if (first == last)
	{
		tmp = first->data;
		free(first);
		first = last = NULL;
	}
	else
	{
		tmp = last->data;
		free(last);
		last = last->prev;
	}
	return tmp;
}

void push(int data)
{
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = data;
	newnode->prev = NULL;

	if (first == NULL)
	{
		first = last = newnode;
		first->next = last;
		first->prev = NULL;
		last->next = NULL;
		last->prev = first;
	}
	else
	{
		newnode->next = first;
		first->prev = newnode;
		first = newnode;
	}

}

/*
int main()
{
	push(1);
	push(2);
	push(3);
	printf("%d\n", pop());

	push(4);
	push(5);
	push(6);
	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());
}
*/