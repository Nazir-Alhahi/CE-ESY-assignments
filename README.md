# CE-ESY-assignments
# Circular Buffer – Assignment 1

## Overview
This project implements a **Circular Buffer** in C.  
The circular buffer is a fixed-size data structure that works in a First-In-First-Out (FIFO) manner, handling memory in a circular way to avoid shifting elements during consumption.

## Difference Between Circular and Linear Buffer
- **Linear Buffer:** When reading an element from the front, all remaining elements must be shifted to the left, leading to O(n) time complexity.
- **Circular Buffer:** Uses two pointers (`head` for reading and `tail` for writing) that rotate within the array. When they reach the end of the array, they wrap around to the beginning. This makes insertion and deletion happen in constant time O(1).

## Working Mechanism and Pointer Handling
- **Initialization:** `head = 0`, `tail = 0`, `count = 0` (buffer is empty).
- **Writing (Enqueue):** The character is placed at the `tail` position, then `tail` moves forward with wrapping (`% size`), and the counter increments.
- **Reading (Dequeue):** The character is retrieved from the `head` position, then `head` moves forward with wrapping, and the counter decrements.
- **Full:** When `count == size` (no new element can be written).
- **Empty:** When `count == 0` (no element can be read).

## Main Functions
- `init()`: Allocates memory and sets the pointers.
- `isFull()`, `isEmpty()`: Check the buffer status.
- `write()`: Adds a character and handles the Overflow condition.
- `read()`: Reads a character and returns `EOF` with a message in case of Underflow.
- `destroy()`: Frees the allocated memory for the array.

## `main` Requirements
1. Input the user's name.
2. Append the string `CE-ESY` to the name.
3. Store the result character by character in the circular buffer.
4. Read the content back and display it on the screen.
5. Confirm that the buffer is empty after reading.
6. Ability to try two different buffer sizes (smaller and larger than the text length) to verify Overflow and its absence.
