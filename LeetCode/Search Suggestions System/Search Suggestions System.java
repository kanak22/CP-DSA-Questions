class Solution {
    Node root; // class variable root
    public List<List<String>> suggestedProducts(String[] products, String searchWord) {
        root = new Node('\0');
        
// iterating all string and inserting into trie data structure using insert method
        for(String s: products){
            insert(s);
        }
        
        List<List<String>> list_list = new ArrayList<>();
        
        char[] carr = searchWord.toCharArray();
        int index = 0;
        Node curr = root;
        String str = "";
        
//iterating through trie elements
        while(index < carr.length){
            char cc = carr[index];
            List<String> list = new ArrayList<>(); index++;
            if(curr != null){
                curr = curr.children[cc - 'a'];
                get_three(curr, searchWord.substring(0, index), list);
            }
            list_list.add(list);
        }
        return list_list;
    }
    
    //insert string in the trie data structure for optimal iteration
    void insert(String string){
        Node curr = this.root;
        for(Character ca: string.toCharArray()){
            if(curr.children[ca - 'a'] == null)
                curr.children[ca - 'a'] = new Node(ca);
            curr = curr.children[ca - 'a'];
        }
        curr.isWord = true;
    }
    
    void get_three(Node curr, String str, List<String> list){
        if(curr == null || list.size() == 3) return;
        
        if(curr.isWord) list.add(str);
        if(list.size() == 3) return;

        for(int i=0;i<26;i++){
            if(curr.children[i] != null)
                get_three(curr.children[i], str.concat(String.valueOf((char)(i + 'a'))), list);
        }
    }
}

// class for Node creation
// is word will be true if there is any word which ends at that Node

class Node {
    char c;
    Node[] children;
    boolean isWord;
    
    Node(char c){
        this.c = c;
        this.children = new Node[26];
        this.isWord = false;
    }
}
