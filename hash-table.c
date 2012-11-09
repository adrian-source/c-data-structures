
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define HASH_TAB 16

struct record{
	char *key;
	char *data;
};

unsigned int h1(char *k){
	unsigned int h;
	unsigned char *c;

	h = 0;
	for (c = (unsigned char *) k; *c; c++)
		h = h * 37 + *c;

	return h;
}

unsigned int h2(char *k)
{
	unsigned int h;
	unsigned char *c;

	h = 0;
	for (c = (unsigned char *) k; *c; c++)
		h = h * 31 + *c;

	return h % 2 == 0 ? h + 1 : h;
}

unsigned int hash(char *k, int i)
{
	return (h1(k) + i * h2(k)) % HASH_TAB;
}


unsigned int locate(struct record tbl[], char *k)
{
	unsigned int i, b;

	for (i = 0; i < HASH_TAB; i++){
		b = hash(k, i);
		if (NULL == tbl[b].key || strcmp(tbl[b].key, k) == 0)
			break;
	}
	return b;
}

int member(struct record tbl[], char *k){
	unsigned int b = locate(tbl, k);

	if (tbl[b].key == NULL)
		return 0;
	else
		return strcmp(tbl[b].key, k) == 0;
}

char *cpy(char *s){
	char *dest, *d;

	d = dest = malloc(strlen(s) * sizeof(char) + 1);
	if (d)
		while ((*d++ = *s++));
	return dest;
}

int insert(struct record tbl[], char *k){
	unsigned int b;

	b = locate(tbl, k);
	if (NULL == tbl[b].key){
		tbl[b].key = cpy(k);
		return 1;
	}
	else
		return strcmp(tbl[b].key, k) == 0;
}

void init_hash_table(struct record tbl[]){
	unsigned int b;

	for (b = 0; b < HASH_TAB; b++)
	{
		tbl[b].key = NULL;
		tbl[b].data = NULL;
	}
}

int main(){

	printf("test\n");

	struct record tbl[HASH_TAB];
	init_hash_table(tbl);

	char* email1 = "adrian.sitterle@gmail.com";
	char* email2 = "adrianman@gmail.com";
	char* email3 = "adrianman@gmail.com";


	printf("trying to insert email1 %d\n", insert(tbl, email1));
	printf("trying to insert email2 %d\n", insert(tbl, email2));
	printf("trying to insert email3 %d\n", insert(tbl, email3));

	int b = locate(tbl, email3);
	tbl[b].data = "test";


	int i;
	for (i = 0; i < HASH_TAB; i++)
		printf("%d %s %s\n", i, tbl[i].key, tbl[i].data);


}

