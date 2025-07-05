# Snake Game in C++ (Windows & Linux)

## Description
This is a simple snake game created using the C++ programming language. The game can be played on both **Windows** and **Linux** platforms.

## System Requirements
- **Windows**: Windows 7 or newer  
- **Linux**: Ubuntu or other Linux distributions

## Installing a C++ Compiler

### For Windows
1. **Install MinGW**:
   - Download MinGW from the official website: [MinGW Download](https://sourceforge.net/projects/mingw-w64/).
   - Choose the 64-bit version and follow the installation instructions.
   - Add the `bin` folder from MinGW to your **Path Environment Variable** (e.g., `C:\MinGW\bin`).

2. **Install a Code Editor**:
   - Use a code editor like **Visual Studio Code** or **Code::Blocks**. You can download Visual Studio Code [here](https://code.visualstudio.com/).

3. **Verify Installation**:
   - Open Command Prompt and type:
     ```bash
     g++ --version
     ```
     If installed correctly, it will show the installed version of g++.

### For Linux
1. **Install GCC**:
   - Open the terminal and run the following commands:
     ```bash
     sudo apt update
     sudo apt install build-essential
     ```

2. **Verify Installation**:
   - After installation, check if GCC is installed by running:
     ```bash
     g++ --version
     ```

## How to Run the Game

### For Windows
1. After installing MinGW and a code editor, open **Command Prompt**.
2. Navigate to the folder where the game file `snake_game.cpp` is located.
3. Compile the program using:
   ```bash
   g++ ularwindows.cpp -o snake_game.exe
   ```
4. Run the game:
   ```bash
   .\snake_game.exe
   ```

### For Linux Ubuntu / Debian
1. After installing the C++ compiler, open **Terminal**.
2. Navigate to the folder where the game file `snake_game.cpp` is located.
3. Compile the program using:
   ```bash
   g++ ular.cpp -o snake_game
   ```
4. Run the game:
   ```bash
   ./snake_game
   ```

---

Happy coding and have fun with the snake! 🐍🎮
