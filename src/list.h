#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

typedef struct list List;

/*
Creates an empty list and assigns it to *l.
By not calling this function before using a list, it will have memory trash.
*/
int create_list(List** l_p, size_t data_size);

/* 
Deletes the list in the address passed on l. 
This function needs to be called in order to avoid memory leaks when the list is no longer needed.
*/
int delete_list(List** l_p);

/*
Inserts an element at the end of the list passed on l, the contents at the adress passed on value will be COPIED inside the list.
*/
int push_back_list (List *l, void *value);

/*
Removes an element at the end of the list passed on l.
*/
int pop_back_list (List *l);

/* ?????
*/
int insert_at_list (List *l, void *value, unsigned pos);

/* ?????
*/ 
int remove_at_list (List *l, unsigned pos);

/*
Returns a pointer to the value at pos of the linked list, in case l is NULL or pos is greater than the lsit size returns NULL.
*/
void* get_at_list (List *l, unsigned pos);

/*
Returns a pointer to the first value of the linked list, in case l is NULL or pos is greater than the lsit size returns NULL.
*/
void* get_start_list (List *l);

/*
Returns a pointer to the last value of the linked list, in case l is NULL or pos is greater than the lsit size returns NULL.
*/
void* get_end_list (List *l);

/*
Returns the linked list size, if l is NULL returns -1 instead.
*/
int get_size_list(List *l);

/*
Returns 1 if the list size is 0 and 0 if it's not. In case l is NULL returns -1.
*/
int is_empty_list(List *l);

/* ?????
Returns the position of the first element in the list with value equals to the one in the target_value adress.
*/
unsigned find_list(List *l, int (*comparator)(void* a, void* b), void* target_value);

#endif