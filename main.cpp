#include <iostream>
#include <locale.h>
#include <typeinfo>
using namespace std;

class Data{
	private:
		int dia;
		int mes;
		int ano;

	public:
		//construtores:
		
		// objeto 1
		Data(int dia, int mes, int ano){
			//argumentos
			this->dia = dia;
			this->mes = mes;
			this->ano = ano;
		}
		// objeto 2
		Data(){
			//argumentos
			this->dia = 0;
			this->mes = 0;
			this->ano = 0;
		}
		
		// métodos:
		
		//setters - > alterar valores dos atributos
		void setDia(int dia){
			this->dia = dia;
		}
		void setMes(int mes){
			this->mes = mes;
		}
		void setAno(int ano){
			this->ano = ano;
		}
		
		//getters - > retornar valores dos atributos
		int getDia() {
			return this->dia;
		}
		int getMes() {
			return this->mes;
		}
		int getAno() {
			return this->ano;
		}

		
		//conversão
		string getData() {
		    string sDia = to_string(this->dia);
		    string sMes = to_string(this->mes);
		    string sAno = to_string(this->ano);
		    
		    return sDia.insert(0, 2-sDia.size(),'0') + "/" +
		           sMes.insert(0, 2-sMes.size(),'0') + "/" +
			       sAno;
        }
};

class Contato{
	private:
		string email;
		string nome;
		string telefone;
		Data *dtnasc;

	public:
		
		Contato(string email, string nome, string telefone, Data *dtnasc){
			this->email = email;
			this->nome = nome;
			this->telefone = telefone;
			this->dtnasc = dtnasc;
		}
		
		Contato(){
			this->email = "Not defined";
			this->nome = "Not defined";
			this->telefone = "(00)00000-0000";
			this->dtnasc = new Data();
		}
		
		void setEmail(string email){
		    if(email != ""){
		        this->email = email;
		    }
		}
		void setNome(string nome){
			if(nome != ""){
			    this->nome = nome;
			}
		}
		void setTelefone(string telefone){
		    //this->telefone = telefone;
		    if(telefone != ""){
		        this->telefone = telefone.insert(0, 1, '(').insert(3, 1, ')').insert(9, 1, '-');
		    }
		}
		
		void setDtnasc(Data *dtnasc){
			this->dtnasc = dtnasc;
		}
		
		string getEmail(){
			return this->email;
		}
		string getNome(){
			return this->nome;
		}
		string getTelefone(){
			return this->telefone;
		}
		
		Data *getDtnasc(){
			return this->dtnasc;
		}
		
		int getIdade(){
		    return this->dtnasc->getAno();
		}
		
		string getContato() {
		    string sEmail = this->email;
		    string sNome = this->nome;
		    string sTelefone = this->telefone;
		    string sDtnasc = this->dtnasc->getData();
		    string sIdade = to_string(2024 - getIdade());
		    
		    return "Contato" + string("\n") +
		           "Email: " + sEmail + '\n' + 
		           "Nome: " + sNome + '\n' + 
		           "Telefone: " + sTelefone + '\n' + 
		           /*"Data de nascimento: " + sDtnasc + '\n' +*/
		           "Idade: " + sIdade + '\n';
        }
        
		
};

#define qtUser 5

void form(string *formulario){
    
    string email;
	string nome;
	string telefone;
	int dia;
	int mes;
	int ano;
	
	Contato preUser;
	Contato *user;
	
	//string banco[qtUser] = {};
	
	for(int i =0; i < qtUser; ++i){
	    
	    cout << "Email: "; getline(cin, email);
    	cout << "Nome: "; getline(cin, nome);
    	cout << "Telefone: "; getline(cin, telefone);

    	cout << "Data de nascimento (somente numero): " << endl;
    	cout << "Dia: "; 
    	cin >> dia;
    	cout << "Mes: ";
    	cin >> mes;
    	cout << "Ano: ";
    	cin >> ano;
    	cin.ignore();
    	cout << endl;
    	
	    // usando os métodos setters como filtragem, antes de usar encapsulamento...
    	preUser.setEmail(email);
    	preUser.setNome(nome);
    	preUser.setTelefone(telefone);
    	preUser.setDtnasc(new Data(dia, mes, ano)); // o encapsulamento foi usado somente no valor da data de nascimento, usando o construtor da classe "Data"
    	
    	user = new Contato(preUser.getEmail(), preUser.getNome(), preUser.getTelefone(), preUser.getDtnasc());
    	
	    //banco[i] = user->getContato();
	    formulario[i] = user->getContato();
	}
}


int main(int argc, char** argv)
{

	string *banco;
	
	banco = new string[qtUser];
	
	form(banco);
	
	// exibindo os 5 usuarios
	for(int i=0; qtUser; ++i){
	    cout << banco[i] << endl;
	}

    delete[] banco;
	return 0;
}

