

# Shell Scripting Cheatsheet
## index
- [Shell Scripting Cheatsheet](#shell-scripting-cheatsheet)
  - [index](#index)
  - [Basic Commands](#basic-commands)
  - [Variables](#variables)
  - [Control Structures](#control-structures)
  - [Functions](#functions)
  - [File Operations](#file-operations)
  - [Input/Output Redirection](#inputoutput-redirection)
  - [Permissions](#permissions)
  - [Special Variables](#special-variables)
  - [Useful Commands](#useful-commands)
  - [Creating a Basic Shell Script](#creating-a-basic-shell-script)
    
   
## Basic Commands

- **echo**: Display text
  ```bash
  echo "Hello, World!"
  ```

- **ls**: List directory contents
  ```bash
  ls
  ```

- **cd**: Change directory
  ```bash
  cd /path/to/directory
  ```

- **cp**: Copy directory/file
  ```bash
  cp file1 file2       # Copy file1 to file2
  cp -r directory1 directory2  # Copy directory1 and its contents recursively to directory2
  ```

- **rm**: Remove File
   ```bash
    rm file1 file2       # Remove multiple files
    rm -r directory      # Remove directory and its contents recursively
    rm -f file           # Force removal without confirmation
    rm -rf directory       # Remove directory and its contents recursively without confirmation

    sudo rm -rf directory / # Try this for fun, btw this will delete all files recursively from the ROOT Dir = deleting all system
    ```

- **cat**: Cat File (Print its content to the terminal)
  ```bash
  cat filename
  ```
- **pwd**: Print working directory
  ```bash
  pwd
  ```

  

## Variables

- **Variable Declaration**
  ```bash
  VAR_NAME=value # Note that no white-spaces are allowed
  ```

- **Access Variable**
  ```bash
  echo $VAR_NAME
  ```

## Control Structures

- **if-else Statement**
  ```bash
  if [ condition ]; then
      # Commands
  else
      # Commands
  fi
  ```

- **for Loop**
  ```bash
  for item in list; do
      # Commands
  done
  ```

- **while Loop**
  ```bash
  while [ condition ]; do
      # Commands
  done
  ```

## Functions

- **Function Declaration**
  ```bash
  function_name() {
      # Commands
  }
  ```

- **Function Call**
  ```bash
  function_name
  ```

## File Operations

- **Create File**
  ```bash
  touch filename
  ```

- **Check File Existence**
  ```bash
  if [ -e filename ]; then
      # Commands
  fi
  ```

## Input/Output Redirection

- **Redirect Output to File**
  ```bash
  command > filename
  ```

- **Redirect Input from File**
  ```bash
  command < filename
  ```

## Permissions

- **Change File Permissions**
  ```bash
  chmod permissions filename

  chmod 700 hello.sh # Example usecase:  
  # sets hello.sh to have read, write, and execute permissions for the owner of the file (rwx), while denying all permissions to the group owner and others.
  ```
- Permissions: `u` (user), `g` (group), `o` (others), `a` (all)
- Operations: `+` (add), `-` (remove), `=` (set)

## Special Variables

- **`$0`**: Script name
- **`$1`, `$2`, ...**: Positional parameters
- **`$#`**: Number of arguments
- **`$@`**: All arguments
- **`$$`**: Process ID

## Useful Commands

- **grep**: Search text
  ```bash
  grep pattern filename
  ```

- **awk**: Text processing
  ```bash
  awk '{print $1}' filename
  ```

- **sed**: Stream editor
  ```bash
  sed 's/pattern/replacement/' filename
  ```

## Creating a Basic Shell Script
1. Create a new file:
```bash
touch script.sh
```
2. Open the file in a text editor:
```bash
nano script.sh # not recommended, use the below command, < Vim
vim script.sh # requires installing vim before
```
3. Write your script:

```bash
#!/bin/bash

# Your commands here
```
4. Save and exit:

- Press `:wq`   (For vim-based editors)
- Press `Enter` to exit

1. Make the script executable:

```bash
chmod +x script.sh
```
5. Run the script:

```bash
./script.sh
```


