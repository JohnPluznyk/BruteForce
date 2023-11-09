#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int sizeCharArray(char a[], char b[]){

    int size = strlen(a);
    printf("size of a: %i\n", size);

    int sizeb = strlen(b);
    printf("size of b: %i\n", sizeb);

    return 0;
}

int compareArray(char a[], char b[]){
    int size = strlen(a);

    for(int i = 0; i<size; i++){
        if(a[i] != b[i])
            return 1;  //exit uncessfully
    }

    return 0; //exit successfully
}

int cracker(char password[], int size){
    //char arr[size];  //this an illeagal statment b/c size isnt a constant value so if this goes into stack we get issue
    char *arr;
    arr = malloc(size + 1);  //this is reserving bytes of memory in our heap for arr

/*
    arr[0] = 'c';
    arr[1] = 'a';
    arr[2] = 't';
*/
    arr[size] = '\0';  //set null terminator as the last character in the array

/*    
    if(compareArray(b, arr) == 0){
        printf("great success!\n");
    }
    else
        printf("great failure!\n");
*/
    
    for(int i = 0; i < size; i++){  //intialize an array of a's
        arr[i] = 'a';
    }

    if(compareArray(password, arr) == 0){  //base case will test for all a's
        printf("password is: %s\n", arr);
        return 0;
    }
    printf("%s\n", arr);  //print out attempt

    while(arr != "zzz"){  //while arr != "zzz"
        arr[0] = arr[0] + 1;

        if(compareArray(password, arr) == 0){  //if the string of characters is equal to password return true and print out password
            printf("password is: %s\n", arr);
            return 0;
        }

        if(strcmp(arr, "zzzz") == 0){
            printf("password was not found\n");
            return 1;
        }
        
        for(int i = 0; i < size - 1; i++){
            if(arr[i] == 'z' || arr[i] == '{'){  //if we detect a z character in the array change it back to an 'a' and add 1 to the next character in the array  in the case where two z's are next to eachother a '{' will generate which is why I also check for '{'
                arr[i] = 'a';                       
                arr[i + 1] = arr[i + 1] + 1;
            }
        }

        printf("%s\n", arr);  //print out attempt
    }

    //printf("%s\n", arr);  //for debugging purposes
    return 0;
}


int main(int argc, char *argv[]){

    char test[] = {"test"};  //super secure secret password
    cracker(test, 4);

    return 0;
}