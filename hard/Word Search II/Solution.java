class Solution {
    private Trie trie = new Trie();
    private TrieNode root = this.trie.getRoot();

    // Trie + DFS
    public List<String> findWords(char[][] board, String[] words) {
        HashSet<String> answer = new HashSet<>();
        List<String> ans = new ArrayList<>();
        
        for (String word : words) {
            this.trie.insert(word);
        }
        
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                dfs(board, answer, this.root, "", i, j);
            }
        }
        
        for (String wordFound : answer) {
            ans.add(wordFound);
        }
        
        return ans;
    }
    
    private void dfs(char[][] board, HashSet<String> answer, TrieNode currNode,
               String curr, int i, int j) {
        if (i < 0 || i >= board.length || j < 0 || j >= board[0].length 
            || board[i][j] == '.') return;
        
         if(currNode.getKthChildren(board[i][j]-'a') != null){
            curr = curr + board[i][j];
            TrieNode nextNode = currNode.getKthChildren(board[i][j] - 'a');
            
            if(nextNode.getIsWord()) answer.add(curr);
            
            char ch=board[i][j];
            board[i][j]='.';
             
            dfs(board, answer, nextNode, curr, i - 1, j);
            dfs(board, answer, nextNode, curr, i + 1, j);
            dfs(board, answer, nextNode, curr, i, j - 1);
            dfs(board, answer, nextNode, curr, i, j + 1);
             
            board[i][j] = ch;       
        }
    }
}

class Trie {
    private TrieNode node;

    public Trie() {
        this.node = new TrieNode(' ');
    }

    public TrieNode getRoot() {
        return this.node;
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