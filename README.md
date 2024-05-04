# SDL2 Draw Circle

This program demonstrates how to draw a circle using SDL2 in C. It creates a window and draws a circle in it using simple pixel-based rendering techniques.

## Prerequisites

To compile and run this program, you need to have the SDL2 library installed on your system. You can download SDL2 from the official website: [SDL2 Download](https://www.libsdl.org/download-2.0.php).

The colors of this programs taken from [Here](https://www.rapidtables.com/web/color/RGB_Color.html).

## Building and Running

1. Clone or download the repository to your local machine.
    ```bash
    git clone https://github.com/nazmul11011/2022831042.git
2. Ensure that SDL2 is installed on your system.
3. Compile the program using a C compiler. For example, if you're using GCC, you can compile it with the following command:
    ```bash
    g++ -I src/include -L src/lib -o TASK101 TASK101.cpp -lmingw32 -lSDL2main -lSDL2
    g++ -I src/include -L src/lib -o TASK102 TASK102.cpp -lmingw32 -lSDL2main -lSDL2
    g++ -I src/include -L src/lib -o TASK103 TASK103.cpp -lmingw32 -lSDL2main -lSDL2

I have already provided the Makefile. You can use make package to compile all the files with sing command.
    ```bash
    
    make
4. Run the compiled executable:
    ```bash
    ./TASK101
    ./TASK102
    ./TASK103

## Usage

### TASK1011

Upon running the `TASK101` program, a window titled "Circle drawing" will appear, displaying a red circle at the center. The window will remain open until you close it manually.

To compile and run `TASK101`, follow the same steps mentioned in the "Building and Running" section above for compiling and running the program.

Feel free to experiment with the code or modify it according to your requirements.

Enjoy exploring the `TASK101` program!

### TASK102

Upon running the `TASK102` program, it will draw expanding circles on the screen. The circles start from the center and grow outward gradually. The size and speed of expansion can be adjusted by modifying the parameters such as `SCREEN_WIDTH`, `SCREEN_HEIGHT`, `INITIAL_RADIUS`, and `RADIUS_INCREMENT` in the source code.

To compile and run `TASK102`, follow the same steps mentioned in the "Building and Running" section above for compiling and running the program.

Experiment with the code by tweaking the parameters to observe different behaviors of the expanding circles.

Enjoy exploring the `TASK102` program!

### TASK103

The `TASK103` program demonstrates interactive moving circles with bounce effect. It creates two circles on the screen, one of which moves horizontally, while the other moves vertically. When these circles collide with the window boundaries, they bounce off. Feel free to experiment with the code or modify it according to your requirements.

To move the circle you need to use "Up", "Down", "Left", "Right" arrow key.

Enjoy exploring the `TASK103` program!

## Contributing

Contributions are welcome! If you find any issues with the code or have suggestions for improvements, feel free to open an issue or submit a pull request.
