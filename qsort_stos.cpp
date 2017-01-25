// QuickSort	w wersji stosowej (stos zamiast rekurencji)

#include <iostream>
#include <stack>
using namespace std;

int podzial(int *a,int l, int h){
	int x = a[h];
	int i = l-1;
	int j=l;
	while(j<=h-1){
		if(a[j]<=x){
			i++;
			if(a[i] > x && a[j] <= x)
				swap(a[i],a[j]);
		}
		j++;
	}
	swap(a[i+1],a[h]);

	return i+1;
}

int quicksort(int *a,int l,int h){
	stack <int > s;

	s.push(l);
	s.push(h);
	while (!s.empty()){
		int ll,hh;
		hh = s.top();
		s.pop();
		ll = s.top();
		s.pop();

		int p = podzial(a,ll,hh);

		if(p-1 > ll){
			s.push(ll);
			s.push(p-1);
		}
		if(p+1 < hh){
			s.push(p+1);
			s.push(hh);
		}
	}
}

int main(){
    int liczba_zestawow, ile_liczb, i, j;

    cin >> liczba_zestawow;
    if (liczba_zestawow>=1 && liczba_zestawow<=100000){
        for(i=0;i<liczba_zestawow;i++){
            cin >> ile_liczb;
            if (ile_liczb>=2 && ile_liczb<=500000){
                int tablica[ile_liczb];

                for (j = 0; j < ile_liczb; j++)
                    cin >> tablica[j];
                    quicksort(tablica,0,ile_liczb-1);
                for (j = 0; j < ile_liczb; j++){
                    cout << tablica[j] << " ";
                }
                cout << endl;
            }
        }
    }
return 0;
}