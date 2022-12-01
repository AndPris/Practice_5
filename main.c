#include <stdio.h>
#include <string.h>
#include <stdlib.h> // rand and srand
#include <time.h>

void displayList(short a, short b, char array[][b+1]) {
    for(int i = 0; i < a; i++) {
        printf("%d --> %s\n", i+1, array[i]);
    }
}

void noChar(short *var) { //checking for characters
    char cond, ch;
    do {
        cond = 0;
        scanf("%hd%c", var, &ch);

        if(ch != '\n') {
            printf("Invalid data\n");
            cond = 1;
            fflush(stdin);
        }
    } while(cond);

}

void inputPositive(short *variable) { // check for positive value
    char cond;
    do {
        cond = 0;
        noChar(variable);
        if((*variable) <= 0) {
            printf("Number should be higher than 0\n");
            cond = 1;
            fflush(stdin);
        }
    } while(cond);
}

int random(short bottom, short top) {
    return bottom + rand()%(top - bottom + 1);
}

void generateList(short amount, short size, char *pointers[], char array[][size+1]) {
    char index;
    for (int i = 0; i < amount; i++) {
        int j = 0;

        do {
            index = random(65, 122);
            if ((index >= 65 && index <= 90) || (index >= 97 && index <= 122)) {
                array[i][j] = index;
                j++;
            }
        } while (j < size);

        array[i][j] = '\0';
        pointers[i] = array[i];
    }
}

void sort(char *pointers[], short size) {
    for(short i = 0; i < size-1; i++) {
        for(short j = i + 1; j < size; j++) {
            if (strcmp(pointers[i], pointers[j]) > 0) {
                char temp[strlen(pointers[j]) + 1];
                strcpy(temp, pointers[j]);
                strcpy(pointers[j],pointers[i]);
                strcpy(pointers[i], temp);
            }

        }
    }
}

int main() {
    short n_str, str_size, isRandom, repeat;
    srand(time(0));

    do {
        printf("Size of the array:\n");
        inputPositive(&n_str);
        printf("Size of each string:\n");
        inputPositive(&str_size);
        printf("Enter 0 to enter strings by your own or any other number to generate them:\n");
        noChar(&isRandom);

        char list[n_str][str_size + 1];
        char *addr[n_str];

        if (isRandom) {
            generateList(n_str, str_size, addr, list);

            printf("Generated list:\n");
            displayList(n_str, str_size, list);
        } else {
            printf("Enter strings (max %hd characters):\n", str_size);
            for (int i = 0; i < n_str; i++) {
                fgets(list[i], str_size + 1, stdin);
                fflush(stdin);
                addr[i] = list[i];
            }
        }
        sort(addr, n_str);

        printf("\n\nSorted list:\n");
        displayList(n_str, str_size, list);

        printf("Enter 0 to end the programme or any other number to continue:\n");
        noChar(&repeat);
    } while(repeat);
    return 0;
}
