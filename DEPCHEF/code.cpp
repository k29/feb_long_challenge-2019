#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    
    // testcases
    while(t--) {
        //subcases
        int n;
        scanf("%d", &n);
        
        // intialise
        int att[100];
        int def[100];
        char temp;
        int i=1;
        
        // take attack input
        do {
            scanf("%d%c", &att[i], &temp);
            i++;
        } while(temp != '\n');
        
        // take defense input
        i=1;
        do {
            scanf("%d%c", &def[i], &temp);
            i++;
        } while(temp != '\n');
        
        // paster n values in the 0 and 1 values in the n
        att[0] = att[n];
        def[0] = def[n];
        att[n+1] = att[1];
        def[n+1] = def[1];

        // solution
        vector<int> survive;
        for(int i=1; i<=n; i++) {
            if(def[i] > (att[i-1] + att[i+1])) {
                survive.push_back(def[i]);
            }
        }   

        int max = -1;
        for(int i=0;i<survive.size();i++) {
            if(survive[i] > max){
                max = survive[i];
            }
        }

        printf("%d\n", max);
    }

    

    return 0;
}