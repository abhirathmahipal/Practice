// https://www.hackerrank.com/challenges/maximum-element

#include <iostream>

using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    unsigned int count, query, top = -1, stack[100000], max = 0;
    cin>>count;
    
    while(count--)
    {
        cin>>query;
        if (query == 1)
        {
            cin>>stack[++top];
            if(max < stack[top])
                max = stack[top];
        }
        if (query == 2)
        {
            if (max == stack[top])
            {
                max = 0;
                for (int i = 0; i < top; i++)
                {
                    if (stack[i] > max)
                        max = stack[i];
                }
            }
            top--;
        }
        if (query == 3)
        {
            cout<<max<<endl;
        }
    }
    return 0;
}
