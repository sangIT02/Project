#include<iostream>
using namespace std;


int a[1000], k, n, dem = 0;
string s[] = {"","A","B","C","D"};
bool ok;
bool check[1000] = {false};


//xuat
void xuat(){
	for(int i = 1;i <= k;i++){
		switch(a[i]){
			case 1: cout<<"Tung - "<<s[a[i]]<<" ,"; break;
			case 2: cout<<"Cuc - "<<s[a[i]]<<" ,"; break;
			case 3: cout<<"Truc - "<<s[a[i]]<<" ,"; break;
			case 4: cout<<"Mai - "<<s[a[i]]<<" ,"; break;
		}
		
	}
	cout<<endl;
}
//khoi tao
void kt(){
	for(int i = 1;i <= k;i++)
	a[i] = i;
}
//sinh hoan vi
void SinhHoanVi(){
	int i = k-1;
	while(i > 0 && a[i] > a[i+1])
	i--;
	if(i == 0)
	ok = false;
	else{
		int j = k;
		while(a[i] > a[j])
		j--;
		swap(a[i],a[j]);
		int l = i + 1, r = k;
		while(l < r){
			swap(a[l],a[r]);
			l++;
			r--;
		}
	}
}
// sinh hoan vi bang quay lui
void Try(int k){
	for(int i = 1;i <= n;i++){
		if(check[i] == false){
			a[k] = i;
			check[i] = true;
			if(n == k)
			xuat();
			else{
				Try(k+1);
			}
			check[i]=false;
		}
	}
}
int main(){
	cin>>n>>k;
	kt();
	ok = true;
	while(ok){
		xuat();
		cout<<endl;
		SinhHoanVi();
		dem++;
	}
	cout<<endl<<"Tong So Cach Sap Xep La: "<<dem<<endl;
//	Try(1);
	return 0;
}