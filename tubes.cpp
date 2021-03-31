//PROGRAM KECOAK DESTROYER TUGAS BESAR SEKURO
//16520373-Farrel Ahmad
//ISI NIM KALIAN

#include <iostream >
#include <cmath>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <cstdlib>
#include <conio.h>
#include<windows.h>
using namespace std;

// procedure visualisasi peta 20 x 20
char visualize (int a, int b, int c, int d){
    int i; int j;
    int xrob = a; int yrob = 20-b;
    int xkec = c; int ykec = 20-d;
    for (i=0;i<=20;i++){
        for (j=0;j<=20;j++){
            if ((i==yrob) && (j==xrob))
                {
                cout << " O ";
                }
            else if ((i==ykec) && (j==xkec))
                {
                    cout << " X ";
                }
            else
                {
                    cout << " . ";
                }
        }
    cout <<endl;
    }}

//fungsi cek posisi robot pada batasan peta
int checkposition(int a, int b)
{
    //parameter input: a (XR), b(YR)
    if (a<0 || b<0 || a>20 || b>20)
    {
        return false;
    }
    else
    {
        return true;
    }
}

// proceduremenunjukkan posisi robot dan kecoak sekarang
int showposition(int a, int b, int c, int d)
//parameter input: a(XR), b(YR), c(XK), d(YK)
{
    cout << "XR = " << a << ", YR = " << b <<endl;
    cout << "XK = " << c << ", YK = " << d <<endl;
    cout << "DeltaX = " << abs(a-c) <<", DeltaY = " << abs(b-d) << endl;
}

// fungsi jarak robot-kecoak dengan pythagoras atau jarak terpendek
bool cekjarak(double a, double b, double c, double d, double e){
    //parameter input: a(dvxr), b(dvyr), c(dvxk), d(dvyk), e (radius max senjata)
    if (sqrt(pow((a-c),2)+ pow((b-d),2)) <= e)//dalam radius senjata
    {
        return true;
    }
    else //di luar radius senjata
    {
        return false;
    }
}

int main (){ //Spawn Kecoa Random
    srand((unsigned) time(0));
    int xk, yk, hpr ,dmgr, xr, yr, hpk, dmgk, gerak, pilihan ;
    // radius, dvxr (double value of X Robot), dvyr (double value of Y robot), dvxk (double value of X kecoak), dvyk (double value of Y kecoak)
    // double data type, bukan dobel nilainya
    double rad, dvxr, dvyr, dvxk, dvyk;
    dmgk = 2;
    hpk = 200;
    xr = 0;
    yr = 0;
    rad = 5.0; // jarak maksimum senjata adalah radius 5
    dmgr = 5 ;
    hpr = 100 ;
    hpk = 50 ;
    xk = (rand() % 16) + 5; // random number range xk [5,20]
    yk = (rand() % 16) + 5; // random number range yk [5,20]
    dvxk = (1.0 * xk); //xk converted to double
    dvyk = (1.0 * yk);//yk converted to double
    while (hpk > 0){
        dvxr = (1.0*xr);
        dvyr = (1.0*yr);
        visualize(xr,yr, xk, yk);
        cout << "'O' adalah Robot dan 'X' adalah Kecoak" << endl;
        showposition(xr,yr,xk,yk);
        cout << "\nMasukkan Perintah: " << endl;
        cout << "(1) Untuk bergerak" << endl;
        cout << "(2) Untuk menembak" << endl;
        cin >> pilihan ;
        if (pilihan == 1){
            system("cls");
            bool flag = true;
            while (flag)
            {
                visualize(xr, yr, xk, yk);
                showposition(xr,yr,xk,yk);
                cout << "Use arrow keys to move and press 'S' on keyboard to stop" << endl;
                int ch = getch();
                if (ch == 224){  //arrow key input
                    ch = getch();
                    switch (ch)
                    {
                        case 72 : // up (224,72)
                            if (checkposition(xr,yr+1))
                                {
                                    yr+=1; break;
                                }
                            else{
                                cout << "Robot dilarang keluar peta" << endl;
                                Sleep(600);
                                break;
                            }
                        case 80 : // down (224,80)
                            if (checkposition(xr,yr-1))
                                {
                                    yr-=1; break;
                                }
                            else{
                                cout << "Robot dilarang keluar peta" << endl;
                                Sleep(600);
                                break;}
                        case 77 :  // right (224,77)
                            if (checkposition(xr+1,yr))
                                {
                                    xr+=1; break;
                                }
                            else{
                                cout << "Robot dilarang keluar peta" << endl;
                                Sleep(600);
                                break;}
                        case 75 : // left (224,75)
                            if (checkposition(xr-1,yr))
                                {
                                    xr-=1; break;
                                }
                            else{
                                cout << "Robot dilarang keluar peta" << endl;
                                Sleep(600);
                                break;
                    }}}
                else if (ch == 115) //nomor input keyboard 115 adalah huruf 's'
                {
                    system("cls");
                    flag = false;
                }
                else{
                    cout <<"wrong input"<<endl;
                    Sleep(150);
                }
                system("cls");
            }
            }
        else if (pilihan == 2){
            system("cls");
            if (cekjarak(dvxr,dvyr,dvxk,dvyk,rad)){
            cout << "\n\n\n\n\n\n\n\n\n\n\nRobot berhasil menyerang kecoa" << endl;
            hpk -= dmgr;
            cout << "Darah kecoa sekarang sebanyak " ;
            cout << hpk << endl;
            }
            else // cekjarak(dvxr,dvyr,dvxk,dvyk,rad) == false
            {
                cout << "\n\n\n\n\n\n\n\n\n\n\nRobot masih terlalu jauh, belum bisa menembak" << endl;
            }
            Sleep(1150);
            system("cls");
        }
        else // salah input pilihan
        {
            cout << "pilihan salah" << endl;
            Sleep(500);
            system("cls");
        }

    }
return 0;
}
