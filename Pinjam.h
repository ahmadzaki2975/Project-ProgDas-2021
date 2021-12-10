#ifndef PINJ_H
#define PINJ_H

#include<iostream>
using namespace std;

class Pinjam{
	private:
		string judul_buku;
		string penulis;
		string nama_peminjam;
		string alamat;
		string no_hp;
		string kelamin;
	public:
	
	
	Pinjam(string input_judul ="null" , string input_penulis="null", string input_nama="null" , string input_alamat="null", string input_nohp="null", string input_kelamin="null");
	void setData();
	void getscreen();
	void saveFile();
	void showData();
	void deleteData();	
	void updateData();
		
};

void showHomescreen();

#endif
