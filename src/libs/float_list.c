#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "./float_list.h"

typedef struct _Node
{
    float value;
    struct _Node *next;
    struct _Node *prev;
} Node;

typedef struct _FloatList
{
    Node *first;
    Node *last;
    size_t length;
} FloatList;

FloatList *list_create()
{
    FloatList *list = malloc(sizeof(FloatList));
    return list;
}

Node *node_create(float value)
{
    Node *node = malloc(sizeof(Node));
    node->value = value;
    return node;
}

void list_append(FloatList *list, float value)
{
    assert(list != 0);

    Node *node = node_create(value);

    if (list->length == 0)
    {
        list->first = node;
    }
    else if (list->length != 0)
    {
        list->last->next = node;
        node->prev = list->last;
    }

    list->last = node;
    list->length += 1;
}

Node *_list_get_node(FloatList *list, size_t index)
{
    assert(list != 0);

    if (index > list->length - 1)
    {
        printf("Index out of bound in %s at %d\n", __FILE__, __LINE__);
        exit(1);
    }

    Node *curr_node;

    if (index < list->length / 2)
    {
        curr_node = list->first;

        for (size_t i = 1; i <= index; i++)
        {
            curr_node = curr_node->next;
        }
    }
    else
    {
        curr_node = list->last;

        for (size_t i = list->length - 1; i != index; i--)
        {
            curr_node = curr_node->prev;
        }
    }

    return curr_node;
}

float list_get(FloatList *list, size_t index)
{
    assert(list != 0);
    return _list_get_node(list, index)->value;
}

long list_index(FloatList *list, float value)
{
    assert(list != 0);

    if (list->length == 0)
    {
        printf("List empty in %s at %d\n", __FILE__, __LINE__);
        exit(1);
    }

    Node *curr_node = list->first;

    for (size_t i = 0; i < list->length; i++)
    {
        if (curr_node->value == value)
        {
            return i;
        }

        curr_node = curr_node->next;
    }

    return -1;
}

float list_remove(FloatList *list, size_t index)
{
    assert(list != 0);

    Node *found_node, *prev_node, *next_node;
    float found_value;

    found_node = _list_get_node(list, index);
    prev_node = found_node->prev;
    next_node = found_node->next;

    found_value = found_node->value;

    if (prev_node != 0)
    {
        prev_node->next = next_node;
    }

    if (next_node != 0)
    {
        next_node->prev = prev_node;
    }

    list->length -= 1;

    if (list->last == found_node && list->first != found_node)
    {
        list->last = prev_node;
    }

    if (list->first == found_node)
    {
        if (list->first == list->last)
        {
            list->first = 0;
            list->last = 0;
            list->length = 0;
        }
        else
        {
            list->first = next_node;
        }
    }

    free(found_node);

    return found_value;
}

void list_clear(FloatList *list)
{
    assert(list != 0);

    size_t length = list->length;

    for (size_t i = 0; i < length; i++)
    {
        list_remove(list, 0);
    }
}

size_t list_length(FloatList *list)
{
    return list->length;
}

void list_foreach(FloatList *list, void (*callback)(float, size_t, FloatList *))
{
    assert(list != 0);

    Node *curr_node = list->first;

    for (size_t i = 0; i < list->length; i++)
    {
        callback(curr_node->value, i, list);
        curr_node = curr_node->next;
    }
}

_float_list_namespace const float_list = {
    list_create,
    list_append,
    list_get,
    list_index,
    list_remove,
    list_clear,
    list_length,
    list_foreach};