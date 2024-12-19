#ifndef CONTA_PALAVRAS_HPP
#define CONTA_PALAVRAS_HPP

#include <string>
#include <map>

/**
 * @brief Lê um arquivo e conta as palavras diferentes no texto.
 * 
 * @param filename Nome do arquivo a ser lido.
 * @return std::map<std::string, int> Mapa com palavras e suas contagens.
 */
std::map<std::string, int> ContaPalavras(const std::string& filename);

#endif // CONTA_PALAVRAS_HPP
