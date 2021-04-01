
//PROGRAM KECOAK DESTROYER TUGAS BESAR SEKURO
//16520373-Farrel Ahmad
//16720470-Rizky Anggian Matondang
//16520222-Farrel Jonathan Vickeldo

#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
using namespace std;

//class robot
class Robot
{
    //access specifier
    public:
    int xr,yr,hpr,score;
    double rad;
    //Default
    Robot()
    {
    xr = 0; yr = 0 ; hpr = 100 ; score = 0; rad = 5.0;
    // jarak maksimum senjata adalah radius 5
    }
};

//class kecoak
class Kecoak
{
    //access specifier
    public:
    int xk, yk, hpk;
    double rad;
    //Default
    Kecoak()
    {
       srand((unsigned) time(0));
       xk = (rand() % 16) + 5; // random number range xk [5,20]
       yk = (rand() % 16) + 5; // random number range yk [5,20]
       hpk = 50 ;
       rad = 3.0;
    }
};

//pointer function to change value
void changevalue(int *a, int val)
{
    *a += val; // changing by dereferencing the memory address
}

void changerad(double *a, double val)
{
    *a = val;
}

// procedure visualisasi peta 20 x 20
void visualize (int a, int b, int c, int d){
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
int checkposition(int a, int b, int c, int d)
{
    //parameter input: a (XR), b(YR), c(XK), d(YK)
    if (a<0 || b<0 || a>20 || b>20)
    {
        return 1;
    }
    else if (a==c && b==d)
    {
        return 2;
    }
    else{
        return 3;
    }
}

// procedure menunjukkan posisi robot dan kecoak sekarang
void showstatus(int a, int b, int c, int d, int e, int f, int g)
    //parameter input: a(XR), b(YR), c(XK), d(YK), e(hpr), f(hpk), g(score robot)
{
    cout << "XR = " << a << ", YR = " << b << ", HP Robot = " << e << ", Destroyed = " << g << endl;
    cout << "XK = " << c << ", YK = " << d << ", HP Kecoak = " << f <<endl;
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
//pointer function to move object kecoak
void movekecoak(int *a, int *b, int *c, int *d)
{
    //parameter input: a(XR), b(YR), c(XK), d(YK)
    int m; //variabel lokal pilihan langkah acak ke atas atau ke bawah jika tidak satu sumbu
    if (*b==*d) //kecoak dan robot satu sumbu y
    {
        if (*a<*c) // robot << kecoak
        {
            *c-=1; // kecoak ke kiri
        }
        else // *c<*a  kecoak << robot
        {
            *c+=1; // kecoak ke kanan
        }
    }
    else if (*a==*c) //kecoak dan robot satu sumbu x
    {
        if (*d<*b) //kecoak di bawah robot
        {
            *d+=1; //kecoak ke atas
        }
        else // *b<*d  kecoak di atas robot
        {
            *d-=1; // kecoak ke bawah
        }
    }
    else if (*a>*c && *b>*d) //robot ada di kanan-atas kecoak
    {
        srand((unsigned) time(0)); //random mau ke atas atau ke kanan
        m = (rand() % 2) + 0;
        if (m==0)
        {
            *c +=1; //X kecoak
        }
        else
        {
            *d +=1; //Y kecoak
        }
    }
    else if (*a>*c && *b<*d) //robot ada di kanan-bawah kecoak
    {
        srand((unsigned) time(0)); //random mau ke bawah atau ke kanan
        m = (rand() % 2) + 0;
        if (m==0)
        {
            *c +=1; //X kecoak
        }
        else
        {
            *d -=1; //Y kecoak
        }
    }
    else if (*a<*c && *b>*d) //robot ada di kiri-atas kecoak
    {
        srand((unsigned) time(0));
        m = (rand() % 2) + 0; //random mau ke atas atau ke kiri
        if (m==0)
        {
            *c -=1; //X kecoak
        }
        else
        {
            *d +=1; //Y kecoak
        }
    }
    else if (*a<*c && *b<*d) //robot ada di kiri-bawah kecoak
    {
        srand((unsigned) time(0)); //random mau ke bawah atau ke kiri
        m = (rand() % 2) + 0;
        if (m==0)
        {
            *c -=1; //X kecoak
        }
        else
        {
            *d -=1; //Y kecoak
        }
    }

}

int main (){ //Spawn Kecoa Random
    //INISIALISASI
    Robot R1;
    int dmgr, dmgk, pilihan ;
    double dvxr, dvyr, dvxk, dvyk; //dv = double data type value of xr/yr/xk/yk
    dmgk = -3;
    dmgr = -5 ;

    //ALGORITMA PROGRAM UTAMA
    cout << "\n\n\n\n\n\n\n\n-------------------------------------------------------------" << endl;
    cout << " Welcome to Ganesha Defender Robot Operating System Ver 1.5" << endl;
    cout << "         Manufactured by Ganesha System Corporation" <<endl;
    cout << "      May this program be used for peaceful purposes..." << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << "\n\nBooting Up Ground Radar System..."<<endl;
    cout << "Booting Up Weaponry System..."<<endl;
    Sleep(4000);
    system("cls");
    while(R1.hpr>0)
    {Kecoak K1;
     dvxk = (1.0 * K1.xk); //xk converted to double
     dvyk = (1.0 * K1.yk);//yk converted to double
        while (K1.hpk > 0 && R1.hpr>0)
        {
            dvxk = (1.0 * K1.xk); //xk converted to double
            dvyk = (1.0 * K1.yk);//yk converted to double
            dvxr = (1.0*R1.xr);
            dvyr = (1.0*R1.yr);
            visualize(R1.xr,R1.yr, K1.xk, K1.yk);
            cout << "'O' adalah Robot dan 'X' adalah Kecoa" << endl;
            showstatus(R1.xr,R1.yr, K1.xk, K1.yk, R1.hpr, K1.hpk, R1.score);
            cout << "\nMasukkan Perintah: " << endl;
            cout << "(1) Untuk bergerak ; (2) Untuk menembak ; (3) Untuk mengganti senjata ; (4) Untuk keluar" << endl;
            pilihan = getch(); // keyboard input
            if (pilihan == 49){ // ASCII decimal 49 == '1'
                system("cls");
                bool flag = true;
                while (flag)
                {
                    visualize(R1.xr,R1.yr, K1.xk, K1.yk);
                    showstatus(R1.xr,R1.yr, K1.xk, K1.yk, R1.hpr, K1.hpk, R1.score);
                    cout << "Use arrow keys to move and press 'S' on keyboard to stop" << endl;
                    int ch = getch();
                    if (ch == 224){  //arrow key input
                        ch = getch();
                        switch (ch) //using ASCII decimal from keyboard
                        {
                            case 72 : // up (224,72)
                                if (checkposition(R1.xr,R1.yr+1, K1.xk, K1.yk)==3) //gerakan diperobolehkan
                                    {
                                        R1.yr+=1; flag = false; break;
                                    }
                                else if ((checkposition(R1.xr,R1.yr+1, K1.xk, K1.yk)==1)){
                                    cout << "Robot dilarang keluar peta" << endl;
                                    Sleep(600);
                                    break;
                                }
                                else
                                {
                                    cout <<"Awas nabrak kecoa!"<<endl; Sleep(600); break;
                                }
                            case 80 : // down (224,80)
                                if (checkposition(R1.xr,R1.yr-1, K1.xk, K1.yk)==3) //gerakan diperobolehkan
                                    {
                                        R1.yr-=1;flag = false; break;
                                    }
                                else if ((checkposition(R1.xr,R1.yr-1, K1.xk, K1.yk)==1)){
                                    cout << "Robot dilarang keluar peta" << endl;
                                    Sleep(600);
                                    break;
                                }
                                else
                                {
                                    cout <<"Awas nabrak kecoak!"<<endl; Sleep(600); break;
                                }
                            case 77 :  // right (224,77)
                                if (checkposition(R1.xr+1,R1.yr, K1.xk, K1.yk)==3) //gerakan diperobolehkan
                                    {
                                        R1.xr+=1; flag = false; break;
                                    }
                                else if ((checkposition(R1.xr+1,R1.yr, K1.xk, K1.yk)==1)){
                                    cout << "Robot dilarang keluar peta" << endl;
                                    Sleep(600);
                                    break;
                                }
                                else
                                {
                                    cout <<"Awas nabrak kecoak!"<<endl; Sleep(600); break;
                                }
                            case 75 : // left (224,75)
                                if (checkposition(R1.xr-1,R1.yr, K1.xk, K1.yk)==3) //gerakan diperobolehkan
                                    {
                                        R1.xr-=1; flag = false; break;
                                    }
                                else if ((checkposition(R1.xr-1,R1.yr, K1.xk, K1.yk)==1)){
                                    cout << "Robot dilarang keluar peta" << endl;
                                    Sleep(600);
                                    break;
                                }
                                else
                                {
                                    cout <<"Awas nabrak kecoa!"<<endl; Sleep(600); break;
                                }
                        }}
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
            else if (pilihan == 50){ // ASCII decimal 50 == '2'
                system("cls");
                if (cekjarak(dvxr,dvyr,dvxk,dvyk,R1.rad)){
                cout << "\n\n\n\n\n\n\n\n\n\n\nRobot berhasil menyerang kecoak" << endl;
                changevalue(&K1.hpk, dmgr);
                cout << "Darah kecoak sekarang sebanyak " ;
                if (K1.hpk > 0)
                {
                    cout << K1.hpk << endl;
                }
                else // K1.hpk <= 0
                {
                    cout << 0 << endl;
                }
                }
                else // cekjarak(dvxr,dvyr,dvxk,dvyk,rad) == false
                {
                    cout << "\n\n\n\n\n\n\n\n\n\n\nRobot masih terlalu jauh, belum bisa menembak" << endl;
                }
                Sleep(1150);
                system("cls");
            }
            else if (pilihan == 51)
            {
                cout << "\nPilihan senjata: " << endl;
                cout << "(1) Boomerang" << endl;
                cout << "\tDamage: 8" << "\tRange: 2" << endl;
                cout << "(2) Laser Beam" << endl;
                cout << "\tDamage: 3" << "\tRange: 10" << endl;
                cout << "(3) Mine" << endl;
                cout << "\tDamage: 1" << "\tRange: 15" << endl;
                cout << "(4) Normal Handgun" << endl;
                cout << "\tDamage: 5" << "\tRange: 5" << endl;
                pilihan = getch();

                if (pilihan == 49)
                {
                    system("cls");
                    double newrad;
                    newrad = 2.0;
                    dmgr = -8;
                    changerad(&R1.rad, newrad);
                    Sleep(1000);
                    system("cls");
                }
                else if (pilihan == 50)
                {
                    system("cls");
                    double newrad;
                    newrad = 10.0;
                    dmgr = -3;
                    changerad(&R1.rad, newrad);
                    Sleep(1000);
                    system("cls");
                }
                else if (pilihan == 51)
                {
                    system("cls");
                    double newrad;
                    newrad = 15.0;
                    dmgr = -1;
                    changerad(&R1.rad, newrad);
                    Sleep(1000);
                    system("cls");
                }
                else if (pilihan == 52)
                {
                    system("cls");
                    double newrad;
                    newrad = 5.0;
                    dmgr = -5;
                    changerad(&R1.rad, newrad);
                    Sleep(1000);
                    system("cls");
                }
            }
            else if (pilihan == 52){ //Program user memilih untuk keluar
                cout << "\n" ;
                cout << "Shutting down..." << endl;
                cout << "Destroyed = " << R1.score << endl;
                cout << "Program Terminated" << endl;

                exit(0);

            }
            else // salah input pilihan
            {
                cout << "pilihan salah"<< endl;
                Sleep(500);
                system("cls");
            }
            dvxk = (1.0 * K1.xk); //xk converted to double
            dvyk = (1.0 * K1.yk);//yk converted to double
            dvxr = (1.0*R1.xr);
            dvyr = (1.0*R1.yr);
            if (cekjarak(dvxr,dvyr,dvxk,dvyk,K1.rad)) //kesempatan kecoak menyerang atau jalan
            {
                cout << "\n\n\n\n\n\n\n\n\n\n\nKecoak berhasil menembak robot" << endl;
                changevalue(&R1.hpr, dmgk);
                cout << "Darah robot sekarang sebanyak ";
                if (R1.hpr>0)
                {
                    cout << R1.hpr<<endl;
                }
                else //R1.hpr <= 0
                {
                    cout << 0 << endl;
                }
                Sleep(1000);
                system("cls");
            }
            else //di luar jangkauan tembakan kecoak
            {
                movekecoak(&R1.xr, &R1.yr, &K1.xk, &K1.yk);
            }
        }
    if (K1.hpk <= 0)
        {
            R1.score+=1;
            cout << "Congratulations! You Destroyed " << R1.score << " Kecoak"<< endl;
            Sleep(1500);
        }
    }
    cout << "\n\n\n\n\n\n\n\n\n\n\nRobot telah hancur. Connection Terminated"<<endl;
    cout << "Destroyed = " << R1.score << endl;
    Sleep(1500);
return 0;
}
