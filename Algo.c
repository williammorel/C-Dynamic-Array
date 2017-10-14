#include <stdio.h>
#include <stdlib.h>
#include "Algo.h"
#include "Functions.h"

int highest_val(node_t * head) {
	node_t * current = head;
	int max = 0;
	do {
		if(current->val >= max) {
			max = current->val;
		}
		current = current->next;
	} while(current->next != NULL);
	if(current->val >= max) {
		max = current->val;
	}

	return max;
}

int lowest_val(node_t * head) {
	node_t * current = head;
	int min = head->val;
	do {
		if(current->val <= min) {
			min = current->val;
		}
		current = current->next;
	} while(current->next != NULL);
	if(current->val <= min) {
		min = current->val;
	}

	return min;
}

int average_val(node_t * head) {
	node_t * current = head;
	float avg = 0.0f;
	int total = 0;
	int index = 0;
	do {
		total += current->val;
		index += 1;
		current = current->next;
	} while(current->next != NULL);
	total += current->val;
	index += 1;
	avg = total / index;

	return avg;
}

int node_count(node_t * head) {
	node_t * current = head;
	int count = 0;
	while(current->next != NULL) {
		count += 1;
		current = current->next;
	}
	count += 1;

	return count;
}

/*
int print_sort(node_t * head) {
	node_t * current = head;
	node_t * temp = current;
	int sorted[node_count(current)];
	sorted[0] = highest_val(current);
	int index = 0;
	while(temp->val != sorted[0]) {
		index += 1;
		temp = temp->next;
	}
	remove_by_index(current, index);

	int count = 0;

	while(count <= node_count(current)) {
		sorted[count+1] = highest_val(current);

		while(temp->val != sorted[0]) {
			index += 1;
			temp = temp->next;
		}
		remove_by_index(current, index);
		index = 0;
		temp = current;
	}

	for(int i = 0; i <= count; i++) {
		printf("%d ", sorted[i]);
	}

}
*/
