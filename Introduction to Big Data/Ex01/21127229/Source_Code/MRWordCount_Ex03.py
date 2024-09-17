
from mrjob.job import MRJob
import re

WORD_RE = re.compile(r"[\w']+")

class MRWordCount(MRJob):

    def mapper(self, _, line):
        # Tách các từ trong dòng (không phân biệt hoa thường)
        for word in WORD_RE.findall(line):
            yield word, 1  # Trường hợp phân biệt hoa thường (Câu a)
            yield word.lower(), 1  # Không phân biệt hoa thường (Câu b)

    def reducer(self, word, counts):
        # Tính tổng số lần xuất hiện của mỗi từ
        yield word, sum(counts)

if __name__ == '__main__':
    MRWordCount.run()
