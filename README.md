# Custom Shell in C

A Unix-like shell implementation built from scratch in C

## Current Features

- **Interactive prompt** - Displays `myshell>` and accepts user input
- **Command parsing** - Parses user input into commands and arguments, handling multiple spaces
- **Command execution** - Uses `fork()` and `execvp()` to execute system commands
- **Type `exit` to quit the shell

## Project Structure
```
shell-project/
├── src/
│   ├── main.c         # Main REPL loop
│   ├── parser.c       # Command parsing logic
│   ├── executor.c     # Command execution with fork/exec
│   ├── builtins.c     # Built-in commands 
│   ├── redirection.c  # I/O redirection 
│   ├── pipeline.c     # Pipe handling 
│   ├── jobs.c         # Job control 
│   └── signals.c      # Signal handling
├── include/
│   ├── shell.h
│   ├── parser.h
│   └── executor.h
├── makefile
└── README.md
```

## Building and Running
```bash
# Compile
make

# Run the shell
./shell

# Clean build files
make clean
```

## Usage Examples
```bash
myshell> ls -la
myshell> pwd
myshell> echo hello world
myshell> cat Makefile
myshell> exit
```

## Planned Features

- [ ] Built-in commands (`cd`, `pwd`, `export`)
- [ ] Input/output redirection (`>`, `<`, `>>`)
- [ ] Pipes (`|`)
- [ ] Background jobs (`&`)
- [ ] Signal handling (Ctrl+C, Ctrl+Z)
- [ ] Job control (`jobs`, `fg`, `bg`)

## Technical Details

- **Language**: C (C11 standard)
- **System Calls**: `fork()`, `execvp()`, `waitpid()`
- **Compilation**: gcc with `-Wall -Wextra -Werror` flags
