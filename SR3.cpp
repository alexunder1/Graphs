#include <bits/stdc++.h>

using namespace std;

vector <vector <int> > g;
vector <int> p;
vector <int> r;
vector <bool> was;
vector <bool> cvet;

void DeepSearch(int a, int last){

    for (auto i : g[a]){
        if (was[i] == false){
            was[i] = true;

            if (cvet[a] == false)
                cvet[i] = true;
            else
                cvet[i] = false;
            DeepSearch(i, a);

        } else {

            if (i!=last){
                cout << "NE VOZMOJNO";
                exit(1);
            }
        }
    }
}


int main(){

    freopen("graph3.txt", "r", stdin);


    int n, b;
    cin >> n;
    cin >> b;

    g.resize(n);
    was.resize(n);
    cvet.resize(n);

    cvet[0]=true;

    for (int i=0 ; i< n; i++)
        was[i] = false;

    was[0]=true;

    for(int i=0; i<b; i++){

        int x,y;
        cin>>x>>y;

        g[x].push_back(y);
        g[y].push_back(x);
    }

    DeepSearch(0, 0);

    for ( int i = 0; i < n; i++){

        if (cvet[i] == true)
            cout << i<<" - KRASNIY ";

        else
            cout << i<< " - CINIY ";
    }



}

