from pyspark.sql import SparkSession
from pyspark.sql.functions import count

# Tạo SparkSession
spark = SparkSession.builder \
    .appName("Movie Rating Count") \
    .getOrCreate()

# Đọc dữ liệu từ file u.data và tạo DataFrame
df = spark.read.csv("../u.data", sep='\t', inferSchema=True)
df = df.withColumnRenamed("_c0", "user_id") \
       .withColumnRenamed("_c1", "item_id") \
       .withColumnRenamed("_c2", "rating") \
       .withColumnRenamed("_c3", "timestamp")

# Thực hiện nhóm theo item_id (mã phim) và đếm số lượt bình chọn
movie_count_df = df.groupBy("item_id").agg(count("item_id").alias("count"))

# Sắp xếp theo tổng số lượt bình chọn (từ cao xuống thấp)
sorted_movie_count_df = movie_count_df.orderBy("count", ascending=False)

# Hiển thị kết quả
sorted_movie_count_df.show()
