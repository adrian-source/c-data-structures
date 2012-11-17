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
	if (size == 0)
	{
		return;
	}
	else
	{
		if (word[0] - 'A' < 'A' && word[0] - 'A' > 'Z')
		{
			printf("ERROR\n");
			return;
		}
		if(!n->branch[word[0] - 'A'])
		{
			struct node* newnode = (struct node*)malloc(sizeof(struct node));
			init_node(newnode);
			n->branch[word[0] - 'A'] = newnode;
			if (size == 1)
				n->branch[word[0] - 'A']->eow = 1;
		}
		add(n->branch[word[0]-'A'], &word[1], size-=1);
	}
}

void print(struct node* n, char* s, int size)
{
	if (n->eow)
	{
		printf("> %s\n", s);
		return;
	}

	int i;
	char * s2 = (char *)malloc(sizeof(char)*(size+1));
	for (i = 0; i < size; i++)
		s2[i] = s[i];
	size++;

	for (i = 0; i < 26; i++)
	{
		if (n->branch[i])
		{
			s2[size-1] = (char)(i+'A');
			print(n->branch[i], s2, size);
		}
	}

	free(s2);
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

	char *s;
	print(n, s, 0);

	free(n);

}
