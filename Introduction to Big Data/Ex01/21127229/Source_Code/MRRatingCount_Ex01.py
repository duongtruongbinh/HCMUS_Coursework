
from mrjob.job import MRJob

class MRRatingCount(MRJob):
    def mapper(self, _, line):
        # Tách dòng dữ liệu theo định dạng 'user_id item_id rating timestamp'
        _, _, rating, _ = line.split('\t')
        yield rating, 1

    def reducer(self, rating, counts):
        # Tính tổng số lượt bình chọn cho mỗi mức đánh giá
        yield rating, sum(counts)

if __name__ == '__main__':
    MRRatingCount.run()
