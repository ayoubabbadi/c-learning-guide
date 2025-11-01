# C Language Learning Guide

This repository contains a comprehensive C file (`leran.c`) designed as a hands-on reference guide for learning the C programming language.

## About This Project

This guide is structured into distinct "levels" encapsulated in functions. It is split into two main files:

* `leran.c`: The core guide covering fundamentals (Levels 1-7).
* `leran_advanced.c`: A continuation covering advanced topics (Levels 8-11).

All concepts are demonstrated with clear, commented code examples.

---

### Part 1: `leran.c` (The Fundamentals)

This file covers the essential building blocks of C.

**Topics Covered:**
* **Level 1:** Variables, Data Types, `printf` / `scanf`.
* **Level 2:** Operators, `if`/`else`, `switch`, `for`/`while` loops.
* **Level 3:** Functions, Pointers, and Pass-by-Reference.
* **Level 4:** Arrays (1D, 2D, 3D), Strings, and `<string.h>`.
* **Level 5:** `struct`, `typedef`, `malloc`, and `free`.
* **Level 6:** File I/O (`fopen`, `fprintf`, `fgets`, `fclose`) and Function Pointers.
* **Level 7:** Simulating Object-Oriented Programming (OOP) in C.

---

### Part 2: `leran_advanced.c` (Advanced Topics)

This file explores more complex and specialized features of C.

**Topics Covered:**
* **Level 8:** Specialized Data Types (`enum`, `union`).
* **Level 9:** Preprocessor Directives (`#define`, `#if`, `#ifdef`) and Bitwise Operations (`&`, `|`, `^`, `~`, `<<`, `>>`).
* **Level 10:** Storage Classes (`static`, `extern`) and Command Line Arguments (`argc`, `argv`).
* **Level 11:** A complete data structure implementation: The Linked List.

---

## How to Use

You can clone this repository and compile the files to see the output of every example.

### Compiling Part 1 (Fundamentals)

1.  **Compile:**
    ```bash
    gcc leran.c -o leran
    ```
2.  **Run:**
    * On Linux/Mac: `./leran`
    * On Windows: `leran.exe`

### Compiling Part 2 (Advanced)

This program is designed to accept command-line arguments.

1.  **Compile:**
    ```bash
    gcc leran_advanced.c -o leran_adv
    ```
2.  **Run (without arguments):**
    ```bash
    ./leran_adv
    ```
3.  **Run (with arguments to see the demo):**
    ```bash
    ./leran_adv hello world 123
    ```
