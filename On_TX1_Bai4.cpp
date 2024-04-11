#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int a[1000], n, k;
bool check[] = {false};
struct ChuyenBay{
	string SoHieuChuyen;
	double GiaVe;
	int SoGheNgoi;
	
};

	ChuyenBay cb[] = { {"01",600000,1},
			  	   	   {"02",800000,2},
			  	   	   {"03",1000000,3},
			  	   	   {"04",500000,4},
			  	   	   {"05",700000,5}
	};
void GiaVeTren700000(ChuyenBay cb[],int n){
	if(n < 0) return;
	if(cb[n-1].GiaVe > 700000){
		cout<<cb[n-1].SoHieuChuyen<<" "<<cb[n-1].GiaVe<<" "<<cb[n-1].SoGheNgoi<<endl;
	}
	GiaVeTren700000(cb,n-1);
}

ChuyenBay minGiaVe(ChuyenBay cb[],int l,int r){
	if(l == r) return cb[l];
	
	int m = (l+r)/2;
	ChuyenBay minleft = minGiaVe(cb,l,m);
	ChuyenBay minright = minGiaVe(cb,m+1,r);
	return (minleft.GiaVe > minright.GiaVe) ? minright : minleft;
}

void xuat(ChuyenBay cb[],int n){
	cout<<setw(20)<<"| SO HIEU CHUYEN BAY |"<<setw(10)<<"GIA VE |"<<setw(10)<<"SO GHE |"<<endl;
	for(int i = 0;i < n;i++){
		cout<<"|"<<setw(20)<<cb[i].SoHieuChuyen<<"|"<<setw(9)<<cb[i].GiaVe<<"|"<<setw(9)<<cb[i].SoGheNgoi<<"|"<<endl;
	}
}


void xuatcb(int a[]){
	for(int i = 1;i <= 4;i++){
		cout<<cb[a[i]-1].SoHieuChuyen<<"-"<<cb[a[i]-1].SoGheNgoi<<" ,";
	}
	cout<<endl;
}
void Try(int i){
	 	for (int j = a[i-1] + 1; j <= n-k+i; j++) {
        a[i] = j;
        if (i == k) 
		xuatcb(a);
        else Try(i+1);
    }
}

int main(){
	cin>>n>>k;
//	xuat(cb,4);
//	GiaVeTren700000(cb,4);
//	ChuyenBay min = minGiaVe(cb,0,3);
//	cout<<"\n"<<"Chuyen Bay Co Gia Ve Thap Nhat La: ";
//	cout<<min.SoHieuChuyen<<" "<<min.SoGheNgoi<<" "<<min.GiaVe<<endl;
	Try(1);
	return 0;
}
