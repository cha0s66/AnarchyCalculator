#include <iostream>
#include <string>
#include <print>
#include <bits/stdc++.h>
using namespace std;

// Performs arithmetic operations based on operator
float calculateAnswer(float a, float b, char op) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b != 0) {
                return a / b;
            } else {
                std::println("[ERROR]: Division by zero");
                return 0;
            }
        default:
            std::println("[ERROR]: Unknown operator: {}", op);
            return 0;
    }
}

int main() {
    bool DEBUG = false; // Set to true to enable debug output
    
    std::println("-------------------------------------------------------------");
    std::println("                 Anarchy Calculator V1.0!                    ");
    std::println("                   Created by: cha0s66                       ");
    std::println("-------------------------------------------------------------");

    std::string equation;
    std::println("Enter equation (use +, -, *, / operators):");
    std::cin >> equation;

    int stringSize = equation.length();

    vector<float> digitBuffer;  // Numbers
    vector<char> opBuffer;      // Operators

    // Parse numbers and operators
    for (int i = 0; i < stringSize; i++) {
        if (isdigit(equation[i])) {
            std::string numStr = "";
            while (i < stringSize && isdigit(equation[i])) {
                numStr += equation[i];
                if (DEBUG) std::println("[DEBUG] Current number string: {}", numStr);
                i++;
            }
            i--; // Back up one since loop will increment
            
            if (DEBUG) std::println("[DEBUG] Final number string: {}", numStr);
            digitBuffer.push_back(std::stoi(numStr));

        } else if (equation[i] == '+' || equation[i] == '-' || equation[i] == '/' || equation[i] == '*') {
            if (DEBUG) std::println("[DEBUG] Found operator: {}", equation[i]);
            opBuffer.push_back(equation[i]);
        }
    }

    // First pass: Handle * and /
    for (int i = 0; i < opBuffer.size(); i++) {
        if (opBuffer[i] == '*' || opBuffer[i] == '/') {
            float a = digitBuffer[i];
            float b = digitBuffer[i + 1];
            char op = opBuffer[i];

            digitBuffer[i] = calculateAnswer(a, b, op);
            digitBuffer.erase(digitBuffer.begin() + i + 1);
            opBuffer.erase(opBuffer.begin() + i);
            i--;
        }
    }

    // Second pass: Handle + and -
    for (int i = 0; i < opBuffer.size(); i++) {
        if (opBuffer[i] == '+' || opBuffer[i] == '-') {
            float a = digitBuffer[i];
            float b = digitBuffer[i + 1];
            char op = opBuffer[i];

            digitBuffer[i] = calculateAnswer(a, b, op);
            digitBuffer.erase(digitBuffer.begin() + i + 1);
            opBuffer.erase(opBuffer.begin() + i);
            i--;
        }
    }
    
    std::println("The answer is: {}", digitBuffer[0]);

    return 0;
}