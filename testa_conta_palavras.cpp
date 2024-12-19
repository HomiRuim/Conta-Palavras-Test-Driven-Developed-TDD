#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "conta_palavras.hpp"


// Teste básico: Verifica se o arquivo é lido corretamente
TEST_CASE("Leitura de palavras do arquivo", "[ContaPalavras]") {
    // Criação de um arquivo de teste
    std::ofstream teste("teste.txt");
    teste << "este é um teste\neste é outro teste";
    teste.close();

    // Chamada da função ContaPalavras
    auto resultado = ContaPalavras("teste.txt");

    // Verificação das contagens de palavras
    REQUIRE(resultado["este"] == 2);
    REQUIRE(resultado["é"] == 2);
    REQUIRE(resultado["um"] == 1);
    REQUIRE(resultado["teste"] == 2);
    REQUIRE(resultado["outro"] == 1);
}

// Teste para verificar se o arquivo inexistente lança uma exceção
TEST_CASE("Arquivo inexistente lança exceção", "[ContaPalavras]") {
    REQUIRE_THROWS_AS(ContaPalavras("inexistente.txt"), const std::ios_base::failure&);
}

