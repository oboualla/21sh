# 21sh - 42 School Education Project

21sh is an educational project developed as part of the 42 School curriculum. This README will provide you with an overview of the project, its features, and instructions on how to get started.

## Project Description

21sh is a shell, similar to the Unix shell (sh), that allows users to interact with the operating system through a command-line interface. The project involves implementing a wide range of shell functionalities, including command-line editing, history navigation, built-in commands, redirection, and more.

For detailed project specifications and requirements, please refer to the [21sh Project Subject](https://cdn.intra.42.fr/pdf/pdf/6355/21sh.fr.pdf).

## Mandatory Features

21sh comes with several mandatory features:

- **Prompt and Error Management**: Implement a custom prompt and handle errors gracefully.
- **Inhibitors**: Support for inhibiting characters `"`, `'`, and `\`.
- **Command Line Editing**: Implement command-line editing using the termcaps library.
- **Cursor Navigation**: Allow users to edit the line where the cursor is.
- **History Navigation**: Use the up and down arrow keys to navigate command history.
- **Copy and Paste**: Support for copying, cutting, and pasting all or part of a line using key sequences.
- **Key Combinations**: Implement the functionality of the `ctrl + D` and `ctrl + C` key combinations for editing and process execution.
- **Built-in Commands**: Implement built-in commands `cd`, `echo`, `exit`, `env`, and `type` with their respective options.
- **Command Execution**: Execute commands with their parameters using the `PATH` environment variable.
- **Redirection and Aggregation**: Support for redirection and aggregation operators `>`, `>>`, `<`, `<<`, `>&`, and `<&`.
- **Command Separation**: Implement command separators `;` and pipes `|`.
- **Shell Variables**: Manage shell variables with `setenv`, `unsetenv`, and `env`, including temporary variables.
- **Word Movement**: Move by "word" to the left and right with `Alt + LEFT` and `Alt + RIGHT`.
- **Multi-Line Commands**: Write and edit a command on several lines.

## Bonus Features

21sh includes some bonus features:

- **Extended Inhibitors**: Support for extended inhibitors `"`, `'`, and `\`.
- **Autocompletion**: Implement tab-based autocompletion.
- **Window Size Change**: Support for resizing the window while editing a command line.

## Getting Started

To get started with the 21sh project, follow these steps:

1. Clone the 21sh repository to your local machine.

```bash
git clone https://github.com/oboualla/21sh.git
```

2. Build the project according to the build instructions provided in the project subject.

3. Run the 21sh shell on your terminal.

4. Start exploring and using the shell with the implemented features.

---

Thank you for diving into the 21sh project! If you have any questions or need further assistance.

**Happy shell scripting!**
