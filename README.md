# Quad Trees



# How to use our program?
To download our program, please copy and paste this line to your terminal:
```
git clone https://github.com/aggarwal-aditya/CS201-Project.git
```
### First you will need to decide if you want to simulate [Region Quad Tree](https://en.wikipedia.org/wiki/Quadtree#Region_quadtree) or [Point Quad Tree](https://en.wikipedia.org/wiki/Quadtree#Point_quadtree):
Region Quadtree is used for image compression (details can be found in hyperlink in heading) while point QuadTree is used for stroing two dimensional points with their coressponding data values (details can be found in hyperlink in heading).
To simulate image compression, type ``` cd img_proc ``` in your terminal. To simulate point quad tree, type ``` cd point_quad ``` in your terminal.

---

### Further Steps to run Image Compression
It is expected that your system has OpenCV library installed (it has been  used for reading and writing images as we cant do this directly in C/C++). If not steps for the same are given below.

***Steps to install OpenCV***

Build and install OpenCV in your machine if you already haven't. Here are guides to do the same:
* [For Ubuntu](http://techawarey.com/programming/install-opencv-c-c-in-ubuntu-18-04-lts-step-by-step-guide/) 
* [For Windows](https://cv-tricks.com/how-to/installation-of-opencv-4-1-0-in-windows-10-from-source/)
* [For MacOS](https://docs.opencv.org/master/d0/db2/tutorial_macos_install.html)

***Recommendation***: Installing OpenCV on windows is a tediuos task and not advised. For easier and quicker installation use Ubuntu(Best Choice) or MacOS(Second Best Choice). If you are on a windows machine, and dont have a Linux distribution installed in your system, you may use a virtual machine.

After installing OpenCV, type ```make``` in your terminal. This will produce an output file ***test***. To run this file type ```./test``` in your terminal. 
After this the programme will ask you the path of image which is to compressed. After you enter the required path, it will ask you if you want to proceed with default setting for image variance(a measure for image compression) or want to change it. After providing the required inputs the programme will display the original and compressed file. The compressed file will also be saved with a name ***modified.jpeg*** in the directory where original image was present. 

---

### Further Steps to run Point Quad Tree



---


**Group Members**
| Name            | Entry Number |
| --------------- | ------------ |
| Aditya Aggarwal | 2020CSB1066  |
| Anubhav Kataria | 2020CSB1073  |
| Prakhar Saxena | 2020CSB1111  |
