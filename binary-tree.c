
#include <stdio.h>
#include <stdlib.h>

struct node{
	struct node* lower;
	struct node* higher;

	int key;
};

int height(struct node* tree)
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

int factor(struct node* tree)
{
	int l = height(tree->lower);
	int r = height(tree->higher);
	return l - r;
}

void insert (int key, struct node** tree)
{

	if (*tree == 0)
	{
		printf("i inserting... %d\n", key);
		*tree = (struct node*)malloc(sizeof(struct node));
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


void print (struct node** tree)
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


struct node** find_largest(struct node** tree)
{
	if ((*tree)->higher != 0)
		return find_largest(&(*tree)->higher);
	else
		return tree;
}

void delete(int key, struct node** tree)
{
	if (*tree != 0)
	{
		if (key == (*tree)->key)
		{
			printf("d found it!\n");
			if ((*tree)->lower != 0 && (*tree)->higher != 0)
			{
				printf("d has two children...\n");
				struct node** replacement = find_largest(&(*tree)->lower);
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





int main()
{
	struct node* tree;
	tree->key = 50;
	tree->lower = 0;
	tree->higher = 0;

	insert(40, &tree);
	insert(45, &tree);
	insert(30, &tree);
	insert(35, &tree);
	insert(60, &tree);


	print(&tree);

	/*
	tree->key = 50;
	tree->lower = 0;
	tree->higher = 0;

	insert(2, &tree);
	insert(10, &tree);
	insert(100, &tree);
	insert(51, &tree);
	insert(49, &tree);
	insert(0, &tree);

	delete(50, &tree);

	printf("height... %d\n", height(tree));

	printf("printing...\n");

	print(&tree);
	*/
}