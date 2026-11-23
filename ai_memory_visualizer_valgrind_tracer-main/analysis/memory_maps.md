## Memory maps

- file : aliasing_example.c

C PROGRAM MEMORY MAP
====================

STEP 1: INITIALIZATION (main)

STACK
+----------------------+
| main()               |
|----------------------|
| a = NULL             |
| b = NULL             |
| n = 5                |
+----------------------+

HEAP
+----------------------+
| Empty                |
+----------------------+


STEP 2: ENTER make_numbers(5)

STACK
+----------------------+
| main()               |
|----------------------|
| a = NULL             |
| b = NULL             |
| n = 5                |
+----------------------+
| make_numbers()       |
|----------------------|
| n = 5                |
| i = 0                |
| arr = NULL           |
+----------------------+

HEAP
+----------------------+
| Empty                |
+----------------------+


STEP 3: malloc() + FILL ARRAY

STACK
+----------------------+
| main()               |
|----------------------|
| a = NULL             |
| b = NULL             |
| n = 5                |
+----------------------+
| make_numbers()       |
|----------------------|
| n = 5                |
| i = 5                |
| arr = 0x1000         |
+----------------------+      

HEAP                          
+------------------------------+
| Address    Value             |
|------------------------------|
| 0x1000       0               |
| 0x1004      11               |
| 0x1008      22               |
| 0x100C      33               |
| 0x1010      44               |
+------------------------------+


STEP 4: return arr

make_numbers() STACK FRAME DISAPPEARS

STACK
+----------------------+
| main()               |
|----------------------|
| a = 0x1000           |
| b = NULL             |
| n = 5                |
+----------------------+      
                              
HEAP                          
+------------------------------+
| 0x1000 |  0                  |
| 0x1004 | 11                  |
| 0x1008 | 22                  |
| 0x100C | 33                  |
| 0x1010 | 44                  |
+------------------------------+


STEP 5: b = a (ALIASING)

STACK
+----------------------+
| main()               |
|----------------------|
| a = 0x1000 ----------+------+
| b = 0x1000 ----------+---+  |
| n = 5                |   |  |
+----------------------+   |  |
                           |  |
HEAP                       |  |
+--------------------------|--|---+
| 0x1000 |  0  <-----------+--+   |
| 0x1004 | 11                     |
| 0x1008 | 22                     |
| 0x100C | 33                     |
| 0x1010 | 44                     |
+---------------------------------+

a AND b POINT TO THE SAME ARRAY.


STEP 6: free(a)

STACK
+----------------------+
| main()               |
|----------------------|
| a = 0x1000 (DANGLING)|
| b = 0x1000 (DANGLING)|
| n = 5                |
+----------------------+

HEAP
+------------------------------+
| FREED ALLOCATION             |
| 0x1000 - 0x1013              |
| NO LONGER VALID TO ACCESS    |
+------------------------------+


STEP 7: USE-AFTER-FREE

printf("%d", b[2]);  // INVALID READ

b[3] = 1234;         // INVALID WRITE

STACK
+----------------------+
| main()               |
|----------------------|
| a = 0x1000 (DANGLING)|
| b = 0x1000 (DANGLING)|
| n = 5                |
+----------------------+

HEAP
+------------------------------+
| FREED MEMORY                 |
| INVALID READ / WRITE         |
+------------------------------+

VALGRIND: INVALID MEMORY ACCESS
===============================

- file crash_example.c

C PROGRAM MEMORY MAP
====================

STEP 1: INITIALIZATION (main)

STACK
+----------------------+
| main()               |
|----------------------|
| nums = NULL          |
| n = 0                |
+----------------------+

HEAP
+----------------------+
| Empty                |
+----------------------+


STEP 2: ENTER allocate_numbers(0)

STACK
+----------------------+
| main()               |
|----------------------|
| nums = NULL          |
| n = 0                |
+----------------------+
| allocate_numbers()   |
|----------------------|
| n = 0                |
| arr = NULL           |
| i = 0                |
+----------------------+

HEAP
+----------------------+
| Empty                |
+----------------------+


STEP 3: CHECK n <= 0

if (n <= 0)
    return NULL;

Since n = 0, the condition is TRUE.

allocate_numbers() RETURNS NULL.

IMPORTANT:
- malloc() IS NEVER EXECUTED.
- The loop IS NEVER EXECUTED.
- No heap memory is allocated.


