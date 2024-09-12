#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;
NO* ultimo = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* buscarElementoFunc(int busca);
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;
		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{
	// se a lista já possuir elementos
// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;


	if (primeiro == NULL)
	{
		primeiro = novo;
		ultimo = novo;
	}

	else {
		// Impedi números duplicados inserindo a função posicaoElemento.

		NO* aux = buscarElementoFunc(novo->valor);
		if (aux != NULL) {
			cout << "Elemento existente, digite outro numero. \n";
			free(novo);
			return;
		}

		if (novo->valor < primeiro->valor)
		{
			NO* aux = novo;
			aux->prox = primeiro;
			primeiro = novo;
		}
		else
		{
			NO* aux = primeiro;
			while ((aux->prox != NULL) && (aux->prox->valor < novo->valor)) {
				aux = aux->prox;
			}

			if (aux->prox == NULL) {
				aux->prox = novo;
			}
			else {
				ultimo = aux->prox;
				aux->prox = novo;
				novo->prox = ultimo;
			}
		}

	}
}

void excluirElemento()
{
	if (primeiro == NULL) {
		cout << "A lista esta vazia. Insira elementos primeiro. \n";
		return;
	}

	int elementoParaExcluir;
	cout << "Digite o valor do elemento a ser excluido: \n";
	cin >> elementoParaExcluir;

	NO* aux = buscarElementoFunc(elementoParaExcluir);
	if (aux == NULL) {
		cout << "Elemento inexistente. \n";
		return;
	}
	else if (primeiro->valor == elementoParaExcluir) {
		aux = primeiro;
		primeiro = primeiro->prox;
		free(aux);
		cout << "Elemento excluido. \n";
	}
	else {

		aux = primeiro;
		NO* anterior = NULL;
		while (aux != NULL && aux->valor != elementoParaExcluir) {
			anterior = aux;
			aux = aux->prox;
		}

		anterior->prox = aux->prox;
		free(aux);
		cout << "Elemento excluido. \n";
	}

}


void buscarElemento()
{
	int elementoParaBusca;

	cout << "Digite o elemento a ser buscado: \n";
	cin >> elementoParaBusca;

	NO* aux = buscarElementoFunc(elementoParaBusca);
	if (aux == NULL) {
		cout << "Elemento não encontrado. \n";
	}
	else {
		cout << "Elemento encontrado. \n";
	}

}

NO* buscarElementoFunc(int buscar) {
	NO* aux = primeiro;
	while ((aux != NULL) && (aux->valor <= buscar)) {
		if (aux->valor == buscar) {
			return aux;
		}

		aux = aux->prox;
	}
	return NULL;
}

