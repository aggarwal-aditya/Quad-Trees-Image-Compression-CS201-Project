#ifndef qtree_hpp
#define qtree_hpp
#include<iostream>
#include <stdio.h>
#include <opencv2/highgui.hpp>

using namespace std;

typedef struct node{
	bool is_leaf;
	int pixel_gray_value;
	int * p;
	int top;
	int left;
	int bottom;
	int right;
	
       int prows;
       int pcols;
       
	node* north_west;
    	node* north_east;
    	node* south_east;
    	node* south_west;
}node;

node* new_node();
void add_values(node* q, int* p, int num_rows, int num_cols);
void split_node(node* q);

float avg_pxvalue(node* q);
float pixel_variance(node* q);
void build_quad_tree(node* root, int var);
void make_matrix(node*start, cv::Mat& modified, int total_rows, int total_cols);
int new_pixels_count(node* root);

#endif
