# Interview Puzzle Solutions (C++)

This repository contains solutions to three algorithmic and mathematical interview puzzles implemented in **C++**. Each solution is written with readability, efficiency, and interview best practices in mind.

---

## Repository Structure

```
Interview-Puzzles/
│
├── AppleGatePuzzle.cpp
├── LiftMinimumEnergy.cpp
├── ChessboardSquaresRectangles.cpp
└── README.md
```

---

## 1. Apple Gate Puzzle

### Problem Statement

A person has some apples and must pass through **M gates**.

At every gate, the person gives away:

```
(Current Apples / 2) + 1
```

After crossing the final gate, exactly **1 apple** remains.

Determine the **minimum number of apples initially required**.

### Approach

Instead of simulating forward, the solution works **backwards** from the final state.

If `x` apples remain after a gate, then before crossing that gate the person must have had:

```
2 × (x + 1)
```

Repeat this calculation for all gates.

**Time Complexity:** O(M)

**Space Complexity:** O(1)

---

## 2. Lift Minimum Energy

### Problem Statement

A building has **20 floors**.

The lift starts at floor **K**.

Energy consumption rules:

- Starting the lift costs **5 units**
- Moving between adjacent floors costs **1 unit per floor**

Given a sequence of floor requests, calculate the total energy required to serve all requests.

### Approach

For each request:

- Add the lift startup cost.
- Add the distance travelled from the current floor.
- Update the current floor.

**Time Complexity:** O(N)

**Space Complexity:** O(1)

---

## 3. Count Squares and Rectangles

### Problem Statement

Given an **N × N chessboard**, determine:

- Total number of squares
- Total number of rectangles

### Mathematical Formula

**Squares**

```
N(N+1)(2N+1)/6
```

**Rectangles**

```
(N(N+1)/2)^2
```

These formulas allow both answers to be computed in constant time.

**Time Complexity:** O(1)

**Space Complexity:** O(1)

---

## Language

- C++17

---

## Skills Demonstrated

- Mathematical Problem Solving
- Greedy Thinking
- Reverse Computation
- Formula Derivation
- Algorithm Design
- Time Complexity Optimization
- Interview Coding

---

## Author

**Chetan Sharma**
