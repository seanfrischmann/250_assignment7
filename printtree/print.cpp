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
bool is_right;
bool right_child;
bool left_child;
bool is_left;
int counter = 0;
map<int,bool> level_map;
string vertical_level_track(int i){
	string ret="";
	//for(int j=0; j<map.
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
		is_right = true;
		level++;
		map(level,true);
		copyofroot = root->right;
		vertical_print(copyofroot);
		if(root->left == NULL){
			cout << vertical_level_track(level) << 'x' << endl;
		}
		map.erase(level);
		level--;
	}
	if(root->left != NULL){
		is_right = false;
		level++;
		map(level,false);
		if(root->right == NULL){
			cout << vertical_level_track(level) << 'x' << endl;
		}
		copyofroot = root->left;
		vertical_print(copyofroot);
		map.erase(level);
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
