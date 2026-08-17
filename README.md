# AnarchyCalculator V1.0

A simple command-line calculator that supports basic arithmetic operations with proper order of operations.

Created by: **cha0s66**

## Features

- ✅ Basic arithmetic operations: `+`, `-`, `*`, `/`
- ✅ Correct order of operations (multiplication/division before addition/subtraction)
- ✅ Left-to-right evaluation for operators of equal precedence
- ✅ Debug mode for troubleshooting
- ✅ Error handling (division by zero, unknown operators)

## Build Instructions

### Requirements
- C++23 compiler (MSVC, GCC, or Clang)

### Using PowerShell/Bash
```powershell
g++ -std=c++23 calculator.cpp -o calculator
```

### Using MSVC
```cmd
cl /std:c++latest calculator.cpp
```

## Usage

Run the executable:
```powershell
./calculator.exe
```

### Example
```
-------------------------------------------------------------
                 AnarchyCalculator V1.0!                     
                   Created by: cha0s66                       
-------------------------------------------------------------
Enter equation (use +, -, *, / operators):
125/10*100
The answer is: 1250
```

### Supported Operations
```
125+50        → 175
100-25        → 75
12*8          → 96
100/5         → 20
2+3*4         → 14    (correct order of operations)
125/10*100    → 1250  (left-to-right for equal precedence)
```

### Debug Mode
Enable debug output to see parsing details:

Edit `calculator.cpp` and change:
```cpp
bool DEBUG = false;  // Change to true
```

This will display tokenization and calculation steps.

## Error Handling
- **Division by zero**: Returns error message and 0
- **Unknown operator**: Returns error message and 0

## Limitations
- No parentheses support
- Integers and decimal results supported
- Single equation per run

## License
MIT License - See LICENSE file for details
