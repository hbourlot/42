#	Pipex - 42 School Project Lisbon

### Table of Contents
* [Introduction](#introduction-)
* [Project Requirements](#project-requirements-)
* [Program Usage](#program-usage-)
* [Key Concepts](#key-concepts-)
* [Bonus Features (if applicable)](#bonus-features-if-applicable-)
* [Conclusion](#conclusion-)
* [Edges Cases](#edges-cases-)

##	Introduction 📖

**Pipex** is a 42 School project designed to replicate the functionality of shell pipelines. Pipelines allow the output of one command to be passed as the input to another command. This project involves creating a program that mimics the behavior of piping multiple commands using redirection.

The goal of **pipex** is to implement the following shell command in C:
```
< infile cmd1 | cmd2 > outfile
```
This means the program will:

1. Read from a file (infile).

2. Pass the output of cmd1 as input to cmd2.

3. Write the output of cmd2 to another file (outfile).

##	Project Requirements 📋

The project focuses on several key concepts:


• **Process creation** using fork().

• **Inter-process communication** using pipes (pipe()).

• **File descriptors management** for redirection using dup2().

• **Execution of commands** using execve().

• Error handling and managing edge cases.

##	Program Usage 💻

To get started, first clone the repository from GitHub:

```
git clone https://github.com/username/pipex.git
cd pipex
make
```

To execute the pipex program, you can use the following syntax:

```
./pipex infile "cmd1" "cmd2" outfile
```

Where:

• infile: The file from which cmd1 will read its input.

• cmd1: The first command to be executed.

• cmd2: The second command, which will take the output of cmd1 as input.

• outfile: The file where the output of cmd2 will be written.

For example:
```
./pipex input.txt "grep something" "wc -l" output.txt
```

This will:

1. Read from input.txt.

2. Execute grep something on the input.

3. Pass the output of grep to wc -l.

4. Write the result to output.txt.


##	Key Concepts 🧠

1. **Pipes:**

• Pipes are used to connect two processes, allowing one to write data that the other can read.

• A pipe is created using the pipe() system call, which returns two file descriptors: one for reading and one for writing.

2. **Redirection:**

• File redirection is used to replace the standard input/output of a command with files.

• The dup2() function is used to duplicate file descriptors for redirection, ensuring that input/output are connected to the appropriate files or pipes.

3. **Forking and Executing:**

• The program creates child processes using fork(), which then execute the desired commands.

• Each child process executes a command using execve(), and its input/output is redirected appropriately using pipes and file descriptors.

4. **Error Handling:**

• Proper error handling is critical in pipex. If a command fails, the program should display an error message and return the appropriate exit code.

• The program checks for errors such as file access issues or invalid commands.

#	Bonus Features (if applicable) 🏅

• **Compilation:**

```
make bonus
```
Once compiled, you can run pipex using the following syntax:

```
./pipex here_doc EOF cmd1 cmd2 outfile
./pipex infile cmd1 cmd2 cmdn... outfile
```

• **Multiple commands:**

The bonus part of the project supports multiple commands in the pipeline. For example:
```
< infile cmd1 | cmd2 | cmd3 > outfile
```

This requires handling a dynamic number of commands, which adds complexity in managing pipes and processes.

• **Here Documents:**

The bonus also includes support for here-documents, which allow input to be provided directly in the command line rather than from a file. This is similar to:
```
<< limiter cmd1 | cmd2 > outfile
```

**Code Structure**

• pipex.c: The main program file that initializes the processes, sets up pipes, and handles file redirection.

• pipex_utils.c: Contains helper functions for path validation, string manipulation, and error handling.

• libft/: A custom library containing useful functions (like those from Libft) for handling strings, memory, and file operations.

##	Conclusion ✅

The pipex project serves as an excellent introduction to Unix system calls, process management, and inter-process communication. It offers a deeper understanding of how the shell operates behind the scenes by allowing you to implement piping functionality from scratch.

Throughout this project, I also explored new libraries and learned valuable concepts related to handling pointers, structures, and data. As a result, I applied different techniques for managing memory addresses in various parts of the code. Although I could have handled them uniformly, I opted to experiment with different approaches to reinforce my learning and gain a deeper understanding of memory management. This hands-on experience helped solidify my understanding of these concepts.

Feel free to explore the code, and if you have any suggestions or find any issues, don’t hesitate to open an issue or contribute!

##	Edges Cases 🧩

The program should handle all commands correctly and behave like the original Unix pipe system.

$> valgrind --trace-children=yes --leak-check=full --show-leak-kinds=all --track-fds=yes

**Call the program without env**
```
 env -i ./pipex in_file "ls" "cat" out_file
 ```

**Check case if unset path**
```
unset PATH
./pipex in_file ls ls out_file
```

```
./pipex in_file "head -n 5" "grep test" "cut -d ' ' -f 1" out_file
./pipex infile "ls -l ../" "wc -l" outfile
```

**Check timeout**
```
./pipex /dev/urandom cat "head -1" outfile
```

# General returns
	•	1: General error (e.g., can’t open the file).
	•	2: Misuse of shell built-ins (but can also be used for command usage errors).
	•	126: Command invoked cannot execute (e.g., permission denied).
	•	127: Command not found.