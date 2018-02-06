#include <stdio.h>
#include <stdlib.h>
#include "Functions.h"
#include "Algo.h"

int main() {
	node_t * head = NULL;
	head = malloc(sizeof(node_t));
	if (head == NULL) {
		return 1;
	}

	head->val = 1;
	head->next = malloc(sizeof(node_t));
	head->next-> val = 2;
	head->next->next = NULL;

	printf("address    val  pointer\n");

	printf("First list:\n");
	print_list(head);

	push_beginning(&head, 3);
	push_end(head, 4);
	push_end(head, 6);

	printf("Second list(push):\n");
	print_list(head);

	pop(&head);
	remove_last(head);

	printf("Third list(pop):\n");
	print_list(head);

	remove_by_index(&head, 1);

	printf("Fourth list(remove by index):\n");
	print_list(head);

	add_by_index(&head, 5, 0);
	add_by_index(&head, 2, 2);
	add_by_index(&head, 7, 4);

	printf("Fifth list(add by index):\n");
	print_list(head);

	swap(&head, 1, 2);

	printf("Sixth list(swap):\n");
	print_list(head);

	change_val(&head, 3, 2);

	printf("Seventh list(change_val):\n");
	print_list(head);

	printf("Highest Value(highest_val):\n%i\n", highest_val(head));
	printf("Lowest Value(lowest_val):\n%i\n", lowest_val(head));
	printf("Average(average_val):\n%i\n", average_val(head));
	printf("Node Count(node_count):\n%i\n", node_count(head));

	clear_list(head);
	printf("Eighth list(clear_list):\n");
	print_list(head);

	return 0;
}
