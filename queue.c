#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node* prev;
	struct node* next;

	int data;
} *front, *back;

int pop()
{

	int temp;
	if (front == NULL)
	{
		return -1;
	}
	else if (front == back)
	{
		temp = front->data;
		front = back = NULL;
	}
	else
	{
		temp = front->data;
		front = front->prev;
		free(front->next);
		front->next = NULL;
	}
	return temp;
}

void push(int data)
{
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = data;

	if (front == NULL)
	{
		front = back = newnode;
		back->prev = front;
	}
	else
	{
		back->prev = newnode;
		newnode->next = back;
		back = newnode;
	}
}


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
