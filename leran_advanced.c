/**************************************************************
 * Filename: leran_advanced.c
 * Description: 
 * This file is the "Advanced Topics" guide for the C language.
 * It covers specialized data types, preprocessor directives,
 * bitwise operations, storage classes, CLI arguments,
 * and a full linked list implementation.
 *
 * How to use (with Command Line Args):
 * 1. Compile: gcc leran_advanced.c -o leran_adv
 * 2. Run without args: ./leran_adv
 * 3. Run with args:    ./leran_adv hello world 123
 **************************************************************/

#include <stdio.h>
#include <stdlib.h> // For malloc, free
#include <string.h> // For strcpy

// --- Level 9: Preprocessor Directives ---
// These are processed *before* the code is compiled.

// 1. #define (Macros)
// Used to define constants. The preprocessor replaces every
// instance of 'PI' with '3.14159' textually.
#define PI 3.14159
// 

// Macros can also be function-like.
// This is NOT a function call; it's a text replacement.
#define SQUARE(x) ((x) * (x))

// 2. Conditional Compilation
// Used to include or exclude code blocks.
// This is very common for debugging.
#define DEBUG_MODE 1 // Try changing this to 0

/* * -----------------------------------------------------------------
 * Level 8: Specialized Data Types (enum & union)
 * -----------------------------------------------------------------
 */
void level_8_data_types_ext() {
    printf("\n--- Level 8: Specialized Data Types (enum & union) ---\n");

    // --- 1. enum (Enumeration) ---
    // Creates a new type for a list of named integer constants.
    // It makes code much more readable than using raw numbers.
    // 
    enum Day {
        MONDAY,    // = 0 by default
        TUESDAY,   // = 1
        WEDNESDAY, // = 2
        THURSDAY,  // = 3
        FRIDAY,    // = 4
        SATURDAY,  // = 5
        SUNDAY     // = 6
    };
    
    // You can also assign values manually
    enum Status {
        PENDING = 10,
        APPROVED = 20,
        REJECTED = 30
    };

    enum Day today = WEDNESDAY;
    enum Status orderStatus = APPROVED;
    
    printf("Today (as an int): %d\n", today); // Prints 2
    printf("Order Status (as an int): %d\n", orderStatus); // Prints 20

    if (today == SATURDAY || today == SUNDAY) {
        printf("It's the weekend!\n");
    } else {
        printf("It's a weekday.\n");
    }

    // --- 2. union (Union) ---
    // A data structure that stores *different* data types
    // in the *same* memory location.
    // Only ONE member can be active at a time.
    // The size of the union is the size of its *largest* member.
    // 
    union Data {
        int i;
        float f;
        char c;
    };

    union Data myData;
    
    // 1. Store an int
    myData.i = 100;
    printf("Stored as int: %d\n", myData.i); // OK
    
    // 2. Store a float (this *overwrites* the int)
    myData.f = 3.14;
    printf("Stored as float: %f\n", myData.f); // OK
    
    // 3. Try to access the int again (CORRUPTED DATA)
    // The memory now holds a float, so reading it as an int gives garbage.
    printf("Reading int after storing float: %d (Garbage!)\n", myData.i);
    
    // 4. Store a char (this *overwrites* the float)
    myData.c = 'A';
    printf("Stored as char: %c\n", myData.c); // OK
}

/* * -----------------------------------------------------------------
 * Level 9: Preprocessor & Bitwise Operations
 * -----------------------------------------------------------------
 */
