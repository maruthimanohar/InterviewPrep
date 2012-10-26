// Given a sorted array arr[] and a number x, write a function that counts
// the occurrences of x in arr[]. Expected time complexity is O(Logn)

#include <stdio.h>
int first_occurence(int *arr, int size, int elem)
{
	int left_index = 0;
	int right_index = size -1;
	while (left_index <= right_index) {
		int middle_index = (right_index + left_index) / 2;
		int x = arr[middle_index];
		if ((x == elem && middle_index == left_index) ||
		    (x == elem && arr[middle_index -1] < x)) {
			return middle_index;
		}
		if ( elem <= x) {
			right_index = middle_index - 1;
		} else {
			left_index = middle_index + 1;
		}
	}
	return -1;
}

int second_occurence(int *arr, int size, int elem)
{
	int left_index = 0;
	int right_index = size -1;
	while (left_index <= right_index) {
		int middle_index = (right_index + left_index) / 2;
		int x = arr[middle_index];
		if ((x == elem && middle_index == right_index) ||
		    (x == elem && arr[middle_index+1] > x)) {
			return middle_index;
		}
		if (elem >= x) {
			left_index = middle_index+1;
		} else {
			right_index = middle_index-1;
		}
	}
	return -1;
}

int count_num_occur_sorted_array(int *arr, int size, int elem)
{
	int first = first_occurence(arr, size, elem);
	if (first == -1)
		return 0;
	int second = second_occurence(arr, size, elem);
	return (second - first)+1;
}

int main()
{
	int arr[] = {1, 1, 2, 2, 2, 2, 3};
	printf("Num of occurences of %d is : %d\n", 1, count_num_occur_sorted_array(arr, 7, 1));
	printf("Num of occurences of %d is : %d\n", 2, count_num_occur_sorted_array(arr, 7, 2));
	printf("Num of occurences of %d is : %d\n", 3, count_num_occur_sorted_array(arr, 7, 3));
}

