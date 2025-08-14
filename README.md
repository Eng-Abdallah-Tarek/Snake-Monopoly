# SnakeMonopoly

## Project Overview

SnakeMonopoly is a C++ project that simulates a board game similar to Snakes and Ladders, with additional features such as cards, players, and a graphical user interface. The project is structured using Object-Oriented Programming (OOP) principles to ensure modularity, reusability, and maintainability.

---
...

## Project Assets

All project-related images, including screenshots and UML diagrams, are stored in the [`assets/`](assets) directory:

- **Screenshots:** Place gameplay or UI screenshots in [`assets/screenshots/`](assets/screenshots).
- **UML Diagrams:** Place your UML class or sequence diagrams in [`assets/uml/`](assets/uml).

### Example

- [`assets/screenshots/main_menu.png`](assets/screenshots/main_menu.png) – Main menu screenshot
- [`assets/uml/class_diagram.png`](assets/uml/class_diagram.png) – UML class diagram

You can reference these images in the README like this:

```markdown
![Main Menu](assets/screenshots/main_menu.png)
![Class Diagram](assets/uml/class_diagram.png)
```

---

## Project Structure

```
.
├── ApplicationManager.h/.cpp
├── Grid.h/.cpp
├── Cell.h/.cpp
├── CellPosition.h/.cpp
├── GameObject.h/.cpp
│   ├── Ladder.h/.cpp
│   ├── Snake.h/.cpp
│   └── Card.h/.cpp
│       ├── CardOne.h/.cpp
│       ├── CardTwo.h/.cpp
│       └── ... (other card types)
├── Player.h/.cpp
├── Input.h/.cpp
├── Output.h/.cpp
├── DEFS.h
├── UI_Info.h
├── Main.cpp
├── CMUgraphicsLib/
│   ├── CMUgraphics.h/.cpp
│   ├── windowinput.h/.cpp
│   ├── mousequeue.h/.cpp
│   └── ... (other graphics support files)
└── ...
```

---

## OOP Design and Hierarchy

### 1. **Core Classes**

- **`ApplicationManager`**  
  The main controller class that manages the game flow, user actions, and coordinates between the UI and the game logic.

- **`Grid`**  
  Represents the game board. Manages cells, players, and game objects (ladders, snakes, cards).

- **`Cell`**  
  Represents a single cell on the grid. Can contain a game object.

- **`CellPosition`**  
  Encapsulates the position of a cell on the grid.

### 2. **Game Objects (Inheritance & Polymorphism)**

- **`GameObject`** (Abstract Base Class)  
  The base class for all objects that can be placed on the grid.  
  - **`Ladder`**  
    Represents a ladder object.
  - **`Snake`**  
    Represents a snake object.
  - **`Card`** (Abstract)  
    Base class for all card types.  
    - **`CardOne`, `CardTwo`, ...**  
      Derived classes for each specific card type, implementing their own behavior.

  This hierarchy demonstrates **inheritance** and **polymorphism**. The grid can store pointers to `GameObject`, allowing it to handle ladders, snakes, and cards uniformly.

### 3. **Player Class**

- **`Player`**  
  Represents a player in the game, holding information such as position, wallet, and turn logic.

### 4. **User Interface Classes**

- **`Input`**  
  Handles all user input (mouse clicks, keyboard input).

- **`Output`**  
  Handles all graphical output, drawing the grid, players, and messages.

- **`CMUgraphicsLib`**  
  A graphics library providing window management and drawing primitives.

### 5. **Supporting Files**

- **`DEFS.h`**  
  Contains global definitions and enumerations (e.g., `ActionType`).

- **`UI_Info.h`**  
  Stores UI configuration and constants.

---

## OOP Principles in the Project

- **Encapsulation:**  
  Each class encapsulates its own data and behavior. For example, `Player` manages its own state, and `Grid` manages the board state.

- **Inheritance:**  
  The `GameObject` class is the base for all objects that can be placed on the grid. Cards, ladders, and snakes inherit from `GameObject`.

- **Polymorphism:**  
  The grid and other components interact with game objects through base class pointers (`GameObject*`), allowing for flexible and extensible game logic.

- **Abstraction:**  
  Abstract classes like `GameObject` and `Card` define interfaces for derived classes, hiding implementation details.

---

## How to Build and Run

1. Open the project in your C++ IDE (e.g., Visual Studio).
2. Build the solution.
3. Run the executable.

---

## Extending the Project

To add new cards or game objects, simply derive a new class from `Card` or `GameObject` and implement the required virtual functions.

---

## License

See [CMUgraphicsLib/version.h](CMUgraphicsLib/version.h) for licensing information regarding the graphics library.
