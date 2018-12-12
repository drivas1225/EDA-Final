#include <iostream>
#include <vector>
#include "mdd.h"
#include "algorithm"

using namespace std;


///bit set de D dimenciones
template< int D, class H>
class node
{
public:
    bitset<D> entry;///nodo obtenido de get filita
    H  proximo ;

    node(){

    }

    node( bitset<D> cop )
    {
        entry = cop;
    }

    bool operator < (const node& P) const
    {
        for(int i = 0 ; i < D ;i++ ){
            if(this->entry[i] < P.entry[i]){

                return true;
            }
        }
        return false;
    }

    bool operator == (const node& P) const
    {
        for(int i = 0 ; i < D ;i++ ){
            //cout<<i;
            if(this->entry[i] != P.entry[i]){
                cout<<"flase"<<endl;
                return false;
            }
        return true;
        }
    }

};

///sobrecarga de <
//template<std::size_t N>
/*bool operator <(const std::bitset<N>& x, const std::bitset<N>& y)
{
    for (int i = N-1; i >= 0; i--) {
        if (x[i] ^ y[i]) return y[i];
    }
    return false;
}
*/
class Node_hyper
{
public:
    int nivel = 0;
    vector  < node<90,Node_hyper> > myvec  ;
    bool vacio = true;


    Node_hyper()
    {
        nivel = 0;
        vacio = true;
    }
    Node_hyper(int n_nivel)
    {
        nivel = n_nivel;
    }

    bool insert_NH (mdd<32> entry,int niv = 0)
    {

        if(niv < 32){
            //cout<<"aqui"<<endl;
        //cout<< entry.getfilita(niv)<<niv;
            //bitset<90> dato = entry.getfilita(nivel);
            //cout<<dato;

            cout<<entry.getfilita(niv)<<endl;
            node<90,Node_hyper> tem(entry.getfilita(niv));

            vector< node<90,Node_hyper> > ::iterator up;

            //low=std::lower_bound (v.begin(), v.end(), 'a'); //          ^
            up= upper_bound (myvec.begin(), myvec.end(), tem);

            cout<<" vacio: "<<!vacio<<endl;
            if( !vacio && ((*up) == tem) ){
                cout<<"caso 1";
                (*up).proximo.insert_NH(entry,niv+1);
                nivel = niv;
               //(*up)->proximo.insert_NH(entry,niv+1);
            }
            else{

              myvec.insert(up,tem);
              cout<<"caso 2";
              nivel = niv;
            (*up).proximo.insert_NH(entry,niv+1);
                return true;
            }
            //

        }else{
            return false;
        }


    }
};

template <int D>
class PH_tree
{
public:
    int dim = D;
    Node_hyper root;

    bool insert_PH(mdd<D> data)
    {
        if (root.insert_NH(data))
        {
            return true;
        }else{
            return false;
        }

    }
};

