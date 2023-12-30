import requests
import numpy as np
import pandas as pd
from typing import List

# Kiểm tra robots.txt để xác định xem có cho phép thu thập dữ liệu hay không.
import urllib.robotparser

# URL cơ sở được sử dụng trong tất cả các lệnh gọi API
BASE_URL = 'http://api.worldbank.org/v2/'

# Danh sách các chỉ số theo đặc điểm được xác định ở trên
INDICATOR_CODES = ['SP.POP.TOTL',
                   'SP.POP.TOTL.FE.IN',
                   'SP.POP.TOTL.MA.IN',
                   'SP.DYN.CBRT.IN',
                   'SP.DYN.CDRT.IN',
                   'SE.COM.DURS',
                   'SL.IND.EMPL.ZS',
                   'SL.AGR.EMPL.ZS',
                   'SL.AGR.EMPL.FE.ZS',
                   'SL.IND.EMPL.FE.ZS',
                   'SL.UEM.TOTL.ZS',
                   'NY.GDP.MKTP.CD',
                   'NY.ADJ.NNTY.PC.KD.ZG',
                   'NY.GSR.NFCY.CD',
                   'NV.AGR.TOTL.CD',
                   'EG.USE.ELEC.KH.PC',
                   'EG.FEC.RNEW.ZS',
                   'EG.USE.COMM.FO.ZS',
                   'SP.DYN.LE00.MA.IN',
                   'SP.DYN.LE00.FE.IN',
                   'SE.PRM.ENRR',
                   'SE.TER.ENRR',
                   'SE.PRM.CMPT.ZS',
                   'SE.ADT.1524.LT.ZS']

# Ánh xạ mã tính năng sang tên có ý nghĩa hơn
features_mapping = {
    "SP.POP.TOTL": "Total Population",
    "SP.POP.TOTL.FE.IN": "Female Population",
    "SP.POP.TOTL.MA.IN": "Male Population",
    "SP.DYN.CBRT.IN": "Birth Rate",
    "SP.DYN.CDRT.IN": "Death Rate",
    "SE.COM.DURS": "Compulsory Education Dur.",
    "SL.IND.EMPL.ZS": "Employment in Industry(%)",
    "SL.AGR.EMPL.ZS": "Employment in Agriculture(%)",
    "SL.AGR.EMPL.FE.ZS": "Female Employment in Agriculture(%)",
    "SL.IND.EMPL.FE.ZS": "Female Employment in Industry(%)",
    "SL.UEM.TOTL.ZS": "Unemployment(%)",
    "NY.GDP.MKTP.CD": "GDP in USD",
    "NY.ADJ.NNTY.PC.KD.ZG": "National Income per Capita",
    "NY.GSR.NFCY.CD": "Net income from Abroad",
    "NV.AGR.TOTL.CD": "Agriculture value added(in USD)",
    "EG.USE.ELEC.KH.PC": "Electric Power Consumption(kWH per capita)",
    "EG.FEC.RNEW.ZS": "Renewable Energy Consumption (%)",
    "EG.USE.COMM.FO.ZS": "Fossil Fuel Consumption (%)",
    "SP.DYN.LE00.MA.IN": "Male life expectancy",
    "SP.DYN.LE00.FE.IN": "Female life expectancy ",
    "SE.PRM.ENRR": "School enrollment, primary",
    "SE.TER.ENRR": "School enrollment, tertiary",
    "SE.PRM.CMPT.ZS": "Primary completion rate",
    "SE.ADT.1524.LT.ZS": "Literacy rate"
}