STACK
+----------------------+
| main()               |
|----------------------|
| nums = NULL          |
| n = 0                |
+----------------------+
| allocate_numbers()   |
|----------------------|
| DESTROYED            |
| arr = NULL           |
| i = 0                |
| n = 0                |
+----------------------+

HEAP
+----------------------+
| Empty                |
+----------------------+


STEP 4: RETURN TO main()

nums = allocate_numbers(n);

The returned NULL is assigned to nums.

STACK
+----------------------+
| main()               |
|----------------------|
| nums = NULL          |
| n = 0                |
+----------------------+

HEAP
+----------------------+
| Empty                |
+----------------------+


STEP 5: NULL DEREFERENCE

nums[0] = 42;

nums is NULL.

Equivalent operation:

*(nums + 0) = 42;

The program attempts to write to address NULL.

STACK
+----------------------+
| main()               |
|----------------------|
| nums = NULL          |
| n = 0                |
+----------------------+

HEAP
+----------------------+
| Empty                |
+----------------------+

ERROR:
+------------------------------+
| NULL POINTER DEREFERENCE     |
| SEGMENTATION FAULT           |
| UNDEFINED BEHAVIOR           |
+------------------------------+


STEP 6: PROGRAM STOPS

printf("nums[0]=%d", nums[0]);

free(nums);

These statements are NOT reached if the
NULL dereference terminates the program.

===============================
VALGRIND: INVALID WRITE / NULL
POINTER DEREFERENCE
===============================

file - heap_example.c

STEP 1: INITIALIZATION (main)

STACK
+----------------------+
| main()               |
|----------------------|
| alice = NULL         |
| bob   = NULL         |
+----------------------+

HEAP
+----------------------+
| Empty                |
+----------------------+


STEP 2: CREATE ALICE

alice = person_new("Alice", 30);

Inside person_new():

Person *p = malloc(sizeof(Person));

STACK
+----------------------+
| main()               |
|----------------------|
| alice = NULL         |
| bob   = NULL         |
+----------------------+
| person_new()         |
|----------------------|
| name = "Alice"       |
| age = 30             |
| i = 0                |
| len = 0              |
| p = 0x1000 ----------+------+
+----------------------+      |
                              |
HEAP                          |
+------------------------------+
| Person at 0x1000             |
|------------------------------|
| name = ?                     |
| age  = ?                     |
+------------------------------+

A Person structure is allocated.


STEP 3: ALLOCATE ALICE'S NAME

while (name[len] != '\0')
    len++;

Alice has 5 characters.

p->name = malloc(len + 1);

6 bytes are allocated (5 characters + '\0').

STACK
+----------------------+
| person_new()         |
|----------------------|
| name = "Alice"       |
| age = 30             |
| i = 0                |
| len = 5              |
| p = 0x1000           |
+----------------------+

HEAP
+--------------------------------+
| Person at 0x1000               |
|--------------------------------|
| name = 0x2000 -----------------+----+
| age  = 30                     |    |
+--------------------------------+    |
                                      |
| String at 0x2000                    |
|-------------------------------------|
| 'A' | 'l' | 'i' | 'c' | 'e' | '\0' |
+-------------------------------------+


STEP 4: CREATE BOB

bob = person_new("Bob", 41);

Bob has 3 characters.

A second Person structure and a
second string are allocated.

STACK
+----------------------+
| main()               |
|----------------------|
| alice = 0x1000       |
| bob   = 0x3000       |
+----------------------+

HEAP
+--------------------------------+
| Person at 0x1000 (ALICE)       |
|--------------------------------|
| name = 0x2000 -----------------+---+
| age  = 30                     |   |
+--------------------------------+   |
                                     |
| String at 0x2000 (ALICE)           |
|------------------------------------|
| 'A' | 'l' | 'i' | 'c' | 'e' | '\0'|
+------------------------------------+

| Person at 0x3000 (BOB)             |
|------------------------------------|
| name = 0x4000 -----------------+---+
| age  = 41                     |   |
+--------------------------------+   |
                                     |
| String at 0x4000 (BOB)             |
|------------------------------------|
| 'B' | 'o' | 'b' | '\0'             |
+------------------------------------+


STEP 5: FREE BOB'S NAME

free(bob->name);

The string allocation is released.

STACK
+----------------------+
| main()               |
|----------------------|
| alice = 0x1000       |
| bob   = 0x3000       |
+----------------------+

HEAP
+--------------------------------+
| Person at 0x1000 (ALICE)       |
|--------------------------------|
| name = 0x2000 -----------------+---+
| age  = 30                     |   |
+--------------------------------+   |
                                     |
