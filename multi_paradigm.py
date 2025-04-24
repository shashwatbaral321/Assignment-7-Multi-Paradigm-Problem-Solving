### Python (Object-Oriented Approach)
import statistics
from collections import Counter

class StatisticsCalculator:
    def __init__(self, data):
        self.data = data

    def mean(self):
        return sum(self.data) / len(self.data)

    def median(self):
        return statistics.median(self.data)

    def mode(self):
        counts = Counter(self.data)
        max_count = max(counts.values())
        return [k for k, v in counts.items() if v == max_count]

# Sample usage
if __name__ == '__main__':
    numbers = [1, 2, 2, 3, 4, 5, 5, 5]
    calc = StatisticsCalculator(numbers)
    print("Mean:", calc.mean())
    print("Median:", calc.median())
    print("Mode:", calc.mode())
