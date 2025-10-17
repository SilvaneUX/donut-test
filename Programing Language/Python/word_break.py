def word_break_all(s: str, wordDict: list) -> list:
    wordset = set(wordDict)
    n = len(s)
    memo = {}

    def dfs(start):
        if start in memo:
            return memo[start]
        if start == n:
            return [""]
        res = []
        for end in range(start+1, n+1):
            pref = s[start:end]
            if pref in wordset:
                for tail in dfs(end):
                    if tail:
                        res.append(pref + " " + tail)
                    else:
                        res.append(pref)
        memo[start] = res
        return res

    return dfs(0)

# Example
print(word_break_all("catsanddog", ["cat","cats","and","sand","dog"]))
# ["cats and dog", "cat sand dog"]
