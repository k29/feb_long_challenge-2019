#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define MAX 1000
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
	    int n;
	    std::vector<int> v(26, 0);
	    scanf("%d", &n);
	    
	    int i=1;
	    int len = n;
	    string k;
	    getline(cin, k);
	    while(len--){
	        char str[MAX];
	        fgets(str, MAX, stdin);
	        for(int it=0; str[it]!='\0'; it++) {
	            if(v[str[it]-'a'] == i-1) {
	                v[str[it] - 'a'] = i;
	            }
	        }
	        i++;
	    }
	    int count = 0;
	    for(int j=0; j<v.size(); j++){
	        if(v[j] == n){
	            count++;
	        }
	    }
	    printf("%d\n", count);
	    
	}
	return 0;
}
