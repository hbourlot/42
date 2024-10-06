#	So_Long (Pacman)- 42 School Lisbon

### Table of Contents
* [Introduction](#introduction-)
* [Install](#install-)
* [How to Play?](#how-to-play-)
* [Project Objectives](#project-objectives-)
* [Pacman-Themed Mechanics](#pacman-themed-mechanics-)
* [Conclusion](#conclusion-)

##	Introduction 📖

So_Long is a graphical project from 42 School where students are tasked with building a small 2D game using the minilibX library. The project’s primary goal is to create a game where the player navigates through a map, collects items, and reaches an exit. In my version of the so_long project, I’ve recreated the classic Pacman game, adapting its core mechanics into the structure required by the project.

This Pacman-themed version incorporates the original game’s nostalgic elements: the player-controlled Pacman navigates the maze, collects dots, avoids ghosts, and heads towards the goal — while adhering to the specific requirements of the so_long project.

##	Install 🛠️

**Steps**
```
apt-get update
apt-get	upgrade
apt install libx11-dev
apt install libxext-dev
apt install libbsd-dev
apt install clang
```

## How to Play? 👾

Playing the Pacman-themed version of So_Long is simple. Follow these steps to get started:

**Running the Game**:

1.	***Build the Game***:
Open your terminal and navigate to the game directory, then run:
```
make
```
or
```
make pacman
```
2.	***Start the Game***:
After the build process completes, you can run the game with:
```
./so_long MAP/"your_map.ber"
```
Replace "your_map.ber" with the name of the map file you wish to load. 

***Controls 🎮***:

Use the arrow keys to move Pacman in the maze:

	•	Up Arrow or W : Move up
	•	Down Arrow or D : Move down
	•	Left Arrow or A : Move left
	•	Right Arrow or D : Move right

##	Project Objectives 🎯

The so_long project focuses on mastering essential programming and game development concepts, such as:

	•	Rendering a 2D grid: Using minilibX, students must render a map from a file into a window, with each tile of the map being displayed as a sprite (e.g., walls, player, collectibles, etc.).
	•	Player Movement: The player should be able to move up, down, left, and right, and this movement should be reflected in real-time.
	•	Collectibles and Exit: Pacman (the player) must collect all the dots before accessing the exit.
	•	Basic AI for Ghosts: In my adaptation, ghosts act as obstacles that move according to a basic AI algorithm.
	•	Game Events: The game must handle keypress events, collision detection, and end the game when the player wins or loses.

##	Pacman-Themed Mechanics 🧑‍🔧

In my Pacman-themed version, I’ve implemented the following key elements:

	•	Pacman (Player): The player controls Pacman, who moves through the maze and collects dots scattered around the map.
	•	Ghosts: The ghosts act as the enemies, similar to the original game. They move across the grid and chase Pacman.
	•	Dots (Collectibles): Pacman must collect all the dots before he can reach the exit.
	•	Power Pellets: Optional power-ups allow Pacman to become invincible temporarily and “eat” the ghosts.
	•	Map Design: The game takes place on a classic Pacman-style maze, with walls, paths, and ghosts navigating the map.

The game operates on a loop, refreshing the screen with each movement and redrawing the grid, much like in traditional 2D games.

How the Game Works

	•	The map is loaded from a .ber file, which defines the maze layout, including walls, paths, collectibles, the player’s start position, and the exit.
	•	Pacman moves across the grid using the arrow keys, and each move updates the window.
	•	Ghosts move autonomously, trying to catch Pacman. If Pacman collides with a ghost, the game ends.
	•	The game finishes when Pacman collects all the dots and reaches the exit, or when he is caught by a ghost.

MinilibX Integration

The so_long project requires the use of minilibX, a simple graphics library that facilitates window creation, sprite rendering, and key event handling. The game renders sprites for Pacman, ghosts, walls, dots, and other elements, giving it a retro arcade-style appearance.

Project Requirements

	•	2D Rendering: Render a grid-based map using sprites.
	•	Movement: Player movement with real-time feedback, collision detection, and basic AI for enemies.
	•	Game Termination: The game should end when Pacman is caught by a ghost or reaches the exit after collecting all items.
	•	Error Handling: Ensure that invalid maps or file inputs are handled gracefully, and the game does not crash unexpectedly.

##	Conclusion ✅

This Pacman-themed version of the so_long project provides a fun and interactive take on the original game while meeting all the requirements of the 42 School project. Through this project, I’ve gained deeper insights into game mechanics, event handling, and rendering using the minilibX library.

Feel free to explore the code, try out the game, and contribute if you’d like!
