#include<fstream>
using namespace std;

fstream g("arbore.out");

struct nod {
    int info;
    nod *st, *dr;
} *R, *nil;

void insert(nod* &n, int nr) {
    if( n==nil ) {
        n = new nod; n->st = nil; n->dr = nil;
        n->info = nr;
        return;
    }
    if( nr < n->info )  insert( n->st , nr );
    else if( nr > n->info )  insert( n->dr , nr );
}

void srd(nod* n) {
    if( n==nil ) return;
    srd(n->st);
    g<< n->info <<" ";
    srd(n->dr);
}

int main() {
    nil = new nod; nil->st = NULL; nil->dr = NULL; nil->info = 0;
    R = nil;

    insert(R, 1); insert(R, 2); insert(R , 3); insert(R, -1); insert(R, 0); insert(R, -3);

    srd(R);

    g.close(); return 0;
}
