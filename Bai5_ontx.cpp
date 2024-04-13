#include<iostream>
using namespace std;

int a[1000], check;
void kt(){
	for(int i = 1;i <= 6;i++)
	a[i] = i;
}
struct CongViec{
	string MaCV;
	string TenCV;
	float TGBatDau;
	float TGThucHien;
};
struct NhanVien{
	string TenNV;
};

void InCongViec(CongViec cv[],int n){
	if(n < 0) return;
	cout<<"MaCV: "<<cv[n].MaCV<<", TenCV: "<<cv[n].TenCV<<" ,"<<"TGBatDau: "<<cv[n].TGBatDau<<" ,"<<"TGThucHien: "<<cv[n].TGThucHien<<"h"<<endl;
	InCongViec(cv,n-1);
}

void DemCV(CongViec cv[],CongViec b[],int &dem,int l,int r){
	if(l == r){
		if(cv[l].TGThucHien <= 0.5){
			b[dem++] = cv[l];
		}
		return;
	}
	int m = (l + r)/2;
	DemCV(cv,b,dem,l,m);
	DemCV(cv,b,dem,m+1,r);
}

void HienThiCV_NV(CongViec cv[],NhanVien nv[]){
	for(int i = 1;i <= 6;i++){
	cout<<cv[i-1].TenCV<<" - "<<nv[a[i]-1].TenNV<<" ,";
	}
	cout<<endl;
}

void sinh(){
	int i = 5;
	while(i > 0 && a[i] > a[i+1])
	i--;
	if(i == 0)
	check = 0;
	else{
		int j = 6;
		while(a[i] > a[j])
		j--;
		swap(a[i],a[j]);
		int l = i+1, r = 6;
		while(l < r){
			swap(a[l],a[r]);
			l++;
			r--;
		}
	}
}

void GiaoCV_NV(CongViec cv[],NhanVien nv[]){
	check = 1;
	kt();
	while(check){
		HienThiCV_NV(cv,nv);
		sinh();
	}
}

void mergeSort(CongViec a[],CongViec b[],int l,int r){
	if(l < r){
		int m = (l + r)/2;
		mergeSort(a,b,l,m);
		mergeSort(a,b,m+1,r);
		for(int i = m;i >= l;i--)
		b[i] = a[i];
		for(int j = m+1;j <= r;j++)
		b[r+m+1-j] = a[j];
		int i = l, j = r;
		for(int k = l;k <= r;k++){
			if(b[i].TGBatDau < b[j].TGBatDau){
				a[k] = b[i];
				i++;			
			}
			else{
				a[k] = b[j];
				j--;
			}
		}
	}
}
int main(){
	CongViec cv[6] = { {"CV001","Cong Viec 1",2,2.5},
			 	   	   {"CV002","Cong Viec 2",1,0.5},
			 	   	   {"CV003","Cong Viec 3",3,1.5},
			 	   	   {"CV004","Cong Viec 4",2,0.4},
			 	   	   {"CV005","Cong Viec 5",4,1.2},
			 	   	   {"CV006","Cong Viec 6",1,0.1}
	};
	NhanVien nv[6] = { {"Tung"},
			 	   	   {"Cuc"},
			 	   	   {"Truc"},
			 	   	   {"Mai"},
			 	   	   {"Anh"},
			 	   	   {"Dao"}
	};
//	InCongViec(cv,5);
//	cout<<endl;
//	int dem = 0;
//	CongViec b[6];
//	DemCV(cv,b,dem,0,5);
//	if(dem == 0){
//		cout<<"Khong Co Cong Viec Nao Co TG Thuc Hien Nho Hoac Bang 0.5h!"<<endl;
//	}
//	else{
//		cout<<"So Cong Viec Co Thoi Gian Thuc Hien Nho Hon Hoac Bang 0.5h La: "<<dem<<endl;
//		for(int i = 0;i < dem;i++)
//		cout<<"MaCV: "<<b[i].MaCV<<", TenCV: "<<b[i].TenCV<<" ,"<<"TGBatDau: "<<b[i].TGBatDau<<" ,"<<"TGThucHien: "<<b[i].TGThucHien<<"h"<<endl;
//
//	}
//	cout<<endl;
//	GiaoCV_NV(cv,nv);
	CongViec c[6];
	mergeSort(cv,c,0,5);
	InCongViec(cv,5);
	return 0;
}
