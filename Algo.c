#include <stdio.h>
#include <stdlib.h>
#include "Algo.h"
#include "Functions.h"

int highest_val(node_t * head) {
	node_t * current = head;
	int max = 0;
	int index = 0;
	while(current->next != NULL) {
		if(current->val >= max) {
			max = current->val;
		}
		current = current->next;
	}

	return max;
}

int lowest_val(node_t * head) {
	node_t * current = head;
	int min = head->val;
	while(current->next != NULL) {
		if(current->val <= min) {
			max = current->val;
		}
		current = current->next;
	}

	return min;
}