| String at 0x2000 (ALICE)           |
| 'A' | 'l' | 'i' | 'c' | 'e' | '\0'|
+------------------------------------+

| Person at 0x3000 (BOB)             |
|------------------------------------|
| name = DANGLING POINTER            |
| age  = 41                          |
+------------------------------------+

| Bob's string: FREED                |
+------------------------------------+


STEP 6: FREE BOB'S STRUCTURE

free(bob);

Bob's Person structure is released.

STACK
+----------------------+
| main()               |
|----------------------|
| alice = 0x1000       |
| bob   = 0x3000       |
|                       |
| bob = DANGLING        |
+----------------------+

HEAP
+--------------------------------+
| Person at 0x1000 (ALICE)       |
|--------------------------------|
| name = 0x2000 -----------------+---+
| age  = 30                     |   |
+--------------------------------+   |
                                     |
| String at 0x2000 (ALICE)           |
| 'A' | 'l' | 'i' | 'c' | 'e' | '\0'|
+------------------------------------+

| Bob's Person: FREED                |
| Bob's string: FREED                |
+------------------------------------+


STEP 7: FREE ALICE PARTIALLY

person_free_partial(alice);

Inside person_free_partial():

free(p);

IMPORTANT:
The function frees ONLY the Person structure.
It DOES NOT free p->name.

HEAP
+--------------------------------+
| Alice's Person structure       |
| FREED                          |
+--------------------------------+

| Alice's name string            |
| 0x2000                         |
| 'A' | 'l' | 'i' | 'c' | 'e' | '\0' |
| STILL ALLOCATED                |
+--------------------------------+

STACK
+----------------------+
| main()               |
|----------------------|
| alice = 0x1000       |
| bob   = 0x3000       |
|                       |
| Both are dangling    |
+----------------------+


STEP 8: PROGRAM ENDS

return 0;

STACK
+----------------------+
| main() returns       |
|----------------------|
| alice disappears     |
| bob disappears       |
+----------------------+

HEAP
+--------------------------------+
| Bob's Person structure: FREED  |
| Bob's name string: FREED       |
| Alice's Person structure: FREED|
| Alice's name string: LEAKED    |
+--------------------------------+

========================================
VALGRIND:
DEFINITELY LOST: Alice's name allocation
========================================

file - stack_example.c

STEP 1: INITIALIZATION (main)

STACK
+---------------------------+
| main()                    |
|---------------------------|
| No local variables        |
+---------------------------+

HEAP
+---------------------------+
| Empty                     |
+---------------------------+


STEP 2: CALL walk_stack(0, 3)

walk_stack(0, 3);

STACK
+---------------------------+
| main()                    |
+---------------------------+
| walk_stack(depth=0)       |
|---------------------------|
| depth = 0                 |
| max_depth = 3             |
| marker = 0                |
+---------------------------+

HEAP
+---------------------------+
| Empty                     |
+---------------------------+


STEP 3: CALL dump_frame("enter", 0)

dump_frame("enter", 0);

STACK
+---------------------------+
| main()                    |
+---------------------------+
| walk_stack(depth=0)       |
| depth = 0                 |
| max_depth = 3             |
| marker = 0                |
+---------------------------+
| dump_frame(depth=0)       |
|---------------------------|
| label = "enter"           |
| depth = 0                 |
| local_int = 100           |
| local_buf[16]             |
| local_buf = "A"           |
| p_local = &local_int -----+---+
+---------------------------+   |
                                |
                                |
         local_int <------------+

p_local points to local_int.

dump_frame() RETURNS.

Its stack frame disappears.


STEP 4: RECURSION — walk_stack(1, 3)

walk_stack(depth + 1, max_depth);

STACK
+---------------------------+
| main()                    |
+---------------------------+
| walk_stack(depth=0)       |
|---------------------------|
| depth = 0                 |
| max_depth = 3             |
| marker = 0                |
+---------------------------+
| walk_stack(depth=1)       |
|---------------------------|
| depth = 1                 |
| max_depth = 3             |
| marker = 10               |
+---------------------------+

HEAP
+---------------------------+
| Empty                     |
+---------------------------+


STEP 5: RECURSION — walk_stack(2, 3)

