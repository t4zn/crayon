#ifndef CRAYON_H
#define CRAYON_H
#include <stdio.h>
#include <stdarg.h>
#ifdef _WIN32
    #include <conio.h>
    #include <windows.h>
    #define SLEEP(ms) Sleep(ms)
#else
    #include <termios.h>
    #include <unistd.h>
    #define SLEEP(ms) usleep((ms) * 1000)
#endif



// Standard Foreground Colors
#define red         "\x1b[31m"
#define blue        "\x1b[34m"
#define yellow      "\x1b[33m"
#define green       "\x1b[32m"
#define black       "\x1b[30m"
#define white       "\x1b[37m"
#define cyan        "\x1b[36m"
#define magenta     "\x1b[35m"

// Extended Foreground Colors
#define orange      "\x1b[38;5;214m"
#define purple      "\x1b[38;5;93m"
#define gray        "\x1b[38;5;244m"
#define brown       "\x1b[38;5;94m"
#define pink        "\x1b[38;5;206m"
#define light_blue  "\x1b[38;5;39m"
#define navy        "\x1b[38;5;17m"
#define light_green "\x1b[38;5;119m"
#define dark_green  "\x1b[38;5;22m"
#define light_gray  "\x1b[38;5;250m"
#define charcoal    "\x1b[38;5;240m"
#define maroon      "\x1b[38;5;88m"
#define teal        "\x1b[38;5;30m"
#define lime        "\x1b[38;5;154m"
#define olive       "\x1b[38;5;100m"
#define gold        "\x1b[38;5;220m"
#define silver      "\x1b[38;5;7m"
#define beige       "\x1b[38;5;230m"
#define ivory       "\x1b[38;5;255m"
#define violet      "\x1b[38;5;129m"
#define crimson     "\x1b[38;5;196m"
#define lavender    "\x1b[38;5;183m"
#define turquoise   "\x1b[38;5;45m"
#define amber       "\x1b[38;5;214m"
#define bronze      "\x1b[38;5;136m"
#define peach       "\x1b[38;5;209m"
#define mustard     "\x1b[38;5;178m"
#define coral       "\x1b[38;5;203m"
#define burgundy    "\x1b[38;5;52m"

// Background Colors
#define bg_red         "\x1b[41m"
#define bg_blue        "\x1b[44m"
#define bg_yellow      "\x1b[43m"
#define bg_green       "\x1b[42m"
#define bg_black       "\x1b[40m"
#define bg_white       "\x1b[47m"
#define bg_cyan        "\x1b[46m"
#define bg_magenta     "\x1b[45m"

// Extended Background Colors
#define bg_orange      "\x1b[48;5;214m"
#define bg_purple      "\x1b[48;5;93m"
#define bg_gray        "\x1b[48;5;244m"
#define bg_brown       "\x1b[48;5;94m"
#define bg_pink        "\x1b[48;5;206m"
#define bg_light_blue  "\x1b[48;5;39m"
#define bg_navy        "\x1b[48;5;17m"
#define bg_light_green "\x1b[48;5;119m"
#define bg_dark_green  "\x1b[48;5;22m"
#define bg_light_gray  "\x1b[48;5;250m"
#define bg_charcoal    "\x1b[48;5;240m"
#define bg_maroon      "\x1b[48;5;88m"
#define bg_teal        "\x1b[48;5;30m"
#define bg_lime        "\x1b[48;5;154m"
#define bg_olive       "\x1b[48;5;100m"
#define bg_gold        "\x1b[48;5;220m"
#define bg_silver      "\x1b[48;5;7m"
#define bg_beige       "\x1b[48;5;230m"
#define bg_ivory       "\x1b[48;5;255m"
#define bg_violet      "\x1b[48;5;129m"
#define bg_crimson     "\x1b[48;5;196m"
#define bg_lavender    "\x1b[48;5;183m"
#define bg_turquoise   "\x1b[48;5;45m"
#define bg_amber       "\x1b[48;5;214m"
#define bg_bronze      "\x1b[48;5;136m"
#define bg_peach       "\x1b[48;5;209m"
#define bg_mustard     "\x1b[48;5;178m"
#define bg_coral       "\x1b[48;5;203m"
#define bg_burgundy    "\x1b[48;5;52m"


// Bright Colors
#define bright_red     "\x1b[91m"
#define bright_green   "\x1b[92m"
#define bright_yellow  "\x1b[93m"
#define bright_blue    "\x1b[94m"
#define bright_magenta "\x1b[95m"
#define bright_cyan    "\x1b[96m"
#define bright_white   "\x1b[97m"


// Formatting
#define bold      "\x1b[1m"
#define underline "\x1b[4m"
#define blink     "\x1b[5m"
#define invert    "\x1b[7m"
#define reset     "\x1b[0m"

// 256-Color Support
#define color(code) "\x1b[38;5;" #code "m"
#define bg_color(code) "\x1b[48;5;" #code "m"
void printz(const char *color, const char *format, ...) {
    va_list args;
    va_start(args, format); 
    printf("%s", color);   
    vprintf(format, args); 
    printf("%s", reset"\n"); 
    va_end(args);
}

void scanz(const char *color, const char *format, void *var) {
    printf("%s", color);

#ifdef _WIN32
    int ch, value = 0;
    while ((ch = getch()) != '\r') {
        if (ch >= '0' && ch <= '9') {
            printf("%c", ch);
            value = value * 10 + (ch - '0');
        }
    }
    *((int*)var) = value;

#else
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    scanf(format, var); 
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
#endif

    printf("%s", reset"\n");
}

void about() {
    printf(bold purple "\n[INFO] Taizun Kaptan - AI Developer \n" reset);
    printf(bold yellow "Passionate about AI, coding, and building unique projects.\n" reset);
    printf(bold magenta "Follow my journey in AI and development! \n" reset);
    printf(bold magenta "View complete documentation at:\nhttps://github.com/t4zn/crayon/blob/main/README.md \n" reset);

}
  
void banner(const char *color, const char *text) {
    printf("%s", color);
    int i;
    for (i = 0; text[i] != '\0'; i++) {
        printf("%c", text[i]);
        fflush(stdout);
        SLEEP(50);
    }
    printf("%s", reset"\n");
}
#endif // CRAYON_H
