# Summary of `fork()`, `exec()`, `wait()` pattern
## `exec()` family
The `exec()` family of functions in Unix-like operating systems replaces the current process image with a new process image. Here's a summary of the `exec()` family:
```diff
- l: list of arguments, exp: `New-Item <filename.pwsh>`
+ e: environment variable: in short those are variables defined within your system, (search how to hide secrets in env vars)
- v: Vector, expects an array(vector) of pointers.
+ p: Path, searches for executables within the `PATH` env variable, in other words, search executables in a place that has `ls`, `mkdir`,`gcc`, executables

- Others exist ofc, I think those are enought 4now.
```
1. **`execl()`**:
   - Executes a file with a list of arguments passed as individual function parameters.
   - Syntax: `int execl(const char *path, const char *arg0, ..., const char *argn, (char *) NULL);`

2. **`execv()`**:
   - Executes a file with a list of arguments passed as an array of pointers to null-terminated strings.
   - Syntax: `int execv(const char *path, char *const argv[]);`

3. **`execle()`**:
   - Similar to `execl()`, but allows specifying environment variables for the new process.
   - Syntax: `int execle(const char *path, const char *arg0, ..., const char *argn, (char *) NULL, char *const envp[]);`

4. **`execve()`**:
   - Similar to `execv()`, but allows specifying environment variables for the new process.
   - Syntax: `int execve(const char *path, char *const argv[], char *const envp[]);`

5. **`execlp()`**:
   - Similar to `execl()`, but searches for the executable file in the directories listed in the `PATH` environment variable.
   - Syntax: `int execlp(const char *file, const char *arg0, ..., const char *argn, (char *) NULL);`

6. **`execvp()`**:
   - Similar to `execv()`, but searches for the executable file in the directories listed in the `PATH` environment variable.
   - Syntax: `int execvp(const char *file, char *const argv[]);`

7. **Return Value**:
   - All `exec()` functions return `-1` if an error occurs, and they do not return if successful (since they replace the current process image).

These functions are commonly used in conjunction with the `fork()` system call to execute other programs within a process. They are fundamental for process management and program execution in Unix-like operating systems.

## `wait()` & `waitpid()`
> Note that this is mostly AI-generated, Some info weren't mentioned in the Course.

`wait()` and `waitpid()` are both functions used in Unix-like operating systems (including Linux) for handling child processes. Here are the key differences between them:

1. **Usage**:
   - `wait()`: It waits for any child process to terminate. It doesn't provide control over which child process to wait for.
   - `waitpid()`: It allows you to specify which child process to wait for based on its process ID.

2. **Parameters**:
   - `wait()`: Takes no arguments.
   - `waitpid()`: Takes three arguments:
     - `pid`: The process ID of the child process to wait for. It can take different values to specify which child process to wait for, such as:
       - `pid > 0`: Wait for the child process with the specified PID.
       - `pid == -1`: Wait for any child process.
       - `pid == 0`: Wait for any child process in the same process group as the current process.
       - `pid < -1`: Wait for any child process whose process group ID is equal to the absolute value of `pid`.

3. **Return Values**:
   - Both `wait()` and `waitpid()` return the process ID of the terminated child process. If there are no child processes or if an error occurs, they return `-1`.

4. **Error Handling**:
   - `wait()`: It doesn't allow you to specify options for error handling.
   - `waitpid()`: It allows you to specify options (`options` parameter) for error handling and behavior

Overall, `waitpid()` provides more flexibility and control over which child process to wait for and how to handle errors compared to `wait()`. It's commonly used in scenarios where specific child process management is required.

### `waitpid()` Syntax
```c
pid_t waitpid(pid_t pid, int *status, int options);
```


| **pid**       | **description**                                                                                                                               |
| ------------- | --------------------------------------------------------------------------------------------------------------------------------------------- |
| `< -1`        | Wait for any child process whose process group ID is equal to the absolute value of `pid`.                                                    |
| `-1`          | Wait for any child process.                                                                                                                   |
| `0`           | Wait for any child process whose process group ID is equal to that of the calling process (i.e., child and parent in the same process group). |
| `> 0`         | Wait for the child whose process ID is equal to the value of `pid`.                                                                           |
| ***options*** | ***description***                                                                                                                             |
| `0`           | Returns when a child has terminated (i.e., similar to `wait`).                                                                                |
| `WNOHANG`     | Do not block if no child changed its state.                                                                                                   |
| `WUNTRACED`   | Returns if a child has stopped. Status for traced children which have stopped is provided even if this option is not specified.               |
| `WCONTINUED`  | Returns if a stopped child has been resumed.                                                                                                  |
|               |                                                                                                                                               |
 >**Note**:
 >  `wait(&status)` is equivalent to `waitpid(-1, &status, 0)`.         


## `WEXITSTATUS()` and other macros
1. `WIFEXITED(int status)`: stands for wait until child process exited, so the functions checks if child process terminated normally.
2. `WEXITSTATUS(int status)`: gets the exit status value of the child, Example: if child does `exit(5)`, a status `5` will be returned.

**Example:**
```c
  // Parent process BLOCK
        int status;
        wait(&status);
        if (WIFEXITED(status)) {
            // Child process terminated normally
            int exit_status = WEXITSTATUS(status);
            printf("Child process exited with status: %d\n", exit_status);
        } else {
            // Child process terminated abnormally
            printf("Child process terminated abnormally\n");
        }
``` 

**Other Macros**
```c
WIFSIGNALED(*statusPtr) => "evaluates to a nonzero (true) value if the specified process terminated because of an unhandled signal. • WTERMSIG(*statusPtr) if the specified process is ended by an unhandled signal, this macro evaluates to the number of that signal."

WIFSTOPPED(*statusPtr) => "(true) value if the specified process is currently stopped but not terminated."

WSTOPSIG(*statusPtr) => "if the specified process is currently stopped but not terminated, then this macro evaluates to the number of the signal that caused the process to stop"
```
