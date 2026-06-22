# Simple Int Stack

## Description

A simple int stack ADT implemented in C++ for COSC 2436, Assignment 4. The `Stack` class
is backed by a fixed-size array and supports `push`, `pop`, `peek`, and `isEmpty`. Underflow
on `pop`/`peek` is signaled via a thrown `std::underflow_error`; overflow on `push` is signaled
via a `false` return value. `main.cpp` is a flat testbed that explicitly exercises every
operation against every possible stack state (underflow, overflow, neither), then runs a batch
of randomized operations scaled to the stack's capacity.

## Build Instructions

```
g++ -I ./ *.cpp -o stack_test
```

## Run Instructions

```
./stack_test
```

The program prints `PASS`/`FAIL` for each explicit test, runs the randomized test batch, and
ends with a pass/fail summary.

## Project Structure

- `stack.h` / `stack.cpp` — the `Stack` ADT
- `main.h` / `main.cpp` — testbed; all test code lives directly in `main()`

## Special Instructions

- The stack's capacity is the `STACKSIZE` constant defined in `stack.h` (default `10`).
  Changing this value and rebuilding requires no other code changes — the random test
  batch size (`STACKSIZE * 100` operations) and the explicit overflow/underflow checks
  both scale automatically with it.

## Special Requirements

- A C++17-capable compiler (`g++` recommended; this is graded by compiling with `g++`
  on Linux from the command line).

## Special Dependencies

- None beyond the C++ standard library (`<iostream>`, `<random>`, `<stdexcept>`).

## Special Notes

- Per assignment requirements, `main()` is intentionally a single, flat function with no
  helper functions — modularity in `main()` is out of scope for this assignment.
