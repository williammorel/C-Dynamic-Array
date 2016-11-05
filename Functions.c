#include <stdio.h>
#include <stdlib.h>
#include "Functions.h"

void print_list(node_t * head) {
	node_t * current = head;

	/* Print node address, value and next value it points to, then move node to next and repeat. */
	while (current != NULL) {
		printf("%p: %d: %p\n", current, current->val, current->next);
		current = current->next;
	}
}

int push_end(node_t * head, int val) {
	node_t * current = head;
	/* While the "next" content is not NULL, move current pointer to next node  */
	while (current->next != NULL) {
		current = current->next;
	}
	
	/* Now we can add a new variable */
	current->next = malloc(sizeof(node_t));
	current->next->val = val;
	current->next->next = NULL;
	return val;
}

int push_beginning(node_t ** head, int val) {
	node_t * new_node;
	new_node = malloc(sizeof(node_t));
	
	/* Declare new node as head (node structure) and declare next value to old head node */
	new_node->val = val;
	new_node->next = *head;
	*head = new_node;
	return val;
}

int pop(node_t ** head) {
	int retval;
	node_t * next_node = NULL;

	/* If head contains no nodes, return NULL */
	if (*head == NULL) {
		return NULL;
	} else {
		/* Make 2nd node head, free old node, then return the old node's value */
		next_node = (*head)->next;
		retval = (*head)->val;
		free(*head);
		*head = next_node;
		
		return retval;
	}
}

int remove_last(node_t * head) {
	int retval;
	node_t * current = head;
	/* If there is only one item in the list, remove it */
	if (head->next == NULL) {
		retval = head->val;
		free(head);
		return retval;
	} else {
		/* Make second to last node's next value NULL and free the last node */
		while (current->next->next != NULL) {
			current = current->next;
		}
		retval = current->next->val;
		free(current->next);
		current->next = NULL;
		return retval;
	}
}

int remove_by_index(node_t ** head, int n) {
	int retval;
	node_t * current = *head;
	node_t * temp_node = NULL;
	node_t * next_node = NULL;

	/* If node position is 0, remove first node and make 2nd node head */
	if (n-1 == 0) {
		next_node = (*head)->next;
		retval = (*head)->val;
		free(*head);
		*head = next_node;
		return retval;
	} else {
		/* Set temp_node to point to node at n (position), then free the node at  */
		for (int i = 0; i < n-1; i++) {
			if (current->next == NULL) {
				/* If last node, break for() loop */
				break;
	        } else {
				current = current->next;
			}
		}
		temp_node = current->next;
		retval = temp_node->val;
		current->next = temp_node->next;
		free(temp_node);
		return retval;
	}
}

void add_by_index(node_t ** head, int val, int n) {
	node_t * current = *head;
	node_t * new_node;
	new_node = malloc(sizeof(node_t));

	if (n == 0) {
		/* Create new node, make it head and point it to old first node */
		new_node->val = val;
		new_node->next = *head;
		*head = new_node;
	} else {
		/* Go to node before new node position, create new node, change new node's "next" point to old node's "next", and change old node's "next" to point to new node */
		for (int i = 0; i < n-1; i++) {
			if (current->next == NULL) {
				current->next->val = val;
		        current->next->next = NULL;
				break;
			} else {
			current = current->next;
			}
		}
		new_node->val = val;
		new_node->next = current->next;
		current->next = new_node;
	}
}

void swap(node_t ** head, int a, int b) {
	node_t * first = *head;
	node_t * second = *head;
	node_t * temp_node = NULL;
	temp_node = malloc(sizeof(node_t));

	/* Swap node a and b's var */
	for (int i = 0; i < a-1; i++) {
		first = first->next;
	}
	for (int i = 0; i < b-1; i++) {
		second = second->next;
	}
	temp_node->val = first->val;
	first->val = second->val;
	second->val = temp_node->val;
	free(temp_node);
}

void clear_list(node_t * head) {
	node_t * current = head;

	while(head->next != NULL) {
		/* Point "current" to third to last node, then clear the last node and make the second to last node's next pointer NULL */
		while(current->next->next != NULL) {
			current = current ->next;
		}
		free(current->next);
		current->next = NULL;
		current->val = NULL;
		current = head;
	}

	free(head);
}

int change_val(node_t ** head, int a, int n) {
	node_t * current = *head;
	int oldval;

	/* Move current pointer to n node and change it's value */
	if (n == 0) {
		oldval = current->val;
		current->val = a;
		return oldval;
	} else {
		for (int i = 0; i < n-1; i++) {
			current = current->next;
		}
		oldval = current->val;
		current->val = a;
		return oldval;
	}
}

/*May be misleading:
 * ->Use (node_t ** head) when working with the pointer to head
 * ->Use (node_t * head) when working directly with head
 */