# Programs memory maps

## File aliasing_example.c Memory Map – Aliasing and Use-After-Free

### 1. Stack Memory

- `main()`: `a = NULL`, `b = NULL`, `n = 5`.
- `make_numbers()`: `i = 0`, `arr = NULL`.
- All these local variables are stored on the STACK.
- `arr` is a stack pointer; the array it references is on the HEAP.

### 2. Heap Allocation

- `malloc(5 * sizeof(int))` allocates 20 bytes (assuming 4-byte integers).
- The heap array contains: [0, 11, 22, 33, 44].
- `arr` points to the allocated heap memory.
- When `make_numbers()` returns, `arr` and `i` cease to exist, but the heap array remains allocated.
- The returned pointer is assigned to `a`.

### 3. Pointer Aliasing

After `b = a`:

- `a` and `b` contain the same memory address.
- Both point to the same heap allocation.
- `a[2]` and `b[2]` both access the value 22.
- Modifications through either pointer affect the same array.

### 4. After free(a)

- `free(a)` releases the heap allocation.
- The heap memory is no longer valid to access.
- Neither `a` nor `b` is automatically set to `NULL`.
- Both pointers become dangling pointers because they still contain the old address.
- The allocation is freed, even though `b` still contains its address.

- On this last sentence the IA is a bit missleading, as it stated before,
`a` too still holds the adress of the freed allocation. 

### 5. Use-After-Free Errors

- `b[2]`: Invalid read because the memory has been freed.
- `b[3] = 1234`: Invalid write because the memory has been freed.
- Both operations cause undefined behavior.
- Valgrind should report these invalid memory accesses.

### 6. Variable Lifetimes

- `a`, `b`, `n`: STACK, exist until `main()` returns.
- `i`, `arr`: STACK, exist until `make_numbers()` returns.
- Dynamically allocated array: HEAP, exists from successful `malloc()` until `free(a)`.
- The heap allocation outlives the function that created it.

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

- Stack stores local variables and pointers; heap stores dynamically allocated data.
- `a` and `b` are aliases referencing the same allocation.
- Returning from `make_numbers()` destroys its local variables, not the heap array.
- `free(a)` releases the allocation and makes all aliases dangling.
- Accessing freed memory causes undefined behavior.
- To avoid this error, free memory only after all accesses are finished, then set both pointers to `NULL`.


## File crash_example.c Memory Map – NULL Pointer Dereference (Segmentation Fault)

### 1. Stack Memory

- `main()`: `nums = NULL`, `n = 0`.
- `allocate_numbers()`: `arr = NULL`, `i = 0`.
- All local variables are stored on the STACK.
- `arr` and `nums` are pointer variables; they do not themselves store the array.

### 2. Heap Allocation

- `allocate_numbers(n)` receives `n = 0`.
- The condition `if (n <= 0)` is TRUE.
- The function immediately returns `NULL`.
- `malloc()` is never executed.
- No heap memory is allocated.
- The array initialization loop is never executed.

### 3. Pointer Assignment

After `nums = allocate_numbers(n)`:

- `nums` receives the returned value `NULL`.
- `arr` was also `NULL` before the function returned.
- There is no pointer aliasing because no heap allocation exists.
- When `allocate_numbers()` returns, its local variables `arr` and `i` cease to exist.

### 4. NULL Pointer Dereference

The program executes: `nums[0] = 42;`

- `nums` is NULL.
- The program attempts to write to memory through a NULL pointer.
- This causes undefined behavior, typically a segmentation fault.
- The program will normally terminate at this instruction.
- The next `printf()` is not reached during the expected crash.

### 5. Variable Lifetimes

- `nums`, `n`: STACK, exist until `main()` returns or terminates.
- `arr`, `i`: STACK, exist until `allocate_numbers()` returns.
- Heap array: No allocation occurs, so no heap array exists.
- The function's local variables cease to exist when it returns, but `nums` remains in `main()`.

### 6. Memory Map Summary

| Stage | nums | arr | Heap |
| --- | --- | --- | --- |
| Initial | NULL | Not created | Empty |
| Function starts | NULL | NULL | Empty |
| n \<= 0 | NULL | NULL | Empty |
| Function returns | NULL | Destroyed | Empty |
| Assignment | NULL | Destroyed | Empty |
| nums\[0\] = 42 | NULL | Destroyed | Invalid access |
| free(nums) | Not reached | Destroyed | Empty |

### 7. Conclusion

