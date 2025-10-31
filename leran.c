/**************************************************************
 * Filename: leran.c
 * Description: 
 * This file is a "Comprehensive Learning Reference Guide" for the C language.
 * Each "level" of learning is encapsulated in its own function for organization.
 * All functions are called in order from the main() function.
 *
 * How to use:
 * 1. Compile the code: gcc leran.c -o leran
 * 2. Run the executable: ./leran (on Linux/Mac) or leran.exe (on Windows)
 **************************************************************/

// --- Include Essential Libraries ---
#include <stdio.h> // (Standard Input/Output) for I/O like printf and scanf
#include <stdlib.h> // (Standard Library) for memory management like malloc and free
#include <string.h> // (String Library) for handling strings like strlen and strcpy

/* * -----------------------------------------------------------------
 * Level 1: The Bare Essentials
 * -----------------------------------------------------------------
 * This level is the foundation: structure, variables, printing, and reading.
 */
void level_1_basics() {
    printf("\n--- Level 1: The Bare Essentials ---\n");

    // --- 1. Variables & Data Types ---
    // A variable is a "box" in memory to store a value.
    
    int age = 30; // 'int' for whole numbers (integers)
    float salary = 2500.50; // 'float' for decimal numbers
    double pi = 3.14159265; // 'double' for high-precision decimal numbers
    char grade = 'A'; // 'char' for a single character (in single quotes)

    // --- 2. Constants ---
    // Variables whose values cannot be changed, using 'const'
    const int DAYS_IN_WEEK = 7;
    // DAYS_IN_WEEK = 8; // If you uncomment this line, it will cause a compile error

    // --- 3. Printing to the User (printf) ---
    // We use "Format Specifiers" to print variables
    // %d (for int), %f (for float/double), %c (for char)
    // \n means "new line"
    
    printf("Age: %d\n", age);
    printf("Grade: %c\n", grade);
    printf("Salary: %.2f\n", salary); // %.2f means "display only 2 digits after the decimal point"
    printf("Value of Pi: %f\n", pi);
    printf("Days in a week: %d\n", DAYS_IN_WEEK);
    
    // --- 4. Reading User Input (scanf) ---
    // We use 'scanf' to get values from the user.
    // **VERY IMPORTANT:** We use the '&' (address-of) symbol
    // to tell 'scanf' the "address" of the variable to store the value in.
    
    int inputAge;
    printf("Please enter your age: ");
    // scanf("%d", &inputAge); // (Note: I've commented this out so it doesn't pause the program)
    // printf("You entered: %d\n", inputAge);
}

/* * -----------------------------------------------------------------
 * Level 2: Operations & Control Flow
 * -----------------------------------------------------------------
 * How to make the program "think," perform calculations, and make decisions.
 */
void level_2_control_flow() {
    printf("\n--- Level 2: Operations & Control Flow ---\n");

    // --- 1. Arithmetic Operators ---
    int a = 10;
    int b = 3;
    printf("Addition (10 + 3): %d\n", a + b);
    printf("Subtraction (10 - 3): %d\n", a - b);
    printf("Multiplication (10 * 3): %d\n", a * b);
    printf("Division (10 / 3): %d\n", a / b); // int / int gives an int (Result is 3)
    printf("Modulus (10 %% 3): %d\n", a % b); // (10 divided by 3 is 3 with a "remainder" of 1)

    // --- 2. Comparison & Logical Operators ---
    // (1 = true, 0 = false)
    printf("Is 10 == 3 ? %d\n", a == b); // (Equals) -> 0
    printf("Is 10 != 3 ? %d\n", a != b); // (Not equals) -> 1
    printf("Is 10 > 3 ? %d\n", a > b); // (Greater than) -> 1
    
    int age = 20;
    int hasLicense = 1; // (1 = true)
    // (AND - &&) - Both conditions must be true
    printf("Can drive (age > 18 AND hasLicense)? %d\n", (age > 18) && (hasLicense == 1)); // -> 1
    // (OR - ||) - Only one condition needs to be true
    printf("Is minor OR has license? %d\n", (age < 18) || (hasLicense == 1)); // -> 1
    // (NOT - !) - Reverses the state
    printf("Does NOT have license? %d\n", !(hasLicense == 1)); // -> 0

    // --- 3. Conditional Logic (if, else if, else) ---
    int grade = 85;
    if (grade >= 90) {
        printf("Letter Grade: A (Excellent)\n");
    } else if (grade >= 80) { // 85 falls here
        printf("Letter Grade: B (Very Good)\n");
    } else if (grade >= 70) {
        printf("Letter Grade: C (Good)\n");
    } else {
        printf("Letter Grade: F (Fail)\n");
    }
    
    // --- 4. Switch...case structure (Alternative to many else if's) ---
    char rank = 'B';
    switch (rank) {
        case 'A':
            printf("Outstanding performance.\n");
            break; // 'break' is essential to prevent "falling through"
        case 'B':
            printf("Very good performance.\n");
            break;
        default: // 'default' is like 'else' - runs if no case matches
            printf("Other performance.\n");
            break;
    }

    // --- 5. Loops (Repetition) ---
    
    // (for loop) - Use when you know the number of iterations
    printf("For Loop (1 to 5): ");
    for (int i = 1; i <= 5; i++) {
        printf("%d ", i);
    }
    printf("\n");

    // (while loop) - Keeps running as long as the condition is true
    printf("While Loop (Count down from 3): ");
    int j = 3;
    while (j > 0) {
        printf("%d ", j);
        j--; // (j-- is the same as j = j - 1)
    }
    printf("\n");
}