def loadData(country_code: str, format: str = "json", per_page: int = 100, year_interval: str = '2015:2022') -> List:
    """Hàm lấy dữ liệu với format

    Args:
        country_code (str): Mã quốc gia 2 ký tự alpha (alpha-2 code), ví dụ như United States có alpha-2 code là US.
        format (str, optional): định dạng của dữ liệu để đảm bảo nhận đúng phản hội dựa trên định dạng đã cho. Defaults to "json".
        per_page (int, optional): Kích thước trang cho việc cào dữ liệu Tùy thuộc vào số năm trong tham số year_interval mà cần thay
        đổi kích thước trang sao cho phù hợp. Defaults to 200.
        year_interval (_type_, optional): Phạm vi số năm cần dữ liệu. Defaults to '1960:2022'.

    Returns:
        List: Danh sách dữ liệu
    """
    # Danh sách dữ liệu
    dataLst = []

    # Tạo các tham số cho request
    start_year, end_year = year_interval.split(
        ':')[0], year_interval.split(':')[1]

    # Duyệt từng indicator được chỉ định trong hằng số INDICATOR_CODES được xác định ở trên
    for indicator in INDICATOR_CODES:
        # tạo URL theo định dạng mong muốn
        # Ví dụ: http://api.worldbank.org/v2/countries/us/indicators/SP.POP.TOTL?format=json&per_page=200&date=196
        url = BASE_URL+'countries/' + country_code.lower() + '/indicators/' + indicator

        # gửi request với các tham số mặc định bằng resquests module
        params = {'format': format,
                  'per_page': str(per_page),
                  'date': str(start_year) + ":" + str(end_year)}

        response = requests.get(url, params=params)

        # Xác thực mã trạng thái phản hồi
        # API trả về status_code 200 ngay cả đối với các thông báo lỗi,
        # tuy nhiên, nội dung phản hồi chứa một trường có tên là "thông báo" bao gồm các chi tiết về lỗi
        # kiểm tra xem tin nhắn có xuất hiện trong phản hồi hay không
        if response.status_code == 200 and ("message" not in response.json()[0].keys()):
            # print("Successfully got data for: " + str(featureMap[indicator]))

            # danh sách các giá trị cho một đặc trưng
            indicatorVals = []

            # phản hồi là một mảng chứa hai mảng - [[{page: 1, ...}], [{year: 2018, SP.POP.TOTL: 123455}, ...]]
            # do đó chúng ta kiểm tra xem độ dài của phản hồi có > 1 hay không
            if len(response.json()) > 1:

                # nếu có, lặp lại từng đối tượng trong phản hồi
                # mỗi đối tượng cho một giá trị duy nhất cho mỗi năm
                for obj in response.json()[1]:

                    # Kiểm tra giá trị rỗng
                    if (obj['value'] == "") or (obj['value'] is None):
                        indicatorVals.append('None')
                    else:
                        # nếu có một giá trị, hãy thêm nó vào danh sách các giá trị chỉ báo indicatorVals
                        indicatorVals.append(float(obj['value']))

                dataLst.append(indicatorVals)

            else:
                # In thông báo lỗi nếu lệnh gọi API không thành công
                print("Error in Loading the data. Status Code: " +
                      str(response.status_code))

    # Khi đã có được tất cả các đặc trưng, ta thêm các giá trị cho "Năm"
    # API trả về các giá trị indicator từ năm gần đây nhất. Do đó, chúng tôi tạo một danh sách các năm ngược lại
    dataLst.append([year for year in range(
        int(end_year), int(start_year)-1, -1)])

    # Trả về danh sách các giá trị đặc trưng [[val1,val2,val3...], [val1,val2,val3...], [val1,val2,val3...], .
    return dataLst


def loadDataCountry(country_code: str, format: str = "json", per_page: int = 100, year_interval: str = '2015:2022', is_display: bool = False) -> pd.DataFrame:
    """Tạo DataFrame cuối cùng cho mỗi quốc gia với country_code

    Args:
        country_code (str): Mã quốc gia 2 ký tự alpha (alpha-2 code), ví dụ như United States có alpha-2 code là US
        format (str, optional): định dạng của dữ liệu để đảm bảo nhận đúng phản hội dựa trên định dạng đã cho. Defaults to "json".
        per_page (int, optional): Kích thước trang cho việc cào dữ liệu Tùy thuộc vào số năm trong tham số year_interval mà cần thay
        đổi kích thước trang sao cho phù hợp. Defaults to 200.
        year_interval (str, optional): Phạm vi số năm cần dữ liệu. Defaults to '1960:2022'.
        is_display (bool, optional): Liệu có muốn show bảng dữ liệu kết quả hay không.

    Returns:
        pd.DataFrame: Pandas dataframe kết quả chứa dữ liệu mong muốn.
    """
    # Định nghĩa một số country codes
    df_country_code = pd.read_csv("../data/external/country-codes.csv")
    # df_country_code = pd.read_csv("../../data/external/country-codes.csv")
    df_country_code = df_country_code.fillna("NA")
    COUNTRIES_MAPPING = dict(
        zip(df_country_code["alpha-2-code"], df_country_code["name"]))
    del df_country_code

    # dataframe kết quả cần phải có tên cột có ý nghĩa
    # do đó chúng ta tạo danh sách tên cột từ ánh xạ các đặc trưng được xác định ở trên
    col_list = list(features_mapping.values())

    # Thêm cột "Year"
    col_list.append('Year')

    print(f"[LOG] Loading data for {COUNTRIES_MAPPING[country_code]}")

    # Với mã country code cho trước, gọi hàm loadData
    dataLst = loadData(country_code=country_code, format=format,
                       per_page=per_page, year_interval=year_interval)

    # Chuyển đổi danh sách các đặc trưng thành kiểu Pandas DataFrame
    df = pd.DataFrame(np.column_stack(dataLst), columns=col_list)

    # Thêm cột quốc gia bằng cách trích xuất tên quốc gia từ bản đồ bằng mã quốc gia
    df['Country'] = COUNTRIES_MAPPING[country_code]

    if is_display:
        from IPython.display import display
        display(df.head())

    return df


