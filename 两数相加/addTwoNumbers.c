#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode {
	int val;
	struct ListNode *next;
} ListNode;

#define FREE_NODE(NODE) do {      \
	if (NODE) {               \
		free(NODE);       \
		NODE = NULL;      \
	}                         \
} while (0)

#define ARRAY_LEN(array)	(sizeof(array) / sizeof(array[0]))

void *
zmalloc_node(size) 
{
	void *_tmp = (void *)malloc(size);
	if (!_tmp) {
		exit(1);
	}
	memset(_tmp, 0, size);
	return _tmp;
}

inline int
addTwoNum(const int num1, const int num2, int *flag)
{
	int sum = 0;

	if (*flag) {
		*flag = 0;
		sum = num1 + num2 + 1;
	} else {
		sum = num1 + num2;
	}

	if (sum >= 10) {
		*flag = 1;
		sum = sum % 10;
	}
	return sum;
}

inline void 
listAdd(ListNode **header, ListNode *node)
{
	ListNode *tmp = *header;

	if (*header == NULL) {
		*header = node;
		return;
	}

	while (tmp->next) {
		tmp = tmp->next;
	}

	tmp->next = node;
}

inline void
listFree(ListNode *list)
{
	ListNode *tmp = NULL;
	
	while (list) {
		tmp = list->next;	
		FREE_NODE(list);
		list = tmp;
	}
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
	ListNode *result = NULL, *l1_tmp = NULL, *l2_tmp = NULL;
	int flag = 0;

	l1_tmp = l1;
	l2_tmp = l2;

	for (;l1_tmp != NULL && l2_tmp != NULL;
			l1_tmp = l1_tmp->next, l2_tmp = l2_tmp->next ) {
		ListNode *tmp = zmalloc_node(sizeof(ListNode));
	
		tmp->val = addTwoNum(l1_tmp->val, l2_tmp->val, &flag);
		listAdd(&result, tmp);
	}
	while (l1_tmp) {
		ListNode *tmp = zmalloc_node(sizeof(ListNode));
		tmp->val = addTwoNum(l1_tmp->val, 0, &flag);
		listAdd(&result, tmp);
		l1_tmp = l1_tmp->next;
	}
	while (l2_tmp) {
		ListNode *tmp = zmalloc_node(sizeof(ListNode));
		tmp->val = addTwoNum(0, l2_tmp->val, &flag);
		listAdd(&result, tmp);
		l2_tmp = l2_tmp->next;
	}
	if (flag) {
		ListNode *tmp = zmalloc_node(sizeof(ListNode));
		tmp->val = 1;
		listAdd(&result, tmp);
	}
	return result;
}

ListNode *
listInit(int *array, int num)
{
	ListNode *result = NULL;
	int i = 0;
	
	if (num == 0) 
		return NULL;

	for (i = 0; i < num; i++) {
		ListNode *tmp = zmalloc_node(sizeof(ListNode));
		tmp->val = array[i];
		listAdd(&result, tmp);
		printf("%d ", array[i]);
	}
	printf("\n");
	return result;
}

int
main(int argc, char *argv[])
{
	int array1[] = {4,5,2,2,9,6,8,9,4};
	int array2[] = {0,7,6,1,6,5,0,6,7};
	ListNode *result = NULL, *l1 = NULL, *l2 = NULL;

	l1 = listInit(array1, ARRAY_LEN(array1));	
	l2 = listInit(array2, ARRAY_LEN(array2));	

	result = addTwoNumbers(l1, l2);
	while (result) {
		printf("%d ", result->val);
		result = result->next;
	}
	printf("\n");

	listFree(l1);
	listFree(l2);
	listFree(result);
	return 0;
}
