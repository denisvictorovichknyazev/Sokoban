#ifndef LOADER_H
#define LOADER_H

#include <fstream>
#include <string>

using namespace std;
class Loader{
public:
    Loader(char* str);
    void read(string let);
    int getm();
    int getn();
    int getelem(int i,int j);
    ~Loader();
private:
    char *fileName;
    int **mat;
    int n,m;
};

#endif // LOADER_H
