#include <stdio.h>

#include "stack_gen.h"

struct s {
	int a;
	int b;
};

void print_struct(struct s *st)
{
	printf("%d %d\n", st->a, st->b);
}

int main()
{
	struct stack st;
	init_stack(&st, 2, sizeof(struct s));
//	int elem1 = 1, elem2 = 2, elem3 = 3;
//	printf("%d:%d\n", st.max_size, st.cur_size);
	struct s elem1, elem2;
	elem1.a = 2;
	elem1.b = 1;

	elem2.a = 4;
	elem2.b = 3;

	push(&st, &elem1);
	printf("%d:%d\n", st.max_size, st.cur_size);
	push(&st, &elem2);
	printf("%d:%d\n", st.max_size, st.cur_size);
//	push(&st, &elem3);
//	printf("%d:%d\n", st.size, st.cur_size);
	while (!is_empty(&st)) {
		printf("%d:%d\n", st.max_size, st.cur_size);
		struct s ret;
		pop(&st, &ret);
		//printf("%d\n", ret);
		print_struct(&ret);
	}
	printf("%d:%d\n", st.max_size, st.cur_size);
	return 1;
}
