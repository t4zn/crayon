#ifndef CRAYON_H
#define CRAYON_H

#include <stdio.h>
#include <stdarg.h>

// Standard Colors
#define red     "\x1b[31m"
#define green   "\x1b[32m"
#define yellow  "\x1b[33m"
#define blue    "\x1b[34m"
#define magenta "\x1b[35m"
#define cyan    "\x1b[36m"
#define white   "\x1b[37m"
#define black   "\x1b[30m"

// Bright Colors
#define bright_red     "\x1b[91m"
#define bright_green   "\x1b[92m"
#define bright_yellow  "\x1b[93m"
#define bright_blue    "\x1b[94m"
#define bright_magenta "\x1b[95m"
#define bright_cyan    "\x1b[96m"
#define bright_white   "\x1b[97m"

// Background Colors
#define bg_red     "\x1b[41m"
#define bg_green   "\x1b[42m"
#define bg_yellow  "\x1b[43m"
#define bg_blue    "\x1b[44m"
#define bg_magenta "\x1b[45m"
#define bg_cyan    "\x1b[46m"
#define bg_white   "\x1b[47m"
#define bg_black   "\x1b[40m"

// Formatting
#define bold      "\x1b[1m"
#define underline "\x1b[4m"
#define blink     "\x1b[5m"
#define invert    "\x1b[7m"
#define reset     "\x1b[0m"

// 256-Color Support
#define color(code) "\x1b[38;5;" #code "m"
#define bg_color(code) "\x1b[48;5;" #code "m"



// Updated printz() Function
void printz(const char *color, const char *format, ...) {
    va_list args;
    va_start(args, format); 
    printf("%s", color);   
    vprintf(format, args); 
    printf("%s", reset"\n"); 
    va_end(args);
}

// Function to Print Info About Taizun
void about() {
    printf(bold cyan "\n[INFO] Taizun Kaptan - AI Developer \n" reset);
    printf(bold yellow "Passionate about AI, coding, and building unique projects.\n" reset);
    printf(bold magenta "Follow my journey in AI and development! \n" reset);
}

#endif // CRAYON_H
