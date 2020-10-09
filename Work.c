#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>


#define LOG_FILE_NAME "Problems.log"
typedef int ElemS;

#include "Stack.h"

void Test1() {
	Stack s = { 0 };
	StackConstruct(&s, 3);
	StackConstruct(&s, 4);
	StackConstruct(&s, 7);
	StackConstruct(&s, 8);

	StackDump(&s);
	StackPush(&s, 5);
	StackPush(&s, 7);
	StackPush(&s, 8);
	StackPop(&s);
	StackPush(&s, 8);
	StackPop(&s);
	StackDump(&s);

	ElemS top = 0;
	if (StackTop(&s, &top) != STACK_OK) printf("error\n");
	else printf("%d\n", top);

	printf("%zu\n", StackSize(&s));

	StackDump(&s);
}

void Test2() {
	Stack s = { 0 };
	Stack s2 = { 0 };
	StackConstruct(&s, 3);
	StackConstruct(&s, 1000);
	StackConstruct(&s, 1000);
	StackConstruct(&s, 2);

	StackDump(&s);
	StackPush(&s2, 5);
	StackPush(&s, 7);
	StackDump(&s);
	StackPush(&s, 432);
	StackPush(&s, 21);
	StackPush(&s, 64);
	StackPush(&s, 75);
	StackPush(&s, 132);
	StackPush(&s, 876);
	StackPush(&s, 511);
	StackPush(&s, 52);
	StackPush(&s, 58);

	StackPush(&s2, 33333);
	StackPush(&s2, 876);
	StackPush(&s2, 511);
	StackPush(&s2, 52);
	StackPush(&s2, 33333);

	StackDump(&s2);

	StackPop(&s2);
	StackPop(&s2);
	StackPop(&s2);

	StackDump(&s2);

	StackDump(&s);
	printf("%zu\n", StackSize(&s));
	StackPop(&s);
	StackPop(&s);
	StackPop(&s);
	StackPop(&s);
	StackDump(&s);
	printf("%zu\n", StackSize(&s));

	ElemS top = 0;
	if (StackTop(&s, &top) != STACK_OK) printf("error\n");
	else printf("%d\n", top);

	printf("%zu\n", StackSize(&s));

	printf("%zu\n", StackSize(&s));

	StackDestruct(&s);
	AllStacksDestruct(&s);
	
	//StackPush(&s, 58);
}


void RuntimeTest() {
	Stack s = { 0 };
	StackConstruct(&s, 3);
	StackConstruct(&s, 4);
	StackConstruct(&s, 7);
	StackConstruct(&s, 8);
	StackConstruct(&s, 9);
	StackConstruct(&s, 9);
	StackConstruct(&s, 9);
	StackConstruct(&s, 2);

	while (1)
	{
		char c[6];
		scanf("%6s", &c);
		if (strcmp(c, "push") == 0) {
			int v;
			scanf("%d", &v);
			if (StackPush(&s, v) != STACK_OK) printf("error\n");
			else printf("ok\n");
		}
		else if (strcmp(c, "pop") == 0) {
			{
				ElemS top = 0;
				if (StackTop(&s, &top) != STACK_OK) printf("error\n");
				else printf("%d\n", top);
				StackPop(&s);
				//if (StackPop(&s) != STACK_OK) printf("error2\n");
			}
		}
		else if (strcmp(c, "top") == 0) {
			ElemS top = 0;
			if (StackTop(&s, &top) != STACK_OK) printf("error\n");
			else printf("%d\n", top);
		}
		else if (strcmp(c, "size") == 0) {
			size_t sz = StackSize(&s);
			printf("%zu\n", sz);
		}
		else if (strcmp(c, "dump") == 0) {
			StackDump(&s);
			printf("ok\n");
		}
		else if (strcmp(c, "clear") == 0) {
			//StackDestruct(&s);
			for (int i = 0; StackSize(&s) > 0; ++i) StackPop(&s);
			printf("ok\n");
		}
		else if (strcmp(c, "print") == 0) {
			//StackPrint(&s);
			//printf("ok\n");
		}
		else if (strcmp(c, "kill") == 0) {
			AllStacksDestruct();
			printf("done\n");
		}
		else if (strcmp(c, "exit") == 0) {
			printf("bye\n");
			return 0;
		}
	}


	return 0;
}

void Infinity() {
	for (int i = 0; i < 10000; ++i) {
		Stack s = { 0 };
		StackConstruct(&s, 10);
	}
}

int main() {

	//Test1(); return 0;
	//Test2(); return 0;
	Infinity(); return 0;

	//RuntimeTest(); return 0;

	return 0;
}