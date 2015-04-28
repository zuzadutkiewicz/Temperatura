#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <fstream>
#define WIELKOSC 40

using namespace std;


float Fahr_to_Kelv(float);
float Fahr_to_Cels(float);
float Cels_to_Fahr(float);
float Cels_to_Kelv(float);
float Kelv_to_Fahr(float);
float Kelv_to_Cels(float);
int sprawdz_zakres(float, char);

void opcja_losowanie(float [],float [],char [],char []);
void losowa(float [],float [],char [],char [],int);

int los_znak(int);
void kompresowanie(float [],float [],char [],char []);
int sprawdz_ciag(float [],char [],int);

void wypisz_tablice(float [],float [],char [],char []);

void zmiana_wartosci(float [],float [],char[],char []);

void przypisz_do_tablicy(float [], float [], char [], char [], int, float, float);
void szukaj_wolnego_i_przypisz(float [],float [],char [],char [],float, float, char, char);

void wyswietl_wybrane(float [],float [],char [],char[]);
void usun_wiersz(float [],float [],char [],char []);

void zerowanie(float[],float [],char [],char []);

void wyb_wyswietl_wiersz(float [],float [],char [],char[]);
void wyswietl_wiersz(float [],float [],char [],char[], int nr_wiersza);

void zapisz_plik(float tab1[],float tab2[],char znak1[],char znak2[]);
void odczytaj_z_pliku(float tab1[],float tab2[],char znak1[],char znak2[]);

int index=0;

