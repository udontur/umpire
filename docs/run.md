## Usage
The usage guide is also available via the following command: `um --help`

### Folder Structure
Organize your code directory as follows:
```sh
task-a/ # The folder that stores everything
└─ main.cpp # File name must be "main"
└─ testcase # Exact name
  ├─ ABC.in
  ├─ ABC.out 
```

### Running Umpire
Run `umpire` in the **current** directory:
```sh
um
```
Or specify a directory:
```
um task-a
```

### Options
#### 1. Execution time limit (`-t`)
Set the execution time limit in seconds (accepts integers and decimal numbers):
```sh
um -t 3.5 # 3.5 second time limit
```
> [!TIP]
> Omit for a 1 second time limit
> ```sh
> um # no flags
> ```
#### 2. Program inputs and outputs (`--output`)
See your program's inputs and outputs by toggling the following flag:
```sh
um --output
```

### Example
Run the code located in the `task-a` folder with a 2 second time limit:
```sh
um task-a -t 2
```  