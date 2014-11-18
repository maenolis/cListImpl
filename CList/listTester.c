#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "List.h"

int main(int argc, char* argv[]) {

	ListPtr list;
	if (createList(&list) < 0) {
		return -1;
	}

	int i, *value = NULL;
	for (i = 0; i < 100000; i++) {
		value = malloc(sizeof(int));
		memcpy(value, &i, sizeof(int));
		if (/*i%2 == 0*/0) {
			if (pushFrontList(list, (void*) value) < 0) {
				return -1;
			}
		} else {
			if (pushBackList(list, (void*) value) < 0) {
				return -1;
			}
		}
		printf("i = %d\ngetSizeList = %d\n", i, getSizeList(list));
	}
	i = 0;
	if (invertList(list) < 0) {
		return -1;
	}
	while (getSizeList(list) > 0) {
		if (1/*i%4 == 0*/) {
			if (getFirstList(list, (void**) &value) < 0) {
				return -1;
			}
			if (popFrontList(list) < 0) {
				return -1;
			}
		} else if (i % 4 == 1) {
			if (getLastList(list, (void**) &value) < 0) {
				return -1;
			}
			if (popBackList(list) < 0) {
				return -1;
			}
		} else if (i % 4 == 2) {
			if (popAndGetBackList(list, (void**) &value) < 0) {
				return -1;
			}
		} else {
			if (popAndGetFrontList(list, (void**) &value) < 0) {
				return -1;
			}
		}
		printf("i = %d\ngetSizeList = %d\nvalue = %d\n", i++,
				getSizeList(list), *value);
		free(value);
		value = NULL;
	}

	if (destroyList(&list) < 0) {
		return -1;
	}
	return 0;
}
