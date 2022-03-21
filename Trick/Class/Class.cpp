#include <bits/stdc++.h>
using namespace std;


int main() {
    freopen("input.txt", "r", stdin);
    

    // OOP 
    // Design - Architecture - Kien truc su - Luong cao = Ky su 10 nam kn
    // Implement - Programmer - Ky su / Tho - Luong cui bap
    // input : substrOcc(string s, string t) 
    // output: vector<
    
    class Solution {
    private:
        int point;
        string sourceFile;
    public:
        
    }
    
    class TestCase {
    private:
        string inputFile; 
        string outputFile; 
    public:
        TestCase();
        void createInput(); // cout to file input
        void createOutput();    
    }       
    
    class Problem {
    private:
        vector<TestCase> testcases;
                    
    }    
    
    class Checker {
    private:
        int type; // default, float, custom
        Solution sol, sub; 
        void matching();
        void floatCompare();
        void custom();
        
    public:
        Checker(int type, Solution sol, Solution sub);
        void judge();
    }
    
    class Result {
        string status; // AC, TLE, WA
        int score;
    }

    return 0;
}