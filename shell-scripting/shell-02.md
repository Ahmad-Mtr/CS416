# Bash Cheatsheet | pt. 02
- [Bash Cheatsheet | pt. 02](#bash-cheatsheet--pt-02)
  - [Commands](#commands)
    - [`read`](#read)
    - [`cat`](#cat)
    - [`while` loop](#while-loop)
    - [`until`](#until)
    - [`sleep`](#sleep)
  - [String Manipulations](#string-manipulations)
    - [Length of a string](#length-of-a-string)
    - [Substring extraction](#substring-extraction)
    - [Parameter expansion with message](#parameter-expansion-with-message)
  - [Functions](#functions)
    - [Syntax](#syntax)
    - [Arguments](#arguments)
    - [Scope](#scope)
  - [Capturing Return from Last Command](#capturing-return-from-last-command)
  - [File and Directory Commands](#file-and-directory-commands)
    - [`ls`](#ls)
    - [`chmod`](#chmod)
    - [`chown`](#chown)
    - [`chgrp`](#chgrp)

## Commands

### `read`

```bash
read var # Read input from the user and store it in 'var'
```

### `cat`
```bash
cat file.txt # Display the contents of 'file.txt'
```

### `while` loop
```bash
while [ condition ]; do
  # commands
done
```

### `until`
```bash
until [ condition ]; do
  # commands
done
```

### `sleep`
```bash
sleep 5 # Pause for 5 seconds
```

## String Manipulations

### Length of a string
```bash
${#string} # Returns the length of 'string'
```

### Substring extraction
```bash
${string:position} # Extracts substring from 'string' starting at 'position'
${string:position:length} # Extracts 'length' characters from 'string' starting at 'position'
```

### Parameter expansion with message
```bash
${parameter?msg} # If 'parameter' is not set, display 'msg'
```

## Functions

### Syntax
```bash
function_name() {
  # commands
}

function_name arg1 arg2 # Call function with arguments
```

### Arguments
```bash
my_function() {
  echo "First argument: $1"
  echo "Second argument: $2"
}
```

### Scope
```bash
my_function() {
  local var="local variable"
  global_var="global variable"
}
```

## Capturing Return from Last Command
```bash
command
ret=$? # Capture return status of the last command
```

## File and Directory Commands

### `ls`
```bash
ls # List files in current directory
ls / # List files in root directory
ls -l # List files in long format
```

### `chmod`
```bash
chmod 755 file # Set rwxr-xr-x permissions for 'file'
chmod g+w file # Add write permission for group to 'file'
chmod o-r file # Remove read permission for others from 'file'
chmod u+x,g+w,o-r file # Set multiple permissions at once
```

### `chown`
```bash
chown user file # Change ownership of 'file' to 'user'
chown user:group file # Change ownership of 'file' to 'user' and 'group'
```

### `chgrp`
```bash
chgrp group file # Change group ownership of 'file' to 'group'
```


