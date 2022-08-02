class Trie {
    private TrieNode node;
    
    public Trie() {
        this.node = new TrieNode(' ');
    }
    
    public void insert(String word) {
        TrieNode curr = this.node;
        
        for (int i = 0; i < word.length(); i++) {
            char ch = word.charAt(i);
            
            if (curr.getKthChildren(ch - 'a') == null) {
                curr.setKthChildren(ch - 'a', ch);
            }
            
            curr = curr.getKthChildren(ch - 'a');
        }
        
        curr.setWord();
    }
    
    public boolean search(String word) {
        TrieNode curr = this.node;
        
        for (int i = 0; i < word.length(); i++) {
            char ch = word.charAt(i);
            
            if (curr.getKthChildren(ch - 'a') == null) {
                return false;
            }
            
            curr = curr.getKthChildren(ch - 'a');
        }
        
        return curr.getIsWord();
    }
    
    public boolean startsWith(String prefix) {
        TrieNode curr = this.node;
        
        for (int i = 0; i < prefix.length(); i++) {
            char ch = prefix.charAt(i);
            
            if (curr.getKthChildren(ch - 'a') == null) {
                return false;
            }
            
            curr = curr.getKthChildren(ch - 'a');
        }
        
        return true;
    }
}

class TrieNode {
    private char ch;
    private TrieNode[] children = new TrieNode[26];
    private boolean isWord = false;
    
    public TrieNode(char ch) {
        this.ch = ch;
    }
    
    public TrieNode getKthChildren(int k) {
        return this.children[k];
    }
    
    public void setKthChildren(int k, char c) {
        this.children[k] = new TrieNode(c);
    }
    
    public boolean getIsWord() {
        return this.isWord;
    }
    
    public void setWord() {
        this.isWord = true;
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */