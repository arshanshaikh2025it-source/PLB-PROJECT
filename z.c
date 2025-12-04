/*  
   DIGITAL LEARNING ASSISTANT  
   ---------------------------------
   A ~200 line C program demonstrating:
   - Strings
   - Functions
   - Animation
   - Interactive menu
   - Learning slides
   - Quiz
   - Terminal control
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef _WIN32
#include <windows.h>
#define CLEAR() system("cls")
#define SLEEP(ms) Sleep(ms)
#else
#include <unistd.h>
#define CLEAR() system("clear")
#define SLEEP(ms) usleep(ms * 1000)
#endif

//--------------------------------------------------------------
// Function: typewriter effect printing
//--------------------------------------------------------------
void type_print(const char *text, int delay) {
    for (int i = 0; i < strlen(text); i++) {
        putchar(text[i]);
        fflush(stdout);
        SLEEP(delay);
    }
}

//--------------------------------------------------------------
// Function: Display animated welcome banner
//--------------------------------------------------------------
void banner() {
    const char *msg = "WELCOME TO THE DIGITAL LEARNING ASSISTANT";
    for (int i = 0; i < strlen(msg); i++) {
        putchar(msg[i]);
        fflush(stdout);
        SLEEP(40);
    }
    printf("\n-----------------------------------------------------\n");
    SLEEP(500);
}

//--------------------------------------------------------------
// Function: Show learning slides
//--------------------------------------------------------------
void show_slides() {
    CLEAR();
    char slides[5][250] = {
        "Slide 1: The learning environment is changing rapidly.",
        "Slide 2: Students learn better with visuals, animations and interaction.",
        "Slide 3: C programming offers strings, functions and libraries to digitize lessons.",
        "Slide 4: Instead of rote learning, interactive digital teaching is impactful.",
        "Slide 5: Let's use programming to make learning fun and meaningful!"
    };

    for (int i = 0; i < 5; i++) {
        CLEAR();
        printf("Slide %d/5\n", i + 1);
        printf("-------------------------------------\n\n");
        type_print(slides[i], 20);
        printf("\n\nPress ENTER to continue...");
        getchar();
    }
}

//--------------------------------------------------------------
// Function: Small quiz to test learning
//--------------------------------------------------------------
void quiz() {
    CLEAR();
    int score = 0;
    char ans[10];

    printf("QUIZ TIME!\n");
    printf("----------------------\n");

    printf("\nQ1) What is a C string?\n");
    printf("a) A number\nb) An array of characters\nc) A file\nYour answer: ");
    scanf("%s", ans);
    getchar();
    if (strcmp(ans, "b") == 0) score++;

    printf("\nQ2) Which header file contains string functions?\n");
    printf("a) <math.h>\nb) <stdio.h>\nc) <string.h>\nYour answer: ");
    scanf("%s", ans);
    getchar();
    if (strcmp(ans, "c") == 0) score++;

    printf("\nQ3) Which learning method is better?\n");
    printf("a) Rote memorization\nb) Visual + interactive learning\nYour answer: ");
    scanf("%s", ans);
    getchar();
    if (strcmp(ans, "b") == 0) score++;

    CLEAR();
    printf("Your Score: %d / 3\n", score);

    if (score == 3) printf("Excellent! You understood the concept well!\n");
    else if (score == 2) printf("Good! Try once more to improve.\n");
    else printf("Keep learning — you're getting there!\n");

    printf("\nPress ENTER to return to menu...");
    getchar();
}

//--------------------------------------------------------------
// Function: Display help/instructions
//--------------------------------------------------------------
void help() {
    CLEAR();
    printf("HELP & INFORMATION\n");
    printf("---------------------------------\n");
    printf("1. Use the menu to choose options.\n");
    printf("2. Slides explain modern academic environment.\n");
    printf("3. Quiz checks how much you learned.\n");
    printf("4. Program uses strings, animations, and C functions.\n");
    printf("\nPress ENTER to return...");
    getchar();
}

//--------------------------------------------------------------
// MAIN FUNCTION (~200 lines total including comments)
//--------------------------------------------------------------
int main() {
    int choice;

    while (1) {
        CLEAR();
        banner();

        printf("\nMAIN MENU\n");
        printf("---------------\n");
        printf("1. View Learning Slides\n");
        printf("2. Take Quiz\n");
        printf("3. Help\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar();   // clear buffer

        switch (choice) {
            case 1: show_slides(); break;
            case 2: quiz(); break;
            case 3: help(); break;
            case 4:
                CLEAR();
                type_print("Thank you for using the Digital Learning Assistant!\n", 25);
                return 0;
            default:
                printf("Invalid choice! Press ENTER to try again...");
                getchar();
        }
    }

    return 0;
}