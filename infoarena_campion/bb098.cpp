/*explicatie

Numarul minim de pauze se obtine pentru dimensiunea maxima a unei pauze
Dimensiunea maxima a unei pauze = P * D, adica timpul maxim de download si umplere al memoriei tampon (dat de P)
Tot ce mai trebuie facut este sa micsoram pe S astfel obtinut, pana cand numarul de pauze creste cu o unitate,
practic sa trunchiem impartirea respectiva.

Pasi:
Aflam dimensiunea maxima a bufferului, impartim la (d-b) ca sa aflam cat timp ruleaza pana la urmatoarea pauza,
impartim timpul total al filmului la timpul unui interval si aflam astfel numarul de intervale.
Rotunjim prin adaos numarul obtinut ca sa vedem numarul minim de intervale.

Repetam acum pasii, insa in ordine inversa. Avem numarul minim de intervale (corespunde cu nr min de pauze)
impartim durata filmului la nr min de intervale ca sa aflam durata unui interval si inmultim cu (d-b) ca sa aflam
lungimea minima ceruta pentru buffer.

*/

#include <fstream>
#include <cmath>
using namespace std;

ifstream f("video.in"); ofstream g("video.out");

double d, b, t, p;
double suma_max, nr_pauze, timp_dim_max;
double suma_min, nr_intervale, timp_dim_min;

int main(){
	f>>d>>b>>t>>p;
	
	suma_max=d*p;
	timp_dim_max = suma_max / (b-d);
	nr_pauze = t / timp_dim_max;
	
	if (nr_pauze==trunc(nr_pauze)) nr_intervale=nr_pauze;
	else nr_intervale = trunc(nr_pauze)+1;
	
	timp_dim_min= t / nr_intervale;
	
	suma_min=timp_dim_min * (b-d);
	
	if (suma_min != trunc (suma_min)) suma_min++;
	
	g<<(long long) (suma_min);
}
