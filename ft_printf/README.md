#	ft_printf - 42 School Project (Lisbon)

### Table of Contents
* [Introduction](#introduction-)
* [Project Objectives](#project-objectives-)
* [Features](#features-)
* [Code Structure](#code-structure-)
* [Learning Outcomes](#learning-outcomes-)
* [Conclusion](#conclusion-)
* [Working with Variadic Functions](#working-with-variadic-functions-)
* [Personal Notes](#personal-notes-)

##	Introduction 📖

ft_printf is a 42 School project that challenges students to reimplement the standard printf() function in C. The goal of this project is to recreate the versatility and functionality of the original printf, including handling various data types and formatting options, without relying on the standard library’s printf function.

This project provides a deep understanding of variadic functions, formatting, and string manipulation in C, while emphasizing the importance of writing efficient and reliable code.

##	Project Objectives 🎯

The ft_printf project aims to:

	1.	Recreate printf() functionality: Implement a custom version that can handle a variety of format specifiers and convert them appropriately.
	2.	Work with Variadic Arguments: Learn to handle an unknown number of arguments passed into the function using stdarg.h in C.
	3.	Memory Management: Efficiently manage memory for dynamic output such as strings and numbers.
	4.	Formatting: Handle various data types and format specifiers, including:
	•	%c: Characters
	•	%s: Strings
	•	%d and %i: Signed integers
	•	%u: Unsigned integers
	•	%x and %X: Hexadecimal (lowercase and uppercase)
	•	%p: Pointers
	•	%%: Percent symbol

##	Features 🧑‍🔧

	1.	Support for Basic Format Specifiers:
	•	The core functionality includes handling format specifiers for integers, characters, strings, pointers, and unsigned numbers in both decimal and hexadecimal forms.
	2.	Variadic Functionality:
	•	ft_printf uses the stdarg.h library to manage variadic arguments, which allows it to handle a variable number of arguments passed to the function, just like the original printf.
	3.	Precision and Width Handling:
	•	The project also supports width and precision modifiers to format the output properly, such as right-aligning or padding numbers and strings to a certain length.
	4.	Efficiency:
	•	One of the key objectives is to ensure that the function is efficient and manages memory properly, preventing memory leaks and handling large inputs smoothly.

##	Code Structure 🏗️

	•	ft_utils1.c: This file contains the main ft_printf function, which parses the format string and handles different format specifiers using variadic arguments. It also includes ft_format() to process specifiers like %c, %s, %p, %d, %i, %u, %x, %X, and %%. Additionally, utility functions like ft_str_len are used for string length calculations.
	•	ft_utils2.c: This file contains auxiliary functions such as ft_putchar for outputting characters, ft_putstr for printing strings, and handle_flags for handling number formatting in various bases (e.g., hexadecimal, pointer formatting %p). It also includes the logic for managing negative numbers and hexadecimal conversions.

##	Learning Outcomes 🎓

By completing ft_printf, you will:

	•	Gain a deeper understanding of variadic functions in C.
	•	Learn how to implement advanced string formatting and parsing logic.
	•	Improve your skills in efficient memory management and system-level programming.
	•	Master the handling of various data types in C, from basic integers and characters to pointers and hexadecimal numbers.

##	Conclusion ✅

The ft_printf project is a fundamental building block in the 42 curriculum, providing a strong foundation in variadic functions, string formatting, and efficient C programming. With this custom printf implementation, I’ve gained key insights into how one of the most commonly used C functions operates under the hood.

Feel free to check out the code, test the functionality, or suggest improvements!

##	Working with Variadic Functions 🔄

In the ft_printf project, variadic functions are used to handle an unknown number of arguments. Here’s a brief overview of the key components involved:

	•	va_list: A type used to hold information about the variable arguments. It is typically declared as ap (argument pointer) and points to the first argument.
	•	va_start: Initializes the va_list object to point to the first argument in the list, allowing you to start accessing the arguments.
	•	va_arg: Retrieves the next argument in the list of variable arguments, moving the pointer forward for subsequent calls.

These macros and facilities are provided by the standard C library and are essential for handling functions like ft_printf that accept a variable number of arguments.

## Personal Notes 📒

I’ve included a main function in the code, commented out with a couple of test cases (made by my friend TimTim 😄🇬🇧), in case you’d like to use it for testing. Feel free to uncomment and modify the tests to suit your needs.