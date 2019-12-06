#ifndef TAD_FILA_H
#define TAD_FILA_H

#include <string>

using namespace std;

class Fila {
	
	private:
		int * fila;
		int tamanho;
		int tamanhoMax;
		int ini;
		int fim;
		
		public:
			Fila();
			Fila(int max);
			~Fila();
			bool cheia();
			bool vazia();
			int inserir(int valor, bool repete);
			int extrair();
			string imprimir();
			int posicaoDoIntem(int valor);
			int quantidade_fila();
};

#endif