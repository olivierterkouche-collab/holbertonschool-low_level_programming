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


## File crash_example.c Memory Map – NULL Pointer Dereference (Segmentation Fault)

### 1\. Stack Memory

- `main()`: `nums = NULL`, `n = 0`.
- `allocate_numbers()`: `arr = NULL`, `i = 0`.
- All local variables are stored on the STACK.
- `arr` and `nums` are pointer variables; they do not themselves store the array.

### 2\. Heap Allocation

- `allocate_numbers(n)` receives `n = 0`.
- The condition `if (n <= 0)` is TRUE.
- The function immediately returns `NULL`.
- `malloc()` is never executed.
- No heap memory is allocated.
- The array initialization loop is never executed.

### 3\. Pointer Assignment

After `nums = allocate_numbers(n)`:

- `nums` receives the returned value `NULL`.
- `arr` was also `NULL` before the function returned.
- There is no pointer aliasing because no heap allocation exists.
- When `allocate_numbers()` returns, its local variables `arr` and `i` cease to exist.

### 4\. NULL Pointer Dereference

The program executes: `nums[0] = 42;`

- `nums` is NULL.
- The program attempts to write to memory through a NULL pointer.
- This causes undefined behavior, typically a segmentation fault.
- The program will normally terminate at this instruction.
- The next `printf()` is not reached during the expected crash.

### 5\. Variable Lifetimes

- `nums`, `n`: STACK, exist until `main()` returns or terminates.
- `arr`, `i`: STACK, exist until `allocate_numbers()` returns.
- Heap array: No allocation occurs, so no heap array exists.
- The function's local variables cease to exist when it returns, but `nums` remains in `main()`.

### 6\. Memory Map Summary

| Stage | nums | arr | Heap |
| --- | --- | --- | --- |
| Initial | NULL | Not created | Empty |
| Function starts | NULL | NULL | Empty |
| n \<= 0 | NULL | NULL | Empty |
| Function returns | NULL | Destroyed | Empty |
| Assignment | NULL | Destroyed | Empty |
| nums\[0\] = 42 | NULL | Destroyed | Invalid access |
| free(nums) | Not reached | Destroyed | Empty |

### 7\. Conclusion

- Stack memory stores local variables and pointers.
- Heap memory would store dynamically allocated arrays, but none is allocated here.
- Since `n = 0`, the function returns NULL before calling malloc().
- `nums` remains NULL after the function call.
- No pointer aliasing occurs.
- Accessing `nums[0]` causes a NULL pointer dereference and typically a segmentation fault.
- `free(nums)` is never reached during the expected crash.
- To fix the problem, check `nums != NULL` before accessing `nums[0]`.