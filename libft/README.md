#	Libft - 42 School Project Lisbon

### Table of Contents
* [Introduction](#introduction-)
* [Project Structure](#project-structure-)
* [Conclusion](#conclusion-)

##	Introduction 📖

Libft is a foundational project at 42 School, where students are tasked with creating their own C library from scratch. The goal is to reimplement essential functions from the standard C library (libc) to better understand how they work under the hood. This custom library will then be reused in several other 42 projects, making it a vital tool for future development.

The Libft project helps students become proficient in key concepts such as memory management, string manipulation, and data structures, all while adhering to strict coding standards. By completing this project, students gain a deep understanding of C language fundamentals and develop skills in creating reusable and efficient code.

##	Project Structure 🏗

The Libft project is divided into several parts:

**Part 1️⃣: Libc Functions**

In this section, students reimplement commonly used functions from the standard C library, such as:

	•	String Manipulation: ft_strlen, ft_strchr, ft_strncmp, ft_strcpy, etc.
	•	Memory Management: ft_memset, ft_memcpy, ft_memmove, ft_calloc, etc.
	•	Character Checking: ft_isalpha, ft_isdigit, ft_isalnum, ft_tolower, etc.

These functions are fundamental for working with strings, memory, and other basic types in C.

**Part 2️⃣: Additional Functions**

This part includes a few utility functions that are not part of the standard library but are still extremely useful:

	•	ft_substr: Extracts a substring from a string.
	•	ft_strjoin: Concatenates two strings into one.
	•	ft_split: Splits a string into an array of strings based on a delimiter.
	•	ft_itoa: Converts an integer to a string.

These functions enhance the basic capabilities provided by the libc functions and offer flexibility in handling more complex operations.

**Part 3️⃣: Bonus - Linked Lists**

As a bonus, students are required to implement a set of functions that manage a singly linked list. These functions include:

	•	ft_lstnew: Creates a new element in a linked list.
	•	ft_lstadd_front: Adds an element to the front of the list.
	•	ft_lstadd_back: Adds an element to the end of the list.
	•	ft_lstclear: Frees all elements in a linked list.

This bonus section introduces dynamic data structures and helps students understand how to manipulate lists in C.

**Learning Objectives**

	•	Mastering C fundamentals: Libft pushes students to understand memory management, pointers, and array handling.
	•	Reusable code: By writing well-organized and modular functions, students learn the importance of reusable code for future projects.
	•	Optimization and efficiency: Writing functions that are both time and space efficient is crucial when dealing with large-scale programs.

Project Importance

Libft is the foundation of many future 42 projects. Once completed, it will serve as a personal library that can be reused in various other tasks, such as pipex, printf, get_next_line, and more. By building a custom library, students learn not only how the standard C library works but also how to extend it with their own utility functions, preparing them for more complex software development tasks.

##	Conclusion ✅

The Libft project is an essential stepping stone for becoming proficient in C programming. It teaches valuable skills in memory management, string manipulation, and dynamic data structures. Once completed, Libft serves as a reusable toolkit that will assist in the successful completion of future projects at 42.

Feel free to explore the code, and if you have any suggestions or improvements, don’t hesitate to open an issue or contribute!