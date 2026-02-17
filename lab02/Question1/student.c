#include "student.h"
#include <stdbool.h>
#include <stddef.h>  // size_t
#include <string.h>  // strlen

bool isValid(const char *s) {
    
    size_t n = strlen(s);
    
    if (s == NULL){
        return false;
    }
    
    if (n == 0){
        return true;
    }
    
    if ((n % 2) == 1){
        return false;
    }
    
    char stack[n];
    size_t top = 0;
    
    for (size_t i = 0; i < n; i++){
        char c = s[i];
        
        if ((c == '{') || (c == '[') || (c == '(')){
            stack[top] = c;
            top++;
        }
        else {
            if (top == 0){
                return false;
            }
            
            char c_top = stack[top - 1];
            if (((c == ']') && (c_top != '[')) || ((c == '}') && (c_top != '{')) || ((c == ')') && (c_top != '('))) {
                return false;
            }
            top--;
            
        }
    }
    
    if (top == 0){
        return true;
    }
    else {
        return false;
    }

    (void)s; // remove after implementing
    return false; // placeholder
}
