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
bool left_side=false;
bool first_case=true;
bool second_case=false;
void vprint(BTNode<string>* root, string prefix){
	if(!left_side){
		if(first_case){
			cout << prefix << "__" << root->payload << endl;
			first_case = false;
		}else{
			cout << prefix << "|__" << root->payload << endl;
			second_case=false;
		}
	}else{
		cout << prefix << "|__" << root->payload << endl;
	}

	if(root->right != NULL){
		left_side=false;
		vprint(root->right, prefix += "  ");
		cout << prefix << "|" << endl;
	}else{
		left_side=true;
	}


	if((root->left == NULL) && (root->right != NULL)){
		cout << prefix << " |__x" << endl;
		second_case=true;
	}else if((root->left != NULL) && (root->right == NULL)){
		cout << prefix << " |__x" << endl;
		second_case=true;
	}
	if(root->left != NULL){
		if(!second_case){
			vprint(root->left, prefix += "");
			second_case=true;
		}else{
			vprint(root->left, prefix += " ");
		}
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

	left_side=false;
	vprint(root->right, "|");
	left_side=true;
	vprint(root->left, "");
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
