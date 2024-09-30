#include <linkedList.h>
#include <linkedListOfMusic.h>
#include <stdio.h>
#include <stdlib.h>

Liste readMusics(FILE *f);
Liste sortMusics(Liste toBeSorted);
void printMusics(FILE *f, Liste toBePrinted);

int main(int argc, char *argv[]) {
    int mustSort = 0;
    char *input_file;
    char *output_file;
    input_file = "music.csv";
    output_file = "out.csv";
    for(int i=1; i<argc; i++) {
        if(!strcmp(argv[i], "-i") && (i + 1 < argc)) {
            input_file = argv[i+1];
        }
        if(!strcmp(argv[i], "-o") && (i + 1 < argc)) {
            output_file = argv[i+1];
        }
        if(!strcmp(argv[i], "--sort")) {
            mustSort = 1;
        }
    }

    char inFilePath[256];
    char outFilePath[256];
    sprintf(inFilePath, "../TP4-ListeChainee/V2/%s", input_file);
    sprintf(outFilePath, "../TP4-ListeChainee/V2/%s", output_file);

    printf("../TP4-ListeChainee/V2/%s", output_file);

    FILE *pFile = fopen(inFilePath,"r");
    Liste result = readMusics(pFile);
    fclose(pFile);


    pFile = fopen(outFilePath, "w");
    if (mustSort) {
        sortMusics(&result);
    }
    printMusics(pFile, &result);
    fclose(pFile);
    freeList(result);
}

Liste readMusics(FILE *f) {
    char lineBuffer[2048];
    Music *currentMusic;
    while (fgets(lineBuffer, sizeof(lineBuffer), f)) {
        currentMusic = malloc(sizeof(Music));
        
        // Duplicate the line because strsep modifies it
        char *line_copy = strdup(lineBuffer);

        char *token;
        
        token = strsep(&line_copy, ",");
        if (token != NULL) 
            currentMusic->title = strdup(token);
        token = strsep(&line_copy, ",");
        if (token != NULL) 
            currentMusic->artist = strdup(token);
        token = strsep(&line_copy, ",");
        if (token != NULL)
            currentMusic->album = strdup(token);
        token = strsep(&line_copy, ",");
        if (token != NULL) 
            currentMusic->genre = strdup(token);
        if (token != NULL) 
            currentMusic->disc = strdup(token); //TODO atoi
        if (token != NULL) 
            currentMusic->track = strdup(token);
        if (token != NULL) 
            currentMusic->year = strdup(token);

        // Now, we have populated the struct 'p'
        printf("Name: %s, Age: %d, Height: %.2f\n", p.name, p.age, p.height);

        // Free the allocated memory for the struct fields
        free_person(&p);
        free(line_copy);  // Free the duplicated line
    }
}

Liste sortMusics(Liste toBeSorted) {

}

void printMusics(FILE *f, Liste toBePrinted) {

}