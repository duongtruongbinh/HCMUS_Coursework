USE QLGV

INSERT INTO CHUDE
    (MACD, TENCD)
VALUES
    (N'NCPT', N'Nghiên cứu phát triển'),
    (N'QLGD', N'Quản lý giáo dục'),
    (N'UDCN', N'Ứng dụng công nghệ')

INSERT INTO KHOA
    (MAKHOA, TENKHOA, NAMTL, PHONG, DIENTHOAI, TRUONGKHOA, NGAYNHANCHUC)
VALUES
    ('CNTT', N'Công nghệ thông tin', '1995', 'B11', '0838123456', NULL, CAST('2005-02-20' AS Date)),
    ('SH', N'Sinh học', '1980', 'B31', '0838454545', NULL, CAST('2000-10-11' AS Date)),
    ('HH', N'Hóa học', '1980', 'B41', '0838456465', NULL, CAST('2001-10-15' AS Date)),
    ('VL', N'Vật lý', '1976', 'B21', '0838223223', NULL, CAST('2003-09-18' AS Date))

INSERT INTO BOMON
    (MABM, TENBM, PHONG, DIENTHOAI, TRUONGBM, MAKHOA, NGAYNHANCHUC)
VALUES
    ('CNTT', N'Công nghệ tri thức', 'B15', '0838126126', NULL, 'CNTT', NULL),
    ('HHC', N'Hóa hữu cơ', 'B44', '838222222', NULL, 'HH', NULL),
    ('HL', N'Hóa lý', 'B42', '0838878787', NULL, 'HH', NULL),
    ('HPT', N'Hóa phân tích', 'B43', '0838777777', NULL, 'HH', CAST('2007-10-15' AS Date)),
    ('HTTT', N'Hệ thống thông tin', 'B13', '0838125125', NULL, 'CNTT', CAST('2004-09-20' AS Date)),
    ('MMT', N'Mạng máy tính', 'B16', '0838676767', NULL, 'CNTT', CAST('2005-05-15' AS Date)),
    ('SH', N'Sinh hóa', 'B33', '0838898989', NULL, 'SH', NULL),
    ('VLDT', N'Vật lý điện tử', 'B23', '0838234234', NULL, 'VL', NULL),
    ('VLUD', N'Vật lý ứng dụng', 'B24', '0838454545', NULL, 'VL', CAST('2006-02-18' AS Date)),
    ('VS', N'Vi sinh', 'B32', '0838909090', NULL, 'SH', CAST('2007-01-01' AS Date))

INSERT INTO GIAOVIEN
    (MAGV, HOTEN, LUONG, PHAI, NGSINH, DIACHI, GVQLCM, MABM)
VALUES
    ('001', N'Nguyễn Hoài An', 2000.0 , N'Nam', CAST(N'1973-02-15' AS Date), N'25/3 Lạc Long Quân, Q.10, TP HCM', NULL, 'MMT'),
    ('002', N'Trần Trà Hương', 2500.0 , N'Nữ', CAST(N'1960-06-20' AS Date), N'125 Trần Hưng Đạo, Q.1, TP HCM', NULL, 'HTTT'),
    ('003', N'Nguyễn Ngọc Ánh', 2200.0 , N'Nữ', CAST(N'1975-05-11' AS Date), N'12/21 Võ Văn Ngân Thủ Đức, TP HCM', '002', 'HTTT'),
    ('004', N'Trương Nam Sơn', 2300.0 , N'Nam', CAST(N'1959-06-20' AS Date), N'215 Lý Thường Kiệt, TP Biên Hòa', NULL, 'VS'),
    ('005', N'Lý Hoàng Hà', 2500.0 , N'Nam', CAST(N'1954-10-23' AS Date), N'22/5 Nguyễn Xí, Q.Bình Thạnh, TP HCM', NULL, 'VLDT'),
    ('006', N'Trần Bạch Tuyết', 1500.0 , N'Nữ', CAST(N'1980-05-20' AS Date), N'127 Hùng Vương, TP Mỹ Tho', '004', 'VS'),
    ('007', N'Nguyễn An Trung', 2100.0 , N'Nam', CAST(N'1976-06-05' AS Date), N'234 3/2, TP Biên Hòa', NULL, 'HPT'),
    ('008', N'Trần Trung Hiếu', 1800.0 , N'Nam', CAST(N'1977-08-06' AS Date), N'22/11 Lý Thường Kiệt, TP Mỹ Tho', '007', 'HPT'),
    ('009', N'Trần Hoàng Nam', 2000.0 , N'Nam', CAST(N'1975-11-22' AS Date), N'234 Trần Não, An Phú, TP HCM', '001', 'MMT'),
    ('010', N'Phạm Nam Thanh', 1500.0 , N'Nam', CAST(N'1980-12-12' AS Date), N'221 Hùng Vương, Q.5, TP HCM', '007', 'HPT')

