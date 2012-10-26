#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void interleave(char *str1, char *str2, char *result, int pos)
{
	if (*str1 == '\0' && *str2 == '\0') {
		printf("%s\n", result);
		return;
	}
	if (*str1 == '\0') {
		memcpy(result+pos, str2, strlen(str2));
		printf("%s\n", result);
		return;
	}
	if (*str2 == '\0') {
		memcpy(result+pos, str1, strlen(str1));
		printf("%s\n", result);
		return;
	}
	*(result+pos) = *str1;
	interleave(str1+1, str2, result, pos+1);
	*(result+pos) = *str2;
	interleave(str1, str2+1, result, pos+1);

}

int main()
{
	char *str1 = "AB";
	char *str2 = "CD";
	char *result = (char *)malloc(sizeof(char) * (strlen(str1) + strlen(str2)));
	interleave(str1, str2, result, 0);
}
