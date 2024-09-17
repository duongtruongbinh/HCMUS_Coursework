from pyspark.sql import SparkSession
from pyspark.sql.functions import split, explode, col, lower, count

# Tạo SparkSession
spark = SparkSession.builder \
    .appName("Word Count") \
    .getOrCreate()

# Đọc dữ liệu từ file văn bản và tạo DataFrame
df = spark.read.text("../pg4300.txt")

# Tách từng từ trong tài liệu (Câu a: phân biệt hoa thường)
df_exploded_a = df.withColumn("word", explode(split(col("value"), "\\s+")))

# Thống kê số lần xuất hiện của mỗi từ (Câu a)
word_count_a = df_exploded_a.groupBy("word").agg(
    count("word").alias("count")).orderBy("count", ascending=False)

# Hiển thị kết quả Câu a
word_count_a.show(10)

# Tách từng từ và chuyển về chữ thường (Câu b: không phân biệt hoa thường)
df_exploded_b = df.withColumn(
    "word", explode(split(lower(col("value")), "\\s+")))

# Thống kê số lần xuất hiện của mỗi từ (Câu b)
word_count_b = df_exploded_b.groupBy("word").agg(
    count("word").alias("count")).orderBy("count", ascending=False)

# Hiển thị kết quả Câu b
word_count_b.show(10)
