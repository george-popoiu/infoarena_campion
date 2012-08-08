#include<fstream>
#include<cstring>
#define inFile "combcuv.in"
#define outFile "combcuv.out"

using namespace std;

char text[1005];
char cuv[501][51];
int N;

void Citire()
{
	int i;
	ifstream fin(inFile);
	fin >> text;
	fin >> N;
	for (i = 0; i < N; i++)
		fin >> cuv[i];
	fin.close();
}

int Combina(char *c1, char *c2, char *t)
{
	int i, j, b[53][53], n1, n2;
	n1 = strlen(c1);
	n2 = strlen(c2);
	
	//initializare
	b[0][0] = 0;
	i = 0;
	while (i < n1 && c1[i] == t[i])
	{
		i++;
		b[i][0] = 1;
	}
	while (i < n1)
	{
		i++;
		b[i][0] = 0;
	}
	i = 0;
	while (i < n2 && c2[i] == t[i])
	{
		i++;
		b[0][i] = 1;
	}
	while (i < n2)
	{
		i++;
		b[0][i] = 0;
	}	
	
	for (i = 1; i <= n1; i++)
		for (j = 1; j <= n2; j++)
		{
			b[i][j] = 0;
			if (b[i - 1][j] && c1[i - 1] == t[i + j - 1])
				b[i][j] = 1;
			if (b[i][j - 1] && c2[j - 1] == t[i + j - 1])
				b[i][j] = 1;
		}

	return b[n1][n2];
}

void Calcul()
{
	ofstream fout(outFile);
	int i, j, p, contor, n1, n2, n, x;
	contor = 0;
	n = strlen(text);
	for (i = 0; i < N - 1; i++)
		for (j = i + 1; j < N; j++)
		{
			n1 = strlen(cuv[i]);
			n2 = strlen(cuv[j]);
			x = 0;
			for (p = 0; (p <= n - (n1 + n2)) && !x; p++)
				if (text[p] == cuv[i][0] || text[p] == cuv[j][0])
				{
					x = Combina(cuv[i], cuv[j], text + p);
					if (x == 1)
					{
						contor++;
						char ww[100];
						strncpy(ww,text+p,n1+n2);
						ww[n1+n2] = 0;
					}
				}
		}
	
	fout << contor << "\n";
	fout.close();
}

int main()
{
	Citire();
	Calcul();
	
	return 0;
}
