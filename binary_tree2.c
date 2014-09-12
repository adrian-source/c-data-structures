#include <stdlib.h>
#include <stdio.h>

struct node{
	int key;
	struct node* lower;
	struct node* higher;
};


void insert(int key, struct node** tree)
{

	if (*tree == NULL)
	{
		*tree = (struct node*)malloc(sizeof(struct node));
		(*tree)->key = key;
	}
	else if (key < (*tree)->key)
		insert(key, &(*tree)->lower);
	else if (key > (*tree)->key)
		insert(key, &(*tree)->higher);
	// else
	//	key already exists in tree

}

void print(struct node** tree)
{
	if ((*tree)->lower != NULL)
		print(&(*tree)->lower);

	printf("%d ", (*tree)->key);

	if ((*tree)->higher != NULL)
		print(&(*tree)->higher);
}

int height(struct node** tree)
{
	if (*tree == NULL)
		return 0;
	else
	{
		int l = 1 + height(&(*tree)->lower);
		int h = 1 + height(&(*tree)->higher);
		return ((l < h)?h:l);
	}
}

struct node** find_largest(struct node** tree)
{
	if ((*tree)->higher != NULL)
		return find_largest(&(*tree)->higher);
	else
		return tree;
}

int main()
{
	struct node* tree = (struct node*)malloc(sizeof(struct node));
	tree->key = 50;
	insert(40, &tree);
	insert(2, &tree);
	insert(10, &tree);
	insert(100, &tree);
	insert(51, &tree);
	insert(49, &tree);
	insert(0, &tree);
	insert(-1, &tree);

	print(&tree);
	printf("\n");

	printf("tree height %d \n", height(&tree));

	printf("largest element %d \n", (*(find_largest(&tree)))->key); 
}
