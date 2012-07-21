#include<stdio.h>
#include<string.h>

void
rec_rev_util(char *str, char **s)
{
	if(!*str)
		return ;
	char a = *str;
	rec_rev_util(str+1, s);
	**s = a;
	*s = *s+1;
}

void
str_rev_rec(char *str)
{
	rec_rev_util(str, &str);
}

main() {
	char str[15] = "maruthi manohar";
	printf("%s\n",str);
	str_rev_rec(str);
	printf("%s\n",str);
}