def replacer(s, newstring, index, nofail=False):
    # raise an error if index is outside of the string
    if not nofail and index not in range(len(s)):
        raise ValueError("index outside given string")

    # if not erroring, but the index is still not in the correct range..
    if index < 0:  # add it to the beginning
        return newstring + s
    if index > len(s):  # add it to the end
        return s + newstring

    # insert the new string between "slices" of the original
    return s[:index] + newstring + s[index + 1:]


def loadDataContinent(continent: str = "Asia", format: str = "json", per_page: int = 100, year_interval: str = '2015:2022', is_display: bool = False) -> pd.DataFrame:
    """Tạo DataFrame cuối cùng cho mỗi lục địa với tên lục địa cho trước, ví dụ: Asia

    Args:
        continent (str, optional): _description_. Defaults to "Asia".
        format (str, optional): định dạng của dữ liệu để đảm bảo nhận đúng phản hội dựa trên định dạng đã cho. Defaults to "json".
        per_page (int, optional): Kích thước trang cho việc cào dữ liệu Tùy thuộc vào số năm trong tham số year_interval mà cần thay
        đổi kích thước trang sao cho phù hợp. Defaults to 200.
        year_interval (str, optional): Phạm vi số năm cần dữ liệu. Defaults to '1960:2022'.
        is_display (bool, optional): Liệu có muốn show bảng dữ liệu kết quả hay không.

    Returns:
        pd.DataFrame: Pandas dataframe kết quả chứa dữ liệu mong muốn.
    """
    if continent.lower() not in ['asia', 'europe', 'africa', 'oceania', 'americas']:
        print(
            f"[LOG] Please check input continent again. We don't support {continent}.")
        raise ValueError

    if not continent[0].isupper():
        continent = replacer(continent, continent[0].upper(), 0)

    # Định nghĩa một số country codes
    df_country_code = pd.read_csv("../data/external/country-codes.csv")
    # df_country_code = pd.read_csv("../../data/external/country-codes.csv")
    df_country_code = df_country_code.fillna("NA")
    df_country_code = df_country_code[df_country_code["continent"] == continent]
    lst_country_codes = df_country_code["alpha-2-code"]
    del df_country_code

    df = pd.DataFrame()
    for country_code in lst_country_codes:
        df = pd.concat([df, loadDataCountry(
            country_code=country_code,
            format=format,
            per_page=per_page,
            year_interval=year_interval,
            is_display=False)], axis=0)

    if is_display:
        from IPython.display import display
        display(df.head())

    return df


def saveDataFrame2CSV(df: pd.DataFrame, save_path: str, sep: str = ',', encoding: str = 'utf-8') -> bool:
    """Hàm lưu DataFrame thành dạng file CSV

    Args:
        save_path (str): Đường dẫn chứa tên tập tin cần lưu, ví dụ: "data/save.csv"
        sep (str, optional): Ký tự phân chia các đặc trưng trong file csv. Defaults to ','.
        encoding (str, optional): . Defaults to 'utf-8'.

    Returns:
        bool: True
    """
    try:
        df.to_csv(save_path, sep=sep, encoding=encoding, index=False)
    except:
        raise ModuleNotFoundError
        # return False
    return True
