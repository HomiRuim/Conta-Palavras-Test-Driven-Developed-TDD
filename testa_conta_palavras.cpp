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

TEST_CASE("Ordem alfabética", "[ContaPalavras]") {
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

TEST_CASE("Ignorando espaços extras", "[ContaPalavras]") {
    std::ofstream teste("teste.txt");
    teste << "  palavra1   palavra2 palavra1   ";
    teste.close();

    auto resultado = ContaPalavras("teste.txt");

    REQUIRE(resultado["palavra1"] == 2);
    REQUIRE(resultado["palavra2"] == 1);
}

TEST_CASE("Caracteres não alfabéticos", "[ContaPalavras]") {
    std::ofstream teste("teste.txt");
    teste << "palavra1, palavra2! (palavra3?) palavra4: palavra1.";
    teste.close();

    auto resultado = ContaPalavras("teste.txt");

    REQUIRE(resultado["palavra1,"] == 1);
    REQUIRE(resultado["palavra2!"] == 1);
    REQUIRE(resultado["(palavra3?)"] == 1);
    REQUIRE(resultado["palavra4:"] == 1);
    REQUIRE(resultado["palavra1."] == 1);
}

TEST_CASE("Palavras repetidas em casos mistos", "[ContaPalavras]") {
    std::ofstream teste("teste.txt");
    teste << "Casa casa CASA";
    teste.close();

    auto resultado = ContaPalavras("teste.txt");

    REQUIRE(resultado["Casa"] == 1);
    REQUIRE(resultado["casa"] == 1);
    REQUIRE(resultado["CASA"] == 1);
}

TEST_CASE("Arquivo grande", "[ContaPalavras]") {
    std::ofstream teste("teste.txt");
    for (int i = 0; i < 1000; ++i) {
        teste << "palavra" << i << " ";
    }
    teste.close();

    auto resultado = ContaPalavras("teste.txt");
    for (int i = 0; i < 1000; ++i) {
        REQUIRE(resultado["palavra" + std::to_string(i)] == 1);
    }
}

TEST_CASE("Linhas em branco", "[ContaPalavras]") {
    std::ofstream teste("teste.txt");
    teste << "linha1\n\nlinha2 palavra1\n\n";
    teste.close();

    auto resultado = ContaPalavras("teste.txt");
    
    REQUIRE(resultado["linha1"] == 1);
    REQUIRE(resultado["linha2"] == 1);
    REQUIRE(resultado["palavra1"] == 1);
}

TEST_CASE("Palavras duplicadas", "[ContaPalavras]") {
    std::ofstream teste("teste.txt");
    teste << "palavra1\npalavra2 palavra1\npalavra3 palavra2";
    teste.close();

    auto resultado = ContaPalavras("teste.txt");

    REQUIRE(resultado["palavra1"] == 2);
    REQUIRE(resultado["palavra2"] == 2);
    REQUIRE(resultado["palavra3"] == 1);
}

TEST_CASE("Só numeros", "[ContaPalavras]") {
    std::ofstream teste("teste.txt");
    teste << "123 456 123";
    teste.close();

    auto resultado = ContaPalavras("teste.txt");

    REQUIRE(resultado["123"] == 2);
    REQUIRE(resultado["456"] == 1);
    REQUIRE(resultado["789"] == 0);
    REQUIRE(resultado["812"] == 0);
    REQUIRE(resultado["913"] == 0);
    REQUIRE(resultado["204"] == 0);
}

TEST_CASE("Caracteres especiais", "[ContaPalavras]") {
    std::ofstream teste("teste.txt");
    teste << "#palavra! @outra_palavra$ %mais_uma^";
    teste.close();

    auto resultado = ContaPalavras("teste.txt");

    REQUIRE(resultado["#palavra!"] == 1);
    REQUIRE(resultado["@outra_palavra$"] == 1);
    REQUIRE(resultado["%mais_uma^"] == 1);
}

TEST_CASE("Sopa de caracteres", "[ContaPalavras]") {
    std::ofstream teste("teste.txt");
    teste << "Casa1 casa1 CASA1";
    teste.close();

    auto resultado = ContaPalavras("teste.txt");

    REQUIRE(resultado["Casa1"] == 1);
    REQUIRE(resultado["casa1"] == 1);
    REQUIRE(resultado["CASA1"] == 1);
    REQUIRE(resultado["cAsA1"] == 0);
    REQUIRE(resultado["CaSa1"] == 0);
}

TEST_CASE("Símbolos como separadores", "[ContaPalavras]") {
    std::ofstream teste("teste.txt");
    teste << "palavra1,palavra2.palavra3;palavra4";
    teste.close();

    auto resultado = ContaPalavras("teste.txt");

    REQUIRE(resultado["palavra1,palavra2.palavra3;palavra4"] == 1);
}
