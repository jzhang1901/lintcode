/* 132. Word Search II
Description

Given a matrix of lower alphabets and a dictionary. Find all words in the dictionary that can be found in the matrix. A word can start from any position in the matrix and go left/right/up/down to the adjacent position. 


Have you met this question in a real interview?  
Example

Given matrix:

doaf
agai
dcan

and dictionary:

{"dog", "dad", "dgdg", "can", "again"}


return {"dog", "dad", "can", "again"}


dog:

doaf
agai
dcan

dad:

doaf
agai
dcan

can:

doaf
agai
dcan

again:

doaf
agai
dcan

Challenge

Using trie to implement your algorithm.
*/

/**
* 本参考程序来自九章算法，由 @令狐冲 提供。版权所有，转发请注明出处。
* - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
* - 现有的面试培训课程包括：九章算法班，系统设计班，算法强化班，Java入门与基础算法班，Android 项目实战班，
* - Big Data 项目实战班，算法面试高频题班, 动态规划专题班
* - 更多详情请见官方网站：http://www.jiuzhang.com/?source=code
*/ 


// 使用 HashMap 的版本。
// 将所有的单词的 Prefix 都加入 HashMap 中。HashMap 的 value 用与判断这是一个 prefix 还是一个 word。
// 如果是 prefix 就是 false，如果是 word 就是 true.

public class Solution {
    public static int[] dx = {0, 1, -1, 0};
    public static int[] dy = {1, 0, 0, -1};
    /**
     * @param board: A list of lists of character
     * @param words: A list of string
     * @return: A list of string
     */
    public List<String> wordSearchII(char[][] board, List<String> words) {
        if (board == null || board.length == 0) {
            return new ArrayList<>();
        }
        if (board[0] == null || board[0].length == 0) {
            return new ArrayList<>();
        }
        
        boolean[][] visited = new boolean[board.length][board[0].length];
        Map<String, Boolean> prefixIsWord = getPrefixSet(words);
        Set<String> wordSet = new HashSet<>();
        
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length; j++) {
                visited[i][j] = true;
                dfs(board, visited, i, j, String.valueOf(board[i][j]), prefixIsWord, wordSet);
                visited[i][j] = false;
            }
        }
        
        return new ArrayList<String>(wordSet);
    }
    
    private Map<String, Boolean> getPrefixSet(List<String> words) {
        Map<String, Boolean> prefixIsWord = new HashMap<>();
        for (String word : words) {
            for (int i = 0; i < word.length() - 1; i++) {
                String prefix = word.substring(0, i + 1);
                if (!prefixIsWord.containsKey(prefix)) {
                    prefixIsWord.put(prefix, false);
                }
            }
            prefixIsWord.put(word, true);
        }
        
        return prefixIsWord;
    }
    
    private void dfs(char[][] board,
                     boolean[][] visited,
                     int x,
                     int y,
                     String word,
                     Map<String, Boolean> prefixIsWord,
                     Set<String> wordSet) {
        if (!prefixIsWord.containsKey(word)) {
            return;
        }
        
        if (prefixIsWord.get(word)) {
            wordSet.add(word);
        }
        
        for (int i = 0; i < 4; i++) {
            int adjX = x + dx[i];
            int adjY = y + dy[i];
            
            if (!inside(board, adjX, adjY) || visited[adjX][adjY]) {
                continue;
            }
            
            visited[adjX][adjY] = true;
            dfs(board, visited, adjX, adjY, word + board[adjX][adjY], prefixIsWord, wordSet);
            visited[adjX][adjY] = false;
        }
    }
    
    private boolean inside(char[][] board, int x, int y) {
        return x >= 0 && x < board.length && y >= 0 && y < board[0].length;
    }
}

//----------------------------------------------------------------------------------------------------
// 使用了 Trie 的版本

class TrieNode {
    String word;
    HashMap<Character, TrieNode> children;
    public TrieNode() {
        word = null;
        children = new HashMap<Character, TrieNode>();
    }
};


class TrieTree{
    TrieNode root;
    
    public TrieTree(TrieNode TrieNode) {
        root = TrieNode;
    }
    
    public void insert(String word) {
        TrieNode node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node.children.containsKey(word.charAt(i))) {
                node.children.put(word.charAt(i), new TrieNode());
            }
            node = node.children.get(word.charAt(i));
        }
        node.word = word;
    }
};

public class Solution {
    /**
     * @param board: A list of lists of character
     * @param words: A list of string
     * @return: A list of string
     */
    public int[] dx = {1, 0, -1, 0};
    public int[] dy = {0, 1, 0, -1};
    
    public void search(char[][] board,
                       int x,
                       int y,
                       TrieNode root,
                       List<String> results) {
        if (!root.children.containsKey(board[x][y])) {
            return;
        }
        
        TrieNode child = root.children.get(board[x][y]);
        
        if (child.word != null) {
            if (!results.contains(child.word)) {
                results.add(child.word);
            }
        }
        
        char tmp = board[x][y];
        board[x][y] = 0;  // mark board[x][y] as used
        
        for (int i = 0; i < 4; i++) {
            if (!isValid(board, x + dx[i], y + dy[i])) {
                continue;
            }
            search(board, x + dx[i], y + dy[i], child, results);
        }
        
        board[x][y] = tmp;  // revert the mark
    }
    
    private boolean isValid(char[][] board, int x, int y) {
        if (x < 0 || x >= board.length || y < 0 || y >= board[0].length) {
            return false;
        }
        
        return board[x][y] != 0;
    }
    
    public List<String> wordSearchII(char[][] board, List<String> words) {
        List<String> results = new ArrayList<String>();
        
        TrieTree tree = new TrieTree(new TrieNode());
        for (String word : words){
            tree.insert(word);
        }
        
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length; j++) {
                search(board, i, j, tree.root, results);
            }
        }
        
        return results;
    }
}