// =============================================================================
// print.cpp
// ~~~~~~~~~
// Sean Frischmann
// - implement the three tree printing routines
// *****************************************************************************
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <stdexcept>
#include <deque>
#include "BTree.h"
#include "term_control.h"
using namespace std;

// feel free to change the following notice
string version = 
    "UB Tree Program. Version 0.1\n"
    " Author: Sean Frischmann\n"
    " Report bugs to seanfris@buffalo.edu\n";

/*
 * -----------------------------------------------------------------------------
 * vprint method
 *------------------------------------------------------------------------------
*/
void vprint(BTNode<string>* root, string prefix){
	if(prefix.length() < 1){
		cout << prefix << "__" << root->payload << endl;
	}else{
		string payload_prefix;
		payload_prefix = prefix;
		payload_prefix[payload_prefix.length()-1]= '|';
		cout << payload_prefix << "__" << root->payload << endl;
	}
	
	if(root->right != NULL) {
		vprint(root->right, prefix + "  |");
		cout << prefix << "  |" << endl;
	}else if((root->left != NULL) && (root->right == NULL)){
		cout << prefix << "  |__x" << endl;
		cout << prefix << "  |" << endl;
	}

	if((root->left == NULL) && (root->right != NULL)){
		cout << prefix << "  |__x" << endl;
	}if(root->left != NULL) {
		vprint(root->left, prefix + "   ");
	}
}

/**
 * -----------------------------------------------------------------------------
 * print a given tree vertically
 * -----------------------------------------------------------------------------
 */
void vertical_print(BTNode<string>* root) {
    // your code goes here
	cout << root->payload << endl;

	vprint(root->right, "|");
	cout << "|" << endl;
	vprint(root->left, " ");
}

/**
 * -----------------------------------------------------------------------------
 * print a given tree horizontally
 * -----------------------------------------------------------------------------
 */
void horizontal_print(BTNode<string>* root) {
    // your code goes here
    cout << "Horizontal print: TBD\n";
}

/**
 * -----------------------------------------------------------------------------
 * print a given tree symmetrically
 * -----------------------------------------------------------------------------
 */
void symmetric_print(BTNode<string>* root) {
    // your code goes here
    cout << "Symmetric print: TBD\n";
}
