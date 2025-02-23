# Crayon.h - The Ultimate Color and Text Formatting Library for C

Crayon.h is a powerful C header file that allows developers to easily add colors, text effects, and formatting to their terminal output. This library enhances text display using ANSI escape codes, making terminal output more engaging and visually appealing.

## Available Colors
**Text Colour Scheme:**
`printz(color(125), "This is a custom purple text!");`

 
![Crayon.h Logo](https://github.com/t4zn/crayon/blob/main/forecolors.png?raw=true)
**Background Colour Scheme:**

`printz(bg_color(226), "Yellow Background!");`
![Crayon.h Logo](https://github.com/t4zn/crayon/blob/main/bgcolor.png?raw=true)

**Standard:** red, blue, yellow, green, black, white, cyan, magenta

**Extended:** orange, purple, gray, brown, pink, light_blue, navy, light_green, dark_green, light_gray, charcoal, maroon, teal, lime, olive, gold, silver, beige, ivory, violet, crimson, lavender, turquoise, amber, bronze, peach, mustard, coral, burgundy

**Backgrounds:** bg_red, bg_blue, bg_yellow, bg_green, bg_black, bg_white, bg_cyan, bg_magenta, and extended background colors.

**Special Effects:** bold, underline, blink, invert, reset

## Installation

To use Crayon.h, download the file and place it in your compiler's include directory.

For MinGW (Windows):

1. Download `crayon.h` manually or use the following command:
   `irm "https://bit.ly/crayon-h" > "C:\Program Files (x86)\Dev-Cpp\MinGW64\include\crayon.h"`
2. Include it in your program with `#include <crayon.h>`.

For Linux/macOS:

1. Download `crayon.h` into `/usr/local/include/`.
2. Include it in your program with `#include <crayon.h>`.

## Usage

### Print Colored Text

To print text with colors, use the `printz()` function.
Example:
`printz(red, "This is red text");`

### Get User Input in Colored Format

To take colored user input, use `scanz()`.
Example:
`scanz(blue, "%d", &number);`

### Display a Banner Effect

To create a styled banner, use `banner()`.
Example:
`banner(green, "Welcome to Crayon!");`

### Special Effects

* **Rainbow Effect:** `rainbow("Hello World!");`
* **Neon Effect:** `neon("Glowing Text!");`
* **Coffee Theme:** `coffee("Smooth and Warm Text!");`

## About

Crayon.h was created by  **Taizun Kaptan** , an AI developer passionate about coding and creative programming. This library was designed to make terminal output visually stunning while maintaining simplicity in usage.

For full documentation, visit:
`https://github.com/t4zn/crayon/blob/main/README.md`
