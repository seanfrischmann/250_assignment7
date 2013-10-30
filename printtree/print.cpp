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
	if(root == NULL){
		cerr << "Please make sure you enter a new tree" << endl;
		return;
	}
	cout << root->payload << endl;

	if(root->right != NULL){
		vprint(root->right, "|");
	}else if(root->left == NULL){
		return;
	}else{
		cout << "|__x" << endl;
	}
	cout << "|" << endl;
	if(root->left != NULL){
		vprint(root->left, " ");
	}else{
		cout << "|__x" << endl;
	}
}

/**
 * -----------------------------------------------------------------------------
 * 
 * -----------------------------------------------------------------------------
 */
vector<string> hvector(BTNode<string>* root){
	vector<string> ret;
	if(root == NULL){
		ret.push_back("x");
	}else if((root->left != NULL) || (root->right != NULL)){
		vector<string> left = hvector(root->left);
		vector<string> right = hvector(root->right);
		int max = left.at(0).length();
		int root_len = root->payload.length();
		for(int i = 1; i < left.size(); i++){
			if(left.at(i).length() > max){
				max = left.at(i).length();
			}
		}
		string root_payload = root->payload;
		string spaces="";
		string spaces_len;
		string output="";
		if(root_len < max){
			for(int i=0;i < max+1; i++){
				root_payload += "_";
				spaces += " ";
			}
			output=left.at(0)+spaces+right.at(0);
			spaces_len=spaces;
		}else{
			for(int i=1; i < root_len; i++){
				spaces += " ";
			}
			spaces_len=spaces+" ";
			output=left.at(0)+spaces_len+right.at(0);
		}
		ret.push_back(root_payload);
		ret.push_back("|"+spaces+"\\");
		ret.push_back(output);
		if(right.size() > left.size()){
			spaces_len+=" ";
			for(int i=1; i < right.size(); i++){
				ret.push_back(spaces_len+right.at(i));
			}
		}else if(left.size() > right.size()){
			for(int i=1; i < left.size(); i++){
				ret.push_back(left.at(i));
			}
		}
	}else{
		ret.push_back(root->payload);
	}
	return ret;
}
/**
 * -----------------------------------------------------------------------------
 * print a given tree horizontally
 * -----------------------------------------------------------------------------
 */
void horizontal_print(BTNode<string>* root) {
    // your code goes here
	vector<string> vec = hvector(root);
	for(int i=0; i < vec.size(); i++){
		cout << vec.at(i) << endl;
	}
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
