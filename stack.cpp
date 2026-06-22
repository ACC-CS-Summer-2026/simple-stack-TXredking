/* *************************************************
*  Name: Rory McLaughlin
*  Course: COSC 2436
*  Date: 2026-06-21
*  Assignment: Assignment 4 - Simple Stack
*  Purpose: Implements the Stack class declared in 
*   stack.h: array-based int stack with bounds-checked 
*   push and exception-based underflow signaling on pop/peek.
************************************************* */

#include "stack.h"
#include <stdexcept>

Stack::Stack() {
    /* *************************************************
    Constructor for Stack. This is the default constructor
    it takes no parameters.

    @param na : na
    @return na : na
    @exception na : na
    @note When the contructor completes, the object should
          be fully ready for use. No further set-up needed.
    * ************************************************* */
    top = -1;
}

Stack::~Stack() {
    /* *************************************************
    There is nothing for the destructor to do. This is
    just a stub and not needed.

    @param na : na
    @return na : na
    @exception na : na
    @note na
    * ************************************************* */
}

bool Stack::push(int value) {
    /* *************************************************
    Checks for possible overflows. Adds argument to top of stack.
    @param value (int) : the value to push onto the top of the stack
    @return (bool) : true if the value was pushed; false if the stack
                      was full and nothing was pushed (overflow)
    @exception na : na
    @note na
    * ************************************************* */
    if (top == STACKSIZE - 1) {
        return false;
    } else {
        top++;
        stack[top] = value;
        return true;
    }
}

int Stack::pop() {
    /* *************************************************
    Removes and returns the value at the top of the stack.

    @param na : na
    @return (int) : the value that was at the top of the stack
    @exception std::underflow_error : thrown if pop is called on an
                empty stack
    @note na
    * ************************************************* */
    if (isEmpty()) {
        throw std::underflow_error("Stack underflow -- pop on empty stack");
    } else {
        int returnValue = stack[top];
        top--;
        return returnValue;
    }
}

int Stack::peek() {
    /* *************************************************
    Returns the value at the top of the stack without removing it.

    @param na : na
    @return (int) : the value currently at the top of the stack
    @exception std::underflow_error : thrown if peek is called on an
                empty stack
    @note na
    * ************************************************* */
    if (isEmpty()) {
     throw std::underflow_error("Stack underflow -- peek on empty stack");
    } else {
        int returnValue = stack[top];
        return returnValue;
    }
}

bool Stack::isEmpty() {
    /* *************************************************
    Tests whether the stack currently holds any elements.

    @param na : na
    @return (bool) : true if the stack has no elements (top < 0);
                      false otherwise
    @exception na : na
    @note na
    * ************************************************* */
    if (top < 0) {
        return true;
    } else {
        return false;
    }
}
