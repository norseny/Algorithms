/*G4 - Gaz - wlasna kolejka + macierz sąsiedztwa
 W podziemnej sieci metra rosprzestrzenia się niebezpieczny gaz. Mając dokładny opis tuneli, oblicz poziom bezpieczeństwa dla każdej stacji.
Poziom bezpieczeństwa jest liczony jako najkrótsza odległość dla danej stacji od źródła gazu.
Zadanie
Napisz program, który:
• wczyta ze standardowego wejścia liczbę stacji, gdzie znajduje się źródło i opis systemu tuneli,
• obliczy poziom bezpieczeństwa dla każdej ze stacji,
• wypisze wyniki na standardowe wyjście.
Wejście:
W pierwszym wierszu standardowego wejścia znajduje się trzy liczby naturalne n,m,k (2 ≤ n ≤ 100, 1 ≤ m ≤ 100, 1 ≤ k ≤ n ). Pierwsza z nich oznacza ilość stacji druga, liczbę połączeń a k oznacza numer stacji, w której znajduje się źródło niebezpiecznego gazu. Następnie znajduje się opis tuneli - w m kolejnych liniach podane są po dwie liczby a,b (1 ≤ a,b ≤ n) mówiące między którymi stacjami istnieje połączenie.
Wyjście:
W m kolejnych liniach należy podać po dwie liczby, numer stacji oraz jej poziom bezpieczeństwa
*/

#include <stdio.h>
using namespace std;

int tab[100000];
int p=0;
int k=0;

bool k_empty(){
	if (k==p)
		return true;
	else 
		return false;
}

void k_push(int x){
	tab[k] =x;
	k++;
}

void k_pop(){
	p++;
}

int k_front(){
	return tab[p]; 
}


int main() {

	int n, m, k, l, gaz, i, a, b;
	int visited[100], lvl[100];
	bool macierz[100][100];

    scanf("%d %d %d", &n,  &m, &gaz);
	
	for (a=0;a<100;a++){
		for (b=0;b<100;b++){
			macierz[a][b] = 0;
		}
	}

    if( 2>=n<=100 && 1>=m<=100 && 1>=gaz<=n  ){
        for (i=0; i<m; i++){
            scanf("%d %d", &k, &l);
			macierz[k][l] =1;
			macierz[l][k] =1;
        }
        for (i=1; i<=n; i++)
            visited[i] = 0;

        k_push(gaz);
        visited[gaz] = 1;
        lvl[gaz]=0;

        while(!k_empty()){
          int node = k_front();
          k_pop();
          for(i=0; i<100; i++){
						if (macierz[node][i] == 1){
							if (visited[i] == 0){
								visited[i] = 1;
								k_push(i);
								lvl[i] = lvl[node]+1;
							}
						}					
          }
        }
        for (i=1; i<=n; i++)
            printf("%d %d\n", i, lvl[i]);
        }
				
return 0;
}