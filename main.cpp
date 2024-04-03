#include <iostream>
#include <locale.h>
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
		//Data *dtnasc;

	public:
		
		Contato(string email, string nome, string telefone/*, Data *dtnasc*/){
			this->email = email;
			this->nome = nome;
			this->telefone = telefone;
			//this->dtnsac = dtnasc;
		}
		
		Contato(){
			this->email = '.';
			this->nome = '.';
			this->telefone = '.';
			//this->dtnsac = '.';
		}
		
		void setEmail(string email){
			this->email = email;
		}
		void setNome(string nome){
			this->nome = nome;
		}
		void setTelefone(string telefone){
			this->telefone = telefone;
		}
		/*
		void setDtnasc(string Data *dtnasc){
			this->dtnasc = dtnasc;
		}
		*/
		
		string getEmail(){
			return this->email;
		}
		string getNome(){
			return this->nome;
		}
		string getTelefone(){
			return this->telefone;
		}
		/*
		Data *getDtnasc(){
			return this->dtnasc;
		}
		*/
		
		string getContato() {
		    string sEmail = this->email;
		    string sNome = this->nome;
		    string sTelefone = this->telefone;
		    // string sDtnasc = to_string(this->dtnasc);
		    
		    return "Email: " + sEmail + '\n' + "Nome: " + sNome + '\n' + "Telefone: " + sTelefone;
        }
		
};

int main(int argc, char** argv)
{
	/*
	Data *hoje;
	hoje = new Data(28, 3, 2024);
	cout << hoje->getData() << endl;
	*/
	
	Contato *user;
	user = new Contato("kaik@gmail.com", "Kaik P. M.", "(11)11111-1111");
	cout << user->getContato();

	return 0;
}
