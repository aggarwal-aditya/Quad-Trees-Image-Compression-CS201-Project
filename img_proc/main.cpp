#include <iostream>
#include <opencv2/opencv.hpp> 
#include "image.hpp"
using namespace cv;
using namespace std;

int main()
{
    int max_comp=100;
    Mat original = imread("index.png", IMREAD_GRAYSCALE);
    Mat modified = imread("index.png", IMREAD_GRAYSCALE);
    if (original.empty()){
        cout << "Could not open or find image"<< endl;
        return -1;
    }
    int rows=modified.rows;
    int cols=modified.cols;
    
    cout << "Rows: " <<  rows << endl;
    cout << "Cols: " <<  cols << endl;
    cout << "Total pixels: " << rows * cols << endl;
    
    int* pixels = new int[rows*cols];
    
    for(int r = 0; r < rows; r++){
        for(int c = 0; c < cols; c++){
            pixels[r*cols+c]=modified.at<uint8_t>(r,c);
        }
    }

    node * q = new_node();
    add_values(q, pixels, rows, cols);
    build_quad_tree(q,max_comp);
    cout << "Nodes: " << new_pixels_count(q) << endl;
    make_matrix(q, modified, rows, cols);
    imshow("Original", modified);
    imwrite("Modified.jpeg", modified);
    waitKey(0);
    return 0;
}
