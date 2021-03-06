/*********************************************************
**                     SAKARYA ÜNİVERSİTESİ
**             Bilgisayar ve Bilişim Bilimleri Fakültesi  
**                  Bilgisayar Mühendisliği Bölümü
**                     Programlama Giriş Dersi
**
**            ÖDEV NUMARASI..........:4
**            ÖĞRENCİ ADI............:YUSUF SİNA YILDIZ
**            ÖĞRENCİ NUMARASI.......:B171210004
**            DERS GRUBU.............:C GRUBU 1.ÖĞRETİM
**
**
*
**************************************************************/

#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;

class Matrix {
private:int matris[10][10];
		int sayac = 0;
		int rastgeleadet = 0;// kaç kere rand() kullanıldığını saymak için kullanılan degisken
		int gecici;//sıralama için
		int durum=1;//elemanKontrol() için
public:
	int olustur() {
		srand(time(NULL));
		//random elemanları atıyorum.
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				matris[i][j] = (rand() % 100) + 1;
				rastgeleadet++;
			}
		}
		//değerleri aynı olan elemanları,  hepsinin değerleri birbirinden farklı olana dek  randomla atıyorum
		while (sayac != 200)
		{
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					for (int i1 = 0; i1 < 10; i1++) {
						for (int j1 = 0; j1 < 10; j1++) {
							if (i == i1 && j == j1) { j1++; }//matris[i][j], matris[i1][j1] ler eşit olacağı için kendisiyle kıyaslamaması için j1 i arttırıyorum.
							if (matris[i][j] == matris[i1][j1]) { matris[i1][j1] = (rand() % 100) + 1; rastgeleadet++; }//eşit işe tekrar random sayı.
						}
					}
				}
			}sayac++;
		}
		return rastgeleadet;//rand() kaç kere kullanıldığını döndürdüm.
	}

	bool elemanKontrol() {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				for (int i1 = 0; i1 < 10; i1++) {
					for (int j1 = 0; j1 < 10; j1++) {
						if (i == i1 && j == j1) { j1++; }
						if (matris[i][j] == matris[i1][j1]) { durum = 0; break; }
					}
				}
			}
		}
		return durum;
	}

	//büyükten kücüge sıralatıyorum.
	void sirala() {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				for (int i1 = 0; i1 < 10; i1++) {
					for (int j1 = 0; j1 < 10; j1++) {
						if (matris[i][j] > matris[i1][j1]) {
							gecici = matris[i][j];
							matris[i][j] = matris[i1][j1];
							matris[i1][j1] = gecici;
						}
					}
				}
			}
		}
	}

	void matrisYaz() {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				cout << setw(4) << matris[i][j];
			}cout << endl;
		}
	}


};

int main()
{
	Matrix m;
	cout << "Rastgele cagirilma adeti : " << m.olustur() << endl;
	cout << "Rastgele olusan ve elemanları birbirinden farkli matris" << endl;
	m.matrisYaz();
	m.elemanKontrol();
	cout <<endl<<endl<< "Buyukten kucuge siralanmis matris" << endl;

	m.sirala();
	m.matrisYaz();
	system("pause");
    return 0;
}

