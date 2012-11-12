#include <stdlib.h>
#include <stdio.h>


struct btnode{
	struct btnode* lower;
	struct btnode* higher;

	int key;
};

struct qnode{
	struct qnode* prev;
	struct qnode* next;

	struct btnode data;
} *first, *last;


int height(struct btnode* tree)
{
	if (tree == 0)
		return 0;
	else
	{
		int lower = 1 + height(tree->lower);
		int higher = 1 + height(tree->higher);
		return (lower > higher) ? lower : higher;
	}
}

int factor(struct btnode* tree)
{
	int l = height(tree->lower);
	int r = height(tree->higher);
	return l - r;
}

void insert (int key, struct btnode** tree)
{

	if (*tree == 0)
	{
		printf("i inserting... %d\n", key);
		*tree = (struct btnode*)malloc(sizeof(struct btnode));
		(*tree)->key = key;
		(*tree)->lower = 0;
		(*tree)->higher = 0;
	}
	else if (key < (*tree)->key)
	{
		printf("i lower...\n");
		insert(key, &(*tree)->lower);
	}
	else if (key > (*tree)->key)
	{
		printf("i higher...\n");
		insert(key, &(*tree)->higher);
	}
}


void print (struct btnode** tree)
{
	
	if ((*tree)->lower != 0)
	{
		printf("/\n");
		print(&(*tree)->lower);
	}
	printf("%d \n", (*tree)->key);

	if ((*tree)->higher != 0)
	{	
		printf("\\\n");
		print(&(*tree)->higher);
	}
}


struct btnode** find_largest(struct btnode** tree)
{
	if ((*tree)->higher != 0)
		return find_largest(&(*tree)->higher);
	else
		return tree;
}

void delete(int key, struct btnode** tree)
{
	if (*tree != 0)
	{
		if (key == (*tree)->key)
		{
			printf("d found it!\n");
			if ((*tree)->lower != 0 && (*tree)->higher != 0)
			{
				printf("d has two children...\n");
				struct btnode** replacement = find_largest(&(*tree)->lower);
				(*tree)->key = (*replacement)->key;
				if ((*replacement)->lower != 0)
					(*replacement) = (*replacement)->lower;

				free(*replacement);
				(*replacement) = NULL;
			}
			else if ((*tree)->lower != 0 || (*tree)->higher != 0)
			{
				printf("d deleting node with one child... %d\n", (*tree)->key);
				if ((*tree)->lower != 0)
					*tree = (*tree)->lower;
				else if ((*tree)->higher != 0)
					*tree = (*tree)->higher;
			}
			else if ((*tree)->lower == 0 && (*tree)->higher == 0)
			{
				printf("d deleting leaf... %d\n", (*tree)->key);
				free(*tree);
				*tree = NULL;
			}
		}
		else if (key < (*tree)->key)
		{
			delete(key, &(*tree)->lower);
		}
		else if (key > (*tree)->key)
		{
			delete(key, &(*tree)->higher);
		}
	}
}

//----

struct btnode* pop()
{
	struct btnode* tmp;
	if (first == NULL)
	{
		return NULL;
	}
	else if (first == last)
	{
		tmp = &first->data;
		first = last = NULL;
	}
	else
	{
		tmp = &last->data;
		last = last->prev;
	}
	return tmp;
}

void push(struct btnode* data)
{
	struct qnode* newnode = (struct qnode*)malloc(sizeof(struct qnode));
	newnode->data = *data;
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

void bfs(struct btnode* tree)
{
	if (tree == NULL)
		return;
	else
	{
		push(tree);

		while(first != NULL)
		{
			struct btnode* tmp = pop();
			printf(" %d", tmp->key);
			if (tmp->lower != NULL)
				push(tmp->lower);
			if (tmp->higher != NULL)
				push(tmp->higher);
		}
		printf("\n");
	}
}

int main()
{
	struct btnode* tree;
	tree->key = 50;
	tree->lower = 0;
	tree->higher = 0;

	insert(40, &tree);
	insert(45, &tree);
	insert(30, &tree);
	insert(35, &tree);
	insert(60, &tree);

	bfs(tree);

}