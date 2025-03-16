# minishell
A simple Unix-like shell implemented in C. It supports basic commands, piping, redirection, and environment variable management, focusing on process handling and system calls.

## Overview  
A minimalist UNIX shell implementation supporting basic command execution, environment management, built-ins, and signal handling. Developed as part of the 42 School curriculum in collaboration with **Gaby Khoury**.  

## Features  

### Core Functionality  
- Command execution with **PATH resolution** (e.g., `ls`, `grep`, `cat`).  
- **Built-in commands**:  
  - `cd` | `echo` | `pwd` | `exit`  
  - `env` | `export` | `unset`  
- **Environment variable management** (set, unset, update).  
- **Redirections**: `>`, `<`, `>>`, `<<` (heredoc).  
- **Pipes**: `|` for command chaining.  
- **Signal handling** for `Ctrl-C` (SIGINT) and `Ctrl-\` (SIGQUIT).  
- **Error handling** for syntax errors and invalid commands.  


## Team Contributions  
### **Your Name**  
- **Tokenization**: Split input into tokens while handling quotes, spaces, and escape characters.  
- **Environment Management**:  
  - `env` list initialization and updates.  
  - `export` and `unset` logic.  
- **Built-ins**: Implemented `cd`, `echo`, `exit`, and environment-related commands.  
- **Signals**: Configured `SIGINT` , `SIGQUIT` ...
- **Project Structure**: Organized code into modular files for readability and collaboration.  

### **Gaby Khoury**  
- **Parsing**: Structured tokens into executable command pipelines.  
- **Execution**:  
  - **Process creation** with `fork()` and `execve()`.  
  - **Redirections** and **pipe** management.  
  - PATH resolution using the `env` list.  

---

## Getting Started  
### Installation  
1. Clone the repository:  
```bash  
git clone https://github.com/tohmeh/minishell.git
```
2. compile
```bash
cd minishell && make
```
3. run
```bash
./minishell
```
### usage example 

```bash
echo "Hello $USER"
```

### Limitations 

- No wild cart expansion (*.c)
- Limited signal handling in heredoc
- No advanced job control (background processes)

### extra

-I created a flowchart diagram to demonstrate some of the functionality I’ve implemented. You can check it out on Draw.io by opening an existing project.
