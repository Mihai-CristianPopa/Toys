#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Jucarie{
protected:
    string denumire;
    double dimensiune;
    string tip;
public:
    Jucarie():dimensiune(0) {}

    Jucarie(const string &denumire, double dimensiune, const string &tip) : denumire(denumire), dimensiune(dimensiune),
                                                                            tip(tip) {}

    virtual ~Jucarie()=0;

    virtual istream& citire(istream& is){
        cout << "denumire: "; is >> denumire;
        cout << "dimensiune: "; is >>dimensiune;
        cout << "tip: "; is >> tip;
        return is;
    }

    virtual ostream& afisare(ostream& os) const{
        os << "denumire: "; os << denumire << " , ";
        os << "dimensiune: "; os << dimensiune<< " , ";
        os << "tip: "; os <<  tip<< " , ";
        return os;
    }

    friend ostream &operator<<(ostream &os, const Jucarie &jucarie) {
        jucarie.afisare(os);
        return os;
    }
    friend istream &operator>>(istream &is,  Jucarie &jucarie) {
        jucarie.citire(is);
        return is;
    }
};
    Jucarie :: ~Jucarie(){}


class JucarieClasica : public Jucarie{
private:
    string material;
    string culoare;
public:
    JucarieClasica() {}

    JucarieClasica(const string &denumire, double dimensiune, const string &tip, const string &material,
                   const string &culoare) : Jucarie(denumire, dimensiune, tip), material(material), culoare(culoare) {}


    istream &citire(istream &is) override {
        Jucarie::citire(is);
        cout << "material: "; is >> material;
        cout << "culoare: "; is >> culoare;
        return is;
    }

    ostream &afisare(ostream &os) const override {
        Jucarie::afisare(os);
        cout << "material: "; os << material << " , ";
        cout << "culoare: "; os << culoare << " ";
        return os;
    }

};

class JucarieEducativa : virtual public Jucarie{
protected:
    string abilitateaDezvoltata;
public:
    JucarieEducativa() {}

    JucarieEducativa(const string &abilitateaDezvoltata) : abilitateaDezvoltata(abilitateaDezvoltata) {}

    istream &citire(istream &is) override {
        Jucarie::citire(is);
        cout << "abilitateaDezvoltata: "; is >> abilitateaDezvoltata;
        return is;
    }

    ostream &afisare(ostream &os) const override {
        Jucarie::afisare(os);
        os << "abilitateaDezvoltata: " << abilitateaDezvoltata << " ";
        return os;
    }
};

class JucarieElectronica: virtual public Jucarie{
protected:
    int nrBaterii;
public:
    JucarieElectronica() {}

    JucarieElectronica(const string &denumire, double dimensiune, const string &tip, int nrBaterii) : Jucarie(denumire,
                                                                                                              dimensiune,
                                                                                                              tip),
                                                                                                      nrBaterii(
                                                                                                              nrBaterii) {}

    istream &citire(istream &is) override {
        Jucarie::citire(is);
        cout << "nrBaterii: "; is >> nrBaterii;
        return is;
    }

    ostream &afisare(ostream &os) const override {
        Jucarie::afisare(os);
        cout << "nrBaterii: " << nrBaterii << " ";

        return os;
    }

};


class JucarieModerna : public JucarieEducativa, public JucarieElectronica {
private:
    string brand;
    string model;
public:
    JucarieModerna() {
        this->nrBaterii = 1;
        this->abilitateaDezvoltata = "generala";
    }

    JucarieModerna(const string &denumire, double dimensiune, const string &tip, const string &brand,
                   const string &model, int nrBaterii = 1, const string &abilitateaDezvoltata = "generala")
            : JucarieEducativa(abilitateaDezvoltata),
              JucarieElectronica(denumire, dimensiune,
                                 tip, nrBaterii),
              brand(brand), model(model) {}

    istream &citire(istream &is) override {
        Jucarie::citire(is);
        cout << "brand: ";
        is >> brand;
        cout << "model: ";
        is >> model;
        return is;
    }

    ostream &afisare(ostream &os) const {
        Jucarie::afisare(os);
        os << "abilitate dezvoltata: " << abilitateaDezvoltata << " , " << "nrBaterii: " << nrBaterii << " , "
           << "brand: " << brand << " , " << "model: " << model;
        return os;
    }

};
Jucarie *allocate(Jucarie *d) {
    auto *asJucarieClasica = dynamic_cast<JucarieClasica *>(d);
    auto *asJucarieEducativa = dynamic_cast <JucarieEducativa * > (d);
    auto *asJucarieElectronica = dynamic_cast<JucarieElectronica *>(d);
    auto *asJucarieModerna = dynamic_cast <JucarieModerna * > (d);
    if (asJucarieClasica) {
        return new JucarieClasica(*asJucarieClasica);
    } else if (asJucarieEducativa) {
        return new JucarieEducativa(*asJucarieEducativa);
    } else if (asJucarieElectronica) {
        return new JucarieElectronica(*asJucarieElectronica);
    } else if (asJucarieModerna) {
        return new JucarieModerna(*asJucarieModerna);
    }
    return nullptr;
}

