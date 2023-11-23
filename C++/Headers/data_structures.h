/*
    Practise on implementing user-defined data structures.
    The style of the interface and the implementation details
    is personal style, however, it is inspired by the interface
    and the implementation of the STL.
    Implementation the full interface of the STL
    is not possible by a one person.
    The first verson will not include iterators.

    The implemented data structures includes
    1. Vector (array based).
    2. List (double linked list).
    3. Stack.
    4. Queue.
*/
#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

#include "vector.h"
#include "list.h"
#include "stack.h"
#include "queue.h"
/*
    Done for  the ease of compiling the data
    structure usage cpp file, could be removed without 
    an error.
    The cpp files are guarded with safe gurads of their own to prevent
    duplicate definition problem.
*/
#include "../CPP/vector.cpp"
#include "../CPP/list.cpp"
#include "../CPP/stack.cpp"
#include "../CPP/queue.cpp"

#endif