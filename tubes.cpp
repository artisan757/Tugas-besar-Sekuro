#include <iostream >
#include <cmath>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <cstdlib>
using namespace std;

int jarak(int a, int b){
    return abs(b-a);
}



int main (){ //Spawn Kecoa Random
    srand((unsigned) time(0));
    int xk, yk, hpr ,dmgr, jarakmin_x, jarakmin_y, xr, yr, hpk, dmgk, gerak, pilihan ;
    dmgk = 2;
    hpk = 200;
    xr = 0;
    yr = 0;
    jarakmin_x = 10 ;
    jarakmin_y = 10 ;
    dmgr = 5 ;
    hpr = 100 ;
    hpk = 50 ;
    xk = (rand() % 50) + 20;
    yk = (rand() % 50) + 20;
    cout << xk << endl;
    cout << yk << endl;

    while (hpk > 0){
        cout << "Apakah kamu ingin bergerak" << endl;
        cout << "(1) Untuk bergerak" << endl;
        cout << "(2) Untuk Menembak" << endl;
        cin >> pilihan ;
        if (pilihan == 1){
            cout << "Anda ingin bergerak ke mana?" << endl;
            cout << "(1) Ke depan" << endl;
            cout << "(2) Ke kanan" << endl;
            cout << "(3) Ke belakang" << endl;
            cout << "(4) Ke kiri" << endl;
            cin >> gerak ;
            if (gerak == 1){
                yr += 1;
            }
            else if (gerak == 2){
                xr += 1;
            }
            else if (gerak == 3){
                yr -= 1;
                if (yr < 0){
                    cout << "Anda keluar dari map" << endl;
                    cout << "Kembali ke titik awal" << endl;
                    yr = 0;
                }
            }
            else if (gerak == 4){
                xr -= 1;
                if (xr < 0){
                    cout << "Anda keluar dari map" << endl;
                    cout << "Kembali ke titik awal" << endl;
                    xr = 0;
                }
            }

        }
        else if (pilihan == 2){

            if ((jarak(yk, yr) <= jarakmin_y) || (jarak(xk, xr) <= jarakmin_x) ){
            cout << "Robot berhasil menyerang kecoa" << endl;
            hpk -= dmgr;
            cout << "Darah kecoa sekarang sebanyak " ;
            cout << hpk << endl;
            }

            else if ((jarak(yk, yr) > jarakmin_y) || (jarak(xk, xr) > jarakmin_x) ){
                cout << "Robot masih terlalu jauh, belum bisa menembak" << endl;
            }


        }
        cout << "Posisi Anda sekarang ada di koordinat" << endl;
        cout << "x = " ;
        cout << xr << endl;
        cout << "y = " ;
        cout << yr << endl;
        xk -= 1 ;
        yk -= 1 ;
        cout << jarak(xk,xr)<< endl;
        cout << jarak(yk, yr) << endl;

    }
return 0;


}
