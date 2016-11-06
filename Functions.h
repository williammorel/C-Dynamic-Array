#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

typedef struct node {
	int val;
	struct node * next;
} node_t;
void print_list(node_t * head);
int push_end(node_t * head, int val);
int push_beginning(node_t ** head, int val);
int pop(node_t ** head);
int remove_last(node_t * head);
int remove_by_index(node_t ** head, int n);
void add_by_index(node_t ** head, int val, int n);
void swap(node_t ** head, int a, int b);
void clear_list(node_t * head);
int change_val(node_t ** head, int a, int n);

#endif