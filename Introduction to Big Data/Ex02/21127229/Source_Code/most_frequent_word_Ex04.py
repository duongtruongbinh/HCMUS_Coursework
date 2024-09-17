from pyspark.sql import SparkSession
from pyspark.sql.functions import split, explode, col, lower, count

# Tạo SparkSession
spark = SparkSession.builder \
    .appName("Most Frequent Word") \
    .getOrCreate()

# Đọc dữ liệu từ file văn bản và tạo DataFrame
df = spark.read.text("../pg4300.txt")

# Tách từng từ và chuyển về chữ thường
df_exploded = df.withColumn("word", explode(
    split(lower(col("value")), "\\s+")))

# Thống kê số lần xuất hiện của mỗi từ
word_count_df = df_exploded.groupBy("word").agg(count("word").alias("count"))

# Sắp xếp theo số lần xuất hiện từ cao đến thấp và lấy từ xuất hiện nhiều nhất
most_frequent_word = word_count_df.orderBy("count", ascending=False).limit(1)

# Hiển thị kết quả
most_frequent_word.show()