UPDATE KHOA SET TRUONGKHOA = '002' WHERE MAKHOA = 'CNTT'
UPDATE KHOA SET TRUONGKHOA = '007' WHERE MAKHOA = 'HH'
UPDATE KHOA SET TRUONGKHOA = '004' WHERE MAKHOA = 'SH'
UPDATE KHOA SET TRUONGKHOA = '005' WHERE MAKHOA = 'VL'

UPDATE BOMON SET TRUONGBM = '007' WHERE MABM = 'HPT'
UPDATE BOMON SET TRUONGBM = '002' WHERE MABM = 'HTTT'
UPDATE BOMON SET TRUONGBM = '001' WHERE MABM = 'MMT'
UPDATE BOMON SET TRUONGBM = '005' WHERE MABM = 'VLUD'
UPDATE BOMON SET TRUONGBM = '004' WHERE MABM = 'VS'

INSERT INTO GV_DT
    (MAGV, DIENTHOAI)
VALUES
    ('001', '0838912112'),
    ('001', '0903123123'),
    ('002', '0913454545'),
    ('003', '0838121212'),
    ('003', '0903656565'),
    ('003', '0937125125'),
    ('006', '0937888888'),
    ('008', '0653717171'),
    ('008', '0913232323')

INSERT INTO DETAI
    (MADT, TENDT, CAPQL, KINHPHI, NGAYBD, NGAYKT, MACD, GVCNDT)
VALUES
    ('001', N'HTTT quản lý các trường ĐH', N'ĐHQG', 20.0 , CAST(N'2007-10-20' AS Date), CAST(N'2008-10-20' AS Date), 'QLGD', '002'),
    ('002', N'HTTT quản lý giáo vụ cho một Khoa', N'Trường', 20.0 , CAST(N'2000-10-12' AS Date), CAST(N'2001-10-12' AS Date), 'QLGD', '002'),
    ('003', N'Nghiên cứu chế tạo sợi Nanô Platin', N'ĐHQG', 300.0 , CAST(N'2008-05-15' AS Date), CAST(N'2010-05-15' AS Date), 'NCPT', '005'),
    ('004', N'Tạo vật liệu sinh học bằng màng ối người', N'Nhà nước', 100.0 , CAST(N'2007-01-01' AS Date), CAST(N'2009-12-31' AS Date), 'NCPT', '004'),
    ('005', N'Ứng dụng hóa học xanh', N'Trường', 200.0 , CAST(N'2003-10-10' AS Date), CAST(N'2004-12-10' AS Date), 'UDCN', '007'),
    ('006', N'Nghiên cứu tế bào gốc', N'Nhà nước', 4000.0 , CAST(N'2006-10-20' AS Date), CAST(N'2009-10-20' AS Date), 'NCPT', '004'),
    ('007', N'HTTT quản lý thư viện ở các trường đại học', N'Trường', 20.0 , CAST(N'2009-05-10' AS Date), CAST(N'2010-05-10' AS Date), 'QLGD', '001')

INSERT INTO CONGVIEC
    (MADT, STT, TENCV, NGAYBD, NGAYKT)
