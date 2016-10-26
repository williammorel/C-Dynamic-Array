#include <stdio.h>
#include <stdlib.h>

int main() {
	typedef struct node {
		int val;
		struct node * next;
	} node_t;
  node_t * head = NULL;
  head = malloc(sizeof(node_t));
  if (head == NULL) {
  	return 1;
  }

  head->val = 1;
  head->next = malloc(sizeof(node_t));
  head->next-> val = 2;
  head->next->next = NULL;

void print_list(node_t * head)
{
	node_t * current = head;

	while (current != NULL)
	{
		printf("%d: %d: %d\n", current, current->val, current->next);
		current = current->next;
	}
}

int push_end(node_t * head, int val)
{
  node_t * current = head;
  while (current->next != NULL)
	{
    current = current->next;
  }

  /* now we can add a new variable */
  current->next = malloc(sizeof(node_t));
  current->next->val = val;
  current->next->next = NULL;
	return val;
}

int push_beginning(node_t ** head, int val)
{
    node_t * new_node;
    new_node = malloc(sizeof(node_t));

    new_node->val = val;
    new_node->next = *head;
    *head = new_node;
		return val;
}

int pop(node_t ** head)
{
    int retval = -1;
    node_t * next_node = NULL;

    if (*head == NULL)
		{
        return -1;
    }

    next_node = (*head)->next;
    retval = (*head)->val;
    free(*head);
    *head = next_node;

    return retval;
}

int remove_last(node_t * head) {
    int retval;
    // if there is only one item in the list, remove it
    if (head->next == NULL) {
        retval = head->val;
        free(head);
        head = NULL;
        //head->val = NULL;
        return retval;
    }

    node_t * current = head;

    while (current->next->next != NULL) {
        current = current->next;
    }
    retval = current->next->val;
    free(current->next);
    current->next = NULL;
    return retval;
}

int remove_by_index(node_t ** head, int n) {
    int i = 0;
    int retval = -1;
    node_t * current = *head;
    node_t * temp_node = NULL;

    if (n == 0) {
        return pop(head);
    }

    for (int i = 0; i < n-1; i++) {
        if (current->next == NULL) {
            return -1;
        }
        current = current->next;
    }

    temp_node = current->next;
    retval = temp_node->val;
    current->next = temp_node->next;
    free(temp_node);

    return retval;
}

void add_by_index(node_t ** head, int val, int n) {
	node_t * current = *head;
	node_t * new_node;
	new_node = malloc(sizeof(node_t));

	if (n == 0) {
		new_node->val = val;
		new_node->next = *head;
		*head = new_node;
	}
	for (int i = 0; i < n-2; i++) {
		if (current->next == NULL) {
			current->next->val = val;
	    current->next->next = NULL;
		}
		current = current->next;
	}
	new_node->val = val;
	new_node->next = current->next;
	current->next = new_node;
}

void swap(node_t ** head, int a, int b) {
	node_t * first = *head;
	node_t * second = *head;
	node_t * temp_node = NULL;
	temp_node = malloc(sizeof(node_t));
	
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
	// node->next before new node needs to point to new node, new node needs to point to where node behind it used to point to

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

  push_end(head, 3);
	add_by_index(&head, 5, 0);
	add_by_index(&head, 2, 1);

	printf("Fifth list(add by index):\n");
	print_list(head);
	
	swap(&head, 1, 2);
	
	printf("Sixth list(swap):\n");
	print_list(head);

  return 0;
}