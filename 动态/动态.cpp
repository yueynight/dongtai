#include <iostream>
using namespace std;
struct thing{
    string name;
    int weight;
    int value;
    thing(string n, int w, int v) {
        name = n;
        weight = w;
        value = v;
    }
    thing() {
        name = "";
        weight = 0;
        value = 0;
    }
};
int backpackquestion(int backpack, thing *things, int thingnums) {
    
    int minWeight = things[0].weight;

    for (int i = 1; i < thingnums; ++i)
    {
        int curWeight = things[i].weight;
        if (curWeight < minWeight) {
            minWeight = curWeight;
        }
    }
cout<<"   1 2  3  4  5  6";
    if (backpack < minWeight) {
        cout << "��������С����Ʒ��С�������޷����� " <<endl;
        return -1;
    }


    int weightCount = backpack+1;
    int** dpArray = new int*[thingnums]();
    for (int i = 0; i < thingnums; ++i) {
        dpArray[i] = new int[weightCount];
    }

    for (int i = 0; i <thingnums; ++i)
    {     cout<<endl<<i+1<<"  ";
        int curWeight = things[i].weight;
        int curValue = things[i].value;
        for (int w = minWeight; w < weightCount; ++w)
        {
            int preTotalValue= 0;

            if (i > 0) {
                preTotalValue = dpArray[i - 1][w];
            }

            int curTotalValue = 0;

            if (w >= curWeight){
                curTotalValue = curValue;
            }

            if ( w > curWeight && i > 0 ) {
                curTotalValue += dpArray[i-1][w - curWeight];
            }
      
            int maxTotalValue = preTotalValue;

            if (maxTotalValue < curTotalValue) {
                maxTotalValue = curTotalValue;
            }

            dpArray[i][w] = maxTotalValue;
            cout<<dpArray[i][w]<<" ";

        }    
      
    }

    int maxValue = dpArray[thingnums  - 1][weightCount - 1];

    for (int i = 0; i < thingnums; ++i) {
        delete [] dpArray[i];
    }
    delete [] dpArray;
    return maxValue;
}

int main() {
    int backpack = 6;
    thing things[] = {     
        thing("ˮ", 3, 10),
        thing("��", 1, 3),
        thing("ʳ��", 2, 9),
        thing("�п�", 2, 5),
		thing("���", 1, 6)
    };
    int thingnums = sizeof(things)/sizeof(thing);
    int maxValue = 0;
    maxValue = backpackquestion(backpack, things, thingnums);
    cout<<endl<<endl<<"��Ϊ��Ʒ��ѡ�����࣬��Ϊ��������";
        cout <<endl<< "��������Ϊ"<<backpack<<"ʱ,"<<"����ֵΪ��" << maxValue << endl;  
}
