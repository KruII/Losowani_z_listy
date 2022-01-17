#include "icludy.h" //Biblioteka includów.

using namespace std; //Uzupełnienie std.

int losowa,odpowiedz_int,wszystkie=0;
string line,odpowiedz;
vector<string> Uczniowie;

void wylosuj(int losowa[]){ //void losowania.
    for (int i = 0; i < odpowiedz_int; i++)  //pętla powtarzająca do ilości pytań.
    {
        losowa[i]=rand()%wszystkie; //Losowanie liczby od 0 do 9.
        for (int j = 0; j<i; j++)  //Losowanie ponowne dla fukcji jeżeli.
        {
            if (losowa[j] == losowa[i]) //Jeżeli wyraz "j" równa się wyraz "i" powtórz losownie.
            {
                losowa[i] = rand() % wszystkie; //Losowanie liczby od 0 do 9.
                j = -1; //Zerowanie wyrazu "j" gdyby była powtórzona nowo wylosowana liczba.
            }
    	}
	}
}

int main(){
    srand( time( NULL ) );
    setlocale(LC_CTYPE, "Polish");
    cout<<"Jeżeli chcesz stworzyć listę lub ją zastąpić wpisz: 1\nJeżeli chcesz dopisać do listy wpisz: 2\nJeżeli chcesz otworzyć biblioteke wpisz: 3\n";
    cin>>odpowiedz_int;
    cout<<"Podaj nazwe biblioteki: ";
    cin>>odpowiedz;
    fstream plik;
    if (odpowiedz_int==1)
    {
        plik.open(odpowiedz,ios::out);
        cout<<"Ile chcesz wprowadzić danych: ";
        cin>>odpowiedz_int;
        for (int i = 1; i <= odpowiedz_int; i++)
        {   
            if(i==1)
            {
			    getline(cin, odpowiedz);
		    }
            getline(cin, odpowiedz);
            plik<<odpowiedz<<endl;
        }
        plik.close();
        exit(0);
    }
    else if (odpowiedz_int==2)
    {
        plik.open(odpowiedz,ios::out | ios::app);
        cout<<"Ile chcesz wprowadzić danych: ";
        cin>>odpowiedz_int;
        for (int i = 1; i <= odpowiedz_int; i++)
        {
            if(i==1)
            {
			    getline(cin, odpowiedz);
		    }
            getline(cin, odpowiedz);
            plik<<odpowiedz<<endl;
        }
        plik.close();
        exit(0);
    }
    else if (odpowiedz_int==3)
    {
        plik.open(odpowiedz,ios::in);
        if(plik.good()!=true)
        {
            cout<<"Plik nieistnieje stwórz go";
            Sleep(5000);
            exit(0);
        }
        while(getline(plik, line))
        {
            Uczniowie.push_back(line);
            wszystkie+=1;
        }
        cout<<"Ile wylosować: ";
        cin>>odpowiedz_int;
        if (odpowiedz_int>wszystkie)
        {
            cout<<"Chyba coś za dużo uzupełnij bibliotekę i wróć później :)";
            Sleep(5000);
            exit(0);
        }
        int tab[odpowiedz_int];
        wylosuj(tab);
        for (int i = 1; i <= odpowiedz_int; i++)
        {
            cout<<i<<": "<<Uczniowie[tab[i-1]]<<endl;
        }
        plik.close();
    }
    else
    {
        cout<<"Nieznana czyność";
        Sleep(5000);
        exit(0);
    }
    return 0;
} 