/* * -----------------------------------------------------------------
 * Level 3: Functions & Pointers
 * -----------------------------------------------------------------
 * Organizing code and interacting directly with computer memory.
 */

// --- 1. Functions ---
// A function is a reusable block of code
// (Return Type) (Function Name) (Parameters)
int addNumbers(int num1, int num2) {
    int sum = num1 + num2;
    return sum; // 'return' to send a value back
}

// A (void) function does not return any value
void printGreeting(char name[]) {
    printf("Hello, %s!\n", name);
}

// --- 2. Pointers ---
// A pointer is a variable that stores the "address" of another variable in memory.

// This function accepts a "pointer" to an int variable
// (Pass by Reference)
void addFive(int *numPtr) {
    // *numPtr means "go to the address stored in numPtr and change the value there"
    *numPtr = *numPtr + 5; 
}

void level_3_functions_pointers() {
    printf("\n--- Level 3: Functions & Pointers ---\n");

    // --- Calling Functions ---
    printGreeting("Ayoub"); // Calling a void function
    
    int result = addNumbers(10, 20); // Calling a function that returns a value
    printf("Result of addition (10+20): %d\n", result);

    // --- Using Pointers ---
    int myNumber = 10;
    int *ptr = &myNumber; // 'ptr' now "points to" myNumber

    printf("Original value of myNumber: %d\n", myNumber);
    // 
    printf("Address stored in ptr (myNumber's address): %p\n", ptr);
    printf("Value that ptr points to (*ptr): %d\n", *ptr); // *ptr = "value at the address"
    
    // --- Pass by Reference Example ---
    printf("myNumber before function call: %d\n", myNumber);
    addFive(&myNumber); // We pass the "address" of the variable
    printf("myNumber after function call: %d\n", myNumber); // The original value changed!
}

/* * -----------------------------------------------------------------
 * Level 4: Complex Data Structures (Arrays & Strings)
 * -----------------------------------------------------------------
 * Grouping data: Lists (Arrays) and Text (Strings).
 */
