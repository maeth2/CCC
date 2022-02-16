/*
A modern computer artist works with black-and-white images of 32 x 32 units, for a total of 1024 
pixels per image. One of the operations the artist performs is "adding" two images together, to 
form a new image. In the resulting image a pixel is black if it was black in at least one of the 
component images, otherwise it is white.

A quadtree is a representation format used to encode images. The fundamental idea behind the 
quadtree is that any image can be split into four quadrants. Each quadrant may again be split 
in four subquadrants, etc. In the quadtree, the image is represented by a parent node, while the 
four quadrants are represented by four child nodes, in a predetermined order as shown in the 
figure below.

Of course, if the whole image is a single color, it can be represented by a quadtree consisting 
of a single node. In general, a quadrant needs only to be subdivided if it consists of pixels of 
different colors. As a result, the quadtree need not be of uniform depth.

The preorder representation of a quadtree consisting of a single node is given by `e', if the node 
represents an `empty' (white) quadrant, or `f', if the node represents a `full' (black) quadrant. 
The preorder representation of a quadtree of more than one node consists of the letter `p' (of "parent") 
followed by the preorder representation of the four subtrees in the order indicated in the figure below. 
See the figure for an example.

The artist believes in what is called the preferred fullness: for an image to be attractive the most 
important property is the number of filled (black) pixels in the image. Your job is to write a program 
that, given the quadtree representation of two images, calculates the number of pixels that are black 
when the two images are added.

In the figure, the first example is shown (from top to bottom) as image, quadtree, pre-order string and 
number of pixels. The quadrant numbering is shown at the top of the figure.
*/
#include <iostream>
#include <cmath>
#include <vector>
#include <tuple>

using namespace std;

vector<vector<int>> calculate(string &a, vector<vector<int>> grid, int layer, int size){
    vector<vector<int>> subgrid(size, vector<int>(size));
    int s = size / 2;
    for(int i = 0; i < (layer == 0 ? 1 : 2); i++){
        for(int j = 0; j < (layer == 0 ? 1 : 2); j++){
            if(a.front() == 'f'){
                a.erase(a.begin());
                for(int r = s * i; r < s * i + s; r++){
                    for(int c = s * j; c < s * j + s; c++){
                        subgrid[r][c] = 1;
                    }
                }
            }else if(a.front() == 'e'){
                a.erase(a.begin());
            }else if(a.front() == 'p'){
                a.erase(a.begin());
                vector<vector<int>> sg = calculate(a, grid, layer + 1, s);
                for(int r = 0; r < s; r++){
                    for(int c = 0; c < s; c++){
                        subgrid[s * i + r][s * j + c] = sg[r][c];
                    }
                }
            }
        }
    }
    return subgrid;
}
int solve(){
    
    int size = 32;

    string preorder[2];

    cin >> preorder[0] >> preorder[1];

    vector<vector<int>> tree(size, vector<int>(size));
    vector<vector<int>> tree1(size, vector<int>(size));

    tree = calculate(preorder[0], tree, 0, size * 2);
    tree1 = calculate(preorder[1], tree1, 0, size * 2);

    int total = 0;

    for(int i = 0; i < 32; i++){
        for(int j = 0; j < 32; j++){
            tree[i][j] = (tree[i][j] > tree1[i][j]) ? tree[i][j] : tree1[i][j];
            if(tree[i][j]){
                total ++;
            }
        }
    }

    cout << "There are " << total << " black pixels.";
    
}

int main(){
    int t;
    cin >> t;
    
    for(int c = 0; c<t; c++){
        solve();
    }

    return 0;
}