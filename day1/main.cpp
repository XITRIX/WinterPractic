#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include "BTree.h"

using namespace cv;
using namespace std;

int main( int argc, char** argv)
{
    BTree<int> tree = *new BTree<int>();
    tree.put(33, 20);
    tree.put(5,5);
    tree.put(35,30);
    tree.put(1, 9);
    tree.put(20, 20);
    tree.put(99, 99);
    tree.put(4, 4);
    tree.put(17, 17);
    tree.put(18, 18);
    tree.put(31, 31);
    
    tree.remove(5);

    cout << tree.get(18) << endl;
    
    return 0;
}
