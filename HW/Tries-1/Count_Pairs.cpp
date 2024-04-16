class Trie{
    private:
        struct Node{
            Node* links[2];
            int cnt = 0;
            bool containsKey(int bit){
                return links[bit];
            }
            Node* get(int bit){
                return links[bit];
            }
            void put(int bit, Node* node){
                links[bit] = node;
            }

            void increaseCount(){
                cnt++;
            }

            void decreaseCount(){
                cnt--;
            }

            int count(){
                return cnt;
            }
        };
        Node* root;
    public:
        Trie(){
            root = new Node();
        }
        void insert(int num){
            Node* node = root;
            for(int i=20; i>=0; i--){
                int bit = (num >> i) & 1;
                if(!node -> containsKey(bit)) node -> put(bit, new Node());
                node = node -> get(bit);
                node -> increaseCount();
            }
        }

        int getCount(int num, int range){
            int cnt = 0;
            Node* node = root;
            for(int i=20; i>=0; i--){
                if(range & (1 << i)){
                    int bit = (num >> i) & 1;
                    if(node -> containsKey(bit)) cnt += node -> get(bit) -> count();
                    if(!node -> containsKey(1 - bit)) return cnt;
                    node = node -> get(1 - bit);
                }else{
                    int bit = (num >> i) & 1;
                    if(!node -> containsKey(bit)) return cnt;
                    node = node -> get(bit);
                }
            }
            cnt += node -> count();
            return cnt;
        }
    
        void deleteNode(int num){
            Node* node = root;
            for(int i=20; i>=0; i--){
                int bit = (num >> i) & 1;
                node = node -> get(bit);
                node -> decreaseCount();
            }
        }
};
class Solution {
public:
    int countPairs(vector<int>& nums, int low, int high) {
        Trie trie;
        for(auto it: nums) trie.insert(it);
        int ans = 0;
        for(auto it: nums){
            ans += trie.getCount(it, high) - trie.getCount(it, low-1);
            trie.deleteNode(it);
        }
        return ans;
    }
};