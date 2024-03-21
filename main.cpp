#include <bits/stdc++.h>

using namespace std;
class Abonament;
class Standard;
class StandardPlus;
class Client;

class Client{
protected:
    int long long ID{};
    string tip_abonament_dorit{};
    int Minute_Folosite_Total{};
    int SMS_folosite_total{};
    int GB_folosit_total{};
    float suma_platita{};
    vector<Abonament*> AbonamenteClient{};
    int numar_abonamente{};
public:
    Client(){
        suma_platita = 0;
        numar_abonamente = 0;
    }
    int long long getID(){
        return ID;
    }
    void citesteClient(int long long id, string abonament){
        ID = id;
        tip_abonament_dorit = abonament;
        cin >> Minute_Folosite_Total >> SMS_folosite_total >> GB_folosit_total;
    }
    void citesteNoiConsumuri(){
        cin >> Minute_Folosite_Total >> SMS_folosite_total >> GB_folosit_total;
    }
    void adunaPlata(float x){
        suma_platita = suma_platita + x;
    }
    float getPlata(){
        return suma_platita;
    }
    void setPreferinta(string abonament){
        tip_abonament_dorit = abonament;
    }
    string getPreferinta(){
        return tip_abonament_dorit;
    }
    int getMinute(){
        return Minute_Folosite_Total;
    }
    int getSMS(){
        return SMS_folosite_total;
    }
    int getInternet(){
        return GB_folosit_total;
    }
    friend void creeazaAbonament(Client*);
    friend void intocmesteCostulTotal(Client*);
};

class Abonament{
protected:
    float cost{};
    int minute{};
    int SMS{};
    int internet{};
public:
    virtual void aplica_cost_abonament(Client*) = 0;
    virtual void penalizeazaMinute(Client*) = 0;
    virtual void penalizeazaSMS(Client*) = 0;
    virtual void penalizeazaInternet(Client*) = 0;
};
class Standard: public Abonament{
public:
    Standard(){
        cost = 50;
        minute = 100;
        SMS = 100;
        internet = 10;
    }
    void aplica_cost_abonament(Client* client) override{
        client->adunaPlata(cost);
    }
    void penalizeazaMinute(Client* client)override{
        float cost;
        if(client->getMinute() > minute){
            cost = (client->getMinute() - minute) * 0.1;
            client->adunaPlata(cost);
        }
    }
    void penalizeazaSMS(Client* client)override{
        float cost;
        if(client->getSMS() > SMS){
            cost = (client->getSMS() - SMS) * 0.5;
            client->adunaPlata(cost);
        }
    }
    void penalizeazaInternet(Client* client)override{
        float cost;
        if(client->getInternet() > internet){
            cost = (client->getInternet() - internet) * 1;
            client->adunaPlata(cost);
        }
    }
};
class StandardPlus: public Abonament{
public:
    StandardPlus(){
        cost = 75;
        minute = 200;
        SMS = 200;
        internet = 15;
    }
    void aplica_cost_abonament(Client* client)override{
        client->adunaPlata(cost);
    }
    void penalizeazaMinute(Client* client)override{
        float cost;
        if(client->getMinute() > minute){
            cost = (client->getMinute() - minute) * 0.15;
            client->adunaPlata(cost);
        }
    }
    void penalizeazaSMS(Client* client)override{
        float cost;
        if(client->getSMS() > SMS){
            cost = (client->getSMS() - SMS) * 0.75;
            client->adunaPlata(cost);
        }
    }
    void penalizeazaInternet(Client* client)override{
        float cost;
        if(client->getInternet() > internet){
            cost = (client->getInternet() - internet) * 1.5;
            client->adunaPlata(cost);
        }
    }
};
void creeazaAbonament(Client* client){
    if (client->tip_abonament_dorit == "A"){
        client->AbonamenteClient.push_back(new Standard);
        client->numar_abonamente++;
    }
    else if (client->tip_abonament_dorit == "B"){
        client->AbonamenteClient.push_back(new StandardPlus);
        client->numar_abonamente++;
    }
}
void intocmesteCostulTotal(Client* client){
    for (int i = 0; i < client->numar_abonamente; i++){
        client->AbonamenteClient[i]->aplica_cost_abonament(client);
        client->AbonamenteClient[i]->penalizeazaMinute(client);
        client->AbonamenteClient[i]->penalizeazaSMS(client);
        client->AbonamenteClient[i]->penalizeazaInternet(client);
    }
}
int main() {

    vector<Client*> clienti;
    vector <int long long> IDs;
    string tip_abonament;
    int long long max = 0;
    int indice3 = 0;
    int indice = 0;
    int indice2 = 0;
    int size = 0;
    int size_vector_oameni = 0;
    int n;
    int long long id;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> id;
        IDs.push_back(id);
        size++;
        if(indice == 1){
            for (int j = 0; j < size - 1 && indice2 == 0; j++){
                if (id == IDs[j]){
                    cin >> tip_abonament;
                    clienti[j]->setPreferinta(tip_abonament);
                    clienti[j]->citesteNoiConsumuri();
                    creeazaAbonament(clienti[j]);
                    IDs.pop_back();
                    indice2++;
                    size--;
                }
            }
        }
        if (indice == 0){
            indice++;
            cin >> tip_abonament;
            clienti.push_back(new Client);
            clienti[size_vector_oameni]->citesteClient(id, tip_abonament);
            creeazaAbonament(clienti[size_vector_oameni]);
            size_vector_oameni++;
        }
        else if (indice2 == 0){
            cin >> tip_abonament;
            clienti.push_back(new Client);
            clienti[size_vector_oameni]->citesteClient(id, tip_abonament);
            creeazaAbonament(clienti[size_vector_oameni]);
            size_vector_oameni++;
        }
        indice2 = 0;
    }
    for (int i = 0; i < size_vector_oameni; i++){
        intocmesteCostulTotal(clienti[i]);
    }
    max = clienti[0]->getPlata();
    for (int i = 0; i < size_vector_oameni; i++){
        if (clienti[i]->getPlata() >= max){
            max = clienti[i]->getPlata();
            indice3 = i;
        }
    }
    cout << clienti[indice3]->getID();
    return 0;
}