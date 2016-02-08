// https://www.hackerrank.com/challenges/balanced-parentheses

#include <iostream>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    char input[1000], trackstack[1000], temp;
    int n, len, stackiterator;
    bool alreadyprinted;
    cin>>n;
    
    while(n--) {
        alreadyprinted = false;
        stackiterator = -1;
        cin>>input;
        for (len = 1; input[len] != '\0'; len++) {
            
        }
        
        
        for (int i = 0; i < len; i++) {
            
            if (input[i] == '(' || input[i] == '{' || input [i] == '[') 
                trackstack[++stackiterator] = input[i];

            
            
            else {
                temp = trackstack[stackiterator];
                if(input[i] == ')') {
                    if (temp == '(') {
                        stackiterator--;
                    }
                    else {
                        cout<<"NO\n";
                        alreadyprinted = true;
                        break;
                    }
                    
                }
                else if (input[i] == '}') {
                     
                    if (temp == '{') {
                        stackiterator--;
                    }
                    else {
                        cout<<"NO\n";
                        alreadyprinted = true;
                        break;
                    }
                    
                    
                }
                else {
                    
                     if (temp == '[') {
                        stackiterator--;
                    }
                    else {
                        cout<<"NO\n";
                        alreadyprinted = true;
                        break;
                    }                  
                    
                }
                
                // End of Main if-else
                }
             
            // End of Iterating For Loop
            } 
        
        if (alreadyprinted == false) {

            if (stackiterator == -1)
            cout<<"YES\n";
        else {
            cout<<"NO\n";  

        }
        }
        
    // End of main while loop 
    }
    
    
   
    
    return 0;
// End of Main Function
}
