alx Monty project repo

## Usage:

1. #### compile:

...```./compile.sh```

> This will produce a `monty` executable, which then you can by:

2. #### run:

...```monty <input file>```

> Note:  
the program executes line by line,
so even if the input file does not contain valid monty code,
it will still run until it reaches an line with an error.

3. #### the monty file:

##### opcodes:

|opcode|description|
|------|-----------|
|`push` <int>|pushes a new element at the top|
|`pall`  |prints all elements|
|`pop`   |removes the top element|
|`pint`  |prints the topmost element|
|`add`   | adds the top two elements|
|`swap`  |swaps the top two elements|
|`nop`   |does nothing|
|`sub`   |subs the top two elements|
|`div`   |divides the top two elements|
|`mul`   |multiplies the top two elements|
|`mod`   |applies the mod operation on the top two elements|
|`stack` |changes the data structure mod to a stack (default)|
|`queue` |changes the data structure mod to a queue|

