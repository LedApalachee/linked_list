#ifndef linked_list_h
#define linked_list_h


typedef unsigned char byte;


typedef struct
{
	void* data;
	void* next;
} node;


typedef struct
{
	unsigned int length;
	node* first_node;
} linked_list;


// when you get an element from the list remember to cast the returning void pointer to a pointer of your data type
// i recomend you wrap it in a macro like "#define _llist_get(llist, index, type) ((*type)llist_get(llist, index))"  ("llist" is a pointer)


void* llist_get(linked_list* llist, unsigned int index);
void llist_set(linked_list* llist, unsigned int index, void* data);

void llist_add(linked_list* llist, unsigned int index, void* data);
void llist_delete(linked_list* llist, unsigned int index);

node* llist_get_node(linked_list* llist, unsigned int index);
void* llist_get_array(linked_list* llist, unsigned char type_size); // produces a dynamically allocated array (remember to free() it)

void llist_clear(linked_list* llist);


#endif
