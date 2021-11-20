#include <iostream>
#include <opencv2/opencv.hpp> 
#include "image.hpp"
using namespace cv;
using namespace std;

int main()
{
    int max_comp=100;
    string s; 
    cout<<"Please Enter the path of Image\n";
    cin>>s;
    Mat original = imread(s, IMREAD_GRAYSCALE);
    Mat modified = imread(s, IMREAD_GRAYSCALE);
    while(original.empty()){
    	if (original.empty()){
        cout << "No such Image found,please try again"<< endl;
    	}
    	cin>>s;
    	 original = imread(s, IMREAD_GRAYSCALE);
    	 modified = imread(s, IMREAD_GRAYSCALE);
    
    }
    cout<<"If you want to set maximum image variance of compressed image (a measure for compression) press Y, else press any other key to continuw with default setting"<<endl;
    char ch; cin>>ch;
    if(ch=='Y')
    {
    	cout<<endl<<"Please enter the value of image variance";
    	cin>>max_comp;
    }
    
    int rows=modified.rows;
    int cols=modified.cols;
    
    cout << "Rows: " <<  rows << endl;
    cout << "Cols: " <<  cols << endl;
    cout << "Total pixels in orignal Image: " << rows * cols << endl;
    
    int* pixels = new int[rows*cols];
    
    for(int r = 0; r < rows; r++){
        for(int c = 0; c < cols; c++){
            pixels[r*cols+c]=modified.at<uint8_t>(r,c);
        }
    }

    node * q = new_node();
    add_values(q, pixels, rows, cols);
    build_quad_tree(q,max_comp);
    cout << "Nodes in Quad Tree - An approximate for new pixels: " << new_pixels_count(q) << endl;
    make_matrix(q, modified, rows, cols);
    imshow("Original", original);
    imshow("Compressed", modified);
    imwrite("Modified.jpeg", modified);
    waitKey(0);
    return 0;
}
