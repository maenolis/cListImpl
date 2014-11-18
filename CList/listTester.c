#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "List.h"

int main(int argc, char* argv[]) {

	myListPtr list;
	if (createMyList(&list) < 0) {
		return -1;
	}

	int i, *value = NULL;
	for (i = 0; i < 100000; i++) {
		value = malloc(sizeof(int));
		memcpy(value, &i, sizeof(int));
		if (/*i%2 == 0*/0) {
			if (pushFrontMyList(list, (void*) value) < 0) {
				return -1;
			}
		} else {
			if (pushBackMyList(list, (void*) value) < 0) {
				return -1;
			}
		}
		printf("i = %d\ngetSizeMyList = %d\n", i, getSizeMyList(list));
	}
	i = 0;
	if (invertMyList(list) < 0) {
		return -1;
	}
	while (getSizeMyList(list) > 0) {
		if (1/*i%4 == 0*/) {
			if (getFirstMyList(list, (void**) &value) < 0) {
				return -1;
			}
			if (popFrontMyList(list) < 0) {
				return -1;
			}
		} else if (i % 4 == 1) {
			if (getLastMyList(list, (void**) &value) < 0) {
				return -1;
			}
			if (popBackMyList(list) < 0) {
				return -1;
			}
		} else if (i % 4 == 2) {
			if (popAndGetBackMyList(list, (void**) &value) < 0) {
				return -1;
			}
		} else {
			if (popAndGetFrontMyList(list, (void**) &value) < 0) {
				return -1;
			}
		}
		printf("i = %d\ngetSizeMyList = %d\nvalue = %d\n", i++,
				getSizeMyList(list), *value);
		free(value);
		value = NULL;
	}

	if (destroyMyList(&list) < 0) {
		return -1;
	}
	return 0;
}
