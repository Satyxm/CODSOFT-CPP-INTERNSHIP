#include<iostream>
using namespace std;

double firstNumber, secondNumber, result;
char operation;
int errorFlag;

double addition(double, double);
double subtraction(double, double);
double multiplication(double, double);
double division(double, double);

int main() {

  while (true) {

    cout << "Enter the first number: ";
    cin >> firstNumber;
    cout << "Enter the second number: ";
    cin >> secondNumber;
    cout << "Enter the operation (+, -, *, /): ";
    cin >> operation;
    errorFlag = 0;
    
    switch (operation) {
      case '+':
        result = addition(firstNumber, secondNumber); break;
      case '-':
        result = subtraction(firstNumber, secondNumber); break;
      case '*':
      case 'x':
      case 'X':
        result = multiplication(firstNumber, secondNumber); break;
      case '/':
        if (secondNumber == 0) {
          cout << "ERROR: Cannot divide by zero." << endl;
          errorFlag = 1;
        } else {
          result = division(firstNumber, secondNumber);
        } break;
      default:
        cout << "Invalid operation." << endl;
        errorFlag = 1; break;
    }
    if (errorFlag == 0)
      cout << firstNumber << operation << secondNumber << " = " << result << endl;
  } 
  return 0;
}

double addition(double num1, double num2) {
  return num1 + num2;
}

double subtraction(double num1, double num2) {
  return num1 - num2;
}

double multiplication(double num1, double num2) {
  return num1 * num2;
}

double division(double num1, double num2) {
  return num1 / num2;
}
