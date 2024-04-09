#include<iostream>
using namespace std;

string s[] = {" ","A","B","C","D","E","F","G"};
int a[1000], n, k, ok;

bool check[1000] = {false};

void kt(){
	for(int i = 1;i <= n;i++)
	a[i] = i;
}
void xuat(){
	for(int i = 1;i <= k;i++){
		cout<<s[a[i]];
	}
	cout<<endl;
}
void sinh(){
	int i = k;
	while(i > 0 && a[i] == n-k+i)
	i--;
	if(i == 0)
	ok = 0;
	else{
		a[i]++;
		for(int j = i+1;j <= k;j++){
			a[j] = a[j-1] + 1;
		}
	}
	
}

void Try(int i){

	for (int j = a[i-1] + 1; j <= n-k+i; j++) {
        a[i] = j;
        if (i == k) 
		xuat();
        else Try(i+1);
    }
}
int main(){
	cin>>n>>k;
	ok = 1;
//	kt();
//	while(ok){
//		xuat();
//		sinh();
//	}
	Try(1);
	return 0;
}