int main()
{
    srand(time(NULL));
    int opcja,index,x,y,z,indeks=0,c;
    float n;
    char a,znak,wynik;
    float tab1[WIELKOSC];
    float tab2[WIELKOSC];
    char znak1[WIELKOSC];
    char znak2[WIELKOSC];
    for(index=0; index<WIELKOSC; index++)
    {
        tab1[index]=0;
        tab2[index]=0;
        znak1[index]= ' ';
        znak2[index]= ' ';
    }

    while(1)
    {
        printf("____________________________\n");
        printf("Menu:\n");
        printf("1. Przelicz Fahrenheita  na Kelvina \n");
        printf("2. Przelicz Fahrenheita  na Celsjusza \n");
        printf("3. Przelicz Celsjusza  na Fahrenheita \n");
        printf("4. Przelicz Celsjusza  na Kelvina \n");
        printf("5. Przelicz Kelvina  na Fahrenheita \n");
        printf("6. Przelicz Kelvina  na Celsjusza \n");
        printf("7.Wyswietl tablice z jednostkami\n");
        printf("8.Zmien wartosc tablicy i przelicz do drugiej tablicy\n");
        printf("9.Dopelnij tablice losowymi wartosciami\n");
        printf("10.Usun puste wiersze z tablicy\n");
        printf("11.Usun wybrany wiersz\n");
        printf("12.Wyswietl wybrany zakres wierszy\n");
        printf("13.Wyzeruj tablice\n");
        printf("14.Wyswietl wybrany wiersz\n");
        printf("15.Zapisz dane w pliku tekstowym\n");
        printf("16.Odczytaj dane z pliku tekstowego\n");
        printf("0.Zakoncz\n");
        printf("____________________________\n");
        printf("\nWybierz polecenie:\t");
        scanf("%d", &opcja);
        printf("\n");
        if(opcja==0)
            break;
        switch(opcja)
        {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
            printf("Podaj wartosc jaka chcesz przeliczyc:\t");
            scanf("%f", &n);
            printf("\n");
            if(opcja==1&&sprawdz_zakres(n, 'F')==1)
            {
                printf("%.2f F to %.2f K\n\n", n,Fahr_to_Kelv(n));
                przypisz_do_tablicy(tab1,tab2,znak1,znak2,opcja,n,Fahr_to_Kelv(n));

            }
            else if(opcja==2&&sprawdz_zakres(n, 'F')==1)
            {
                printf("%.2f F to %.2f C\n\n", n,Fahr_to_Cels(n));
                przypisz_do_tablicy(tab1,tab2,znak1,znak2,opcja,n,Fahr_to_Cels(n));
            }
            else if(opcja==3&&sprawdz_zakres(n, 'C')==1)
            {
                printf("%.2f C to %.2f F\n\n", n,Cels_to_Fahr(n));
                przypisz_do_tablicy(tab1,tab2,znak1,znak2,opcja,n,Cels_to_Fahr(n));
            }
            else if(opcja==4&&sprawdz_zakres(n, 'C')==1)
            {
                printf("%.2f C to %.2f K\n\n", n,Cels_to_Kelv(n));
                przypisz_do_tablicy(tab1,tab2,znak1,znak2,opcja,n,Cels_to_Kelv(n));
            }
            else if(opcja==5&&sprawdz_zakres(n, 'K')==1)
            {
                printf("%.2f K to %.2f F\n\n", n,Kelv_to_Fahr(n));
                przypisz_do_tablicy(tab1,tab2,znak1,znak2,opcja,n,Kelv_to_Fahr(n));
            }
            else if(opcja==6&&sprawdz_zakres(n, 'K')==1)
            {
                printf("%.2f K to %.2f C\n\n", n,Kelv_to_Cels(n));
                przypisz_do_tablicy(tab1,tab2,znak1,znak2,opcja,n,Kelv_to_Cels(n));
            }
            else
                printf("Blad. Wartosc poza zakresem\n\n");
            break;
        case 7:
            wypisz_tablice(tab1,tab2,znak1,znak2);
            break;
        case 8:
            zmiana_wartosci(tab1,tab2,znak1,znak2);
            break;
        case 9:
            opcja_losowanie(tab1,tab2,znak1,znak2);
            break;
        case 10:
            kompresowanie(tab1,tab2,znak1,znak2);
            break;
        case 11:
            usun_wiersz(tab1,tab2,znak1,znak2);
            break;
        case 12:
            wyswietl_wybrane(tab1,tab2,znak1,znak2);
            break;
        case 13:
            zerowanie(tab1,tab2,znak1,znak2);
            break;
        case 14:
            wyb_wyswietl_wiersz(tab1,tab2,znak1,znak2);
            break;
        case 15:
            zapisz_plik(tab1,tab2,znak1,znak2);
            break;
        case 16:
            odczytaj_z_pliku(tab1,tab2,znak1,znak2);
            break;
        default:
            printf("\n\nNie ma takiej opcji!\n\n");
            break;
        }
    }
}
//Funkcje globalne:
float Fahr_to_Kelv(float temperatura)
{
    float wynik=Fahr_to_Cels(temperatura)+273.15;
    return wynik;
}
float Fahr_to_Cels(float temperatura)
{
    float wynik=(5.0/9.0)*(temperatura-32.0);
    return wynik;
}
float Cels_to_Fahr(float temperatura)
{
    float wynik=(9.0/5.0)*temperatura+32.0;
    return wynik;
}
float Cels_to_Kelv(float temperatura)
{
    float wynik=temperatura+273.15;
    return wynik;
}
float Kelv_to_Fahr(float temperatura)
{
    float wynik=(9.0/5.0)*(temperatura-273.15)+32.0;
    return wynik;
}
float Kelv_to_Cels(float temperatura)
{
    float wynik=temperatura-273.15;
    return wynik;
}
int sprawdz_zakres(float n, char znak)
{
    if((znak=='F'&&n>=-459.67)||(znak=='K'&&n>=0)||(znak=='C'&&n>=-273.15))
        return 1;
    else
        return 0;
}
void opcja_losowanie(float tab1[],float tab2[],char znak1[],char znak2[])
{
    int wybor,y;
    sprawdz_ciag(tab1,znak1,-1);
    if(sprawdz_ciag(tab1,znak1,0)>0||(znak1[0]!=' '&&znak2[0]!=0))
    {
        printf("Tablica zapelniona! Wybierz opcje:\n1.Nadpisz wartosci tablic\n2.Kompresuj tablice i losuj dla pustych wartosci\n3.Wypelnij puste pola wartosciami losowymi\n");
        scanf("%d", &wybor);
        switch(wybor)
        {
        case 1:
            y=0;
            losowa(tab1,tab2,znak1,znak2,y);
            break;
        case 2:
            kompresowanie(tab1,tab2,znak1,znak2);
            y=sprawdz_ciag(tab1,znak1,-1)+1;
            losowa(tab1,tab2,znak1,znak2,y);
            break;
        case 3:
            for(index=0; index<WIELKOSC; index++)
            {
                if(znak1[index]==' '&&znak2[index]==' ')
                {
                    tab1[index]=(rand()%2001)-1000;
                    znak1[index]=los_znak(rand()%3);
                    if(sprawdz_zakres(tab1[index],znak1[index])==1)
                    {
                        do
                        {
                            znak2[index]=los_znak(rand()%3);
                        }
                        while(znak2[index]==znak1[index]);
                        switch(znak2[index])
                        {
                        case 'F':
                            if(znak1[index]=='C')
                                tab2[index]=Cels_to_Fahr(tab1[index]);
                            else if(znak1[index]=='K')
                                tab2[index]=Kelv_to_Fahr(tab1[index]);
                            break;
                        case 'C':
                            if(znak1[index]=='F')
                                tab2[index]=Fahr_to_Cels(tab1[index]);
                            else if(znak1[index]=='K')
                                tab2[index]=Kelv_to_Cels(tab1[index]);
                            break;
                        case 'K':
                            if(znak1[index]=='C')
                                tab2[index]=Cels_to_Kelv(tab1[index]);
                            else if(znak1[index]=='F')
                                tab2[index]=Fahr_to_Kelv(tab1[index]);
                            break;
                        }
                    }
                }
            }
            break;
        default:
            printf("Blad, nie ma takiej opcji!\n\n");
            break;
        }
    }
    else
    {
        y=0;
        losowa(tab1,tab2,znak1,znak2,y);
    }
    printf("\nNacisnij dowolny klawisz aby kontynuowac do menu glownego:\n");
    getch();
}
void losowa(float tab1[],float tab2[],char znak1[], char znak2[],int y)
{
    index=y;
    for(index; index<WIELKOSC; index++)
    {
        tab1[index]=(rand()%2001)-1000;
        znak1[index]=los_znak(rand()%3);
        while(sprawdz_zakres(tab1[index],znak1[index])==0)
        {
            tab1[index]=(rand()%2001)-1000;
        }
        do
        {
            znak2[index]=los_znak(rand()%3);
        }
        while(znak2[index]==znak1[index]);
        switch(znak2[index])
        {
        case 'F':
            if(znak1[index]=='C')
                tab2[index]=Cels_to_Fahr(tab1[index]);
            else if(znak1[index]=='K')
                tab2[index]=Kelv_to_Fahr(tab1[index]);
            break;
        case 'C':
            if(znak1[index]=='F')
                tab2[index]=Fahr_to_Cels(tab1[index]);
            else if(znak1[index]=='K')
                tab2[index]=Kelv_to_Cels(tab1[index]);
            break;
        case 'K':
            if(znak1[index]=='C')
                tab2[index]=Cels_to_Kelv(tab1[index]);
            else if(znak1[index]=='F')
                tab2[index]=Fahr_to_Kelv(tab1[index]);
            break;
        }
    }
}
int los_znak(int y)
{
    y=rand()%3;
    if(y==0)
        return 'K';
    else if(y==1)
        return 'F';
    else if(y==2)
        return 'C';

}
void kompresowanie(float tab1[],float tab2[],char znak1[],char znak2[])
{
    int y,n=0;
    for(index=0; index<WIELKOSC; index++)
    {
        if(tab1[index]!=0||znak1[index]!= ' ')
        {
            for(y=n; y<index; y++)
            {
                if(znak1[y]== ' ')
                {
                    tab1[y]=tab1[index];
                    tab1[index]=0;
                    znak1[y]=znak1[index];
                    znak1[index]= ' ';
                    tab2[y]=tab2[index];
                    tab2[index]=0;
                    znak2[y]=znak2[index];
                    znak2[index]= ' ';
                    n++;
                    break;
                }
                else continue;
            }
        }
        else continue;
    }
    printf("Nacisnij dowolny klawisz aby kontynuowac do menu glownego..\n");
    getch();
}
int sprawdz_ciag(float tab[],char znak[],int y)
{
    int z,ostatni=0;
    for(z=y+1; z<WIELKOSC; z++)
    {
        if(tab[z]!=0||znak[z]!=' ')
        {
            ostatni=z;
        }
    }
    if(ostatni>0)
        return ostatni;
    else
        return 0;
}
void wypisz_tablice(float tab1[],float tab2[],char znak1[], char znak2[])
{
    int suma_pustych=0;
    for(index=0; index<WIELKOSC; index++)
    {
        if(znak1[index]!=' '&&znak2[index]!=' ')
        {
            printf("%d.\t%f %c\t->\t%f %c\n",index+1,tab1[index],znak1[index],tab2[index],znak2[index]);
        }
        else
            suma_pustych++;
    }
    if(suma_pustych==WIELKOSC)
        printf("Brak danych do wyswietlenia, wprowadz wartosci do tablic!\n\n");
    printf("\nNacisnij dowolny klawisz aby kontynuowac do menu glownego:\n");
    getch();
}
void zmiana_wartosci(float tab1[],float tab2[],char znak1[],char znak2[])
{
    int wiersz;
    float temp;
    char lS,lT;
    printf("Wybierz ktory wiersz chcesz edytowac(1-40):\t");
    scanf("%d", &wiersz);
    if(wiersz>=1&&wiersz<=WIELKOSC)
    {
        printf("\nPodaj nowa wartosc temperatury:\t");
        scanf("%f", &temp);
        printf("\nPodaj jednostke(K/F/C):\t");
        scanf(" %c", &lS);
        while(lS!='K'&&lS!='F'&&lS!='C')
        {
            printf("\nBlad, nie ma takiej jednostki! Podaj jednostke jeszcze raz:\t");
            scanf(" %c", &lS);
            printf("\n");
        }
        sprawdz_zakres(temp,lS);
        if(sprawdz_zakres(temp,lS)==1)
        {
            tab1[wiersz-1]=temp;
            znak1[wiersz-1]=lS;
            printf("\nPodaj jednostke na ktora chcesz przeliczyc podana wartosc(K/F/C):\t");
            scanf(" %c", &lT);
            printf("\n");
            while(lT==lS||lT!='K'&&lT!='F'&&lT!='C')
            {
                printf("Blad! Podaj jednostke jeszcze raz:\t");
                scanf(" %c", &lT);
                printf("\n");

            }
            switch(lT)
            {
            case 'F':
                if(lS=='C')
                {
                    tab2[wiersz-1]=Cels_to_Fahr(temp);
                    znak2[wiersz-1]=lT;
                }
                else if(lS=='K')
                {
                    tab2[wiersz-1]=Kelv_to_Fahr(temp);
                    znak2[wiersz-1]=lT;
                }
                printf("Zedytowany wiersz: %d\nNowe wartosci to:\n%f %c\t-->\t%f %c\n",wiersz,tab1[wiersz-1],znak1[wiersz-1],tab2[wiersz-1],znak2[wiersz-1]);
                break;
            case 'C':
                if(lS=='F')
                {
                    tab2[wiersz-1]=Fahr_to_Cels(temp);
                    znak2[wiersz-1]=lT;
                }
                else if(lS=='K')
                {
                    tab2[wiersz-1]=Kelv_to_Cels(temp);
                    znak2[wiersz-1]=lT;
                }
                printf("Dokonano edycji wiersza: %d\nNowe wartosci to:\n%d\t%f %c\t%f %c",wiersz,tab1[wiersz-1],znak1[wiersz-1],tab2[wiersz-1],znak2[wiersz-1]);
                break;
            case 'K':
                if(lS=='C')
                {
                    tab2[wiersz-1]=Cels_to_Kelv(temp);
                    znak2[wiersz-1]=lT;
                }
                else if(lS=='F')
                {
                    tab2[wiersz-1]=Fahr_to_Kelv(temp);
                    znak2[wiersz-1]=lT;
                }
                printf("Dokonano edycji wiersza: %d\nNowe wartosci to:\n%d\t%f %c\t%f %c",wiersz,tab1[wiersz-1],znak1[wiersz-1],tab2[wiersz-1],znak2[wiersz-1]);
                break;
            }
        }
        else
            printf("Blad, temperatura poza skala!\n\n");
    }
    else
        printf("Blad, nie istnieje taki wiersz!\n\n");
    printf("\nNacisnij dowolny klawisz aby kontynuowac do menu glownego:\n");
    getch();
}
void przypisz_do_tablicy(float tab1[],float tab2[],char znak1[],char znak2[],int opcja,float n,float funkcja)
{
    char lS, lT;
    switch(opcja)
    {
    case 1:
        lS='F';
        lT='K';
        szukaj_wolnego_i_przypisz(tab1,tab2,znak1,znak2,n,funkcja,lS,lT);
        break;
    case 2:
        lS='F';
        lT='C';
        szukaj_wolnego_i_przypisz(tab1,tab2,znak1,znak2,n,funkcja,lS,lT);
        break;
    case 3:
        lS='C';
        lT='F';
        szukaj_wolnego_i_przypisz(tab1,tab2,znak1,znak2,n,funkcja,lS,lT);
        break;
    case 4:
        lS='C';
        lT='K';
        szukaj_wolnego_i_przypisz(tab1,tab2,znak1,znak2,n,funkcja,lS,lT);
        break;
    case 5:
        lS='K';
        lT='F';
        szukaj_wolnego_i_przypisz(tab1,tab2,znak1,znak2,n,funkcja,lS,lT);
        break;
    case 6:
        lS='K';
        lT='C';
        szukaj_wolnego_i_przypisz(tab1,tab2,znak1,znak2,n,funkcja,lS,lT);
        break;
    }
}
void szukaj_wolnego_i_przypisz(float tab1[],float tab2[],char znak1[],char znak2[],float n,float funkcja,char lS,char lT)
{
    for(index=0; index<WIELKOSC; index++)
    {
        if(tab1[index]==0&&znak1[index]== ' '&&tab2[index]==0&&znak2[index]== ' ')
        {
            tab1[index]=n;
            znak1[index]=lS;
            tab2[index]=funkcja;
            znak2[index]=lT;
            printf("Nacisnij dowolny klawisz aby kontynuowac do menu glownego:\n");
            getch();
            return;
        }
        else
            continue;
    }
    if(index==WIELKOSC)
    {
        printf("Blad, brak miejsc w tablicy!\n\n");
        printf("Nacisnij dowolny klawisz aby kontynuowac do menu glownego:\n");
        getch();
        return;
    }
}
void wyswietl_wybrane (float tab1[],float tab2[],char znak1[],char znak2[])
{
    int wiersz1,wiersz2,x;
    printf("Podaj pierwszy wiersz(1-40):\t");
    scanf("%d", &wiersz1);
    printf("\nPodaj ostatani wiersz(1-40):\t");
    scanf("%d", &wiersz2);
    printf("\n");
    if(wiersz1>=1&&wiersz1<=WIELKOSC&&wiersz2>=1&&wiersz2<=WIELKOSC)
    {
        if(wiersz1>wiersz2)
        {
            for(x=wiersz1-1; x>=wiersz2-1; x--)
            {
                printf("%d.\t%f %c\t->\t%f %c\n", x+1,tab1[x],znak1[x],tab2[x],znak2[x]);
            }
        }
        else if(wiersz1<wiersz2)
        {
            for(x=wiersz1-1; x<wiersz2; x++)
            {
                printf("%d.\t%f %c\t->\t%f %c\n", x+1,tab1[x],znak1[x],tab2[x],znak2[x]);
            }
        }
        else if(wiersz1==wiersz2)
        {
            x=wiersz1-1;
            printf("%d.\t%f %c\t->\t%f %c\n", x+1,tab1[x],znak1[x],tab2[x],znak2[x]);
        }
    }
    else
        printf("\nBlad, wartosci poza skala tablicy!\n\n");
    printf("Nacisnij dowolny klawisz aby kontynuowac do menu glownego:\n");
    getch();
}
void usun_wiersz(float tab1[],float tab2[],char znak1[],char znak2[])
{
    int wiersz,x;
    char opcja;
    printf("Podaj numer wiersza, ktory chcesz usunac (1-40):\t");
    scanf("%d",&wiersz);
    printf("\n");
    index=wiersz-1;
    if(index>=0&&index<WIELKOSC-1)
    {
        for(index; index<WIELKOSC-1; index++)
        {
            tab1[index]=tab1[index+1];
            tab1[index+1]=0;
            znak1[index]=znak1[index+1];
            znak1[index+1]=' ';
            tab2[index]=tab2[index+1];
            tab2[index+1]=0;
            znak2[index]=znak2[index+1];
            znak2[index+1]=' ';
        }
    }
    else if(index==WIELKOSC-1)
    {
        tab1[index]=0;
        znak1[index]=' ';
        tab2[index]=0;
        znak2[index]=' ';
    }
    else
    {
        printf("\nBlad! Podany wiersz nie istnieje!\n\n");
    }
    printf("Czy chcesz kontynuowac usuwanie wierszy? (T/N):\t");
    scanf(" %c", &opcja);
    while(opcja!='T'&&opcja!='t'&&opcja!='N'&&opcja!='n')
    {
        printf("Blad, nie ma takiej opcji!  Wybierz opcje ponownie (T/N):\t");
        scanf(" %c", &opcja);
    }
    if(opcja=='T'||opcja=='t')
        usun_wiersz(tab1,tab2,znak1,znak2);
    else if(opcja=='N'||opcja=='n')
        return;
}
void zerowanie(float tab1[],float tab2[],char znak1[],char znak2[])
{
    for(index=0; index<WIELKOSC; index++)
    {
        tab1[index]=0;
        znak1[index]= ' ';
        tab2[index]=0;
        znak2[index]= ' ';
    }
    printf("\nNacisnij dowolny klawisz aby kontynuowac do menu glownego:\n");
    getch();
}
void wyb_wyswietl_wiersz(float tab1[],float tab2[],char znak1[],char znak2[])
{
    int nr_wiersza;
    printf("Podaj wiersz(1-40):\t");
    scanf("%d", &nr_wiersza);

    if (nr_wiersza<1 || nr_wiersza>40)
    {
        printf("\nBlad, wartosci poza skala tablicy!\n\n");
        printf("Nacisnij dowolny klawisz aby kontynuowac do menu glownego:\n");
        getch();
        return ;
    }
    if (znak1[nr_wiersza - 1] == ' ')
    {
        printf("Wiersz pusty\n");
    }
    else
    {
        wyswietl_wiersz( tab1, tab2, znak1, znak2,  nr_wiersza);
    }

    printf("Nacisnij dowolny klawisz aby kontynuowac do menu glownego:\n");
    getch();

}

