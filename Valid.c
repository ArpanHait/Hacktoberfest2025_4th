#include <stdbool.h>
#include <string.h>

bool isValid(char* s) {
    int length = strlen(s);
    char stack[length]; 
    int top = -1;  

    for (int i = 0; i < length; i++) {
        char store = s[i];
        
        if (store == '(' || store == '{' || store == '[') {
            stack[++top] = store;
        } else {
            
            if (top == -1) return false;
            
            if ((store == ')' && stack[top] != '(') ||
                (store == '}' && stack[top] != '{') ||
                (store == ']' && stack[top] != '[')) {
                return false;
            }
            
            top--;
        }
    }
    return top == -1;
}
