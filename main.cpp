#include <fstream>
using std::ifstream, std::ofstream;

#include <iostream>
using std::cerr, std::endl, std::cout, std::string;

const string PUBLIC_DIR = "public";
const string OUT_DIR = "out";

int main() {
    ifstream in(PUBLIC_DIR + "/page.html");
    ofstream out(OUT_DIR + "/index.html");

    if (!in) {
        cerr << "Error opening file" << endl;
        return 1;
    }

    char ch;
    while (in.get(ch)) {
        if (ch == '|') {
            std::string comp_dir = "";
            while (in.get(ch) && ch != '|') {
                comp_dir += ch;
            }
            ifstream comp(PUBLIC_DIR + "/" + comp_dir + ".html");
            if (!comp) {
                cerr << "Error opening file" << endl;
                return 1;
            }
            while(comp.get(ch)) {
                out << ch;
            }
        } else {
            out << ch;
        }
    }

    return 0;
}