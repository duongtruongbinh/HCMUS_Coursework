from pyspark.sql import SparkSession
from pyspark.sql.functions import col

# Khởi tạo Spark session
spark = SparkSession.builder \
    .appName("Movie Ratings Count") \
    .getOrCreate()

# Đọc dữ liệu từ file u.data
df = spark.read.csv("../u.data", sep="\t",
                    inferSchema=True, header=False)

# Đặt tên các cột cho dễ đọc
df = df.withColumnRenamed("_c0", "user_id") \
       .withColumnRenamed("_c1", "movie_id") \
       .withColumnRenamed("_c2", "rating") \
       .withColumnRenamed("_c3", "timestamp")

# Thực hiện thống kê số lượng người bình chọn ở mỗi mức rating
rating_count_df = df.groupBy("rating").count().orderBy(col("rating").asc())

# Hiển thị kết quả
rating_count_df.show()

# Dừng Spark session
spark.stop()
