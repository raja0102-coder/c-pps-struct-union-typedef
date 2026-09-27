# PPS Structures vs. Unions & Memory Layout

A Semester 1 Programming for Problem Solving (PPS) C application demonstrating the key architectural differences between `struct` and `union` memory allocation, type aliasing via `typedef`, and shared-memory overlay mechanics.

## PPS Concepts Covered
* **Structure (`struct`) Memory**: Concurrent storage where each member maintains an isolated memory address.
* **Union (`union`) Memory**: Memory sharing where all members share the same base address, reducing total size to the largest member.
* **Type Aliasing (`typedef`)**: Constructing clean domain-specific type names without repeating type tags.
* **Structure Alignment & Padding**: Understanding why compiler memory padding aligns double/int boundaries.

## How to Compile & Run
```bash
gcc main.c -o struct_union_typedef
./struct_union_typedef
