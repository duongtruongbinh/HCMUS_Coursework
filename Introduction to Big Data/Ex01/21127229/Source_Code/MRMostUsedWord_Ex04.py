
from mrjob.job import MRJob
from mrjob.step import MRStep
import re

WORD_RE = re.compile(r"[\w']+")

class MRMostUsedWord(MRJob):

    def steps(self):
        return [
            MRStep(mapper=self.mapper_get_words,
                   reducer=self.reducer_count_words),
            MRStep(reducer=self.reducer_find_max_word)
        ]

    def mapper_get_words(self, _, line):
        # Tách từ trong dòng
        for word in WORD_RE.findall(line):
            yield word.lower(), 1

    def reducer_count_words(self, word, counts):
        # Đếm số lần xuất hiện của từ
        yield None, (sum(counts), word)

    def reducer_find_max_word(self, _, word_count_pairs):
        # Tìm từ xuất hiện nhiều nhất
        yield max(word_count_pairs)

if __name__ == '__main__':
    MRMostUsedWord.run()
