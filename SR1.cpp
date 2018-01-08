#include <bits/stdc++.h>

using namespace std;

int main(){


    freopen("graph1.txt", "r", stdin);

    int n,m,k, l, ans=0;
    cin >> n >> m;
    int a[n][n], b[n];
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            a[i][j]=0;
    for (int i=0; i<m; i++){
        cin >> k >> l;
        a[k][l]=1;
        a[l][k]=1;
    }

    int sum[n];
    for (int i=0; i<n; i++){
        sum[i]=0;
        for (int j=0; j<n; j++){

            cin >>  a[i][j];
            sum[i]+=a[i][j];

        }

    }

    for (int i=0; i<n-1; i++){
        if (sum[i]!=sum[i+1]){

            cout << "UNREGULAR!!!1111";
            return 0;
        }
    }

    cout << "regular";


}
