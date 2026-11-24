# Valgrind Memory Error Analysis Report

## Program: aliasing_example.c
### Tool: Valgrind 3.26.0 (Memcheck)

### 1. Invalid Read – Use-After-Free (Line 42)

- Error type: Invalid read of 4 bytes.
- Memory object: Dynamically allocated integer array of 5 elements (20 bytes).
- Cause: The memory was allocated using malloc() in make_numbers() and released using free(a) at line 38.
- Lifetime violation: Pointer b still references the freed memory because it is an alias of a. Accessing b[2] at line 42 reads memory after it has been freed.
- Invalid address: 0x4a91488 (8 bytes inside the freed block).

### 2. Invalid Write – Use-After-Free (Line 44)

- Error type: Invalid write of 4 bytes.
- Memory object: The same dynamically allocated integer array.
- Cause: The program attempts to modify b[3] after the memory has been released using free(a).
- Lifetime violation: Pointer b is dangling and no longer provides valid access to the allocated array. Writing to b[3] therefore accesses freed memory.
- Invalid address: 0x4a9148c (12 bytes inside the freed block).

### 3. Invalid Read – Use-After-Free (Line 45)

- Error type: Invalid read of 4 bytes.
- Memory object: The same dynamically allocated integer array.
- Cause: The program reads b[3] after attempting to write to it at line 44.
- Lifetime violation: The memory remains freed. The previous invalid write does not restore its lifetime or make pointer b valid.
- Invalid address: 0x4a9148c (12 bytes inside the freed block).

### 4. Memory Leaks

- Error type: No memory leaks detected.
- Memory object: Dynamically allocated integer array.
- Explanation: Valgrind confirms that all heap blocks were freed successfully. The allocated memory was released using free(a).

### 5. Use of Uninitialized Memory

- Error type: No uninitialized memory usage detected.
- Memory object: No uninitialized memory object reported.
- Explanation: Valgrind did not report any use of uninitialized values.

### 6. Final Summary

| Issue | Number |
| --- | --- |
| Invalid reads | 2 |
| Invalid writes | 1 |
| Memory leaks | 0 |
| Uninitialized memory errors | 0 |
| Total errors | 3 |

### 7. Conclusion:

- The main problem is a use-after-free caused by pointer aliasing. Pointers a and b reference the same dynamically allocated memory. After free(a), pointer b becomes dangling but is still used to read and modify the released memory.

- Valgrind reports three invalid memory accesses from three separate contexts. Although all allocated heap memory is freed and no memory leaks are detected, the program exhibits undefined behaviour because it accesses memory after it has been freed.


## Program: crash_example.c
### Tool: Valgrind 3.26.0 (Memcheck)

### 1. Invalid Write – NULL Pointer Dereference (Line 32)

- Error type: Invalid write of 4 bytes.
- Memory object: No valid allocated memory object. The access targets address 0x0 (NULL).
- Cause: The program attempts to write the value 42 to nums[0] when nums is NULL.
- Lifetime violation or misuse: The allocation function returns NULL because the requested size is zero. The program does not check the returned pointer before dereferencing it.
- Invalid address: 0x0.
- Consequence: The invalid write causes a segmentation fault (SIGSEGV), terminating the program.

### 2. Memory Leaks and Heap Summary

- Error type: No definitely lost, indirectly lost or possibly lost memory detected.
- Memory object: One allocated heap block of 1,024 bytes.
- Explanation: Valgrind reports 1,024 bytes as still reachable when the program terminates. This means the allocated block remains accessible through a pointer, but the program terminates before explicitly freeing it.
- Important: Although this is not classified as a definite memory leak, the allocated memory was not released before termination.

### 3. Use of Uninitialized Memory

- Error type: No uninitialized memory usage detected.
- Memory object: No uninitialized memory object reported.
- Explanation: Valgrind did not report any use of uninitialized values.

### 4. Final Summary

| Issue | Result |
| --- | --- |
| Invalid reads | 0 |
| Invalid writes | 1 |
| NULL pointer dereference | 1 |
| Definitely lost memory | 0 bytes |
| Indirectly lost memory | 0 bytes |
| Possibly lost memory | 0 bytes |
| Still reachable memory | 1,024 bytes |
| Uninitialized memory errors | 0 |

### 5. Conclusion:

