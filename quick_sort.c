#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
int a[N];
typedef int keytype;
#define INFINITY_LOOP 1

void quicksort(keytype a[], int first, int last)
{
	int i, j;
	keytype pivot, temp;
	
	pivot = a[(first + last) / 2];
	i = first;
	j = last;
	while (INFINITY_LOOP)
	{
		while (a[i] < pivot)
			i++;
		while (pivot < a[j])
			j--;
		if (i >= j)
			break;
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
		i++;
		j--;
	}
	printf("pivot = %d, i = %d, j = %d, first = %d, last = %d \n ", pivot, i, j, first, last);
	if (first < i - 1)
		quicksort(a, first , i - 1);
	if (j + 1 < last)
		quicksort(a, j + 1, last);
}

int main(void)
{
	int i;
	
	srand(time(NULL));
	printf("Before:");
	for (i = 0; i < N; i++)
	{
		a[i] = rand() / (RAND_MAX / 100 + 1);
		printf(" %2d", a[i]);
	}
	printf("\n");
	quicksort(a, 0, N - 1);
	printf("After: ");
	for (i = 0; i < N; i++)
		printf(" %2d", a[i]);
	printf("\n");
	return 0;
}