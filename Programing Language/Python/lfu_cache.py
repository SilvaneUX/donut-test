from collections import defaultdict, OrderedDict

class LFUCache:
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.key_to_val = {}
        self.key_to_freq = {}
        self.freq_to_keys = defaultdict(OrderedDict)
        self.min_freq = 0

    def _update_freq(self, key):
        freq = self.key_to_freq[key]
        val = self.key_to_val[key]
        # remove from current freq
        del self.freq_to_keys[freq][key]
        if not self.freq_to_keys[freq]:
            del self.freq_to_keys[freq]
            if freq == self.min_freq:
                self.min_freq += 1
        # add to next freq
        self.key_to_freq[key] = freq + 1
        self.freq_to_keys[freq+1][key] = True

    def get(self, key: int) -> int:
        if key not in self.key_to_val:
            return -1
        self._update_freq(key)
        return self.key_to_val[key]

    def put(self, key: int, value: int) -> None:
        if self.capacity == 0:
            return
        if key in self.key_to_val:
            self.key_to_val[key] = value
            self._update_freq(key)
            return
        if len(self.key_to_val) >= self.capacity:
            # evict least freq and oldest key among them
            k, _ = self.freq_to_keys[self.min_freq].popitem(last=False)
            del self.key_to_val[k]
            del self.key_to_freq[k]
            if not self.freq_to_keys[self.min_freq]:
                del self.freq_to_keys[self.min_freq]
        # insert new key
        self.key_to_val[key] = value
        self.key_to_freq[key] = 1
        self.freq_to_keys[1][key] = True
        self.min_freq = 1

# Example usage
cache = LFUCache(2)
cache.put(1, 1)
cache.put(2, 2)
print(cache.get(1))  # 1
cache.put(3, 3)      # evicts key 2
print(cache.get(2))  # -1
print(cache.get(3))  # 3
