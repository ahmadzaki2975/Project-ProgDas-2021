#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class Pinjam{
	private:
		string title;
		string penulis;
		string nama;
		string alamat;
		string no_hp;
		string Kelamin;
	public:
	
	
	Pinjam(string intitle ="null" , string inpen="null", string inname="null" , string inal="null", string inno="null", string inkel="null");
	void setData();
	void getscreen();
	void saveFile();
	void showData();
	void deleteData();	
	void updateData();
	
		
};

void Pinjam::setData(){
	char next;
	do{
	ifstream data_buku;
	data_buku.open("List Buku.txt");
	string jud, pen, nam, ala, no, kela, baru2, get;
	
	cout<<"Masukkan nama : ";
	getline(cin, nam);
	cout<<"Masukkan alamat : ";
	getline(cin, ala);
	cout<<"Masukkan no HP : ";
	getline(cin, no);
	cout<<"Masukkan jenis kelamin : ";
	getline(cin, kela);
	cout<<"Masukkan judul buku : ";
	getline(cin, jud);
	if(data_buku.is_open()){
		while(!data_buku.eof()){
			getline(data_buku, baru2);
			if(baru2.find(jud)==8){
				break;
			}
			else if( data_buku.eof() && baru2.find(jud)!=8){
				cout<<"Data tidak ditemukan"<<endl;
				system("pause");
				exit(0);
			}
		}
	} else{
	cout<<"File belum tersedia "<<endl;
	system("pause");
	exit(0);
	}
	cout<<"Masukkan penulis buku : ";
	getline(cin, pen);
	
	
	cout<<"Tambahkan data lagi <y/n> : ";
	cin>>next;
	cin.ignore();
	Pinjam p1(jud, pen, nam, ala, no, kela);
	system("cls");
	p1.getscreen();
	p1.saveFile();
	} while(next == 'y');
	
}
Pinjam::Pinjam(string intitle , string inpen, string inname , string inal, string inno, string inkel){
		title = intitle;
		penulis = inpen;
		nama = inname;
		alamat = inal;
		no_hp = inno;
		Kelamin = inkel;
}

void Pinjam::getscreen(){
	cout<<"Data Peminjaman Buku\n";
	cout<<"Nama peminjam   : "<<nama<<"\n";
	cout<<"Alamat peminjam : "<<alamat<<"\n";
	cout<<"No Handphone    : "<<no_hp<<"\n";
	cout<<"Jenis kelamin   : "<<Kelamin<<"\n";
	cout<<"Judul buku      : "<<title<<"\n";
	cout<<"Penulis buku    : "<<penulis<<"\n\n";
	
}

void Pinjam::saveFile(){
	ofstream myfile;
	
	myfile.open("Data Peminjaman.txt", ios::app);
	myfile<<"Nama peminjam   : "<<nama<<"\n";
	myfile<<"Alamat peminjam : "<<alamat<<"\n";
	myfile<<"No Handphone    : "<<no_hp<<"\n";
	myfile<<"Jenis kelamin   : "<<Kelamin<<"\n";
	myfile<<"Judul buku      : "<<title<<"\n";
	myfile<<"Penulis buku    : "<<penulis<<"\n\n";
	myfile.close();
	
}

void Pinjam::showData(){
	ifstream mynewfile;
	string data, total;
	mynewfile.open("Data Peminjaman.txt");
	if(mynewfile.is_open()){
		while(!mynewfile.eof()){
			getline(mynewfile, data);
			total.append("\n"+data);
		}
		cout<<total;
	}
	else
	cout<<"Data Kosong "<<"\n";
	
	mynewfile.close();
}


void Pinjam::deleteData(){
	string nama, baru;
	cout<<"===================================================\n";
	cout<<"Note : Nama harus sesuai data(Kapital harus sesuai)\n";
	cout<<"Ketidaksesuaian input, data tidak akan di Delete \n";
	cout<<"===================================================\n";
	cout<<"Masukkan nama depan : ";
	getline(cin, nama);
	ifstream myfile;
	myfile.open("Data Peminjaman.txt");
	ofstream newfile;
	newfile.open("new.txt", ios::app);
	while(!myfile.eof()){
		getline(myfile, baru);
		if(baru.find(nama)==18){
			for(int a=0; a<7; a++){
				getline(myfile, baru);
			}
		}
		if(!myfile.eof()){
		newfile<<baru<<"\n";
		}
		}
		
	myfile.close();
	newfile.close();
		
	remove("Data Peminjaman.txt");
	rename("new.txt","Data Peminjaman.txt");
}

void Pinjam::updateData(){
	string nama1, baru1;
	string jud1, pen1, nam1, ala1, no1, kela1;
	cout<<"===================================================\n";
	cout<<"Note : Nama harus sesuai data(Kapital harus sesuai)\n";
	cout<<"Ketidaksesuaian input, data tidak akan di update\n";
	cout<<"===================================================\n";
	cout<<"Masukkan nama depan : ";
	getline(cin, nama1);
	ifstream myfile1;
	myfile1.open("Data Peminjaman.txt");
	ofstream newfile1;
	newfile1.open("new1.txt", ios::app);
	while(!myfile1.eof()){
		getline(myfile1, baru1);
		if(baru1.find(nama1)==18){
			cout<<"\n";
			cout<<"Masukkan nama baru : ";
			getline(cin, nam1);
			cout<<"Masukkan alamat baru : ";
			getline(cin, ala1);
			cout<<"Masukkan no HP baru : ";
			getline(cin, no1);
			cout<<"Masukkan jenis kelamin baru : ";
			getline(cin, kela1);
			cout<<"Masukkan judul buku baru : ";
			getline(cin, jud1);
			cout<<"Masukkan penulis buku baru : ";
			getline(cin, pen1);
			newfile1<<"Nama peminjam   : "<<nam1<<"\n";
			newfile1<<"Alamat peminjam : "<<ala1<<"\n";
			newfile1<<"No Handphone    : "<<no1<<"\n";
			newfile1<<"Jenis kelamin   : "<<kela1<<"\n";
			newfile1<<"Judul buku      : "<<jud1<<"\n";
			newfile1<<"Penulis buku    : "<<pen1<<"\n\n";
			for(int c=0; c<7; c++){
				getline(myfile1, baru1);
			}
		}
		if(!myfile1.eof()){
		newfile1<<baru1<<"\n";
		}
		}
		
	myfile1.close();
	newfile1.close();
		
	remove("Data Peminjaman.txt");
	rename("new1.txt","Data Peminjaman.txt");
}


void menuPinjam(){
	char pilih;
	do{
	string a;
	Pinjam p;
	cout<<"\t--------------------------\n";
	cout<<"\t      Peminjaman Buku\n";
	cout<<"\t--------------------------\n\n";
	cout<<"====================\n";
	cout<<"   1. Pinjam Buku\n";
	cout<<"   2. Lihat data Pinjam Buku\n";
	cout<<"   3. Delete data Pinjam Buku\n";
	cout<<"   4. Edit data Pinjam Buku\n";
	cout<<"   5. Exit\n";
	cout<<"  Enter your choice : ";
	cin>>pilih;
	cin.ignore();
	system("cls");
	
	switch(pilih){
		case '1' :
			p.setData();
			break;
		case '2':
			p.showData();
			break;
		case '3':
			p.deleteData();
			break;
		case '4':
			p.updateData();
			break;
	}
	if(pilih != '5'){
		cout<<"Please click enter to Continue..";
		cin.get();
	}
	
	system("cls");
}while(pilih != '5');

}
	
