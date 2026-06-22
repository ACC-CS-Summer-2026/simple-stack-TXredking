# AI Statement and Essay

## Assignment 4 — Simple Stack
**Course:** COSC 2436  
**Name:** Rory McLaughlin  
**Date:** 2026-06-21

---

1. **Explain your AI usage — what you used and why.**

   I used AI in the following ways:
   - To implement the main.cpp testbed (explicit tests for every stack state, plus randomized tests scaled to STACKSIZE).
   - To review my hand-written stack.h/stack.cpp line-by-line as I went, catching syntax and logic bugs (a malformed constructor, an invalid `throw` statement, a stray `===` operator, a method name mismatch with the header).
   - To explain concepts I was unsure about, such as exceptions vs. pass-by-reference for signaling pop/peek errors, and how the `<random>` engine/distribution classes work.
   - To check this course's own notes (compile command, submission checklist) instead of guessing, which surfaced rules I wasn't applying correctly.
   - To review and revise code comments, the README, and this essay for clarity and structure.

2. **An error AI made that you caught and corrected (or explain why AI made no errors).**

   The first version of main.cpp that AI wrote used `using namespace std;` and put standard-library `#include`s (`<iostream>`, `<random>`, `<stdexcept>`) directly in main.cpp instead of main.h. Both of those violate this course's Submission Checklist, which explicitly requires that a .cpp file include only its own matching header, and forbids `using namespace std;`. I caught this by asking AI to check the course's own grading/checklist notes rather than assume, and we fixed it by moving the includes into main.h and qualifying every standard-library name with `std::`.

3. **AI code that was correct but you improved (or explain why there was no such case).**

   AI's first version of the random-testing loop used the older `rand()`/`srand()` pattern. It would have worked correctly, but I had it switched to the more modern `<random>` facilities (`std::random_device`, `std::mt19937`, `std::uniform_int_distribution`) for better randomness quality and to avoid manually managing a global seed.

4. **Something you learned by using AI that you didn't know before (or explain why you learned nothing new).**

   I hadn't used the `<random>` header's engine/distribution model before — only `rand() % n`. Understanding how `random_device` seeds the `mt19937` engine, and how a `uniform_int_distribution` maps the engine's output into a bounded range, was new to me. I also better understand the tradeoff between exceptions and pass-by-reference for error signaling when a function's return type can't double as an error code.

5. **Whether you think you could have done better without AI, and why.**

   The end result would likely have been functionally similar without AI, given the program's low complexity. That said, AI caught real bugs faster than I would have on my own (including in its own generated code), and saved time on comment/README cleanup and on quickly explaining C++ facilities I don't use day-to-day.
