#include "image.hpp"

node* build_quad_tree(){
	node * tree_node = new node;
	tree_node->is_leaf=false;
	tree->pixel_gray_value=NULL;
	tree->top=NULL;
	tree->left=NULL;
	tree->bottom=NULL;
	tree->right=NULL;
	tree->difference=NULL;
	tree->north_west=NULL;
    	tree->north_east=NULL;
    	tree->south_east=NULL;
    	tree->south_west=NULL;
    	return tree_node;
 }
 
 void add_values(node* q, int *p, int num_rows, int num_cols){
    q->p=p;
    q->prows=num_rows;
    q->pcols=num_cols;
    q->bottom=0;
    q->top=num_rows-1;
    q->left=0;
    q->right=num_cols-1;
}

void split_node(node * q)
{

}


float avg_pxvalue(node* q){
    float total=0;
    int right=q->right;
    int left=q->left;
    int top=q->top;
    int bottom=q->bottom;
    int total_cells = (right-left+1)*(top-bottom+1);
    int pcols = q->pcols;
    for(int r =bottom; r <= top; r++){
        for(int c=left; c <= right; c++){
            total += q->p[r*pcols+c];
        }
    }
    float average = (total)/float(total_cells);
    return average;
}


float pixel_variance(node* q){
    float average = avg_pxvalue(q);
    
    float total_dev=0;
    int right=q->right;
    int left=q->left;
    int top=q->top;
    int bottom=q->bottom;
    int total_cells = (right-left+1)*(top-bottom+1);
    int pcols = q->pcols;
    for(int r = bottom; r <= top; r++){
        for(int c=left; c <= right; c++){
            total_dev += (average - q->p[r*pcols+c])*(average - q->p[r*pcols+c]);
        }
    }
    float dev = total_dev/total_cells;
    return dev;
}

void build_quad_tree(node * q, int limit)
{
	if(q==NULL)//base case or new quad tree
	{
		return;
	}
	float var = pixel_variance(q);
	
	if(var>limit)
	{
	split_node(q);
	build_quad_tree(q->northwest,limit);
	build_quad_tree(q->northeast,limit);
	build_quad_tree(q->southeast,limit);
	build_quad_tree(q->southwest,limit);
	}
	else{
		q->is_leaf=true;
		float avg=avg_pxvalue(q);
		q->gray_pixel_value=avg;
	}
}

void make_matrix(node* root, cv::Mat& modified, int total_rows, int total_cols)
{
	if(root=null)
		return;
	
	if(root->is_leaf)
	{
		int right=q->right;
    		int left=q->left;
		int top=q->top;
    		int bottom=q->bottom;
    		int pixel_val=root->pixel_gray_value;
    		for(int r =bottom; r <= top; r++){
        		for(int c=left; c <= right; c++){
		            modified.at<uint8_t>(r,c)=pixel_value;
        		}
    		}	
	}
	else{
	make_matrix(root->northwest, modified, total_rows, total_cols);
        make_matrix(root->northeast, modified, total_rows, total_cols);
        make_matrix(root->soutwest, modified, total_rows, total_cols);
        make_matrix(root->southeast, modified, total_rows, total_cols);
	}		
}

int new_pixels_count(node* root){
    if (root == NULL){
        return 0;
    }
    if (root->is_leaf){
        return 1;
    }
    else{
        return new_pixels_count(root->northwest)+new_pixels_count(root->northeast)+new_pixels_count(root->southwest)+new_pixels_count(root->southeast);
    }
}










