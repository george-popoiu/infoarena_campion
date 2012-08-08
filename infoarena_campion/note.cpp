#include<fstream>
#include<algorithm>
#include<iostream>
using namespace std;

fstream f("note.in", ios::in);

int n, v[110];

int main()
{
    f>>n;
    for(int i=0; i<n; i++) f>>v[i];

    sort(v, v+n);

    int start = 1, stop = n-2;

    while( v[start]==v[0] ) start++;
    while( v[stop]==v[n-1] ) stop--;

    double sum = 0.0;
    for(int i=start; i<=stop; i++)
    {
        sum += v[i];
    }

    cout<< sum / (stop-start+1) <<endl;

	f.close();
	return 0;
}
