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