- The main problem is an invalid write caused by dereferencing a NULL pointer. The allocation function returns NULL when n = 0, but the program attempts to access nums[0] without checking whether the allocation succeeded.

- This causes a segmentation fault (SIGSEGV) and terminates the program.

- Valgrind also reports 1,024 bytes of still reachable memory at termination. No definite, indirect or possible memory leaks and no uninitialized memory errors are reported.

- Total: 1 reported memory error from 1 context.


## Program: heap_example.c
### Tool: Valgrind 3.26.0 (Memcheck)

### 1. Memory Leak – Definitely Lost

- Error type: Definite memory leak.
- Memory object: Dynamically allocated character array containing Alice's name (alice->name), occupying 6 bytes.
- Cause: The memory for Alice's name was allocated using malloc(len + 1) but was never released using free().
- Lifetime violation: The function person_free_partial(alice) only frees the Person structure itself using free(p). It does not free the separately allocated name field.
- Consequence: Once the Person structure is freed, the pointer to the name allocation is lost, making the 6-byte memory block inaccessible.
- Valgrind classification: Definitely lost: 6 bytes in 1 block.

### 2. Invalid Reads and Writes

- Error type: No invalid reads or writes detected.
- Memory object: No invalid memory access reported.
- Explanation: Valgrind reports no invalid memory operations during program execution.

### 3. Use of Uninitialized Memory

- Error type: No uninitialized memory usage detected.
- Memory object: No uninitialized memory object reported.
- Explanation: Valgrind did not report any use of uninitialized values.

### 4. Final Summary

| Issue | Result |
| --- | --- |
| Invalid reads | 0 |
| Invalid writes | 0 |
| Definitely lost memory | 6 bytes |
| Indirectly lost memory | 0 bytes |
| Possibly lost memory | 0 bytes |
| Still reachable memory | 0 bytes |
| Uninitialized memory errors |	0 |
| Total reported errors | 0 |

### 5. Conclusion:

- The main problem is a definite memory leak involving Alice's dynamically allocated name. The person_free_partial() function releases the Person structure but does not release the separately allocated name field.

- As a result, the pointer to Alice's name is lost when the structure is freed, leaving 6 bytes of allocated memory inaccessible.

- Bob's structure and name are both correctly released. No invalid reads, invalid writes or uninitialized memory accesses are reported.

- Note: Valgrind reports 0 memory access errors, but identifies 1 definite memory leak of 6 bytes.


## Program: stack_example.c
### Tool: Valgrind 3.26.0 (Memcheck)

### 1. Invalid Reads and Writes

- Error type: No invalid reads or writes detected.
- Memory object: Stack variables (local_int, local_buf, p_local and marker) in the recursive function calls.
- Explanation: Valgrind reports no invalid memory accesses. All displayed stack variables are accessed while their respective function calls are active.

### 2. Memory Leaks

- Error type: No memory leaks detected.
- Memory object: Heap memory.
- Explanation: Valgrind confirms that all allocated heap memory was freed successfully.
- Heap summary: 1 allocation and 1 deallocation, with 0 bytes remaining at program termination.

### 3. Use of Uninitialized Memory

- Error type: No uninitialized memory usage detected.
- Memory object: No uninitialized memory object reported.
- Explanation: Valgrind did not report any use of uninitialized values.

### 4. Stack Memory and Lifetime

- Memory objects: local_int, local_buf, p_local and marker.
- Explanation: Each recursive call creates its own stack frame with separate local variables. These variables remain valid while their corresponding function calls are active and cease to exist when those calls return.
- Observation: The addresses differ between recursion depths, demonstrating that each call has its own stack frame. No stack lifetime violations are reported.

### 5. Final Summary

| Issue | Result |
| --- | --- |
| Invalid reads | 0 |
| Invalid writes | 0 |
| Memory leaks | 0 |
| Uninitialized memory errors | 0 |
| Remaining heap memory | 0 bytes |
| Total reported errors | 0 |

### 6. Conclusion:

- The program executes without any reported memory errors. Valgrind confirms that all heap allocations are released and no invalid reads, invalid writes or uninitialized memory accesses occur.

- The recursive function creates independent stack frames for each call. Local variables are accessed within their valid lifetimes, and no stack-related memory violations are detected.

- Overall result: 0 errors from 0 contexts.
