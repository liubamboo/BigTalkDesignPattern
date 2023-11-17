#include <iostream>
#include <memory>

#include "delegateNonParams.h"
#include "mainObserver.h"
#include "mainSubject.h"

using namespace std;

int main()
{
    shared_ptr<CBoss> boss(new CBoss);
    // shared_ptr的get方法用于获取原始指针
    shared_ptr<CStockObserver> stock(new CStockObserver(boss.get(), "lisi"));
    shared_ptr<CNBAObserver> nba(new CNBAObserver(boss.get(), "zhangsan"));

    // shared_ptr<IDelegateAgent<CStockObserver>> stockAgent(new IDelegateAgent<CStockObserver>(stock.get(), 
    //     &CStockObserver::CloseMarket));
    shared_ptr<IDelegateAgent<CStockObserver> > stockAgent = make_shared<IDelegateAgent<CStockObserver> >(stock.get(), 
        &CStockObserver::CloseMarket);
    // shared_ptr<IDelegateAgent<CNBAObserver>> nbaAgent(new IDelegateAgent<CNBAObserver>(nba.get(), 
    //     &CNBAObserver::CloseNBA));
    shared_ptr<IDelegateAgent<CNBAObserver> > nbaAgent = make_shared<IDelegateAgent<CNBAObserver> >(nba.get(),
        &CNBAObserver::CloseNBA);

    boss->Event += stockAgent.get();
    boss->Event += nbaAgent.get();

    boss->State("老子回来了，小的们准备接风酒啊");
    boss->Notify();

    return 0;
}

