# include <cstdio>

const char *FIN = "video.in", *FOU = "video.out";

long long D, B, T, P;

int main (void) {
    fscanf (fopen (FIN, "r"), "%lld %lld %lld %lld", &D, &B, &T, &P);
    long long a = T * (B - D), b = D * P, c = a / b, d = 0;
    if (a % b) ++c;
    d = a / c;
    if (a % c) ++d;
    fprintf (fopen (FOU, "w"), "%lld", d);
}
