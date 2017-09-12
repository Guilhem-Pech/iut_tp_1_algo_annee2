#include <iostream>

using namespace std;

// EXERCICE 1
namespace {

void NewDelete_a(){
    string* pStr = new string();
    getline(cin, *pStr);

    cout<< *pStr << endl ;
    delete pStr;
}

void NewDelete_b(){
    const string* pConstStr = new string("une chaîne quelconque");
    cout << *pConstStr << endl;
    //*pConstStr = "J'aime édouard";     // Impossible !
    pConstStr = new string ("I love myself");
    cout << *pConstStr << endl;
    delete pConstStr;
}

void NewDelete_c(){
    string* const pConstStr = new string("une chaîne quelconque");
    cout << *pConstStr << endl;
    *pConstStr = "J'aime édouard";
    //pConstStr = new string ("I love myself"); // Impossible !
    cout << *pConstStr << endl;
    delete pConstStr;
}

void NewDelete_d(){
    cout << "Rentrer taille tableau: ";
    unsigned tabSize;
    cin >> tabSize;
    cout << endl;

    unsigned* tab = new unsigned[tabSize];
    for (unsigned* ptr=tab; ptr<tab+tabSize ; ++ptr){
        *ptr = ptr-tab;
        cout << *ptr << " ";
    }
    delete tab;
}

void NewDelete_e(){
    cout << "Rentrer taille tableau: ";
    unsigned tabSize;
    cin >> tabSize;
    cout << endl;

    unsigned* tab = new unsigned[tabSize];
    for (unsigned* ptr=tab; ptr<tab+tabSize ; ++ptr){
        *ptr = ptr-tab;
        cout << *ptr << " ";
    }

    unsigned* First = tab;
    unsigned* Last = tab + tabSize - 1;
    *First = 69;
    *Last = 70;
    cout << endl << endl;
    for (unsigned* ptr=tab; ptr<tab+tabSize ; ++ptr){
        cout << *ptr << " ";
    }
    delete tab;
}

void NewDelete_f(){
    int UnInt = 0;
    int* RefUnInt = &UnInt;
    int** pUnInt = &RefUnInt;

    UnInt = 6;
    *RefUnInt = 7;
    **pUnInt = 8;

    cout << UnInt << " " << *RefUnInt << " " << **pUnInt << endl;

}


// EXERCICE 2

void TabPtrs(){
    string *ptrStr[10];
    for (unsigned i = 0; i < 10;++i){
        ptrStr[i] = new string();
        cout << "ptrStr[" << i << "] = ";
        getline(cin,*ptrStr[i]);
        cout << endl;
    }
    for (unsigned i = 0; i < 10;++i){
        cout << *ptrStr[i] << endl;
        delete ptrStr[i];
    }
}

}


int main(){
    TabPtrs();
    return 0;
}

