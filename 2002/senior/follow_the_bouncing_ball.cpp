/*

*/
#include <iostream>
#include <cmath>

using namespace std;
using ll = long long;

void solve(){
    double width, height, startx, starty, x, y, slope, numheight, numwidth, a, b, bounce;
    cin >> width >> height >> startx >> starty;

    bool done = false;
    slope = starty / (width - startx);
    for(int k = 0; k < 100000; k++){
        y = slope * ((k * width) - startx);
	    x = (k * height) / slope + startx;

	    numheight = (int) ((y - (height / 2)) / height) + 1;
	    numwidth = (int) ((x - (width / 2)) / width) + 1;
	    a = numheight * height;
	    b = numwidth * width;

	    if ((abs(a - y) < 5) || (abs(b - x) < 5)) {
            if (abs(a - y) < 5) {
                if (a != y){
                    bounce = k - 1 + (int) (y / height);
                }else{
                    bounce = k - 1 + (int) (y / height) - 1;
                }
            } else {
                if (b != x){
                    bounce = k - 1 + (int) (x / width);
                }else{
                    bounce = k - 1 + (int) (x / width) - 1;
                }
            }
            cout << bounce;
		    done = true;
            break;
        }
    }
    if(!done) cout << 0;
    
}

int main(void){
    solve();
    return 0;
}