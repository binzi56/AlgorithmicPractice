#  LFU缓存

请你为 最不经常使用（LFU）缓存算法设计并实现数据结构。它应该支持以下操作：get 和 put。

get(key) - 如果键存在于缓存中，则获取键的值（总是正数），否则返回 -1。
put(key, value) - 如果键已存在，则变更其值；如果键不存在，请插入键值对。当缓存达到其容量时，则应该在插入新项之前，使最不经常使用的项无效。在此问题中，当存在平局（即两个或更多个键具有相同使用频率）时，应该去除最久未使用的键。
「项的使用次数」就是自插入该项以来对其调用 get 和 put 函数的次数之和。使用次数会在对应项被移除后置为 0 。


进阶：
你是否可以在 O(1) 时间复杂度内执行两项操作？

示例：
```
LFUCache cache = new LFUCache( 2 /* capacity (缓存容量) */ );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // 返回 1
cache.put(3, 3);    // 去除 key 2
cache.get(2);       // 返回 -1 (未找到key 2)
cache.get(3);       // 返回 3
cache.put(4, 4);    // 去除 key 1
cache.get(1);       // 返回 -1 (未找到 key 1)
cache.get(3);       // 返回 3
cache.get(4);       // 返回 4
```

解法：
```
struct Node {
    int count, time, key, value;
    Node(int _count, int _time, int _key, int _value):count(_count),time(_time),key(_key), value(_value){}
    bool operator < (const Node& temp) const{
        return count == temp.count ? time < temp.time : count < temp.count;
    }
};

class LFUCache {
    int cap, time; //缓存容量，时间戳
    unordered_map<int, Node> key_table;
    set<Node> S;
public:
    LFUCache(int capacity) {
       cap = capacity;
       time = 0;
       key_table.clear();
       S.clear();
    }
    
    int get(int key) {
       if(cap == 0) return -1;
       auto it = key_table.find(key);
       if(it == key_table.end()) return -1; //如果哈希表中没有键 key，返回 -1
       Node cache = it->second;             //从哈希表中得到旧的缓存
       S.erase(cache);                      //从平衡二叉树中删除旧的缓存
       cache.count++;                       //将旧缓存更新
       cache.time = ++time;
       S.insert(cache);                     //将新缓存重新放入哈希表和平衡二叉树中
       it->second = cache;
       return cache.value;
    }
    
    void put(int key, int value) {
        if(cap == 0) return;
        auto it = key_table.find(key);
        if(it == key_table.end()){
            if(cap == key_table.size()){     //如果到达缓存容量上限 
                key_table.erase(S.begin()->key);  //从哈希表和平衡二叉树中删除最近最少使用的缓存
                S.erase(S.begin());
            }

            Node cache = Node(1, ++time, key, value);  //创建新的缓存
            key_table.insert(make_pair(key, cache));   //将新缓存放入哈希表和平衡二叉树中
            S.insert(cache);
        }else{
            //类比get
            Node cache = it->second;
            S.erase(cache);
            cache.count++;
            cache.time = ++time;
            cache.value = value;
            S.insert(cache);
            it->second = cache;
        }
    }
};
```