- Stack memory stores local variables and pointers.
- Heap memory would store dynamically allocated arrays, but none is allocated here.
- Since `n = 0`, the function returns NULL before calling malloc().
- `nums` remains NULL after the function call.
- No pointer aliasing occurs.
- Accessing `nums[0]` causes a NULL pointer dereference and typically a segmentation fault.
- `free(nums)` is never reached during the expected crash.
- To fix the problem, check `nums != NULL` before accessing `nums[0]`.


## File heap_example.c Memory Map – Heap Allocations and Memory Leak

### 1. Stack Memory (first attempt)

- `main()`: `alice = NULL`, `bob = NULL`.
- `person_new()`: local variables `i`, `len` and pointer `p`.
- `person_free_partial()`: parameter `p`.
- All local variables and pointer variables are stored on the STACK.
- The `Person` structures and their names are dynamically allocated on the HEAP.

- This part did not talk about `name`and `age`parametters for this reason comes the corrected version.

### 1. Stack Memory (corrected)

- `main()`: `alice = NULL`, `bob = NULL`.
- `person_new()`: parameters `name` (pointer to the input string) and `age` (integer), plus local variables `i`, `len` and pointer `p`.
- `person_free_partial()`: parameter `p` (pointer to Alice's Person structure).
- All local variables, function parameters and pointer variables are stored in their respective STACK frames.
- The string literals `"Alice"` and `"Bob"` have static storage duration; they are not stored on the stack or heap.
- The Person structures and their dynamically allocated name arrays are stored on the HEAP.

### 2. Heap Allocation

- `person_new("Alice", 30)` allocates one `Person` structure and a separate character array for `"Alice"` (6 bytes including `'\0'`).
- `person_new("Bob", 41)` allocates another `Person` structure and a separate character array for `"Bob"` (4 bytes including `'\0'`).
- Each structure contains a `name` pointer and an `age` integer.
- Alice's structure contains `age = 30` and `name = "Alice"`.
- Bob's structure contains `age = 41` and `name = "Bob"`.
- Both structures and both name arrays are stored separately on the HEAP.

### 3. Pointer Assignment and Aliasing

After both function calls:

- `alice` points to Alice's heap structure.
- `bob` points to Bob's heap structure.
- `alice->name` points to Alice's separately allocated name array.
- `bob->name` points to Bob's separately allocated name array.
- There is no pointer aliasing between Alice and Bob because they reference different allocations.
- Inside `person_new()`, `p` temporarily points to the newly allocated structure. Its returned address is copied into `alice` or `bob`.
- The local pointer `p` disappears when `person_new()` returns, but its allocated memory remains alive.

### 4. Freeing Bob's Memory

The program executes:

- `free(bob->name)`: releases Bob's name array.
- `free(bob)`: releases Bob's Person structure.
- Bob's two heap allocations are correctly freed.
- `bob` remains in the STACK but contains a dangling pointer.
- Bob's name allocation is no longer valid.

### 5. Freeing Alice's Memory (Deliberate Memory Leak)

The program executes: `person_free_partial(alice);`

- The function receives Alice's address through its local parameter `p`.
- `free(p)` releases Alice's Person structure.
- However, Alice's separately allocated `name` array is NOT freed.
- The name array remains allocated on the HEAP, but no valid pointer references it anymore.
- This creates a MEMORY LEAK.
- `alice` remains in the STACK but becomes a dangling pointer.

### 6. Variable Lifetimes

- `alice`, `bob`: STACK, exist until `main()` returns.
- `p`, `i`, `len`: STACK, exist only during their respective function calls.
- Alice's Person structure: HEAP, from malloc() until `free(p)`.
- Alice's name array: HEAP, from malloc() until program termination (leaked).
- Bob's Person structure: HEAP, from malloc() until `free(bob)`.
- Bob's name array: HEAP, from malloc() until `free(bob->name)`.

### 7. Memory Map Summary

| Allocation | Contents | Final status |
| --- | --- | --- |
| Alice structure | name pointer, age = 30 | Freed |
| Alice name array | "Alice" | LEAKED |
| Bob structure | name pointer, age = 41 | Freed |
| Bob name array | "Bob" | Freed |

**Final stack state before main returns:**

- `alice`: Dangling pointer.
- `bob`: Dangling pointer.
- Both pointer variables still exist, but neither points to valid allocated memory.

### 8. Conclusion

- Stack memory stores local variables and pointers; heap memory stores dynamically allocated structures and name arrays.
- Each Person structure and its name are separate heap allocations.
- Alice and Bob do not share memory.
- Bob's structure and name are both correctly freed.
- Alice's structure is freed, but her name array is not.
- This causes a memory leak because the allocated name array becomes unreachable.
- The pointers `alice` and `bob` become dangling pointers after their structures are freed.
- To fix the leak, use `free(p->name)` before `free(p)` inside `person_free_partial()`.


## File stack_example.c Memory Map – Recursion and Stack Frames

### 1. Stack Memory

- `main()`: no local variables; calls `walk_stack(0, 3)`.
- `walk_stack()`: parameters `depth`, `max_depth` and local variable `marker`.
- `dump_frame()`: parameters `label` (pointer to a string literal) and `depth`, plus local variables `local_int`, `local_buf[16]` and pointer `p_local`.
- All local variables, arrays, function parameters and pointer variables are stored in their respective STACK frames.
- `label` points to the string literal `"enter"` or `"exit"`, which has static storage duration.
- `p_local` points to `local_int`, which belongs to the same `dump_frame()` stack frame.
No heap allocation occurs in this program.

### 2. Stack Frame Creation and Recursion

- `main()` calls `walk_stack(0, 3)`.
- `walk_stack()` creates its first stack frame with `depth = 0`, `max_depth = 3` and `marker = 0`.
- It calls `dump_frame("enter", 0)`, creating a separate temporary stack frame.
- Since `depth < max_depth`, it recursively calls `walk_stack(1, 3)`.
- This creates another independent stack frame.
- Recursion continues with depths 2 and 3.
- Each recursive call has its own `depth`, `max_depth` and `marker` variables.
- Each call also creates its own `dump_frame()` frame when entering and exiting.

### 3. Pointer Assignment and Aliasing

- Inside dump_frame():

   - p_local = &local_int stores the address of local_int.
   - p_local and &local_int refer to the same variable.
   - local_buf is a local character array stored directly in the stack frame.
   - local_buf[0] contains 'A' + depth, and local_buf[1] contains '\0'.
   - label points to the static string literal "enter" or "exit".
   - No pointers reference heap memory.
   - No pointer aliasing occurs between different recursive frames.

### 4. Recursion and Stack Frame Destruction

- The recursion reaches `depth = 3`, where `depth < max_depth` is FALSE.
- The deepest call executes `dump_frame("exit", 3)`.
- After returning, its stack frame is destroyed.
- Execution continues in the previous frame `(depth = 2)`.
- `dump_frame("exit", 2)` executes before that frame is destroyed.
- The same process continues for `depths 1 and 0`.
- Each recursive call returns independently, following the `LIFO (Last In, First Out)` order.
- Each `dump_frame()` stack frame is destroyed immediately after its function returns.

### 5. Variable Lifetimes

- `depth, max_depth`: STACK, exist during their respective `walk_stack()` calls.
- `marker`: STACK, exists until its corresponding `walk_stack()` call returns.
- `label`: STACK pointer parameter, exists during each `dump_frame()` call.
- String literals `"enter"` and `"exit"`: static storage duration, exist throughout the program.
- `local_int`: STACK, exists during its `dump_frame()` call.
- `local_buf[16]`: STACK, exists during its `dump_frame()` call.
- `p_local`: STACK pointer, exists during its `dump_frame()` call.
- `main()` remains active until the program finishes.

### 6. Memory Map Summary

| Function call | depth | marker | Stack status |
| --- | --- | --- | --- |
| walk_stack(0,3) |	0 |	0 |	Active |
| walk_stack(1,3) |	1 |	10 | Active |
| walk_stack(2,3) |	2 |	20 | Active |
| walk_stack(3,3) |	3 |	30 | Active |
| walk_stack(3,3) returns |	3 |	30 | Destroyed |
| walk_stack(2,3) returns |	2 |	20 | Destroyed |
| walk_stack(1,3) returns |	1 |	10 | Destroyed |
| walk_stack(0,3) returns |	0 |	0 | Destroyed |

- Each dump_frame() call also creates a temporary stack frame containing:

  - `label`
  - `depth`
  - `local_int` = 100 + `depth`
  - `local_buf[16]`
  - `p_local` = `&local_int`

### 7. Conclusion

- Stack memory stores all local variables, parameters, arrays and pointers.
- Each recursive call creates an independent stack frame.
- Every frame has its own `depth`, `max_depth` and `marker`.
- `p_local` points to `local_int` within the same `dump_frame()` frame.
- label points to a string literal with static storage duration.
- No heap memory is allocated in this program.
- No pointer aliasing occurs between different recursive calls.
- Stack frames are destroyed in LIFO order as recursive calls return.
- The exit messages are printed in reverse order: depth 3, 2, 1, then 0.