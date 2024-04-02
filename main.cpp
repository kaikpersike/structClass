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

int main(int argc, char** argv)
{
	
	Data *hoje;
	hoje = new Data(28, 3, 2024);
	cout << hoje->getData() << endl;

	return 0;
}