void level_9_preprocessor_bitwise() {
    printf("\n--- Level 9: Preprocessor & Bitwise Operations ---\n");
    
    // --- 1. Using #define Macros (from top of file) ---
    double radius = 10.0;
    double area = PI * radius * radius;
    printf("Area with PI macro: %f\n", area);
    
    // The preprocessor expands SQUARE(5) to ((5) * (5))
    printf("SQUARE(5) macro: %d\n", SQUARE(5));
    // Note: The extra parentheses are crucial for safety.
    printf("SQUARE(1 + 4) expands to ((1 + 4) * (1 + 4)): %d\n", SQUARE(1 + 4));

    // --- 2. Using Conditional Compilation (from top of file) ---
    printf("Checking for DEBUG_MODE...\n");
    #if DEBUG_MODE == 1
        // This code block is *only* included if DEBUG_MODE is 1
        printf("DEBUG: Debug mode is ON. (This line is from a #if block)\n");
    #else
        // This block is included if the #if is false
        printf("DEBUG: Debug mode is OFF.\n");
    #endif

    #ifdef PI
        // This block is included if PI is defined at all
        printf("DEBUG: PI is defined. (This line is from an #ifdef block)\n");
    #endif

    // --- 3. Bitwise Operations ---
    // Manipulating the individual bits (0s and 1s) of integers.
    // We'll use 8-bit unsigned chars for simple examples.
    // 5 in binary (8-bit) = 00000101
    // 3 in binary (8-bit) = 00000011
    
    unsigned char a = 5;  // 00000101
    unsigned char b = 3;  // 00000011
    
    // & (Bitwise AND) - 1 only if *both* bits are 1
    //   00000101
    // & 00000011
    // ----------
    //   00000001  (Result is 1)
    // 
    printf("Bitwise AND (5 & 3): %d\n", a & b); // 1

    // | (Bitwise OR) - 1 if *either* bit is 1
    //   00000101
    // | 00000011
    // ----------
    //   00000111  (Result is 7)
    printf("Bitwise OR (5 | 3): %d\n", a | b); // 7

    // ^ (Bitwise XOR) - 1 if bits are *different*
    //   00000101
    // ^ 00000011
    // ----------
    //   00000110  (Result is 6)
    printf("Bitwise XOR (5 ^ 3): %d\n", a ^ b); // 6
    
    // ~ (Bitwise NOT) - Flips all bits
    // ~ 00000101
    // ----------
    //   11111010  (Result is 250 for unsigned char)
    printf("Bitwise NOT (~5): %d\n", (unsigned char)(~a)); // 250

    // << (Left Shift) - Shifts bits left (multiplies by 2)
    // 5 << 1  (00000101 -> 00001010) (Result is 10)
    printf("Left Shift (5 << 1): %d\n", a << 1); // 10

    // >> (Right Shift) - Shifts bits right (divides by 2)
    // 5 >> 1  (00000101 -> 00000010) (Result is 2)
    printf("Right Shift (5 >> 1): %d\n", a >> 1); // 2
}

/* * -----------------------------------------------------------------
 * Level 10: Storage Classes & Command Line Arguments
 * -----------------------------------------------------------------
 */

// --- 1. Storage Classes ---

// (extern)
// This tells the compiler that 'global_var' *exists*, but is
// *defined* in another .c file. We can't demo this in one file.
// extern int global_var_from_another_file;

// (static - global)
// This variable is global, but its visibility is
// *restricted* to only this file (leran_advanced.c).
// Another .c file cannot access it, even with 'extern'.
static int file_scope_var = 100;

// (static - local)
// This function demonstrates a static local variable.
void static_counter_function() {
    // This variable is initialized *only once*.
    // Its value is *preserved* between function calls.
    static int counter = 0;
    
    counter++;
    printf("Static counter is now: %d\n", counter);
}

void level_10_storage_cli() {
    printf("\n--- Level 10: Storage Classes & CLI Arguments ---\n");
    
    printf("File-scope static var: %d\n", file_scope_var);
    
    // Demonstrate static local variable
    printf("Calling static_counter_function 3 times:\n");
    static_counter_function(); // counter becomes 1
    static_counter_function(); // counter becomes 2
    static_counter_function(); // counter becomes 3
    
    // Command Line Arguments are handled in main()
    printf("See the 'main' function for the CLI argument demo.\n");
}

/* * -----------------------------------------------------------------
 * Level 11: Full Data Structure Example: Linked List
 * -----------------------------------------------------------------
 * A linked list is a fundamental data structure. It's a chain
 * of 'nodes', where each node contains data and a pointer
 * to the next node in the chain.
 * 
 */

