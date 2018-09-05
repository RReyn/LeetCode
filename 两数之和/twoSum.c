/**
 *  * Note: The returned array must be malloced, assume caller calls free().
 *   */
int* twoSum(int* nums, int numsSize, int target) {
	int i = 0, j = 0;
	int *array = NULL;

	array = (int *)malloc(2 * sizeof(int));
	if (array == NULL) {
		return NULL;
	}

	for (i = 0; i < numsSize; i++) {
		for (j = i + 1; j < numsSize; j++) {
			if (nums[i] + nums[j] == target) {
				array[0] = i;
				array[1] = j;
				return array;
			}
		}
	}
	return NULL;
}
