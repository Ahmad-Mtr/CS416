
# Bash Cheatsheet | pt.03

- [Bash Cheatsheet | pt.03](#bash-cheatsheet--pt03)
  - [Commands](#commands)
    - [Pipelining Operators](#pipelining-operators)
      - [`|`](#)
      - [`>`](#-1)
      - [`<`](#-2)
    - [`$?`](#-3)
    - [`wc`](#wc)
    - [`head`](#head)
    - [`tail`](#tail)
    - [`basename`](#basename)
    - [`tr`](#tr)
    - [`mv`](#mv)
    - [`cmp`](#cmp)


## Commands

### Pipelining Operators

#### `|`
```bash
command1 | command2 # Use the output of command1 as input for command2
```

#### `>`
```bash
command > file # Redirect output of 'command' to 'file'
ls > file_list.txt # Save the output of 'ls' to 'file_list.txt'
```

#### `<`
```bash
command < file # Use 'file' as input to 'command'
```

### `$?`
```bash
command
echo $? # Display the return status of the last command
```

### `wc`
```bash
wc file.txt # Count lines, words, and characters in 'file.txt'
wc -l file.txt # Count lines in 'file.txt'
```

### `head`
```bash
head -n 5 file.txt # Display the first 5 lines of 'file.txt'
```

### `tail`
```bash
tail -n 5 file.txt # Display the last 5 lines of 'file.txt'
```

### `basename`
```bash
basename /path/to/file.txt # Extract the filename from a path
basename /path/to/file.txt .txt # Extract the filename without the extension
```

### `tr`
```bash
echo "hello world" | tr 'a-z' 'A-Z' # Translate lowercase to uppercase
```

### `mv`
```bash
mv oldname newname # Rename or move 'oldname' to 'newname'
mv file.txt /new/directory/ # Move 'file.txt' to '/new/directory/'
```

### `cmp`
```bash
cmp file1 file2 # Compare two files byte by byte
```

