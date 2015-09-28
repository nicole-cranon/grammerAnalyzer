/*
	nicole cranon <nicole.cranon@ucdenver.edu>
	csci 4240 fall 2015
	assignment 5 - grammer analyzer
 */

#include "grammerAnalyzer.h"
#include <iostream>

int main (int argc, char *argv[]) {

	if (argc < 2) {
		std::cerr << "\nNot enough arguments provided!\n";
		return 0;
	}

	std::vector<std::string> ingrammer,
		outgrammer,
		RHSList,
		LHSList;
	std::vector<char> symbols;

	std::set<std::string> nonterminals,
		terminals;

	ga::read_productions (argv[1], ingrammer);

	ga::analyze (ingrammer, outgrammer, nonterminals, terminals, LHSList, 
		RHSList, symbols);

	std::cout << "\n::Grammer (Production List)::";
	for (unsigned i = 0; i < outgrammer.size(); ++i) {
		std::cout << "\nProduction " << i+1 << " " <<  outgrammer[i];
	}

	std::cout << "\n\n::Nonterminals List::";
	for (auto nt : nonterminals) {
		std::cout << "\nNonterminal " << nt;
	}

	std::cout << "\n\n::Terminals List::";
	for (auto t : terminals) {
		std::cout << "\nTerminal " << t;
	}

	std::cout << "\n\n::LHS List::";
	for (unsigned i = 0; i < LHSList.size(); ++i) {
		std::cout << "\nLHS " << i+1 << " " << LHSList[i];
	}

	std::cout << "\n\n::RHS List::";
	for (unsigned i = 0; i < RHSList.size(); ++i) {
		std::cout << "\nRHS " << i+1 << " " << RHSList[i];
	}

	std::cout  << "\n\n";

	return 0;
}
