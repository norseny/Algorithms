/* DFS - zadanie 
Masz n skrzynek, każdą z nich można otworzyć jej kluczem lub siłowo łomem. Ktoś powrzucał klucze do pewnych skrzynek - dostałeś dokładny opis, w której jaki jest klucz. Pilnie potrzebujesz złota ze wszytskich skrzynek i chcesz je wszytskie otworzyć używając jak najmniej razy łomu.
Zadanie
Napisz program, który:
• wczyta ze standardowego wejścia liczbę skrzynek i rozmieszczenie odpowiadających im kluczy,
• obliczy minimalną liczbę skrzynek, które trzeba otworzyć siłowo łomem, aby dostać się do wszystkich skrzynek,
• wypisze wynik na standardowe wyjście.
Wejście:
W pierwszym wierszu standardowego wejścia znajduje się jedna liczba całkowita n (1 ≤ n ≤ 1 000 000 ) — ilość skrzynek. Skrzynki (jak również odpowiadające im klucze) są ponumerowane od 1 do n. Dalej na wejściu mamy n wierszy: w ( i + 1)-szym wierszu zapisana jest jedna liczba całkowita — numer skrzynki, w której znajduje się i-ty klucz.
Wyjście:
W pierwszym i jedynym wierszu standardowego wyjścia należy zapisać jedną liczbę całkowitą — minimalną liczbę skrzynek, które trzeba otworzyć siłowo, aby dostać się do wszystkich. 
UWAGA!
Użyj struktury wektor.
*/

#include <iostream>
#include<vector>

using namespace std;
int visited[1000000];
int open;
vector<int>vertex[1000000];

int DFS(int node, int master){
    int i;
    
		for(i=0; i<vertex[node].size(); i++){
        if(visited[vertex[node][i]]>=-1&&visited[vertex[node][i]]!=master){
					open--;
					visited[vertex[node][i]]=-2;
					DFS(vertex[node][i], master);
				}
    }
}

int main() {
    int i,k,n;
    cin >> n;
    for(i=0; i<n; i++){
			cin >> k;
      vertex[k-1].push_back(i);
    }
    open=n;
		for(i=0; i<n; i++)visited[i]=-1;
		for(i=0;i<n;i++){
			if(visited[i]>=-1){
				visited[i]=i;
				DFS(i, i);
			}
		}
    cout << open;
		return 0;
}