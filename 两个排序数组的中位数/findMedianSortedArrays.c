#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double
findMedianSortArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
	double median = 0;
	int numsCount = nums1Size + nums2Size;
	int *tmp_array = NULL;
	int index = 0, median_index = 0;
	int i = 0, j = 0;

	tmp_array = (int *)malloc(numsCount * sizeof(int));
	if (!tmp_array) {
		return 0;
	}
	memset(tmp_array, 0, numsCount * sizeof(int));

	while (i < nums1Size && j < nums2Size) {
		if (nums1[i] < nums2[j]) {
			tmp_array[index++] = nums1[i++];
		} else {
			tmp_array[index++] = nums2[j++];
		}
	}
	while (i < nums1Size && j >= nums2Size) {
		tmp_array[index++] = nums1[i++];
	}
	while (i >= nums1Size && j < nums2Size) {
		tmp_array[index++] = nums2[j++];	
	}

	median_index = (nums1Size + nums2Size) / 2;
	if ((nums1Size + nums2Size) % 2 == 0) {
		median = (double)(tmp_array[median_index - 1] + tmp_array[median_index ]) / 2;
	} else {
		median = (double)(tmp_array[median_index]);
	}

	free(tmp_array);

	return median;
}

int
main(int argc, char *argv[])
{
	int a1[] = {1, 3};
	int a2[] = {2};
	int a3[] = {1, 2};
	int a4[] = {3, 4};

	printf("a1 and a2 meidan = %f\n", findMedianSortArrays(a1, 2, a2, 1));
	printf("a3 and a4 meidan = %f\n", findMedianSortArrays(a3, 2, a4, 2));
	return 0;
}
