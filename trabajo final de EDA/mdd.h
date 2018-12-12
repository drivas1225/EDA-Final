///mdd(multi dimensional dato)
#include <iostream>
#include <bitset>
#include <stdlib.h>


using namespace std;

bitset<32> convertir( string value){

    union
    {
         float input;   // assumes sizeof(float) == sizeof(int)
         int   output;
    }    data;

    data.input = strtof((value).c_str(),0) ; //value;

    bitset<sizeof(float) * CHAR_BIT>   bits(data.output);

    //string mystring = bits.to_string<char,char_traits<char>,allocator<char> >();

    return bits;


  }


    bitset<90> operator+(bitset<90> a,bitset<90> b) {
        int carry=0;
        bitset <90> bc;
        int i=0;
        while (i<=89) {
            if(i!=0) {
                bc[i]=(a[i]+b[i]+carry)%2;
            }else{
                bc[i]=(a[i]+b[i])%2;
            }
            if((a[i]+b[i]+carry)>1)
                carry=1;
            else
                carry=0;
            i++;
        }
        return bc;
    }

    bitset<90> operator*(bitset<90> a,bitset<90> b)
    {
        vector < bitset<90> > v;
        int c=0;
        bitset<90> bcm;
        for(int i=0;i<90;i++){

            bitset<90> bcm1;
            if(v.size()<2){
                    if(b[i]==1){
                        v.push_back(a<<c);
                    }else{
                        v.push_back(bcm1<<c);
                    }
            }

            if(v.size()==2){
                    bcm1=v[0]+v[1];
                    v.clear();
                    v.push_back(bcm1);
                    cout<<v[0]<<endl;
                    bcm=bcm1;
            }
            c++;
        }

        return bcm;
    }

template<int D>
struct mdd{

	vector< bitset<32> > vec_bit;

	bitset<90> getfilita(int pos)
	{

        bitset<90> ret;
	    for(int i = 0; i < 90;i++)
        {
            ret[i]=vec_bit[i][pos];
        }
        return ret;
	}

};

