
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* xor_encrypt(char* key, char* m, int len)
{
	int i;
	int key_len = strlen(key);
	int m_len = len;
	char* encrypted = (char*)malloc(sizeof(char)*m_len);

	for (i = 0; i < (m_len); i++)
		encrypted[i] = m[i] ^ key[i % (key_len-1)];
	
	return encrypted;
}

int main()
{
	char* key = "adrian";
	char* to_encrypt = "This is a message that needs to be encrypted.";
	int len = strlen(to_encrypt);

	printf(">> %s\n", to_encrypt);

	char* encrypted = xor_encrypt(key, to_encrypt, len);
	printf(">> %s\n", encrypted);
	
	char* decrypted = xor_encrypt(key, encrypted, len);
	printf(">> %s\n", decrypted);

}