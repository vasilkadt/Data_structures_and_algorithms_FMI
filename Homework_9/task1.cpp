#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    unordered_map<string, set<string>> folders; //folder name -> subfolders
    stack<string> currentPath;
    currentPath.push("/");

    for (int i = 0; i < n; i++)
    {
        string input;

        getline(cin, input);
        string firstWord = input.substr(0, input.find(" "));

        if (firstWord == "mkdir")
        {
            string name = input.substr(firstWord.size() + 1, input.find("\n"));
            if (folders.find(currentPath.top() + name + "/") != folders.end())
            {
                cout << "Directory already exists\n";
            }
            else
            {
                folders[currentPath.top()].insert(name);
                folders[currentPath.top() + name + "/"];
            }
        }
        else if (firstWord == "cd")
        {
            string name = input.substr(firstWord.size() + 1, input.find("\n"));

            if (name == "..")
            {
                if (currentPath.size() == 1)
                {
                    cout << "No such directory\n";
                }
                else
                {
                    currentPath.pop();
                }
                continue;
            }

            if (folders.find(currentPath.top() + name + "/") == folders.end())
            {
                cout << "No such directory\n";
            }
            else
            {
                string element = currentPath.top();
                currentPath.push(element + name + "/");
            }
        }
        else if (firstWord == "ls")
        {
            for (string dir : folders[currentPath.top()])
            {
                cout << dir << " ";
            }
            cout << "\n";
        }
        else if (firstWord == "pwd")
        {
            string path = currentPath.top();
            cout << path << '\n';
        }
    }
    return 0;
}