/*
Nama	: Muhammad Rizqi Ardiansyah
Kelas	: S1 2020 TI-B
NIM		: 20051204044
*/

#include <iostream>
using namespace std;
// Pendeklarasian dan inisialisasi linked list Mahasiswa (berurutan dari yang paling kecil (head) ke yang paling besar (tail))
struct Mahasiswa
{
	string nama;
	long NIM;
	Mahasiswa* next;
};
Mahasiswa* head;

// Membuat list, diawali dengan node pertama NULL
void buat()
{
	head = NULL;
}

// Menyisipkan/menambahkan node ke dalam list
void isi(string input_nama, long input_NIM)
{
	Mahasiswa* cur = new Mahasiswa;
	Mahasiswa* prev = new Mahasiswa; // Pointer yang menunjuk node sebelum cur

	// Node yang akan ditambahkan ke list
	Mahasiswa* baru = new Mahasiswa;
	baru->nama = input_nama;
	baru->NIM = input_NIM;

	// Inisialisasi prev dan cur
	prev = NULL; cur = head;

	// Jika linked list masih kosong
	if (head == NULL) {
		// Tetapkan variabel baru sebagai head dari linked list
		head = baru;
		baru->next = NULL;
	}
	// Jika linked list tidak kosong
	else
	{
		/* Pengulangan yang berhenti ketika
		elemen NIM dari node yang ditunjuk
		pointer cur lebih kecil daripada
		input_NIM atau cur sudah tidak ber-
		nilai NULL*/

		while (cur != NULL && cur->NIM < input_NIM)
		{
			prev = cur;
			cur = cur->next;
		}

		// Jika cur menunjuk ke node paling terakhir, taruh node baru di paling belakang
		if (cur == NULL) {
			prev->next = baru;
			baru->next = NULL;
		}
		// Jika cur menunjuk ke node paling pertama (dengan kata lain prev = NULL)
		else if (prev == NULL) {
			baru->next = cur;
			head = baru;
		}
		// Jika cur tidak menunjuk ujung list, sisipi node baru di antara node-node lain
		else
		{
			prev->next = baru;
			baru->next = cur;
		}
	}

}

// Menghapus node dalam list
void hapus(string input_nama, long input_NIM)
{
	Mahasiswa* cur = new Mahasiswa;
	Mahasiswa* prev = new Mahasiswa;

	// Inisialisasi prev dan cur
	prev = NULL; cur = head;

	while (cur != NULL)
	{
		// Jika data yang ingin dihapus sama
		if ((cur->nama == input_nama) && (cur->NIM == input_NIM))
		{
			// Jika cur menunjuk node pertama
			if (prev == NULL) {
				head = head->next;
				delete cur;
				break;
			}
			prev->next = cur->next;
			delete cur;
			break;
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}

	}
	if (cur == NULL)
	{
		cout << "\nMaaf, data yang Anda inginkan untuk dihapus tidak ada\n";
	}

}

// Mencetak seluruh isi list
void cetak() {
	if (head == NULL) {
		cout << "\nMaaf, data masih kosong\n";
	}

	for (Mahasiswa* cur = head; cur != NULL; cur = cur->next)
		cout
		<< "Nama   : " << cur->nama << "\n"
		<< "NIM    : " << cur->NIM << "\n\n";
}

// Fungsi main
int main()
{
	buat(); // Menginisialisasi linked list

	char menu;
	cout << "Halo, selamat datang. ";
	while (true)
	{
		// Print menu
		cout
			<< "\nPilih menu di bawah ini: "
			<< "\n1. Isi data mahasiswa"
			<< "\n2. Hapus data mahasiswa"
			<< "\n3. Lihat data mahasiswa"
			<< "\nKetik x untuk keluar dari program\n>> ";
		cin >> menu;

		// Pilih menu
		string input_nama; long input_NIM;
		switch (menu)
		{
		case '1':
			cout << "Isi nama: \n>> ";
			cin >> input_nama;
			cout << "Isi NIM: \n>> ";
			cin >> input_NIM;
			cin.ignore();
			isi(input_nama, input_NIM);
			break;

		case '2':
			cout << "Isi nama: \n>> ";
			cin >> input_nama;
			cout << "Isi NIM: \n>> ";
			cin >> input_NIM;
			hapus(input_nama, input_NIM);
			break;

		case '3':
			cout << "\n\n";
			cetak();
			break;

		case 'x':
		case 'X':
			cout << "\nSampai Jumpa :)";
			return 0;
			break;

		default:
			cout << "\nIsi dengan benar.";
			break;
		}
	}

	return 0;
}

/* Made with love by Rizqi :)*/