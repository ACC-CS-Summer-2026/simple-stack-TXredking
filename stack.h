/* *************************************************
*  Name: Rory McLaughlin
*  Course: COSC 2436
*  Date: 2026-06-21
*  Assignment: Assignment 4 - Simple Stack
*  Purpose: Header file for stack.cpp. All directives for
*  stack go here.
************************************************* */

#ifndef CLASSES_STACK_H
#define CLASSES_STACK_H

#define STACKSIZE 10

class Stack {

    public:
    /**********************
    Constructors/Destructor
    ***********************/
    Stack();
    ~Stack();

    /**********************
    Getters/Accessors
    ***********************/
    int pop();
    int peek();
    bool isEmpty();

    /**********************
    Setters/Mutators
    ***********************/
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
    int top;
    int stack[STACKSIZE];
};

#endif //CLASSES_STACK_H