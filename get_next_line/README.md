# get_next_line - 42 School Project (Lisbon)

## Table of Contents
- [Introduction](#introductio-)
- [Project Objectives](#project-objectives-)
- [Features](#features-)
- [How it Works](#how-it-works-)
- [Learning Outcomes](#learning-outcomes-)
- [Bonus Features](#bonus-features-)
- [Edge Cases](#edge-cases-)
- [Conclusion](#conclusion-)
- [Personal Note](#personal-note-️)

## Introduction 📘

**get_next_line** is a project from 42 School that focuses on implementing a function capable of reading a line from a file descriptor, regardless of its length or size. The function reads the file line-by-line, which allows for sequential reading of text files or any other input. By managing buffers and dynamically allocated memory, the goal is to create a reliable and efficient solution for continuous reading.

This project teaches you how to manipulate file descriptors, manage buffers in C, and properly allocate memory while preventing memory leaks. It also introduces you to handling edge cases in file reading and dynamic memory allocation.

## Project Objectives 🎯

- **Implement Line-by-Line Reading**: Create a function that reads one line at a time from a file descriptor, handling different input sizes.
- **Efficient Buffer Management**: Use buffers to read data from files and manage the process of returning a single line from the buffer.
- **Memory Management**: Ensure that memory is properly allocated and freed without causing memory leaks, especially in cases of large or unknown input sizes.
- **Handle Multiple File Descriptors**: Support reading from different file descriptors in parallel.

## Features 🛠️

1. **Line-by-Line Reading**: The core functionality of `get_next_line` allows reading a single line from a file descriptor with each function call.
2. **Dynamic Memory Allocation**: Handles varying line lengths efficiently with dynamically allocated memory.
3. **Buffer Optimization**: Reads input data into a buffer to minimize system calls and optimize performance.
4. **Multiple File Descriptors**: Supports reading from multiple file descriptors simultaneously, handling each independently.

## How it Works ⚙️

1. **Buffer Management**: The function reads data into a fixed-size buffer and processes it to extract a single line. If the buffer contains more than one line, the remaining data is stored for the next call.
2. **Dynamic Memory Handling**: When a line exceeds the buffer size, `get_next_line` dynamically reallocates memory to accommodate the growing line.
3. **End of File and Error Handling**: The function returns `NULL` when the end of the file is reached or if an error occurs during reading.

## How to Compile 💻

To compile the **mandatory** part of the project, use the following command (with the main uncommented):

**Mandatory**
```bash
cc get_next_line.c get_next_line_utils.c
```
**Bonus**
```bash
cc get_next_line_bonus.c get_next_line_utils_bonus.c
```

## Learning Outcomes 🎓

By completing the **get_next_line** project, you will:

- Understand how to work with file descriptors and read from files efficiently.
- Learn to manage dynamic memory allocation in C, ensuring no memory leaks occur.
- Gain experience in optimizing file reading operations, especially when dealing with different line sizes.
- Improve your ability to handle edge cases, such as incomplete lines, empty files, or large inputs.

## Bonus Features ✨

If you decide to implement bonus features, here are some ideas:

- **Handle Multiple File Descriptors Simultaneously**: Extend `get_next_line` to support reading from multiple file descriptors at the same time.
- **Custom Buffer Size**: Allow the function to handle custom buffer sizes for more flexible file reading performance.
  
## Edge Cases 🧩

- **Empty Files**: Handle files with no content and return the appropriate result.
- **No Newline at EOF**: Handle cases where the last line does not end with a newline character.
- **Large Inputs**: Manage very large lines or files efficiently, ensuring the function can handle extensive data without memory issues.
- **Multiple Calls**: Ensure that repeated calls to `get_next_line` correctly return each subsequent line from the file.

## Conclusion ✅

The **get_next_line** project is a valuable exercise in file manipulation, memory management, and low-level C programming. By completing this project, you will gain a deep understanding of how file reading works at a system level, preparing you for more complex file handling in future projects.

Feel free to explore the code, test the function with different file sizes, or suggest improvements!

## Personal Note ✍️

There's a main function commented out in `get_next_line.c`, along with a `test.txt` file, so you can easily test the program and see how it works. Feel free to uncomment the main function and modify the test file to suit your needs.