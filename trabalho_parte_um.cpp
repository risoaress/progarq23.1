#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;


vector<string> separaPorDelimitador(string s, char delimitador)
{
	vector<string> stringsSeparadas;
	vector<int> pontosDeSeparacao;

	pontosDeSeparacao.push_back(0);
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == delimitador)
			pontosDeSeparacao.push_back(i + 1);
	}

	for (int j = 0; j < pontosDeSeparacao.size() - 1; j++)
	{
		stringsSeparadas.push_back(s.substr(pontosDeSeparacao[j], pontosDeSeparacao[j + 1] - pontosDeSeparacao[j] - 1));
	}

	stringsSeparadas.push_back(s.substr(pontosDeSeparacao.back(), pontosDeSeparacao.size()));

	return stringsSeparadas;

}

string extrairData(string stringInteira)
{
	string data;

	string dia = stringInteira.substr(0, 2);
	string mes = stringInteira.substr(2, 2);
	string ano = stringInteira.substr(4, 4);

	data = dia + "/" + mes + "/" + ano;

	return data;
}

vector<string> lerArquivoCSV(string nomeArquivo)
{
	vector<string> linhas;
	string arquivoComExtensao = nomeArquivo + ".csv";
	ifstream arquivo(arquivoComExtensao);
	if (!arquivo)
	{
		cerr << "\nErro ao abrir o arquivo " << nomeArquivo << "\n\n";
		return linhas;
	}

	string linha;

  cout << "\nArquivo do dia " << extrairData(nomeArquivo) << " lido com sucesso!\n" << endl;
  
	while (getline(arquivo, linha))
	{
		linhas.push_back(linha);
	}

	arquivo.close();
	return linhas;
}

int main()
{
	bool continua = true;
	set<string> quesitos;

	vector<map<string, int>> criancas;
	vector<string> nomesCriancas;

	while (continua)
	{
		int opcao;
		string data;
		cout << "Digite a opcao desejada: \n\n    1) Ler novo arquivo CSV\n    2) Gerar relatorio por criança\n    3) Gerar Relatorio por quesito\n    4) Encerrar o programa\n\n>";
		cin >> opcao;

		if (opcao == 4)
		{
			continua = false;
		}	// fim do programa

		if (opcao == 1)
		{
			quesitos.clear();
			nomesCriancas.clear();
			criancas.clear();

			vector<string> arquivo;
			string nomeArquivo;
			cout << "\nDigite o nome do arquivo que será aberto: \n>";
			cin >> nomeArquivo;

			data = extrairData(nomeArquivo);

			arquivo = lerArquivoCSV(nomeArquivo);

			for (auto linha: arquivo)
			{
				vector<string> atributosSeparados = separaPorDelimitador(linha, ',');
				int tamanhoVetor = atributosSeparados.size();
				int numeroAtributos = tamanhoVetor / 2;
				map<string, int> novaCrianca;

				nomesCriancas.push_back(atributosSeparados[0]);

				for (int i = 1; i < tamanhoVetor - 2; i += 2)
				{
					if (!atributosSeparados[i + 1].empty())
					{
						novaCrianca[atributosSeparados[i]] = stoi(atributosSeparados[i + 1]);
						quesitos.insert(atributosSeparados[i]);
					}
				}

				criancas.push_back(novaCrianca);
			}

		}

		// Relatorio por quesito:

		if (opcao == 3)
		{
			for (auto quesito: quesitos)
			{
				cout << "Quesito " << quesito << ":\n" << endl;

				for (int i = 0; i < criancas.size(); i++)
				{
					cout << nomesCriancas[i] << ": " << criancas[i][quesito] << endl;
				}

				cout << "\n\n";
			}
		}

		// Relatorio por crianca:
		if (opcao == 2)
		{
			for (int i = 0; i < criancas.size(); i++)
			{
				cout << nomesCriancas[i] << ":" << endl;
				for (auto quesito: criancas[i])
				{
					cout << quesito.first << ": " << quesito.second << endl;
				}

				cout << endl;
			}
		}
	}
}