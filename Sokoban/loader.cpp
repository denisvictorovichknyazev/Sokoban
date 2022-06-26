#include "loader.h"

Loader::Loader(char* str)
{
    fileName=str;
}

void Loader::read(string let){
    ifstream in(fileName);
    string buf;
    if (in.is_open())
        {
            int count = 0;
            int temp;
            while ((!in.eof()))
            {
                getline(in, buf);
                if (buf == let){
                    break;
                }
            }

            while ((!in.eof()))
            {
                if (in >> temp){
                    count++;
                }
                else
                    break;
            }
            in.close();
            in.open(fileName);
            while ((!in.eof()))
            {
                getline(in, buf);
                if (buf == let){
                    break;
                }
            }
            int count_space = 0;
            char symbol;
            while (!in.eof())
            {

                in.get(symbol);
                if (symbol == ' ') count_space++;
                if ((symbol == 'E') || (symbol == 'H') || (symbol == 'B')) break;
                if (symbol == '\n') break;
            }

            in.close();
            in.open(fileName);
            while ((!in.eof()))
            {
                getline(in, buf);
                if (buf == let){
                    break;
                }
            }
             n = count / (count_space + 1);
             m = count_space + 1;
            double t;
            mat = new int*[n];
            for (int i = 0; i<n; i++)
                mat[i] = new int[m];
                for (int i = 0; i < n; i++)
                    for (int j = 0; j < m; j++){
                        if (in >> t){
                            mat[i][j] = t;
                        }
                        else break;
                    }

  }else{

    }
}

int Loader::getm(){
    return m;
}

int Loader::getn(){
    return n;
}

int Loader::getelem(int i,int j){
    return mat[i][j];
}

Loader::~Loader(){
   delete[] mat;
}
