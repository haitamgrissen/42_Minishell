# 42_Minishell

The objective of this project is to create a shell like BASH.
## Introduction:
The existence of shells is linked to the very existence of IT. At the time, all coders agreed.
that communicating with a computer using aligned 1/0 switches was seriously.
irritating. It was only logical that they came up with the idea to communicate with.
a computer using interactive lines of commands in a language somewhat close to english.

With Minishell, you’ll be able to travel through time and come back to problems people faced when Windows didn’t exist.

### This minishell:

- Dont interpret unclosed quotes or unspecified special characters.
- Show a prompt when waiting for a new command.
- Have a working History.
- Search and launch the right executable (based on the PATH variable or by using relative or absolute path).
- implement the builtins:
  - `echo` with option `-n`.
  - `cd` with only a relative or absolute path.
  - `pwd` with no options.
  - `export` with no options.
  - `unset` with no options.
  - `env` with no options or arguments.
  - `exit` with no options.
- `’` inhibit all interpretation of a sequence of characters.
- `"` inhibit all interpretation of a sequence of characters except for `$`.
- Redirections:
  - `<` redirect input.
  - `>` redirect output.
  - `<<` read input from the current source until a line containing only the delimiter is seen. it doesn’t need to update history!
  - `>>` should redirect output with append mode.
- Pipes `|` The output of each command in the pipeline is connected via a pipe to the input of the next command.
- Environment variables (`$` followed by characters) should expand to their values.
- `$?` should expand to the exit status of the most recently executed foreground pipeline.
- `ctrl-C` `ctrl-D` `ctrl-\` work like in bash.
- When interactive:
  - `ctrl-C` print a new prompt on a newline.
  - `ctrl-D` exit the shell.
  - `ctrl-\` do nothing.
