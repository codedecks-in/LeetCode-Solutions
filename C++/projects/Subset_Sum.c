#include <stdio.h>
#include <stdlib.h>

#define ARRAYSIZE(a) (sizeof(a)) / (sizeof(a[0]))

static int total_nodes;
void printSubset(int A[], int size)
{
	for (int i = 0; i < size; i++) {
		printf("%*d", 5, A[i]);
	}

	printf("n");
}

void subset_sum(int s[], int t[],
				int s_size, int t_size,
				int sum, int ite,
				int const target_sum)
{
	total_nodes++;
	if (target_sum == sum) {
		printSubset(t, t_size);
		subset_sum(s, t, s_size, t_size - 1, sum - s[ite], ite + 1, target_sum);
		return;
	}
	else {
		for (int i = ite; i < s_size; i++) {
			t[t_size] = s[i];
			subset_sum(s, t, s_size, t_size + 1, sum + s[i], i + 1, target_sum);
		}
	}
}

void generateSubsets(int s[], int size, int target_sum)
{
	int* tuplet_vector = (int*)malloc(size * sizeof(int));

	subset_sum(s, tuplet_vector, size, 0, 0, 0, target_sum);

	free(tuplet_vector);
}

int main()
{
	int weights[] = { 10, 7, 5, 18, 12, 20, 15 };
	int size = ARRAYSIZE(weights);

	generateSubsets(weights, size, 35);
	printf("Nodes generated %dn", total_nodes);
	return 0;
}
