/* *************************************************
*  Name: Rory McLaughlin
*  Course: COSC 2436
*  Date: 2026-06-21
*  Assignment: Assignment 4 - Simple Stack
*  Purpose: Testbed for the Stack class. Exercises every operation
*  (push, pop, peek, isEmpty) against every state (underflow, overflow,
*  neither), then runs randomized operations scaled to STACKSIZE.
************************************************* */

#include "main.h"

int main() {
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> opDist(0, 3);
    std::uniform_int_distribution<int> valueDist(0, 999);

    int passCount = 0;
    int failCount = 0;

    Stack stack;

    // ---------------------------------------------------------------
    // Section 1: Explicit testing - every state x every operation
    // ---------------------------------------------------------------

    // --- State 1: Underflow (stack starts empty) ---
    std::cout << "=== Explicit Tests: Underflow state ===" << std::endl;

    if (stack.isEmpty()) {
        std::cout << "PASS: isEmpty() true on new stack" << std::endl;
        passCount++;
    } else {
        std::cout << "FAIL: isEmpty() false on new stack" << std::endl;
        failCount++;
    }

    try {
        stack.pop();
        std::cout << "FAIL: pop() on empty stack did not throw" << std::endl;
        failCount++;
    } catch (const std::underflow_error&) {
        std::cout << "PASS: pop() on empty stack threw std::underflow_error" << std::endl;
        passCount++;
    }

    try {
        stack.peek();
        std::cout << "FAIL: peek() on empty stack did not throw" << std::endl;
        failCount++;
    } catch (const std::underflow_error&) {
        std::cout << "PASS: peek() on empty stack threw std::underflow_error" << std::endl;
        passCount++;
    }

    // --- State 2: Neither underflow nor overflow (mixed operations) ---
    std::cout << "=== Explicit Tests: Neither state (mixed push/pop/peek) ===" << std::endl;

    if (stack.push(5)) {
        std::cout << "PASS: push(5) succeeded" << std::endl;
        passCount++;
    } else {
        std::cout << "FAIL: push(5) failed unexpectedly" << std::endl;
        failCount++;
    }

    if (stack.peek() == 5) {
        std::cout << "PASS: peek() returned 5" << std::endl;
        passCount++;
    } else {
        std::cout << "FAIL: peek() did not return 5" << std::endl;
        failCount++;
    }

    if (!stack.isEmpty()) {
        std::cout << "PASS: isEmpty() false after push" << std::endl;
        passCount++;
    } else {
        std::cout << "FAIL: isEmpty() true after push" << std::endl;
        failCount++;
    }

    stack.push(10);
    stack.push(15);

    if (stack.pop() == 15) {
        std::cout << "PASS: pop() returned 15 (LIFO order)" << std::endl;
        passCount++;
    } else {
        std::cout << "FAIL: pop() did not return 15" << std::endl;
        failCount++;
    }

    if (stack.peek() == 10) {
        std::cout << "PASS: peek() returned 10 after pop" << std::endl;
        passCount++;
    } else {
        std::cout << "FAIL: peek() did not return 10 after pop" << std::endl;
        failCount++;
    }

    stack.pop(); // removes 10, leaving just the original 5
    stack.pop(); // removes 5, stack is now empty

    if (stack.isEmpty()) {
        std::cout << "PASS: isEmpty() true after draining stack" << std::endl;
        passCount++;
    } else {
        std::cout << "FAIL: isEmpty() false after draining stack" << std::endl;
        failCount++;
    }

    // --- State 3: Overflow ---
    std::cout << "=== Explicit Tests: Overflow state ===" << std::endl;

    bool allPushed = true;
    for (int i = 0; i < STACKSIZE; i++) {
        if (!stack.push(i)) {
            allPushed = false;
        }
    }

    if (allPushed) {
        std::cout << "PASS: filled stack with STACKSIZE (" << STACKSIZE << ") values" << std::endl;
        passCount++;
    } else {
        std::cout << "FAIL: a push failed while filling the stack to capacity" << std::endl;
        failCount++;
    }

    if (!stack.push(999)) {
        std::cout << "PASS: push() on full stack returned false (overflow rejected)" << std::endl;
        passCount++;
    } else {
        std::cout << "FAIL: push() on full stack returned true" << std::endl;
        failCount++;
    }

    if (stack.peek() == STACKSIZE - 1) {
        std::cout << "PASS: peek() still shows last valid pushed value after rejected overflow push" << std::endl;
        passCount++;
    } else {
        std::cout << "FAIL: stack state corrupted after rejected overflow push" << std::endl;
        failCount++;
    }

    // Drain the full stack back to empty and confirm underflow detection still works
    for (int i = 0; i < STACKSIZE; i++) {
        stack.pop();
    }

    try {
        stack.pop();
        std::cout << "FAIL: pop() after draining full stack did not throw" << std::endl;
        failCount++;
    } catch (const std::underflow_error&) {
        std::cout << "PASS: pop() after draining full stack threw std::underflow_error" << std::endl;
        passCount++;
    }

    // ---------------------------------------------------------------
    // Section 2: Random testing, volume scaled to STACKSIZE
    // ---------------------------------------------------------------
    std::cout << "=== Random Tests ===" << std::endl;

    int randomOps = STACKSIZE * 100; // matches assignment's example ratio (1000 ops @ size 10, 10000 @ size 100)
    int currentSize = 0; // shadow count of what the stack should currently hold

    for (int i = 0; i < randomOps; i++) {
        int op = opDist(rng); // 0=push, 1=pop, 2=peek, 3=isEmpty

        switch (op) {
            case 0: { // push
                int value = valueDist(rng);
                bool expected = (currentSize < STACKSIZE);
                bool result = stack.push(value);
                if (result == expected) {
                    passCount++;
                    if (result) currentSize++;
                } else {
                    failCount++;
                    std::cout << "FAIL: push() result mismatch at op " << i << std::endl;
                }
                break;
            }
            case 1: { // pop
                try {
                    stack.pop();
                    if (currentSize > 0) {
                        passCount++;
                        currentSize--;
                    } else {
                        failCount++;
                        std::cout << "FAIL: pop() did not throw on empty stack at op " << i << std::endl;
                    }
                } catch (const std::underflow_error&) {
                    if (currentSize == 0) {
                        passCount++;
                    } else {
                        failCount++;
                        std::cout << "FAIL: pop() threw unexpectedly at op " << i << std::endl;
                    }
                }
                break;
            }
            case 2: { // peek
                try {
                    stack.peek();
                    if (currentSize > 0) {
                        passCount++;
                    } else {
                        failCount++;
                        std::cout << "FAIL: peek() did not throw on empty stack at op " << i << std::endl;
                    }
                } catch (const std::underflow_error&) {
                    if (currentSize == 0) {
                        passCount++;
                    } else {
                        failCount++;
                        std::cout << "FAIL: peek() threw unexpectedly at op " << i << std::endl;
                    }
                }
                break;
            }
            case 3: { // isEmpty
                bool expected = (currentSize == 0);
                bool result = stack.isEmpty();
                if (result == expected) {
                    passCount++;
                } else {
                    failCount++;
                    std::cout << "FAIL: isEmpty() mismatch at op " << i << std::endl;
                }
                break;
            }
        }
    }

    std::cout << "Random testing complete: ran " << randomOps
         << " operations (scaled to STACKSIZE = " << STACKSIZE << ")" << std::endl;

    // ---------------------------------------------------------------
    // Summary
    // ---------------------------------------------------------------
    std::cout << "=== Summary ===" << std::endl;
    std::cout << "Passed: " << passCount << std::endl;
    std::cout << "Failed: " << failCount << std::endl;

    return 0;
}
