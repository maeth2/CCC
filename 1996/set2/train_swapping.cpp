/*
At an old railway station, you may still encounter one of the last remaining "train swappers". 
A train swapper is an employee of the railroad, whose sole job it is to rearrange the carriages of trains.

Once the carriages are arranged in the optimal order, all the train driver has to do is drop the 
carriages off, one by one, at the stations for which the load is meant.

The title "train swapper" stems from the first person who performed this task, at a station close 
to a railway bridge. Instead of opening up vertically, the bridge rotated around a piller in the 
center of the river. After rotating the bridge 90 degrees, boats could pass left or right. The 
first train swapper had discovered that the bridge could be operated with at most two carriages on 
it. By rotating the bridge 180 degrees, the carriages switched place, allowing him to rearrange the 
carriages (as a side effect, the carriages then faced the opposite directions, but train carriages 
can move either way, so who cares).

Now that almost all train swappers have died out, the railway company would like to automate their 
operation. Part of the program to be developed is a routine which decides, for a given train, the 
least number of swaps of two adjacent carriages necessary to order the train. Your assignment is to 
create a routine that computes the minimal number of swaps.
*/
#include <iostream>
#include <vector>

using namespace std;

int solve(){
    int n;
    vector<int> train;
    cin >> n;
    for(int i = 0; i<n; i++){
        int a;
        cin >> a;
        train.push_back(a);
    }

    int switches = 0;
    
    for(int i = 0; i < n - 1; i++){ //bubble sorting
        for(int j = 0; j < n - 1; j++){
            if(train[j] > train[j+1]){
                swap(train[j], train[j+1]);
                switches++;
            }
        }
    }

    cout << "Optimal train swapping takes " << switches << " switches \n";
}

int main(){
    int t;
    cin >> t;
    
    for(int c = 0; c<t; c++){
        solve();
    }

    return 0;
}