void level_4_complex_data() {
    printf("\n--- Level 4: Complex Data Structures ---\n");

    // --- 1. One-Dimensional Arrays (1D Arrays) ---
    // A list of a single data type (e.g., a list of 5 ints)
    // (Indexing starts at 0)
    int grades[5] = {80, 95, 78, 92, 88};

    // Accessing an element
    printf("The third grade (index 2): %d\n", grades[2]); // 78
    
    // Modifying an element
    grades[0] = 82; // Change the first grade from 80 to 82

    // Looping through an array
    printf("All grades: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", grades[i]);
    }
    printf("\n");

    // --- 2. Strings ---
    // A string is just an "array of type char"
    // It ends with a special character '\0' (Null Terminator) to tell C the string is finished.
    char greeting[] = "Hello"; // C adds the '\0' automatically

    printf("The message is: %s\n", greeting); // %s to print a string
    printf("The first letter (index 0): %c\n", greeting[0]); // 'H'

    // --- 3. The string.h Library ---
    char str1[20] = "Hello";
    char str2[] = "World";
    
    // (strlen) - (String Length) - gets the length (doesn't count \0)
    printf("Length of '%s' is: %zu\n", str1, strlen(str1)); // 5
    
    // (strcat) - (String Concatenation) - joins two strings
    strcat(str1, " "); // str1 is now "Hello "
    strcat(str1, str2); // str1 is now "Hello World"
    printf("Concatenation (strcat): %s\n", str1);
    
    // (strcpy) - (String Copy) - copies a string (we don't use = to copy)
    char copy[20];
    strcpy(copy, "Copied Text");
    printf("Copy (strcpy): %s\n", copy);
    
    // (strcmp) - (String Compare) - compares two strings
    // (Returns 0 if they are identical)
    if (strcmp("Test", "Test") == 0) {
        printf("strcmp: The strings are identical.\n");
    }

    // --- 4. Two-Dimensional Arrays (2D Arrays) ---
    // A table (rows and columns)
    // An array with 2 rows and 3 columns
    int matrix[2][3] = {
        {1, 2, 3}, // Row 0
        {4, 5, 6}  // Row 1
    };
    // 
    printf("Element at Row 1, Column 2: %d\n", matrix[1][2]); // 6

    // --- 5. Three-Dimensional Arrays (3D Arrays) ---
    // A cube (layers, rows, columns)
    int cube[2][2][2] = {
        { {1, 2}, {3, 4} }, // Layer 0
        { {5, 6}, {7, 8} }  // Layer 1
    };
    printf("3D Element (Layer 1, Row 0, Col 1): %d\n", cube[1][0][1]); // 6
}

/* * -----------------------------------------------------------------
 * Level 5: Custom Structures & Memory Management
 * -----------------------------------------------------------------
 * Creating your own data types (Structs) and managing memory manually.
 */

// --- 1. Structures (struct) ---
// Used to group different data types into one "object"
struct Student {
    char name[50];
    int id;
    float gpa;
};
// 

// --- 2. Typedef (Alias) ---
// Used to give a nickname to a data type
typedef struct Student Student_t; // Now we can write Student_t instead of struct Student

void level_5_structs_memory() {
    printf("\n--- Level 5: Structs & Memory Management ---\n");

    // --- Using a struct ---
    // (Static allocation)
    struct Student s1;
    strcpy(s1.name, "Ahmed");
    s1.id = 101;
    s1.gpa = 3.8;

    // Access members using '.' (the dot operator)
    printf("Student (s1) Name: %s, ID: %d\n", s1.name, s1.id);
    
    // Using the typedef (easier)
    Student_t s2;
    strcpy(s2.name, "Fatima");
    s2.id = 102;

    // --- 3. Dynamic Memory Allocation ---
    // Used when we don't know the size of data at compile-time
    // (malloc) - (Memory Allocation) - reserves memory
    
    int *dynamicArray;
    int size = 5;
    
    // Reserve memory space for 5 int variables
    dynamicArray = (int*) malloc(size * sizeof(int));
    
    if (dynamicArray == NULL) { // Always check if allocation succeeded
        printf("Failed to allocate memory!\n");
        return;
    }
    
    // Use the allocated memory
    for(int i = 0; i < size; i++) {
        dynamicArray[i] = i * 10;
    }
    printf("Dynamic Array: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", dynamicArray[i]);
    }
    printf("\n");
    
    // (free) - (THE MOST IMPORTANT!) - Must release memory when done
    free(dynamicArray);
    
    // --- 4. Pointers to Structs ---
    Student_t *s3_ptr;
    s3_ptr = (Student_t*) malloc(sizeof(Student_t)); // Allocate memory for one struct
    
    // We use '->' (the arrow operator) to access members via a pointer
    strcpy(s3_ptr->name, "Ali");
    s3_ptr->id = 103;
    
    printf("Student (s3_ptr): %s, ID: %d\n", s3_ptr->name, s3_ptr->id);
    
    free(s3_ptr); // Free the struct's memory
}

/* * -----------------------------------------------------------------
 * Level 6: Advanced Topics
 * -----------------------------------------------------------------
 * File I/O, Function Pointers.
 */
