#include <iostream>
#include <fstream>
#include <cstdlib>
#include <fstream>
#include <ostream>
#include <vector>
using namespace std;

bool is_number(string);
void operacje();
void kursy_walut();
void portfel();
void kalkulator();

int main() {
    cout << "Witaj, co chcesz zrobic?" << "\n";
    while(true) {
        cout << "\n1. Sprawdz kursy kruptowalut" << "\n";
        cout << "2. Zamienic walute na inna" << "\n";
        cout << "3. Wykonac operacje na koncie" << "\n";
        cout << "4. Wyjsc" << "\n";
        cout << "\n\n>";
        string m;
        cin >> m ;
        if(!is_number(m)) {
            cout << "\nNieprawidlowy wybor\n\n";
            continue;
        }
        switch (stoi(m)) {
            case 1 :
                kursy_walut();
                break;
            case 2 :
                kalkulator();
                break;
            case 3 :
                portfel();
                break;
            case 4 :
                exit(0);
            default:
                cout << "\nNieprawidlowy wybor\n\n";
        }
    }

    return 0;
}

bool is_number(string s) {
    for(auto const &el : s) {
        if(!isdigit(el))
            return false;
    }
    return true;
}

void kalkulator () {
    int u1,u2;
    float k1,k2,s;
    string sk1,sk2,nk1,nk2;
    cout << "Wybierz dwie waluty do porownania: ";
    fstream nazwy("../nazwy.csv", ios::in);
    string tmp;
    vector<string> lines;
    while(getline(nazwy, tmp)) {
        lines.push_back(tmp);
    }
    for(int i = 0; i < lines.size(); ++i) {
        cout << i << ". " << lines.at(i) << "\n";
    }
    nazwy.close();

    fstream kalkulator("../kalkulator.csv", ios::in);
    string lk; // linia kalkulator
    vector<string> contentk;
    while(getline(kalkulator, lk)) {
        contentk.push_back(lk);
    }
    kalkulator.close();
    string s1, s2;
    cin >> s1 >> s2;
    if(!is_number(s1) || !is_number(s2)) {
        cout << "Nieprawidlowe dane\n";
        return;
    }
    u1 = stoi(s1);
    u2 = stoi(s2);
    string n1 = lines.at(u1);
    string n2 = lines.at(u2);
    if(u1>14 || u1 < 0 || u1 == u2){
        cout << "Nieprawidlowe dane\n";
        return;
    }

    k1= stof(contentk.at(u1));
    k2= stof(contentk.at(u2));

    s = k1/k2;
    cout << n1 << " jest warte " << s << n2 << endl;
}

void operacje () {
    int m_o,wartosc,zo; // menu_operacje ,  wartosc ,  zmienna operacje
    string bo; //

    ifstream inFile; // to czyta
    ofstream outdata; // to zapisuje

    inFile.open("../portfel.csv");
    if (!inFile) {
        cerr << "Nie mozna otworzyc pliku z danymi";
        exit(1);
    }

    cout << "Wybierz czy chcesz wplacic (1) czy wyplacic (2) srodki oraz kwote " << "\n";
    cout << "(opcja kwota)" << "\n";

    cin >> m_o >> wartosc ;
    getline(inFile, bo);
    zo = stoi(bo);
    inFile.close();
    outdata.open("../portfel.csv");
    if (!outdata) {
        cerr << "Nie mozna otworzyc pliku z danymi";
        exit(1);
    }
    switch (m_o) {
        case 1 :
            zo += wartosc;
            cout << "Wplacono: " << wartosc << "$" << "\n";
            cout << "Stan konta to: " << zo << "\n";
            outdata << zo << "\n";
            break;
        case 2 :
            zo -= wartosc;
            cout << "Wyplacono: " << wartosc << "$" << "\n";
            cout << "Stan konta to: " << zo << "\n";
            outdata << zo << "\n";
            break;
    }
    outdata.close();
}

void kursy_walut() {
    string dane;
    ifstream inFile;

    inFile.open("../kursy.csv");
    if (!inFile) {
        cout << "Unable to open file\n";
        exit(1); // terminate with error
    }
    while ( getline (inFile,dane) ) {
        cout << dane << '\n';
    }
    inFile.close();
    cout << "\n";
}

void portfel() {
    int mp,zp;
    string balance;
    ifstream inFile;
    cout << "Chcesz:" << "\n";
    cout << "1. Sprawdzic stan konta" << "\n";
    cout << "2. Wykonac operacje" << "\n";
    cin >> mp;
    switch (mp) {
        case 1 :
            inFile.open("../portfel.csv");
            if (!inFile) {
                cout << "Unable to open file";
                exit(1); // terminate with error
            }
            getline(inFile, balance);
            zp = stoi(balance);
            cout << "Twoj stan konta to: " << zp << "$" << "\n";
            cout << "\n";
            inFile.close();
            break;
        case 2 :
            operacje();
            break;
    }
}
