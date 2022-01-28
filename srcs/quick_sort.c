#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20
#define INFINITY_LOOP 1
int	a[N];
typedef int	keytype;

void	quicksort(keytype a[], int first, int last) {
	int	i;
	int	j;
	keytype	pivot, temp;

	pivot = a[(first + last) / 2];
	printf("\npivot = %d, first = %d, last = %d\n", pivot, first, last);
	i = first;
	j = last;
	while (INFINITY_LOOP)
	{
		while (a[i] < pivot)
			i++;
		while (pivot < a[j])
			j--;
		if (i >= j)
			break ;
		for (int i = 0; i <= N; i++)
			printf("%2.d ", a[i]);
		printf("\n");
		printf("i = %d, j = %d \n", i, j);
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
		i++;
		j--;
	}
	if (first < i - 1)
	{
		printf("aaaaaaa\n");
		quicksort(a, first, i - 1);
	}
	if (j + 1 < last)
	{
		printf("bbbbbbbb\n");
		quicksort(a, j + 1, last);
	}
}

int main(void)
{
	srand(time(NULL));
	printf("Before:");
	for (int i = 0; i < N; i++)
	{
		a[i] = rand() / (RAND_MAX / 100 + 1);
		printf(" %2d", a[i]);
	}
	printf("\n");
	quicksort(a, 0, N - 1);
	printf("After: ");
	for (int i = 0; i < N; i++)
		printf(" %2d", a[i]);
	printf("\n");
	return 0;
}
