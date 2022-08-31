#include<bits/stdc++.h>
using namespace std;

long M = 1e9+7; 

long mod(long x) {
    return (((x%M) + M)%M);
}

vector<vector<long>> mult(vector<vector<long>> mat1, vector<vector<long>> mat2) {
    vector<vector<long>> res(2, vector<long>(2, 0));

    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            for(int k = 0; k < 2; k++) 
                res[i][j] += mod(mat1[i][k] * mat2[k][j]);
    
    return res;
}

vector<vector<long>> fib(vector<vector<long>> a, int n) {
    if(n == 1)
        return a;
    
    vector<vector<long>> temp = fib(a, n/2);

    if(n%2 == 0)
        return mult(temp, temp);
    
    else 
        return mult(temp, mult(temp, a));
}

int main() {

    vector<vector<long>> a = {{1, 1}, {1, 0}};
    vector<vector<long>> res = fib(a, 100);

    cout << mod(res[1][0]);

    return 0;
}