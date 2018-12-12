#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <bitset>
//#include "Node_hyper.h"
#include "node.h"
//#include "phtree.h"

using namespace std;

//PH_tree<90> tree;
phtree tree;
void imprimir_vec(vector< bitset<32> > vec){
    int tam = vec.size();
    for(int i = 0; i < tam; i++){
        cout<<vec[i]<< " ";
    }
    cout<<endl;

}



vector< mdd<90> > csvLector(string g)
{
    ifstream  archivodata(g);
    vector< mdd<90> > resultado;
    string line;
    string cell;
    int cont =0;
    while(getline(archivodata,line))
    {
            stringstream  lineStream(line);
            int i =0;
            mdd<90> temporal;

            while(getline(lineStream,cell,','))
            {
                  temporal.vec_bit.push_back(convertir(cell));
                  i++;

            }
            //tree.insert_PH(temporal);
            tree.insertar(temporal,&tree.root);
            cont++;
            //cout<<"insertor "<< cont <<endl;
            //imprimir_vec(temporal.vec_bit);
            //resultado.push_back(temporal);
            resultado.push_back(temporal);
    }

    cout<<cont<<endl;

    return resultado;
}


int main()
{
    union
    {
         float input;   // assumes sizeof(float) == sizeof(int)
         int   output;
    }    data;

    data.input = 2.25125;

    std::bitset<sizeof(float) * CHAR_BIT>   bits(data.output);

    std::cout << bits << std::endl;

    // or

    std::cout << "BIT 4: " << bits[4] << std::endl;
    std::cout << "BIT 7: " << bits[7] << std::endl;

    vector< mdd<90> > res =csvLector("yp.txt");
    //vector< mdd<90> > res =csvLector("mycoord.txt");

    cout<<"lo encontro =="<<tree.buscar(res[0],&tree.root);
    //csvLector("mycoord.txt");
    tree.view_tree(tree.root);
    //int a;
    //cin>>a;
    return 0;
}
