#include "NgayThang.h"
using namespace std;

void main()
{
	/// 1.0 điểm: không lỗi biên dịch
	NgayThang nt1(1960, 640, 120), nt2(-2010, 173, -50), nt3(731000), nt4;
	/// 1.0 điểm: khởi tạo object hợp lý
	/// xuất ra dạng: 'x/x/x' ; vd: '3/2/1900'
	/// 1.0 điểm: xuất định dạng: dd/mm/yyyy
	cout << "nt1: " << nt1 << endl;
	cout << "nt2: " << nt2 << endl;
	cout << "nt3: " << nt3 << endl;
	cout << "nt4: " << nt4 << endl;
	/// 1.0 điểm
	NgayThang nt5 = nt1 + nt2;
	cout << "nt5 (= nt1 + nt2): " << nt5 << endl;
	/// 1.5 điểm
	NgayThang nt6 = nt1 + 100;
	cout << "nt6 (= nt1 + 100): " << nt6 << endl;
	/// 1.5 điểm
	NgayThang nt7 = 100 + nt1;
	cout << "nt7 (= 100 + nt1): " << nt7 << endl;
	/// 1.0 điểm (lưu ý toán tử ++, +int áp dụng lên Ngày)
	NgayThang nt8 = 101 + nt1 + nt3;
	cout << "nt1: " << nt1 << "; nt3: " << nt3 << endl;
	NgayThang nt9 = 100 + nt1++ + ++nt3;
	cout << "nt8 (= 101 + nt1 + nt3): " << nt8 << endl;
	cout << "nt9 (= 100 + nt1++ + ++nt3): " << nt9 << endl;
	cout << "nt1: " << nt1 << "; nt3: " << nt3 << endl;
	/// 1.0 điểm: xuất ngày tháng lớn nhất trong các ngày tháng
	/// đã tạo và tính toán ở trên
	//cout << "Ngay thang lon nhat: ";
	//cout << *(NgayThang::NgayThangLonNhat()) << endl << endl;
	/// 1.0 điểm: ngày tối đa mỗi tháng hợp lý
	/// (vd: tháng 2 có 28~29 ngày, tháng 7 có 31 ngày).
}