STACK
+---------------------------+
| main()                    |
+---------------------------+
| walk_stack(depth=0)       |
| depth = 0                 |
| max_depth = 3             |
| marker = 0                |
+---------------------------+
| walk_stack(depth=1)       |
| depth = 1                 |
| max_depth = 3             |
| marker = 10               |
+---------------------------+
| walk_stack(depth=2)       |
|---------------------------|
| depth = 2                 |
| max_depth = 3             |
| marker = 20               |
+---------------------------+


STEP 6: RECURSION — walk_stack(3, 3)

STACK
+---------------------------+
| main()                    |
+---------------------------+
| walk_stack(depth=0)       |
| depth = 0                 |
| max_depth = 3             |
| marker = 0                |
+---------------------------+
| walk_stack(depth=1)       |
| depth = 1                 |
| max_depth = 3             |
| marker = 10               |
+---------------------------+
| walk_stack(depth=2)       |
| depth = 2                 |
| max_depth = 3             |
| marker = 20               |
+---------------------------+
| walk_stack(depth=3)       |
|---------------------------|
| depth = 3                 |
| max_depth = 3             |
| marker = 30               |
+---------------------------+

RECURSION STOPS.

depth < max_depth

3 < 3 is FALSE.


STEP 7: dump_frame("enter", 3)

A new dump_frame() stack frame is created.

STACK
+---------------------------+
| main()                    |
+---------------------------+
| walk_stack(depth=0)       |
+---------------------------+
| walk_stack(depth=1)       |
+---------------------------+
| walk_stack(depth=2)       |
+---------------------------+
| walk_stack(depth=3)       |
| marker = 30               |
+---------------------------+
| dump_frame(depth=3)       |
|---------------------------|
| label = "enter"           |
| depth = 3                 |
| local_int = 103           |
| local_buf[16] = "D"       |
| p_local = &local_int -----+---+
+---------------------------+   |
                                |
                                +--> local_int = 103

dump_frame() RETURNS.

Its stack frame disappears.


STEP 8: UNWIND RECURSION

The program now returns through the
previous walk_stack() calls.

ORDER OF EXECUTION:

walk_stack(3) -> exit
walk_stack(2) -> exit
walk_stack(1) -> exit
walk_stack(0) -> exit

Each function calls dump_frame("exit", depth).

For each exit call, a NEW dump_frame()
stack frame is created and destroyed.


STACK DURING walk_stack(3) EXIT:

+---------------------------+
| main()                    |
+---------------------------+
| walk_stack(depth=0)       |
| marker = 0                |
+---------------------------+
| walk_stack(depth=1)       |
| marker = 10               |
+---------------------------+
| walk_stack(depth=2)       |
| marker = 20               |
+---------------------------+
| walk_stack(depth=3)       |
| marker = 30               |
+---------------------------+
| dump_frame("exit", 3)     |
| local_int = 103           |
| local_buf = "D"           |
| p_local = &local_int      |
+---------------------------+

dump_frame() RETURNS.

walk_stack(3) RETURNS.


STEP 9: walk_stack(2) EXIT

STACK
+---------------------------+
| main()                    |
+---------------------------+
| walk_stack(depth=0)       |
| marker = 0                |
+---------------------------+
| walk_stack(depth=1)       |
| marker = 10               |
+---------------------------+
| walk_stack(depth=2)       |
| marker = 20               |
+---------------------------+

dump_frame("exit", 2) runs.

local_int = 102
local_buf = "C"
p_local = &local_int

dump_frame() RETURNS.

walk_stack(2) RETURNS.


STEP 10: walk_stack(1) EXIT

STACK
+---------------------------+
| main()                    |
+---------------------------+
| walk_stack(depth=0)       |
| marker = 0                |
+---------------------------+
| walk_stack(depth=1)       |
| marker = 10               |
+---------------------------+

dump_frame("exit", 1) runs.

local_int = 101
local_buf = "B"
p_local = &local_int

dump_frame() RETURNS.

walk_stack(1) RETURNS.


STEP 11: walk_stack(0) EXIT

STACK
+---------------------------+
| main()                    |
+---------------------------+
| walk_stack(depth=0)       |
| marker = 0                |
+---------------------------+

dump_frame("exit", 0) runs.

local_int = 100
local_buf = "A"
p_local = &local_int

dump_frame() RETURNS.

walk_stack(0) RETURNS.


STEP 12: PROGRAM ENDS

main() RETURNS.

STACK
+---------------------------+
| Empty                     |
+---------------------------+

HEAP
+---------------------------+
| Empty                     |
+---------------------------+

NO HEAP ALLOCATIONS.
NO MEMORY LEAKS.