#include <stdio.h>
#include <string.h>
#include <string>
void swap(char *a, char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
//	*a = *a ^ *b;
//	*b = *a ^ *b;
//	*a = *a ^ *b;
}
void print_all_perm4(string s)
{
	int num_perm = 1, i, j, len = s.length();

	for (i = 1; i <= len; i++) num_perm *=i;

	for (i = 0; i < num_perm; i++){
		string p = s;
		string one_perm; 

		int dv = num_perm;
		int num = i;
		for (j = len; j > 0;  j--){
			int index = num % j;
			one_perm.push_back( p[index] );
			p.erase(index, 1);
			num /= j;        
		}
		cout << one_perm << endl;
	} 
}
// start index and end index
void print_perms_util(char *str, int start, int end)
{
	if (start == end) {
		printf("%s\n", str);
		return;
	}
	int i = 0;
	for (i = start; i <= end; i++) {
		swap(str+i, str+start);
		print_perms_util(str, start+1, end);
		swap(str+i, str+start);
	}
}
void print_perms(char *str)
{
	int len = strlen(str);
	print_perms_util(str, 0, len-1);
}
int main()
{
	char str[] =  "abc";
	print_perms(str);
	printf("done\n");
	print_all_perm4(str);

}
