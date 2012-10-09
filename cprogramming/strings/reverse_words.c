#include <stdio.h>
#include <string.h>

void swap(char *a, char *b)
{
	char tmp = *a;
	*a = *b;
	*b = tmp;
}

void reverse(char *begin, char *end)
{
	while(begin < end) {
		swap(begin++, end--);
	}
}

void reverse_sentence(char *str, int len)
{
	char *begin = NULL;
	char *cur = str;
	while (*cur) {
		if (begin == NULL && *cur != ' ') {
			begin = cur;
		}
		if(begin && (*(cur+1) == ' ' || *(cur+1) == '\0')) {
			reverse(begin, cur);
			begin = NULL;
		}
		cur++;
	}
	reverse(str, cur -1);

}

int main()
{
	char str[] = "This is a sentence";
	printf("Initial string :%s:\n", str);
	reverse_sentence(str, strlen(str));
	printf("Reverse string :%s:\n",str);
}
