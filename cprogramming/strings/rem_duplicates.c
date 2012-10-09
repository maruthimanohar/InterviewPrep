#include <stdio.h>
#include <string.h>

void remove_duplicates(char *str)
{
	int len = strlen(str);
	int count_arr[256] = {0};
	int cur_index = 0, result_index =0;
	char temp;
	while( *(str + cur_index)) {
		temp = *(str + cur_index);
		if (count_arr[temp] == 0) {
			count_arr[temp] = 1;
			*(str + result_index) = temp;
			result_index++;
		}
		cur_index++;
	}
	*(str+result_index) = '\0';
}

// remove all the characters that are from str1 that are occuring from str2
void remove_chars_from_string(char *str1, char *str2)
{
	int len = strlen(str2);
	int count_arr[256] = {0};
	int cur_index = 0, result_index = 0;
	char temp;

	while (*(str2 + cur_index)) {
		count_arr[*(str2 + cur_index)]++;
		cur_index++;
	}

	len = strlen(str1);
	cur_index = 0;
	result_index = 0;
	while (*(str1 + cur_index)) {
		temp = *(str1 + cur_index);
		if (count_arr[temp] == 0) {
			*(str1 + result_index) = temp;
			result_index++;
		}
		cur_index++;
	}
	*(str1 + result_index) = '\0';
}

int main()
{
	char str[] = "geeksforgeeks";
	printf("initial string :%s\n", str);
	remove_duplicates(str);
	printf("result string :%s\n", str);

	char str1[] = "geeksforgeeks";
	printf("initial string:%s\n", str1);

	char str2[] = "mask";
	printf("second string:%s\n", str2);

	remove_chars_from_string(str1, str2);
	printf("result string :%s\n", str1);
}
