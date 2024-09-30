#pragma ONCE

typedef struct {
    char *title;
    char *artist;
    char *album;
    char *genre;
    int disc;
    int track;
    int year;
} Music;

bool equalsChars(char *e1, char *e2);
