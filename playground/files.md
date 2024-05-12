# Files
## list of Content
* [Libraries](#libraries)
* [open](#open)
* [close](#close)
* [read](#read)
* [write](#write)
* [lseek](#lseek)
* [dup, dup2](#dup-system-calls)
---
## Libraries
`<sys/file.h>` or `<fcntl.h>`

----
## `open`

**Signature:** 
```c
int open(char* filename, int flags, int mode)
```
***
**Flags:** used to describe the File opening method.
  * `O_RDONLY` Opens a file for reading only.
  * `O_WRONLY` Open only for writing.
  * `O_RDWR` ... Read & Write.
  * `O_APPEND` Open ... Append.
  * `O_CREAT` Create the File if `d.n.e`.
  * `O_TRUNC` Truncate its size to 0, meaning clear the content.
***
**Mode:** A number that describes The Permissions for _special, user, group, others_
|  Permission  |  Values  |
|  ---  |  --- |
|  Read  |  4  |
|  Write  |  2  |
|  execute|  1  |

`0751`:
`0`: special permissions `0` for none.
`7`: user
`5`: group
`1`: others

**Special Permissions**:
* `0` None
* `1` set sticky bit
> _Sticky Bit:_ only the `file`, `dir` owner can delete/rename. However, it should be noted that root user is still able to do it as well.
* `2` SGID set
> _SGID_ (Set-Group Identification) enables other users to inherit the
effective GID (group identifier) of a group owner.
* `3` Sticky Bit and SGID Set
* `4` SUID set
> _SUID_ (Set User Identification) enables other users to run the file with
the effective permission of the file owner.
* `5` Sticky Bit and SUID Set
* `6` SGID and SUID set
* `7` Sticky Bit GID and UID Set

## `close`

**Signature:** 
```c
int close(int fd)
```
return -1 onError, 0 otherwise.
---

## `read`
```c
int read(int fd, void *buffer, size_t bytes); 
```
buffer: where data is stored.
bytes: max data to read from the Stream.
---

## `write`
```c
write(int fd, void *buffer, size_t bytes);
```

---

## `lseek`
used to reposition the reading/writing cursor or pointer, returns the new position, `-1` onError.
```c
lseek(fd, offset, whence)
```
**Whence:**
*  `SEEK_SET` Seek the File's Beginning, + offset.
*  `SEEK_CUR` Seek the File's current position, + offset.
*  `SEEK_END` Seek the File's End, + offset.

---

## `dup` System calls
### `dup`
```c
#include <unistd.h>

int dup(int oldfd);
```
Uses lowest unused descriptor, returns a new `fd`.
> Both descriptors will refer to the same file, therefore if the cursor is modified in `fd_A`, `fd_B` will be modified.
***
### `dup2`
```c
#include <unistd.h>

int dup2(int oldfd, int newfd);
```
`newfd`:  the new descriptor to use to create a copy.

> in short, same as `dup()`, but you specify the `newfd` instead of _lowest unused value_

`oldfd` isn't valid? call fails, and `newfd` won't close have `oldfd`'s value.


****
The previous usecase of `dup2()` was boring and sometimes not useful, to spice it up.

|  Value|  **Files Stream**  |
|  ---  |  ---            |
| 0  |  `stdin`  |
| 1  |  `stdout`  |
| 2  |  `stderr`  |

Those are Unix standard channels. File Descriptors generallly are handles for input, output, or error changes.
So what happens if we put a channel as `newfd`?

**Examples:**
1.

main.c
```c 
/*
  #include <...>
*/
int main() {
  int x = 0;
  int fd = open("a.txt", O_RDWR, 0644);
  dup2(fd, 0);
  scanf("%d", &x);
  printf("This is X: %d\n", x);
  return 0;
}
```
a.txt
```txt
10
```
**Output:**
> duplicate `fd` into `stdin` channel, thus handling The File's data as Input given to the Channel, equivelant to the user's entering those manually.
```bash
This is X: 10
```
****

2.
a.txt (Empty)
```

```
main.c
```c
int fd = open("a.txt", O_RDWR, 0644);
dup2(fd, 1);

printf("This is a kartoffel 🥔\n");
```
**Output:**
a.txt
```
This is a kartoffel 🥔
```
> The File handler `fd` is copied to `1` --> `stdout` now handles that file, so whenever it detects a coming Stream of data, it'll be printed also in the File



***
