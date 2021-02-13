/*scrivere un programma che inserisce in una tabella i dati degli iscritti,
 i dati sono composti da un cognome, data dell'acconto,acconto e
data saldo. Il programma esegua le seguenti funzionalità:
1)l'inserimento degli iscritti
2)l'inserimento del saldo per gli iscritti che non ce l'hanno
3)stampi tutti gli iscritti che non hanno un saldo
4)cancelli un iscritto*/
#include <iostream>
#include <string>
using namespace std;
const int mi = 100; //massimo iscritti che si possono inserire
int ni = 0;         //contatore numero iscritti
bool contatore = 0;
bool riprova = 0;
struct iscritti
{
    string cognome;
    string data_acconto;
    float acconto;
    string data_saldo;
};
struct iscritti a[mi];
void inserire()
{ //Inserimento iscritti
    int n;
    cout << "\t\t"
         << "----Inserimento iscritto numero " << ni + 1 << "----" << endl;
    cout << "Inserisci cognome dell'iscritto :";
    cin >> a[ni].cognome;
    cout << "Inserisci 1 se vuoi inserire l'acconto o 0 per andare avanti:";
    cin >> contatore;
    if (contatore == 1)
    {
        do
        {
            cout << "Inserire acconto pagato(l'acconto dev'essere inferiore ai 200€):";
            cin >> a[ni].acconto;
        } while (a[ni].acconto > 200);
        cout << "inserire data dell'acconto(es. 12/03/20-->120320):";
        cin >> a[ni].data_acconto;
    }
    else
    {
        if (contatore == 0)
        {
            a[ni].acconto = 0;
            a[ni].data_acconto = " ";
        }
    }
    a[ni].data_saldo = " ";
    ni++;
    contatore = 0;
}
void saldo()
{ //Inserimento saldo
    string s;
    cout << "\t\t"
         << "----INSERIMENTO SALDO----" << endl;
    do
    {
        riprova = 0;
        cout << "Inserisci cognome dell'iscritto che vuole inserire il proprio saldo:";
        cin >> s;
        for (int i = 0; i < ni; i++)
        {
            if (s == a[i].cognome)
            {
                if (a[i].data_saldo != " ")
                {
                    cout << "La persona da lei inserita ha gia' inserito il proprio saldo" << endl;
                    contatore = 1;
                }
                else
                {
                    cout << "L'utente e' stato trovato ed ha un acconto di " << a[i].acconto << " in data " << a[i].data_acconto << endl;
                    cout << "inserire la data del saldo(es. 12/03/20-->120320):";
                    cin >> a[i].data_saldo;
                    contatore = 1;
                }
            }
        }
        if (contatore == 0)
        {
            cout << "La persona da lei cercata non e' stata trovata in caso voglia "
                    "riprovare inserisca 1 o inserisca 0 in caso non voglia riprovare"
                 << endl;
            cin >> riprova;
            contatore = 0;
        }
    } while (riprova != 0);
}
void senza_saldo()
{ //Stampa iscritti senza saldo
    cout << "\t\t"
         << "----LISTA ISCRITTI SENZA SALDO:----" << endl;
    for (int j = 0; j < ni; j++)
    {
        if (a[j].data_saldo == " ")
        {
            cout << a[j].cognome << " ha un acconto di " << a[j].acconto
                 << " e non ha ancora pagato il saldo" << endl;
        }
    }
}
void inserire_acconto()
{ //Inserimento acconto
    string t;
    cout << "\t\t"
         << "----INSERIMENTO ACCONTO----" << endl;
    do
    {
        riprova = 0;
        cout << "Inserisci cognome dell'iscritto che vuole inserire il proprio acconto:";
        cin >> t;
        for (int i = 0; i < ni; i++)
        {
            if (t == a[i].cognome)
            {
                if (a[i].acconto == 0)
                {
                    cout << "!L'utente e' stato trovato! " << endl;
                    do
                    {
                        cout << "Inserire acconto pagato(l'acconto dev'essere inferiore ai 200€):";
                        cin >> a[i].acconto;
                    } while (a[i].acconto > 200);
                    cout << "Inserire data dell'acconto(es. 12/03/20-->120320):";
                    cin >> a[i].data_acconto;
                    contatore = 1;
                }
                else
                {
                    cout << "!L'iscritto cercato ha gia' un acconto!" << endl;
                    contatore = 1;
                }
            }
        }
        if (contatore == 0)
        {
            cout << "la persona da lei cercata non e' stata trovata in caso voglia "
                    "riprovare inserisca 1 o inserisca 0 in caso non voglia riprovare:";
            cin >> riprova;
            contatore = 0;
        }
    } while (riprova != 0);
}
void cancellare()
{ //Cerca e cancella un iscritto
    string cc;
    cout << "\t\t"
         << "----CANCELLA ISCRITTO----" << endl;
    cout << "Inserire cognome dell'iscritto che si vuole cancellare:";
    cin >> cc;
    for (int i = 0; i < ni; i++)
    {
        if (cc == a[i].cognome)
        {
            for (int j = i; j <= ni; j++)
            {
                a[j].cognome = a[j + 1].cognome;
                a[j].acconto = a[j + 1].acconto;
                a[j].data_acconto = a[j + 1].data_acconto;
                a[j].data_saldo = a[j + 1].data_saldo;
                contatore = 1;
            }
            a[ni].cognome = " ";
            a[ni].acconto = 0;
            a[ni].data_acconto = " ";
            a[ni].data_saldo = " ";
            ni--;
            break;
        }
    }
    if (contatore != 0)
    {
        cout << "!L'iscritto e' stato cancellato con successo!" << endl;
    }
    else
    {
        cout << "!L'iscritto inserito non e' stato trovato!" << endl;
    }
    contatore = 0;
}
int main()
{
    int cont = 0;
    do
    {
        cout << "\t\t"
             << "----MENU SCELTA----" << endl;
        cout << "Inserire 1 se vuole inserire l'iscritto,"
             << "\n"
                "Inserire 2 se vuole inserire l'acconto,"
             << "\n"
                "Inserire 3 se vuole inserire il saldo,"
             << "\n"
                "Inserire 4 se vuole stampare gli iscritti che non hanno ancora pagato il saldo,"
             << "\n"
                "Inserire 5 se vuole cancellare un'iscritto,"
             << "\n"
                "Inserire 0 se si vuole uscire."
             << "\n"
                "Scelta:";
        cin >> cont;
        switch (cont)
        {
        case 0:
        {
            cout << "!Hai deciso di uscire dal programma!" << endl;
        }
        break;
        case 1:
        {
            inserire();
            cout << "----------------------------------------------------------------" << endl;
        }
        break;
        case 2:
        {
            inserire_acconto();
            cout << "----------------------------------------------------------------" << endl;
        }
        break;
        case 3:
        {
            saldo();
            cout << "----------------------------------------------------------------" << endl;
        }
        break;
        case 4:
        {
            senza_saldo();
            cout << "----------------------------------------------------------------" << endl;
        }
        break;
        case 5:
        {
            cancellare();
            cout << "----------------------------------------------------------------" << endl;
        }
        break;
        default:
            cout << "Scelta errata" << endl;
            break;
        }
    } while (cont != 0);
    return 0;
}