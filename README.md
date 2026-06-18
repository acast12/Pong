# Pong

A Pong variant written in C++ using the SFML graphics library, built with a finite state machine architecture to manage game flow (splash screen, main menu, gameplay, and end state).

## Architecture

The game is structured around a `StateMachine` that manages transitions between distinct game states, each implemented as its own class:

- **SplashState** — initial splash/loading screen
- **MainMenuState** — main menu and game start
- **GameState** — core gameplay loop
- **EndState** — game over / result screen

Gameplay objects (`Ball`, `Paddle`, `Enemy`) are encapsulated as their own classes with their own update and render logic, keeping the core game loop in `Game.cpp` clean and focused on orchestration rather than entity-specific behavior.

```
main.cpp
  └── StateMachine
        ├── SplashState
        ├── MainMenuState
        ├── GameState
        │     ├── Ball
        │     ├── Paddle
        │     └── Enemy
        └── EndState
```

## Why a state machine

Rather than hardcoding screen transitions with flags and conditionals, each screen is its own self-contained state with its own update/render/handle-input logic. The `StateMachine` holds a stack of active states, push/pop transitions between them (e.g. menu → game, game → end state), and each state only needs to know about itself, not the others. This is the same pattern used in most production game engines for managing menus, gameplay, and pause screens cleanly.

## Built with

- **C++**
- **SFML** — Simple and Fast Multimedia Library, used for rendering, window management, and input handling

## Setup

Built using Visual Studio (`Pong.sln` / `Pong.vcxproj`).

1. Install [SFML](https://www.sfml-dev.org/download.php) and link it in your Visual Studio project settings
2. Open `Pong.sln` in Visual Studio
3. Build and run

## Controls

- Player paddle: Up/Down arrow keys (or W/S, depending on build configuration)
- Goal: don't let the ball pass your paddle

## Notes

This was an early project focused on learning object-oriented design patterns in C++ — specifically separating game logic into discrete, swappable states rather than a single monolithic game loop.
