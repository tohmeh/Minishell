# minishell  
A simple Unix-like shell implemented in C. It supports basic commands, piping, redirection, and environment variable management, with a focus on process handling and system calls.

## Overview  
A minimalist UNIX shell implementation that supports basic command execution, environment management, built-in commands, and signal handling. Developed as part of the 42 School curriculum in collaboration with **Gaby Khoury**.  

## Features  

### Core Functionality  
- **Command execution** with **PATH resolution** (e.g., `ls`, `grep`, `cat`).  
- **Built-in commands**:  
  - `cd` | `echo` | `pwd` | `exit`  
  - `env` | `export` | `unset`  
- **Environment variable management** (set, unset, update).  
- **Redirections**: `>`, `<`, `>>`, `<<` (heredoc).  
- **Pipes**: `|` for command chaining.  
- **Signal handling** for `Ctrl-C` (SIGINT) and `Ctrl-\` (SIGQUIT).  
- **Error handling** for syntax errors and invalid commands.  

## Team Contributions  

### **Mohammad Tohmeh**  
- **Tokenization**: Splitting input into tokens while handling quotes, spaces, and escape characters.  
- **Environment Management**:  
  - `env` list initialization and updates.  
  - `export` and `unset` logic.  
- **Built-ins**: Implemented `cd`, `echo`, `exit`, and environment-related commands.  
- **Signals**: Configured `SIGINT`, `SIGQUIT`, etc.  
- **Project Structure**: Organized code into modular files for readability and collaboration.  

### **Gaby Khoury**  
- **Parsing**: Structured tokens into executable command pipelines.  
- **Execution**:  
  - **Process creation**  
  - **Redirection** and **pipe management**  

## Getting Started  

### Installation  
1. Clone the repository:  
```bash  
git clone https://github.com/tohmeh/minishell.git
```
2. Compile:  
```bash
cd minishell && make
```
3. Run:  
```bash
./minishell
```

### Usage Example  
```bash
echo "Hello $USER"
```

### Limitations  
- No wildcard expansion (`*.c`).  
- Limited signal handling in heredoc.  
- No advanced job control (background processes).  

### Extra  
We created the following flowchart diagram to demonstrate some of the functionalities we’ve implemented. You can check it below.  

![alt text](minishell.drawio.png)
---
