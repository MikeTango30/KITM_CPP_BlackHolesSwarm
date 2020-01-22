#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
const string FILENAME = "spiecius.txt";
const string RESULTS_FILE = "spieciusrez.txt";

void readFile(vector<int> &Nums);
void writeVector(vector<int> &Nums, string text);
int formBlackHole(int a, int b);
void modelSwarmBehaviour(vector<int> &Nums);
void writeResults(vector<int> &Nums);


int main() {
    vector<int> Swarm;

    readFile(Swarm);
    writeVector(Swarm, "Pradinis vektorius:");

    writeResults(Swarm);

    return 0;
}

void readFile(vector<int> &Nums)
{
    int i;
    ifstream in(FILENAME.c_str());

    while(!in.eof()) {
        in >> i;
        Nums.push_back(i);
    }

    in.close();
}

void writeVector(vector<int> &Nums, string text)
{
    ofstream out(RESULTS_FILE, ios_base::app);

    out << text << '\n';

    for(int i : Nums) {
        out << i << " ";
    }

    out << '\n';

    out.close();
}

int formBlackHole(int a, int b)
{
    int result;

    if (a > b) {
        result = a + 1;
    } else if (a < b) {
        result = b + 1;
    } else {
        result = a * 2;
    }

    return result;
}

void modelSwarmBehaviour(vector<int> &Nums){
    Nums[0] = formBlackHole(Nums[0], Nums[1]);
    Nums.erase(Nums.begin() + 1);
}

void writeResults(vector<int> &Nums) {
    string txt;
    while(Nums.size() > 1) {
        if (Nums[0] > Nums[1]) {
            txt = "Antrąją juodają skylę įtraukia pirmoji";
        } else if (Nums[0] < Nums[1]) {
            txt = "Pirmąją juodają skylę įtraukia antroji";
        } else {
            txt = "Juodosios skylės susijungia ir padvigubėja";
        }
        modelSwarmBehaviour(Nums);
        writeVector(Nums, txt);
    }
}