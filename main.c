#include <stdio.h>
#include <string.h>

void displayTable() {
    for(int i = 0; i < 257; i++) {
        printf("%d -> %c  ", i, i);
        if(i%10==0) {
            printf("\n");
        }
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
    short n_str, str_size;

    printf("Size of the array:\n");
    inputPositive(&n_str);
    printf("Size of each string:\n");
    inputPositive(&str_size);

    char list[n_str][str_size+1];
    char *addr[n_str];

    printf("Enter strings (max %hd characters):\n", str_size);
    for(int i = 0; i < n_str; i++) {
        fgets(list[i], str_size+1, stdin);
        fflush(stdin);
        addr[i] = list[i];
    }

    sort(addr, n_str);

    for(int i = 0; i < n_str; i++) {
        printf("%d --> %s\n", i+1, list[i]);
    }
    return 0;
}
