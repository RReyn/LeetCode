#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BITMAP_ARRAY_LEN	8
#define BITMAP_MASK		32

int
bitmap_set(int *bitmap, size_t bitmap_len, int i)
{
	if (i > bitmap_len * BITMAP_MASK) {
		return -1;
	}

	bitmap[i / BITMAP_MASK]  |= 1 << (i % BITMAP_MASK);
	return 0;
}

void
bitmap_clear(int *bitmap, size_t bitmap_len, int i)
{
	bitmap[i / BITMAP_MASK] &= ~(1 << (i % BITMAP_MASK));
}

int
bitmap_test(int *bitmap, int i)
{
	return bitmap[i / BITMAP_MASK] & (1 << (i % BITMAP_MASK));
}

void
bitmap_init(int *bitmap, size_t bitmap_len)
{
	memset(bitmap, 0, bitmap_len * sizeof(int));	
}

int
lengthOfLongestSubstring(char *s)
{
	int max_count = 0, count = 0, str_len = strlen(s);
	int i = 0, j = 0;

	for (i = 0; i < str_len; i++) {
		int bitmap[MAX_BITMAP_ARRAY_LEN] = {0};
		if (max_count < count) {
			max_count = count;
		}
		count = 1;
		bitmap_init(bitmap, MAX_BITMAP_ARRAY_LEN);
		bitmap_set(bitmap, MAX_BITMAP_ARRAY_LEN, s[i]);
		for (j = i + 1; j < str_len; j++) {
			if (bitmap_test(bitmap, s[j])) {
				break;
			}
			count++;
			bitmap_set(bitmap, MAX_BITMAP_ARRAY_LEN, s[j]);
		}
		if (count == str_len) {
			max_count = count;
			break;
		}

	}
	return max_count;
}

int
main(int argc, char *argv[])
{
	char *s1 = "abcabcbb";
	char *s2 = "bbbbb";
	char *s3 = "pwwkew";
	int ret = 0;
	
	ret = lengthOfLongestSubstring(s1);
	printf("ret = %d\n", ret);
	ret = lengthOfLongestSubstring(s2);
	printf("ret = %d\n", ret);
	ret = lengthOfLongestSubstring(s3);
	printf("ret = %d\n", ret);
	return 0;
}
