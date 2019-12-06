#include <iostream>

#include "tad_fila.h"

using namespace std;

int main() {

	cout << "\n----------------------------------------------";
	cout << "\n PROGRAMA PARA APRENDIZADO DO TAD FILA (VETOR)";
	cout << "\n----------------------------------------------";

	int tamVet;
	cout << "\n\nInforme o tamanho do vetor para uso da fila: ";
	cin >> tamVet;

	Fila fila(tamVet);

	while(true) {

		cout << "\n\n\n";
		cout << "\n----------------------------------------------";
		cout << "\n PROGRAMA PARA APRENDIZADO DO TAD FILA (VETOR)";
		cout << "\n----------------------------------------------";

		cout << "\n0 - sair ";
		cout << "\n1 - entrar na fila ";
		cout << "\n2 - sair da fila ";
		cout << "\n3 - imprimir a fila ";
		cout << "\n4 - verifica se o item esta' na fila" ;
		cout << "\n5 - tamanho da fila ";

		int opc = 0;
		cout << "\n\nForneca sua opcao: ";
		cin >> opc;

		if (opc == 0) {
			break;
		} else if (opc == 1) {
			int opc1 = -1;
			cout << "\nInforme o valor do novo elemento: ";
			cin >> opc1;
			int x = fila.inserir(opc1, false);
			if (x == -1) {
				cout << "\nERRO: A fila esta' lotada.";
			} else if (x == -2) {
				cout << "\nERRO: Este elemento ja' esta' na fila.";
			} else {
				cout << "\n Incluido com sucesso na posicao " << x;
			}
		} else if (opc == 3) {
			cout << fila.imprimir();
		} else if (opc == 2) {
			int x = fila.extrair();
			if (x == -1) {
				cout << "\nERRO: A fila esta' vazia.";
			} else {
				cout << "\n Retirado o elemento " << x << " da fila \n\n";
			}
		} else if (opc == 4) {
			cout << "\nDigite o valor para consultar se esta na fila ";
			int opc4;
			cin >> opc4;
			int x = fila.posicaoDoIntem(opc4);
			if (x == -1) {
				cout << "\nO valor JA ESTA na fila.\n\n";
			} else {
				cout << "\nO valor nao se encontra na fila\n\n";
			}
		} else if (opc == 5) {
			cout << "\nHa " << fila.quantidade_fila() << " elemento(s) na fila.\n\n";	
		}

	}



	cout << "\n\n--- Obrigado e ate' a proxima ---\n\n";
	return 0;
}
