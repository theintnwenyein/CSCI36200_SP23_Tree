#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

struct Node{
	int value;
	Node* leftChild;
	Node* rightChild;
};// end Node

Node* createNode(int value){
	Node* newNode = new Node();
	newNode->value = value;
	newNode->leftChild = nullptr;
	newNode->rightChild = nullptr;
	return newNode;
}// end createNode


// Creating the BST
Node* insert(Node* root, int value){
	// Check if the tree is empty
	if(root == NULL){
		root = createNode(value);
		return root;
	}// end if

	// If the key is less than the root's value, insert at as the root's leftChild
	else if(value < root->value){
		root->leftChild = insert(root->leftChild, value);
	}// end else if

	// If the key is greater than the root, insert it as the rightChild
	else if(value > root->value){
		root->rightChild = insert(root->rightChild, value);
	}// end else
	
	return root;
}// end insert

void printNodes(Node* root, int k1, int k2){
	if(k1 < k2){
		// Check if the tree is empty
		if(root == NULL){
			return;
		}// end if
		
		// Print the leftChild nodes first
		if(k1 <= root->value){
			printNodes(root->leftChild, k1, k2);
		}// end if

		// Print the parent node
		if(k1 <= root->value && k2 >= root->value){
			std::cout<<root->value<<std::endl;
		}// end if

		// Pring the rightChild nodes now
		if(k2 >= root->value){
			printNodes(root->rightChild, k1, k2);
		}// end if
	}// end if
	else{
		std::cout<<"Input input! k1 must be smaller than k2."<<std::endl;
	}// end else
}// end printNodes

int main(){
	std::ifstream inputFile;
	std::string inputKeyString;
	Node* root = NULL;
	int inputKey;
	int k1;
	int k2;

	std::cout<<"Enter the value for k1: ";
	std::cin>>k1;

	std::cout<<"Enter the value for k2: ";
	std::cin>>k2;

	inputFile.open("input.txt");
	while(getline(inputFile, inputKeyString)){
		inputKey = std::stoi(inputKeyString);
		root = insert(root, inputKey);
	}// end while
	
	printNodes(root, k1, k2);
	inputFile.close();
	return 0;
}// end main
