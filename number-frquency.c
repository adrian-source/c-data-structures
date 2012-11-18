
#import <stdlib.h>
#import <stdio.h>

struct node{
	struct node* next;
	struct node* prev;

	int num;
	int f;
}*first, *last;


////
// Given a set of numbers, store them so that you can answer questions
// about each number's frequency: 
// What number ahs average frequency?
// What number has 2nd highest frequency?
//
// Implementation using a linked list that is ordered based on the frequency,
// where most frequent numers are at the end.
////



void init_node(struct node** n)
{
	*n = (struct node*)malloc(sizeof(struct node));
	(*n)->next = NULL;
	(*n)->prev = NULL;
	(*n)->num = 0;
	(*n)->f = 0;
}

struct node* find(int i)
{
	struct node *s;
	s = first;
	while (s != NULL)
	{
		if (s->num == i)
			return s;
		s = s->next;
	}
	return NULL;
}

// insetrs number
// if it already exists, increment the frequency counter and reorder the nodes based on frequency
// if it doesnt exist, add it at the end
void insert(int i)
{
	printf("inserting %d...\n", i);
	if (first == NULL)
	{
		struct node* n;
		init_node(&n);
		n->num = i;
		n->f = 1;
		first = last = n;
	}
	else
	{
		struct node* s = find(i);
		if (s != NULL)
		{
			s->f++;
			while (s->prev != NULL && s->prev->f < s->f)
			{
				int num = s->num, f = s->f;
				s->num = s->prev->num;
				s->f = s->prev->f;
				s->prev->num = num;
				s->prev->f = f;

				s = s->prev;
			}
		}
		else
		{
			init_node(&s);
			s->num = i;
			s->f = 1;
			s->prev = last;
			last->next = s;
			last = s;

		}
	}
}

struct node* find_average()
{
	int count = 0, sum = 0;
	struct node* n = first;

	while (n != NULL)
	{
		count++;
		sum += n->f;
		n = n->next;
	}
	int average = sum/count;
	printf("average %d\n", average);

	n = first;
	while (n != NULL)
	{
		if (n->f == average)
			printf("num: %7d %7d times\n", n->num, n->f);

		n = n->next;
	}
}

int main()
{

	first = last = NULL;

	int i;
	for (i = 0; i < 100000; i++)
		insert(rand()%10000);

	struct node* n = first;
	for (i = 0; i < 10; i++)
	{
		printf("%2d. %7d %7d times\n", i+1, n->num, n->f);
		n = n->next;
	}

	find_average();

}