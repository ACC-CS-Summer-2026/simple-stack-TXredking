/* *************************************************
*  Name: Rory McLaughlin
*  Course: COSC 2436
*  Date: 2026-06-21
*  Assignment: Assignment 4 - Simple Stack
*  Purpose: Declares the Stack class interface and 
*   the STACKSIZE constant shared with main.cpp
************************************************* */

#ifndef CLASSES_STACK_H
#define CLASSES_STACK_H

// Maximum number of elements the stack can hold. Exposed here (not as a
// literal) so test code in main.cpp can size its tests to match.
#define STACKSIZE 10

class Stack {

    public:
    /**********************
    Constructors/Destructor
    ***********************/
    // Default constructor; initializes the stack to empty (top = -1)
    Stack();
    // Destructor; no dynamic resources to release
    ~Stack();

    /**********************
    Getters/Accessors
    ***********************/
    // Removes and returns the value at the top of the stack;
    // throws std::underflow_error if the stack is empty
    int pop();
    // Returns the value at the top of the stack without removing it;
    // throws std::underflow_error if the stack is empty
    int peek();
    // Returns true if the stack has no elements (top < 0)
    bool isEmpty();

    /**********************
    Setters/Mutators
    ***********************/
    // Pushes value onto the top of the stack;
    // returns false instead of pushing if the stack is full (overflow)
    bool push(int);

    /**********************
    Printing
    ***********************/

private:
    /**********************
    Methods
    ***********************/

    /**********************
    Attributes
    ***********************/
    // Index of the top element in the stack
    int top;
    // Fixed-size array backing the stack; capacity is STACKSIZE elements
    int stack[STACKSIZE];
};

#endif //CLASSES_STACK_H