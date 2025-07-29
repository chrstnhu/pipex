# Pipex

Project 42 school

Recreate the behavior of shell pipelines using process creation and file descriptors.

## 📖 Objective

Simulate the behavior of the shell pipe (`|`) operator, using `fork`, `execve`, and file redirection.

## ✅ Allowed Functions

* `open`, `close`, `read`, `write`
* `malloc`, `free`, `access`, `execve`
* `dup`, `dup2`, `pipe`
* `fork`, `wait`, `waitpid`, `perror`
* `strerror`, `exit`

## 🔧 Compile

```bash
make
```

## ▶️ Run the Program

```bash
./pipex infile "cmd1" "cmd2" outfile
```

This executes:

```bash
< infile cmd1 | cmd2 > outfile
```

### Example

```bash
./pipex file1 "grep a" "wc -l" file2
```

This is equivalent to:

```bash
< file1 grep a | wc -l > file2
```

## ✏️ Rules

<details>
<summary>Mandatory</summary>

* The program takes **exactly 4 arguments**.
* It must use `pipe()` to connect the output of `cmd1` to the input of `cmd2`.
* Use `fork()` to create child processes.
* Handle file descriptors correctly to redirect input/output.
* Handle errors (permission denied, command not found, etc).

</details>