// --- 1. Define the Node Structure ---
// This is a self-referential struct.
typedef struct Node {
    int data; // The data we are storing
    struct Node *next; // A pointer to the *next* node in the list
} Node_t;

// --- 2. Function to create a new node ---
Node_t* create_node(int data) {
    // 1. Allocate memory for the new node
    Node_t *newNode = (Node_t*) malloc(sizeof(Node_t));
    if (newNode == NULL) {
        printf("Error: malloc failed in create_node\n");
        return NULL;
    }
    // 2. Set its data
    newNode->data = data;
    // 3. Initialize its 'next' pointer to NULL (it's the end for now)
    newNode->next = NULL;
    return newNode;
}

// --- 3. Function to print the entire list ---
// 'head' is a pointer to the *first* node in the list.
void print_list(Node_t *head) {
    Node_t *current = head; // Start at the beginning
    
    printf("List: [ ");
    while (current != NULL) { // Loop until we reach the end
        printf("%d -> ", current->data);
        current = current->next; // Move to the next node
    }
    printf("NULL ]\n");
}

// --- 4. Function to insert a node at the front ---
// We need a **pointer to the head pointer** (**Node_t)
// because we might need to *change* which node is the head.
void insert_at_front(Node_t **head, int data) {
    // 1. Create the new node
    Node_t *newNode = create_node(data);
    
    // 2. Set the new node's 'next' to point to the *current* head
    newNode->next = *head;
    
    // 3. Update the head pointer to be our new node
    *head = newNode;
}

// --- 5. Function to free the entire list (cleanup) ---
void free_list(Node_t *head) {
    Node_t *current = head;
    Node_t *temp;
    
    printf("Freeing list memory...\n");
    while (current != NULL) {
        temp = current; // Save the current node
        current = current->next; // Move to the next one
        free(temp); // Free the one we saved
    }
    printf("List freed.\n");
}

void level_11_linked_list() {
    printf("\n--- Level 11: Full Data Structure: Linked List ---\n");

    // 'head' is the pointer to the *start* of our list.
    // It starts as NULL because the list is empty.
    Node_t *head = NULL;
    
    print_list(head); // Should show an empty list
    
    // Insert 10. List: [ 10 -> NULL ]
    insert_at_front(&head, 10);
    print_list(head);
    
    // Insert 20. List: [ 20 -> 10 -> NULL ]
    insert_at_front(&head, 20);
    print_list(head);
    
    // Insert 30. List: [ 30 -> 20 -> 10 -> NULL ]
    insert_at_front(&head, 30);
    print_list(head);

    // Always clean up your memory!
    free_list(head);
}


/* * =================================================================
 * MAIN FUNCTION (with Command Line Arguments)
 * =================================================================
 * int argc: (Argument Count) Number of strings passed.
 * char *argv[]: (Argument Vector) An array of strings.
 *
 * argv[0] is *always* the name of the program itself.
 * 
 */
int main(int argc, char *argv[]) {
    printf("===========================================\n");
    printf("Welcome to your C Language Advanced Guide\n");
    printf("===========================================\n");

    // --- Part of Level 10: Command Line Arguments Demo ---
    printf("\n--- (From Level 10): CLI Arguments Demo ---\n");
    printf("Program name (argv[0]): %s\n", argv[0]);
    printf("Number of arguments (argc): %d\n", argc);
    
    // Loop through all *other* arguments (start from i=1)
    if (argc > 1) {
        printf("Arguments passed:\n");
        for (int i = 1; i < argc; i++) {
            printf("  argv[%d]: %s\n", i, argv[i]);
        }
    } else {
        printf("No extra arguments were passed.\n");
    }
    
    // --- Call all other levels ---
    level_8_data_types_ext();
    level_9_preprocessor_bitwise();
    level_10_storage_cli(); // Will print the static demo
    level_11_linked_list();

    printf("\n===========================================\n");
    printf("Advanced Reference Guide complete. End of program.\n");
    printf("===========================================\n");
    
    return 0;
}