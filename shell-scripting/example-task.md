# Example Task | Hilow Game
## Random Number Generation

### Using `RANDOM`
```bash
echo $RANDOM # Generates a random number between 0 and 32767
```

### Modulo with `RANDOM`
```bash
echo $(((RANDOM % 10))) # Generates a random number between 0 and 9
echo $(((RANDOM % 10) + 1)) # Generates a random number between 1 and 10
```

### Using `shuf`
```bash
shuf -i 0-10 -n 1 # Generates a random number between 0 and 10
shuf -i 0-10 -n 3 # Generates 3 random numbers between 0 and 10
```

## Question
```
Write a script that generates a random number then ask the user to
guess it. Then, count the number of guesses the user needed.
```
## Solution
```bash
#!/bin/bash

guess=0
# Generate a random number between 1 and 100
n=$((($RANDOM % 100) + 1))
# init count
c=0
echo "Welcome! Take a Guess from 1 to 100"
while [ $guess -ne $n ]; do
c=$[$c+1]
echo -n "Guess #$c? " ; read guess
if [ $n -gt $guess ]; then
  echo "Higher"
elif [ $n -lt $guess ]; then
  echo "Lower"
fi
done
echo "Finished Hajji"
echo "You took $c Guesses!"
```
