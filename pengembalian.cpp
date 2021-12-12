#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Pengembalian{
    public:
        string title;
        string penulis;

        string nama;
        string alamat;
        string no_hp;

    Pengembalian(string inTitle, string inPenulis, string inNama, string inAlamat, string inNo_hp){

    Pengembalian::title     = inTitle;
    Pengembalian::penulis   = inPenulis;
    Pengembalian::nama      = inNama;
    Pengembalian::alamat    = inAlamat;
    Pengembalian::no_hp     = inNo_hp;
    }

};

    void addDataPengembalian(){

    string inputJudul, inputPenulis, inputNama, inputAlamat, inputNo_hp, baris;
    ifstream inFile;
    inFile.open("Data Peminjaman.txt");

        cout << "INPUT DATA BUKU"   << endl;
        cout << "Judul\t\t: ";
        getline(cin, inputJudul);
        cout << "Penulis\t\t: ";
        getline(cin, inputPenulis);
        cout << "Nama peminjam\t: ";
        getline(cin, inputNama);

        while(!inFile.eof()){
            getline(inFile, baris);

            if(baris.find(inputNama)==18){
                break;
            }
            else if(inFile.eof() && baris.find(inputNama)!=18){
                cout << "=============================" << endl;
                cout << "Data peminjam tidak ditemukan" << endl;
                system("pause");
                exit(0);
            }
        }

        cout << "Alamat\t\t: ";
        getline(cin, inputAlamat);
        cout << "Nomor hape\t: ";
        cin >> inputNo_hp;
        cout << " ";

Pengembalian p1 = Pengembalian(inputJudul, inputPenulis, inputNama, inputAlamat, inputNo_hp);

    ofstream outFile;
    outFile.open("Data Pengembalian.txt", ios::app);
    if(outFile.is_open()){
        outFile << "Judul\t\t: " << p1.title << endl;
        outFile << "Penulis\t\t: " << p1.penulis << endl;
        outFile << "Nama Peminjam\t: " << p1.nama << endl;
        outFile << "Alamat\t\t: " << p1.alamat << endl;
        outFile << "Nomor hape\t: " << p1.no_hp << endl;
        outFile << " " << endl;
        }

}

    void displayDataPengembalian(){
        ifstream inFile;
        string lines;
        inFile.open("Data Pengembalian.txt");
        cout << " " << endl;
        cout << "Data Pengembalian" << endl;
        cout << "=========================" << endl;
        while(getline(inFile, lines)){
            cout << lines << endl;
        }
    }

    void deleteDataPengembalian(){
	string judul, baru;
	cout << "===================================================" << endl;
	cout << "MENGHAPUS DATA PENGEMBALIAN" << endl;
	cout << "Note : Judul harus sama persis (Kapital harus sesuai)" << endl;
	cout << "===================================================" << endl;
	cout << "Masukkan judul buku : ";
	getline(cin, judul);
	ifstream myfile;
	myfile.open("Data Pengembalian.txt");
	ofstream newfile;
	newfile.open("new.txt", ios::app);

	while(getline(myfile, baru)){
    size_t foundWord = baru.find(judul);
    if(foundWord != string::npos){
        for(int a=0; a<6; a++){
				getline(myfile, baru);
			}
    }
    if(!myfile.eof()){
		newfile<<baru<<"\n";
		}
	}
	myfile.close();
	newfile.close();

	remove("Data Pengembalian.txt");
	rename("new.txt","Data Pengembalian.txt");
    }

    void clearDataPengembalian(){
    ofstream outFile;
    outFile.open("Data Pengembalian.txt", ios::trunc);
    outFile.close();
    cout << "\nSemua data pengembalian telah terhapus\n\n";
    }
/*int main(){
    return 0;
}*/
