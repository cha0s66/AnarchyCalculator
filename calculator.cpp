#include <iostream>
#include <string>
#include <print>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

bool DEBUG = false; // Set to true to enable debug output

// Forward declarations
float evaluateExpression(const std::string& expr);

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
        case '^':
            return pow(a, b);
        default:
            std::println("[ERROR]: Unknown operator: {}", op);
            return 0;
    }
}

// Evaluates a simple expression without parentheses
float evaluateSimple(const std::string& expr) {
    vector<float> digitBuffer;
    vector<char> opBuffer;
    
    int i = 0;
    while (i < expr.length()) {
        if (isdigit(expr[i]) || (expr[i] == '-' && (i == 0 || expr[i-1] == '(' || expr[i-1] == '^' || expr[i-1] == '*' || expr[i-1] == '/'))) {
            // Handle negative numbers
            std::string numStr = "";
            if (expr[i] == '-') {
                numStr += '-';
                i++;
            }
            while (i < expr.length() && (isdigit(expr[i]) || expr[i] == '.')) {
                numStr += expr[i];
                i++;
            }
            digitBuffer.push_back(std::stof(numStr));
            if (DEBUG) std::println("[DEBUG] Parsed number: {}", numStr);
        } else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '/' || expr[i] == '*' || expr[i] == '^') {
            opBuffer.push_back(expr[i]);
            if (DEBUG) std::println("[DEBUG] Found operator: {}", expr[i]);
            i++;
        } else {
            i++;
        }
    }

    if (digitBuffer.empty()) return 0;
    if (digitBuffer.size() == 1) return digitBuffer[0];

    // First pass: Handle ^ (exponentiation)
    for (int i = 0; i < opBuffer.size(); i++) {
        if (opBuffer[i] == '^') {
            float a = digitBuffer[i];
            float b = digitBuffer[i + 1];
            digitBuffer[i] = calculateAnswer(a, b, '^');
            digitBuffer.erase(digitBuffer.begin() + i + 1);
            opBuffer.erase(opBuffer.begin() + i);
            i--;
        }
    }

    // Second pass: Handle * and /
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

    // Third pass: Handle + and -
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

    return digitBuffer[0];
}

// Evaluates expressions with parentheses
float evaluateExpression(const std::string& expr) {
    std::string processed = expr;
    
    // Find and evaluate innermost parentheses
    while (processed.find('(') != std::string::npos) {
        int lastOpen = processed.rfind('(');
        int firstClose = processed.find(')', lastOpen);
        
        if (firstClose == std::string::npos) {
            std::println("[ERROR]: Mismatched parentheses");
            return 0;
        }
        
        std::string inner = processed.substr(lastOpen + 1, firstClose - lastOpen - 1);
        float result = evaluateSimple(inner);
        
        // Replace (inner) with the result
        processed = processed.substr(0, lastOpen) + std::to_string(result) + processed.substr(firstClose + 1);
    }
    
    return evaluateSimple(processed);
}

int main() {
    std::println("-------------------------------------------------------------");
    std::println("                 Anarchy Calculator V2.0!                    ");
    std::println("                   Created by: cha0s66                       ");
    std::println("-------------------------------------------------------------");

    std::string equation;
    std::println("Enter equation (use +, -, *, /, ^ operators and parentheses):");
    std::println("Example: (2^4) or 3*(2+5)^2");
    std::cin >> equation;

    float answer = evaluateExpression(equation);
    std::println("The answer is: {}", answer);

    return 0;
}