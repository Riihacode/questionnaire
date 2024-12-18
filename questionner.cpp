#include <iostream>
#include <string>
using namespace std;

// variable yang tidak akan berubah nilainya. 
/* yg ini buat menentukan hasil klasifikasi skor untuk hasil 
analisis dari `bagianKuisionerHasil()`*/
const string 
    level_stress_rendah     = "10-20: Level stress rendah",
    level_stress_sedang     = "21-30: Level stress sedang",
    level_stress_tinggi     = "31-40: Level stress tinggi",
    level_stress_parah      = "41-50: Level stress parah"
;

// variable yang tidak akan berubah nilainya
// variable ini untuk menampilkan intruksi inputan user pada `bagianKuisioner(0)`
const string instruksiKuisioner = 
R"(Mohon isi pertanyaan dengan inputan 1 - 5, berikut detailnya:
    1 = Tidak pernah
    2 = jarang
    3 = Kadang-kadang
    4 = Sering
    5 = Selalu
)";

// variable yang tidak akan berubah nilainya
const string arrayKuisionerPertanyaan[10] = 
{
    "Saya merasa kewalahan dengan banyaknya pekerjaan yang harus saya lakukan? ",
    "Saya mengalami gejala fisik (sakit kepala, kelelahan, dll) akibat stres akibat pekerjaan? ",
    "Saya merasa tidak punya cukup waktu untuk menyelesaikan tugas saya? ",
    "Saya khawatir membuat kesalahan dalam pekerjaan saya? ",
    "Saya merasa sulit untuk menyeimbangkan pekerjaan dan kehidupan pribadi saya? ",
    "Saya merasa tertekan oleh supervisor/manajer saya untuk memenuhi harapan yang tinggi? ",
    "Saya sulit berkonsentrasi pada pekerjaan karena stres? ",
    "Saya mendapati diri saya bekerja lembur untuk memenuhi tenggat waktu? ",
    "Saya merasa didukung oleh rekan-rekan saya ketika saya berada di bawah tekanan? ",
    "Saya merasa burn out karena pekerjaan saya? "
};

/* variable global array yang menyimpan inputan 
jawaban user dari function `void bagianKuisioner();`*/
int arrayKuisionerInput[10];

/* variable global agar untuk pengisian function`bagianDataDiri()` 
dan nantinya akan ditampilkan lagi pada function bagianKuisionerHasil() */
string 
    nama,
    jenis_kelamin,
    pekerjaan,
    alamat,
    umur,
    riwayat_penyakit
;

// deklarasi function agar bisa digunakan untuk dijalankan
void bagianDataDiri();
void bagianKuisioner();
void bagianKuisionerHasil();

// bagian utama yang akan dijalankan terlebih dahulu
int main(){
    bagianDataDiri();
    bagianKuisioner();
    bagianKuisionerHasil();
}

// function bagianDataDiri() untuk input data diri
void bagianDataDiri(){
    cout << "===========================\n";
    cout << "Inputkan data diri anda :" <<endl;
    cout << "Nama                       : ";
    getline(cin, nama);
    cout << "Jenis Kelamin              : ";
    getline(cin, jenis_kelamin);
    cout << "Pekerjaan                  : ";
    getline(cin, pekerjaan);
    cout << "Alamat                     : ";
    getline(cin, alamat);
    cout << "Umur                       : ";
    getline(cin, umur);
    cout << "Penyakit (riwayat terakhir): ";
    getline(cin, riwayat_penyakit);

    cout<<"\n===========================\n";
}

// function bagianKuisioner() untuk input pertanyaan kuisioner
void bagianKuisioner(){
    cout << "Bagian Pertanyaan \n\n";
    cout << instruksiKuisioner;

    // 0 - 9 = 10
    for (int halamanPertanyaanAkumulasi = 0; halamanPertanyaanAkumulasi < 10; halamanPertanyaanAkumulasi++) {
        int halamanPertanyaanSaatIni = halamanPertanyaanAkumulasi + 1;
        
        do {
            cout << "\nPertanyaan ke-" << halamanPertanyaanSaatIni << endl;
            cout << arrayKuisionerPertanyaan[halamanPertanyaanAkumulasi];
            cin >> arrayKuisionerInput[halamanPertanyaanAkumulasi];

            // Validasi input agar harus di antara 1 dan 5
            if (arrayKuisionerInput[halamanPertanyaanAkumulasi] < 1 || arrayKuisionerInput[halamanPertanyaanAkumulasi] > 5) {
                cout << "Input tidak valid. Harap masukkan angka antara 1 hingga 5.\n";
            }
            // Ulangi jika input tidak di antara 1 dan 5
        } while (arrayKuisionerInput[halamanPertanyaanAkumulasi] < 1 || arrayKuisionerInput[halamanPertanyaanAkumulasi] > 5); 
    }
}

// function bagianKuisionerHasil() untuk menampilkan hasil output kuisioner
void bagianKuisionerHasil(){
    int poinJawabanIndexTotal = 0;

    cout << "\n===============================\n";
    cout << "Hasil Analisis : "<<endl; 
    cout << "Nama                       = "<< nama << endl;
    cout << "Alamat                     = "<< alamat << endl;
    cout << "Pekerjaan                  = "<< pekerjaan << endl;
    cout << "Jenis Kelamin              = "<< jenis_kelamin << endl;
    cout << "Umur                       = "<< umur << endl;
    cout << "Penyakit (riwayat terkahir)= "<< riwayat_penyakit << endl <<endl;

    // Menghitung total poin
    for (int index = 0; index<10; index++){
        int poinJawabanIndex = arrayKuisionerInput[index];
        poinJawabanIndexTotal += poinJawabanIndex;
    }

    cout<<"Total poin : "<<poinJawabanIndexTotal<<endl;

    if (poinJawabanIndexTotal >50){
        cout << "Unknown"<< endl;
    } else if (poinJawabanIndexTotal > 40){
        cout << "Level stress anda adalah " << level_stress_parah;
    } else if (poinJawabanIndexTotal > 30){
        cout << "Level stress anda adalah " << level_stress_tinggi;
    } else if (poinJawabanIndexTotal > 20){
        cout << "Level stress anda adalah " << level_stress_sedang;
    } else if (poinJawabanIndexTotal >= 10){
        cout << "Level stress anda adalah " << level_stress_rendah;
    } else {
        cout << "Unknown" << endl;
    }
    
    cout << "\n===============================" << endl; 
}