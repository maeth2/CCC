/*
Every Web Page is identified by a string of characters known as a URL (Uniform
Resource Locator). Web Pages are formatted using HTML (Hypertext Markup
Language). HTML has many codes, collectively known as markup, that allow the author
to specify the format of the pages as well as to specify links to other pages. For this
problem, we are concerned only with the markup that identifies links to other pages
within a given page.

A link within the page is denoted <A HREF="URL"> where URL is the URL of some
other page. A user viewing a page containing a link may click on the link to view the
other page.

You are to write a program that reads a number of web pages and their associated URLs.
For each link in each page, you must print the URL of the page containing the link, and
the URL of the page referred to by the link.
Following the last page, you are then given several pairs of URLs. For each pair you are
to assume that you are viewing the page identified by the first URL, and determine
whether it is possible to click a sequence of links so as to view the page identified by the
second URL. If so, you should print "Can surf from here to there." where here and there
are the two URLs. If not you should print "Can't surf from here to there
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

vector<vector<int>> pathways;
vector<string> urls;

int url_index(string url){
    for(int i = 0; i < urls.size(); i++){
        if(url == urls[i]) return i;
    }
    return -1;
}

int dfs(int current, int dest, vector<int> searched){
    if(current == dest) return 1;
    for(int i = 0; i < pathways[current].size(); i++){
        int index = pathways[current][i];
        if(!searched[index]){
            searched[index] = 1;
            if(dfs(index, dest, searched)){
                return 1;
            }
        }
    }
    return 0;
}

void solve(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        string url;
        cin >> url;
        int index = url_index(url);
        vector<int> paths;
        vector<int> p;
        if(index == -1){
            index = urls.size();
            urls.push_back(url);
            pathways.push_back(p);
        }
        string c;
        while(c != "</HTML>"){
            cin >> c;
            if(c.find("HREF=") != c.npos){
                string delimeter = "\"";
                string u = c.erase(0, c.find(delimeter) + delimeter.size());
                u = c.erase(c.find(delimeter), c.size() - c.find(delimeter));
                int ui = url_index(u);
                if(ui == -1){
                    ui = urls.size();
                    urls.push_back(u);
                    pathways.push_back(p);
                }
                string o = "Link from " + url + " to " + u + "\n";
                cout << o;
                paths.push_back(ui);
            }
        }
        pathways[index] = paths;
    }

    string a, b;
    cin >> a >> b;

    while(a != "The" && b != "End"){
        vector<int> searched(urls.size());
        if(dfs(url_index(a), url_index(b), searched)){
            cout << "Can surf from " << a << " to " << b << ".\n";
        }else{
            cout << "Can't surf from " << a << " to " << b << ".\n";
        }
        cin >> a >> b;
    }
}

int main(void){
    solve();
    return 0;
}