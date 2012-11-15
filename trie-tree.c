#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node** branch;
	int eow; // end of word
};

void init_node(struct node* n)
{
	int i;
	n->branch = (struct node**)malloc(26 * sizeof(struct node));
	n->eow = 0;
}

void add(struct node* n, char* word, int size)
{
	printf("size %d, eow %d \n", size, n->eow);
	if (size == 0)
	{
		return;
	}
	else
	{

		printf("adding %s, position %d \n", word, word[0]-'A');
		if (word[0] - 'A' < 'A' && word[0] - 'A' > 'Z')
		{
			printf("ERROR\n");
			return;
		}
		printf("%d\n", n->eow);
		if(!n->branch[word[0] - 'A'])
		{
			printf("creating new node...\n");
			struct node* newnode = (struct node*)malloc(sizeof(struct node));
			init_node(newnode);
			n->branch[word[0] - 'A'] = newnode;
			if (size == 1)
				n->branch[word[0] - 'A']->eow = 1;
			printf(".\n");
		}
		add(n->branch[word[0]-'A'], &word[1], size-=1);
		printf(",\n");
	}
}

void print(struct node* n)
{
	if (n->eow)
		printf("END OF WORD\n");

	int i;
	for (i = 0; i < 26; i++)
	{
		if (n->branch[i])
		{
			printf("%c\n", (char)(i+'A'));
			print(n->branch[i]);
		}
	}
}

int main()
{
	char* word1 = "APPLE";
	char* word2 = "APE";
	char* word3 = "BABY";
	char* word4 = "BALL";
	char* word5 = "CAT";

	struct node* n = (struct node*)malloc(sizeof(struct node));
	init_node(n);

	add(n, word1, 5);
	add(n, word2, 3);
	add(n, word3, 4);
	add(n, word4, 4);
	add(n, word5, 3);

	print(n);
}