#include<iostream>
#include<fstream>

using namespace std;

void printAsHex(const char* inputFile) {
    ifstream f(inputFile, ios_base::ate|ios_base::binary);
    streampos size = 0;
    char *memblock;
    long i;
    if (f.is_open()) {
        size = f.tellg();
        memblock = new char[size];
        f.seekg(0, ios::beg);
        f.read(memblock, size);
        f.close();
    }
    if (size == 0) return;
    cout << size << endl;
    for (i=0; i<size; i++) {
        char d = memblock[i];
        cout << d;
        cout << (char)(d/16+(d/16<10?48:55));
        cout << (char)(d%16+(d%16<10?48:55));
    }
}

int main()
{
    printAsHex("a.png");
    return 0;
}
