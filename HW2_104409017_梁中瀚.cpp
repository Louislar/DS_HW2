#include<iostream>
#include<ctype.h>
#include<stdio.h>
#include<fstream>

using namespace std;

class e{
public:
    e();
    e(int r, int c, int v);
    int row;
    int column;
    int value;

};

e::e()
{
    row=0;
    column=0;
    value=0;
}

e::e(int r, int c, int v){
        row=r;
        column=c;
        value=v;
}

/*int input(e a[]) // '0' is 48 in ascii
{
    {
        int i=0;
        int r=0;
        int c=0;
        char temp;
        while(cin.get(temp))
        {
            if(temp==EOF)
                break;
            if(temp==' ')
                continue;
            if(temp=='|')
                break;
            if(temp=='\n')
            {
                r++;
                c=0;
                continue;
            }
            int intTemp=temp-48;
            if(intTemp==0)
            {
                c++;
                continue;
            }
            e eTemp=e(r, c, intTemp);
            a[i]=eTemp;
            c++;
            i++;
        }//while end
        return i;
    }
}*/

int matrixMultiply(e a[], int aLength, e b[], int bLength, e c[], int cLength)
{
    {
        int ATop=0;
        int ARear=0;
        while(ARear<aLength&&ATop<aLength)
        {
            for(int i=ATop;i<aLength-1;i++)
            {
                if(a[i].row==a[i+1].row)
                {
                    ARear++;
                }
                if(a[i].row!=a[i+1].row)
                {
                    break;
                }
            }// for end
            int bTop=0;
            int bRear=0;
            while(bTop<bLength&&bRear<bLength)
            {
                for(int j=bTop;j<bLength-1;j++)
                {
                    if(b[j].row==b[j+1].row)
                    {
                        bRear++;
                    }
                    if(b[j].row!=b[j+1].row)
                    {

                        break;
                    }
                }
                int sum=0;
                for(int j=bTop;j<bRear+1;j++)
                {
                    for(int l=ATop;l<ARear+1;l++)
                    {
                        if(a[l].column==b[j].column)
                        {
                            sum=sum+(a[l].value*b[j].value);
                        }
                    }
                }//for end
                if(sum!=0){
                c[cLength]=e(a[ATop].row, b[bTop].row, sum);
                cLength++;
                }
                bTop=bRear+1;
                bRear=bRear+1;
            }//while end, go through b[]
            ATop=ARear+1;
            ARear=ARear+1;
        }//while end, go through a[]
    }
    return cLength;
}

void matrixTranspose(e a[],const int aLength)
{
    e b[100];
    int columnNum[100]={0}; //How many elements are in each column
    int transPos[100]={0};  //
    int columnNumLength=0;

    for(int i=0;i<aLength;i++)
    {
        columnNum[a[i].column]++;
        columnNumLength++;
    }

    /*for(int i=0;i<columnNumLength;i++) //test
    {
        cout<<"\n"<<columnNum[i];
    }*/

    int sum=0;
    for(int i=0;i<columnNumLength;i++)
    {
        transPos[i]=sum;
        sum=sum+columnNum[i];
    }

    /*for(int i=0;i<columnNumLength;i++) //test
    {
        cout<<"\n"<<transPos[i];
    }*/

    for(int i=0;i<aLength;i++)
    {
        b[transPos[a[i].column]]=a[i];
        {
            int temp=b[transPos[a[i].column]].column;
            b[transPos[a[i].column]].column=b[transPos[a[i].column]].row;
            b[transPos[a[i].column]].row=temp;
        }
        transPos[a[i].column]++;
    }

    for(int i=0;i<aLength;i++)
    {
        a[i]=b[i];
    }

    /*for(int i=0;i<aLength;i++) //test
    {
        cout<<"\n"<<a[i].row;
    }*/

}

int main()
{
    e a[100];
    e b[100];
    e c[100];
    int aLength;
    int bLength;
    int cLength=0;
    //input
    ifstream ifs;
    ifs.open("input1-1.txt", ios::in);

    {
        int i=0;
        int r=0;
        int c=0;
        char temp;
        while(ifs.get(temp))
        {
            if(temp==EOF)
                break;
            if(temp==' ')
                continue;
            if(temp=='|')
                break;
            if(temp=='\n')
            {
                r++;
                c=0;
                continue;
            }
            int intTemp=temp-48;
            if(intTemp==0)
            {
                c++;
                continue;
            }
            e eTemp=e(r, c, intTemp);
            a[i]=eTemp;
            c++;
            i++;
        }//while end
        aLength=i;
    }

    {
        int i=0;
        int r=0;
        int c=0;
        char temp;
        while(ifs.get(temp))
        {
            if(temp==EOF)
                break;
            if(temp==' ')
                continue;
            if(temp=='|')
                break;
            if(temp=='\n')
            {
                r++;
                c=0;
                continue;
            }
            int intTemp=temp-48;
            if(intTemp==0)
            {
                c++;
                continue;
            }
            e eTemp=e(r, c, intTemp);
            b[i]=eTemp;
            c++;
            i++;
        }//while end
        bLength=i;
    }
    //input end

    //aLength=input(a);
    //bLength=input(b);
    for(int i=0;i<bLength;i++) b[i].row--;
    matrixTranspose(b, bLength);
    cLength=matrixMultiply(a, aLength, b, bLength, c, cLength);
    for(int i=0;i<cLength;i++)
    {
        cout<<"\n"<<c[i].row<<" "<<c[i].column<<" "<<c[i].value;
    }


}
