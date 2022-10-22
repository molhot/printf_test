//10 to 16
#include<stdio.h>
#include <stdlib.h>

int counter_digit(char *base_num)
{
	int digit;

	digit = 0;
	while(*base_num != '\0')
	{
		digit = digit + 1;
		base_num = base_num + 1;
	}
	return digit;
}

char *basenum_char_malloc(int subject_num, int base_num, char *basechar)
{
	int malloc_size;
	int subjectnum_copy;
	char *char_malloc;

	malloc_size = 0;
	subjectnum_copy = subject_num;
	while(subject_num != 0)
	{
		malloc_size = malloc_size + 1;
		subject_num = subject_num / base_num;
	}
	char_malloc = (char *)malloc(sizeof(char) * malloc_size);
	*(char_malloc + malloc_size) = '\0';
	while(malloc_size-- != 0)
	{
		*(char_malloc + malloc_size) = *(basechar + subjectnum_copy % base_num);
		subjectnum_copy = subjectnum_copy / 2;
	}
	return char_malloc;
}

int main()
{
	char *base_num_char = "0123456789ABCDEF";
	int subject_num = 1000;
	int base_num;
	char *char_subject_num;

	base_num = counter_digit(base_num_char);
	printf("%d\n", base_num);
	char_subject_num = basenum_char_malloc(subject_num, base_num, base_num_char);
	printf("%s\n", char_subject_num);
	free(char_subject_num);
	//base_numはきちんと2が入っている
}