#include <stdlib.h>
#include "linked_list.h"


void* llist_get(linked_list* llist, unsigned int index)
{
	if (index >= llist->length) return 0;
	node* current = llist->first_node;
	for (int i = 1; i <= index; ++i)
		current = current->next;
	return (current ? current->data : 0);
}


void llist_set(linked_list* llist, unsigned int index, void* data)
{
	if (index >= llist->length) return;
	node* current = llist->first_node;
	for (int i = 1; i <= index; ++i)
		current = current->next;
	if (current) current->data = data;
}


void llist_add(linked_list* llist, unsigned int index, void* data)
{
	if (llist->length == 0)
	{
		llist->first_node = (node*)malloc(sizeof(node));
		llist->first_node->data = data;
		llist->first_node->next = 0;
	}
	else if (index >= llist->length)
	{
		node* current = llist->first_node;
		for (int i = 1; i < llist->length; ++i)
			current = current->next;
		current->next = (node*)malloc(sizeof(node));
		((node*)(current->next))->data = data;
		((node*)(current->next))->next = 0;
	}
	else
	{
		node* current = llist->first_node;
		for (int i = 1; i < index; ++i)
			current = current->next;
		node* new = (node*)malloc(sizeof(node));
		new->data = data;
		new->next = current->next;
		current->next = new;
	}
	llist->length += 1;
}


void llist_delete(linked_list* llist, unsigned int index)
{
	if (index >= llist->length) return;
	if (index == 0)
	{
		node* next = llist->first_node->next;
		free(llist->first_node);
		llist->first_node = next;
	}
	else
	{
		node* current = llist->first_node;
		for (int i = 1; i < index; ++i)
			current = current->next;
		node* next = current->next ? ((node*)(current->next))->next : 0;
		free(current->next);
		current->next = next;
	}
	llist->length -= 1;
}


node* llist_get_node(linked_list* llist, unsigned int index)
{
	if (index >= llist->length) return 0;
	node* current = llist->first_node;
	for (int i = 1; i <= index; ++i)
		current = current->next;
	return current;
}


void* llist_get_array(linked_list* llist, unsigned char type_size)
{
	if (!llist->length) return 0;
	char* array = (char*)malloc(type_size * llist->length);
	int k = 0;
	node* current = llist->first_node;
	for (int i = 0; i < llist->length; ++i)
	{
		for (int j = 0; j < type_size; ++j, ++k)
			array[k] = *((char*)(current->data + j));
		current = current->next;
	}
	return array;
}


void llist_clear(linked_list* llist)
{
	while (llist->length)
		llist_delete(llist, llist->length-1);
}