void level_6_advanced_topics() {
    printf("\n--- Level 6: Advanced Topics ---\n");

    // --- 1. File I/O (Input/Output) ---
    // We use a 'FILE' pointer
    FILE *file_ptr;

    // --- a. Writing to a file (Write Mode 'w') ---
    // 'w' (write): Creates a new file or erases an existing file's contents
    file_ptr = fopen("test.txt", "w");
    
    if (file_ptr == NULL) {
        printf("Could not open file for writing!\n");
        return;
    }
    
    // (fprintf) - Like printf, but prints to a file
    fprintf(file_ptr, "Hello, this is line 1.\n");
    fprintf(file_ptr, "This is line 2, with number %d.\n", 100);
    
    fclose(file_ptr); // Always close the file
    printf("Successfully wrote to 'test.txt'.\n");

    // --- b. Reading from a file (Read Mode 'r') ---
    // 'r' (read): Opens an existing file for reading
    file_ptr = fopen("test.txt", "r");
    
    if (file_ptr == NULL) {
        printf("Could not open file for reading!\n");
        return;
    }

    char lineBuffer[100]; // Temporary storage for a line
    
    printf("Contents of 'test.txt':\n");
    // (fgets) - (File Get String) - reads a full line from the file
    // (EOF - End Of File)
    while (fgets(lineBuffer, sizeof(lineBuffer), file_ptr) != NULL) {
        printf("%s", lineBuffer); // Print the line we just read
    }
    
    fclose(file_ptr); // Close the file
    
    // --- c. Appending to a file (Append Mode 'a') ---
    // 'a' (append): Opens a file to write at the *end* without erasing
    file_ptr = fopen("test.txt", "a");
    fprintf(file_ptr, "This is an appended line 3.\n");
    fclose(file_ptr);

    // --- 2. Function Pointers ---
    // A variable that stores the "address" of a function
    
    // Declare a function pointer named 'calcPtr'
    // It can point to any function that takes (int, int) and returns int
    int (*calcPtr)(int, int); 
    
    // 'calcPtr' now points to our 'addNumbers' function (from Level 3)
    calcPtr = &addNumbers;
    
    // Call the function "through the pointer"
    int sum = calcPtr(50, 30);
    printf("Function pointer result (50+30): %d\n", sum);
}

/* * -----------------------------------------------------------------
 * Level 7: Simulating OOP (Object-Oriented Programming)
 * -----------------------------------------------------------------
 * C is a procedural language, but we can "simulate" OOP concepts.
 */

// --- 1. Create the "Class" using a struct ---
// We combine data (Attributes) and functions (Methods)

typedef struct Car_t {
    // Attributes (Data)
    char model[50];
    int year;
    int speed;
    
    // Methods (Function Pointers)
    void (*printDetails)(struct Car_t *self); // (struct Car_t *self) to simulate 'this'
    void (*accelerate)(struct Car_t *self, int amount);
    
} Car;

// --- 2. Define the "Method" functions ---
void car_printDetails(struct Car_t *self) {
    Car *thisCar = (Car*)self; // Cast the generic pointer
    printf("Car Model: %s, Year: %d, Speed: %d\n", 
           thisCar->model, thisCar->year, thisCar->speed);
}

void car_accelerate(struct Car_t *self, int amount) {
    Car *thisCar = (Car*)self;
    thisCar->speed += amount;
    printf("%s is accelerating to %d km/h\n", thisCar->model, thisCar->speed);
}

// --- 3. The "Constructor" ---
// A function to create a new "object"
Car createCar(char model[], int year) {
    Car newCar;
    
    // Assign data
    strcpy(newCar.model, model);
    newCar.year = year;
    newCar.speed = 0;
    
    // Link the method pointers to the actual functions
    newCar.printDetails = &car_printDetails;
    newCar.accelerate = &car_accelerate;
    
    return newCar;
}

void level_7_oop_simulation() {
    printf("\n--- Level 7: Simulating OOP in C ---\n");
    
    // --- Create an "Object" ---
    Car myCar = createCar("Tesla Model S", 2024);
    
    // --- Call the "Methods" ---
    // We pass the address of 'myCar' to act as 'self' or 'this'
    myCar.printDetails(&myCar); 
    
    myCar.accelerate(&myCar, 50);
    myCar.accelerate(&myCar, 30);
    
    myCar.printDetails(&myCar); // Print the new state
}


/* * =================================================================
 * MAIN FUNCTION
 * =================================================================
 * This is the true starting point of the program.
 * It will call all the level functions one by one.
 */
int main() {
    printf("===========================================\n");
    printf("Welcome to your C Language Reference Guide\n");
    printf("===========================================\n");

    // Call all levels in order
    level_1_basics();
    level_2_control_flow();
    level_3_functions_pointers();
    level_4_complex_data();
    level_5_structs_memory();
    level_6_advanced_topics();
    level_7_oop_simulation();

    printf("\n===========================================\n");
    printf("Reference Guide complete. End of program.\n");
    printf("===========================================\n");
    
    // return 0 means the program finished successfully
    return 0;
}