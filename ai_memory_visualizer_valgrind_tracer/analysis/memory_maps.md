# Programs memory maps

## File aliasing_example.c Memory Map – Aliasing and Use-After-Free

### 1. Stack Memory

main(): a = NULL, b = NULL, n = 5.
make_numbers(): i = 0, arr = NULL.
All these local variables are stored on the STACK.
arr is a stack pointer; the array it references is on the HEAP.

### 2. Heap Allocation

malloc(5 * sizeof(int)) allocates 20 bytes (assuming 4-byte integers).
The heap array contains: [0, 11, 22, 33, 44].
arr points to the allocated heap memory.
When make_numbers() returns, arr and i cease to exist, but the heap array remains allocated.
The returned pointer is assigned to a.

### 3. Pointer Aliasing

After b = a:

a and b contain the same memory address.
Both point to the same heap allocation.
a[2] and b[2] both access the value 22.
Modifications through either pointer affect the same array.

### 4. After free(a)

free(a) releases the heap allocation.
The heap memory is no longer valid to access.
Neither a nor b is automatically set to NULL.
Both pointers become dangling pointers because they still contain the old address.
The allocation is freed, even though b still contains its address.

### 5. Use-After-Free Errors

b[2]: Invalid read because the memory has been freed.
b[3] = 1234: Invalid write because the memory has been freed.
Both operations cause undefined behavior.
Valgrind should report these invalid memory accesses.

### 6. Variable Lifetimes

a, b, n: STACK, exist until main() returns.
i, arr: STACK, exist until make_numbers() returns.
Dynamically allocated array: HEAP, exists from successful malloc() until free(a).
The heap allocation outlives the function that created it.

### 7. Memory Map Summary

| Stage | a | b | Heap |
|-----|-----|-----|-----|
| Initial | NULL | NULL | Empty |
| After malloc | Address X | NULL | Allocated |
| After b = a |	Address X |	Address X | Allocated |
| After free(a) | Dangling | Dangling | Freed |
| After b[2] | Dangling | Dangling | Invalid read |
| After b[3] = 1234 | Dangling | Dangling | Invalid write |

### 8. Conclusion

Stack stores local variables and pointers; heap stores dynamically allocated data.
a and b are aliases referencing the same allocation.
Returning from make_numbers() destroys its local variables, not the heap array.
free(a) releases the allocation and makes all aliases dangling.
Accessing freed memory causes undefined behavior.
To avoid this error, free memory only after all accesses are finished, then set both pointers to NULL.