from collections import deque, defaultdict

def ladder_length(beginWord: str, endWord: str, wordList: list) -> int:
    if endWord not in wordList:
        return 0
    L = len(beginWord)
    all_combo = defaultdict(list)
    for word in wordList:
        for i in range(L):
            all_combo[word[:i] + "*" + word[i+1:]].append(word)
    q = deque([(beginWord, 1)])
    visited = {beginWord}
    while q:
        word, level = q.popleft()
        for i in range(L):
            pattern = word[:i] + "*" + word[i+1:]
            for next_word in all_combo.get(pattern, []):
                if next_word == endWord:
                    return level + 1
                if next_word not in visited:
                    visited.add(next_word)
                    q.append((next_word, level + 1))
            all_combo[pattern] = []  # avoid revisiting pattern
    return 0

# Example
print(ladder_length("hit", "cog", ["hot","dot","dog","lot","log","cog"]))  # 5
