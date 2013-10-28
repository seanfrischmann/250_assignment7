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
 *Vertical Level track
 *------------------------------------------------------------------------------
 */
int level = 0;
string vertical_level_track(int i){
	string ret="";
	if(i==1){
		ret = "|__";
	}
	else if(i != 0){
		ret = "|";
		for(int j=0; j<level; j++){
			ret += "  ";
		}
		ret += "|__";
	}
	return ret;
}
/**
 * -----------------------------------------------------------------------------
 * print a given tree vertically
 * -----------------------------------------------------------------------------
 */
void vertical_print(BTNode<string>* root) {
    // your code goes here
	BTNode<string> *copyofroot=root;
	cout << vertical_level_track(level) << root->payload << endl;
	if(root->right != NULL){
		level++;
		copyofroot = root->right;
		vertical_print(copyofroot);
		level--;
		if(root->left == NULL){
			cout << vertical_level_track(level) << 'x' << endl;
		}
	}
	if(root->left != NULL){
		if(root->right == NULL){
			cout << vertical_level_track(level) << 'x' << endl;
		}
		level++;
		copyofroot = root->left;
		vertical_print(copyofroot);
		level--;
	}
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
