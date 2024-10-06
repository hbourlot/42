#	push_swap - 42 School Project (Lisbon)

###	Table of Contents
* [Introduction](#introduction-)
* [Project Objectives](#project-objectives-)
* [How it Works](#how-it-works-)
* [Features](#features-)
* [Edge Cases](#edge-cases-)
* [Learning Outcomes](#learning-outcomes-)
* [Bonus Features](#bonus-features-)
* [Conclusion](#conclusion-)

##	Introduction 📖

push_swap is a project from the 42 School curriculum that challenges students to create a sorting algorithm using two stacks. The goal is to sort a list of numbers with the least number of operations using a predefined set of rules and commands.

This project tests the efficiency of algorithms, data structure manipulation, and the ability to optimize solutions under constraints. The challenge is to handle different sets of integers with varying levels of complexity while aiming for the most efficient solution.

##	Project Objectives 🏆

The objectives of the push_swap project are:

	1.	Create Sorting Algorithms: Develop an algorithm capable of sorting numbers using two stacks (stack A and stack B).
	2.	Minimize Operations: Implement sorting using the fewest possible instructions.
	3.	Implement Push_Swap Commands: Use a specific set of allowed operations, including:
	•	sa, sb, ss - Swap elements in stacks
	•	pa, pb - Push elements between stacks
	•	ra, rb, rr - Rotate stacks upwards
	•	rra, rrb, rrr - Rotate stacks downwards
	4.	Handle Edge Cases: Ensure your solution manages edge cases such as sorted input, reverse-sorted input, duplicates, and more.

##	How it Works 🔧

The push_swap program works in two parts:

	1.	Push_Swap Program: This program sorts the integers using a series of commands (push, swap, rotate) and outputs the series of commands used to achieve the sorting.
	2.	Checker Program (optional): This is a separate program that validates whether the list of commands provided successfully sorts the list of integers. It takes the original numbers and checks if the provided commands correctly result in a sorted stack.

##	Features ✨

	1.	Efficient Sorting Algorithms: You will need to develop algorithms to sort stacks of various sizes, ranging from simple cases (e.g., 3 numbers) to more complex cases (e.g., 500 numbers). The program’s output must be optimized to use the least number of operations possible.
	2.	Command Implementation: You’ll implement the allowed operations (sa, pb, etc.) and use these commands to manipulate the stacks and achieve the final sorted state.
	3.	Edge Case Handling: The program must gracefully handle various edge cases such as:
	•	Already sorted input
	•	Input with only one element
	•	Large sets of numbers
	•	Duplicates (if handled)

##	Edge Cases 🧩

```
./push_swap "" | ./checker ""
./push_swap " " | ./checker " "
./push_swap 9999999999999999999999999999999999999999999999999999999999999999 | ./checker 9999999999999999999999999999999999999999999999999999999999999999
./push_swap +0 | ./checker +0
./push_swap -0 +0 | ./checker -0 +0
./push_swap -0 +0
ARG="4 67 3 999999999999999999999999999999999999999999999999999999" ; ./push_swap $ARG | ./checker $ARG
```

##	Learning Outcomes 🎓

By completing this project, you will:

	•	Gain a deep understanding of sorting algorithms and their efficiencies
	•	Learn how to work with stacks, and manipulate them through basic operations
	•	Develop skills in writing efficient C code, optimizing for speed and performance
	•	Get comfortable with debugging and handling edge cases in complex scenarios

##	Bonus Features ✨

If you decide to implement bonus features, here are some optional improvements to your push_swap project:

	•	Checker Program: Implement a checker program that reads the output of the push_swap program and verifies whether the list was correctly sorted.
	•	Improved Efficiency: Further optimize your sorting algorithm for larger sets of numbers (up to 500) to use fewer operations.
	•	Advanced Sorting Strategies: Implement more sophisticated sorting techniques such as quicksort or mergesort to further minimize operations.

##	Conclusion ✅

The push_swap project is an excellent exercise in algorithm design, optimization, and data structure manipulation. By implementing this project, you will gain valuable insights into how to write efficient, high-performance C code and develop a strong foundation in sorting algorithms and data structure operations.