Jucarie *createJucarie() {
    int optiune;
    cout << "0 = JucarieClasica, 1 = JucarieEducativa, 2= JucarieElectronica, 3= JucarieModerna";
    cin >> optiune;

    Jucarie *p = nullptr;
    if (optiune == 0) {
        p = new JucarieClasica;
    } else if (optiune == 1) {
        p = new JucarieEducativa;
    }else if (optiune == 2) {
        p = new JucarieElectronica;
    }else if (optiune == 3) {
        p = new JucarieModerna;
    }

    if (p) {
        cin >> *p;
    }
    return p; // 0
}





class Contor{
    static int lastId;
    const int ID;
public:
    Contor() : ID(lastId++) {}

    const int getId() const;
};
int Contor::lastId=0;

const int Contor::getId() const {
    return ID;
}
class Copil{
protected:
    Contor c;
    string nume;
    string prenume;
    string adresa;
    int varsta;
    int cntFapteBune;
    vector<Jucarie*>jucarii;
public:
    Copil()  {}

    Copil(int cntFapteBune) : cntFapteBune(cntFapteBune) {}

    Copil(const vector<Jucarie *> &_jucarii)   {
        for (auto*jucarie:_jucarii){
            jucarii.push_back(allocate(jucarie));
        }
    }

    int getID() const {
        return c.getId();
    }
    virtual istream& citire(istream &is){

        cout <<"Numele: "; is >> nume;
        cout <<"Prenumele: "; is >> prenume;
        cout <<"Adresa: "; is >> adresa;
        cout <<"Varsta: "; is >> varsta;
        cout << "Numarul de fapte bune: ";
        is >> cntFapteBune;
        for (int i = 0; i < cntFapteBune; i++){
            jucarii.push_back(createJucarie());
        }

        return is;
    }

    virtual ~Copil()=0;

    virtual ostream& afisare(ostream &os) const{
        cout <<"ID: " << getID() << " , " << "NrFapteBune: " << cntFapteBune << " ";
        return os;
    }

    friend ostream &operator<<(ostream &os, const Copil &copil) {
        copil.afisare(os);
        return os;
    }
    friend istream &operator>>(istream &is, Copil &copil) {
        copil.citire(is);
        return is;
    }

    const string &getNume() const {
        return nume;
    }

    int getVarsta() const {
        return varsta;
    }

    int getCntFapteBune() const {
        return cntFapteBune;
    }

    void adaugaFapteBune(int x){
        cntFapteBune=cntFapteBune+x;
    }

    void adaugaJucarii(int x){
        for (int i=0; i<x; i++){
            jucarii.push_back(createJucarie());
        }
    }
    void afisareJucarii(){
        int i=0;
        for (auto* jucarie: jucarii){
            cout << "Jucaria " << ++i << ": " << *jucarie;
        }
    }
};


Copil :: ~Copil() {}



class CopilCuminte : public Copil{
    int nrDulciuri;
public:
    CopilCuminte() : nrDulciuri(0) {}

    CopilCuminte(int cntFapteBune) : Copil(cntFapteBune) {
//        if(cntFapteBune < 10){
//            throw 1;
//        }
    }

    istream &citire(istream &is) override {
         Copil::citire(is);
//             if (cntFapteBune < 10) throw 1;
             cout << "nrDulciuri: " ; is >> nrDulciuri;
             return is;

    }

    ostream &afisare(ostream &os) const override {
        Copil::afisare(os);
        os << "nrDulciuri: " << nrDulciuri;
        return os;
    }
};

class CopilNeastamparat : public Copil{
    int nrCarbuni;
public:
    CopilNeastamparat() : nrCarbuni(0) {}

    CopilNeastamparat(int cntFapteBune, int nrCarbuni) : Copil(cntFapteBune), nrCarbuni(nrCarbuni) {}

    istream &citire(istream &is) override {
         Copil::citire(is);
         cout << "nrCarbuni: "; is >> nrCarbuni;
         return is;
    }

    ostream &afisare(ostream &os) const override {
       Copil::afisare(os);
       os << "nrCarbuni: " << nrCarbuni;
       return os;
    }
};

