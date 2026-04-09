*This project has been created as part of the 42 curriculum by mcaro-ro*

# CPP Module 07 – C++ Templates

## 📖 Description
CPP Module 07 introduces function templates and class templates within the C++98 standard.
Across three exercises, you will work with:
 - Generic utility functions
 - Template-based iteration
 - A fully dynamic templated array class

The module focuses on writing reusable, type‑agnostic code and understanding how template instantiation works.

## ⚙️ Instructions
1. Clone the repository from your Git workspace.
2. Navigate into the exercise folder (ex00, ex01, ex02).
3. Compile the project using:
   make
4. Each exercise includes its own main.cpp for testing.
5. Clean build artifacts with:
   make clean
   make fclean
   make re

## 📚 Concepts Covered
1. Function Templates
   - Generic functions that work with any type.
   - Must be defined in header files.
   - Used in ex00 and ex01.

2. Class Templates
   - Generic classes parameterized by type.
   - Must be fully implemented in .hpp or .tpp.
   - Used in ex02.

3. Template Instantiation
   - The compiler generates concrete versions of templates when used.

4. Const‑correctness
   - Especially important in iter(), which must support const and non‑const arrays.

5. Memory Management (ex02)
   - Using new[] and delete[].
   - Implementing deep copy.
   - Throwing exceptions on invalid index access.

## 🧱 Exercises

### ex00 – Function Templates
Implements:
 - swap(T &a, T &b)
 - min(T const &a, T const &b)
 - max(T const &a, T const &b)

All functions must work with any comparable type and be defined in a header.

### ex01 – iter
Implements a function template:
   iter(array, length, function)
Applies a function to each element of an array.
Supports const and non‑const arrays.

### ex02 – Array
Implements a class template Array<T> with:
 - Default constructor
 - Constructor with size
 - Copy constructor
 - Assignment operator
 - Destructor
 - operator[] with bounds checking
 - size() method

Memory must be allocated with new[] and deep‑copied.

