#include <bits/stdc++.h>

using namespace std;

vector <vector <int> > g;
vector <int> p;
vector <int> r;
vector <bool> was;
vector <int> otvet;

/*void poschitai(int a, int u){
    r[a]=0;
    for (int i = 0; i < p.size(); i++){
        if (p[i]!= a){
            r[a]++;
            otvet.push_back(p[i]);
        } else
            break;
    }


    if (r[a]==u){

        for (int j = 0; j < r[a]; j++){

            cout << otvet[j];

        }
        exit(1);

    }
}
*/

void DeepSearch(int a, int last, int u){
    int sum=0;
    for (auto i : g[a]){

        if (was[i] == false){

            p.push_back(i);
            was[i] = true;
            DeepSearch(i, a, u);

        } else {

            if (i!=last){

                for (int j=0; j<p.size(); j++){

                    if (p[j]==i)
                        while (p[j]!=a){
                            otvet.push_back(p[j]);
                            sum++;
                            j++;
                        }

                }

                otvet.push_back(a);
                sum++;

                if (sum==u){


                    for (int k=otvet.size()-u; k<otvet.size(); k++)
                        cout << otvet[k]<<" ";

                    exit(1);

                }
                else {

                    sum=0;

                }

                //poschitai(i, u);
                //return;

            }
        }
    }
}


int main(){

    freopen("graph2.txt", "r", stdin);


    int n, b, u;
    cin >> n;
    cin >> b;
    r.resize(n);
    p.resize(n);
    g.resize(n);
    was.resize(n);
    otvet.resize(n);

    for (int i=0 ; i< n; i++)
        was[i] = false;

    was[0]=true;

    for(int i=0; i<b; i++){

        int x,y;
        cin>>x>>y;

        g[x].push_back(y);
        g[y].push_back(x);

    }

    cin >> u;

    DeepSearch(0, 0, u);

    cout <<"Takih ciclov net";

}