void wyswietl_wiersz(float tab1[],float tab2[],char znak1[],char znak2[], int nr_wiersza)
{
    int nrtab = nr_wiersza-1;
    printf("%d.\t%f %c\t->\t%f %c\n", nr_wiersza,tab1[nrtab],znak1[nrtab],tab2[nrtab],znak2[nrtab]);
}

void zapisz_plik(float tab1[],float tab2[],char znak1[],char znak2[])
{
    int index = 0;
    char buf[100];
    fstream plik;
    plik.open("plik.txt", ios::out);
    if(plik.good()==true)
    {
        for(index=0; index<WIELKOSC; index++)
        {
            sprintf(buf,"%d %f %c %f %c", index,tab1[index],znak1[index],tab2[index],znak2[index]);
            plik << buf << endl;
        }
    }
    plik.close();
    printf("Nacisnij dowolny klawisz aby kontynuowac do menu glownego:\n");
    getch();

}
void odczytaj_z_pliku(float tab1[],float tab2[],char znak1[],char znak2[])
{
    fstream plik;
    string line;
    int index =0;
    plik.open("plik.txt", ios::in);
    {
        for(index=0; index<WIELKOSC; index++)
        {
            getline(plik,line);
            const char * buf = line.c_str();
            sscanf(buf, "%d %f %c %f %c", &index,&tab1[index],&znak1[index],&tab2[index],&znak2[index]);
        }
    }
    plik.close();
    printf("Nacisnij dowolny klawisz aby kontynuowac do menu glownego:\n");
    getch();
}

