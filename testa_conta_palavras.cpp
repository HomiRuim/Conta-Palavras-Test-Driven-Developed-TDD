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
    REQUIRE_THROWS_AS(ContaPalavras("inexistente.txt"), const std::ios_base::failure&);
}

