#include <iostream>
#include <fstream>
#include <cstdlib>
#include <fstream>
#include <vector>
using namespace std;

bool is_number(std::string);
void operacje();
void kursy_walut();
void portfel();
void kalkulator();

int main() {
    while(true) {
        cout << "Witaj, co chcesz zrobic?" << "\n";
        cout << "1. Sprawdz kursy kruptowalut" << "\n";
        cout << "2. Zamienic walute na inna" << "\n";
        cout << "3. Wykonac operacje na koncie" << "\n";
        cout << "4. Wyjsc" << "\n";
        std::string m;
        cin >> m ;
        if(!is_number(m)) {
            cout << "\nNieprawidlowy wybor\n\n";
            continue;
        }
        switch (std::stoi(m)) {
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

bool is_number(std::string s) {
    for(auto const &el : s) {
        if(!std::isdigit(el))
            return false;
    }
    return true;
}

void kalkulator () {
    int u1,u2;
    float k1,k2,s;
    string sk1,sk2,nk1,nk2;
    cout << "Wybierz walute do porownania z inna:" << "\n";
    cout << "0. BTC\n" << "1. ETH\n" << "2. USDT\n" << "3. BNB\n" << "4. USDC\n" << "5. ADA\n" << "6. XRP\n";
    cout << "7. SOL\n" << "8. LUNA\n" << "9. DOT\n" << "10. DOGE\n" << "11. AVAX\n" << "12. BUSD\n"<<"13. SHIB\n" <<"14. UST\n"  ;

    std::fstream kalkulator("../kalkulator.csv", std::ios::in);
    std::string lk; // linia kalkulator
    std::vector<std::string> contentk;
    while(std::getline(kalkulator, lk)) {
        contentk.push_back(lk);
    }
    cin >> u1 >> u2;
    if(u1>14 || u1 <0){
        cout << "Zla wartosc" << "\n";
        return;
    }
    if(u2>14 || u2 <0 || u1 == u2){
        cout << "Zla wartosc" << "\n";
        return;
    }
    kalkulator.close();\

    // linijkę 10 wywołujemy pisząc 9
    sk1 = contentk[u1];
    sk2 = contentk[u2];
    k1= std::stof(sk1);
    k2= std::stof(sk2);
    cout << k1 << "\n" << k2 << "\n";

    std::fstream nazwy("../nazwy.csv", std::ios::in);
    std::string nk; // linia kalkulator
    std::vector<std::string> contentn;
    while(std::getline(nazwy, nk)) {
        contentn.push_back(nk);
    }
    nazwy.close();\
     nk1 = contentn[u1];
    nk2 = contentn[u2];
    cout << nk1 << "\n" << nk2 << "\n";
    s = k1/k2;
    cout << "Za 1 " << nk1 << " mozna miec " << s << " " <<nk2 << "\n";
    return;
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
    zo = std::stoi(bo);
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
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    while ( getline (inFile,dane) ) {
        std::cout << dane << '\n';
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
            zp = std::stoi(balance);
            cout << "Twoj stan konta to: " << zp << "$" << "\n";
            cout << "\n";
            inFile.close();
            break;
        case 2 :
            operacje();
            break;
    }
}