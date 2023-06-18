#include "splithtable.h"


void SplitHTable::splitKeys(HTable<int>& one, HTable<int>& two)
{
    for(int i=-50;i<51;i++)
    {
        if(search(i))
        {
            stack<int>& stackbuf = table[hash(i)];
            while(!table[hash(i)].empty())
            {
                int current = stackbuf.pop();
                if(current>=0)
                {
                    one.insert(current);
                }
                else
                {
                    two.insert(current);
                }
            }
        }
    }
}
