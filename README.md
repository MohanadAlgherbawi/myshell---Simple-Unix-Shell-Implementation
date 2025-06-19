# myshell---Simple-Unix-Shell-Implementation

myshell - Simple Unix Shell Implementation
=========================================

Course: Operating Systems

Development Team:
-----------------
- Muhannad Alaa AlGherbawi (ID: 120201208) - Core Developer
- Ahmed Mousa Shalayel (ID: 120212546) - Core Developer

Date: June 17, 2025

1. Requirements
---------------
- Operating System: Linux/Unix or Windows with WSL
- C Compiler: gcc (version 9.0 or newer)
- Build Tools: make
- Dependencies: Standard C Library, POSIX-compliant system calls

2. Installation
---------------
1. Clone the repository:
   git clone https://github.com/MohanadAlgherbawi/myshell---Simple-Unix-Shell-Implementation.git
2. Navigate to project directory:
   cd myshell---Simple-Unix-Shell-Implementation
3. Compile the project:
   make

3. Usage
--------
Interactive Mode:
./myshell
myshell> [command]

Batch Mode:
./myshell batchfile.txt

Examples:
myshell> cd /path/to/directory
myshell> ls -l > output.txt
myshell> make &

4. Project Structure
--------------------
myshell.c    - Main shell implementation
utility.c    - Helper functions implementation
myshell.h    - Header file with declarations
makefile     - Build configuration
README.txt   - This documentation file

5. Features
-----------
Built-in Commands:
- cd, clr, dir, environ, echo, help, pause, quit

Advanced Features:
- I/O Redirection (<, >, >>)
- Background execution (&)
- Batch file processing
- Environment variable support

6. Testing
----------
Test basic functionality:
./myshell
myshell> echo "Hello World"
myshell> dir /usr/bin
myshell> help
myshell> quit

7. Troubleshooting
-----------------
Error Message               Solution
gcc: command not found      Install build-essential (Linux) or MinGW (Windows)
make: Nothing to be done    Remove executable (rm myshell) and recompile
Permission denied           Add execute permissions: chmod +x myshell
Command not found           Check command spelling or install required packages

8. License
----------
This project is licensed under the MIT License.

9. Acknowledgments
-----------------
- Special thanks to Dr. Sadiq Ashour for valuable guidance
- Inspired by GNU Bash and Unix shell implementations
