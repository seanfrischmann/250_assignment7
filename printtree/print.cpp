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
 *Creates a vector storing elements to be printed as a horizontal tree 
 * -----------------------------------------------------------------------------
 */
vector<string> hvector(BTNode<string>* root){
	vector<string> ret;
	if(root == NULL){
		ret.push_back("x");
	}else if((root->left != NULL) || (root->right != NULL)){
		vector<string> left = hvector(root->left);
		vector<string> right = hvector(root->right);
		size_t max = left.at(0).length();
		size_t root_len = root->payload.length();
		for(size_t i = 1; i < left.size(); i++){
			if(left.at(i).length() > max){
				max = left.at(i).length();
			}
		}
		string root_payload = root->payload;
		string space_btwn_elements="";
		string spaces_len;
		string output="";
		int space_modifier=0;
		if(root_len < max){
			space_modifier=1;
			int dash_number= (max - root->payload.length())+2;
			for(int i=0;i < dash_number; i++){
				root_payload += "_";
			}
			for(size_t i=0;i < max+1; i++){
				space_btwn_elements += " ";
			}
			spaces_len=space_btwn_elements;
		}else{
			for(size_t i=1; i < root_len; i++){
				space_btwn_elements += " ";
			}
			spaces_len=space_btwn_elements+" ";
		}
		ret.push_back(root_payload);
		ret.push_back("|"+space_btwn_elements+"\\");
		size_t right_size= right.size();
		size_t left_size= left.size();
		size_t j=0;
		spaces_len+=" ";
		while((right_size >= 1) && (left_size >= 1)){
			string spaces_btwn_LR;
			size_t length_btwn_LR=(spaces_len.length())-(left.at(j).length());
			for(size_t i=0; i < length_btwn_LR + space_modifier; i++){
				spaces_btwn_LR += " ";
			}
			ret.push_back(left.at(j)+spaces_btwn_LR+right.at(j));
			right_size--;
			left_size--;
			j++;
		}
		if(right.size() > 1){
			for(size_t i=j; i < right.size(); i++){
				ret.push_back(spaces_len+" "+right.at(i));
			}
		}if(left.size() > j){
			for(size_t i=j; i < left.size(); i++){
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
	for(size_t i=0; i < vec.size(); i++){
		cout << vec.at(i) << endl;
	}
}

/**
 * -----------------------------------------------------------------------------
 *Creates a vector storing elements to be printed as a symetrical tree 
 * -----------------------------------------------------------------------------
 */
/*vector<string> svector(BTNode<string>* root){
	vector<string> ret;
	if(root == NULL){
		ret.push_back("x");
	}else if((root->left != NULL) || (root->right != NULL)){
		vector<string> left = svector(root->left);
		vector<string right = svector(root->right);
		size_t root_length = root->payload.length();
		size_t big_half_max;
		size_t small_half_max=0;
		string root_payload = root->payload;
		string spaces_in_front="";
		if(root->left != NULL){
			big_half_max =  root->left->payload/2;
			if((root->left->payload%2) != 0){
				big_half_max += 1;
			}
			for(int i=0; i< big_half_max; i++){
				spaces_in_front += " ";
			}
		}else if(root->right != NULL){
			spaces_in_front += " ";
		}
		if(root_length > small_half_max){
			
		}
		}
	}else{
		ret.push_back(root->payload);
	}
	return ret;
}*/
/**
 * -----------------------------------------------------------------------------
 * print a given tree symmetrically
 * -----------------------------------------------------------------------------
 */
void symmetric_print(BTNode<string>* root) {
    // your code goes here
    cout << "Symmetric print: TBD\n";
}
