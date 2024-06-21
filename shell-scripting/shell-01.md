### Systems Programming - Basics of Shell Scripting Cheatsheet

- [Systems Programming - Basics of Shell Scripting Cheatsheet](#systems-programming---basics-of-shell-scripting-cheatsheet)
  - [Introduction to Shell](#introduction-to-shell)
  - [Writing Shell Scripts](#writing-shell-scripts)
  - [Variables](#variables)
  - [Input and Arithmetic](#input-and-arithmetic)
  - [Conditional Statements](#conditional-statements)
  - [Iteration Statements](#iteration-statements)
  - [Shell Operators](#shell-operators)
    - [Arithmetic, relational, boolean Operators](#arithmetic-relational-boolean-operators)
    - [File Operators](#file-operators)
  - [Special Shell Parameters](#special-shell-parameters)
  - [Example Scripts](#example-scripts)

---

#### Introduction to Shell

- **What is Shell?**

  - A command interpreter that converts text input into actions.
  - Acts as a user interface for the Unix operating system.

- **Shell Scripting Benefits**
  - Automation of repetitive tasks.
  - System administration tasks such as backups and monitoring.
  - Adding new functionality to the shell.

---

#### Writing Shell Scripts

- **Basic Script Example**

  ```bash
  #!/bin/bash
  echo "Hello World"
  ```

  - Save as `hello.sh` and make it executable with `chmod +x hello.sh`.

- **Second Script Example**
  ```bash
  #!/bin/bash
  mkdir test  # make directory 'test'
  cp src dest  # copy src to dest
  rm -rf test # remove recusively & forcefully 'test' and its children
  echo "Deleted all files!"
  ```

#### Variables

- **Creating Variables**

  ```bash
  STR="Hello CS416 Students!"
  echo $STR
  ```

  - No spaces around the assignment operator `=`.
  - Use `$` to reference variable values, somewhat familiar for those who know Dart or the `$` in JS.

- **Quotes in Variables**

  - Double quotes `"` allow variable resolution or referencing.

  ```sh
  name="Ahmad"
  greeting="Hello, $name!"
  echo "$greeting" # Hello, Ahmad!
  ```

  - Single quotes `'` do not allow variable resolution.

  ```sh
  name="Ahmad"
  greeting='Hello, $name!' # Notice the double quotes
  echo "$greeting" # Hello, $name!
  ```

- **Export Command**

  - **In Short**: Makes variables available to child processes:

    ```bash
    export VAR='Something'
    ```

  - If the child process modifies `var`, it will not modify the parent’s original value. Verify this by changing `var in
    the following way

    ```bash
    export var='Something'
    bash
    echo $var  #'Something'
    var='Another Thing'
    echo $var  #'Another Thing'
    exit
    echo $var  #'Something'

    ```

- **Environmental Variables**
  - Set by the system, e.g., `$SHELL`, `$PATH`.
  - Defined in `/etc/profile`, `/etc/profile.d/`, and `~/.bash_profile`.

---

#### Input and Arithmetic

- **Read Command**

  ```bash
  echo -n "Enter name of file to delete: "
  read file
  rm -i $file
  ```

- **Arithmetic Evaluation**

  ```bash
  let X=10+2*7
  echo $X
  ```

  - Operators: `+`, `-`, `/`, `*`, `%`.
  - An arithmetic expression can be evaluated by `$[expression]` or `$((expression))`

---

#### Conditional Statements

- **if Statement**

  ```bash
  if [ expression ]; then
    statement
  fi
  ```

- **if-else Statement**

  ```bash
  if [ expression ]; then
    statement1
  else
    statement2
  fi
  ```

- **if-elif-else-fi Statement**

  ```bash
  if [ expression1 ]; then
    statement1
  elif [ expression2 ]; then
    statement2
  else
    statement3
  fi
  ```

- **Nested if Statement**

  ```bash
  if [ condition1 ]; then
    if [ condition2 ]; then
      statement
    fi
  fi
  ```

- **case Statement**
  ```bash
  case $variable in
    pattern1) statement1 ;;
    pattern2) statement2 ;;
    *) default_statement ;;
  esac
  ```

---

#### Iteration Statements

- **for Loop**

  ```bash
  for var in list; do
    statements
  done
  ```

- **C-like for Loop**
  ```bash
  for (( expr1; expr2; expr3 )); do
    statements
  done
  ```


---

#### Shell Operators

##### Arithmetic, relational, boolean Operators

> Suppose `$a` is **10** & `$b` is **20**

| Operator | Description                                            | Example                    |
| -------- | ------------------------------------------------------ | -------------------------- |
| `-eq`    | equal                                                  | [ $a -eq $b ] is not true. |
| -ne      | not equal                                              | [ $a -ne $b ] is true.     |
| -gt      | greater than                                           | [ $a -gt $b ] is not true. |
| -lt      | less than                                              | [ $a -lt $b ] is true.     |
| -ge      | greater than or equal                                  | [ $a -ge $b ] is not true. |
| -le      | less than or equal                                     | [ $a -le $b ] is true.     |
| !        | logical Negation                                       | [ `[ !false ]` is true     |
| -o       | logical **OR**                                         |                            |
| -a       | logical **AND**                                        |                            |
| -z       | returns `true` if the String's operand is **zero**     | `[ -z $a ]`                |
| -n       | returns `true` if the String's operand is **non-zero** | `[ -n $a ]`                |
| str      | returns `true` is `str` is **not empty**               | `[ $a ]` is true           |

> [!IMPORTANT]
> all the conditional expressions should be placed inside square braces with spaces around them. For example:

```diff
+ [ $a -lt $b ]` is correct
- [$a -lt $b] is incorrect.
```

##### File Operators

| Operator | Description                                                  | Example                     |
| -------- | ------------------------------------------------------------ | --------------------------- |
| `-d`     | returns `true` if file is a Directory                        | `[-d $file  ]` is not true. |
| `-f`     | returns `true` if file is an ordinary File                   | `[-f $file  ]` is true.     |
| -r file  | file is readable;                                            | [ -r $file ] is true.       |
| -w file  | file is writable;                                            | [ -w $file ] is true.       |
| -x file  | file is executable;                                          | [ -x $file ] is true.       |
| -s file  | file has size greater than 0;                                | [ -s $file ] is true.       |
| -e file  | file exists; is true even if file is a directory but exists. | [ -e $file ] is true.       |

---

#### Special Shell Parameters

- `$#`: Number of parameters passed.
- `$0`: Name and location of the script.
- `$*`: All parameters as a single word.
- `$@`: All parameters as an array of words.
#### Example Scripts

- **Trash Script**

  ```bash
  #!/bin/bash
  if [ $# -eq 1 ]; then
    if [ ! -d "$HOME/trash" ]; then
      mkdir "$HOME/trash"
    fi
    mv $1 "$HOME/trash"
  else
    echo "Use: $0 filename"
    exit 1
  fi
  ```

- **Old Directory Script**
  ```bash
  #!/bin/bash
  if [ ! -d "$HOME/old" ]; then
    mkdir "$HOME/old"
  fi
  echo "The following files will be saved in the old directory:"
  echo $*
  for file in $*; do
    mv $file "$HOME/old/"
    chmod 400 "$HOME/old/$file"
  done
  ls -l "$HOME/old"
  ```

---

This cheatsheet provides an overview of the essential concepts and commands discussed in the slides, categorized for easy reference and study.
