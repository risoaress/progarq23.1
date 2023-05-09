#include <iostream>
#include <algorithm>
#include <fstream>
#include <cctype>
#include <vector>


using namespace std;

bool criterio_ordenacao(pair<char, int> a, pair<char, int> b){
    
    return a.second < b.second;
    
}

int main(){
    
    bool continua = true;
    
    while(continua){
        
        string arquivo;
        vector<pair<char, int>> ocorrencias;
        cout << "Digite '0' para parar o programa\nDigite o nome do arquivo a ser lido: " << endl;
        cin >> arquivo;
        
        if(arquivo != "0"){
            
            ifstream ifs;
            string arquivoComExtensao = arquivo + ".txt";
            
            ifs.open(arquivoComExtensao, ifstream::in); 
            char caractere = ifs.get(); // pega o caractere inicial do arquivo
            
            
            while(ifs.good()){ 
                
                auto resultadoBusca = find_if(ocorrencias.begin(), ocorrencias.end(),
                    [caractere](const pair<char, int>& ocorrencia) {return ocorrencia.first == caractere;});
                
                if(resultadoBusca != ocorrencias.end()){ 
                    resultadoBusca->second++;
                    
                }else{
                    
                    if(isalpha(caractere) || isdigit(caractere)){
                        pair<char, int> novoPar = make_pair(caractere, 1);
                        ocorrencias.push_back(novoPar);
                    }
                    
                }
                
                caractere = ifs.get();
                
            }
            
            ifs.close();
  
            sort(ocorrencias.begin(), ocorrencias.end(), criterio_ordenacao);
            
            for(auto ocorrencia: ocorrencias){
                cout << ocorrencia.first << " : " << ocorrencia.second << endl; 
            }
            cout << endl << endl;    
        }else{
            continua = false;
       }
    }
    return 0;
}