Copil *allocate(Copil *d) {
    auto asCopilCuminte = dynamic_cast<CopilCuminte *>(d);
    auto *asCopilNeastamparat = dynamic_cast <CopilNeastamparat * > (d);
    if (asCopilNeastamparat) {
        return new CopilNeastamparat(*asCopilNeastamparat);
    } else if (asCopilCuminte) {
        return new CopilCuminte(*asCopilCuminte);
    }
    return nullptr;
}

Copil *createCopil() {
    int optiune;
    cout << "0 = CopilCuminte, 1 = CopilNeascultator";
    cin >> optiune;

    Copil *p = nullptr;
    if (optiune == 0) {
        p = new CopilCuminte;
    } else if (optiune == 1) {
        p = new CopilNeastamparat;
    }

    if (p) {
        cin >> *p;
    }
    return p; // 0
}
bool suntOrdonate(int a,  int b){
return a > b;
}

class Menu{
private:
    Menu() {}

    Menu(const vector<Copil *> &_copii)   {
        for (auto*copil : _copii){
            copii.push_back(allocate(copil));
        }
    }

protected:
    vector<Copil*>copii;

public:
    static Menu* app;
    static Menu* getInstance(){
        if (app==0){
            app = new Menu();
            return app;
        }else return app;
    }


public:


 ///Cerinta 1;
    ////memorarea a n copii?

    void citesteNcopii(){
        int n;
        cout << "Numarul de copii: ";
        cin >> n;
        for (int i=0 ; i < n ; i++){
            copii.push_back(createCopil());
        }
    }
    void afiseazaNcopii(){
        for (auto* copil : copii){
            cout << "Copilul" << copil->getID() << ": " << copil <<"\n" ;
        }
    }
///Cerinta2
    void afisJucarii(){///trebuie cumva sa se retina jucariile pt fiecare copil in parte, sau macar sa le afisez de asa maniera
     for (auto* copil : copii){
         int m;
        cout << "Numarul de jucarii: ";
        cin >> m;
        copil->adaugaJucarii(m);
        copil->afisareJucarii();
     }
 }
 ///Cerinta 3
    void dupaNume(){
     string nume;
     cout << "Cauta nume: ";
     cin >> nume;
     for (auto* copil:copii){
         if(copil->getNume().find(nume)){
            cout << copil << endl;
     }
 }
 }
 ///Cerinta4


    void ordonareVarsta(){
     int i=0;
     int v[100];
     for (auto* copil : copii){

          v[i] = copil->getVarsta();
         i++;
     }
     sort(v, v+i-1, suntOrdonate);
     for (int j = 0; j<i; j++)
     {
         cout << v[j] << " , ";
     }
     cout << endl;
 }

 ///Cerinta5
 void ordonareFapteBune(){
     int i=0;
     int v[100];
     for (auto* copil : copii){

         v[i] = copil->getCntFapteBune();
         i++;
     }
     sort(v, v+i-1, suntOrdonate);
     for (int j = 0; j<i; j++)
     {
         cout << v[j] << " , ";
     }
     cout << endl;
 }

 ///Cerinta6
 void adaugareFapteBune(){
     int x;
     cout << "Cate fapte bune sa adauge: ";
     cin >> x;
     for(auto*copil : copii){
         if(copil->getID()==0){
             copil->adaugaFapteBune(x);
             copil ->adaugaJucarii(x);
         }
     }
 }


    void showmenu(){
        cout << "1. Citeste si afiseaza n copii" << endl;
        cout << "2. Citeste si afiseaza m jucarii pentru fiecare copil" << endl;
        cout << "3. Gasire dupa nume" << endl;
        cout << "4. Ordonare dupa varsta" << endl;
        cout << "5. Ordonare dupa fapte bune" << endl;
        cout << "6. Cerinta 6" << endl;
//        cout << "1. Citeste si afiseaza n copii" << endl;
//        cout << "1. Citeste si afiseaza n copii" << endl;
    }

    void run(){
        int optiune;

        while(true){
            showmenu();
            cout << "Optiune: ";
            cin >> optiune;


            if(optiune == 1){
                citesteNcopii();
                afiseazaNcopii();
            } else if(optiune == 2){
                afisJucarii();
            } else if (optiune == 3){
                dupaNume();
            } else if (optiune == 4){
                ordonareVarsta();
            } else if (optiune ==5 ){
                ordonareFapteBune();
            } else if (optiune == 6){
                adaugareFapteBune();
            } else{break;}
        }


    }
};

///Menu* app = nullptr;
/// Mi-a luat ceva, dar in sfarsit mi-am dat seama care era problema cu codul asta
/// si cu cel de la colocviu instructiunea prin care instantiam variabila statica app era gresita
/// CORECT :
Menu* Menu::app=nullptr;

int main() {

        Menu* app = Menu::getInstance();
        app -> run();
        delete app;

        return 0;
}
