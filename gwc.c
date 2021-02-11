#include <stdio.h>

#define MAXHEIGHT 10                    /* y axis length */
#define MAXWIDTH 40                     /* x axis length */
#define GRAPHLENGTH 40                  /* vertical graph length multiplier */
#define START_DRAWING_LINE_GRAPH 2      /* controls where on the Y axis line graph is starting */
#define IN 1
#define OUT 0

void drawGraph(int lines, int words, int chars);

/* Count characters, words, lines and display data in a graph */
int main(int argc, char *argv[]) {
    /* if (argc == 1) { */
    /*     printf("No input file\n"); */
    /*     return 1; */
    /* } */

    int c = 0;
    int nchar = 0;   /* number of characters */
    int nwords = 0;  /* number of words */
    int nlines = 0;  /* number of lines */
    int state = OUT;

    /* while ((c = getchar()) != EOF) { */
    /*     ++nchar; */
    /*     if (c == '\n') */
    /*         ++nlines; */
    /*     if (c == ' ' || c == '\n' || c == '\t') */
    /*         state = OUT; */
    /*     else if (state == OUT) { */
    /*         state = IN; */
    /*         ++nwords; */
    /*     } */
    /* } */


    drawGraph(100, 200, 200);

    return 0;
}


void drawGraph(int lines, int words, int chars) {
    int denominator = chars + words + lines;
    double lines_ratio = (double) lines / denominator;
    double words_ratio = (double) words / denominator;
    double chars_ratio = (double) chars / denominator;
    double line_graph_length = GRAPHLENGTH * lines_ratio;
    double word_graph_length = GRAPHLENGTH * words_ratio;
    double char_graph_length = GRAPHLENGTH * chars_ratio;
    printf("Denominator is %d\n", denominator);
    printf("lines ratio  is %f\n", lines_ratio);
    printf("words ratio  is %f\n", words_ratio);
    printf("chars ratio  is %f\n", chars_ratio);

    for (int i = 0, y = 0; i < MAXHEIGHT; ++i, ++y)
        if (y == START_DRAWING_LINE_GRAPH && line_graph_length != 0) {
            printf("|");
            for (int i = 0; i < line_graph_length; ++i)
                printf(" -");
            printf("\n");
            printf("|");
            for (int i = 0; i < line_graph_length; ++i)
                printf("  ");
            printf("|\n");
            printf("|");
            for (int i = 0; i < line_graph_length; ++i)
                printf("  ");
            printf("| %d line(s)\n", lines);
            printf("|");
            for (int i = 0; i < line_graph_length; ++i)
                printf("  ");
            printf("|\n");
            printf("|");
            for (int i = 0; i < line_graph_length; ++i)
                printf(" -");
            printf("\n");
        } else if (y == START_DRAWING_LINE_GRAPH && line_graph_length == 0) {
            printf("|%d lines\n", lines);
        } else if (y == 5) {
            printf("|");
            for (int i = 0; i < word_graph_length; ++i)
                printf(" -");
            printf("\n");
            printf("|");
            for (int i = 0; i < word_graph_length; ++i)
                printf("  ");
            printf("|\n");
            printf("|");
            for (int i = 0; i < word_graph_length; ++i)
                printf("  ");
            printf("| %d word(s)\n", words);
            printf("|");
            for (int i = 0; i < word_graph_length; ++i)
                printf("  ");
            printf("|\n");
            printf("|");
            for (int i = 0; i < word_graph_length; ++i)
                printf(" -");
            printf("\n");

        } else if (y == 8) {
            printf("|");
            for (int i = 0; i < char_graph_length; ++i)
                printf(" -");
            printf("\n");
            printf("|");
            for (int i = 0; i < char_graph_length; ++i)
                printf("  ");
            printf("|\n");
            printf("|");
            for (int i = 0; i < char_graph_length; ++i)
                printf("  ");
            printf("| %d character(s)\n", chars);
            printf("|");
            for (int i = 0; i < char_graph_length; ++i)
                printf("  ");
            printf("|\n");
            printf("|");
            for (int i = 0; i < char_graph_length; ++i)
                printf(" -");
            printf("\n");
        } else {
            printf("|\n");
        }
    printf("0");
    for (int i = 0; i < MAXWIDTH; ++i)
        printf(" -");
    printf("\n");
}
