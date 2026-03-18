# 🎮 so_long

*And thanks for all the fish!* **so_long** is a small 2D graphical game developed as part of the 1337 (42 Network) curriculum. The objective of this project is to create a top-down game where the player must collect all the items on a map and reach the exit, all while using the school's internal graphics library, **MiniLibX**.

---

## 📖 About The Project

This project serves as an introduction to basic game development in C. It bridges the gap between terminal-based programs and windowed applications, requiring you to handle textures, sprites, keyboard events, and window management.

Beyond just putting pixels on a screen, `so_long` demands rigorous algorithmic logic, specifically for **map validation** (ensuring the map is closed, rectangular, and has a valid path using algorithms like Flood Fill) and memory leak prevention.

### 🎯 Core Objectives
* Work with the **MiniLibX** (MLX) graphics library.
* Handle window creation, rendering, and destruction cleanly.
* Manage events and hooks (keyboard inputs, window close button).
* Parse and rigorously validate external configuration files (`.ber` maps).
* Implement pathfinding algorithms (Flood Fill) to ensure map solvability.

---

## ✨ Features & Gameplay

### The Rules
* The player's goal is to collect all collectibles (`C`) present on the map.
* Once all collectibles are gathered, the player must reach the exit (`E`).
* The player cannot move through walls (`1`).
* The game must display the current number of movements in the shell.

### Controls
| Key | Action |
| :---: | :--- |
| `W` / `↑` | Move Up |
| `A` / `←` | Move Left |
| `S` / `↓` | Move Down |
| `D` / `→` | Move Right |
| `ESC` | Close the game and exit cleanly |

---

## 🗺️ Map Configuration

The game loads maps from a `.ber` file. The map is constructed using the following characters:

* `0` : Empty space
* `1` : Wall
* `C` : Collectible
* `E` : Map exit
* `P` : Player's starting position

**Example of a valid map (`map.ber`):**
```text
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```

---

## 🛠️ Getting Started

### Prerequisites
* A standard C compiler (`cc`, `gcc`, or `clang`)
* `make` utility
* **MiniLibX** dependencies (Linux: X11 and Xext / macOS: OpenGL and AppKit)

### Installation & Compilation

1. Clone the repository:
   ```bash
   git clone [https://github.com/yuuryyy/So_long.git](https://github.com/yuuryyy/So_long.git)
   cd So_long
   ```

2. Compile the game:
   ```bash
   make
   ```
   This will compile your source files, link the MiniLibX library, and generate the `so_long` executable.

### Makefile Rules
* `make` / `make all`: Compiles the game.
* `make clean`: Removes the compiled `.o` object files.
* `make fclean`: Removes the object files and the `so_long` executable.
* `make re`: Runs `fclean` followed by `all`.

---

## 💻 Usage

To launch the game, run the executable followed by the path to a valid `.ber` map file.

```bash
./so_long maps/map.ber
```

*(Note: If you have a `maps/` directory in your repository, replace `map.ber` with any valid map file inside it).*

---
*Developed by Youssra Chagri at 1337 (UM6P).*
