#include <iostream>
using namespace std;

// Pendeklarasian dan inisialisasi linked list Mahasiswa (berurutan dari yang paling kecil (head) ke yang paling besar (tail))
struct Mahasiswa
{
	string nama;
	int NIM;
	Mahasiswa* next;
};
Mahasiswa* head;

void buat()
{
	head = NULL;
}

void isi(string input_nama, int input_NIM)
{
	Mahasiswa* cur = new Mahasiswa;
	Mahasiswa* prev = new Mahasiswa; // Pointer yang menunjuk node sebelum cur

	// Node yang akan ditambahkan ke list
	Mahasiswa* baru = new Mahasiswa;
	baru->nama = input_nama;
	baru->NIM = input_NIM;

	// inisialisas prev dan cur
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

		while (cur != NULL && cur->NIM > input_NIM)
		{
			prev = cur;
			cur = cur->next;
		}

		// Jika cur menunjuk ke node paling terakhir, taruh node baru di paling belakang
		if (cur == NULL) {
			prev->next = baru;
			baru->next = NULL;
		}
		// Jika cur tidak menunjuk ujung list, sisipi node baru di antara node-node lain
		else
		{
			prev->next = baru;
			baru->next = cur;
		}
	}

}

void cetak() {
	for (Mahasiswa* cur = head; cur != NULL; cur = cur->next)
		cout
		<< "Nama   : " << cur->nama << "\n"
		<< "NIM    : " << cur->NIM << "\n\n";
}

int main()
{
	buat();
	isi("Bebek", 10);
	isi("Ayam", 30);
	cetak();
}
