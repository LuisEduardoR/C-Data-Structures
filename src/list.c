#include "list.h"
#include <stdio.h>

typedef struct node Node;

struct node
{
    void *data;
    Node *next;
    Node *prev;
};

struct list
{

    unsigned list_size;
    size_t data_size;
    Node *start, *end;

};

void copy_data(void *from, void *to, size_t data_size)
{

    char *f = (char*)from;
    char *t = (char*)to;

    for(size_t i = 0; i < data_size; i++)
        t[i] = f[i]; 

}

int create_list(List **l_p, size_t data_size) {

    *l_p = malloc(sizeof(List));
    if(*l_p == NULL)
        return 1;

    (*l_p)->list_size = 0;
    (*l_p)->data_size = data_size;

    (*l_p)->start = NULL;
    (*l_p)->end = NULL;
    return 0;
    
}

int delete_list(List **l_p) {

    if(l_p == NULL)
        return 1;
    if((*l_p) == NULL)
        return 2;

    Node *cur, *nxt;

    cur = (*l_p)->start;

    while(cur != NULL)
    {

        nxt = cur->next;

        free(cur->data);
        free(cur);

        cur = nxt;

    }

    free(*l_p);
    *l_p = NULL;
    return 0;

}

int push_back_list (List *l, void *value) {

    if(l->list_size == 0)
    {

        Node* new_node = malloc(sizeof(Node));
        if(new_node == NULL)
            return 1;

        new_node->data = malloc(l->data_size);
        if(new_node->data == NULL)
            return 1;

        copy_data(value, new_node->data, l->data_size);

        new_node->next = NULL;
        new_node->prev = NULL;

        l->start = new_node;
        l->end = new_node;

        l->list_size++;

    } 
    else
    {
        Node* new_node = malloc(sizeof(Node));
        if(new_node == NULL)
            return 1;

        new_node->data = malloc(l->data_size);
        if(new_node->data == NULL)
            return 1;

        copy_data(value, new_node->data, l->data_size);

        new_node->next = NULL;
        new_node->prev = l->end;

        l->end->next = new_node;
        l->end = l->end->next;

        l->list_size++;
    }
    
    return 0;

}

int pop_back_list (List *l) {

    if(l == NULL)
        return 1;

    if(l->list_size == 0)
        return 2;


    // Gets and sets the new end of the list.
    Node* n_end = l->end->prev;
    n_end->next = NULL;

    // Frees the old end of the list.
    free(l->end->data);
    free(l->end);

    l->end = n_end;
    l->list_size--;

    if(l->list_size == 0)
    {
        l->start = NULL;
        l->end = NULL;
    }

    return 0;

}

void* get_at_list (List *l, unsigned pos) {

    if(l == NULL)
        return NULL;

    int count = 0;

    Node* cur = l->start;

    while(count < pos) {

        if(cur->next == NULL)
            return NULL;

        cur = cur->next;
        count++;

    }
    
    return cur->data;

}

void* get_start_list (List *l) {

    if(l == NULL)
        return NULL;

    if(l->list_size == 0)
        return NULL;

    return l->start->data;

}

void* get_end_list (List *l) {

    if(l == NULL)
        return NULL;

    if(l->list_size == 0)
        return NULL;

    return l->start->data;

}


int get_size_list(List *l) {

    if(l == NULL)
        return -1;

    return l->list_size;

}

int is_empty_list(List *l) {

    if(l == NULL)
        return -1;

    if(l->list_size == 0)
        return 1;
    
    return 0;
}

