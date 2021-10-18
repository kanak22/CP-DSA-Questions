// question link : https://leetcode.com/problems/map-sum-pairs/

// The problem can be solved using binary search :
/* 
    The approach is simple:
    Step 1: Whenever the insert command is called we insert the string into trie data structure
    Stpe 2: We insert the word such that the last character will store the value (counter) in the node so the whenever the word is complete the value can be retrived 
    Step 3: In keep insert the word and value in trie data structure.
    Step 4: In case sum command is called, we iterate the word through trie structure and calculate all the word from trie originating from that node
    Step 5: The sum of counter for all such words in result for sum command
*/

class MapSum {
    Node root;
    int count;

    /** Initialize your data structure here. */
    public MapSum() {
        root = new Node('\0');
        count = 0;
    }
    
    public void insert(String key, int val) {
        char[] carr = key.toCharArray();
        Node curr = root;
        for(char c: carr){
            if(curr.children[c - 'a'] == null){
                curr.children[c-'a'] =  new Node(c);
            }
            curr = curr.children[c - 'a'];
        }
        curr.counter = val;
    }
    
    public int sum(String prefix) {
        char[] ca = prefix.toCharArray();
        Node curr = root;
        for(char c: ca){
            if(curr.children[c - 'a'] == null) return 0;
            else curr = curr.children[c-'a'];
        }
        
        this.count  = 0;
        
        collect(curr);
        
        return this.count;
    }
    
    void collect(Node curr){
        if(curr == null) return;
        
        if(curr.counter > 0) this.count += curr.counter;
        
        for(int i=0;i<26;i++){
            if(curr.children[i] != null){
                collect(curr.children[i]);
            }
        }
    }
}

class Node {
    char c;
    Node[] children;
    int counter;
    
    Node(char c){
        this.c = c;
        this.children = new Node[26];
        this.counter = 0;
    }
}

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */
