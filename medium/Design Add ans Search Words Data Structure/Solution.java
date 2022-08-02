class WordDictionary {
    private WordDictionary[] children;
    private boolean isWord;
    
    public WordDictionary() {
        this.children = new WordDictionary[26];
    }
    
    public void addWord(String word) {
        WordDictionary curr = this;
        
        for (int i = 0; i < word.length(); i++) {
            char c = word.charAt(i);
            
            if (curr.children[c - 'a'] == null) {
                curr.children[c - 'a'] = new WordDictionary();
            }
            
            curr = curr.children[c - 'a'];
        }
        
        curr.isWord = true;
    }
    
    public boolean search(String word) {
        WordDictionary curr = this;
        
        for (int i = 0; i < word.length(); i++) {
            char c = word.charAt(i);
            
            if (c == '.') {
                for (int j = 0; j < 26; j++) {
                    if (curr.children[j] != null && 
                        curr.children[j].search(word.substring(i + 1))) {
                        return true;
                    }
                }
                
                return false;
            }
            
            if (curr.children[c - 'a'] == null) {
                return false;
            }
            
            curr = curr.children[c - 'a'];
        }
        
        return curr.isWord;
    }
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * boolean param_2 = obj.search(word);
 */