#include <stdio.h>
#include <string.h>

// 1. Structure definition: Members occupy distinct contiguous memory
typedef struct {
    int id;          // 4 bytes
    char grade;      // 1 byte + 3 bytes padding
    double gpa;      // 8 bytes
} StudentStruct;

// 2. Union definition: Members share the exact same memory space
typedef union {
    int intVal;      // 4 bytes
    float floatVal;  // 4 bytes
    char strVal[20]; // 20 bytes (union size = size of largest member)
} DataUnion;

int main() {
    printf("==================================================\n");
    printf("  PPS STRUCTURES vs UNIONS & MEMORY LAYOUT ENGINE \n");
    printf("==================================================\n\n");

    // 1. Memory Size Comparison
    printf("[1] MEMORY ALLOCATION COMPARISON:\n");
    printf("    sizeof(StudentStruct) : %zu bytes (Cumulative members + alignment padding)\n", 
           sizeof(StudentStruct));
    printf("    sizeof(DataUnion)     : %zu bytes (Sized to fit largest single member)\n\n", 
           sizeof(DataUnion));

    // 2. Structure Behavior (All members retain their values simultaneously)
    printf("[2] STRUCTURE MEMBER ISOLATION:\n");
    StudentStruct s1;
    s1.id = 101;
    s1.grade = 'A';
    s1.gpa = 3.85;

    printf("    Student Struct -> ID: %d | Grade: %c | GPA: %.2f\n", 
           s1.id, s1.grade, s1.gpa);
    printf("    Member Addresses:\n");
    printf("      &s1.id    : %p\n", (void*)&s1.id);
    printf("      &s1.grade : %p\n", (void*)&s1.grade);
    printf("      &s1.gpa   : %p\n\n", (void*)&s1.gpa);

    // 3. Union Behavior (Shared Memory Overlay)
    printf("[3] UNION SHARED MEMORY OVERLAY:\n");
    DataUnion u;

    u.intVal = 42;
    printf("    Assigned u.intVal = 42\n");
    printf("      u.intVal   : %d\n", u.intVal);
    printf("      Address    : %p\n\n", (void*)&u.intVal);

    // Overwriting memory with float value
    u.floatVal = 3.14159f;
    printf("    Assigned u.floatVal = 3.14159f (Overwrites shared memory)\n");
    printf("      u.floatVal : %.5f\n", u.floatVal);
    printf("      u.intVal   : %d (Corrupted due to shared overlay)\n", u.intVal);
    printf("      Address    : %p\n\n", (void*)&u.floatVal);

    // Overwriting memory with string
    strcpy(u.strVal, "PPS C Engine");
    printf("    Assigned u.strVal = \"PPS C Engine\"\n");
    printf("      u.strVal   : \"%s\"\n", u.strVal);
    printf("      Address    : %p\n", (void*)u.strVal);

    printf("\n==================================================\n");

    return 0;
}
