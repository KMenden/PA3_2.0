## Cluster Program Introduction

The following is a cluster program that contains two classes (both their definition and implementation files) named cluster and point. The program is a clustering program where the user is able to create their own points of a user defined number of demensions (X,Y,Z and above, stored in a dynamic array) and then create clusters that contain these points. In order to utilize this program you must include the cluster.h and point.h header into your program using #include "point.h" (include the quotes), you also must use the clustering namespace that the program is written into using "using namespace clustering" (without the quotes). This program also includes a clustering algorithm using the KMeans method to cluster your points in a more optimized way using a text file containing point coordinates, more details below.

## Point Class Documentaion

The point class is capable of creating points with a user given number of dimensions. In order to create a new point, you define a point data type such as "Point p1" but you must pass in the number of demensions as a function argument such as "Point p1(3)" for a point that has three coordinates for three demensions. Should you only pass the number of demensions, then each coordinate will be set to 0 and can be set later using the getvalue and setvalue functions, you can also copy two points with the copy constructor for points such as Point p2(p1). Should you define an array that is the same size as your demensions, you can pass the array into your point as well to initialize it as it is created. From there, it is possible to utilize the comparison, arithmetic, and assiment operators on two points such as +, -, +=, and -=, which will take two points and add/subtract them (and in the case of += and -=, assign them to another point), and ==, <=, >=, <, >, which will check for each comparison and return a bool result. Comparisons between two points is done in a lexicographic order (point (1,2,3) is less than (4,5,2) and (4,2,1) is greater than (1,1,4)). However, the *, /, *=, and /=, operators can ONLY be done with whole numbers (Such as (1,2,3) * 2 is (2,4,6)).
It is also possible to create dynamic points by the use of PointPtrs (Such as PointPtr p1 = new Point(4), which creates a dynamic point of four demensions with corrodinates (0,0,0,0).

##Cluster Class Documentation

The Cluster class is a class that works with a number of point objects and thus, you need to have the point class included in your file for the program to work with an #include "Point.h" statement, along with the Clustering namespace as said before. The clustering class is capable of tracking and manuplating a set of points, you are able to add clusters in an argument with the operators + and - as well as replace the right hand side with the memory address of a point (c1 + &p3 for example) or with a pointer to a dynamically allocated point to have the point be added to a temporary cluster for a function argument, you are also able to copy clusters with c1(c2) for example (Same as points), and can also add or subtract points from a cluster with the += and -= arguments respectively, should the right hand argument be a point (c1 += p2) and unlike the +, -, operators you can simply use a point rather than the memory address of one or pointer to a point. Also important to the cluster class is the add and remove functions, these functions allow the programmer to add and remove a given point from a cluster, all you need to do is pass in that point by reference using c1.add(&p1) or c1.remove(&p1), you can also use dynamically allocated points in which case, you can simply use that pointPtr in the function argument instead (Such as c1.add(pointer1) or c1.remove(pointer2) the functions can also return a reference to this same point allowing arguments such as c1.add(c2.remove(&p1)) to quickly remove a point from one cluster and put it into another. The last thing of note is that you can also create two clusters and have one equal the other such as c1 = c2. You can also check if both clusters hold the same points with the == operator (c1==c2).

## KMeans
The KMeans class is for KMeans clustering and is capable of reading a file containing point coordinates and clustering them within a point space. In order to utilize the KMeans class you must first include the KMeans class (#include "KMeans.h") and then to create a KMeans object using three parameters for it's constructor (KMeans test(2, 4, "points.txt") for example). The first and second parameters are the value of K and the point dimensions, the K value is the number of clusters you wish to use in your KMeans clustering while the point dimensions value is the number of coordinates (Or dimensions) your points will take up. Should you attmpt to use near, or more, clusters than your number of points then you will end up with a number of empty clusters, this is normal and is a side effect of how KMeans clusters works with your data for optimal results.

!!IMPORTANT!!

It is VERY important that all your points take on the same dimensions! You cannot have an X,Y,Z and an X,Y point within the same clustering point space! Should your data contain a point that does not have the correct number of dimensions, it will be discarded and the algorithm will move to the next point.

!!IMPORTANT!!

The third and final parameter is a string containing the name of your text file that contains your points, your file should be located in the same folder that the KMeans, Cluster, and Point files are located since this is where the program will look for your data. The clustering program will cluster your points to the most optimized locations it can find. After doing this, the KMeans program will write out the results to a "results.txt" file and onto your console's screen. The points within your file should be written as such

11.4,2.2,4.7,8.22

3.67,6,56,89.3,23

Note how each point is on it's own line and each coordinate is separated by commas, this is very important and your file should not deviate from this format, also be warned to NOT include a comma at the very end of a line, it will cause the algorithm to not read in legitimate points and worse, it can cause an invalid point to be read into the clustering space causing undefined behavior. After creating your KMeans object with the correct parameters you then call it's start() function (test.start() for example) to begin the clustering algorithm, this function will perform all the necessary set up and execution of your data so long as you provide the correct format and information when you create the object.

After completing it's clustering algorithm the program will print out each point and which cluster that point belongs to, the results will not only be printed to your screen but will be written out to the "results.txt" file located in the same place as you input file. The format for this output is as follows

0, 23.2, 12, 5.6, 14.2, : 1

1.3, 4.3, 0, 5.6, 7.9, : 2

4.1, 5.6, 5, 1.6, 7.9, : 2

0.1, 2.3, 5.4, 22, 11.2, : 3

2.3, 5.6, 0, 5.6, 7.9, : 3

2.4, 5.6, 0, 6.6, 7.1, : 3

Where the number after the colon is the ID of which ever cluster that point belongs too.

##Compiler
G++ and Clion

The compiler used to create this program was the GNU C++ compiler (G++), done through CLion on a VMware Ubuntu Linux Operating system.
#ucd-csci2312-pa2.

