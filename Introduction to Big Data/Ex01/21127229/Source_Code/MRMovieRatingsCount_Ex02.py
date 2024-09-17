
from mrjob.job import MRJob
from mrjob.step import MRStep

class MRMovieRatingsCount(MRJob):

    def steps(self):
        return [
            MRStep(mapper=self.mapper_get_ratings,
                   reducer=self.reducer_count_ratings),
            MRStep(reducer=self.reducer_sort_by_ratings)
        ]

    def mapper_get_ratings(self, _, line):
        # Tách dòng dữ liệu theo định dạng 'user_id item_id rating timestamp'
        _, movie_id, _, _ = line.split('\t')
        yield movie_id, 1

    def reducer_count_ratings(self, movie_id, counts):
        # Tính tổng số lượt bình chọn cho mỗi bộ phim
        yield None, (sum(counts), movie_id)

    def reducer_sort_by_ratings(self, _, movie_counts):
        # Sắp xếp phim theo số lượt bình chọn và xuất kết quả
        for count, movie_id in sorted(movie_counts, reverse=True):
            yield movie_id, count

if __name__ == '__main__':
    MRMovieRatingsCount.run()
