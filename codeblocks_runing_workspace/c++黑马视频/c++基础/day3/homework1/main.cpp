#include <iostream>

using namespace std;
class Goods
{
public:
    Goods *next;
    Goods()
    {
        weight = 0;
        total_weight += weight;
        next = 0;
    }
    Goods(int weight)
    {
        this->weight = weight;
        total_weight += weight;
        next = NULL;
    }
    int get_weight()
    {
        return weight;
    }
    static int get_total_weight()
    {
        return total_weight;
    }
    ~Goods()
    {
        total_weight -= weight;
    }
private:
    static int total_weight;
    int weight;
};

void buy(Goods* &head,int weight)
{
    Goods *new_goods = new Goods(weight);
    cout << "这次进货了" << weight << endl;
    if(head == 0){
        head = new_goods;
    }
    else{
        new_goods->next = head;
        head = new_goods;
    }
}

void sale(Goods* &head)
{
    if(head == 0){
        cout << "已经没有货物了!" << endl;
    }
    else{

        Goods* temp;
        temp = head;
        cout << "出货了:" << head->get_weight() << endl;
        head = head->next;
        delete temp;
    }
}

int Goods::total_weight = 0;

int main()
{
    Goods *head =0;
    do{
        cout<<"1.进货"<< endl;
        cout << "2.出货"<< endl;
        cout << "3.退出" << endl;
        int choice;
        cin >> choice;
        switch(choice)
        {
        case 1:
            cout << "请输入进货的重量:";
            int weight;
            cin >> weight;
            buy(head,weight);
            break;
        case 2:
            sale(head);
            break;
        case 3:
            return 0;
        }
        cout << "货物一共还有"<< Goods::get_total_weight() << endl;
    }while(1);
    return 0;
}
