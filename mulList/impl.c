//:impl.c
//	program:
//		this file realized the mulList functions
//	history:
//		guo 20161211 first release
//
#include <stdio.h>

struct Node
{
	char stu[20];
	int class;
	struct Node * NextStu;
	struct Node * NextClass;
};

