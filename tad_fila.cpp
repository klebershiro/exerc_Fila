#include <sstream>
#include "tad_fila.h"

Fila::~Fila() {}

Fila::Fila() {}

Fila::Fila(int max) {

	this->fila = new int(max);
	this->tamanhoMax = max;
	this->tamanho = 0;
	this->ini = -1;
	this->fim = -1;

}

bool Fila::vazia() {
	return this->tamanho == 0;
}

bool Fila::cheia() {
	return this->tamanho == this->tamanhoMax;
}

/**
 * INSERE UM ELEMENTO NA FILA.
 * Se a fila permitir repeticao, o parametro "repete" deve ir como true,
 *   caso contrario deve ser false (nao pode ter repeticao).
 * Antes de inserir:
 *   - verifica se a fila nao esta' lotada.
 *   - se estiver lotada retorna -1.
 *   - caso nao permita repeticao e o elemento ja' estiver na fila, retorna -2
 * Depois de inserir:
 *   - retorna o tamanho da fila.
 */
int Fila::inserir(int valor, bool repete) {
	if (cheia()) {
		return -1;
	}
	if (!repete) {
		if (posicaoDoIntem(valor) == -1) {
			return -2;
		}
	}

	fim = (fim + 1) % tamanhoMax;
	if (ini == -1) {
		ini = 0;
	}
	this->fila[fim] = valor;
	this->tamanho++;
	int posicao = this->tamanho;
	return this->tamanho;

}

/**
 * EXTRAI O PROXIMO ELEMENTO A SER ATENDIDO (PRIMEIRO DA FILA).
 * Retorna o valor do elemento.
 * Obs: se esvaziar a fila (tamanho=0) retorne "ini" e "fim" para -1.
 */
int Fila::extrair() {
    if (vazia()){
        this->ini = -1;
		this->fim = -1;
		return -1;
    } else {
		int retira = this->fila[ini];
		this->ini++;
		this->tamanho--;
		return retira;
	}
	return 0;
}

/**
 * VERIFICA EM QUAL POSICAO DA FILA SE ENCONTRA DETERMINADO ITEM.
 * Inicia pelo ponteiro "ini" e retorna a posicao da primeira ocorrencia.
 * Caso nao encontre, retorna -1 (nao esta' na fila ou a fila esta' vazia).
 * O primeiro da fila esta' na posicao 1.
 */
int Fila::posicaoDoIntem(int valor) {
	for(int i = ini; i <= this->tamanhoMax; i++){
		if(this->fila[i] == valor){
			return -1;
		}
	}
	if(fim <= ini){
		for(int j = 0; j <= fim; j++){
			if(this->fila[j] == valor){
				return -1;
			}
		} 
	}
	return 0;
}


string Fila::imprimir() {

	stringstream ss;
	ss << "[ ";
	if (!this->vazia()) {
		/**
		 * Percorrer a fila a partir do ponteiro "ini" com limite em "tamanhoMax".
		 * Se "fim" estiver depois de "ini", encerrar me "fim", caso contr�rio
		 * deve-se ter um segundo laco para percorrer do inicio do vetor ate'
		 * o ponteiro "fim" (e' o caso em que "fim" esta' antes de "ini".
		 */
		for (int i = ini; i < this->tamanhoMax; i++) {
			ss << this->fila[i] << " ";
			if (i == fim) {
				break;
			}
		}
		if (fim < ini) {
			for (int i = 0; i <= fim; i++) {
				ss << this->fila[i] << " ";
			}
		}
	}
	ss << "]";

	return ss.str();


}

int Fila::quantidade_fila() {
	int contador = 0;
	if (this->ini == -1 && this->fim ==-1){
		contador = 0;
	} else {
		for(int i = this->ini; i <= this->fim; i++){
			contador += 1;
		}
	}
	
	return contador;
}