# Sudoku game

![GitHub repo size](https://img.shields.io/github/repo-size/MloGit/Sudoku)
![GitHub license](https://img.shields.io/github/license/MloGit/Sudoku)

Sudoku game in C that runs in the linux terminal.

The purpose off this project was to help me to learn and experiment with testing concepts and test driven development.

## Prerequisites

Before you begin, ensure you have met the following requirements:

* A C compiler (GCC is required for helper scripts)
* A Linux machine.
* The testing tools are included in the project repo.

## Installing the sudoku game

To install the game, follow these steps:

1. Clone the repo

    ```bash
    git clone https://github.com/MloGit/Sudoku
    ```

2. Compile and run game

    ```bash
    cd scripts
    ./run_game.sh
    ```

## Using the sudoku game

| Command   |                  Explanation |
| :-------- | ---------------------------: |
| enter (e) | Prompts number entry to cell |
| help      |            Show all commands |
| quit (q)  |                    Quit game |

Use help in game to get the full list.

## Testing

The tests are implemented with the Unity, CMock and Ceedling. These tools, along with their documentation, are included with the project.

### Unit tests

The unit tests uses a text file to redirect input for some of the unit tests. This is included in the helper script for the unit tests.

```bash
./run_unit_tests.sh
```

### Integration tests

The integration tests are hierarchical, so if one fails the rest will likely fail as well. The helper script guides you through the execution of these tests.

```bash
./run_integration_tests.sh
```

## License

This project is [MIT](LICENSE) licensed.
