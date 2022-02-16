/*
A square 1000 by 1000 field contains several sheep. A coyote enters the field at some
point in the south boundary and proceeds to eat the sheep closest to the point of entry,
picking arbitrarily if more than one sheep is equally close. The coyote, being sated, then
leaves the field.

Your job is to determine which sheep may be eaten by the coyote.
*/

/*
To solve this problem you have know whether there is a point closer to the x axis at all points along x = 0 to x = 1000.
First, you compare the point you pick with other points (Lets call the point you picked A and the other B). At what point along the x axis 
does point A become closer to point B? To find this what you need to do is imagine line A to B as the base of an isosceles triangle.
The height of the triangle would be the perpendicular bisector of the two points. Now we have a base and a mid line for the triangle
all we need is find the third point. For this we will use the x intercept of the pb, lets call it C. Since the pb is also the mid-line of the 
isosceles triangle ABC, C being along pb, lines AC will be equal to BC.

       C(on the x axis)
      /|\
     / | \
    /  |  \
   A   pb  B

If we were to move C in any direction the balance would change. How it changes depends on where point B is in relation to A. If B is to the left of A,
then when C is shifted towards x = 0, the line BC will be shorter and AC would get longer. If B was to the right, the opposite would occur.
Now that we know this, we can find the range at which the wolf would need to enter in order for it to prioritize the point B (before or after point C). 
Repeat this step for all other points and find each respective point C. We then keep track of all the point C based on all the point Bs to the left and right of point A 
(making sure to keep the values from the left of point A seperate from the right). If the left and right values were to overlap 
(when left is greater then right), then no matter where on the x axis there will always be a point closer then A.
*/

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;
using ll = long long;
int fpe = 1000;

int min(float a, float b){return (a < b) ? a : b;}
int max(float a, float b){return (a > b) ? a : b;}

void solve(){
    int n;
    cin >> n;
    vector<pair<float, float>> sheeps(n);
    vector<pair<float, float>> eaten;
    vector<int> out(n);
    for(int i = 0; i < n; i++) cin >> sheeps[i].first >> sheeps[i].second;
    for(int i = 0; i < n; i++){
        sheeps[i].first *= fpe;
        sheeps[i].second *= fpe;
    }
    for(int i = 0; i < n; i++){
        float left = 0, right = 1000 * fpe;
        for(int j = 0; j < n; j++){
            if(!out[i] && !out[j] && j != i){
                float xm = (sheeps[i].first + sheeps[j].first) / 2;
                float ym = (sheeps[i].second + sheeps[j].second) / 2;
                if(sheeps[j].first - sheeps[i].first == 0){
                    if(sheeps[i].second < sheeps[j].second){
                        out[j] = true;
                    }else{
                        out[i] = true;
                    }
                }else{
                    float slope = (sheeps[j].second - sheeps[i].second) / (sheeps[j].first - sheeps[i].first);
                    slope = -1 / slope;
                    float b = -slope * xm + ym;
                    float p = -b/slope; 
                    if (sheeps[j].first < sheeps[i].first){
                        left = max(p, left);    
                    }else{
                        right = min(p, right);
                    }
                }
            }
        }
        if (left > right) out[i] = true;
    }
    
    for(int i = 0; i < out.size(); i++){
        if(!out[i]) cout << fixed << setprecision(2) << "The sheep at (" << sheeps[i].first / fpe << ", " << sheeps[i].second / fpe << ") might be eaten.\n";
    }
}

int main(void){
    solve();

    return 0;
}