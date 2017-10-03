#include <stdio.h>
#include <stdlib.h>
#include "Algo.h"
#include "Functions.h"

int highest_val(node_t * head) {
	node_t * current = head;
	int max = 0;
	int index = 0;

	while(head->next != NULL) {
		while(current->next != NULL) {
			current = current->next;
		}
		if(current->val >= max) {
			max = current->val;
		}
	}
	
	return max;
}
/*
int lowest_val(node_t * head) {
	node_t * current = head;
	int min = head->val;
	int index = 0;
}*/
