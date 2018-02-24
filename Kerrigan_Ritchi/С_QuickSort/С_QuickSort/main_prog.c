#include <stdio.h>

void qs(int*, int, int);

main()
{
	int n = 5;
	int a[5] = { 3, 4, 1, 6, 2 };

	qs(a, 0, n - 1);

	for (int i = 0; i < 5; i++)
		printf("%d ", a[i]);
	printf("\n");
}


void qs(int *s_arr, int first, int last)
{
	if (first < last)
	{
		int left = first, right = last, middle = s_arr[(left + right) / 2];
		do
		{
			while (s_arr[left] < middle) left++;
			while (s_arr[right] > middle) right--;
			if (left <= right)
			{
				int tmp = s_arr[left];
				s_arr[left] = s_arr[right];
				s_arr[right] = tmp;
				left++;
				right--;
			}
		} while (left <= right);
		qs(s_arr, first, right);
		qs(s_arr, left, last);
	}
}
