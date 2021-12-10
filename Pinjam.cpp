#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
using namespace std;
#include "pinj.h"

void Pinjam::setData(){
	char next;
	do{
	ifstream data_buku;
	data_buku.open("List Buku.txt");
	string judul, penulis, nama, alamat, no_hp, kelamin, baru2, get;
	
	cout<<"Masukkan nama : ";
	getline(cin, nama);
	cout<<"Masukkan alamat : ";
	getline(cin, alamat);
	cout<<"Masukkan no HP : ";
	getline(cin, no_hp);
	cout<<"Masukkan jenis kelamin : ";
	getline(cin, kelamin);
	cout<<"Masukkan judul buku : ";
	getline(cin, judul);
	while(!data_buku.eof()){
		getline(data_buku, baru2);
		if(baru2.find(judul)==8){
			for(int a=0; a<5; a++){
				getline(data_buku, baru2);
			}
				get = baru2.substr(9,8);
				if(get == "Tersedia"){
					break;
				}
				else if(get != "Tersedia") {
					cout<<"Buku sudah dipinjam"<<endl;
					system("pause");
					exit (0);
				}
			
		}
		else if(baru2.find(judul)!=8 && data_buku.eof() ){
			cout<<"Buku tidak ditemukan"<<endl;
			system("pause");
			exit (0);
		}
	}
	cout<<"Masukkan penulis buku : ";
	getline(cin, penulis);
	cout<<"Tambahkan data lagi <y/n> : ";
	cin>>next;
	cin.ignore();
	Pinjam p1(judul, penulis, nama, alamat, no_hp, kelamin);
	system("cls");
	p1.getscreen();
	p1.saveFile();
	} while(next == 'y');
	
}

Pinjam::Pinjam(string input_judul, string input_penulis, string input_nama, string input_alamat, string input_nohp, string input_kelamin){
		judul_buku = input_judul;
		penulis = input_penulis;
		nama_peminjam = input_nama;
		alamat = input_alamat;
		no_hp = input_nohp;
		kelamin = input_kelamin;
}

void Pinjam::getscreen(){
	cout<<"Data Peminjaman Buku\n";
	cout<<"Nama peminjam   : "<<nama_peminjam<<"\n";
	cout<<"Alamat peminjam : "<<alamat<<"\n";
	cout<<"No Handphone    : "<<no_hp<<"\n";
	cout<<"Jenis kelamin   : "<<kelamin<<"\n";
	cout<<"Judul buku      : "<<judul_buku<<"\n";
	cout<<"Penulis buku    : "<<penulis<<"\n\n";
	
}

void Pinjam::saveFile(){
	ofstream myfile;
	
	myfile.open("Data Peminjaman.txt", ios::app);
	myfile<<"Nama peminjam   : "<<nama_peminjam<<"\n";
	myfile<<"Alamat peminjam : "<<alamat<<"\n";
	myfile<<"No Handphone    : "<<no_hp<<"\n";
	myfile<<"Jenis kelamin   : "<<kelamin<<"\n";
	myfile<<"Judul buku      : "<<judul_buku<<"\n";
	myfile<<"Penulis buku    : "<<penulis<<"\n\n";
	myfile.close();
	
}

void Pinjam::showData(){
	ifstream myfile;
	string data, total;
	myfile.open("Data Peminjaman.txt");
	if(myfile.is_open()){
		while(!myfile.eof()){
			getline(myfile, data);
			total.append("\n"+data);
		}
		cout<<total;
	}
	else
	cout<<"Data Kosong "<<"\n";
	
	myfile.close();
}


void Pinjam::deleteData(){
	string nama, baru;
	cout<<"===================================================\n";
	cout<<"Note : Nama harus sesuai data(Kapital harus sesuai)\n";
	cout<<"Ketidaksesuaian input, data tidak akan di Delete \n";
	cout<<"===================================================\n";
	cout<<"Masukkan nama lengkap : ";
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
	ifstream data_buku;
	data_buku.open("List Buku.txt");
	string nama1, baru1;
	string judul_baru, penulis_baru, nama_baru, alamat_baru, nohp_baru, kelamin_baru, baru2, get;
	cout<<"===================================================\n";
	cout<<"Note : Nama harus sesuai data(Kapital harus sesuai)\n";
	cout<<"Ketidaksesuaian input, data tidak akan di update\n";
	cout<<"===================================================\n";
	cout<<"Masukkan nama lengkap : ";
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
			getline(cin, nama_baru);
			cout<<"Masukkan alamat baru : ";
			getline(cin, alamat_baru);
			cout<<"Masukkan no HP baru : ";
			getline(cin, nohp_baru);
			cout<<"Masukkan jenis kelamin baru : ";
			getline(cin, kelamin_baru);
			cout<<"Masukkan judul buku baru : ";
			getline(cin, judul_baru);
				while(!data_buku.eof()){
					getline(data_buku, baru2);
					if(baru2.find(judul_baru)==8){
						for(int a=0; a<5; a++){
							getline(data_buku, baru2);
						}
							get = baru2.substr(9,8);
							if(get == "Tersedia"){
								break;
							}
							else if(get != "Tersedia") {
								cout<<"Buku sudah dipinjam"<<endl;
								system("pause");
								exit (0);
							}
			
					}
					else if(baru2.find(judul_baru)!=8 && data_buku.eof() ){
					cout<<"Buku tidak ditemukan"<<endl;
					system("pause");
					exit (0);
					}
				}
			cout<<"Masukkan penulis buku baru : ";
			getline(cin, penulis_baru);
			newfile1<<"Nama peminjam   : "<<nama_baru<<"\n";
			newfile1<<"Alamat peminjam : "<<alamat_baru<<"\n";
			newfile1<<"No Handphone    : "<<nohp_baru<<"\n";
			newfile1<<"Jenis kelamin   : "<<kelamin_baru<<"\n";
			newfile1<<"Judul buku      : "<<judul_baru<<"\n";
			newfile1<<"Penulis buku    : "<<penulis_baru<<"\n\n";
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

void showHomescreen(){
	char pilih;
	do{
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
