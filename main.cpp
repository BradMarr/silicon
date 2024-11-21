#include <fstream>
using std::ifstream, std::ofstream;

#include <iostream>
using std::cerr, std::endl, std::cout, std::string, std::isupper;

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
        if (ch == '<') {
            in.get(ch);
            if (isupper(ch)) {
                string comp_dir = string(1, ch);
                while (in.get(ch) && ch != '/') {
                    ch = ch == '-' ? '/' : ch;
                    if (ch != ' ') {
                        comp_dir += ch;
                    }
                }
                in.get(ch);
                
                
                ifstream comp(PUBLIC_DIR + "/" + comp_dir + ".html");
                if (!comp) {

                    cerr << "Error opening file `" << PUBLIC_DIR + "/" + comp_dir + ".html" << '`' << endl;
                    return 1;
                }

                while(comp.get(ch)) {
                    out << ch;
                }
            } else {
                out << '<' << ch;
                continue;
            }
        } else {
            out << ch;
        }
    }

    return 0;
}