VALUES
    ('001', 1, N'Khởi tạo và Lập kế hoạch', CAST(N'2007-10-20' AS Date), CAST(N'2008-12-20' AS Date)),
    ('001', 2, N'Xác định yêu cầu', CAST(N'2008-12-21' AS Date), CAST(N'2008-03-21' AS Date)),
    ('001', 3, N'Phân tích hệ thống', CAST(N'2008-03-22' AS Date), CAST(N'2008-05-22' AS Date)),
    ('001', 4, N'Thiết kế hệ thống', CAST(N'2008-05-23' AS Date), CAST(N'2008-06-23' AS Date)),
    ('001', 5, N'Cài đặt thử nghiệm', CAST(N'2008-06-24' AS Date), CAST(N'2008-10-20' AS Date)),
    ('002', 1, N'Khởi tạo và Lập kế hoạch', CAST(N'2009-05-10' AS Date), CAST(N'2009-07-10' AS Date)),
    ('002', 2, N'Xác định yêu cầu', CAST(N'2009-07-11' AS Date), CAST(N'2009-10-11' AS Date)),
    ('002', 3, N'Phân tích hệ thống', CAST(N'2009-10-12' AS Date), CAST(N'2009-12-20' AS Date)),
    ('002', 4, N'Thiết kế hệ thống', CAST(N'2009-12-21' AS Date), CAST(N'2010-03-22' AS Date)),
    ('002', 5, N'Cài đặt thử nghiệm', CAST(N'2010-03-23' AS Date), CAST(N'2010-05-10' AS Date)),
    ('006', 1, N'Lấy mẫu', CAST(N'2006-10-20' AS Date), CAST(N'2007-02-20' AS Date)),
    ('006', 2, N'Nuôi cấy', CAST(N'2007-02-21' AS Date), CAST(N'2008-08-21' AS Date))

INSERT INTO THAMGIADT
    (MAGV, MADT, STT, PHUCAP, KETQUA)
VALUES
    ('001', '002', 1, CAST(0.0 AS Numeric(5, 1)), NULL),
    ('001', '002', 2, CAST(2.0 AS Numeric(5, 1)), NULL),
    ('002', '001', 4, CAST(2.0 AS Numeric(5, 1)), N'Đạt'),
    ('003', '001', 1, CAST(1.0 AS Numeric(5, 1)), N'Đạt'),
    ('003', '001', 2, CAST(0.0 AS Numeric(5, 1)), N'Đạt'),
    ('003', '001', 4, CAST(1.0 AS Numeric(5, 1)), N'Đạt'),
    ('003', '002', 2, CAST(0.0 AS Numeric(5, 1)), NULL),
    ('004', '006', 1, CAST(0.0 AS Numeric(5, 1)), N'Đạt'),
    ('004', '006', 2, CAST(1.0 AS Numeric(5, 1)), N'Đạt'),
    ('006', '006', 2, CAST(1.5 AS Numeric(5, 1)), N'Đạt'),
    ('009', '002', 3, CAST(0.5 AS Numeric(5, 1)), NULL),
    ('009', '002', 4, CAST(1.5 AS Numeric(5, 1)), NULL)

INSERT INTO NGUOITHAN
    (MAGV, TEN, NGSINH, PHAI)
VALUES
    ('001', N'Hùng', CAST(N'1990-01-14' AS Date), N'Nam'),
    ('001', N'Thủy', CAST(N'1994-12-05' AS Date), N'Nữ'),
    ('003', N'Hà', CAST(N'1997-09-03' AS Date), N'Nữ'),
    ('003', N'Thu', CAST(N'1998-09-03' AS Date), N'Nữ'),
    ('007', N'Mai', CAST(N'2003-03-26' AS Date), N'Nữ'),
    ('007', N'Vy', CAST(N'2000-02-14' AS Date), N'Nữ'),
    ('008', N'Nam', CAST(N'1991-05-06' AS Date), N'Nam'),
    ('009', N'An', CAST(N'1996-08-19' AS Date), N'Nam'),
    ('010', N'Nguyệt', CAST(N'2006-01-14' AS Date), N'Nữ')