#include "Translator.h"

Translator::Translator() {
	BST<char, string> *bst = new BST<char, string>("MorseTable.txt");
	bst->translate("Convert.txt");
}

Translator::~Translator() {

}