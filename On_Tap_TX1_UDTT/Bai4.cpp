#include<iostream>
using namespace std;

struct ChuyenBay{
	string SoHieu;
	double GiaVe;
	int SoGhe;
	
};

void GiaVe(ChuyenBay cb[],int n){
	if(n < 0) return;
	if(cb[n].GiaVe > 700000){
		cout<<cb[n].SoHieu<<" "<<cb[n].GiaVe<<" "<<" "<<cb[n].SoGhe<<endl;
	}
	GiaVe(cb,n-1);
	
}

int main(){
	
	ChuyenBay cb[] = { {"01",800000,1},
						{"02",70000,2},
						{"03",7000000,3}
	};
	for(int i = 0;i < 3;i++){
		cout<<cb[i].SoHieu<<" "<<cb[i].GiaVe<<" "<<" "<<cb[i].SoGhe<<endl;
	}
	GiaVe(cb,2);
	return 0;
}