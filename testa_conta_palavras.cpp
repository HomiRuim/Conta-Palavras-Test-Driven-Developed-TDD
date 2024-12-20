// "Copyright [2024] <Davi Bueno>"

#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "conta_palavras.hpp"

TEST_CASE("Leitura de palavras do arquivo", "[ContaPalavras]") {
    std::ofstream teste("teste.txt");
    teste << "este é um teste\neste é outro teste";
    teste.close();
    auto resultado = ContaPalavras("teste.txt");
    REQUIRE(resultado["este"] == 2);
    REQUIRE(resultado["é"] == 2);
    REQUIRE(resultado["um"] == 1);
    REQUIRE(resultado["teste"] == 2);
    REQUIRE(resultado["outro"] == 1);
}

TEST_CASE("Arquivo inexistente lança exceção", "[ContaPalavras]") {
    REQUIRE_THROWS_AS(ContaPalavras("inexistente.txt"),
    const std::ios_base::failure&);
}

TEST_CASE("Ordem Alfabética", "[ContaPalavras]") {
    std::map<std::string, int> palavras = {
        {"banana", 2},
        {"abacaxi", 1},
        {"uva", 3}
    };

    auto ordenadas = PalavrasOrdenadas(palavras);

    REQUIRE(ordenadas[0].first == "abacaxi");
    REQUIRE(ordenadas[1].first == "banana");
    REQUIRE(ordenadas[2].first == "uva");
}

TEST_CASE("Entrada com múltiplas linhas", "[ContaPalavras]") {
    std::ofstream teste("teste.txt");
    teste << "linha1 palavra1 palavra2\nlinha2 palavra1 palavra3\n";
    teste.close();

    auto resultado = ContaPalavras("teste.txt");

    REQUIRE(resultado["linha1"] == 1);
    REQUIRE(resultado["palavra1"] == 2);
    REQUIRE(resultado["palavra2"] == 1);
    REQUIRE(resultado["palavra3"] == 1);
    REQUIRE(resultado["linha2"] == 1);
}
