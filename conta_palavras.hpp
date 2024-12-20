// "Copyright [2024] <Davi Bueno>"

#ifndef CONTA_PALAVRAS_HPP_
#define CONTA_PALAVRAS_HPP_

#include <string>
#include <map>
#include <vector>


/**
 * @brief Lê um arquivo e conta as palavras diferentes no texto.
 * 
 * @param filename Nome do arquivo a ser lido.
 * @return std::map<std::string, int> Mapa com palavras e suas contagens.
 */


std::map<std::string, int>
ContaPalavras(const std::string& filename);

std::vector<std::pair<std::string, int>>
PalavrasOrdenadas(const std::map<std::string, int>& palavras);


#endif // CONTA_PALAVRAS_HPP_
