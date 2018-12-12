#include <iostream>
#include <vector>
#include <set>
#include <stdlib.h>
#include "mdd.h"

#define PROF 32
#define DIM 90

using namespace std;
///bit set de D dimenciones


class node2
{
public:

    int nivel;
    bitset<DIM> name; /// se obtiede de getfilita
    set<node2> * ptrVN = nullptr; /// puntero a el siguiente hypercubo

    node2(bitset<DIM> vec,int n_nivel ){
        name = vec;
        nivel = n_nivel;
    };

    bool operator < (const node2& P) const
    {

        for(int i = 0 ; i < DIM ;i++ ){
            if(this->name[i] < P.name[i]){

                return true;
            }

        }

        return false;
    }

    bool operator == (const node2& P) const
    {
        for(int i = 0 ; i < DIM ;i++ ){
            //cout<<i;
            if(this->name[i] != P.name[i]){

                return false;
            }
            return true;
        }
        return true;
    }

};

class phtree
{
public:

    set<node2> root;
    int cant_datos = 0;

    phtree(){
        cant_datos = 0;
    }

    pair<std::set<node2>::iterator,bool> buscarInH(node2 s, set<node2> f){

        cout<<"entro";
        pair<std::set<node2>::iterator,bool> p;
        set<node2>::iterator iter = f.begin();

        while( (iter != f.end()) && (s < *iter) ){
            iter++;

        }
        p.first = iter;
        if(s == *iter){
            p.second = true;
            return p;

        }

        p.second = false;
        return p;
    }

    bool insertar( mdd<DIM> datos , set<node2> * ptrmyvec){




	 	/*for(int nivel = 0 ; nivel < PROF ; nivel++){
            cout<<"hola";
            node2 * ptrN = new node2(datos.getfilita(nivel),nivel);
            ptrmyvec->find(*ptrN);

            if (*ptrN == *it){
                ptrmyvec = it->ptrVN;
            }else{
                ptrN->ptrVN = new set<node2>;
                auto p_ret= ptrmyvec->insert(*ptrN);
                ptrmyvec = p_ret.first->ptrVN;
            }*/
            /*
            ptrN->ptrVN = new set<node2>;

            auto p_ret= ptrmyvec->insert(*ptrN);
            ptrmyvec = p_ret.first->ptrVN;
            */

        node2 * ptrN;
	 	for(int nivel = 0 ; nivel < PROF ; nivel++){
            ptrN = new node2(datos.getfilita(nivel),nivel);
            if(!(ptrN->ptrVN)){
                    ptrN->ptrVN = new set<node2>;
            }
            auto p_ret= ptrmyvec->insert(*ptrN);
            if(p_ret.second  == true){
                ptrmyvec = p_ret.first->ptrVN;
            }else{
                ptrmyvec = ptrN->ptrVN;
            }

            delete(ptrN);
            //cout<<root.size()<<" ";
        }

        cant_datos++;

        return true;
	}



	bool buscar( mdd<DIM> datos, set<node2> * ptrmyvec ){
        node2 * ptrN;
        bool ret = false;

        for(int nivel = 0 ; nivel < PROF ; nivel++){
            ptrN = new node2(datos.getfilita(nivel),nivel);

            for(auto i = (*ptrmyvec).begin() ; i != (*ptrmyvec).end() ; i ++){
                if( *i == *ptrN ){
                    ret = true;
                    ptrmyvec = i->ptrVN;
                    break;
                }
            }

            if(ret == false){
                return false;
            }
            //trmyvec = ptrmyvec->insert(*ptrN).first->ptrVN;
        }

        return ret;

	}

	double distancia( mdd<DIM> x,mdd<DIM> y ){


	}

    void knn( mdd<DIM> datos, set<node2> * ptrmyvec, int k){

            if(cant_datos<k){
                view_tree(*ptrmyvec);
                return;
            }
             node2 * ptrN;
             vector<std::set<node2>::iterator> res;
             vector< node2* > aux;
            for(int nivel = 0 ; nivel < PROF ; nivel++){
                ptrN = new node2(datos.getfilita(nivel),nivel);
                aux.push_back(ptrN);
                res.push_back( ptrmyvec->find(*ptrN) );
                ptrmyvec = res[nivel]->ptrVN;
            }

            for(int i = res.size()-1 ; i >= 0 ;i--){
                res[i]->name;
            }

        }


	void view_tree(set<node2> x ,int prof = 0){

        if(prof>=PROF){
            for(auto iter=x.begin(); iter!=x.end();++iter)  {
                std::cout << (*iter).name << "  ";
            }
            return;
        }
        else {

            for(auto iter=x.begin(); iter!=x.end();++iter)  {
                std::cout << (*iter).name << "  ";
                view_tree( (*(*iter).ptrVN) ,prof + 1);

            }
            //cout<<"aqui: "<<prof<<endl;
            //view_tree( (*(*iter).ptrVN) ,prof + 1);

        }

	}

	void view_tree_amp(set<node2> x ,int prof = 0){

        if(prof>=PROF){
            for(auto iter=x.begin(); iter!=x.end();++iter)  {
                std::cout << (*iter).name << "  ";
            }
            return;
        }
        else {

            for(auto iter=x.begin(); iter!=x.end();++iter)  {
                std::cout << (*iter).name << "  ";

            }

            for(auto iter=x.begin(); iter!=x.end();++iter)  {
                view_tree( (*(*iter).ptrVN) ,prof + 1);

            }
            //cout<<"aqui: "<<prof<<endl;
            //view_tree( (*(*iter).ptrVN) ,prof + 1);

        }

	}

    void view_hp(set<node2> x ){


            for(auto iter=x.begin(); iter!=x.end();++iter)  {
                std::cout << (*iter).name << "  ";
            }


	}


};
