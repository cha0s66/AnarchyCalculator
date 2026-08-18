# AnarchyCalculator V2.0

A command-line calculator that supports arithmetic operations with proper order of operations, including parentheses and exponents.

Created by: **cha0s66**

## Features

- ✅ Arithmetic operations: `+`, `-`, `*`, `/`
- ✅ Exponentiation operator: `^`
- ✅ Parentheses support for grouping expressions
- ✅ Correct order of operations (PEMDAS/BODMAS):
  - Parentheses (highest priority)
  - Exponents
  - Multiplication/Division
  - Addition/Subtraction (lowest priority)
- ✅ Error handling (division by zero, mismatched parentheses)
- ✅ Support for decimal numbers and negative values

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
                 AnarchyCalculator V2.0!                     
                   Created by: cha0s66                       
-------------------------------------------------------------
Enter equation (use +, -, *, /, ^ operators and parentheses):
Example: (2^4) or 3*(2+5)^2
(2^4)
The answer is: 16
```

### Supported Operations
```
125+50          → 175
100-25          → 75
12*8            → 96
100/5           → 20
2^4             → 16               (exponentiation)
(2+3)*4         → 20               (parentheses)
3*(2+5)^2       → 147              (combined operators)
2+3*4           → 14               (correct order of operations)
(10+5)/(2+1)    → 5                (complex expression)
2^3^2           → 512              (2^(3^2), right-to-left exponentiation)
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
- **Mismatched parentheses**: Returns error message and 0

## What's New in V2.0
- Added exponentiation operator (`^`)
- Full parentheses support with proper nesting
- Improved expression parsing and evaluation
- Better error messages

## License
MIT License - See LICENSE file for details

